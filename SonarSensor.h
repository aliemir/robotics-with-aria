#pragma once
#include "RangeSensor.h"

class SonarSensor : public RangeSensor {
private:
    float ranges[16];
public:
    void updateSensor(float ranges[]);
    float getMax();
    float getMin();
    float getRange(int index);
    float operator[](int i);
};
