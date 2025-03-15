bool level2BG = false;

bool checkFor2 = false;
bool breaked = false;

bool nearWall = false;

bool fireIcon = false;
// Windmill animation variables
int windmillX = 800, windmillY = 100;  // Position of the windmill
int windmillFrame = 0;  // Current frame index



extern bool gemBreaked;
char* windmillFrames[32] = {
	"Images//W1.bmp", "Images//W2.bmp", "Images//W3.bmp", "Images//W4.bmp",
	"Images//W5.bmp", "Images//W6.bmp", "Images//W7.bmp", "Images//W8.bmp",
	"Images//W9.bmp"
};

// Function to show windmill animation
void showWindmill() {
	if (level2BG) {  // Only play in Level 2
		iShowBMP2(windmillX, windmillY, windmillFrames[windmillFrame], 0);
	}
}

// Function to update windmill animation
void updateWindmillAnimation() {
	if (level2BG) {
		windmillFrame = (windmillFrame + 1) % 9;  // Loop through 32 frames
	}
}

void showLevel2BG(){
	if (level2BG == true && fireIcon==false && !breaked && !gemBreaked){
		iShowBMP(0, 0, "Images//level2_1.bmp");
		checkFor2 = true;
	}
	if (level2BG == true && fireIcon && !breaked && !gemBreaked){
		iShowBMP(0, 0, "Images//level2_2.bmp");
		checkFor2 = true;
	}
	if (level2BG == true && fireIcon && breaked && !gemBreaked){
		iShowBMP(0, 0, "Images//level2_3.bmp");
		checkFor2 = true;
	}
	if (level2BG == true && fireIcon && breaked && gemBreaked){
		iShowBMP(0, 0, "Images//level2_4.bmp");
		checkFor2 = true;
	}
	
}	

// Waterfall animation variables
int waterfallX = 600, waterfallY = 380;  // Position of the waterfall
int waterfallFrame = 0;  // Animation frame

char* waterfallFrames[5] = {
	"Images//waterfall1.bmp",
	"Images//waterfall2.bmp",
	"Images//waterfall3.bmp",
	"Images//waterfall4.bmp",
	"Images//waterfall5.bmp"
};

void showWaterfall() {
	if (level2BG) {  // Show only in Level 2
		iShowBMP2(waterfallX, waterfallY, waterfallFrames[waterfallFrame], 0);
	}
}
void updateWaterfallAnimation() {
	if (level2BG) {
		waterfallFrame = (waterfallFrame + 1) % 5;  // Loop through 5 frames
	}
}

bool pickedmatchBox = false;
bool pickedShovel = false;
bool pickedAxe = false;

bool matchpickuptext = false;
bool shovelpickuptext = false;
bool axepickuptext = false;

void showMatchBox(){
	if (level2BG && !pickedmatchBox)
	iShowBMP2(30, 300, "Images//matchboxalt (1).bmp",0);

	if (charX > 76 && charX<155 && charY>390 && charY < 450 && pickedmatchBox==false){
		iText(500, 10, "Enter P to Pickup", GLUT_BITMAP_TIMES_ROMAN_24);
		matchpickuptext = true;
	}
}

void showShovel(){
	if (level2BG && !pickedShovel)
		iShowBMP2(110, 310, "Images//Shovel1.bmp",0);

	if (charX > 254 && charX<340 && charY>460 && charY < 525 && pickedShovel == false){
		iText(500, 10, "Enter P to Pickup", GLUT_BITMAP_TIMES_ROMAN_24);
		shovelpickuptext = true;
	}
}


void showAxe(){
	if (level2BG && !pickedAxe)
		iShowBMP2(555, 22, "Images//axe.bmp",0);

	if (charX > 530 && charX< 570 && charY>0 && charY < 100 && pickedAxe == false){
		iText(500, 10, "Enter P to Pickup", GLUT_BITMAP_TIMES_ROMAN_24);
		axepickuptext = true;
	}
}

bool nearrFire = false;

void lightUpFire(){
	if (pickedmatchBox && charX > 100 && charX< 200 && charY>100 && charY < 200 && fireIcon==false){
		iText(500, 10, "Enter F to Fire", GLUT_BITMAP_TIMES_ROMAN_24);
		nearrFire = true;
	}
}

bool nearrDig = false;

void digging(){
	if (pickedShovel &&  charX > 254 && charX<340 && charY>460 && charY < 525 && !digDone){
		iText(500, 10, "Enter X to Dig", GLUT_BITMAP_TIMES_ROMAN_24);
		nearrDig = true;
	}
}

bool digDone = false;

bool earthCollected = false;

void showDirt(){
	if (digDone && level2 && level2BG){
		iShowBMP2(150, 444, "Images//pileOfDirt1.bmp", 0);
		earthCollected = true;
	}
}

bool nearAir = false;
bool pickedAir = false;
extern bool windCollected;

void collectAir(){

	if (charX > 730 && charX< 840 && charY>90 && charY < 180 && !pickedAir && level2){
		iText(500, 10, "Enter X to Collect", GLUT_BITMAP_TIMES_ROMAN_24);
		nearAir = true;
	}
}

extern bool _instruction10;

void takeAir(){
	if (pickedAir){
		windCollected = true;
	}
}


void breakWall(){
		if (charX > 651 && charX< 905 && charY>327 && charY < 395 && pickedAxe && fireCollected && !breaked){

		iText(500, 10, "Enter X to Break", GLUT_BITMAP_TIMES_ROMAN_24);
		nearWall = true;
	}
}

void collectWater(){
	if (breaked && !waterCollected && nearWall && level2 && level2BG){
		iText(500, 10, "Enter P to Collect", GLUT_BITMAP_TIMES_ROMAN_24);
	}
}

extern bool _instruction6;
bool showeddd = false;

void collected4elements(){
	if (fireCollected && waterCollected && windCollected && earthCollected && level2 && !showeddd){
		_instruction6 = true;
	}
}

bool nearGemm = false;
bool gemBreaked = false;

bool pressedBreak = false;

char* gemBreakFrames[5] = {
	"Images//explosion1.bmp",
	"Images//explosion2.bmp",
	"Images//explosion3.bmp",
	"Images//explosion4.bmp",
	"Images//explosion5.bmp"
};

void showToBreakgem(){
	if (charX > 460 && charX< 590 && charY>462 && charY < 560 && fireCollected && waterCollected && windCollected && earthCollected && level2 && !pressedBreak){
		iText(500, 10, "Enter X to Break", GLUT_BITMAP_TIMES_ROMAN_24);
		nearGemm = true;
	}
}

int gemBreakFrame = 0;
bool playingGemBreakAnim = false;
bool showing = true;
bool portalVisible = false;

void showGemBreakAnimation() {
	if (gemBreaked && gemBreakFrame < 5 && !portalVisible) {
		iShowBMP2(456, 459, gemBreakFrames[gemBreakFrame], 0);
		playingGemBreakAnim = true;
	}
}



void updateGemBreakAnimation() {
	if (playingGemBreakAnim) {
		if (gemBreakFrame < 4) {
			gemBreakFrame++;  // Move to the next frame
		}
		else {
			playingGemBreakAnim = false;  // Stop animation after last frame
			showing = false;
			gemBreaked = true;  // Mark gem as broken
			portalVisible = true;
		}
	}
}

int portalFrame = 0;  // Tracks the animation frame
int portalX = 400, portalY = 420;  // Adjust as needed

char* portalFrames[5] = {
	"Images//greenportal1.bmp",
	"Images//greenportal2.bmp",
	"Images//greenportal3.bmp",
	"Images//greenportal4.bmp",
	"Images//greenportal5.bmp"
};

void showPortal() {

	if (portalVisible && level2BG) {
		iShowBMP2(portalX, portalY, portalFrames[portalFrame], 0);
		playingGemBreakAnim = false;
		showing = false;
	}
} 

// Function to update portal animation
void updatePortalAnimation() {
	if (portalVisible && level2BG) {
		portalFrame = (portalFrame + 1) % 5;  // Loop through 3 frames
	}
}


bool entered = false;


void afterGemBreaked(){
	if (gemBreaked && nearGemm && !entered){
		iText(500, 10, "Enter E to Enter", GLUT_BITMAP_TIMES_ROMAN_24);
	}
}

