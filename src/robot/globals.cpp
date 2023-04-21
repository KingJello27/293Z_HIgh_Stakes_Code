#include "robot/globals.hpp"
#include "okapi/api/control/async/asyncVelocityController.hpp"
#include "okapi/impl/device/distanceSensor.hpp"

//Controller
Controller master(E_CONTROLLER_MASTER);

//Motors
Motor leftFront(7, E_MOTOR_GEARSET_06, true, E_MOTOR_ENCODER_DEGREES); 
Motor leftMiddle(8, E_MOTOR_GEARSET_06, false, E_MOTOR_ENCODER_DEGREES); 
Motor leftBack(9, E_MOTOR_GEARSET_06, true, E_MOTOR_ENCODER_DEGREES); 
Motor rightFront(3, E_MOTOR_GEARSET_06, false, E_MOTOR_ENCODER_DEGREES); 
Motor rightMiddle(4, E_MOTOR_GEARSET_06, true, E_MOTOR_ENCODER_DEGREES); 
Motor rightBack(6, E_MOTOR_GEARSET_06, false, E_MOTOR_ENCODER_DEGREES); 

Motor flywheel(5, E_MOTOR_GEARSET_06, true, E_MOTOR_ENCODER_DEGREES); 
Motor intake(2, E_MOTOR_GEARSET_06, true, E_MOTOR_ENCODER_DEGREES); 

Motor motors[8] = {leftFront, leftMiddle, leftBack, rightFront, rightMiddle, rightBack, flywheel, intake};

//Pneumatics
pros::ADIDigitalOut leftEndgame('C');
pros::ADIDigitalOut rightEndgame('D');
pros::ADIDigitalOut angleAdjuster('A');
pros::ADIDigitalOut discStopper('B');

//Chassis
Drive chassis (
  // Left Chassis Ports (negative port will reverse it!)
  //   the first port is the sensored port (when trackers are not used!)
  {-7,8,-9} 

  // Right Chassis Ports (negative port will reverse it!)
  //   the first port is the sensored port (when trackers are not used!)
  ,{3,-4,6}

  // IMU Port
  ,10

  // Wheel Diameter (Remember, 4" wheels are actually 4.125!)
  //    (or tracking wheel diameter)
  ,2.72

  // Cartridge RPM
  //   (or tick per rotation if using tracking wheels)
  ,600

  // External Gear Ratio (MUST BE DECIMAL)
  //    (or gear ratio of tracking wheel)
  // eg. if your drive is 84:36 where the 36t is powered, your RATIO would be 2.333.
  // eg. if your drive is 36:60 where the 60t is powered, your RATIO would be 0.6.
  ,(60.0/36.0)
);




