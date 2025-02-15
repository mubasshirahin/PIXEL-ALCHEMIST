

extern bool _mainGameBG;
bool _inventory = false;
extern bool fireCollected;

void showInventoryIcon(){
	if (_mainGameBG == true){
		iShowBMP2(960, 0, "Images//inventory.bmp", 0);
	}
}

void openInventory(){
	if (_inventory == true){
		 iShowBMP2(0, 0, "Images//inv1.bmp",0);
	}
	if (fireCollected == true && _inventory==true){
		iShowBMP2(0, 0, "Images//inv2.bmp", 0);
	}
	if (waterCollected == true && _inventory == true){
		iShowBMP2(0, 0, "Images//inv3.bmp", 0);
	}
	if (waterCollected == true && _inventory == true && fireCollected==true){
		iShowBMP2(0, 0, "Images//inv4.bmp", 0);
	}

}