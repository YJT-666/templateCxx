#include "../../../include/display/objUnit.h"


void Enemy::updateLoc(unsigned int ticks){
	if (isKilled) return;
	if( ticks % spd == 0){
		y++;
	}
	if( y >= max_y) regeneration();
	draw();
}
void Enemy::draw(){
	limitBoundary();
	int draw_x = TRANS_X(x);
	int draw_y = TRANS_Y(y);

	pwin->addChar(draw_y, draw_x, ch);
}
void Enemy::regeneration(){
		x = GET_X_LIMIT(min_x) + rand()%(GET_X_LIMIT(max_x) - GET_X_LIMIT(min_x)); 
		y = GET_Y_LIMIT(min_y);
}

void Bullet::updateLoc(unsigned int ticks){
	if(isLive){
		if(ticks % spd == 0 ){
			y--;
		}
		draw();
	}
}

void Bullet::draw(){
	limitBoundary();
	int draw_x = TRANS_X(x);
	int draw_y = TRANS_Y(y);
	pwin->addChar(draw_y, draw_x, ch);
}

void Plane::draw(){
	
	limitBoundary();
	int draw_x = TRANS_X(x);
	int draw_y = TRANS_Y(y);

	init_pair(color_pair, color_f, color_f);
	pwin->setColorPart(color_pair);
	pwin->addChar(draw_y, draw_x,  ch);
	pwin->addChar(draw_y, draw_x-1, ch);
	pwin->addChar(draw_y, draw_x-2, ch);
	pwin->addChar(draw_y, draw_x+1, ch);
	pwin->addChar(draw_y, draw_x+2, ch);
	pwin->addChar(draw_y-1, draw_x, ch);
	pwin->addChar(draw_y+1, draw_x-1, ch);
	pwin->addChar(draw_y+1, draw_x+1, ch);
	pwin->unSetColorPart(color_pair);	
}


