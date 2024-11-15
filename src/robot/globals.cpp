#include "main.h" // IWYU pragma: keep
#include "ladybrown.h" // IWYU pragma: keep
#include "colorSort.h" // IWYU pragma: keep

//Controller
Controller master(E_CONTROLLER_MASTER);

//Motors
Motor leftFront(13, E_MOTOR_GEAR_GREEN, true, E_MOTOR_ENCODER_DEGREES); 
Motor leftMiddle(14, E_MOTOR_GEAR_GREEN, true, E_MOTOR_ENCODER_DEGREES); 
Motor leftBack(20, E_MOTOR_GEAR_GREEN, true, E_MOTOR_ENCODER_DEGREES);
Motor rightFront(11, E_MOTOR_GEAR_GREEN, false, E_MOTOR_ENCODER_DEGREES); 
Motor rightMiddle(12, E_MOTOR_GEAR_GREEN, false, E_MOTOR_ENCODER_DEGREES); 
Motor rightBack(19, E_MOTOR_GEAR_GREEN, false, E_MOTOR_ENCODER_DEGREES); 
 
Motor intake(18, E_MOTOR_GEAR_BLUE, false, E_MOTOR_ENCODER_DEGREES); 

Imu imu(16);

// pros::Optical optical_sensor(3);
// pros::c::optical_rgb_s_t rgb_value;


// Motor ladyBrown1(5, E_MOTOR_GEAR_GREEN, false, E_MOTOR_ENCODER_DEGREES);
// Motor ladyBrown2(-4, E_MOTOR_GEAR_GREEN, true, E_MOTOR_ENCODER_DEGREES);

pros::Motor motors[7] = {leftFront, leftMiddle, leftBack, rightFront, rightMiddle, rightBack, intake};

//Pneumatics
pros::ADIDigitalOut tilter('B');
pros::ADIDigitalOut doinker('A');
// pros::ADIDigitalOut color('C');


// Chassis constructor
Drive chassis (
  // Left Chassis Ports (negative port will reverse it!)
  //   the first port is the sensored port (when trackers are not used!)
  {-13, -14, -20}

  // Right Chassis Ports (negative port will reverse it!)
  //   the first port is the sensored port (when trackers are not used!)
  ,{11, 12, 19}

  // IMU Port
  ,16

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