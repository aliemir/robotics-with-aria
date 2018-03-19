//
// Created by Ali Emir Sen on 26.12.2017.
//

#include "SonarSensor.h"

void SonarSensor::updateSensor(float *ranges) {
    for(int i = 0;i<16;i++) {
        this->ranges[i] = ranges[i];
    }
}

float SonarSensor::getMax() {
    float max = 0;
    for(int i = 0;i<16;i++) {
        if(ranges[i] > max)
            max = ranges[i];
    }
    return max;
}

float SonarSensor::getMin() {
    float min = 99999;
    for(int i = 0;i<16;i++) {
        if(ranges[i] < min)
            min = ranges[i];
    }
    return min;
}

float SonarSensor::getRange(int index) {
    return ranges[index];
}

float SonarSensor::operator[](int i) {
    return getRange(i);
}
