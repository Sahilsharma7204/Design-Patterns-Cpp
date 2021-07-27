#include<iostream>
using namespace std;

/*
* https://www.geeksforgeeks.org/command-pattern/
*/
class Command {
public:
	virtual void execute() = 0;
};

class Light {
public:
	void on() {
		cout << "light is on \n";
	}
};

class WashingMachine {
public:
	void on_blower() {
		cout << "washing machine blower is on \n";
	}
	void on_washer() {
		cout << "washing machine washer is on \n";
	}
};

class LightOnCommand : public Command {
private :
	Light* light;
public:
	LightOnCommand(Light* light) {
		this->light = light;
	}
	void execute() override {
		light->on();
	}
	
};

class WashingMachineOnCommand : public Command {
private:
	WashingMachine* wm;
public:
	WashingMachineOnCommand(WashingMachine* wm) {
		this->wm = wm;
	}
	void execute() override {
		wm->on_blower();
		wm->on_washer();
	}
};

class Remote {
private:
	Command* cmd;
public:
	void set_cmd(Command* cmd) {
		this->cmd = cmd;
	}
	void button_execute() {
		cmd->execute();
	}
};
/*
int main() {
	Light* light = new Light();
	WashingMachine* wm = new WashingMachine();
	Command* lt = new LightOnCommand(light);
	Command* wm_cmd = new WashingMachineOnCommand(wm);
	Remote* rmt = new Remote();
	rmt->set_cmd(wm_cmd);
	rmt->button_execute();
	rmt->set_cmd(lt);
	rmt->button_execute();
}
*/