#include "LaserSensor.h"

void LaserSensor::updateSensor(float *ranges) { min = ranges[0]; max = ranges[1]; }

float LaserSensor::getMax() { return max; }

float LaserSensor::getMin() { return min; }

float LaserSensor::getRange(int index) { return (index == 0) ? min : max; }

float LaserSensor::operator[](int i) { return getRange(i); }