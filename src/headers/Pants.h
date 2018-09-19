#ifndef PANTS_H
#define PANTS_H

#include "./Equipment.h"

class Pants : public Equipment {
public:
	Pants();
	Pants(std::string n, int r, int s);
};
#endif