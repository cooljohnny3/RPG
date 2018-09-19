#ifndef SHIELD_H
#define SHIELD_H

#include "./Equipment.h"

class Shield : public Equipment{
public:
	Shield();
	Shield(std::string n, int r, int s);
};
#endif