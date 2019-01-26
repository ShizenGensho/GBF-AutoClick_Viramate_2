// gw5.cpp : Defines the entry point for the console application.
//

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

void main()
{
	int sleepTime = 10;
	double refreshDelay = 0;
	ifstream inFile;
	int counter = 0;
	//int x;
	string x;
	char ch = 'A';
	int offsetX = 0;
	int offsetY = 0;
	string go = "y";
	string fileChoose = "1.txt";
	/* initialize random seed: */
	srand(time(NULL));
	int variationX;
	int variationY;
	int variantonD;
	//bool zoom = 0;
	int currentChar = 0;

	inFile.open("Settings.txt");
	if (!inFile) {
		cerr << "Unable to open file " << "Settings.txt" << endl;
		exit(1);   // call system to stop
	}

	inFile >> offsetX;
	inFile >> offsetY;
	inFile >> sleepTime;

	//Load a file
	while (go != "`" || '\0') {
		cout << "--- --- --- --- ---\n";
		cout << "Loop #: " << counter << endl;
			
		
		counter++;
		cout << "choose your skill file: \n(no \".txt\" needed)" << endl;
		getline(cin, go);
		fileChoose = go + ".txt";

		inFile.close();
		inFile.open(fileChoose);
		if (!inFile) {
			cerr << "Unable to open file "<< fileChoose << ".txt" <<  endl;
			exit(1);   // call system to stop
		}
		
		//Run all lines of such file
		while (inFile >> x) {

			cout << "ID: " << x << endl;
			ch = x[0];
			variationX = randX();
			variationY = randY();
			variantonD = randD();


			/*
			//Zoomed out
			if (x == ("11") || x == ("12") || x == ("13") || x == ("14"))
			{
				if (zoom == 0) {
					SetCursorPos(50 + offsetX + variationX * 2, 609 + offsetY + variationY * 3);

					cout << "ID: Zooomed Out 1\n";

					mouseClick(sleepTime, variantonD, variationY, variationX);
					zoom = 1;
					currentChar = 1;
					variationX = randX();
					variationY = randY();
					variantonD = randD();
				}
				
			}
			if (x == ("21") || x == ("22") || x == ("23") || x == ("24"))
			{
				if (zoom == 0) {
					SetCursorPos(130 + offsetX + variationX * 2, 609 + offsetY + variationY * 3);

					cout << "ID: Zooomed Out 2\n";

					mouseClick(sleepTime, variantonD, variationY, variationX);
					zoom = 1;
					currentChar = 2;
					variationX = randX();
					variationY = randY();
					variantonD = randD();
				}
				
			}
			if (x == ("31") || x == ("32") || x == ("33") || x == ("34"))
			{
				if (zoom == 0) {
					SetCursorPos(212 + offsetX + variationX * 2, 609 + offsetY + variationY * 3);

					cout << "ID: Zooomed Out 3\n";

					mouseClick(sleepTime, variantonD, variationY, variationX);
					zoom = 1;
					currentChar = 3;
					variationX = randX();
					variationY = randY();
					variantonD = randD();
				}
				
			}
			if (x == ("41") || x == ("42") || x == ("43") || x == ("44"))
			{
				if (zoom == 0) {
					SetCursorPos(293 + offsetX + variationX * 2, 609 + offsetY + variationY * 3);

					cout << "ID: Zooomed Out 4\n";

					mouseClick(sleepTime, variantonD, variationY, variationX);
					zoom = 1;
					currentChar = 4;
					variationX = randX();
					variationY = randY();
					variantonD = randD();
				}
				
			}

			//Zoomed in and skills are in another character
			if ((x == ("11") || x == ("12") || x == ("13") || x == ("14")) && currentChar != 1)//Next skill is MC
			{
				if ((currentChar == 2)) {
					//cout << "\t2->1\n";
					swipeLeft(offsetX, variationX, offsetY, variationY, sleepTime, variantonD);
					

					variationX = randX();
					variationY = randY();
					variantonD = randD();
				}
				if ((currentChar == 3)) {
					//cout << "\t3->1\n";
					swipeLeft(offsetX, variationX, offsetY, variationY, sleepTime, variantonD);
					//cout << "\t3->1\n";
					Sleep(75 + randCustom(15));
					variationX = randX();
					variationY = randY();
					variantonD = randD();
					swipeLeft(offsetX, variationX, offsetY, variationY, sleepTime, variantonD);
					

					variationX = randX();
					variationY = randY();
					variantonD = randD();
				}
				if ((currentChar == 4)) {
					//cout << "\t4->1\n";
					swipeRight(offsetX, variationX, offsetY, variationY, sleepTime, variantonD);
					

					variationX = randX();
					variationY = randY();
					variantonD = randD();
				}
				currentChar = 1;
			}
			if ((x == ("21") || x == ("22") || x == ("23") || x == ("24")) && currentChar != 2)//Next skill is Char2
			{
				if ((currentChar == 3)) {
					//cout << "\t3->2\n";
					swipeLeft(offsetX, variationX, offsetY, variationY, sleepTime, variantonD);
					

					variationX = randX();
					variationY = randY();
					variantonD = randD();
				}
				if ((currentChar == 4)) {
					//cout << "\t4->2\n";
					swipeLeft(offsetX, variationX, offsetY, variationY, sleepTime, variantonD);
					//cout << "\t4->2\n";
					Sleep(75 + randCustom(15));
					variationX = randX();
					variationY = randY();
					variantonD = randD();
					swipeLeft(offsetX, variationX, offsetY, variationY, sleepTime, variantonD);
					

					variationX = randX();
					variationY = randY();
					variantonD = randD();
				}
				if ((currentChar == 1)) {	
					//cout << "\t1->2\n";
					swipeRight(offsetX, variationX, offsetY, variationY, sleepTime, variantonD);
					

					variationX = randX();
					variationY = randY();
					variantonD = randD();
				}
				currentChar = 2;
			}
			if ((x == ("31") || x == ("32") || x == ("33") || x == ("34")) && currentChar != 3)//Next skill is Char3
			{
				if ((currentChar == 4)) {
					//cout << "\t4->3\n";
					swipeLeft(offsetX, variationX, offsetY, variationY, sleepTime, variantonD);
					

					variationX = randX();
					variationY = randY();
					variantonD = randD();
				}
				if ((currentChar == 1)) {
					//cout << "\t1->3\n";
					swipeLeft(offsetX, variationX, offsetY, variationY, sleepTime, variantonD);
					Sleep(75 + randCustom(15));
					variationX = randX();
					variationY = randY();
					variantonD = randD();
					//cout << "\t1->3\n";
					swipeLeft(offsetX, variationX, offsetY, variationY, sleepTime, variantonD);
					

					variationX = randX();
					variationY = randY();
					variantonD = randD();
				}
				if ((currentChar == 2)) {	
					//cout << "\t2->3\n";
					swipeRight(offsetX, variationX, offsetY, variationY, sleepTime, variantonD);
					

					variationX = randX();
					variationY = randY();
					variantonD = randD();
				}
				currentChar = 3;
			}
			if ((x == ("41") || x == ("42") || x == ("43") || x == ("44")) && currentChar != 4)//Next skill is Char4
			{
				if ((currentChar == 1)) {	
					//cout << "\t1->4\n";
					swipeLeft(offsetX, variationX, offsetY, variationY, sleepTime, variantonD);
					

					variationX = randX();
					variationY = randY();
					variantonD = randD();
				}
				if ((currentChar == 2)) {
					//cout << "\t2->4\n";
					swipeRight(offsetX, variationX, offsetY, variationY, sleepTime, variantonD);
					Sleep(75 + randCustom(15));
					variationX = randX();
					variationY = randY();
					variantonD = randD();
					//cout << "\t2->4\n";
					swipeRight(offsetX, variationX, offsetY, variationY, sleepTime, variantonD);
					

					variationX = randX();
					variationY = randY();
					variantonD = randD();
				}
				if ((currentChar == 3)) {	
					//cout << "\t3->4\n";
					swipeRight(offsetX, variationX, offsetY, variationY, sleepTime, variantonD);
					

					variationX = randX();
					variationY = randY();
					variantonD = randD();
				}
				currentChar = 4;
			}
			
			//Summon
			if ((x == ("51") || x == ("52") || x == ("53") || x == ("54") || x == ("55") || x == ("56")) && zoom == 1) {

				variationX = randCustom(20);
				SetCursorPos(48 + offsetX + variationX *2, 477 + offsetY + variationY);//Back
				mouseClick(sleepTime, variantonD, variationY, variationX);

				variationX = randX();
				variationY = randCustom(30);
				variantonD = randD();
				SetCursorPos(387 + offsetX + variationX * 2, 607 + offsetY + variationY * 3);//Open Summons
				mouseClick(sleepTime, variantonD, variationY, variationX);

				variationX = randX();
				variationY = randCustom(15);
				variantonD = randD();
				if (x == ("56")) {
					SetCursorPos(429 + offsetX + variationX, 607 + offsetY + variationY * 3);//Shiva 
					mouseClick(sleepTime, variantonD, variationY, variationX);

					variationY = randY();
					SetCursorPos(346 + offsetX + variationX * 3, 613 + offsetY + variationY / 3);//OK
					//mouseClick(sleepTime, variantonD, variationY, variationX);
					variationX = randX();
					variationY = randY();
					variantonD = randD();
				}
				Sleep(100 + variantonD);
			}
			*/
			

			//Character skills
			//MC
			{
				if (x == "11") {
					SetCursorPos(32 + offsetX + variationX, 710 + offsetY + variationY);
				}//1
				if (x == "12") {
					SetCursorPos(68 + offsetX + variationX, 710 + offsetY + variationY);
				}//2
				if (x == "13") {
					SetCursorPos(32 + offsetX + variationX, 746 + offsetY + variationY);
				}//3
				if (x == "14") {
					SetCursorPos(68 + offsetX + variationX, 746 + offsetY + variationY);
				}//4
			}
			 //Char 2
			{
				if (x == "21") {
					SetCursorPos(113 + offsetX + variationX, 710 + offsetY + variationY);
				}//1
				if (x == "22") {
					SetCursorPos(149 + offsetX + variationX, 710 + offsetY + variationY);
				}//2
				if (x == "23") {
					SetCursorPos(113 + offsetX + variationX, 746 + offsetY + variationY);
				}//3
				if (x == "24") {
					SetCursorPos(149 + offsetX + variationX, 746 + offsetY + variationY);
				}//4
			}
			 //Char 3
			{
				if (x == "31") {
					SetCursorPos(194 + offsetX + variationX, 710 + offsetY + variationY);
				}//1
				if (x == "32") {
					SetCursorPos(230 + offsetX + variationX, 710 + offsetY + variationY);
				}//2
				if (x == "33") {
					SetCursorPos(194 + offsetX + variationX, 746 + offsetY + variationY);
				}//3
				if (x == "34") {
					SetCursorPos(230 + offsetX + variationX, 746 + offsetY + variationY);
				}//4
			}
			 //Char 4
			{
				if (x == "41") {
					SetCursorPos(275 + offsetX + variationX, 710 + offsetY + variationY);
				}//1
				if (x == "42") {
					SetCursorPos(311 + offsetX + variationX, 710 + offsetY + variationY);
				}//2
				if (x == "43") {
					SetCursorPos(275 + offsetX + variationX, 746 + offsetY + variationY);
				}//3
				if (x == "44") {
					SetCursorPos(311 + offsetX + variationX, 746 + offsetY + variationY);
				}//4
			}


			//Skills for 1 Char
			if (x == ("1")) {
				SetCursorPos(146 + offsetX + variationX, 399 + offsetY + variationY);
				Sleep(100 + randCustom(25));
			}//1
			if (x == ("2")) {
				SetCursorPos(240 + offsetX + variationX, 399 + offsetY + variationY);
				Sleep(100 + randCustom(25));
			}//2
			if (x == ("3")) {
				SetCursorPos(338 + offsetX + variationX, 399 + offsetY + variationY);
				Sleep(100 + randCustom(25));
			}//3
			if (x == ("4")) {
				SetCursorPos(146 + offsetX + variationX, 559 + offsetY + variationY);
				Sleep(100 + randCustom(25));
			}//4
			if (x == ("5")) {
				SetCursorPos(240 + offsetX + variationX, 559 + offsetY + variationY);
				Sleep(100 + randCustom(25));
			}//5
			if (x == ("6")) {
				SetCursorPos(338 + offsetX + variationX, 559 + offsetY + variationY);
				Sleep(100 + randCustom(25));
			}//6

			//Only useful for when viramate does not auto-refresh
			if (ch  != 'r') {
				mouseClick(sleepTime, variantonD, variationY, variationX);
			}
			
		}

		//Attack
		variationX = randCustom(64);
		variationY = randCustom(20);
		variantonD = randCustom(82);
		cout << "ID: Attack" << endl;
		cout << "X:" << variationX << ",\tY:" << variationY << ",\tTime(ms):" << variantonD << "\n";
		SetCursorPos(370 + offsetX + variationX, 472 + variationY);
		mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
		Sleep(sleepTime + variantonD);
		

		//AUTO
		variationX = randCustom(36);
		variationY = randCustom(18);
		variantonD = randCustom(82);
		cout << "ID: AUTO" << endl;
		cout << "X:" << variationX << ",\tY:" << variationY << ",\tTime(ms):" << variantonD << "\n";
		SetCursorPos(52 + offsetX + variationX, 501 + variationY);
		mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);

		//Refresh after delay
		//ch = x[0];
		if (ch == 'r') {
			refreshDelay = (stod(x.substr(1)) * 1000);
			Sleep(refreshDelay + variantonD);
			SetCursorPos(352 + offsetX + variationX, 1001 + offsetY + variationY);
			mouseClick(sleepTime, variantonD, variationY, variationX);
		}

		inFile.close();
		//zoom = 0;

		//system("pause");

	}
}