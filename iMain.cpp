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
#include "instruction.h"
#include "charachterplot.h"
#include "windIcon.h"
#include "movementBlocking.h"
#include "level3.h"


using namespace std;

extern int charX;
extern int charY;
extern bool temp1;
extern bool _instruction1;
extern bool _instruction2;
extern bool fogCleared;
extern bool showdoor;




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
	story();
	back();
	backHover();
	showLevel();
	showBackgroundOfGame();
	showFire();
	updateFireMovement();
	checkFireProximity(charX, charY);
	showWater();
	checkWaterProximity(charX, charY);
	showFog();
	checkFogClear();
	goTolevel2();
	showDoor();
	showIndicatorLevelOne();
	updateforOne();
	showLevel2();
	updateForLevel2();
	showLevel2BG();
	showWindmill();
	showWaterfall();
	updateWaterfallAnimation();
	showWind();
	updateWindAnimation();
	showMatchBox();
	showShovel();
	showAxe();
	lightUpFire();
	digging();
	showDirt();
	collectAir();
	takeAir();
	breakWall();
	collectWater();
	collected4elements();
	showToBreakgem();
	showGemBreakAnimation();
	updateGemBreakAnimation();
	showPortal();
	updatePortalAnimation();
	afterGemBreaked();
	updateforLevel3();
	showLv3BG();
	showAxee2(); 
	cutTree();
	showRope();
	if (isThrowing) {
		iShowBMP2(ropeidx1, ropeidx2, "Images//ropeToGo.bmp", 0);
	}
	if (isThrowing2){
		iShowBMP2(ballidx1, ballidx2, "Images//fireBall.bmp", 0);
	}
	throwRopeMessage();
	updateBackgroundAnimation();
	toPull();
	showPani();
	nextPage1();
	showGlass();
	lightUp();
	showLightingFire();
	showDirt2();
	showToPickingEarth();
	displayEnemyAnimation();
	updateEnemyAnimation();
	checkForInstruction();
	showLava();
	updateLava();
	showDead();
	goToMap3();
	blockFor3();
	showBhut();
	updateBhut();
	showToThrow();
	updateBall();
	takeBoat();
	ending();
	blackScreen();


	openInventory();
	showInventoryIcon();
	showInstruction();
	

	characterPlot();
	DownChange();
	movement();
	StandingCounterr();
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
			_story = false;
		}
		if (isHovering4 == true){
			_credit = true;
			_story = false;
		}
		if (mx >= 900 && mx <= 960 && my >= 500 && my <= 560){
			_credit = false;
			_menuOptions = true;
			_help = false;
			_story = false;
		}
		if (mx >= 945 && mx <= 1006 && my >= 19 && my <= 77 && _menuOptionsTexts==true && _menuOptions){
			_sound = !_sound;
			sound();
		}
		if (isHovering3 == true){
			_help = true;
			_story = false;
		}
		if (mx >= 15 && mx <= 55 && my >= 12 && my <= 40 && temp1 == true){
			_inventory = !_inventory;
		}
		if (isHovering2 && _menuOptionsTexts){
			_story = true;
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

	// Check if on level page and Enter key is pressed
	if (_levelPage == true && key == '\r') {
		_levelPage = false;
		_instruction1 = true;
	}

	// Check if instruction 1 is active and Enter key is pressed
	if (_instruction1 == true && key == ' ') {
		_instruction1 = false;
		_instruction2 = true;
	}

	if (_instruction2 == true && key == '\r') {
		_instruction2 = false;
		_instruction1 = false;
		_mainGameBG = true;
		level1 = true;
	}

	if (level2 == true && key == '\r')
	{
		_instruction3 = true;
	}

	if (_instruction3 == true && key == ' ') {
		_instruction2 = false;
		_instruction1 = false;
		_instruction3 = false;
		_instruction5 = true;
	}

	if (_instruction5 == true && key == '\r') {
		_instruction2 = false;
		_instruction1 = false;
		_instruction3 = false;
		_instruction5 = false;
		level2BG = true;
		fireCollected = false;
		waterCollected = false;
	}




	if (_instruction4 == true && key == '\r') {
		_instruction4 = false;	
		_instruction1 = false;
		_instruction2 = false;
		_instruction3 = false;

		showed4 = false;
		fogCleared = true;
	}

	if (_instruction6 == true && key == ' '){
		_instruction6 = false;
		_instruction5 = false;
		_instruction4 = false;
		_instruction3 = false;
		_instruction2 = false;
		_instruction1 = false;

		showeddd = true;
	}

	if (matchpickuptext && key == 'p' && level2BG && level2){
		pickedmatchBox = true;
	}
	if (shovelpickuptext && key == 'p' && level2BG && level2){
		pickedShovel = true;
	}
	if (axepickuptext && key == 'p' && level2BG && level2){
		pickedAxe = true;
	}

	if (nearrFire && pickedmatchBox && key == 'f' && level2BG && level2){
		fireIcon = true;
		fireCollected = true;
		_instruction8 = true;
	}

	if (nearrDig && pickedShovel && key == 'x' && level2BG && level2 && fireCollected){
		if (fireCollected){
			digDone = true;
			_instruction9 = true;
		}
	}

	if (nearAir && key == 'x' &&level2BG && level2){
		if (fireCollected && earthCollected && nearAir){
			pickedAir = true;
			_instruction10 = true;
	}
	}

	if (nearWall && key == 'x' && level2BG && level2){
		if (fireCollected && earthCollected && windCollected){
			breaked = true;
			_instruction1 = false;
			_instruction2 = false;
			_instruction3 = false;
			_instruction4 = false;
			_instruction5 = false;
			_instruction6 = false;
			_instruction7 = false;
			_instruction8 = false;
			_instruction9 = false;
			_instruction10 = false;
		}
	}

	if (nearWall && breaked && key == 'p' && level2){
		if (fireCollected && windCollected && earthCollected)
		waterCollected = true;
	}

	if (nearGemm && key == 'x' && level2BG && level2){
		gemBreaked = true;
		pressedBreak = true;
	}

	if (gemBreaked && nearGemm && key == 'e' && level2BG && level2){
		entered = true;
		_levelPage = true;
		level2BG = false;
		level2 = false;
		waterCollected = false;
		fireCollected = false;
		windCollected = false;
		earthCollected = false;
		checkFor2 = false;
	}

	if ( _levelPage == true && entered && key == ' ') {
		_instruction7 = true;
	}

	if (_instruction11 && key == '\r'){
		_instruction1 = false;
		_instruction2 = false;
		_instruction3 = false;
		_instruction4 = false;
		_instruction5 = false;
		_instruction6 = false;
		_instruction7 = false;
		_instruction8 = false;
		_instruction9 = false;
		_instruction10 = false;
		_instruction11 = false;

		showOneTime = false;
	}

	if (_instruction10 && key == '\r'){
		_instruction1 = false;
		_instruction2 = false;
		_instruction3 = false;
		_instruction4 = false;
		_instruction5 = false;
		_instruction6 = false;
		_instruction7 = false;
		_instruction8 = false;
		_instruction9 = false;
		_instruction10 = false;

	}

	if (_instruction9 && key == '\r'){
		_instruction1 = false;
		_instruction2 = false;
		_instruction3 = false;
		_instruction4 = false;
		_instruction5 = false;
		_instruction6 = false;
		_instruction7 = false;
		_instruction8 = false;
		_instruction9 = false;
	}



	if (_instruction8 && key == '\r'){
		_instruction1 = false;
		_instruction2 = false;
		_instruction3 = false;
		_instruction4 = false;
		_instruction5 = false;
		_instruction6 = false;
		_instruction7 = false;
		_instruction8 = false;
	}

	if (_instruction7 && key == '\r'){
		_instruction1 = false;
		_instruction2 = false;
		_instruction3 = false;
		_instruction4 = false;
		_instruction5 = false;
		_instruction6 = false;
		_instruction7 = false;
		level3 = true;
		charX = 100;
		charY = 100;
		waterCollected = false;
		fireCollected = false;
		windCollected = false;
		earthCollected = false;
		pickedAir = false;
		digDone = false;
	}

	if (nearAxee2 && key == 'p' && level3){
		pickedAxee2 = true;
		waterCollected = false;
	}

	if (pickedAxee2 && charX > 800 && charX< 860 && charY>0 && charY < 120 && !cutted && key == 'x'){
		cutted = true;
	}

	if (nearRope && key == 'p' && level3 && cutted){
		pickedRope = true;
		waterCollected = false;
	}

	if (nearThrow && key == 't'){
		throwRope();
	}
	if (nearThrow2 && key == 't'){
		throwBall();
	}

	if (done && pullDone == false && key == 'p'){
		pullDone = true;
	}

	if (nearPani && level3 && pullDone &&key == 'x'){
		waterCollected = true;
	}

	if (nearGlass && map2 && key == 'x'){
		pickedGlass = true;
	}

	if (nearLight && key == 'f'){
		lightUpFire2 = true;
	}

	if (nearDirt2 && key == 'x'){
		pickingDirt2 = true;
	}

	if (nearBoat && key == '\r'){
		took = true;
		_instruction1 = false;
		_instruction2 = false;
		_instruction3 = false;
		_instruction4 = false;
		_instruction5 = false;
		_instruction6 = false;
		_instruction7 = false;
		_instruction8 = false;
		_instruction9 = false;
		_instruction10 = false;
		_instruction11 = false;
	}





	if (key == 'w')
{
    // Check if the character can move up without going out of bounds
    if (charY + CHARACTER_HEIGHT <= 594)  // Ensure that the character doesn't go beyond the top
    {
        // Restrict movement if level2 is true and within the restricted area, and breaked is false
        if (!(level2 && !breaked && charX >= 600 && charX <= 1021 && charY + CHARACTER_HEIGHT > 398 && charY + CHARACTER_HEIGHT <= 594)) {
            charY += 20;
            upMovement = true;
        }
    }
}

if (key == 'd')
{
    // Check if the character can move right without going out of bounds
    if (charX + CHARACTER_WIDTH <= 1025)  // Ensure that the character doesn't go beyond the right
    {
        // Restrict movement if level2 is true and within the restricted area, and breaked is false
        if (!(level2 && !breaked && charX + CHARACTER_WIDTH > 600 && charX + CHARACTER_WIDTH <= 1021 && charY >= 398 && charY <= 594)) {
            charX += 20;
            rightMovement = true;
        }
    }
}

if (key == 'a')
{
    // Check if the character can move left without going out of bounds
    if (charX >= 10)  // Ensure that the character doesn't go beyond the left
    {
        // Restrict movement if level2 is true and within the restricted area, and breaked is false
        if (!(level2 && !breaked && charX - CHARACTER_WIDTH < 1021 && charX - CHARACTER_WIDTH >= 600 && charY >= 398 && charY <= 594)) {
            charX -= 20;
            leftMovement = true;
        }
    }
}

if (key == 's')
{
    // Check if the character can move down without going out of bounds
    if (charY >= 10)  // Ensure that the character doesn't go beyond the bottom
    {
        // Restrict movement if level2 is true and within the restricted area, and breaked is false
        if (!(level2 && !breaked && charX >= 600 && charX <= 1021 && charY - CHARACTER_HEIGHT < 594 && charY - CHARACTER_HEIGHT >= 398)) {
            charY -= 20;
            downMovement = true;
        }
    }
}

	




	if (key == 'u'){
		_open = true;
	}

	if (key == 'e' && _open){
		level2 = true;
		charX = 228;
		charY = 348;
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
	blockMovement();
	
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
	if (readyToMove2 && key == GLUT_KEY_DOWN)
	{
		map2 = true;
		charX = 204;
		charY = 217;
		moved = true;
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
	iSetTimer(100, updateWindmillAnimation);
	startAnimation();
	iSetTimer(10, updateforOne);
	iSetTimer(50, updateRope); // Update rope movement at intervals
	iSetTimer(1000, updateBackgroundAnimation);
	iSetTimer(5000, ending);


	
	iStart();
	iSetTimer(100, TextBlink);

	
	return 0;
}