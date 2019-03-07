#include "uArm.hpp"
#include <iostream>
#include <thread>
#include <chrono>

void uArm::move(float x, float y, float z, int speed, int G, bool limitSwitch){
		std::string command = 	"G" + std::to_string(G) + " X" + std::to_string(x) + " Y" + std::to_string(y) + 
												" Z" + std::to_string(z) + " F" + std::to_string(speed) +  "\n";
		performCommand(command, limitSwitch);
}

void uArm::move2rest(){
	turnPumpOFF();
	moveWrist(90, 5);
	move(200, 0, 50, 10, 0);
	move(101, 0, 40, 10, 0);
	conn.writeData("M2019\n", 7); // detach motors
}

void uArm::calibreer() {
	openClamp();
	move(150, -100, -15, 20);
	std::cout << "Positioneer de stift in de grijper, en druk op enter om verder te gaan";
	std::cin.get();
	closeClamp();
	Sleep(2000);
}


void uArm::turnPumpON(){
	performCommand("M2231 V1\n");
}

void uArm::turnPumpOFF(){
	performCommand("M2231 V0\n");
}

void uArm::closeClamp() {
	performCommand("M2232 V1\n");
}

void uArm::openClamp() {
	performCommand("M2232 V0\n");
}


void uArm::moveWrist(int angle, int speed){
	moveMotor(3, angle, speed);
}

void uArm::moveMotor(int motor, int angle, int speed){
	performCommand("G2202 N" + std::to_string(motor) + " V" + std::to_string(angle) + " F" + std::to_string(speed) + "\n");
}

void uArm::setMode(int mode){
	performCommand("M2400 S" + std::to_string(mode) + "\n");
}

bool uArm::getLimitSwitch(){
	performCommand("P2233\n");
	return strstr(response, "V1");
}

float uArm::getAngle(int joint){
	// TODO: op forum vragen of #n P2206 N0\n het wel doet op firmware 4.
	return 0;
}

//private:
void uArm::waitDone(uint8_t command_number, bool limitSwitch){
	conn.clearReadBuffer();
	conn.readData(response, response_size);
	while(!strstr(response, (std::to_string(command_number) + " ok").c_str())){
		if(limitSwitch && strstr(response, "@6")){
			break;
		}
		Sleep(200);
		conn.readData(response, response_size);
	}
	if(verbose){
		std::cout << response << "\n";
	}
	conn.clearReadBuffer();
}

void uArm::performCommand(const std::string & command, bool limitSwitch){
		command_number++;
		std::string command_with_n = "#" + std::to_string(command_number) + " " + command;
		
		conn.writeData(command_with_n.c_str(), command_with_n.size());
		
		if(verbose){
			std::cout << command_with_n;
		}
		if (command != "M2231 V1\n" && command != "M2231 V0\n") {
			waitDone(command_number, limitSwitch);
		}
}