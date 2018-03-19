//
// Created by Ali Emir Sen on 26.12.2017.
//

#include "RobotInterface.h"

void RobotInterface::setPosition(Position *position) {
    this->position = position;
}

void RobotInterface::setRangeSensor(RangeSensor *sonar, RangeSensor *laser) {
    this->laserSensor = laser;
    this->sonarSensor = sonar;
}