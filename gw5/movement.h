#pragma once

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <conio.h>
#include <fstream>
#include <string>
#include <stdlib.h> 
#include <time.h>    

using namespace std;

int randCustom(int delta) {
	return rand() % (delta * 2) - delta;
}
int randX() {
	return randCustom(12);
}
int randY() {
	return randCustom(12);
}
int randD() {
	return randCustom(80);
}

void mouseClick(int sleepTime, int variationD, int variationX, int variationY) {
	mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
	Sleep(sleepTime + variationD);
	cout << "X:" << variationX << ",\tY:" << variationY << ",\tTime(ms):" << variationD << "\n";
}

void swipeLeft(int offsetX, int variationX, int offsetY, int variationY, int sleepTime, int variantonD) {
	cout << "ID: Swipe Left\n";
	variationY = randCustom(8);
	variationX = randCustom(10);
	SetCursorPos(18 + offsetX + variationX / 2, 633 + offsetY + variationY);//left
	mouseClick(sleepTime, variantonD, variationY, variationX);
}

void swipeRight(int offsetX, int variationX, int offsetY, int variationY, int sleepTime, int variantonD) {
	cout << "ID: Swipe Right\n";
	variationY = randCustom(8);
	variationX = randCustom(10);
	SetCursorPos(460 + offsetX + variationX / 2, 633 + offsetY + variationY);//right
	mouseClick(sleepTime, variantonD, variationY, variationX);
}