// main_clicker.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "movement.h"

//using namespace std;

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