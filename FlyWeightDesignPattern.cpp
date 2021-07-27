/*
Flyweight Design Pattern
https://www.geeksforgeeks.org/flyweight-design-pattern/
*/

#include<iostream>
using namespace std;
#include<string>
#include<unordered_map>

class Player {
protected:
	string weapon;
public:
	virtual void mission() = 0;
	virtual void add_gun(string weapon ) {
		this->weapon = weapon;
	}
};

class Terrorist : public Player {
public:
	void mission() override {
		cout << "mission is to plant the bomb\n";
	}
};

class CounterTerrorist : public Player{
public:
	void mission() override {
		cout << "mission is to diffuse the bomb \n";
	}
};

class PlayerFactory {
private:
	unordered_map<string, Player*> registry;
public:
	Player* get_player(string player_type) {

		if (registry.find(player_type) != registry.end()) {
			return registry[player_type];
		}
		if (player_type == "Terrorist") {
			registry[player_type] = new Terrorist();
			return registry[player_type];
		}
		else {
			registry[player_type] = new CounterTerrorist();
			return registry[player_type];
		}
	}
};

/*
int main() {
	string players[] = { "Terrorist", "CounterTerrorist" };
	string weapons[] = { "shotgun", "Assault Rifle" };
	PlayerFactory pf;
	for (int i = 0; i < 10; i++) {
		Player* terrorist = pf.get_player("Terrorist");
		terrorist->add_gun("shotgun");
		terrorist->mission();
		Player* counter_terrorist = pf.get_player("CounterTerrorist");
		counter_terrorist->add_gun("rifle");
		counter_terrorist->mission();
	}
}

*/