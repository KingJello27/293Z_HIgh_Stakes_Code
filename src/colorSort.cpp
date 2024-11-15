// #include "colorSort.h"
// #include "ladybrown.h" // IWYU pragma: keep
// #include "main.h"
// #include "pros/rtos.hpp" // IWYU pragma: keep
// #include <iostream> // IWYU pragma: keep
// #include <ostream> // IWYU pragma: keep

// //Color sensor
// extern pros::Optical optical_sensor;
// extern pros::c::optical_rgb_s_t rgb_value;

// pros::ADIDigitalOut colorPiston('C');
// pros::Optical optical_sensor(3);

// //Initialization
// void colorSortInit(){
//     colorPiston.set_value(false);
// }

// // int colorSelect(int index) {
// //     return index;
// // }

// // void blueFilter() {
// //     // Configure the optical sensor for color detection
// //     optical_sensor.set_led_pwm(100);  // Turn on the LED at full brightness

// //     while (true) {
// //         // Get the detected color from the optical sensor
// //         pros::c::optical_rgb_s_t color = optical_sensor.get_rgb();
        
// //         // Check if the detected color is red
// //         if (color.red > color.green && color.red > color.blue && color.red > 50) {
// //             pros::delay(500);
// //             colorPiston.set_value(true);  // Activate the piston
// //             pros::delay(500);
// //         } else {
// //             colorPiston.set_value(false); // Deactivate the piston
// //         }

// //         pros::delay(20);  // Add a short delay to avoid overloading the loop
// //     }
// //     }

// //     void redFilter() {
// //     // Configure the optical sensor for color detection
// //     optical_sensor.set_led_pwm(100);  // Turn on the LED at full brightness

// //     while (true) {
// //         // Get the detected color from the optical sensor
// //         pros::c::optical_rgb_s_t color = optical_sensor.get_rgb();
        
// //         // Check if the detected color is red
// //         if (color.blue > color.green && color.blue > color.red && color.blue > 50) {
// //             pros::delay(500);
// //             colorPiston.set_value(true);  // Activate the piston
// //             pros::delay(500);
// //         } else {
// //             colorPiston.set_value(false); // Deactivate the piston
// //         }

// //         pros::delay(20);  // Add a short delay to avoid overloading the loop
// //         }
// //     }

// //Pseudocode

// //Remove Red Rings
// //If we detect a red ring, extent the piston and wait
// //If wait is complete and ring is still detected, it will keep waiting
// //If wait is complete and ring is gone, piston will retract until another ring is detected
// void removeRed(){
//     optical_sensor.set_led_pwm(100);
//     while(true){
//         pros::c::optical_rgb_s_t color = optical_sensor.get_rgb();
//         if(color.red > color.green && color.red > color.blue && color.red > 50){
//             pros::delay(500);
//             colorPiston.set_value(true);  // Activate the piston
//             pros::delay(500);
//         }else{
//             colorPiston.set_value(false); // Deactivate the piston
//         }
//         pros::delay(20);
//     }
// }

// void removeBlue(){
//     optical_sensor.set_led_pwm(100);
//     while(true){
//         pros::c::optical_rgb_s_t color = optical_sensor.get_rgb();
//         if(color.blue > color.green && color.blue > color.red && color.blue > 50){
//             pros::delay(500);
//             colorPiston.set_value(true);  // Activate the piston
//             pros::delay(500);
//         }else{
//             colorPiston.set_value(false); // Deactivate the piston
//         }
//         pros::delay(20);
//     }
// }

// //Helper Fuction
// bool ringIsBlue(){
//     //Check if ring is blue with if statement 
//     //Return true if blue
//     //Return false if not
// }

// bool ringIsRed(){
//     //Check if ring is red with if statement 
//     //Return true if red
//     //Return false if not
// }


// void asyncColorSortController(void*param){
//     while(!inAutonomous && !inDriverControl)
//         pros::delay(50);
            
//     if(colorIndex%2==0)
//         removeRed();
//     removeBlue();
// }