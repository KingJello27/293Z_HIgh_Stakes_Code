#include "main.h" // IWYU pragma: keep

//Autonomous Manager Fields
int autonIndex;
const char* autonNames[12] = {"Autonomous 1",
                                        "Autonomous 2",
                                        "Autonomous 3",
                                        "Autonomous 4",
                                        "Autonomous 5",
                                        "Autonomous 6",
                                        "Autonomous 7",
                                        "Autonomous 8",
                                        "Autonomous 9",
                                        "Autonomous 10",
                                        "Autonomous 11",
                                        "Autonomous 12"};

const char* autonDescs[12] = {"Red Left AWP",
                                        "Blue Right AWP",
                                        "Red Right 1/2 AWP",
                                        "Blue Left 1/2 AWP",
                                        "Red Left Elim",
                                        "Blue Left Elim",
                                        "Red Right Elim",
                                        "Blue Right Elim",
                                        "Do Nothing",
                                        "Do Nothing",
                                        "Do Nothing",
                                        "Do Nothing"};

//Autonomous Manager Initialization
void autonInit(){
  autonIndex=5;
}

int colorIndex(){
    return autonIndex;
}
