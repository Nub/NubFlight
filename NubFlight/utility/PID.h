//
//  PID.h
//  NubFlight
//
//  Created by Zachry Thayer on 3/23/15.
//  Copyright (c) 2015 A_Nub. All rights reserved.
//

#ifndef NubFlight_PID_h
#define NubFlight_PID_h

#include "Types.h"

template <typename T>
class PID {
	T p;
	T i;
	T d;
	
public:
	T input;
	T goal;
	T output;
	
	T kp;
	T ki;
	T kd;
	
	void update() {
		calculatePID();
		calculateOutput();
	}
	
	void calculatePID() {
		Float error = goal - input;
		d = error - p;
		p = error;
		i += p;
	}
	
	void calculateOutput() {
		output = (kp * p) + (ki * i) + (kd * d);
	}
	
};

#endif /* defined(NubFlight_PID_h) */
