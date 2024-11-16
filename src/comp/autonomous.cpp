#include "main.h"
#include "pros/rtos.hpp"
#include "robot/globals.hpp"
#include "graphics/managers/autonManager.hpp"
#include "robot/subsystems/controllers/flywheelController.hpp" // IWYU pragma: keep
#include "robot/subsystems/managers/pneumaticManager.hpp" // IWYU pragma: keep
#include <algorithm> // IWYU pragma: keep
#include "colorSort.h" // IWYU pragma: keep
#include "ladybrown.h"


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
            chassis.set_drive_pid(2.4,80);
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
            chassis.set_turn_pid(48,100);
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
            chassis.set_drive_pid(6.9, 50);
            chassis.wait_drive();
            pros::delay(1000);

            //touch the pole
            chassis.set_drive_pid(-5, 80);
            chassis.wait_drive();
            chassis.set_turn_pid(0,100);
            chassis.wait_drive();
            chassis.set_drive_pid(11.5, 80);
            chassis.wait_drive();
            doinker.set_value(true);
            pros::delay(250);
            chassis.set_turn_pid(-65,90);
            chassis.wait_drive();
            intake.move_velocity(0);


            break;
        case 1:

            //Blue Right AWP

            //score on alliance stake           
            chassis.set_drive_pid(2.4,80);
            chassis.wait_drive();
            chassis.set_turn_pid(90,100);
            chassis.wait_drive();
            chassis.set_drive_pid(-1.3, 60);
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
            chassis.set_drive_pid(12, 80);
            chassis.wait_drive();
            doinker.set_value(true);
            pros::delay(250);
            chassis.set_turn_pid(-45,90);
            chassis.wait_drive();
            intake.move_velocity(0);


            break;
        case 2:

            //Red Right 1/2 AWP

            //score on alliance stake
            chassis.set_drive_pid(2.4,80);
            chassis.wait_drive();
            chassis.set_turn_pid(90,100);
            chassis.wait_drive();
            chassis.set_drive_pid(-1.5, 60);
            chassis.wait_drive();
            intake.move_velocity(12000);
            pros::delay(750);

            //grab first mobile goal
            chassis.set_drive_pid(1.7, 100);
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
            chassis.set_drive_pid(4,100);
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
        case 3:

            //Blue Left 1/2 AWP
            
            //score on alliance stake
            chassis.set_drive_pid(1.95,80);
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
            chassis.set_drive_pid(5,100);
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
        case 4:

            //Red Left Elim
    
            break;
        case 5:

            //Blue Left Elim

            // Grab first goal
            chassis.set_drive_pid(-24,80);
            chassis.wait_drive();
            tilter.set_value(true);
            pros::delay(1000);

            // turn to rings + intake
            chassis.set_turn_pid(135,100);
            chassis.wait_drive();
            intake.move_velocity(12000);
            pros::delay(750);
            chassis.set_drive_pid(24,80);
            chassis.wait_drive();
            chassis.set_swing_pid(ez::LEFT_SWING, 90, 80);
            chassis.wait_drive();
            chassis.set_drive_pid(-12,80);
            chassis.wait_drive();
            chassis.set_swing_pid(ez::LEFT_SWING, -45, 80);
            chassis.wait_drive();
            pros::delay(2000);
            intake.move_velocity(0);
           
            break;
        case 6:

            //Red Right Elim



            break;
        case 7:

            //Blue Right Elim

            

            break;
        case 8: 

            //Skills

            //score on alliance goal and grab first goal
            intake.move_velocity(12000);
            pros::delay(750);
            intake.move_velocity(0);
            chassis.set_drive_pid(3.3, 100);
            chassis.wait_drive();
            chassis.set_turn_pid(-90, 100);
            chassis.wait_drive();
            tilter.set_value(true);
            chassis.set_drive_pid(-6.2, 100);
            chassis.wait_drive();
            tilter.set_value(false);
            pros::delay(500);

            //score first ring
            chassis.set_turn_pid(15,100);
            chassis.wait_drive();
            intake.move_velocity(12000);
            chassis.set_drive_pid(9, 100);
            chassis.wait_drive();
            pros::delay(750);

            //score second ring
            chassis.set_turn_pid(28,100);
            chassis.wait_drive();
            chassis.set_drive_pid(20, 100);
            chassis.wait_drive();
            pros::delay(1000);

            //grab lady brown ring
            setPosition(20);
            chassis.set_turn_pid(148,100);
            chassis.wait_drive();
            chassis.set_drive_pid(8.5,100);
            chassis.wait_drive();
            pros::delay(1000);
            
            //jitter
            intake.move_velocity(0);
            pros::delay(50);
            intake.move_velocity(12000);
            pros::delay(50);
            intake.move_velocity(0);
            pros::delay(50);
            intake.move_velocity(12000);
            pros::delay(50);
            intake.move_velocity(0);
            pros::delay(50);
            intake.move_velocity(12000);
            pros::delay(50);
            intake.move_velocity(0);

            //score on wall stake
            chassis.set_turn_pid(90,100);
            chassis.wait_drive();
            setPosition(120);
            pros::delay(1000);
            chassis.set_drive_pid(3,100);
            chassis.wait_drive();

            //score third + fourth + fifth rings
            chassis.set_drive_pid(-6,100);
            chassis.wait_drive();
            setPosition(0);
            // intake.move_velocity(12000);
            // chassis.set_turn_pid(180,100);
            // chassis.wait_drive();
            // chassis.set_drive_pid(15,100);
            // chassis.wait_drive();
            // pros::delay(1000);

            // //score sixth ring
            // chassis.set_turn_pid(45,100);
            // chassis.wait_drive();
            // chassis.set_drive_pid(3.5,100);
            // chassis.wait_drive();

            // //drop of mobile goal
            // chassis.set_turn_pid(-10,100);
            // chassis.wait_drive();
            // chassis.set_drive_pid(-3.5,100);
            // chassis.wait_drive();
            // tilter.set_value(true);
            // pros::delay(250);

            // //grab second mobile goal
            // chassis.set_drive_pid(3.5,100);
            // chassis.wait_drive();
            // chassis.set_turn_pid(90,100);
            // chassis.wait_drive();
            // chassis.set_drive_pid(-20,100);
            // chassis.wait_drive();
            // tilter.set_value(false);
            // pros::delay(500);

            // //score seventh ring
            // chassis.set_turn_pid(0,100);
            // chassis.wait_drive();

            // // turn to next ring
            // chassis.set_drive_pid(3.5,100);
            // chassis.wait_drive();

            // // go to ring in the middle
            // chassis.set_turn_pid(45,100);
            // chassis.wait_drive();
            // chassis.set_drive_pid(3.5,100);
            // chassis.wait_drive();
            // chassis.set_drive_pid(-3.5,100);
            // chassis.wait_drive();

            // // go to the next group of rings
            // chassis.set_turn_pid(-90,100);
            // chassis.wait_drive();
            // chassis.set_drive_pid(3.5 ,100);
            // chassis.wait_drive();
            // chassis.set_turn_pid(-180,100);
            // chassis.wait_drive();

            // // intake the new row of ring
            // chassis.set_drive_pid(12 ,100);
            // chassis.wait_drive();
            // chassis.set_turn_pid(315,100);
            // chassis.wait_drive();
            // chassis.set_drive_pid(3.5 ,100);
            // chassis.wait_drive();

            // //pick up ring
            // pros::delay(1000);
            // chassis.set_turn_pid(-165,100);
            // chassis.wait_drive();
            // tilter.set_value(true);
            // pros::delay(250);
            // chassis.set_drive_pid(3 ,100);
            // chassis.wait_drive();



            break;
        case 9:
            break;
        case 10:
            break;
        case 11:
            break;
    }
}


