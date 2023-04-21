#pragma once
#include "main.h"

//Pneumatics Initialization
extern void pneumaticInit();

//Pneumatic State Getters
extern bool getAngleAdjusterState();
extern bool getEndgameState();
extern bool getDiscStopperState();

//Pneumatic State Togglers
extern void toggleEndgame();
extern void toggleDiscStoppper();
extern void toggleAngleAdjuster();