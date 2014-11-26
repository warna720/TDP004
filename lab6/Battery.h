#ifndef BATTERY_COMPONENT_H
#define BATTERY_COMPONENT_H

#include "Component.h"

#include <string>

class Battery : public Component
{
public:
	Battery(const std::string & name, const float & charge, Connection & p, Connection & n);

	void move(const float &);

	double getVoltage() {return _charge;};
	float getCurrent() {return 0;};

private:
	float _charge;
};

#endif
