#include "RobotControl.h"
#include <iostream>
#include <string>
using namespace std;

void RobotControl::safeMove(int speed) { robot->move(speed); }

void RobotControl::stop() { robot->stop(); }

void RobotControl::connect() { robot->open(); }

void RobotControl::disconnect() { robot->close(); }

void RobotControl::turnLeft() { robot->turn(::DIRECTION::left); this_thread::sleep_for(chrono::seconds(1)); }

void RobotControl::turnRight() { robot->turn(::DIRECTION::right); this_thread::sleep_for(chrono::seconds(1)); }

void RobotControl::forward() { robot->turn(::DIRECTION::forward); this_thread::sleep_for(chrono::seconds(1)); }

RobotControl::RobotControl(RobotInterface *robot) : robot(robot) {
    position = new Position;
    sensor.push_back(new SonarSensor);
    sensor.push_back(new LaserSensor);
    robot->setPosition(position);
    robot->setRangeSensor(sensor[0],sensor[1]);
    sensor[0]->setType("Sonar");
    sensor[1]->setType("Laser");
}

void RobotControl::print() {
    cout << "Robot's Position " << "[ " << position->getX() << ", " << position->getY() << "] Angle [ " << position->getTh() << " ]\n";
    cout << sensor[0]->getType() << " Sensors \n << ";
    for(int i = 0;i<16;i++) {
        cout << sensor[0]->getRange(i) << " - ";
        if(i == 7)
            cout << " >> \n << ";
    }
    cout << " >> \n";
    cout << sensor[1]->getType() << " Sensors \n << ";
    cout << " Min : " << sensor[1]->getMin() << " Max : " << sensor[1]->getMax() << " >> \n";
}

void RobotControl::moveDistance(float distance) {
    distance /= 300;
	robot->move(300);
    for(int timePassed = 0;collisionSafe() && timePassed < distance;timePassed++)
        this_thread::sleep_for(chrono::seconds(1));
	robot->stop();
}

void RobotControl::closeWall() {
    safeMove(250);
	while (collisionSafe())
		this_thread::sleep_for(chrono::seconds(1));
	stop();
}

bool RobotControl::collisionSafe() {
    for(int i = 0;i<16;i++)
        if(sensor[0]->getRange(i) <= 200)
            return false;
    return true;
}