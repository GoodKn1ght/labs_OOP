#ifndef LAB4_H 
#define LAB4_H 
#include<iostream> 

class CMultiSet {
	int n;
	int* address;
public:
	CMultiSet(int, int*);
	CMultiSet(int);
	CMultiSet() : n(0), address(nullptr) {}
	CMultiSet(CMultiSet& other);
	CMultiSet(CMultiSet&& other) noexcept;
	~CMultiSet();

	void set(int);
	void setA(int*);
	int* getA();

	int findN(int);
	int power();
	int min();
	int max();
	void add(int);
	void dele();

	CMultiSet operator+(CMultiSet);
	CMultiSet operator-(CMultiSet);
	CMultiSet operator/(CMultiSet);
	friend std::istream& operator>>(std::istream&, CMultiSet&);
	friend std::ostream& operator<<(std::ostream&, const CMultiSet&);

	CMultiSet& operator=(CMultiSet&& other) noexcept;
	CMultiSet& operator=(const CMultiSet& other);

	friend void plus1(int** d, int k);
};

#endif