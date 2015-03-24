//
//  Types.h
//  NubFlight
//
//  Created by Zachry Thayer on 3/9/15.
//  Copyright (c) 2015 A_Nub. All rights reserved.
//

#ifndef NubFlight_Types_h
#define NubFlight_Types_h

typedef float Float;

typedef struct{
	Float pitch, yaw, roll;
} Orientation;

typedef enum {
	NO_PRIORITY,
	HIGH_PRIORITY,
	MEDIUM_PRIORITY,
	LOW_PRIORITY
} Priority;

#endif
