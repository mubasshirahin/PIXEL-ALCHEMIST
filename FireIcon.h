#ifndef FIREICON_H
#define FIREICON_H

extern bool _mainGameBG;
int fireOffset = 0;         // Offset for vertical movement
bool movingUp = true;       // Direction of movement

// Fire icon position
int fireX = 817, fireY = 295;

// Fire animation frames
int fireFrame = 0;
bool nearFire = false;
bool fireCollected = false;

// Fire animation images
char* fireFrames[5] = { 
    "Images//Fire1.bmp",
	"Images//Fire2.bmp", 
    "Images//Fire3.bmp",
	"Images//Fire4.bmp",
	"Images//Fire5.bmp"
};

// Function to display the fire icon
void showFire() {
	if (!fireCollected && _mainGameBG) {  // Fire appears only in main game
		
		iShowBMP2(fireX, fireY + fireOffset, fireFrames[fireFrame], 0);
		if (nearFire) {
			iSetColor(255,255,255);
			iText(400, 10, "Press X to collect", GLUT_BITMAP_TIMES_ROMAN_24);
		}
	}
}
void updateFireMovement() {
	if (!fireCollected) {
		if (movingUp) {
			fireOffset += 1;
			if (fireOffset >= 5) movingUp = false;
		}
		else {
			fireOffset -= 1;
			if (fireOffset <= -5) movingUp = true;
		}
		
	}
}

// Function to update fire animation
void updateFireAnimation() {
	if (!fireCollected && _mainGameBG) {  // Fire animates only in-game
		fireFrame = (fireFrame + 1) % 5;  // Cycle through frames
	}
}

// Function to check if player is near fire
void checkFireProximity(int charX, int charY) {
    int range = 50; // Interaction range
    nearFire = (charX > fireX - range && charX < fireX + range &&
                charY > fireY - range && charY < fireY + range);
}

#endif
