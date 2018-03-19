#pragma once
#include "PioneerRobotAPI.h"
#include "RobotInterface.h"

class PioneerRobotInterface : public PioneerRobotAPI, public RobotInterface {
public:
    PioneerRobotInterface();
    void update();
    bool open();
    void move(float speed);
    bool close();
    void turn(DIRECTION dir);
    void stop();
    void updateRobot();
};
