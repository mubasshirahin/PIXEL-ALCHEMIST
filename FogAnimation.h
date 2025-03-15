#ifndef FOGANIMATION_H
#define FOGANIMATION_H

extern bool _mainGameBG;
extern bool fireCollected, waterCollected;
extern bool _instruction3;

// Fog animation frames
char* fogFrames[5] = {
	"Images//Fog1.bmp",
	"Images//Fog2.bmp",
	"Images//Fog3.bmp",
	"Images//Fog5.bmp",
	"Images//Fog6.bmp"
};

int fogX = 0, fogY =0; // Fog position
int fogFrame = 0; // Current animation frame
bool fogCleared = false; // Is fog removed?

void showFog() {
	
	if (_mainGameBG && !fogCleared) {
		iShowBMP2(fogX, fogY, "Images//withFog.bmp", 0);
	}
}

extern bool _instruction4;

bool showed4 = true;

void checkFogClear() {
	if (fireCollected && waterCollected && showed4) {
		//fogCleared = true; // Remove fog
		_instruction4 = true;
	}
}

#endif
