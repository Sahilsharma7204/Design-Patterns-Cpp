/*
https://www.geeksforgeeks.org/strategy-pattern-set-2/
*/

#include<iostream>
using namespace std;


class JumpStrategy {
public:
	virtual void jump() = 0;
};

class JumpLong : public JumpStrategy {
public:
	void jump() {
		cout << "long jump \n";
	}
};

class JumpShort : public JumpStrategy {
public:
	void jump() {
		cout << "Jump short \n";
	}
};


class Robot {
private:
	JumpStrategy* jump_strategy;
public:
	Robot(JumpStrategy* jump_strategy) {
		this->jump_strategy = jump_strategy;
	}
	void jump() {
		jump_strategy->jump();
	}
	virtual void walk() = 0;
	void run() {
		cout << " Robot running \n";
	}

	void assign_strategy(JumpStrategy* js) {
		this->jump_strategy = js;
	}
};

class Alpha : public Robot {
public:
	Alpha(JumpStrategy* js): Robot(js){}
	void walk() override {
		cout << "aplha walking \n";
	}
};

class Beta : public Robot {
public:
	Beta(JumpStrategy* js) : Robot(js) {
	}
	void walk() override {
		cout << "beta walking \n";
	}
};

/*
int main() {
	JumpStrategy* jump_long = new JumpLong();
	JumpStrategy* jump_short = new JumpShort();
	Alpha* r_alpha = new Alpha(jump_long);
	r_alpha->walk();
	r_alpha->run();
	r_alpha->jump();
	r_alpha->assign_strategy(jump_short);
	r_alpha->jump();
}

*/