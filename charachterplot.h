extern bool checkFor2;

extern bool ok;

extern bool _instruction1;
extern bool _instruction2;
extern bool _instruction3;
extern bool _instruction4;
extern bool _instruction5;
extern bool _instruction6;
extern bool _instruction7;
extern bool _instruction8;
extern bool _instruction9;
extern bool _instruction10;
extern bool _instruction11;


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

void StandingCounterr(){
	standingCounter++;
	if (standingCounter >= 20){
		downMovement = false;
		upMovement = false;
		leftMovement = false;
		rightMovement = false;
	}
}

extern bool level3;

// Character plotting function (displays the current image based on movement)
void characterPlot() {
	if ((_mainGameBG || checkFor2 || level3) && (_inventory == false) && (!ok) && (!(_instruction1 || _instruction2 || _instruction3 || _instruction4 || _instruction5 || _instruction6 || _instruction7 || _instruction8 || _instruction9 || _instruction10 || _instruction11))) {
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