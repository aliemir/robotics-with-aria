#pragma once
#include "RangeSensor.h"

class LaserSensor : public RangeSensor {
private:
    float min,max;
public:
    void updateSensor(float ranges[]);
    float getMax();
    float getMin();
    float getRange(int index);
    float operator[](int i);
};