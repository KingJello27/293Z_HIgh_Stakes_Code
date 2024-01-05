#include "robot/subsystems/controllers/flywheelController.hpp"
#include "pros/rtos.hpp"
#include "robot/globals.hpp"

//For Adi


// double flywheelTarget, flywheelOutput, flywheelInput, flywheelError;
// const double kP = 0.05, kV = 0.03528, threshold = 100;
// //const double kP = 0.5, kV = 0.03528, threshold = 100;

// void setFlywheel(double iTarget){
//     flywheelTarget = iTarget;
// }

// double getFlywheelTarget(){
//     return (flywheelTarget / 36.0);
// }
// double getFlywheelOutput(){
//     return (flywheel.get_actual_velocity() / 6.0);
// }
// double getFlywheelInput(){
//     return (flywheelInput * 100.0 / 127.0);
// }

// void waitUntilFlywheelSettled(){
//     while(flywheelError>=25){
//         pros::delay(20);
//     }
//     pros::delay(20);
// }

// void flywheelInit(){
//     flywheelTarget = 2400;
//     flywheelInput = 0;
//     flywheelOutput = 0;
// }

// void asyncFlywheelController(void* param){
//     while(true){
//         flywheelError = flywheelTarget - flywheel.get_actual_velocity() * 6.0;
        
//         if (flywheelError > threshold){
//             flywheelInput = 127;
//         } 
//         //else if (flywheelError < -threshold){
//         //     flywheelInput = 0;
//         //} 
//         else{
//             flywheelInput = (kV * flywheelTarget) + (kP * flywheelError);
//         }

//         if (flywheelInput > 127){
//             flywheelInput = 127;
//         } else if (flywheelInput < 0){
//             flywheelInput = 0;
//         }

//         flywheel.move(flywheelInput);

//         pros::delay(25);
//     }
// }