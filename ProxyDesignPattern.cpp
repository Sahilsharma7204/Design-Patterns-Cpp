/*
* 
* https://www.geeksforgeeks.org/proxy-design-pattern/
* 
*/

#include<iostream>
using namespace std;
#include<unordered_set>
#include<string>

class Internet {
public:
	virtual void connect_to(string site) = 0;
};

class RealInternet  : public Internet{
public:
	void connect_to(string site) {
		cout << "connecting to site"<<site <<endl;
	}
};

class ProxyInternet : public Internet {
private:
	RealInternet* rl = new RealInternet;
	unordered_set<string> st{ "gfg", "leetcode" };
public:
		void connect_to(string site) {
			if (st.find(site) != st.end()) {
				rl->connect_to(site);
			}
			else {
				cout << "site is banned \n";
			}
	}
};
/*
int main() {
    Internet* pl = new ProxyInternet();
	pl->connect_to("gfg");
	pl->connect_to("abc");
}
*/