#pragma once
#include "main.h"
#include "pros/adi.hpp"
#include "pros/distance.hpp"

//Controller
extern Controller master;

//Motors
extern pros::Motor cata;
extern pros::Motor intake;
extern pros::Motor motors[8];

//IMU
extern pros::IMU imu;

//Pneumatics
extern pros::ADIDigitalOut wings;

//Chassis
extern Drive chassis;