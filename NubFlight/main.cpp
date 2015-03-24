//
//  main.cpp
//  NubFlight
//
//  Created by Zachry Thayer on 3/9/15.
//  Copyright (c) 2015 A_Nub. All rights reserved.
//

#include <iostream>

#include "ProcessManager.h"
#include "Flight.h"

int main(int argc, const char * argv[]) {
	ProcessManager processManager;
	
	Flight *flight = new Flight();
	flight->controller = new Controller();
	
	flight->pid.kp = Vector3(1, 1, 1);
	flight->pid.ki = Vector3(0.01, 0.01, 0.01);
	flight->pid.kd = Vector3(10, 10, 10);
	
	processManager.processes.push_back(flight);
	processManager.processes.push_back(flight->controller);
	
	processManager.run();
	
	delete flight->controller;
	delete flight;
	
    return 0;
}
