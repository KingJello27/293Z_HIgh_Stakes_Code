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
// chassis.wait_drive();
// chassis.set_exit_condition(chassis.drive_exit, 8000, 5000, 30000, 15000, 50000, 50000);

// chassis.set_swing_pid(ez::LEFT_SWING,90,127); is a right forward swing
// chassis.set_swing_pid(ez::LEFT_SWING,90,127); is a right backward swing

// chassis.set_swing_pid(ez::RIGHT_SWING,90,127); is a left backward swing
// chassis.set_swing_pid(ez::RIGHT_SWING,90,127); is a left forward swing


// 24 inches in code is 19.5 irl *Multiply by 0.8125*

void autonomous() {

    switch(autonIndex){
        case 0: 
           
           //Close Side
         
            intake.move_velocity(-12000);
            pros::delay(500);
            chassis.set_drive_pid(34,100,true,true);
            intake.move_velocity(0);
            chassis.wait_drive();
            chassis.set_turn_pid(45,90);
            chassis.wait_drive();
            chassis.set_drive_pid(12,127,false,false);
            chassis.wait_drive();
            wings.set_value(true);
            chassis.set_drive_pid(-29,127,true,true);
            chassis.wait_drive();
            chassis.set_turn_pid(-195,90);
            intake.move_velocity(12000);
            pros::delay(500);
            wings.set_value(false);
            chassis.set_drive_pid(53,100,true,true);

        
            // chassis.wait_drive();
            // pros::delay(500);
            // chassis.set_turn_pid(-90,127);
            // chassis.wait_drive();
            // pros::delay(500);
            // chassis.set_turn_pid(180,127);
            // chassis.wait_drive();
            // pros::delay(500);

           

            break;
        case 1:
    
            //Far Side

            intake.move_velocity(-12000);
            pros::delay(500);
            chassis.set_drive_pid(-44,100,true,true);
            chassis.wait_drive();
            wings.set_value(true);
            pros::delay(100);
            chassis.set_turn_pid(-30,127);
            chassis.wait_drive();
            chassis.set_drive_pid(-12,100,true,true);
            chassis.wait_drive();
            chassis.set_turn_pid(-85,100);
            chassis.wait_drive();
            pros::delay(100);
            chassis.set_drive_pid(-25,127,true,true);
            chassis.wait_drive();
            chassis.set_drive_pid(15,100,false,false);
            chassis.wait_drive();
            chassis.set_drive_pid(-23,127,true,true);
            chassis.wait_drive();
            chassis.set_drive_pid(10,100,false,false);
            chassis.wait_drive();
            wings.set_value(false);
            pros::delay(100);
            chassis.set_turn_pid(110,50);
            chassis.wait_drive();
            intake.move_velocity(12000);
            chassis.set_drive_pid(19,127,true,true);
            chassis.wait_drive();
            chassis.set_turn_pid(-20,127);
            chassis.set_drive_pid(-10,127,false,false);
            chassis.wait_drive();
            chassis.set_drive_pid(15,127,false,false);
            chassis.wait_drive();
            pros::delay(500);

            

            break;
        case 2:

            //Skills
            chassis.set_drive_pid(-17,100,true,true);
            chassis.wait_drive();
            chassis.set_turn_pid(-20,90);
            chassis.wait_drive();
            wings.set_value(true);
            chassis.set_drive_pid(-4,30,false,false);
            chassis.wait_drive();
            cata.move_velocity(-12000);
            // pros::delay(30000);
            // pros::delay(500);
            // chassis.set_turn_pid(8,90);
            // chassis.wait_drive();
            // wings.set_value(false);
            // pros::delay(100);
            // chassis.set_drive_pid(95,100,true,true);
            // chassis.wait_drive();
            // chassis.set_turn_pid(150,90);
            // chassis.wait_drive();
            // wings.set_value(true);
            // pros::delay(100);
            // chassis.set_drive_pid(-30,100,true,true);
            // chassis.wait_drive();
            // chassis.set_turn_pid(245,90);

            
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


