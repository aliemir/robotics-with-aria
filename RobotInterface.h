#pragma once
#include "RangeSensor.h"
#include "Position.h"

class RobotInterface {
protected:
    Position * position;
    RangeSensor * sonarSensor;
    RangeSensor * laserSensor;
public:
    enum DIRECTION {
        left = -1,
        forward = 0,
        right = 1
    };
    void setPosition(Position *position);
    void setRangeSensor(RangeSensor *sonar,RangeSensor *laser);
    virtual void update() = 0;
    virtual bool open() = 0;
    virtual bool close() = 0;
    virtual void move(float speed) = 0;
    virtual void turn(DIRECTION dir) = 0;
    virtual void stop() = 0;
};