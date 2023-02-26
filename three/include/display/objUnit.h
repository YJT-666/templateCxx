#ifndef OBJUNIT_H__JT
#define OBJUNIT_H__JT
#include "window.h"

#define MIN_X          0
#define MIN_Y          0
#define MAX_X          200
#define MAX_Y          40
#define TRANS_X(X)     (int(((float)X/(float)MAX_X)*(float)pwin->gWinW())) // when display
#define TRANS_Y(Y)     (int(((float)Y/(float)MAX_Y)*(float)pwin->gWinH()))

#define GET_X_LIMIT(X)   (int((float)X/(float)100.0f*(MAX_X-MIN_X) + MIN_X)) // when input
#define GET_Y_LIMIT(Y)   (int((float)Y/(float)100.0f*(MAX_Y-MIN_Y) + MIN_Y))


class BasicObj{
public:
	int y;
	int x;
	int min_y;
	int min_x;
	int max_y;
	int max_x;
	int spd;
	char ch;

	short color_pair;
	short color_f;
	short color_b;
	
	Window* pwin;
	
	// max min is percent to win  0~100
	BasicObj(int my, int mx, int mspd, int maxY, int maxX, int minY, int minX, char mch, short mcolor, short colorF, short colorB,  Window* mpwin){
		y = my;
		x = mx;
		spd = mspd;
		max_y = GET_Y_LIMIT(maxY);
		max_x = GET_X_LIMIT(maxX);
		min_y = GET_Y_LIMIT(minY);
		min_x = GET_X_LIMIT(minX);
		ch = mch;
		color_pair = mcolor;
		color_f = colorF;
		color_b = colorB;
		pwin = mpwin;
	}	
	
	

	virtual void draw()=0;
	virtual void updateLoc(unsigned int ticks){
		draw();
	}
	void limitBoundary(){	
		if(x >= max_x) x = max_x;
		else if(x <= min_x) x = min_x;
		if(y >= max_y) y = max_y;
		else if(y <= min_y) y = min_y;
	}
	bool isLocEq(BasicObj* obj){
		if (obj == NULL ) return false;
		if( (x == (obj->x)) && (y == (obj->y) ) ) return true;
		return false;
	}

};
class Enemy : public BasicObj{
public:
	Enemy(int my, int mx, int mspd, int maxY, int maxX, int minY, int minX, char mch, short mcolor, short colorF, short colorB,  Window* mpwin) : \
		BasicObj(my, mx, mspd, maxY, maxX, minY, minX, mch, mcolor, colorF, colorB, mpwin){
		isKilled = false;
	}	
	void updateLoc(unsigned int ticks);
	void draw();
	void regeneration();

	bool isKilled;
};

class Plane : public BasicObj{
public:
	Plane(int my, int mx, int mspd, int maxY, int maxX, int minY, int minX, char mch, short mcolor, short colorF, short colorB,  Window* mpwin) : \
		BasicObj(my, mx, mspd, maxY, maxX, minY, minX, mch, mcolor, colorF, colorB, mpwin){
	}	
	void draw();
};
class Bullet : public BasicObj{
public:
	Bullet(int my, int mx, int mspd, int maxY, int maxX, int minY, int minX, char mch, short mcolor, short colorF, short colorB,  Window* mpwin): \
		BasicObj(my, mx, mspd, maxY, maxX, minY, minX, mch, mcolor, colorF, colorB, mpwin){
		isLive = false;
	}	
	void draw();
	void updateLoc(unsigned int ticks);
	bool isLive;
};

#endif
