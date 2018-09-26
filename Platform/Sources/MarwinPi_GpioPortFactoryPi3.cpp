#include "MarwinPi_GpioPortFactoryPi3.hpp"
#include "MarwinPi_GpioPort.hpp"
#include <iostream>

namespace MarwinPi
{

std::unique_ptr<IGpioPort> GpioPortFactoryPi3::createGpioPort(
        GpioWpi p_gpio,
        GpioMode p_mode)
{
    if(isGpioUsed(p_gpio))
    {
        std::cout << "ERROR: wpi gpio port number already used: " << static_cast<unsigned>(p_gpio) << std::endl;
        throw std::exception();
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