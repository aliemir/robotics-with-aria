#pragma once
#include <iostream>

using namespace std;

class RangeSensor {
private:
    string type;
public:
    virtual void updateSensor(float ranges[]) = 0;
    virtual float getMin() = 0;
    virtual float getMax() = 0;
    virtual float getRange(int index) = 0;
    virtual float operator[](int i) = 0;

    const string &getType() const;
    void setType(const string &type);
};