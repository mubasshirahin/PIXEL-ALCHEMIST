extern bool _start;

bool level1 = false;

bool _open = false;


bool temp1 = false;

extern bool _inventory;


bool _levelPage = false;
bool _mainGameBG = false;

bool rightMovement = false;
bool leftMovement = false;
bool upMovement = false;
bool downMovement = false;

extern bool fogCleared;

int standingCounter = 0;

int charX = 100;
int charY = 300;

int i = 0;

char* downMovementPic[4] = {
	"Images//down1.bmp",
	"Images//down2.bmp",
	"Images//down3.bmp",
	"Images//down4.bmp"
};

char* leftMovementPic[4] = {
	"Images//left1.bmp",
	"Images//left2.bmp",
	"Images//left3.bmp",
	"Images//left4.bmp"
};

char* rightMovementPic[4] = {
	"Images//right1.bmp",
	"Images//right2.bmp",
	"Images//right3.bmp",
	"Images//right4.bmp"
};

char* upMovementPic[4] = {
	"Images//up1.bmp",
	"Images//up2.bmp",
	"Images//up3.bmp",
	"Images//up4.bmp"
};



// Show the level page
void showLevel(){
	if (_start == true){
		_levelPage = true;
		iShowBMP(0, 0, "Images//levelMap.bmp");
		if (_levelPage == true){
			iSetColor(255, 255, 255);
			iText(800, 20, "Press Enter to Continue", GLUT_BITMAP_9_BY_15);
		}
	}
}

int idx1 = -10;  // Start outside the screen on the left (you can adjust this based on your screen size)
int idx2 = 400;  // Same for idx2, starting outside the screen (you can adjust the values based on your screen resolution)

void showIndicatorLevelOne(){
	if (_levelPage == true && _mainGameBG==false)
	iShowBMP2(idx1, idx2, "Images//indicator.bmp", 0);
}

void updateforOne() {
	if (_levelPage == true){
		// Increment the coordinates to move the indicator towards (100, 100)
		if (idx1 < 140) {
			idx1+=2;  // Increment horizontally towards 100
		}
		if (idx2 < 460) {
			idx2+=2;  // Increment vertically towards 100
		}
	}
}

void showDoor(){
	if (_open==false && fogCleared &&_inventory == false)
	iShowBMP2(500, 520, "Images//doorClose.bmp",0);
	if (_open && fogCleared && _inventory == false)
		iShowBMP2(500, 520, "Images//doorOpen.bmp", 0);

}

void showHint(){
	if (level1 == true && _inventory==false){
		iSetColor(0, 0, 0);
		iFilledRectangle(600, 550, 380, 100);
		iSetColor(255,255,255);
		iText(650,570, "Clear the fog to reveal the door", GLUT_BITMAP_9_BY_15);
	}
}

// Show the background of the game
void showBackgroundOfGame(){
	if (_mainGameBG == true){
		iShowBMP(0, 0, "Images//withoutFog.bmp");
		_menuOptions = false;
		temp1 = true;
	}
}

void StandingCounterr(){
	standingCounter++;
	if (standingCounter >= 20){
		downMovement = false;
		upMovement = false;
		leftMovement = false;
		rightMovement = false;
	}
}

// Character plotting function (displays the current image based on movement)
void characterPlot() {
	if (_mainGameBG) {
		// Character animation
		if (downMovement) {
			iShowBMP2(charX, charY, downMovementPic[i], 0);
		}
		else if (leftMovement) {
			iShowBMP2(charX, charY, leftMovementPic[i], 0);
		}
		else if (rightMovement) {
			iShowBMP2(charX, charY, rightMovementPic[i], 0);
		}
		else if (upMovement) {
			iShowBMP2(charX, charY, upMovementPic[i], 0);
		}
		else {
			iShowBMP2(charX, charY, "Images//down1.bmp", 0);
		}

		
	}
}



// Update the animation frame
void DownChange() {
	i++;
	if (i > 3) {
		i = 0; // Reset to the first image after the last one
	}
}

// Handle downward movement animation (cycling through the images)
void movement(){
	if (downMovement) {
		DownChange(); // Call the frame change logic to cycle through the images
		iShowBMP2(charX, charY, downMovementPic[i], 0); // Show the image for the current frame
	}
}





