#ifndef RESISTOR_COMPONENT_H
#define RESISTOR_COMPONENT_H

#include "Component.h"

#include <string>

class Resistor : public Component
{
public:
	Resistor(const std::string & name, const float & ohm, Connection & p, Connection & n);

	void move(const float & timeunits);
	float getCurrent();

private:
	float _ohm;
};

#endif
