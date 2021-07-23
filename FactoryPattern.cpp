#include<iostream>
/**
Factory method is a creational design pattern which solves the problem of creating product objects without specifying their concrete classes.

Factory  defines a method, which should be used for creating objects instead of direct constructor call (new operator).
Subclasses can override this method to change the class of objects that will be created

Usage examples: The Factory class pattern is widely used in C++ code. It’s very useful when you need to provide a
high level of flexibility for your code.

Identification: Factory class can be recognized by creation methods, which create objects from concrete classes, 
but return them as objects of abstract type or interface.

Need : 
Client will end up chaining a new else if in the conditional ladder to create objects of ThreeWheeler. Which in turn will need Client to be recompiled. So, each time a new change is made at the library side, Client would need to make some
corresponding changes at its end and recompile the code. Sounds bad? This is a very bad practice of design.

Disadvantage : violates open close princicple: Function / module can be extended but not intended to be modified in future
TO be read : 
https://www.geeksforgeeks.org/design-patterns-set-2-factory-method/
*/
class Toy {
public:
    virtual void run() = 0;
    virtual void turn_on() = 0;
    virtual ~Toy() {
        std::cout << "Destroying the toy \n";
    }
};

class Car : public Toy {
public:
    ~Car() {
        std::cout << "Destroying the car \n";
    }
    void turn_on() {
        std::cout << " Turn on Car \n";
    }
    void run() override {
        std::cout << " Runs car \n";
    }
};

class Truck : public Toy {
public:
     ~Truck() {
        std::cout << "Destroying truck";
    }
    void run() override {
        std::cout << "Runs Truck \n";
    }
    void turn_on() {
        std::cout << "Turn on Truck \n";
    }
};

class FactoryToy {
public:
    static Toy* make_toy(int type) {
        if (type == 1) {
            return new Car;
        }
        else {
            return new Truck;
        }
    }
};

void client_code(Toy* toy) {
    toy->turn_on();
    toy->run();
}

/*
int main() {
    Toy* toy1 = FactoryToy::make_toy(1);
    client_code(toy1);
    Toy* toy2 = FactoryToy::make_toy(2);
    client_code(toy2);
    delete toy1;
    delete toy2;
}
*/