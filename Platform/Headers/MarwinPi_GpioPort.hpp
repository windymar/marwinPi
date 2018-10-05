#ifndef MARWINPI_GPIOPORT_HPP
#define MARWINPI_GPIOPORT_HPP

#include "MarwinPi_IGpioPort.hpp"
#include "MarwinPi_Types.hpp"
#include "MarwinPi_IWiringPiWrapper.hpp"

namespace MarwinPi
{

class GpioPort : public IGpioPort
{
public:
    GpioPort(IWiringPiWrapper& p_wpiWrapper, GpioWpi p_gpioWpi, GpioMode p_gpioMode);
    ~GpioPort();

    void write(GpioValue p_value) const override;
    void write(unsigned p_signal) const override;
    GpioValue read() const override;

    GpioWpi getWpiPort() const override;
    GpioMode getMode() const override;

private:
    GpioWpi m_gpioWpi;
    GpioMode m_gpioMode;
    IWiringPiWrapper& m_wiringPiWrapper;
};

}

#endif // MARWINPI_GPIOPORT_HPP
