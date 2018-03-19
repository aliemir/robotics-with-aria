//
// Created by Ali Emir Sen on 26.12.2017.
//

#include "LaserSensor.h"

void LaserSensor::updateSensor(float *ranges) {
    min = ranges[0];
    max = ranges[1];
}

float LaserSensor::getMax() {
    return max;
}

float LaserSensor::getMin() {
    return min;
}

float LaserSensor::getRange(int index) {
    if(index == 0)
        return min;
    else
        return max;
}

float LaserSensor::operator[](int i) {
    return getRange(i);
}
