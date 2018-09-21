#ifndef MARWINPI_IGPIOPORT_HPP
#define MARWINPI_IGPIOPORT_HPP

#include "MarwinPi_Types.hpp"

namespace MarwinPi
{

class IGpioPort
{
public:
    virtual ~IGpioPort() { }

    virtual void write(GpioValue) const = 0;
    virtual GpioValue read() const = 0;
};

}

#endif // MARWINPI_IGPIOPORT_HPP
