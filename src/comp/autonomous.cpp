#include "pros/rtos.hpp"
#include "robot/globals.hpp"
#include "graphics/managers/autonManager.hpp"
#include "robot/subsystems/controllers/flywheelController.hpp"
#include "robot/subsystems/managers/pneumaticManager.hpp"
#include <algorithm>


void tug (int attempts) {
  for (int i=0; i<attempts-1; i++) {
    // Attempt to drive backwards
    printf("i - %i", i);
    chassis.set_drive_pid(12, 127);
    chassis.wait_drive();

    // If failsafed...
    if (chassis.interfered) {
      chassis.reset_drive_sensor();
      chassis.set_drive_pid(-2, 20);
      pros::delay(1000);
    }
    // If robot successfully drove back, return
    else {
      return;
    }
  }
}

// chassis.set_turn_pid(90,90);
// chassis.set_drive_pid(24,127,false);
// chassis.set_swing_pid(ez::LEFT_SWING,90,90);
//chassis.wait_drive();
//chassis.set_exit_condition(chassis.drive_exit, 8000, 5000, 30000, 15000, 50000, 50000);

//24 inches in code is 19.5 irl *Multiply by 0.8125*

void autonomous() {

    switch(autonIndex){
        case 0: 
           
           //Close Side
         
            break;
        case 1:
    
            //Far Side

            break;
        case 2:

            //Skills
            
            break;
        case 3:
           
            break;
        case 4:
            
            break;
        case 5:
           
            break;
        case 6:

            break;
        case 7:
            
            break;
        case 8: 

            break;
        case 9:
            break;
        case 10:
            break;
        case 11:
            break;
    }
}
