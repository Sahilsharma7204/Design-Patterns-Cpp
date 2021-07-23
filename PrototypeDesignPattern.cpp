/*
Read from https://www.geeksforgeeks.org/prototype-design-pattern/
Take the example from https://en.wikibooks.org/wiki/C%2B%2B_Programming/Code/Design_Patterns#Prototype 
pls check record factory example from above as implemented in this file too



What’s the point of using the Prototype Design Pattern?
– To create an object rapidly based on cloning a pre-configured object.
– Useful to remove a bunch of boilerplate code.
– Handly while working with object without knowing its type.
– Prototype Design Pattern is an obvious choice while you are working with the Command Design Pattern.
For example, in HTTP request most of the time header & footer content remains the same, what changes are data. 
In such a scenario, you should not create an object from scratch. Rather leverage Prototype Design Pattern.
Prototype design pattern to be used when creation is costly, but we do create in the clone.
You must be wondering that in Prototype Factory we show above, we are creating instances in the copy constructor. Isn’t that expensive. Yes, it is. But just think about HTTP request, its header consist version, encoding type, content type, server-type, etc. Initially, you need a find out these parameters using respective function calls. But once you got these, these are not going to change until connection closed.
So there is no point in doing function calls to extract these params over & over.
What cost us here is not parameters but their functions to extract value.
*/

#include<iostream>
using namespace std;
#include<unordered_map>

class Record {
public:
	virtual unique_ptr<Record> clone() = 0;
	virtual void show() = 0;
};

class CarRecord : public Record {
private:
	string carname;
public:
	CarRecord(string name) : carname(name) {

	}
	unique_ptr<Record> clone() {
		return make_unique<CarRecord>(*this);
	}
	void show() {
		cout << carname <<endl;
	}
};

class BusRecord : public Record {
private:
	string busname;
public:
	BusRecord(string name) : busname(name) {

	}
	unique_ptr<Record> clone() {
		return make_unique<BusRecord>(*this);
	}
	void show() {
		cout << busname << endl;
	}
};
class RecordFactory {
private:
	unordered_map<string, unique_ptr<Record>> registery;
public:
	RecordFactory() {
		registery["BUS"] = make_unique<BusRecord>("Mercedes");
		registery["CAR"] = make_unique<CarRecord>("Ford");
	}

	unique_ptr<Record> createRecord(string type) {
	    return registery[type]->clone();
	}

};
/*
int main() {
	RecordFactory rf;
	unique_ptr<Record> car_record = rf.createRecord("BUS");
		car_record->show();
	unique_ptr<Record> bus_record = rf.createRecord("CAR");
	    bus_record->show();
	
}
*/