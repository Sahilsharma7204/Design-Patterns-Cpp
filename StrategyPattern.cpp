// Strategy is  a behavioral design pattern
// The original object, called context, holds a reference to a strategy object and delegates it executing the behavior.
// In order to change the way the context performs its work, other objects may replace the currently linked strategy object with another one.

/*
Usage examples: The Strategy pattern is very common in C++ code. It’s often used in various frameworks to provide users a way to change the behavior of a class without extending it.
Identification: Strategy pattern can be recognized by a method that lets nested object do the actual work, as well as the setter that allows replacing that object with a different one.
*/


// Abstract DisplayStrategy Class
#include<iostream>
// Coding Note : With Virtual function virtual distructor should be used always
class DisplayStrategy {
public:
    virtual ~DisplayStrategy() {
        std::cout << "distroying display \n";
    }
    virtual void display() const = 0;
};

class PhoneDisplayStrategy : public DisplayStrategy{
    void display()const {
        std::cout << "Phone Display Started \n";
    }
    ~PhoneDisplayStrategy() {
        std::cout << "Distroying phone display \n";
    }
};

class LaptopDisplayStrategy : public DisplayStrategy {
    void display()const {
        std::cout << "Laptop Display Started \n";
    }
    ~LaptopDisplayStrategy() {
        std::cout << "Distroying laptop display \n";
    }
};

class  Display {
private:
    DisplayStrategy* display_strategy;
 public:
     Display(DisplayStrategy* display_strategy) {
         this->display_strategy = display_strategy;
    }
     ~Display() {
         delete display_strategy;
    }
     void display() {
         display_strategy->display();
    }
     void set_display_strategy(DisplayStrategy* display_strategy) {
         delete this->display_strategy;
         this->display_strategy = display_strategy;
     }
};
/*
int main()
{
    // Use Phone Strategy 
    Display* dp_phone= new Display(new PhoneDisplayStrategy);
    dp_phone->display();
    // Use Laptop Strategy
    Display* dp_laptop = new Display(new LaptopDisplayStrategy);
    // Change the dp_laptop to point to phone display
    dp_laptop->set_display_strategy(new PhoneDisplayStrategy);
    dp_laptop->display();
    delete dp_laptop;
    delete dp_phone;
}

*/