#ifndef MARWINPI_IWIRINGPIWRAPPER_HPP
#define MARWINPI_IWIRINGPIWRAPPER_HPP

#include "MarwinPi_Types.hpp"

namespace MarwinPi
{

class IWiringPiWrapper
{
public:
    virtual ~IWiringPiWrapper() { }

    virtual void pinMode(GpioWpi, GpioMode) const = 0;
    virtual void digitalWrite(GpioWpi, GpioValue) const = 0;
    virtual void pwmWrite(GpioWpi, unsigned) const = 0;
    virtual GpioValue digitalRead(GpioWpi) const = 0;
};

}

#endif // MARWINPI_IWIRINGPIWRAPPER_HPP
