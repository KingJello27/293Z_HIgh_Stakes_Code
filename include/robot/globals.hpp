#pragma once
#include "main.h" // IWYU pragma: keep
#include "pros/adi.hpp" // IWYU pragma: keep
#include "pros/distance.hpp" // IWYU pragma: keep

//Controller
extern Controller master;

//Motors
extern pros::Motor intake;
extern pros::Motor motors[8];

//IMU
extern pros::IMU imu;

//Pneumatics
extern pros::ADIDigitalOut tilter, doinker;

//Chassis
extern Drive chassis;