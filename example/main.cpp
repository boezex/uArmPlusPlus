/**
 * @file
 * @brief     The uArm module for PC
 * @author    Jorn Bunk
 */
#include "serial.hpp"
#include "uArm.hpp"
#include <iostream>
#include <thread>
using namespace std;


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


int main() {
    uArm arm("\\\\.\\COM8", true, 0);
	// arm.setMode(0);
	arm.calibreer();
	//this_thread::sleep_for(1s);
	arm.move(200, 100, 80, 20);
	// streepLijn(arm);
	/* 
	arm.move(100, 100, 100, 20, 1);
	arm.move(150, 100, 100, 20, 1);
	arm.move(100, 150, 100, 20, 1);
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
	*/
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