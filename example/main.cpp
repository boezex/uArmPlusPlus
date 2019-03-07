/**
 * @file
 * @brief     The uArm module for PC
 * @author    Jorn Bunk
 */
#include "../include/serial.hpp"
#include "../include/uArm.hpp"
#include <iostream>
#include <thread>
#include <string>
#include <math.h>
using namespace std;


void sorteerOpKleur(uArm arm, vector<vector<string>> kaarten, vector<vector<int>> huidigeStapel, vector<vector<int>> nieuweStapel) {
	for (unsigned int i = 0; i < kaarten.size(); i++) {
		for (unsigned int j = 0; j < kaarten[i].size(); j++) {
			arm.move(huidigeStapel[i][0], huidigeStapel[i][1], 35, 20);
			arm.move(huidigeStapel[i][0], huidigeStapel[i][1], 0, 20);
			arm.turnPumpON();
			arm.move(huidigeStapel[i][0], huidigeStapel[i][1], 35, 20);

			switch (kaarten[i][j][kaarten[i][j].size() - 1]) {
			case ('H'): arm.move(nieuweStapel[0][0], nieuweStapel[0][1], 35, 20); break;
			case ('R'): arm.move(nieuweStapel[1][0], nieuweStapel[1][1], 35, 20); break;
			case ('S'): arm.move(nieuweStapel[2][0], nieuweStapel[2][1], 35, 20); break;
			case ('K'): arm.move(nieuweStapel[3][0], nieuweStapel[3][1], 35, 20); break;
			}
			arm.turnPumpOFF();
		}
	}
}


void tekenPi(uArm arm) {
	string Pi = "14159265358979323846264338327950288419716939937510582097494459230781640628620899862803482534211706798214808651328230664709384460955058223172535940812848111745028410270193852110555964462294895493038196442881097566593344612847564823378678316527120190914564856692346034861045432664821339360726024914127372458700660631";
	int x = 315;
	int y = -90;
	int zDown = -15;
	int zUp = 20;
	int stapGrootte = 3;

	arm.move(x, y, zUp, 20);
	arm.move(x, y, zDown, 20);
	for (int i = 0; i < Pi.size(); i++) {
		cout << int(Pi[i]) << i << endl;
		switch (Pi[i]) {
		case ('0'): x += stapGrootte; break;
		case ('1'): x += stapGrootte; y += stapGrootte; break;
		case ('2'): y += stapGrootte; break;
		case ('3'): x -= stapGrootte; y += stapGrootte; break;
		case ('4'): x -= stapGrootte; break;
		case ('5'): x -= stapGrootte; y -= stapGrootte; break;
		case ('6'): y -= stapGrootte; break;
		case ('7'): x -= stapGrootte; y -= stapGrootte; break;
		}
		cout << x << ", " << y << endl;
		arm.move(x, y, zDown, 5, 1);
	}
	arm.move(x, y, zUp, 20);
}


void streepLijn(uArm arm) {
	int lengte = 0;
	int lengteMax = 80;
	int strepen = 0;
	int yAs = -90;
	cout << "Geef een lengte: ";
	cin >> lengte;
	while (lengte > lengteMax) {
		cout << "\nLengte mag niet groter zijn dan " << lengteMax;
		cout << "\nGeef een lengte: ";
		cin >> lengte;
	}
	cout << "Geef het aantal strepen: ";
	cin >> strepen;
	
	for (unsigned int i = 0; i < (strepen); i++) {
		arm.move(200, yAs, 3, 20, 1);
		yAs += (lengte / (strepen));
		arm.move(200, yAs, 3, 20, 1);
		arm.move(200, yAs, 20, 20, 1);
		yAs += (lengte / (strepen));
	}
	arm.move(200, yAs, 3, 20, 1);
}


void test(uArm arm) {
	arm.move(200, 0, 80, 20);
	arm.move(250, 100, 80, 20);
	arm.openClamp();
}


void draaiDriehoek(uArm arm) {
	arm.move(200, 0, 50, 20);
	float cx = 210;
	float cy = 110;

	int x = 200;
	int y = 100;

	int grootte = 50;

	float theta;
	cout << "Hoeveel graden moet elke driehoek gedraaid zijn: ";
	cin >> theta;

	int aantal;
	cout << "Hoeveel driehoeken moeten getekent worden: ";
	cin >> aantal;

	cout << "\n" << theta << ", " << aantal << "\n";
	float tempX;
	float tempY;
	float rotatedX;
	float rotatedY;
	cout << "\nStarting loop\n";
	for (unsigned int i = 0; i < aantal; i++) {
		cout << i;
		arm.move(x, y, 3, 20);
		arm.move(x, y + grootte, 3, 20, 1);
		arm.move(x + grootte, y + grootte, 3, 20, 1);
		arm.move(x + grootte, y, 3, 20, 1);
		arm.move(x, y, 3, 20, 1);
		arm.move(x, y, 50, 20);

		tempX = x - cx;
		tempY = y - cy;

		rotatedX = tempX * cos(theta) - tempY * sin(theta);
		rotatedY = tempX * sin(theta) - tempY * cos(theta);

		x = rotatedX + cx;
		y = rotatedY + cy;
	}


}


int main() {
	uArm arm("\\\\.\\COM8", true, 0);
	// arm.setMode(0);
	//arm.calibreer();
	//tekenPi(arm);
	vector<vector<string>> decks = {
		{"6S", "8H", "3H", "8S", "4H"},
		{"AS", "3S", "6H", "10H", "9S"},
		{"5S", "2S", "7S", "2H", "7H"},
		{"9H", "4S", "5H", "10S", "AH"}
	};
	vector<vector<int>> cor = {
		{300, 150},
		{300, 60},
		{300, -60},
		{300, -150}
	};
	vector<vector<int>> cor_new = {
		{150, 150},
		{150, 60},
		{150, -60},
		{150, -150}
	};
	//sorteerOpKleur(arm, decks, cor, cor_new);
	//this_thread::sleep_for(1s);
	// draaiDriehoek(arm);
	// streepLijn(arm);
	/*
	arm.move(100, 100, 100, 20, 1);
	arm.move(150, 100, 100, 20, 1);
	arm.move(100, 150, 100, 20, 1);
	*/
	arm.move(180, 0, 150, 20, 1);
	arm.move(270, 0, 150, 20, 1);
	arm.move(270, 0, 80, 20, 1);
	arm.move(270, 90, 80, 20, 1);
	arm.move(270, -90, 80, 20, 1);
	arm.move(220, -90, 3, 20, 1);
	arm.move(220, 90, 3, 20, 1);

	arm.move(120, 90, 3, 20, 1);
	arm.move(120, -90, 3, 20, 1);
	arm.move(220, -90, 3, 20, 1);
	for (unsigned int i = 0; i < 100; i++) {
		arm.move((200 + (i / 1.0)), 0, 150, 20, 1);
	}
	
	// arm.move(, 100, 20, 3, 1);

	/*
	arm.move(250, 0, 100, 10);
	arm.turnPumpON();
	arm.move(200, 90,60, 10);
	arm.turnPumpOFF();

	arm.move(200, -30, 60, 30, 1); // move in a straight line
	//arm.moveWrist(30, 50); // only works when wrist is attached.
	
	arm.moveMotor(0,140,50);
	
	
	arm.move(200, 0, 60, 10);

	arm.move(200, 0, 0, 2, 0, true); //move and stop when the limit switch is triggered.
	
	
	arm.move(200, 0, 60, 10);  
	arm.move(200, 45, 60, 10); 
	*/

	arm.move2rest();
}