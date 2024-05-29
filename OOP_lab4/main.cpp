#include "lab4.h"
int main() {
	CMultiSet* c = new CMultiSet(); CMultiSet* d = new CMultiSet();
	CMultiSet* g = new CMultiSet();
	c->add(6);
	c->add(3); c->add(2);
	std::cout << *c;
	d->add(6); d->add(2);
	d->add(5); std::cout << *d;
	std::cout << "c + d = " << (*c) + (*d);
	std::cout << "c - d = " << (*c) - (*d); std::cout << "c / d = " << (*c) / (*d);
	*g = *c;
	std::cout << *c; std::cout << *g;
	std::cout << *c;
	*g = std::move(*c);
	std::cout << *g; std::cout << *c;
	delete c, d, g;
	return 0;
}