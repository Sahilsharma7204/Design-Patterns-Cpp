#include<iostream>
using namespace std;

/*
1. Make the default constructor private 
2. delete the copy constructor
3. always use the get_instance() and store return value in reference variable
4. delete the assignment operator also
*/

class RandomNumber {
	int num;
	RandomNumber() {
		cout << "constructor called \n";
	}
public:
	static RandomNumber&  get_instance() {
		static RandomNumber obj;
		return obj;
	}
	int  get_random_number() {
		return  num;
	}
	RandomNumber(const RandomNumber&) = delete;
	RandomNumber& operator=(RandomNumber&) = delete;
};

void client_code() {
	RandomNumber& rd = RandomNumber::get_instance();
	std::cout << rd.get_random_number() << std::endl;
	RandomNumber& rd1 = RandomNumber::get_instance();
	std::cout<<rd1.get_random_number()<< std::endl;
}
/*
int main() {
	client_code();
}
*/