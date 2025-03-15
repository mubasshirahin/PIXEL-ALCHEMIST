bool _gameNamePage = true;
bool _menuOptions = false;
bool whenToShowEnterText = true;
bool isHovering1 = false;
bool isHovering2 = false;
bool isHovering3 = false;
bool isHovering4 = false;
bool _menuOptionsTexts = false;
bool _help = false;
bool _credit = false;
bool _sound = true;
bool _back = false;
bool _backHover = false;
bool _start = false;
extern bool _levelPage;

bool forSound = false;

int buttonStartX = 500;
int buttonStartY = 388;
int buttonLeaderX = 455;
int buttonLeaderY = 315;
int buttonHelpX = 490;
int buttonHelpY = 245;
int buttonCreditX = 480;
int buttonCreditY = 175;

int color11 = 0;
int color12 = 0;
int color13 = 0;

int color21 = 0;
int color22 = 0;
int color23 = 0;

int color31 = 0;
int color32 = 0;
int color33 = 0;

int color41 = 0;
int color42 = 0;
int color43 = 0;


void Hover(){
	if (isHovering1 == true){
		color11 = 255;
		color12 = 255;
		color13 = 255;
	}
	else if (isHovering2 == true){
		color21 = 255;
		color22 = 255;
		color23 = 255;
	}
	else if (isHovering3 == true){
		color31 = 255;
		color32 = 255;
		color33 = 255;
	}
	else if (isHovering4 == true){
		color41 = 255;
		color42 = 255;
		color43 = 255;
	}
	else{
		color11 = 0;
		color12 = 0;
		color13 = 0;

		color21 = 0;
		color22 = 0;
		color23 = 0;

		color31 = 0;
		color32 = 0;
		color33 = 0;

		color41 = 0;
		color42 = 0;
		color43 = 0;
	}
}

void backHover(){
	if (_backHover == true && _gameNamePage == false && _menuOptions==false){
		iShowBMP(900, 500, "Images//backHover.bmp");
	}

}

void texts(){
	if (_menuOptionsTexts){
		iSetColor(color11, color12, color13);
		iText(buttonStartX, buttonStartY, "START", GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(color21, color22, color23);
		iText(buttonLeaderX, buttonLeaderY, "LEADERBOARD", GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(color31, color32, color33);
		iText(buttonHelpX, buttonHelpY, "HELP", GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(color41, color42, color43);
		iText(buttonCreditX, buttonCreditY, "CREDITS", GLUT_BITMAP_TIMES_ROMAN_24);
	}
}

void TextBlink(){
	whenToShowEnterText = !whenToShowEnterText;
	if (whenToShowEnterText == true && _gameNamePage == true ){
		iText(800, 20, "Press Enter to Continue", GLUT_BITMAP_9_BY_15);
	}
}

void back(){
	if (_credit == true || _help == true){
		iShowBMP(900, 500, "Images//backk.bmp");
	}
}

void sound(){
	if (_sound == true){
		PlaySound("Music//bg.wav", NULL, SND_LOOP | SND_ASYNC);
	}
	else{
		PlaySound(NULL, 0, 0);
	}
}

void setting(){
}



char* animations[35] = {
	"Animation//ani1.bmp",
	"Animation//ani2.bmp",
	"Animation//ani3.bmp",
	"Animation//ani4.bmp",
	"Animation//ani5.bmp",
	"Animation//ani6.bmp",
	"Animation//ani7.bmp",
	"Animation//ani8.bmp",
	"Animation//ani9.bmp",
	"Animation//ani10.bmp",
	"Animation//ani11.bmp",
	"Animation//ani12.bmp",
	"Animation//ani13.bmp",
	"Animation//ani14.bmp",
	"Animation//ani15.bmp",
	"Animation//ani16.bmp",
	"Animation//ani17.bmp",
	"Animation//ani18.bmp",
	"Animation//ani19.bmp",
	"Animation//ani20.bmp",
	"Animation//ani21.bmp",
	"Animation//ani22.bmp",
	"Animation//ani23.bmp",
	"Animation//ani24.bmp",
	"Animation//ani25.bmp",
	"Animation//ani26.bmp",
	"Animation//ani27.bmp",
	"Animation//ani28.bmp",
	"Animation//ani29.bmp",
	"Animation//ani30.bmp",
	"Animation//ani31.bmp",
	"Animation//ani32.bmp",
	"Animation//ani33.bmp",
	"Animation//ani34.bmp",
	"Animation//ani35.bmp",
};

int z = 0;

void homepage(){
	if (_menuOptions == true){
		_menuOptionsTexts = true;
		iShowBMP(0, 0, "Images\\3.bmp");
	}
	else if (_gameNamePage == true){
		iShowBMP(0, 0, animations[z]);
	}
}

void aniChange() {
	z++;
	if (z >= 35) {
		z = 0; // Reset to the first image after the last one
	}
}

void startAnimation() {
	iSetTimer(100, aniChange);  // Set the interval to 1000 milliseconds (1 second)
}