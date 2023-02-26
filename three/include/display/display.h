#ifndef DISPLAY_H__JT
#define DISPLAY_H__JT

#include "window.h"
#include "objUnit.h"

#define MAIN_WIN_COLOR 0
#define ANIMATION_WIN_COLOR 1
#define TIPS_WIN_COLOR 2
#define PLANE_COLOR_PAIR (COLORS-1)
#define EMENY_COLOR_PAIR (COLORS-2)
#define BULLET_COLOR_PAIR (COLORS-3)

class Display{
public:
	Display();
	~Display(){
		delete main_win;
		delete plane;
		delete enemy1;
	}

	void updateInput(int key);
	void updateWithoutInput(unsigned ticks);
	void updateFrame();

	void updateScore();

	Window* main_win;
	Window* animation_win;
	Window* tips_win;
	
	char tipsBuff[256];
	unsigned int ticks;	
	int score;
	bool isPause; 

	Plane* plane;
	Enemy* enemy1;
	Bullet* bullet1;
private:

};

#endif
