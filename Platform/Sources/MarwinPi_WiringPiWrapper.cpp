#include "MarwinPi_WiringPiWrapper.hpp"
#include <wiringPi.h>

namespace MarwinPi
{

void WiringPiWrapper::pinMode(GpioWpi p_wpi, GpioMode p_mode) const
{
    ::pinMode(static_cast<unsigned>(p_wpi), static_cast<unsigned>(p_mode));
}

void WiringPiWrapper::digitalWrite(GpioWpi p_wpi, GpioValue p_value) const
{
    ::digitalWrite(static_cast<unsigned>(p_wpi),
                   static_cast<unsigned>(p_value));
}

void WiringPiWrapper::pwmWrite(GpioWpi p_wpi, unsigned p_signal) const
{
    ::pwmWrite(static_cast<unsigned>(p_wpi), p_signal);
}

GpioValue WiringPiWrapper::digitalRead(GpioWpi p_wpi) const
{
    return static_cast<GpioValue>(::digitalRead(static_cast<unsigned>(p_wpi)));
}

}
