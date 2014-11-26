#ifndef CAPACITOR_COMPONENT_H
#define CAPACITOR_COMPONENT_H

#include "Component.h"

#include <string>

class Capacitor : public Component
{
public:
	Capacitor(const std::string & name, const float & fahrad, Connection & p, Connection & n);

	void move(const float & timeunits);
	float getCurrent();

private:
	float _fahrad;
	float _charge;
};

#endif
