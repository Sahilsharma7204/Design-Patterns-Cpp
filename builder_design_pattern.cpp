#include<iostream>
using namespace std;
#include<string>
/*
Want to create object composing other objects
want to create those objects step by step . They are complex and dependent on each other so ordering matters
We dont want to have complex constructor member

source : medium.com (c++ builder design pattern)
*/

class Pizza {
private:
	string topping;
	string base;
	int spice;
public:
	void show_pizza() {
		cout << "topping : " << topping << " base :" << base << " spice : " << spice << endl;
	}
	void set_topping(string topping) {
		this->topping = topping;
	}
	void set_base(string base) {
		this->base = base;
	}
	void set_spice(int spice) {
		this->spice = spice;
	}
};

class PizzaBuilder {
public:
	~PizzaBuilder() = default;
	virtual void build_topping() = 0;
	virtual void build_base() = 0;
	virtual void build_spice() = 0;
	void create_pizza() {
		pizza = new Pizza();
	}
	Pizza* get_pizza() {
		return pizza;
	}
protected:
	Pizza* pizza;
};

class MasalaPizzaBuilder : public PizzaBuilder {
public:
	void build_topping() override {
		pizza->set_topping("masala topping");
	}
	void build_base() override {
		pizza->set_base("masala base");
	}
	void build_spice() override {
		pizza->set_spice(10);
	}
};

class NormalPizzaBuilder : public PizzaBuilder {
public:
	void build_topping() override {
		pizza->set_topping("normal topping");
	}
	void build_base() override {
		pizza->set_base("normal base");
	}
	void build_spice() override {
		pizza->set_spice(0);
	}
};

// can also be called as director

class Cook {
public:
	void create_pizza(PizzaBuilder* pb) {
		pb->create_pizza();
		pb->build_base();
		pb->build_topping();
		pb->build_spice();
	}
	void show_pizza(PizzaBuilder* pb) {
		pb->get_pizza()->show_pizza();
	}
	
};
/*
int main() {
	Cook ck;
	MasalaPizzaBuilder mb;
	ck.create_pizza(&mb);
	ck.show_pizza(&mb);

	NormalPizzaBuilder nb;
	ck.create_pizza(&nb);
	ck.show_pizza(&nb);


}
*/