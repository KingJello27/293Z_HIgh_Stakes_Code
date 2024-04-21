#include "main.h"

//Controller
Controller master(E_CONTROLLER_MASTER);

//Motors
Motor leftFront(8, E_MOTOR_GEAR_GREEN, false, E_MOTOR_ENCODER_DEGREES); 
Motor leftMiddle(10, E_MOTOR_GEAR_GREEN, false, E_MOTOR_ENCODER_DEGREES); 
Motor leftBack(7, E_MOTOR_GEAR_GREEN, false, E_MOTOR_ENCODER_DEGREES);
Motor rightFront(13, E_MOTOR_GEAR_GREEN, true, E_MOTOR_ENCODER_DEGREES); 
Motor rightMiddle(14, E_MOTOR_GEAR_GREEN, true, E_MOTOR_ENCODER_DEGREES); 
Motor rightBack(2, E_MOTOR_GEAR_GREEN, true, E_MOTOR_ENCODER_DEGREES); 

Motor hang(9, E_MOTOR_GEAR_RED, false, E_MOTOR_ENCODER_DEGREES); 
Motor intake(1, E_MOTOR_GEAR_BLUE, false, E_MOTOR_ENCODER_DEGREES); 

Imu imu(11);

Motor motors[8] = {leftFront, leftMiddle, leftBack, rightFront, rightMiddle, rightBack, hang, intake};

//Pneumatics
pros::ADIDigitalOut wings1('B');
pros::ADIDigitalOut wings2('A');
pros::ADIDigitalOut rachet('H');


// Chassis constructor
Drive chassis (
  // Left Chassis Ports (negative port will reverse it!)
  //   the first port is the sensored port (when trackers are not used!)
  {-8, -10, -7}

  // Right Chassis Ports (negative port will reverse it!)
  //   the first port is the sensored port (when trackers are not used!)
  ,{13, 14, 2}

  // IMU Port
  ,11

  // Wheel Diameter (Remember, 4" wheels are actually 4.125!)
  //    (or tracking wheel diameter)
  ,3.25

  // Cartridge RPM
  //   (or tick per rotation if using tracking wheels)
  ,600

  // External Gear Ratio (MUST BE DECIMAL)
  //    (or gear ratio of tracking wheel)
  // eg. if your drive is 84:36 where the 36t is powered, your RATIO would be 2.333.
  // eg. if your drive is 36:60 where the 60t is powered, your RATIO would be 0.6.
  ,1.333


  // Uncomment if using tracking wheels
  /*
  // Left Tracking Wheel Ports (negative port will reverse it!)
  // ,{1, 2} // 3 wire encoder
  // ,8 // Rotation sensor

  // Right Tracking Wheel Ports (negative port will reverse it!)
  // ,{-3, -4} // 3 wire encoder
  // ,-9 // Rotation sensor
  */

  // Uncomment if tracking wheels are plugged into a 3 wire expander
  // 3 Wire Port Expander Smart Port
  // ,1
);

// void default_constants() {
//   chassis.set_slew_min_power(80, 80);
//   chassis.set_slew_distance(7, 7);
//   chassis.set_pid_constants(&chassis.headingPID, 11, 0, 20, 0);
//   chassis.set_pid_constants(&chassis.forward_drivePID, 0.45, 0, 5, 0);
//   chassis.set_pid_constants(&chassis.backward_drivePID, 0.45, 0, 5, 0);
//   chassis.set_pid_constants(&chassis.turnPID, 5, 0.003, 35, 15);
//   chassis.set_pid_constants(&chassis.swingPID, 7, 0, 45, 0);
// }