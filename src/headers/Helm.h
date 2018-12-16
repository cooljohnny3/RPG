#ifndef HELM_H
#define HELM_H

#include "Equipment.h"

class Helm : public Equipment {
public:
	Helm();
	Helm(std::string n, int r, int s);
};
#endif