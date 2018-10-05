#ifndef MARWINPI_WIRINGPIWRAPPER_HPP
#define MARWINPI_WIRINGPIWRAPPER_HPP

#include "MarwinPi_IWiringPiWrapper.hpp"

namespace MarwinPi
{

class WiringPiWrapper : public IWiringPiWrapper
{
public:
    void pinMode(GpioWpi p_wpi, GpioMode p_mode) const override;
    void digitalWrite(GpioWpi p_wpi, GpioValue p_value) const override;
    void pwmWrite(GpioWpi p_wpi, unsigned p_signal) const override;
    GpioValue digitalRead(GpioWpi p_wpi) const override;
};

}

#endif // MARWINPI_WIRINGPIWRAPPER_HPP
