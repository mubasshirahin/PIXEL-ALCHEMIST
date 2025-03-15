bool level3 = false;

bool cutted = false;
bool pullDone = false;
bool done = false;
bool map2 = false;


// Background animation variables
int bgX = 0, bgY = 0;  // Position of the background
int bgFrame = 0;  // Animation frame index

char* bgFrames[4] = {
	"Level3//level3_1.bmp",
	"Level3//level3_2.bmp",
	"Level3//level3_3.bmp",
	"Level3//level3_4.bmp"
};

void updateBackgroundAnimation() {
	bgFrame = (bgFrame + 1) % 4;  // Loop through 4 frames
}


bool map3 = false;




void showLv3BG(){
	if (level3 && !cutted && !done && !map2 && !map3){
		iShowBMP(0, 0, "Level3//withoutWaterLv3_1.bmp");
	}
	if (level3 && cutted && !done && !map2 && !map3){
		iShowBMP(0, 0, "Level3//withoutWaterLv3_2.bmp");
	}
	if (level3 && done && !map2 && !map3){
		iShowBMP(0, 0, "Level3//withoutWaterLv3_3.bmp");
	}
	if (level3 && done && pullDone && !map2 && !map3){
		iShowBMP(bgX, bgY, bgFrames[bgFrame]);
	}
	if (level3 && done && pullDone && map2 && !map3){
		iShowBMP(0, 0, "Level3//map2_1.bmp");
	}
	if (level3 && done && pullDone && map2 && map3){
		iShowBMP(0, 0, "Level3//map3.bmp");
	}
}

bool pickedAxee2 = false;
bool nearAxee2 = false;


bool nearRope = false;
bool pickedRope = false;

void showAxee2(){
	if (level3 && !pickedAxee2){
		iShowBMP2(562, 22, "Images//axe.bmp", 0);
	}

	if (charX > 530 && charX< 570 && charY>0 && charY < 100 && pickedAxee2 == false && level3){
		iText(500, 10, "Enter P to Pickup", GLUT_BITMAP_TIMES_ROMAN_24);
		nearAxee2 = true;
	}
	else{
		nearAxee2 = false;
	}
}

void cutTree(){
	if (pickedAxee2 && !cutted && charX > 800 && charX< 860 && charY>0 && charY < 120 && level3){
		iText(500, 10, "Enter X to Cut", GLUT_BITMAP_TIMES_ROMAN_24);
	}
}


void showRope(){
	if (level3 && !pickedRope){
		iShowBMP2(235, 330, "Images//rope.bmp", 0);
	}

	if (charX > 230 && charX< 300 && charY>348 && charY < 384 && pickedRope == false && level3 && cutted){
		iText(500, 10, "Enter P to Pickup", GLUT_BITMAP_TIMES_ROMAN_24);
		nearRope = true;
	}
}

bool nearThrow = false;
bool isThrowing = false; // New flag to control throwing

int ropeidx1 = 0; // Rope's X position
int ropeidx2 = 120; // Rope's Y position


void throwRopeMessage(){
	if (charX > 193 && charX < 811 && charY == 100 && pickedRope && !done && level3){
		iText(500, 10, "Enter T to Throw Rope", GLUT_BITMAP_TIMES_ROMAN_24);
		nearThrow = true;
	}
	else nearThrow = false;
}

void throwRope(){
	if (!isThrowing) {
		// Initialize rope throw from character position
		ropeidx1 = charX;
		ropeidx2 = 120;
		isThrowing = true;
	}
}





void updateRope(){
	if (isThrowing) {
		ropeidx2 += 20; // Move the rope upwards

		// Check if rope reaches the target area
		if (ropeidx2 >= 520 && ropeidx1 > 530 && ropeidx1 < 560){
			done = true;
			isThrowing = false; // Stop throwing when it reaches the destination

		}

		// Reset rope if it misses the target
		if (ropeidx2 > 530) {
			isThrowing = false;
		}
	}
}

void toPull(){
	if (done && pullDone == false && level3){
		iText(500, 10, "Enter P to Pull Rope", GLUT_BITMAP_TIMES_ROMAN_24);
	}
}

extern bool waterCollected;
bool nearPani = false;

void showPani(){
	if (pullDone && !waterCollected){
		iShowBMP2(200, 100, "Images//New Project.bmp",0);
	}

	if (charX > 219 && charX < 264 && charY >106 && charY < 148 && level3 && pullDone && !waterCollected){
		iText(500, 10, "Enter X to Collect", GLUT_BITMAP_TIMES_ROMAN_24);
		nearPani = true;
	}
}

bool moved = false;

bool readyToMove2 = false;
void nextPage1(){
	if (charX > 400 && charX < 800 && charY >0 && charY < 30 && level3 && pullDone && waterCollected && !moved && level3){
		iText(500, 10, "Enter Down to Move", GLUT_BITMAP_TIMES_ROMAN_24);
		readyToMove2 = true;
	}
}

bool pickedGlass = false;

bool nearGlass = false;

void showGlass(){
	if (map2 && !pickedGlass){
		iShowBMP2(880, 187, "Images//glass.bmp", 0);
	}

	if (charX > 864 && charX < 948 && charY >188 && charY < 256 && !pickedGlass && level3){
		iText(500, 10, "Enter X to Collect", GLUT_BITMAP_TIMES_ROMAN_24);
		nearGlass = true;
	}
}


//357///55//

bool nearLight = false;
bool lightUpFire2 = false;

void lightUp(){
	if (charX > 300 && charX<400 && charY > 30 && charY < 80 && map2 && pickedGlass && !lightUpFire2 && level3){
		iText(500, 10, "Enter F to Fire", GLUT_BITMAP_TIMES_ROMAN_24);
		nearLight = true;
	}
}

void showLightingFire(){
	if (map2 && lightUpFire2 && pickedGlass && !map3){
		iShowBMP2(300, 100, "Images//fireForMap2.bmp", 0);
		fireCollected = true;
	}
}

bool nearDirt2 = false;
bool pickingDirt2 = false;

void showDirt2(){
	if (level3 && map2 && !pickingDirt2){
		iShowBMP2(630, 55, "Images//pileOfDirt1.bmp", 0);
	}
}

void showToPickingEarth(){
	if (charX > 638 && charX<756 && charY>26 && charY < 160 && waterCollected && map2 && level3 && !pickingDirt2){
		iText(500, 10, "Enter X to Collect", GLUT_BITMAP_TIMES_ROMAN_24);
		nearDirt2 = true;
		earthCollected = true;
	}
}

bool showOneTime = true;

void checkForInstruction(){
	if (map2 && fireCollected && earthCollected && showOneTime){
		_instruction11 = true;
	}
}

int currentFrame = 0;  // To track which image to show
const int totalFrames = 5;  // Total number of frames in the animation

bool lavaOn = false;

// Array to hold the image file names
char* enemyImages[totalFrames] = {
	"Level3//enemy1.bmp",
	"Level3//enemy2.bmp",
	"Level3//enemy3.bmp",
	"Level3//enemy4.bmp",
	"Level3//enemy5.bmp"
};

// Function to display the current frame of the animation
void displayEnemyAnimation() {
	if (map2 && lavaOn == false){
		iShowBMP2(210, 444, enemyImages[currentFrame], 0);
		iShowBMP2(264, 380, enemyImages[currentFrame], 0);
		iShowBMP2(366, 425, enemyImages[currentFrame], 0);
		iShowBMP2(530, 360, enemyImages[currentFrame], 0);
		iShowBMP2(566, 450, enemyImages[currentFrame], 0);
		iShowBMP2(719, 426, enemyImages[currentFrame], 0);
		iShowBMP2(871, 380, enemyImages[currentFrame], 0);
	}
}

// This function is called automatically to update the frame and create the animation
void updateEnemyAnimation() {
	currentFrame = (currentFrame + 1) % totalFrames;  // Move to the next frame, loop back to 0 after the last frame
}

char* lavaImages[10] = {
	"Level3//lava1.bmp",
	"Level3//lava2.bmp",
	"Level3//lava3.bmp",
	"Level3//lava4.bmp",
	"Level3//lava5.bmp",
	"Level3//lava6.bmp",
	"Level3//lava7.bmp",
	"Level3//lava8.bmp",
	"Level3//lava9.bmp",
	"Level3//lava10.bmp"
};

int crntFrame = 0;

void showLava(){
	if (!showOneTime && map2 && !map3){
		iShowBMP2(200, 350, lavaImages[crntFrame], 0);
		iShowBMP2(250, 350, lavaImages[crntFrame], 0);
		iShowBMP2(300, 350, lavaImages[crntFrame], 0);
		iShowBMP2(350, 350, lavaImages[crntFrame], 0);
		iShowBMP2(700, 350, lavaImages[crntFrame], 0);
		iShowBMP2(750, 350, lavaImages[crntFrame], 0);
		iShowBMP2(800, 350, lavaImages[crntFrame], 0);
		iShowBMP2(850, 350, lavaImages[crntFrame], 0);
		lavaOn = true;
	}
}

void updateLava(){
	crntFrame = (crntFrame + 1) % 10;
}

void showDead(){
	if (lavaOn && !map3){
		iShowBMP2(200, 430, "Level3//dead.bmp", 0);
		iShowBMP2(300, 430, "Level3//dead.bmp", 0);
		iShowBMP2(700, 430, "Level3//dead.bmp", 0);
		iShowBMP2(800, 430, "Level3//dead.bmp", 0);
	}
}

void blockMovement(){
	if (charY > 277 && map2 && lavaOn == false){
		charY = 275;
	}
}

void goToMap3(){
	if (map2 && charX > 400 && charX < 650 && charY>550){
		map3 = true;
		charX = 200;
		charY = 500;
	}
}


void blockFor3(){
	if (charX > 265 && charX<661 && charY>0 && charY < 507 && map3){
		charX = 200;
		charY = 500;
	}
}

bool collision = false;

int bhutX = 700;
int bhutY = 300;

bool goRight = true;
bool goDown = false;
bool goLeft = false;
bool goUp = false;

// To define the movement speed
int speed = 2;  // Adjust the speed as per your need

void showBhut(){
	if (map3 && !collision){
		iShowBMP2(bhutX, bhutY, "Level3//bhut.bmp", 0);
	}
}

void updateBhut(){
	// Right movement
	if (goRight) {
		bhutX += speed;
		if (bhutX >= 950) {
			goRight = false;
			goDown = true;
		}
	}

	// Down movement
	if (goDown) {
		bhutY -= speed;
		if (bhutY <= 140) {
			goDown = false;
			goLeft = true;
		}
	}

	// Left movement
	if (goLeft) {
		bhutX -= speed;
		if (bhutX <= 700) {
			goLeft = false;
			goUp = true;
		}
	}

	// Up movement
	if (goUp) {
		bhutY += speed;
		if (bhutY >= 300) {  // Resetting back to the original position
			goUp = false;
			goRight = true;  // Start moving right again
		}
	}
}

bool nearThrow2 = false;
bool killed = false;

void showToThrow(){
	if (charX > 0 && charX<267 && charY>225 && charY < 395  && map3 && !killed && level3){
		iText(500, 10, "Enter T to Throw Lava", GLUT_BITMAP_TIMES_ROMAN_24);
		nearThrow2 = true;
	}
	else{
		nearThrow2 = false;
	}
}


bool isThrowing2 = false; // New flag to control throwing

int ballidx1 = 0; // Rope's X position
int ballidx2 = 120; // Rope's Y position



void throwBall(){
	if (!isThrowing2) {
		// Initialize rope throw from character position
		ballidx1 = charX;
		ballidx2 = charY;
		isThrowing2 = true;
	}
}

void updateBall(){
	if (isThrowing2) {
		ballidx1 += 50; // Move the rope upwards

		// Check if rope reaches the target area
		if (ballidx1 > bhutX - 10 && ballidx1 < bhutX + 80 && ballidx2 > bhutY - 10 && ballidx2 < bhutY + 80){
			killed = true;
			isThrowing2 = false; // Stop throwing when it reaches the destination
			collision = true;

		}

		// Reset rope if it misses the target
		if (ballidx1 >= 1000) {
			isThrowing2 = false;
		}
	}
}

bool nearBoat = false;
bool took = false;

void takeBoat(){
	if (killed && map3 && charX > 783 && charX<956 && charY>297 && charY < 310 && !took && level3){
		iText(500, 10, "Press Enter to Take Boat", GLUT_BITMAP_TIMES_ROMAN_24);
		nearBoat = true;
	}
	else{
		nearBoat = false;
	}
}

char* EndingImages[10] = {
	"Level3//end1.bmp",
	"Level3//end2.bmp",
	"Level3//end3.bmp",
	"Level3//end4.bmp",
	"Level3//end5.bmp",
	"Level3//end6.bmp",
	"Level3//end7.bmp",
	"Level3//end8.bmp",
	"Level3//end9.bmp",
	"Level3//end10.bmp"	
};

int dd = 0;

bool ok = false;

void ending(){
	if (took && !ok){
		iShowBMP2(0, 0, EndingImages[dd], 0);
		dd++;

		if (dd == 10){
			ok = true;
		}
	}
}
void blackScreen(){
	if (ok){
		iSetColor(0,0,0);
		iFilledRectangle(0, 0, 1100, 1000);
		iSetColor(255, 255, 255);
		iText(350,330, "\"Master the four,become the fifth\"", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(450,300, "-Elder Alaric", GLUT_BITMAP_TIMES_ROMAN_24);
				
	}
}


