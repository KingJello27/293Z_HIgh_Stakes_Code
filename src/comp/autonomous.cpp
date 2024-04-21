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



// 9.5 inches in code is 24 irl *Divide by 2.52*

void autonomous() {

    switch(autonIndex){
        case 0: 

           //Close Side AWP
            
            intake.move_relative(-1800,12000);
            chassis.set_drive_pid(-2.75,100);
            chassis.wait_drive();
            chassis.set_swing_pid(ez::RIGHT_SWING,45,127);
            chassis.wait_drive();
            chassis.set_drive_pid(-3.4,100);
            chassis.wait_drive();
            chassis.set_drive_pid(4.5,100);
            chassis.wait_drive();
            chassis.set_turn_pid(10,90);
            chassis.wait_drive();
            wings2.set_value(true);
            pros::delay(100);
            chassis.set_drive_pid(5,100);
            chassis.wait_drive();
            chassis.set_turn_pid(-45,127);
            chassis.wait_drive();
            chassis.set_drive_pid(16,100);
            chassis.wait_drive();


            break;
        case 1:
    
            //Far Side 6 Ball

            intake.move_velocity(-12000);
            pros::delay(1000);
            intake.move_velocity(0);
            chassis.set_drive_pid(-13,100);
            chassis.wait_drive();
            wings2.set_value(true);
            pros::delay(100);
            chassis.set_swing_pid(ez::LEFT_SWING,-45,90);
            chassis.wait_drive();
            chassis.set_turn_pid(0.5,90);
            chassis.wait_drive();
            chassis.set_drive_pid(-2,100);
            chassis.wait_drive();
            chassis.set_swing_pid(ez::LEFT_SWING,-90,80);
            chassis.wait_drive();
            

            chassis.set_drive_pid(-9,100);
            chassis.wait_drive();
            chassis.set_drive_pid(6,100);
            chassis.wait_drive();
            chassis.set_turn_pid(100,90);
            chassis.wait_drive();
            intake.move_velocity(12000);
            chassis.set_drive_pid(8,100);
            chassis.wait_drive();
            chassis.set_drive_pid(-3,100);
            chassis.wait_drive();
            wings2.set_value(false);
            pros::delay(100);

            chassis.set_turn_pid(20,90);
            chassis.wait_drive();
            intake.move_velocity(-12000);
            chassis.set_drive_pid(18.5,100);
            chassis.wait_drive();
            pros::delay(500);
            intake.move_velocity(0);
            chassis.set_turn_pid(165,90);
            chassis.wait_drive();
            intake.move_velocity(12000);
            pros::delay(500);

            intake.move_velocity(-12000);
            chassis.set_turn_pid(70,90);
            chassis.wait_drive();
            chassis.set_drive_pid(7,100);
            chassis.wait_drive();
            pros::delay(350);
            intake.move_velocity(0);
            chassis.set_turn_pid(180,90);
            chassis.wait_drive();
            intake.move_velocity(12000);
            wings1.set_value(true);
            chassis.set_drive_pid(14,100);
            chassis.wait_drive();
            chassis.set_drive_pid(-9.5,100);
           


            break;
        case 2:

            //Far Side AWP
           

            
            break;
        case 3:

            //Close Side Mess Up
           
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


