#include "RobotControl.h"

RobotControl::RobotControl(RobotInterface *robot) : robot(robot) {
    position = new Position;
    sensor.push_back(new SonarSensor);
    sensor.push_back(new LaserSensor);
    robot->setPosition(position);
    robot->setRangeSensor(sensor[0],sensor[1]);
    sensor[0]->setType("Sonar");
    sensor[1]->setType("Laser");
}

void RobotControl::safeMove(int speed) {
    robot->move(speed);
    while(collisionSafe())
        this_thread::sleep_for(chrono::seconds(1));
    robot->stop();
}

void RobotControl::turnLeft() {
    robot->turn(robot->left);
    this_thread::sleep_for(chrono::seconds(1));
}

void RobotControl::turnRight() {
    robot->turn(robot->right);
    this_thread::sleep_for(chrono::seconds(1));
}

void RobotControl::forward() {
    robot->turn(robot->forward);
    this_thread::sleep_for(chrono::seconds(1));
}

void RobotControl::backward() {
    robot->turn(robot->left);
    this_thread::sleep_for(chrono::seconds(1));
    robot->turn(robot->left);
    this_thread::sleep_for(chrono::seconds(1));
}

void RobotControl::print() {
    cout << "Robot's Position " << "[ " << position->getX() << ", " << position->getY() << ", " << position->getTh() << " ]\n";
    cout << sensor[0]->getType() << " Sensors \n << ";
    for(int i = 0;i<16;i++)
        cout << sensor[0]->getRange(i) << " - ";
    cout << " >> \n";
    cout << sensor[1]->getType() << " Sensors \n << ";
    cout << " Min : " << sensor[1]->getMin() << " Max : " << sensor[1]->getMax() << " >> \n";
}

void RobotControl::moveDistance(float distance) {
//speed is milimeters/seconds, distance is also
    distance /= 300;
    int timePassed = 0;
    if(collisionSafe()) {
        robot->move(300);
        while(collisionSafe() && timePassed < distance)
            this_thread::sleep_for(chrono::seconds(1));
    }
}

void RobotControl::closeWall() {
    forward();
    safeMove(100);
}

bool RobotControl::collisionSafe() {
    for(int i = 0;i<16;i++) {
        if(sensor[0]->getRange(i) < 550)
            return false;
    }
    return true;
}

void RobotControl::connect() {
    robot->open();
}

void RobotControl::disconnect() {
    robot->close();
}

void RobotControl::stopRobot() {
    robot->stop();
}
