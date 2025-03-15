extern bool _credit;

void credits(){
	if (_credit == true){
		iShowBMP(0, 0, "Images//credits.bmp");
		_menuOptions = false;
	}
}