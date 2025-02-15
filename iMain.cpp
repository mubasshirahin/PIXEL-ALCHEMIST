#include<iostream>
#include "iGraphics.h"
#include "StartPage.h"
#include "Credits.h"
#include "Help.h"
#include "MainGameStart.h"
#include "FireIcon.h"
#include "waterIcon.h"
#include "FogAnimation.h"
#include "Inventory.h"
#include "levelTwoTransition.h"
#include "level2.h"


using namespace std;

extern int charX;
extern int charY;
extern bool temp1;





//----------------------------------------------------------------------------------------------------------------//

void iDraw()
{
	iClear();
	homepage();
	helpp();
	TextBlink();
	texts();
	Hover();
	credits();
	back();
	backHover();
	showLevel();
	showBackgroundOfGame();
	characterPlot();
	DownChange();
	movement();
	StandingCounterr();
	showFire();
	updateFireMovement();
	checkFireProximity(charX, charY);
	showWater();
	checkWaterProximity(charX, charY);
	showFog();
	checkFogClear();
	openInventory();
	showInventoryIcon();
	showHint();
	goTolevel2();
	showDoor();
	showIndicatorLevelOne();
	updateforOne();
	showLevel2();
	updateForLevel2();
	showLevel2BG();
}







//----------------------------------------------------------------------------------------------------------------//

void iMouseMove(int mx, int my)
{
	cout << mx << " " << my << endl;
}

//*******************************************************************ipassiveMouse***********************************************************************//

void iPassiveMouseMove(int mx, int my)
{
	if (mx >= 364 && mx <= 730 && my >= 372 && my <= 416 && _menuOptions == true){
		isHovering1 = true;
	}
	else{
		isHovering1 = false;
	}
	if (mx >= 364 && mx <= 730 && my >= 300 && my <= 345 && _menuOptions == true){
		isHovering2 = true;
	}
	else{
		isHovering2 = false;
	}
	if (mx >= 364 && mx <= 730 && my >= 230 && my <= 275 && _menuOptions == true){
		isHovering3 = true;
	}
	else{
		isHovering3 = false;
	}
	if (mx >= 364 && mx <= 730 && my >= 155 && my <= 205 && _menuOptions == true){
		isHovering4 = true;
	}
	else{
		isHovering4 = false;
	}
	if (mx >= 900 && mx <= 960 && my >= 500 && my <= 560 && _menuOptions == false){
		_backHover = true;
	}
	else{
		_backHover = false;
	}
}

//----------------------------------------------------------------------------------------------------------------//

void iMouse(int button, int state, int mx, int my)
{

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if (mx >= 364 && mx <= 730 && my >= 372 && my <= 416 && _menuOptions == true){
			_start = true;
		}
		if (isHovering4 == true){
			_credit = true;
		}
		if (mx >= 900 && mx <= 960 && my >= 500 && my <= 560){
			_credit = false;
			_menuOptions = true;
			_help = false;
		}
		if (mx >= 882 && mx <= 998 && my >= 20 && my <= 72 && _menuOptions==true){
			_sound = !_sound;
			sound();
		}
		if (isHovering3 == true){
			_help = true;
		}
		if (mx >= 882 && mx <= 998 && my >= 20 && my <= 72 && temp1 == true){
			_inventory = !_inventory;
		}

	}


	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{

	}
}

//----------------------------------------------------------------------------------------------------------------//

#define CHARACTER_WIDTH 50
#define CHARACTER_HEIGHT 50

void iKeyboard(unsigned char key)
{
	if (key == '\r')
	{
		_menuOptions = true;
		_gameNamePage = false;
	}

	if (_levelPage == true && key == '\r')
	{
		_levelPage = false;
		_mainGameBG = true;
		level1 = true;
	}

	if (level2 == true && key == '\r')
	{
		level2BG = true;
	}

	if (key == 'w')
	{
		// Check if the character can move up without going out of bounds
		if (charY + CHARACTER_HEIGHT <= 594)  // Ensure that the character doesn't go beyond the top
		{
			charY += 10;
			upMovement = true;
		}
	}

	if (key == 'd')
	{
		// Check if the character can move right without going out of bounds
		if (charX + CHARACTER_WIDTH <= 1025)  // Ensure that the character doesn't go beyond the right
		{
			charX += 10;
			rightMovement = true;
		}
	}

	if (key == 'a')
	{
		// Check if the character can move left without going out of bounds
		if (charX >= 10)  // Ensure that the character doesn't go beyond the left
		{
			charX -= 10;
			leftMovement = true;
		}
	}
	if (key == 'u'){
		_open = true;
	}

	if (key == 'e'){
		level2 = true;
	}

	if (key == 's')
	{
		// Check if the character can move down without going out of bounds
		if (charY >= 10)  // Ensure that the character doesn't go beyond the bottom
		{
			charY -= 10;
			downMovement = true;
		}
	}
	
	if (key == 'x' && nearFire && !fireCollected) {
			fireCollected = true;
		}
	if (key == 'x' && nearWater && !waterCollected) {
		waterCollected = true;
	}
	if (key == 'x' && nearWater && !waterCollected) {
		waterCollected = true;
		printf("Water collected!\n");
	}
	checkFogClear();
	
}

//----------------------------------------------------------------------------------------------------------------//
/*
function iSpecialKeyboard() is called whenver user hits special keys like-
function keys, home, end, pg up, pg down, arraows etc. you have to use
appropriate constants to detect them. A list is:
GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/

void iSpecialKeyboard(unsigned char key)
{
	if (key == GLUT_KEY_RIGHT)
	{
	}
	if (key == GLUT_KEY_LEFT)
	{

	}
	if (key == GLUT_KEY_HOME)
	{
	}
}



//----------------------------------------------------------------------------------------------------------------------//


int main()
{
	iInitialize(1025, 594, "Project Title");
	sound();
	iSetTimer(100, updateFireAnimation);  // Animates fire frames
	iSetTimer(100, updateFireMovement);   // Moves fire up and down
	iSetTimer(50, updateWaterMovement);
	startAnimation();
	iSetTimer(10, updateforOne);



	iStart();
	iSetTimer(100, TextBlink);

	
	return 0;
}