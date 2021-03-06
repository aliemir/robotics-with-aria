#include "PioneerRobotInterface.h"
#include "RobotControl.h"
#include <iostream>
using namespace std;

RobotInterface * Robot = new PioneerRobotInterface();
RobotControl Controller(Robot);

void Connection();
void Motion();
void Sensor();

int main() {
    int MainChoice = 0;
    do{
        cout << "Main Menu\n";
        cout << "1. Connection\n";
        cout << "2. Motion\n";
        cout << "3. Sensor\n";
        cout << "4. Quit\n";
        do {
            cout << "Choose one : ";
            cin >> MainChoice;
        } while (!(MainChoice < 5 && MainChoice > 0));
        switch(MainChoice) {
            case 1:
                Connection();
                break;
            case 2:
                Motion();
                break;
            case 3:
                Sensor();
            case 4:
                cout << "Terminating app...\n";
        }
    }while(MainChoice != 4);

    return 0;
}

void Connection() {
    int SubChoice = 0;
    do{
        cout << "Connection Menu\n";
        cout << "1. Connect Robot\n";
        cout << "2. Disconnect Robot\n";
        cout << "3. Back\n";
        do {
            cout << "Choose one : ";
            cin >> SubChoice;
        } while (!(SubChoice < 4 && SubChoice > 0));
        switch(SubChoice) {
            case 1:
                cout << "<Connect>\n";
                Controller.connect();
                break;
            case 2:
                cout << "<Disconnect>\n";
                Controller.close();
                break;
            case 3:
                cout << "Back to main menu...\n";
        }
    }while(SubChoice != 3);
}

void Motion() {
    int SubChoice = 0;
    do{
        cout << "Motion Menu\n";
        cout << "1. Safe Move Robot\n";
        cout << "2. Turn Left\n";
        cout << "3. Turn Right\n";
        cout << "4. Forward\n";
		cout << "5. Stop\n";
        cout << "6. Move Distance\n";
        cout << "7. Close Wall\n";
        cout << "8. Back\n";
        do {
            cout << "Choose one : ";
            cin >> SubChoice;
        } while (!(SubChoice < 9 && SubChoice > 0));
        switch(SubChoice) {
            case 1:
                cout << "<Safe Move>\n";
                cout << "Robot will try to avoid collision, even though manual checking is recommended.\n";
                int speed;
                cout << "Enter speed : ";
                cin >> speed;
                Controller.safeMove(speed);
                break;
            case 2:
                cout << "<Turn Left>\n";
                Controller.turnLeft();
                break;
            case 3:
                cout << "<Turn Right>\n";
                Controller.turnRight();
                break;
            case 4:
                cout << "<Forward>\n";
                Controller.forward();
                break;
            case 6:
                cout << "<Move Distance>\n";
                float dist;
                cout << "Enter distance : ";
                cin >> dist;
                Controller.moveDistance(dist);
				break;
            case 7:
                cout << "<Close Wall>\n";
                Controller.closeWall();
				break;
            case 8:
                cout << "Back to main menu...\n";
				break;
			case 5:
				cout << "<Stop>\n";
				Controller.stop();
				break;
        }
    }while(SubChoice != 8);
}

void Sensor() {
    cout << "Sensor Display\n";
    Controller.print();
}