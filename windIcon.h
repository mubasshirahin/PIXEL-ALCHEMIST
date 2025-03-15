#ifndef WINDICON_H
#define WINDICON_H

extern bool level2BG; // Ensure wind appears only in Level 2
extern int charX, charY; // Character position

// Wind icon position (bottom-right corner)
int windX = 700, windY = 40;

// Wind animation frames
int windFrame = 0;
char* windFrames[5] = {
	"Images//wind1_.bmp",
	"Images//wind2_.bmp",
	"Images//wind3_.bmp",
	"Images//wind4_.bmp",
	"Images//wind5_.bmp"
};

// Wind element collection state
bool nearWind = false;
bool windCollected = false;

// Function to display the wind icon
void showWind() {
	if (!windCollected && level2BG) {  // Only show in Level 2 and if not collected
		iShowBMP2(windX, windY, windFrames[windFrame], 0);

		if (nearWind) {  // Show text when near wind element
			iSetColor(255, 255, 255);
			iText(windX - 20, windY + 50, "Press X to collect", GLUT_BITMAP_TIMES_ROMAN_24);
		}
	}
}

// Function to update wind animation
void updateWindAnimation() {
	if (!windCollected && level2BG) {
		windFrame = (windFrame + 1) % 5; // Cycle through 5 frames
	}
}

#endif
