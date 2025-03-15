#ifndef WATERICON_H
#define WATERICON_H

extern bool _mainGameBG; // Check if level is active

// Water icon position
int waterX = 100, waterY = 100;

// Floating effect variables
int waterOffset = 0;
bool waterMovingUp = true;

bool nearWater = false;
bool waterCollected = false;

// Water icon image
char* waterImage = "Images//New Project.bmp";

// Function to display the water icon
void showWater() {
	if (!waterCollected && _mainGameBG) {
		iShowBMP2(waterX, waterY + waterOffset, waterImage, 0);
		if (nearWater) {
			iSetColor(255,255,255);
			iText(400 , 10, "Press X to collect", GLUT_BITMAP_TIMES_ROMAN_24);
		}
	}
}

// Function to update water floating effect
void updateWaterMovement() {
	if (waterMovingUp) {
		waterOffset += 1;
		if (waterOffset >= 5) waterMovingUp = false;
	}
	else {
		waterOffset -= 1;
		if (waterOffset <= -5) waterMovingUp = true;
	}
}

// Function to check if player is near the water icon
void checkWaterProximity(int charX, int charY) {
	int range = 50; // Interaction range

	// Adjust the range slightly for better detection
	nearWater = (charX >= waterX - range && charX <= waterX + range &&
		charY >= waterY - range && charY <= waterY + range);

	
}

#endif
