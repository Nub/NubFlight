//
//  Flight.h
//  NubFlight
//
//  Created by Zachry Thayer on 3/9/15.
//  Copyright (c) 2015 A_Nub. All rights reserved.
//

#ifndef __NubFlight__Flight__
#define __NubFlight__Flight__

#include <stdio.h>
#include <thread>

#import "Types.h"

#include "Process.h"
#include "Controller.h"
#include "PID.h"
#include "Vector3.h"

Vector3 readGyro();

class Flight: public Process {
	
public:
	Controller* controller;
	PID<Vector3> pid;
	
	virtual void update() {
		Process::update();
		
		Vector3 gyro = readGyro();
		gyro.X = 1;
		gyro.print();
		
		pid.input = gyro;
//		pid.goal = controller
		pid.update();
		gyro += pid.output;
		
		gyro.print();
	}
	
	virtual void endUpdate() {
		Process::endUpdate();
	}
	
	virtual char* name(){
		return (char*)"Flight";
	}
};

Vector3 readGyro(){
	return Vector3(1, 0, 0);
}

#endif /* defined(__NubFlight__Flight__) */
