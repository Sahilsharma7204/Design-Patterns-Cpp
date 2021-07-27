/*
https://sourcemaking.com/design_patterns/adapter/cpp/1
https://www.geeksforgeeks.org/adapter-pattern/
There are two types of adapter patterns 
class adapter and object adapter . object adapter implemented by gfg and sourcemaking implements class adapter
*/

#include<iostream>
using namespace std;

class Dog {
public:
	virtual void dog_moves() = 0;
};

class Cat {
public:
	virtual void cat_moves() = 0;
};

class DogMale : public Dog {
public:
	void dog_moves () override {
		cout << "Dog moves \n";
	}
};

class CatMale : public Cat {
public:
	void cat_moves () override {
		cout << "Cat moves \n";
	}
};

class CatAdapter : public Dog {
private:
	Cat* cat;
public:
	CatAdapter(Cat* c) : cat(c) {};
	void dog_moves() override{
		cat->cat_moves();
	}
};
/*
int main() {
	DogMale dog;
	dog.dog_moves();
	CatMale cat;
	CatAdapter* cd = new CatAdapter(&cat);
	cd->dog_moves();
}
*/