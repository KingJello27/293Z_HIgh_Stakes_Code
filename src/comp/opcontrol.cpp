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

    bool wing1State = false;
    wings1.set_value(wing1State);

    bool wing2State = false;
    wings2.set_value(wing2State);

    bool rachetState = false;
    rachet.set_value(rachetState);


    while (true) {

        chassis.tank(); // Tank control
        // chassis.arcade_standard(ez::SPLIT); // Standard split arcade
        // chassis.arcade_standard(ez::SINGLE); // Standard single arcade
        // chassis.arcade_flipped(ez::SPLIT); // Flipped split arcade
        // chassis.arcade_flipped(ez::SINGLE); // Flipped single arcade

        //Front Wings Cotrol
        if (master.get_digital_new_press(DIGITAL_L2)){
        wing1State = !wing1State;
        wings1.set_value(wing1State);
        }

        //Back Wings Control
        if (master.get_digital_new_press(DIGITAL_UP)){
        wing2State = !wing2State;
        wings2.set_value(wing2State);
        }

        //Rachet Control
        if (master.get_digital_new_press(DIGITAL_B)){
        rachetState = !rachetState;
        rachet.set_value(rachetState);
        }

        //Hang Control
        if (master.get_digital(DIGITAL_DOWN)){
            hang.move_voltage(12000);
            hang.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
        }else if (master.get_digital(DIGITAL_L1)){
            hang.move_voltage(-12000);
            hang.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
        }else{
            hang.move_voltage(0);
        }

        //Intake Control
        if (master.get_digital(DIGITAL_R2)){
            intake.move_voltage(12000);
        }else if (master.get_digital(DIGITAL_R1))
            intake.move_voltage(-12000);
        else{
            intake.move_voltage(0);
        }


        pros::delay(20);

    }
}
