//
//  Process.h
//  NubFlight
//
//  Created by Zachry Thayer on 3/9/15.
//  Copyright (c) 2015 A_Nub. All rights reserved.
//

#ifndef __NubFlight__Process__
#define __NubFlight__Process__

#include "Types.h"

class Process {
public:
	Priority priority;
	
	Float length;
	clock_t lastStart;
	clock_t lastEnd;
	
	virtual char* name() {
		return (char*)"Process";
	}
	
	virtual void update() {
		lastStart = clock();
	}
	
	virtual void endUpdate() {
		
		lastEnd = clock();
		length = Float(lastEnd - lastStart) / CLOCKS_PER_SEC;
	}

};

#endif /* defined(__NubFlight__Process__) */
