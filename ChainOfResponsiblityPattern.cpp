/*
    https://www.geeksforgeeks.org/chain-responsibility-design-pattern/
*/

#include<iostream>
using namespace std;
class Processor {
protected:
    Processor* processor;
public:
    Processor(Processor* processor) {
        this->processor = processor;
    }
    virtual void process(int num) = 0;
};

class PosProcessor : public Processor {
public:
    PosProcessor(Processor* processor) : Processor(processor) {

    }
    void process(int num) override {
        if (num > 0) {
            cout << "Positive num processed \n";
        }
        else {
            processor->process(num);
        }
    }
};

class NegProcessor : public Processor {
public:
    NegProcessor(Processor* processor) : Processor(processor) {

    }
    void process(int num) override {
        if (num < 0) {
            cout << "Negative num processed \n";
        }
        else {
            processor->process(num);
        }
    }
};

class ZeroProcessor : public Processor {
public:
    ZeroProcessor(Processor* processor) : Processor(processor) {

    }
    void process(int num) override {
        if (num == 0) {
            cout << "Zero num processed \n";
        }
        else {
            processor->process(num);
        }
    }
};

class Chain {
private:
    Processor* processor;
public:
    void build_chain() {
        processor = new PosProcessor(new NegProcessor(new ZeroProcessor(NULL)));
    }
    void process(int num) {
        processor->process(num);
    }
};

/*
int main() {

    Chain* chain = new Chain();
    chain->build_chain();
    chain->process(1);
    chain->process(-1);
    chain->process(0);
}
*/