#include <iostream>
#include <string>

using namespace std;

class MotionAxis {
private:
	string name;
	bool connected;
	bool servoOn;
	bool homed;
	bool moving;
	bool alarm;
	int currentPosition;

public:
	MotionAxis(const string& AxisName) :name(AxisName), connected(false), servoOn(false), homed(false), moving(false), alarm(false), currentPosition(0) {}

	void Connect() {
		if (connected) {
			cout << "이미 연결되어 있습니다.\n";
			return;
		}

		connected = true;
		cout << "성공적으로 연결했습니다.\n";
	}
	void Disconnect() {
		if (!connected) {
			cout << "이미 연결되어 있지 않습니다.\n";
			return;
		}

		connected = false;
		servoOn = false;
		homed = false;
		cout << "성공적으로 연결 해제 되었습니다.\n";
	}

	void ServoOn() {
		if (servoOn) {
			cout << "이미 Servo On 상태입니다.\n";
			return;
		}

		if (!connected) {
			cout << "연결되어 있지 않습니다.\n";
			return;
		}
		if (alarm) {
			cout << "알람 상태에서는 처리할 수 없습니다.\n";
			return;
		}

		servoOn = true;
		cout << "성공적으로 Servo On 처리 되었습니다.\n";
	}
	void ServoOff() {
		if (!servoOn) {
			cout << "이미 Servo Off 상태입니다.\n";
			return;
		}

		if (moving) {
			cout << "이동 중에는 Servo Off 처리할 수 없습니다.\n";
			return;
		}

		servoOn = false;
		cout << "성공적으로 Servo Off 처리 되었습니다.\n";
	}

	void Home() {
		if (!connected || !servoOn) {
			cout << "연결 및 Servo On 상태에서만 가능합니다.\n";
			return;
		}

		if (alarm) {
			cout << "알람 상태에서는 처리할 수 없습니다.\n";
			return;
		}

		moving = true;
		cout << "Home 동작을 시작합니다.\n";

		currentPosition = 0;
		homed = true;
		moving = false;

		cout << "성공적으로 Home 처리되었습니다.\n";
	}

	void MoveAbsolute(int targetPosition) {
		if (!connected || !servoOn) {
			cout << "연결 및 Servo On 상태에서만 가능합니다.\n";
			return;
		}

		if (!homed) {
			cout << "Home 처리 후 이용 가능합니다.\n";
			return;
		}

		if (alarm) {
			cout << "알람 상태에서는 처리할 수 없습니다.\n";
			return;
		}

		if (moving) {
			cout << "이미 이동 중이므로 새로운 이동 명령을 실행할 수 없습니다.\n";
			return;
		}

		if (targetPosition < 0 || targetPosition>1000) {
			cout << "0 ~ 1000 의 범위만 허용됩니다.\n";
			return;
		}

		moving = true;

		int previousPosition = currentPosition;
		currentPosition = targetPosition;

		cout << previousPosition << " 위치에서 " << currentPosition << " 위치로 이동하였습니다.\n";

		moving = false;
	}
	void MoveRelative(int distance) {
		if (!connected || !servoOn) {
			cout << "연결 및 Servo On 상태에서만 가능합니다.\n";
			return;
		}

		if (!homed) {
			cout << "Home 처리 후 이용 가능합니다.\n";
			return;
		}

		if (alarm) {
			cout << "알람 상태에서는 처리할 수 없습니다.\n";
			return;
		}

		if (moving) {
			cout << "이미 이동 중이므로 새로운 이동 명령을 실행할 수 없습니다.\n";
			return;
		}

		if ((currentPosition + distance) < 0 || (currentPosition + distance) > 1000) {
			cout << "거리의 합이 0 ~ 1000 범위 내만 허용됩니다.\n";
			cout << "현재 거리 합 :" << (currentPosition + distance);
			return;
		}

		moving = true;

		int previousPosition = currentPosition;
		currentPosition = currentPosition + distance;

		cout << previousPosition << " 위치에서 " << currentPosition << " 위치로 이동하였습니다.\n";

		moving = false;
	}

	void Stop() {
		if (!moving)
		{
			cout << "현재 이동 중이 아닙니다.\n";
			return;
		}

		moving = false;
		cout << "이동을 중지했습니다.\n";
	}
	void SetAlarm() {
		alarm = true;
		cout << "알람 상태로 변경했습니다.\n";

		if (moving) {
			cout << "알람 상태로 변경되어 이동을 중지합니다.\n";
			moving = false;
		}

		servoOn = false;
		cout << "알람 상태로 변경하고 Servo를 해제했습니다.\n";
	}
	void ResetAlarm() {
		alarm = false;
		cout << "알람 상태를 해제했습니다.\n";
	}

	void PrintStatus() const {
		/*
		string name;
		bool connected;
		bool servoOn;
		bool homed;
		bool moving;
		bool alarm;
		int currentPosition;
		*/

		cout << "장비 이름:" << name << "\n";
		cout << "연결 상태:" << (connected?"CONNECTED":"DISCONNECTED") << "\n";
		cout << "Servo On 상태:" << (servoOn?"ON":"OFF") << "\n";
		cout << "Home 상태:" << (homed?"ON":"OFF") << "\n";
		cout << "Moving 상태:" << (moving?"ON":"OFF") << "\n";
		cout << "Alarm 상태:" << (alarm?"ON":"OFF") << "\n";
		cout << "현재 위치:" << currentPosition << "\n";
	}
};

int main() {

	MotionAxis xAxis("X Axis");

	xAxis.MoveAbsolute(500);

	xAxis.Connect();
	xAxis.ServoOn();
	xAxis.MoveAbsolute(500);

	xAxis.Home();
	xAxis.MoveAbsolute(500);
	xAxis.MoveRelative(-200);

	xAxis.SetAlarm();
	xAxis.MoveAbsolute(700);

	xAxis.ResetAlarm();
	xAxis.ServoOn();
	xAxis.Home();
	xAxis.MoveAbsolute(700);

	xAxis.PrintStatus();

	return 0;
}
