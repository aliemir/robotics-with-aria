#include "PioneerRobotInterface.h"

PioneerRobotInterface::PioneerRobotInterface() {
    setRobot(this);
}

void PioneerRobotInterface::update() {
    updateRobot();
}

void PioneerRobotInterface::updateRobot() {
    position->setX(getX());
    position->setY(getY());
    position->setTh(getTh());
    float lranges[2];
    float sranges[16];
    getLaserRange(lranges[0],lranges[1]);
    getSonarRange(sranges);
    laserSensor->updateSensor(lranges);
    sonarSensor->updateSensor(sranges);
}

void PioneerRobotInterface::turn(DIRECTION dir) {
    turnRobot(dir);
}

bool PioneerRobotInterface::open() {
    return connect();
}

void PioneerRobotInterface::move(float speed) {
    moveRobot(speed);
}

bool PioneerRobotInterface::close() {
    return disconnect();
}

void PioneerRobotInterface::stop() {
    stopRobot();
}
