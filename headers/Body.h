#ifndef BODY_H
#define BODY_H

#include "./Equipment.h"

class Body : public Equipment {
public:
	Body();
	Body(std::string n, int r, int s);
};
#endif