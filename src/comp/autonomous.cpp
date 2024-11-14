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
            
            //Red Left AWP
            
            //score on alliance stake
            chassis.set_drive_pid(1.75,80);
            chassis.wait_drive();
            chassis.set_turn_pid(-90,100);
            chassis.wait_drive();
            chassis.set_drive_pid(-1.2, 60);
            chassis.wait_drive();
            intake.move_velocity(12000);
            pros::delay(750);

            //grab first mobile goal
            chassis.set_drive_pid(1.5, 100);
            chassis.wait_drive();
            tilter.set_value(true);
            chassis.set_turn_pid(53,100);
            chassis.wait_drive();
            chassis.set_drive_pid(-9.5, 80);
            chassis.wait_drive();
            chassis.set_drive_pid(-3, 50);
            chassis.wait_drive();
            tilter.set_value(false);
            pros::delay(1000);

            //score first ring
            chassis.set_turn_pid(187,70);
            chassis.wait_drive();
            chassis.set_drive_pid(8.5,60);
            chassis.wait_drive();
            pros::delay(1500);

            //score second ring
            chassis.set_turn_pid(-90,100);
            chassis.wait_drive();
            chassis.set_drive_pid(8, 50);
            chassis.wait_drive();
            pros::delay(1000);

            //touch the pole
            chassis.set_drive_pid(-5.5, 80);
            chassis.wait_drive();
            chassis.set_turn_pid(0,100);
            chassis.wait_drive();
            chassis.set_drive_pid(12.5, 80);
            chassis.wait_drive();
            doinker.set_value(true);
            pros::delay(250);
            chassis.set_turn_pid(-65,90);
            chassis.wait_drive();
            intake.move_velocity(0);


            break;
        case 1:
    
            //Red Right 1/2 AWP

            //score on alliance stake
            chassis.set_drive_pid(2.4,80);
            chassis.wait_drive();
            chassis.set_turn_pid(90,100);
            chassis.wait_drive();
            chassis.set_drive_pid(-1, 60);
            chassis.wait_drive();
            intake.move_velocity(12000);
            pros::delay(750);

            //grab first mobile goal
            chassis.set_drive_pid(1.5, 100);
            chassis.wait_drive();
            tilter.set_value(true);
            chassis.set_turn_pid(-53,100);
            chassis.wait_drive();
            chassis.set_drive_pid(-9.5, 80);
            chassis.wait_drive();
            chassis.set_drive_pid(-3.5, 50);
            chassis.wait_drive();
            tilter.set_value(false);
            pros::delay(1000);

            //score first ring
            chassis.set_turn_pid(-184,70);
            chassis.wait_drive();
            chassis.set_drive_pid(8,60);
            chassis.wait_drive();
            pros::delay(1500);

            //drop off first goal
            chassis.set_turn_pid(90,100);
            chassis.wait_drive();
            chassis.set_drive_pid(-6,90);
            chassis.wait_drive();
            tilter.set_value(true);
            pros::delay(500);

            //grab second mobile goal
            chassis.set_drive_pid(6,100);
            chassis.wait_drive();
            chassis.set_turn_pid(-90,100);
            chassis.wait_drive();
            chassis.set_drive_pid(-2.5,80);
            chassis.wait_drive();
            chassis.set_turn_pid(-75,100);
            chassis.wait_drive();
            chassis.set_drive_pid(-0.7,50);
            pros::delay(250);
            tilter.set_value(false);
            pros::delay(1000);
            chassis.set_drive_pid(2.5,80);
            chassis.wait_drive();
            intake.move_velocity(0);
            
            break;
        case 2:

            //Blue Left 1/2 AWP
            
           //score on alliance stake
            chassis.set_drive_pid(1.8,80);
            chassis.wait_drive();
            chassis.set_turn_pid(-90,100);
            chassis.wait_drive();
            chassis.set_drive_pid(-1.2, 60);
            chassis.wait_drive();
            intake.move_velocity(12000);
            pros::delay(750);

            //grab first mobile goal
            chassis.set_drive_pid(1.5, 100);
            chassis.wait_drive();
            tilter.set_value(true);
            chassis.set_turn_pid(53,100);
            chassis.wait_drive();
            chassis.set_drive_pid(-9.5, 80);
            chassis.wait_drive();
            chassis.set_drive_pid(-3, 50);
            chassis.wait_drive();
            tilter.set_value(false);
            pros::delay(1000);

            //score first ring
            chassis.set_turn_pid(184,70);
            chassis.wait_drive();
            chassis.set_drive_pid(8,65);
            chassis.wait_drive();
            pros::delay(1500);

            //drop off first goal
            chassis.set_turn_pid(-90,70);
            chassis.wait_drive();
            chassis.set_drive_pid(-6,90);
            chassis.wait_drive();
            tilter.set_value(true);
            pros::delay(500);

            //grab second mobile goal
            chassis.set_drive_pid(6,100);
            chassis.wait_drive();
            chassis.set_turn_pid(90,100);
            chassis.wait_drive();
            chassis.set_drive_pid(-2.3,80);
            chassis.wait_drive();
            chassis.set_turn_pid(65,100);
            chassis.wait_drive();
            chassis.set_drive_pid(-0.75,50);
            pros::delay(350);
            tilter.set_value(false);
            pros::delay(1000);
            chassis.set_drive_pid(2.5,80);
            chassis.wait_drive();
            intake.move_velocity(0);
            
            
            break;
        case 3:

           //Blue Right AWP

            //score on alliance stake
            chassis.set_drive_pid(2.4,80);
            chassis.wait_drive();
            chassis.set_turn_pid(90,100);
            chassis.wait_drive();
            chassis.set_drive_pid(-1, 60);
            chassis.wait_drive();
            intake.move_velocity(12000);
            pros::delay(750);

            //grab first mobile goal
            chassis.set_drive_pid(1.25, 100);
            chassis.wait_drive();
            tilter.set_value(true);
            chassis.set_turn_pid(-53,100);
            chassis.wait_drive();
            chassis.set_drive_pid(-9.5, 80);
            chassis.wait_drive();
            chassis.set_drive_pid(-3.5, 50);
            chassis.wait_drive();
            tilter.set_value(false);
            pros::delay(1000);

            //score first ring
            chassis.set_turn_pid(-187,70);
            chassis.wait_drive();
            chassis.set_drive_pid(7.5,60);
            chassis.wait_drive();
            pros::delay(1500);

            //score second ring
            chassis.set_turn_pid(90,100);
            chassis.wait_drive();
            chassis.set_drive_pid(7, 50);
            chassis.wait_drive();
            pros::delay(1000);

            //touch the pole
            chassis.set_drive_pid(-3.5, 80);
            chassis.wait_drive();
            chassis.set_turn_pid(0,100);
            chassis.wait_drive();
            chassis.set_drive_pid(12.5, 80);
            chassis.wait_drive();
            doinker.set_value(true);
            pros::delay(250);
            chassis.set_turn_pid(-45,90);
            chassis.wait_drive();
            intake.move_velocity(0);

            

            
            break;
        case 4:
        
            //Blue Left Elim



            break;
        case 5:

            //Blue Right Elim


           
            break;
        case 6:

            //Red Left Elim



            break;
        case 7:

            //Red Right Elim

            

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


