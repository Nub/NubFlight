//
//  ProcessManager.h
//  NubFlight
//
//  Created by Zachry Thayer on 3/9/15.
//  Copyright (c) 2015 A_Nub. All rights reserved.
//

#ifndef __NubFlight__ProcessManager__
#define __NubFlight__ProcessManager__

#include <vector>

#include "Process.h"

typedef void (^ProcessInterrupt)();

using namespace std;
class ProcessManager {
	
private:
	Float maximumProcessingLength;
	
	bool running;
	bool shouldExit;
	
	void optimize();
	void update();
	
public:
	vector<Process*> processes;
	
	ProcessInterrupt interrupt;
	
	ProcessManager();
	
	void run();
	void exit();
	
	bool limitFrequency;
	void setDesiredFrequency(Float frequency);
};

#endif /* defined(__NubFlight__ProcessManager__) */
