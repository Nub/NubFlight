//
//  ProcessManager.cpp
//  NubFlight
//
//  Created by Zachry Thayer on 3/9/15.
//  Copyright (c) 2015 A_Nub. All rights reserved.
//

#include "ProcessManager.h"

ProcessManager::ProcessManager() {
	maximumProcessingLength = 1.f / 100.f;
}

void ProcessManager::run() {
	running = true;
	while (running) {
		update();
		
		//Allow external interruptions
		if (interrupt) {
			interrupt();
		}
		//Exit
		if (shouldExit) {
			break;
		}
	}
}

void ProcessManager::exit() {
	running = false;
}


void ProcessManager::optimize() {
	//Organize processes via priority
}

void ProcessManager::update() {
	Float updateLength = 0;
	
	for(vector<Process*>::iterator i = processes.begin(); i != processes.end(); ++i ) {
		Process* process = *i;
		
		//Skip over less important processes if our current update has taken too long so far
		if (limitFrequency && process->priority <= NO_PRIORITY) {
			if (updateLength > maximumProcessingLength) {
				continue;//Used instead of break in case processes have not been ordered via self.optimize()
			}
		}
		
		process->update();
		process->endUpdate();
		
		updateLength += process->length;
		
		printf("ProcessManager::update::%s::processLength = \t%f\n", process->name(), process->length);
	}
	printf("ProcessManager::update::looptime = \t\t\t%f\n", updateLength);
}

void ProcessManager::setDesiredFrequency(Float frequency) {
	maximumProcessingLength = 1.f / frequency;
}