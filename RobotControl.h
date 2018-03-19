#pragma once
#include "RangeSensor.h"
#include "LaserSensor.h"
#include "SonarSensor.h"
#include "Position.h"
#include "RobotInterface.h"
#include "vector"
#include <chrono>
#include <thread>

class RobotControl {
private:
    vector<RangeSensor*> sensor;
    Position * position;
    RobotInterface * robot;
public:
    RobotControl(RobotInterface *robot);
    void safeMove(int speed);
    void connect();
    void disconnect();
    void turnLeft();
    void turnRight();
    void forward();
    void print();
    void moveDistance(float distance);
    void closeWall();
    void stopRobot();
private:
    bool collisionSafe();
    void backward();
};
