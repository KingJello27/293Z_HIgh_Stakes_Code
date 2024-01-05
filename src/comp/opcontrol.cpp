#include "main.h"
#include "robot/globals.hpp"
#include "robot/subsystems/controllers/flywheelController.hpp"
#include "robot/subsystems/managers/pneumaticManager.hpp"
#include <string>

    /**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
 
    void opcontrol() {
    // This is preference to what you like to drive on.
    chassis.set_drive_brake(MOTOR_BRAKE_COAST);

    bool wingState = false;
    wings.set_value(wingState);

    // bool blockerState = false;
    // blocker.set_value(blockerState);

    bool intakeState = false;

    bool cataState = false;


    while (true) {

        chassis.tank(); // Tank control
        // chassis.arcade_standard(ez::SPLIT); // Standard split arcade
        // chassis.arcade_standard(ez::SINGLE); // Standard single arcade
        // chassis.arcade_flipped(ez::SPLIT); // Flipped split arcade
        // chassis.arcade_flipped(ez::SINGLE); // Flipped single arcade

        //Wing Control
        if (master.get_digital_new_press(DIGITAL_R1)){
        wingState = !wingState;
        wings.set_value(wingState);
        }

        // //Blocker Control
        // if (master.get_digital_new_press(DIGITAL_R2)){
        // blockerState = !blockerState;
        // blocker.set_value(blockerState);
        // }

        //Catapult controll
        if (master.get_digital_new_press(DIGITAL_L1)){
            cataState = !cataState;
        }

        if (cataState == true){
            cata.move_voltage(10000);
        }else{
            cata.move_voltage(0);
        }

        //Intake Control
        if (master.get_digital_new_press(DIGITAL_L2)){
            intakeState = !intakeState;
        }

        if (intakeState == true){
            intake.move_voltage(12000);
        }else{
            intake.move_voltage(0);
        }


        pros::delay(20);

    }
}
