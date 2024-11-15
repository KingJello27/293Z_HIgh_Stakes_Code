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

        pros::delay(20);  // Add a short delay to avoid overloading the loop
        }
    }

void asyncColorSortController(void*param){
    while (true){
    if (colorIndex() % 2 == 0)
    redFilter();
    else if (colorIndex() % 2 != 0)
    blueFilter();
    }
}

// double ladyBrownTargetPosition;
// double kP;
// double error;
// double input;
// bool settled = false;

// if (colorIndex() % 2 == 0){

// }else{

// }

// //Rotation Sensor
// pros::Rotation rotationSensor(2);

// //Motors
// Motor ladyBrown1(17, E_MOTOR_GEAR_GREEN, false, E_MOTOR_ENCODER_DEGREES);
// Motor ladyBrown2(1, E_MOTOR_GEAR_GREEN, true, E_MOTOR_ENCODER_DEGREES);

// double getData(){
//     return input;
// }

// //Setters
// void setPosition(double targetPosition){
//     ladyBrownTargetPosition = targetPosition;
// }

// //Async Controller
// void asyncController(void * param){
//     while (true){
//         // settled = false;
//         error = ladyBrownTargetPosition - (rotationSensor.get_position()/100); 
//         if (error < 3 && error > -3){
//             error = 0;
//             // settled = true;
//         }
//         input = kP * error;
//         ladyBrown1.move_voltage(input * 120);
//         ladyBrown2.move_voltage(input * 120);
//         pros::delay(25);
//     }
// }

// // void waitUntilSettled(){
// //     while (settled == false){
// //         pros::delay(25);
// //     }
// // }

