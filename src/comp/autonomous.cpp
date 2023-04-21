#include "pros/rtos.hpp"
#include "robot/globals.hpp"
#include "graphics/managers/autonManager.hpp"
#include "robot/subsystems/controllers/flywheelController.hpp"
#include "robot/subsystems/managers/pneumaticManager.hpp"
#include <algorithm>

void longShot(){
    intake.move_voltage(-12000);
    waitUntilFlywheelSettled();
    intake.move_voltage(0);

    discStopper.set_value(true);
    pros::delay(150);
    intake.move_voltage(-12000);
    pros::delay(175);
    intake.move_voltage(0);
    discStopper.set_value(false);
    pros::delay(100);

    intake.move_voltage(-12000);
    pros::delay(500);

    waitUntilFlywheelSettled();
    intake.move_voltage(0);

    discStopper.set_value(true);
    pros::delay(150);
    intake.move_voltage(-12000);
    pros::delay(175);
    intake.move_voltage(0);
    discStopper.set_value(false);
    pros::delay(100);

    intake.move_voltage(-12000);
    pros::delay(500);

    waitUntilFlywheelSettled();
    intake.move_voltage(0);

    discStopper.set_value(true);
    pros::delay(150);
    intake.move_voltage(-12000);
    pros::delay(400);
    intake.move_voltage(0);
    discStopper.set_value(false);
    pros::delay(100);

}

 void longShotV2(){
    intake.move_voltage(-12000);
    waitUntilFlywheelSettled();
    intake.move_voltage(0);

    discStopper.set_value(true);
    pros::delay(150);
    intake.move_voltage(-12000);
    pros::delay(150);
    intake.move_voltage(0);
    discStopper.set_value(false);
    pros::delay(100);

    intake.move_voltage(-12000);
    pros::delay(500);

    waitUntilFlywheelSettled();
    intake.move_voltage(0);

    discStopper.set_value(true);
    pros::delay(150);
    intake.move_voltage(-12000);
    pros::delay(400);
    intake.move_voltage(0);
    discStopper.set_value(false);
    pros::delay(100);
 }

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
// chassis.set_swing_pid(ez::LEFT_SWING,90,90);

void autonomous() {

    switch(autonIndex){
        case 0: 
           
            //On Roller
            setFlywheel(3300);
            angleAdjuster.set_value(false);

            chassis.set_drive_pid(2,110,false,true);
            intake.move_relative(-750,6000);
            pros::delay(250);
            
            chassis.set_drive_pid(-5.5,110,false,true);
            chassis.wait_drive();

            chassis.set_turn_pid(-13,90);
            chassis.wait_drive();
            longShotV2();
            setFlywheel(3100);

            chassis.set_turn_pid(-135,90);
            chassis.wait_drive();

            chassis.set_drive_pid(23,95,true,true);
            chassis.wait_drive();
            
            intake.move_velocity(-12000);

            chassis.set_drive_pid(25,65,true,true);
            chassis.wait_drive();
            
            chassis.set_drive_pid(-15,110,true,true);
            chassis.wait_drive();

            chassis.set_turn_pid(-26,90);
            chassis.wait_drive();

            longShot();

            break;
        case 1:
    
            //Off Roller
            setFlywheel(2900);
            angleAdjuster.set_value(false);
            intake.move_velocity(-1200);

            chassis.set_drive_pid(45,110,true,true);
            chassis.wait_drive();
            chassis.set_turn_pid(-139,90);
            chassis.wait_drive();

            chassis.set_drive_pid(-3,95,false,true);
            longShot();
            chassis.set_turn_pid(-225,90);
            chassis.wait_drive();

            intake.move_velocity(-1200);
            chassis.set_drive_pid(70,110,true,true);
            chassis.wait_until(65);
            intake.move_velocity(0);
            chassis.wait_drive();
            
            intake.move_relative(-740,6000);
            pros::delay(250);
            
            chassis.set_drive_pid(-66,110,false,true);
            chassis.wait_drive();
            chassis.set_turn_pid(-138,90);
            chassis.wait_drive();
            
            chassis.set_drive_pid(-3,95,false,true);
            longShotV2();
            intake.move_velocity(-12000);
            discStopper.set_value(true);

            setFlywheel(3100);
            chassis.set_drive_pid(13,90,false,true);
            chassis.wait_drive();

            break;
        case 2:

            //AWP
            setFlywheel(3000);
            angleAdjuster.set_value(false);

            chassis.set_drive_pid(2,110,false,true);
            intake.move_relative(-750,6000);
            pros::delay(250);

            chassis.set_drive_pid(-5.5,110,false,true);
            chassis.wait_drive();

            chassis.set_turn_pid(-135,90);
            chassis.wait_drive();

            chassis.set_drive_pid(23,95,true,true);
            chassis.wait_drive();
            
            intake.move_velocity(-12000);

            chassis.set_drive_pid(25,65,true,true);
            chassis.wait_drive();
            
            chassis.set_turn_pid(-35,90);
            chassis.wait_drive();

            longShot();
            setFlywheel(3200);
            chassis.set_turn_pid(-138,90);
            chassis.wait_drive();

            intake.move_velocity(-12000);
            chassis.set_drive_pid(90,110,true,true);
            chassis.wait_until(60);
            intake.move_velocity(0);
            chassis.wait_drive();

            intake.move_relative(-750,6000);
            pros::delay(750);
            chassis.set_swing_pid(ez::RIGHT_SWING,-80,90);
            chassis.wait_drive();
            
            longShot();
            
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
