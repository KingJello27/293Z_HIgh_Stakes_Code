#include "robot/subsystems/managers/pneumaticManager.hpp"
#include "robot/globals.hpp"

//Pneumatic State Fields
bool discStopperState, endgameState, angleAdjusterState;

//Pneumatic Initializer
void pneumaticInit(){
    discStopperState=false;
    endgameState=false;
    angleAdjusterState=false;

    leftEndgame.set_value(endgameState);
    rightEndgame.set_value(endgameState);
    discStopper.set_value(discStopperState);
    angleAdjuster.set_value(angleAdjusterState);
}

//Pneumatic State Getters
bool getAngleAdjusterState(){
    return angleAdjusterState;
}

bool getDiscStopperState(){
    return discStopperState;
}

bool getEndgameState(){
    return endgameState;
}

//Pneumatic State Togglers
void toggleEndgame(){
    endgameState = !endgameState;
    leftEndgame.set_value(endgameState);
    rightEndgame.set_value(endgameState);
}

void toggleDiscEjector(){
    discStopperState = !discStopperState;
    discStopper.set_value(discStopperState);
}

void toggleAngleAdjuster(){
    angleAdjusterState = !angleAdjusterState;
    angleAdjuster.set_value(angleAdjusterState);
}