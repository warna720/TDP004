#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>
#include "Connection.h"

class Component
{

public:
	Component(const std::string & name, Connection & p, Connection & n );
	virtual ~Component();

	virtual void move(const float & timeunits) =0;

	virtual float getCurrent() =0;
	virtual double getVoltage();

	std::string getName() {return _name;};

private:
	std::string _name;

	Component(const Component&);
    void operator=(const Component&);

protected:
	//Both sides
	Connection * _a;
	Connection * _b;

};

#endif
