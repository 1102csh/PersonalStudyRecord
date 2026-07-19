#include <iostream> 
#include <memory>
#include <vector>
#include <string>
using namespace std; 

class Equipment { 
public: virtual void Start() = 0;
  virtual void Stop() = 0;
  virtual void PrintStatus() const = 0;
  virtual const string& GetName() const = 0;
  virtual ~Equipment() = default;
  Equipment(string equipmentName) { name = equipmentName; running = false;} 
protected: 
  string name; bool running; 
}; 

class MotionController : public Equipment { 
  public: 
  MotionController(string equipmentName) :Equipment(equipmentName) {} 
  void Start() override { 
    if (running) { cout << "장비가 이미 작동 중 입니다.\n"; } 
    else { cout << "Motion 장비 시작\n"; running = true; } 
  } 
  void Stop() override { 
    if (!running) { cout << "장비가 이미 정지 중 입니다.\n"; } 
    else { cout << "Motion 장비 정지\n"; running = false; } 
  } 
  void PrintStatus() const override { 
    cout << "장비 이름: " << name << "\n"; cout << "장비 상태: " << (running ? "RUNNING" : "STOPPED") << "\n"; 
  } 
  const string& GetName() const { 
    return name; 
  } 
}; 

class VisionController : public Equipment {
  public: VisionController(string equipmentName) :Equipment(equipmentName) {} 
  void Start() override { 
    if (running) { cout << "장비가 이미 작동 중 입니다.\n"; } 
    else { cout << "Vision 장비 시작\n"; running = true; } 
  } 
  void Stop() override {
    if (!running) { cout << "장비가 이미 정지 중 입니다.\n"; } 
    else { cout << "Vision 장비 정지\n"; running = false; } 
  } 
  void PrintStatus() const override {
    cout << "장비 이름: " << name << "\n"; 
    cout << "장비 상태: " << (running ? "RUNNING" : "STOPPED") << "\n"; 
  } 
  const string& GetName() const { return name; } 
}; 

class IoController : public Equipment { 
  public: IoController(string equipmentName) :Equipment(equipmentName) {} 
  void Start() override { 
    if (running) { cout << "장비가 이미 작동 중 입니다.\n"; } 
    else { cout << "I/O 장비 시작\n"; running = true; } 
  } 
  void Stop() override { 
    if (!running) { cout << "장비가 이미 정지 중 입니다.\n"; } 
    else { cout << "I/O 장비 정지\n"; running = false; } 
  } 
  void PrintStatus() const override {
    cout << "장비 이름: " << name << "\n"; cout << "장비 상태: " << (running ? "RUNNING" : "STOPPED") << "\n"; 
  } 
  const string& GetName() const { return name; } 
}; 
class EquipmentManager { 
  private: 
  vector<unique_ptr<Equipment>> equipmentList; 
  public: 
  void AddEquipment(unique_ptr<Equipment> equipment) { 
    equipmentList.push_back(std::move(equipment)); 
  } 
  void StartAll() { 
    for (int i = 0; i < equipmentList.size(); i++) { equipmentList[i]->Start(); } 
  } 
  void StopAll() { 
    for (int i = 0; i < equipmentList.size(); i++) { equipmentList[i]->Stop(); } 
  } 
  void PrintAllStatus() const { 
    for (int i = 0; i < equipmentList.size(); i++) {
      equipmentList[i]->PrintStatus(); } 
  } 
  int GetEquipmentCount() const {
    return equipmentList.size(); 
  } 
}; 

int main() {
  EquipmentManager manager;
  manager.AddEquipment( make_unique<MotionController>("X Axis") );
  manager.AddEquipment( make_unique<VisionController>("Top Camera") );
  manager.AddEquipment( make_unique<IoController>("Main I/O") );
  cout << "등록 장비 수: " << manager.GetEquipmentCount() << "\n";
  manager.StartAll();
  manager.PrintAllStatus();
  manager.StopAll();
  manager.PrintAllStatus(); 
  return 0; 
}
