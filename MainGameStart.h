extern bool _start;

bool level1 = false;

bool _open = false;


bool temp1 = false;

extern bool _inventory;


bool _levelPage = false;
bool _mainGameBG = false;
extern bool level2BG;

bool rightMovement = false;
bool leftMovement = false;
bool upMovement = false;
bool downMovement = false;

extern bool fogCleared;

int standingCounter = 0;

int charX = 100;
int charY = 300;

int i = 0;





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
	iShowBMP2(400, 400, "Images//greenportal1.bmp",0);
	if (_open && fogCleared && _inventory == false)
		iShowBMP2(400, 400, "Images//greenportal2.bmp", 0);

}

// Show the background of the game
void showBackgroundOfGame(){
	if (_mainGameBG == true){
		iShowBMP(0, 0, "Images//withoutFog.bmp");
		_menuOptions = false;
		temp1 = true;
	}
}	




