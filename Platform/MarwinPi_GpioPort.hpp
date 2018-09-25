#ifndef MARWINPI_GPIOPORT_HPP
#define MARWINPI_GPIOPORT_HPP

#include "MarwinPi_IGpioPort.hpp"
#include "MarwinPi_Types.hpp"

namespace MarwinPi
{

class GpioPort : public IGpioPort
{
public:
    GpioPort(GpioWpi p_gpioWpi, GpioMode p_gpioMode);
    ~GpioPort();

    void write(GpioValue p_value) const override;
    void write(unsigned p_signal) const override;
    GpioValue read() const override;

private:
    GpioWpi m_gpioWpi;
    GpioMode m_gpioMode;
};

}

#endif // MARWINPI_GPIOPORT_HPP
