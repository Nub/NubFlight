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
	
	Orientation controlInputs;
	Orientation gain;
	Orientation expo;
	
public:
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
