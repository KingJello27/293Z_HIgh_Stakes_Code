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

        double intakeVoltage = 0;
        // *Max Flywheel RPM is 3600
        double flywheelRPM = 2600;

        bool angleAdjusterState = true;
        bool discStopperState = false;

        angleAdjuster.set_value(angleAdjusterState);

        while (true) {
            chassis.tank();

            intake.move_voltage(intakeVoltage);
            setFlywheel(flywheelRPM);

            //Angle Adjuster + Flywheel Control
            if (master.get_digital_new_press(DIGITAL_R1)){
                angleAdjusterState = !angleAdjusterState;
                angleAdjuster.set_value(angleAdjusterState);
                if(angleAdjusterState == true){//Blooper Up
                    flywheelRPM = 2600;
                }else{//Blooper Down
                    flywheelRPM = 2800;
                }
            }

            //Disc Stopper Control
            discStopper.set_value(master.get_digital(DIGITAL_R2));

            //Intake/Roller Control
            if (master.get_digital(DIGITAL_R2)){
                intakeVoltage = -12000;
                
            }else if (master.get_digital(DIGITAL_L1)){
                intakeVoltage = 12000;
            }else if (master.get_digital(DIGITAL_L2)) {
                intakeVoltage = -12000;
            }else{
                intakeVoltage = 0;
            }

            //Endgame Control
            if (master.get_digital_new_press(DIGITAL_LEFT)){
                leftEndgame.set_value(true);
            }

            pros::delay(30);
        }
        
    }
