#include "MarwinPi_GpioPortFactoryPi3.hpp"
#include "MarwinPi_GpioPort.hpp"
#include "MarwinPi_GpioException.hpp"
#include <iostream>

namespace MarwinPi
{

std::unique_ptr<IGpioPort> GpioPortFactoryPi3::createGpioPort(
        GpioWpi p_gpio,
        GpioMode p_mode)
{
    if(isGpioUsed(p_gpio))
    {
        throw GpioException("Wpi gpio port number already used", p_gpio, p_mode);
    }
    markGpioUsed(p_gpio);
    return std::unique_ptr<GpioPort>(new GpioPort(p_gpio, p_mode));
}

bool GpioPortFactoryPi3::isGpioUsed(GpioWpi p_gpio)
{
    return m_gpioUsageMap[p_gpio];
}

void GpioPortFactoryPi3::markGpioUsed(GpioWpi p_gpio)
{
    m_gpioUsageMap[p_gpio] = true;
}

}
