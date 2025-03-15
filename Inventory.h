

extern bool _mainGameBG;
bool _inventory = false;
extern bool fireCollected;
extern bool level2;
extern bool level3;
extern bool ok;





void showInventoryIcon(){
	if (_mainGameBG == true || level2BG || level3 && !ok){
		iShowBMP2(10, 0, "Images//inventory.bmp", 0);
	}
}

extern bool earthCollected;
extern bool digDone;
extern bool windCollected;

void openInventory(){
	if (_inventory == true){
		 iShowBMP2(0, 0, "Images//invlevel2.bmp",0);
	}
	if (fireCollected == true && _inventory==true){
		iShowBMP2(295, 397, "Images//fireCollected.bmp", 0);
	}
	if (waterCollected == true && _inventory == true){
		iShowBMP2(178, 397, "Images//waterCollected.bmp", 0);
	}
	if (earthCollected == true && _inventory == true){
		iShowBMP2(529, 397, "Images//earthCollected.bmp", 0);
	}
	if (windCollected == true && _inventory == true){
		iShowBMP2(412, 397, "Images//windCollected.bmp", 0);
	}
}

