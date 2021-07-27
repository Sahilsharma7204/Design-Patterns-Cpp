#include<iostream>
using namespace std;
#include<vector>


class Iterator {
public:
	virtual bool has_next() = 0;
	virtual int next_id() = 0;
};
class Collection {
public:
	virtual Iterator* createIterator() = 0;
};

class StudentIterator : public Iterator {
private:
	vector<int> ids;
	int pos;
public:
	StudentIterator(vector<int>& ids) {
		this->ids = ids;
		pos = 0;
	}
	bool has_next() override {
		if (pos < ids.size()) {
			return true;
		}
		return false;
	}
	int next_id() override {
		return ids[pos++];
	}
};


class StudentCollection : public Collection {
	vector<int> ids;
public:
	void add_Collection(int n) {
		ids.push_back(n);
	}
	int get_ids_size() {
		return ids.size();
	}
	int get_id(int index) {
		return ids[index];
	}
	Iterator* createIterator() override {
		Iterator* str = new StudentIterator(ids);
		return str;
	}
};


/*
int main() {
	StudentCollection* stdcollect = new StudentCollection();
	stdcollect->add_Collection(1);
	stdcollect->add_Collection(2);
	stdcollect->add_Collection(3);


	Iterator* student_iter = stdcollect->createIterator();
	while (student_iter->has_next()) {
		cout << student_iter->next_id();
	}
}

*/