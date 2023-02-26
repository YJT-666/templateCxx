#include "../../../include/display/display.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

Display::Display(){

	std::string	win_name("main_win");
	main_win = new Window(win_name, 0, 0, 0, 0, MAIN_WIN_COLOR);

	win_name = std::string("animation_win");
	int win_h = 73;
	int win_w = 100;
	int y0 = 0;
	int x0 = 0;
	animation_win = new Window(win_name, win_h, win_w, y0, x0, ANIMATION_WIN_COLOR, main_win);

	win_name = std::string("tips_win");
	win_h = 28;
	win_w = 100;
	y0 = 75;
	x0 = 0;
	tips_win = new Window(win_name, win_h, win_w, y0, x0, TIPS_WIN_COLOR, main_win);
    
	ticks = 0;
	score = 0;
	isPause = false;

	y0 = 1;
	x0 = 1;
	int spd = 1;
	int maxY = 99;
	int maxX = 99;
	int minY = 1;
	int minX = 1;
	char objCh = '*';
	short color = PLANE_COLOR_PAIR;
	short colorF = COLOR_BLUE;
	short colorB = COLOR_BLACK;
	Window* pWin = animation_win;
	plane = new Plane(y0, x0, spd, maxY, maxX, minY, minX, objCh, color, colorF, colorB,  pWin);

	
	spd = 20;
	maxY = 99;
	maxX = 99;
	y0 = 1;
	x0 = maxX / 2;
	minY = 1;
	minX = 1;
	objCh = '@';
	color = EMENY_COLOR_PAIR;
	colorF = COLOR_RED;
	colorB = COLOR_BLACK;
	pWin = animation_win;
	enemy1 = new Enemy(y0, x0, spd, maxY, maxX, minY, minX, objCh, color, colorF, colorB, pWin);

	spd = 1;
	maxY = 100;
	maxX = 100;
	y0 = 1;
	x0 = 1;
	minY = 0;
	minX = 0;
	objCh = '|';
	color = BULLET_COLOR_PAIR;
	colorF = COLOR_YELLOW;
	colorB = COLOR_BLACK;
	pWin = animation_win;
	bullet1 = new Bullet(y0, x0, spd, maxY, maxX, minY, minX, objCh, color, colorF, colorB, pWin);	
}
void Display::updateFrame(){
	ticks++;
	int key = getch();
	updateInput(key);
	if(isPause) return;	
	updateWithoutInput(ticks);
	updateScore();
	animation_win->reflashWin();
	animation_win->clearWin();
	tips_win->reflashWin();
	tips_win->clearWin();
}
void Display::updateScore(){

	if( bullet1->isLocEq(enemy1) ){
		score++;
		enemy1->regeneration();
	}

	tips_win->printTips(" ");
	sprintf(tipsBuff, "   score: %3d", score);
	tips_win->printTips(tipsBuff);
}

void Display::updateInput(int key){

	if(isPause && key == 'p'){
		isPause = false;
	}else if(key == 'p'){
		isPause = true;
	}
	if(isPause) return;

	switch(key){
		case 'a':
			(plane->x)--;
			break;
		case 'd':
			(plane->x)++;
			break;
		case 'w':
			(plane->y)--;
			break;
		case 's':
			(plane->y)++;
			break;
		case ' ':
			(bullet1->isLive) = true;
			(bullet1->x) = (plane->x);
			(bullet1->y) = (plane->y)-1;
			break;
		default:
			break;
	}
}
void Display::updateWithoutInput(unsigned ticks){
	plane->updateLoc(ticks);
	enemy1->updateLoc(ticks);
	bullet1->updateLoc(ticks);
}

