#include "PioneerRobotInterface.h"

PioneerRobotInterface::PioneerRobotInterface() { setRobot(this); }

void PioneerRobotInterface::update() { updateRobot(); }

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
    //Carpisma engelleme
    if(!CollisionSafe) {
        cout << "<Collision Danger!>\n";
        stop();
    }
}

void PioneerRobotInterface::turn(DIRECTION dir) { turnRobot(dir); }

bool PioneerRobotInterface::open() { connect(); return true; }

void PioneerRobotInterface::move(float speed) { moveRobot(speed); }

bool PioneerRobotInterface::close() { disconnect(); return true; }

void PioneerRobotInterface::stop() { stopRobot(); }

bool PioneerRobotInterface::CollisionSafe() { 
    for(int i = 0;i<16;i++)
    if(sensor[0]->getRange(i) <= 200) 
        return false;
    return true;
}
