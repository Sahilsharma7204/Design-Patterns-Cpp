#include<iostream>
#include<vector>
/*
Observer is a behavioral design pattern that allows some objects to notify other objects about changes in their state.

The Observer pattern provides a way to subscribe and unsubscribe to and from these events for any object that implements a subscriber interface.

Usage examples: The Observer pattern is pretty common in C++ code, especially in the GUI components. It provides a way to react to events
happening in other objects without coupling to their classes.

Identification: The pattern can be recognized by subscription methods, that store objects in a list and
by calls to the update method issued to objects in that list.

*/
// observer class
class IObserver {
public:
	virtual ~IObserver() {};
	virtual void update(int temp) = 0;
};


// observable class
class IObservable {
public:
	virtual ~IObservable() {};
	virtual void notify() = 0;
	virtual void add(IObserver* observer) = 0;
	virtual void remove(IObserver* observer) = 0;
};

class WeatherStation : public IObservable {
private:
	std::vector<IObserver*> observers;
	int temperature;
public:
	void create_temperature(int temp) {
		temperature = temp;
		notify();
	}
	void notify() override {
		for (auto it = observers.begin(); it != observers.end(); it++) {
			(*it)->update(temperature);
		}
	}
	void add(IObserver* observer) override {
		observers.push_back(observer);
	}
	void remove(IObserver* observer) override {
		auto it = find(observers.begin(), observers.end(), observer);
		observers.erase(it);
	}
};

class PhoneDisplay : public IObserver {
private:
	WeatherStation* weather_station;
	void print_temp_on_phone(int temp) {
		std::cout << "temperature printed on phone is " << temp << std::endl;
	}
public:
	PhoneDisplay(WeatherStation* weather_station) {
		this->weather_station = weather_station;
		weather_station->add(this);
	}
	void update(int temp) {
		print_temp_on_phone(temp);
	}
	void remove_me() {
		weather_station->remove(this);
	}
};

class LaptopDisplay : public IObserver {
private:
	WeatherStation* weather_station;
	void print_temp_on_laptop(int temp) {
		std::cout << "temperature printed on laptop is " << temp << std::endl;
	}
public:
	LaptopDisplay(WeatherStation* weather_station) {
		this->weather_station = weather_station;
		weather_station->add(this);
	}
	void update(int temp) {
		print_temp_on_laptop(temp);
	}
	void remove_me() {
		weather_station->remove(this);
	}
};

/*
int main() {
	WeatherStation* weather_station = new WeatherStation();
	PhoneDisplay* phone_display = new PhoneDisplay(weather_station);
	LaptopDisplay* laptop_display = new LaptopDisplay(weather_station);
	weather_station->create_temperature(24);
	laptop_display->remove_me();
	weather_station->create_temperature(24);
}

*/