#pragma once
#include "main.h" // IWYU pragma: keep
#include "pros/adi.hpp" // IWYU pragma: keep
#include "pros/distance.hpp" // IWYU pragma: keep
#include "pros/optical.hpp"

//Controller
extern Controller master;

//Motors
// extern pros::Motor intake, ladyBrown1, ladyBrown2;
extern pros::Motor intake;
extern pros::Motor motors[8];

//IMU
extern pros::IMU imu;

// //Color sensor
// extern pros::Optical optical_sensor;
// extern pros::c::optical_rgb_s_t rgb_value;

//Pneumatics
extern pros::ADIDigitalOut tilter, doinker, color;

//Chassis
extern Drive chassis;