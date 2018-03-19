#include "RobotInterface.h"

void RobotInterface::setPosition(Position *position) { this->position = position; }

void RobotInterface::setRangeSensor(RangeSensor *sonar, RangeSensor *laser) { this->laserSensor = laser; this->sonarSensor = sonar; }