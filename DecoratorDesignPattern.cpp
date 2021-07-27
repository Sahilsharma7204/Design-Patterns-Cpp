#include<iostream>
using namespace std;
#include<string>

class Pizza {
public:
	virtual int get_cost() = 0;
	virtual string get_desc() = 0;
};

class Margherita : public Pizza {
public:
	int get_cost() {
		return 10;
	}
	string get_desc() {
		return "Pizza : Margherita ";
	}
};


class Farmhouse : public Pizza {
public:
	int get_cost() {
		return 20;	
	}
	string get_desc() {
		return "Pizza : Farmhouse";
	}
};
// This is the decorator
class Topping : public Pizza {
protected:
	Pizza* pizza;
public:
	Topping(Pizza* pizza) {
		this->pizza = pizza;
	}
	virtual int get_cost() = 0;
	virtual string get_desc() = 0;
};

class Masala : public Topping {

public:
	Masala(Pizza* pizza) : Topping(pizza){
	}
	int get_cost() {
		return (pizza->get_cost() + 19);
	}

	string get_desc() {
		return (pizza->get_desc() + "topping used masala, ");
	}
};

class Normal : public Topping {
public:
	Normal(Pizza* pizza) : Topping(pizza){
	}
	int get_cost() {
		return (pizza->get_cost() + 22);
	}
	string get_desc() {
		return (pizza->get_desc() + "topping used normal");
	}
};
/*
int main() {
	Pizza* pizza = new Margherita();
	pizza = new Masala(pizza);
	pizza = new Normal(pizza);
	cout << pizza->get_desc() << endl;
	cout << pizza->get_cost() << endl;
}
*/