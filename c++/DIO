#include <iostream>
#include <string>

using namespace std;

class DioController {
private:
    bool doorClosed;
    bool emergencyStop;
    bool productDetected;

    bool greenLamp;
    bool redLamp;
    bool buzzer;
    bool cylinderForward;

public:
    DioController():doorClosed(false),emergencyStop(false),productDetected(false),greenLamp(false),redLamp(false),buzzer(false),cylinderForward(false){}

    void SetDoorClosed(bool value) {
        doorClosed = value;
        cout << "DoorClose 상태가 " << (value ? "TRUE" : "FALSE") << " 상태로 전환되었습니다.\n";
    }
    void SetEmergencyStop(bool value) {
        emergencyStop = value;

        if (emergencyStop) {
            cout << "비상 정지가 발생되었습니다.\n";
            greenLamp = false;
            redLamp = true;
            buzzer = true;
            cylinderForward = false;
        }
        else{
            cout << "비상 정지가 해제되었습니다.\n";
            buzzer = false;
        }
    }
    void SetProductDetected(bool value) {
        productDetected = value;
        cout << "ProductDetected 상태가 " << (value ? "TRUE" : "FALSE") << " 상태로 전환되었습니다.\n";
    }

    void StartEquipment() {
        bool trigger = false;
        if (!doorClosed) {
            cout << "문이 닫혀있어야 합니다.\n";
            trigger = true;
        }
        if (emergencyStop) {
            cout << "비상 정지 상태가 아니여야 합니다.\n";
            trigger = true;
        }
        if (!productDetected) {
            cout << "제품이 감지되지 않았습니다.\n";
            trigger = true;
        }

        if (trigger) {
            cout << "장비 작동에 실패했습니다.\n";
            greenLamp = false;
            redLamp = true;
            buzzer = true;
        }
        else {
            cout << "장비를 작동합니다.\n";
            greenLamp = true;
            redLamp = false;
            buzzer = false;
        }
    }
    void StopEquipment() {
        cout << "장비를 정지합니다.\n";

        greenLamp = false;
        redLamp = true;
        buzzer = false;
        cylinderForward = false;
    }

    void MoveCylinderForward() {
        if (!doorClosed) {
            cout << "문이 닫혀있어야 합니다.\n";
            return;
        }
        if (emergencyStop) {
            cout << "비상 정지 상태가 아니여야 합니다.\n";
            return;
        }
        if (!productDetected) {
            cout << "제품이 감지되지 않았습니다.\n";
            return;
        }

        cylinderForward = true;
        cout << "실린더를 앞으로 이동합니다.\n";
    }
    void MoveCylinderBackward() {
        cylinderForward = false;
        cout << "실린더를 뒤로 이동합니다.\n";
    }

    void PrintStatus() const {

        cout << "DoorClosed: " << (doorClosed ? "TRUE" : "FALSE") << "\n";
        cout << "EmergencyStop: " << (emergencyStop ? "TRUE" : "FALSE") << "\n";
        cout << "ProductDetected: " << (productDetected ? "TRUE" : "FALSE") << "\n";
        cout << "GreenLamp: " << (greenLamp ? "TRUE" : "FALSE") << "\n";
        cout << "RedLamp: " << (redLamp ? "TRUE" : "FALSE") << "\n";
        cout << "Buzzer: " << (buzzer ? "TRUE" : "FALSE") << "\n";
        cout << "CylinderForward: " << (cylinderForward ? "TRUE" : "FALSE") << "\n";
    }
};

int main()
{
    DioController dio;

    dio.StartEquipment();

    dio.SetDoorClosed(true);
    dio.SetProductDetected(true);

    dio.StartEquipment();
    dio.MoveCylinderForward();

    dio.SetEmergencyStop(true);
    dio.MoveCylinderForward();

    dio.PrintStatus();

    return 0;
}
