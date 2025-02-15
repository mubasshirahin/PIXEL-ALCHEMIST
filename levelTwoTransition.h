extern bool fogCleared;
extern bool level1;

extern bool _open;
extern int charX;
extern int charY;

extern int idx1;
extern int idx2;

bool level2 = false;

void  goTolevel2(){

	if (fogCleared){
		level1 = false;
	}
	if (charX > 450 && charX<600 && charY>450 && charY < 600){
		if (_open == false){
			iSetColor(255, 255, 255);
			iText(400, 10, "Press U to Unlock", GLUT_BITMAP_TIMES_ROMAN_24);
		}
		if (_open){
			iSetColor(255, 255, 255);
			iText(400, 10, "Press E to Enter", GLUT_BITMAP_TIMES_ROMAN_24);
		}
	}
}

void showLevel2(){
	if (level2 == true && _open){
		iShowBMP(0, 0, "Images//levelMap.bmp");
		iShowBMP2(idx1, idx2, "Images//indicator.bmp", 0);
	}
}

void updateForLevel2(){
	if (level2 == true && _open){
		if (idx1 < 429) {
			idx1 += 5;  // Increment horizontally towards 100
		}
		idx2 = 394;
		iSetColor(255, 255, 255);
		iText(800, 20, "Press Enter to Continue", GLUT_BITMAP_9_BY_15);
	}

}