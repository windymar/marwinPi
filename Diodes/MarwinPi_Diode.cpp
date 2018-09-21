#include "MarwinPi_Diode.hpp"
#include <wiringPi.h>

namespace MarwinPi
{

Diode::Diode(std::unique_ptr<IGpioPort>& p_gpioPort) :
    m_gpioPort(p_gpioPort)
{
}

Diode::~Diode()
{
    switchOff();
    m_gpioPort->clear();
}

void Diode::switchOn()
{
    m_gpioPort->write(GpioValue::GpioValue_High);
    m_isSwichedOn = true;
}

void Diode::switchOff()
{
    m_gpioPort->write(GpioValue::GpioValue_Low);
    m_isSwichedOn = false;
}

bool Diode::isSwitchedOn()
{
    return m_isSwichedOn;
}

}
