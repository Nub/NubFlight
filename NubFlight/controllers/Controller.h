//
//  Controller.h
//  NubFlight
//
//  Created by Zachry Thayer on 3/9/15.
//  Copyright (c) 2015 A_Nub. All rights reserved.
//

#ifndef __NubFlight__Controller__
#define __NubFlight__Controller__

#include <stdio.h>

#include "Types.h"
#include "Process.h"

class Controller: public Process {
	Float throttle;
	
	Vector3 controlInputs;
	Vector3 controlGain;
	Vector3 controlExpo;
	
public:
	Vector3 adjustedInput() {
		return (controlInputs * controlGain).pow(controlExpo);
	}
	
	virtual void update() {
		Process::update();
		
		
		
	}
	
	virtual void endUpdate() {
		Process::endUpdate();
	}
	
	virtual char* name() {
		return (char*)"Controller";
	}
};

#endif /* defined(__NubFlight__Controller__) */
