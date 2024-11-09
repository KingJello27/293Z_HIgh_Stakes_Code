#include "pros/rtos.hpp"
#include "robot/globals.hpp"
#include "graphics/managers/autonManager.hpp"
#include "robot/subsystems/controllers/flywheelController.hpp" // IWYU pragma: keep
#include "robot/subsystems/managers/pneumaticManager.hpp" // IWYU pragma: keep
#include <algorithm> // IWYU pragma: keep


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



void autonomous() {

    switch(autonIndex){
        case 0: 
            
            //Left AWP
            tilter.set_value(true);
            pros::delay(250);
            chassis.set_drive_pid(-9,60);
            chassis.wait_drive();
            tilter.set_value(false);
            pros::delay(1000);
            intake.move_velocity(12000);
            pros::delay(1000);
            chassis.set_turn_pid(75, 60);
            chassis.wait_drive();
            chassis.set_drive_pid(8, 60);
            chassis.wait_drive();
            pros::delay(1000);
            intake.move_velocity(0);
            chassis.set_turn_pid(-10, 60);
            chassis.wait_drive();
            chassis.set_drive_pid(8.5, 90);
            chassis.wait_drive();
            
            // chassis.set_turn_pid(-135, 60);
            // chassis.wait_drive();
            // tilter.set_value(false);
            // chassis.set_drive_pid(14.5,100);
            // chassis.wait_drive();
            // doinker.set_value(true);
            // pros::delay(500);
            // chassis.set_turn_pid(-150,100);

            


            break;
        case 1:
    
            //Right AWP
            tilter.set_value(true);
            pros::delay(250);
            chassis.set_drive_pid(-9,60);
            chassis.wait_drive();
            tilter.set_value(false);
            pros::delay(1000);
            intake.move_velocity(12000);
            pros::delay(1000);
            chassis.set_turn_pid(-75, 60);
            chassis.wait_drive();
            chassis.set_drive_pid(8, 60);
            chassis.wait_drive();
            pros::delay(1000);
            intake.move_velocity(0);
            chassis.set_turn_pid(10, 60);
            chassis.wait_drive();
            chassis.set_drive_pid(8.5, 90);
            chassis.wait_drive();

            // chassis.set_turn_pid(135, 60);
            // chassis.wait_drive();
            // tilter.set_value(false);
            // chassis.set_drive_pid(14.5,100);
            // chassis.wait_drive();
            // doinker.set_value(true);
            // pros::delay(500);
            // chassis.set_turn_pid(150,100);

            
            break;
        case 2:

            // //Red Left AWP
            // chassis.set_drive_pid(-8.8, 50);
            // chassis.wait_drive();
            // chassis.set_turn_pid(-87, 80);
            // chassis.wait_drive();
            // chassis.set_drive_pid(-2.8,100);
            // chassis.wait_drive();
            // intake.move_velocity(12000);
            // pros::delay(1500);
            // chassis.set_drive_pid(3,100);
            // chassis.wait_drive();
            // chassis.set_turn_pid(133, 80);
            // chassis.wait_drive();
            // tilter.set_value(true);
            // chassis.set_drive_pid(-11.7,60);
            // chassis.wait_drive();
            // tilter.set_value(false);
            // pros::delay(500);
            // chassis.set_turn_pid(-8.5, 60);
            // chassis.wait_drive();
            // chassis.set_drive_pid(4,70);
            // chassis.wait_drive();
            // pros::delay(250);
            // chassis.set_drive_pid(7,40);
            // chassis.wait_drive();
            // pros::delay(800);
            // chassis.set_turn_pid(-85, 60);
            // chassis.wait_drive();
            // chassis.set_drive_pid(5,60);
            // chassis.wait_drive();
            // pros::delay(2000);
            // chassis.set_drive_pid(-4,80);
            // chassis.wait_drive();
            // chassis.set_turn_pid(-180, 60);
            // chassis.wait_drive();
            // chassis.set_drive_pid(13,80);
            // chassis.wait_drive();
            // doinker.set_value(true);
            // chassis.set_turn_pid(-90, 60);
            // chassis.wait_drive();
            
            break;
        case 3:

           //Blue Right AWP
            // chassis.set_drive_pid(-8.8, 50);
            // chassis.wait_drive();
            // chassis.set_turn_pid(87, 80);
            // chassis.wait_drive();
            // chassis.set_drive_pid(-2.8,100);
            // chassis.wait_drive();
            // intake.move_velocity(12000);
            // pros::delay(1500);
            // chassis.set_drive_pid(3,100);
            // chassis.wait_drive();
            // chassis.set_turn_pid(-133, 80);
            // chassis.wait_drive();
            // tilter.set_value(true);
            // chassis.set_drive_pid(-11.7,60);
            // chassis.wait_drive();
            // tilter.set_value(false);
            // pros::delay(500);
            // chassis.set_turn_pid(8.5, 60);
            // chassis.wait_drive();
            // chassis.set_drive_pid(4,70);
            // chassis.wait_drive();
            // pros::delay(250);
            // chassis.set_drive_pid(7,40);
            // chassis.wait_drive();
            // pros::delay(800);
            // chassis.set_turn_pid(85, 60);
            // chassis.wait_drive();
            // chassis.set_drive_pid(5,60);
            // chassis.wait_drive();
            // pros::delay(2000);
            // chassis.set_drive_pid(-4,80);
            // chassis.wait_drive();
            // chassis.set_turn_pid(180, 60);
            // chassis.wait_drive();
            // chassis.set_drive_pid(13,80);
            // chassis.wait_drive();
            // doinker.set_value(true);
            // chassis.set_turn_pid(90, 60);
            // chassis.wait_drive();
            
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


