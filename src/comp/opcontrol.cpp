#include "main.h"
#include "robot/globals.hpp"
#include "robot/subsystems/controllers/flywheelController.hpp" // IWYU pragma: keep
#include "robot/subsystems/managers/pneumaticManager.hpp" // IWYU pragma: keep
#include <string> // IWYU pragma: keep
#include "ladybrown.h"
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

    int counter = 0;
    bool tilterState = false;
    tilter.set_value(tilterState);

    bool doinkerState = false;
    doinker.set_value(doinkerState);


    // bool grmState = false;
    // grm.set_value(grmState);

    // //Lady Brown
    // const int start = 0;  
    // const int receive = 22; 
    // const int score = 145; 
    // rotationSensor.reset_position();
    // int currentPosition = 1;


    // loop forever
    while (true) {

        //chassis.tank(); // Tank control
        chassis.arcade_standard(ez::SPLIT); // Standard split arcade
        // chassis.arcade_standard(ez::SINGLE); // Standard single arcade
        // chassis.arcade_flipped(ez::SPLIT); // Flipped split arcade
        // chassis.arcade_flipped(ez::SINGLE); // Flipped single arcade

        // //Rotation Sensor -> Lady Brown Motor
        // rotationSensor.get_position();
        

        // //Shift Key
        // if (controller.get_digital(DIGITAL_L1)){

        //     // //Intake Supressor
        //     // intake.move_voltage(0);

        //     // //Tilter Supressor
        //     // tilt1.set_value(false);
        //     // tilt2.set_value(false);

        //     //Lift Control
        //     // if (controller.get_digital_new_press(DIGITAL_R1)){
                
        //     // }
            

        //     // //Goal Rush Mech Control
        //     // if (controller.get_digital_new_press(DIGITAL_L2)){
        //     // grmState = !grmState;
        //     // grm.set_value(grmState);
        //     // }
        // }

        //Tilter Control
        if (master.get_digital_new_press(DIGITAL_L1)){
        tilterState = !tilterState;
        tilter.set_value(tilterState);
        }

        //Doinker Control
        if (master.get_digital_new_press(DIGITAL_UP)){
        doinkerState = !doinkerState;
        doinker.set_value(doinkerState);
        }

        // //Goal Rush Mech Control
        // if (controller.get_digital_new_press(DIGITAL_L2)){
        // grmState = !grmState;
        // grm.set_value(grmState);
        // }

        //Intake Control
        if (master.get_digital(DIGITAL_R2)){
            intake.move_voltage(-12000);
        }else if (master.get_digital(DIGITAL_R1))
            intake.move_voltage(12000);
        else{
            intake.move_voltage(0);
        }

        //Lady Brown
        // if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L2)) {
        //     if (counter == 0) {
        //         setPosition(30);
        //     }
        //     else if (counter == 1) {
        //         setPosition(130);
        //     }
        //     else if (counter == 2) {
        //         setPosition(0);
        //     }
        //     counter ++;
        //     counter = counter % 3;
        // }

        if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L2)) {
            if (counter == 0) {
                //ladyBrown1.move_absolute(140,127);
                //ladyBrown2.move_absolute(140,127);
                setPosition(20);
            }else if (counter == 1) {
                // ladyBrown1.move_absolute(735,127);
                // ladyBrown2.move_absolute(735,127);
                setPosition(120);
            }
            else if (counter == 2) {
                // ladyBrown1.move_absolute(0,127);
                // ladyBrown2.move_absolute(0,127);
                setPosition(0);
            }
            counter ++;
            counter = counter % 3;
        }

         //Color Sorter

         rgb_value = optical_sensor.get_rgb();

        // if (colorIndex() % 2 == 0) {
        //     if (rgb_value.blue){
        //         color.set_value(true);
        //         pros::delay(800);
        //         color.set_value(false);
        //     }
        // }

        // if (colorIndex() % 2 != 0) {
        //     if (rgb_value.red){
        //         color.set_value(true);
        //         pros::delay(800);
        //         color.set_value(false);
        //     }
        // }



        // delay to save resources
        pros::delay(25);
    }
}