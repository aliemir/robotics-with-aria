#include "RangeSensor.h"

const string &RangeSensor::getType() const {
    return type;
}

void RangeSensor::setType(const string &type) {
    RangeSensor::type = type;
}
