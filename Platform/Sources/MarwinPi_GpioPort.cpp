#include "MarwinPi_GpioPort.hpp"
#include <wiringPi.h>
#include <iostream>
#include "MarwinPi_GpioException.hpp"

namespace MarwinPi
{

GpioPort::GpioPort(GpioWpi p_gpioWpi, GpioMode p_gpioMode) :
    m_gpioWpi(p_gpioWpi),
    m_gpioMode(p_gpioMode)
{
#ifdef UNITTESTS
#else
    pinMode(static_cast<unsigned>(p_gpioWpi), static_cast<unsigned>(p_gpioMode));
#endif
}

GpioPort::~GpioPort()
{
#ifdef UNITTESTS
#else
    pinMode(static_cast<unsigned>(m_gpioWpi), static_cast<unsigned>(GpioMode::GpioMode_Input));
#endif
}

void GpioPort::write(GpioValue p_value) const
{
    if(m_gpioMode != GpioMode::GpioMode_Output)
    {
        throw GpioException("You are trying to write to input port type", m_gpioWpi, m_gpioMode);
    }
#ifdef UNITTESTS
#else
    digitalWrite(static_cast<unsigned>(m_gpioWpi),
                 static_cast<unsigned>(p_value));
#endif
}

void GpioPort::write(unsigned p_signal) const
{
    if(m_gpioMode != GpioMode::GpioMode_Pwm)
    {
        throw GpioException("Port is not PWM type", m_gpioWpi, m_gpioMode);
    }
#ifdef UNITTESTS
#else
    pwmWrite(static_cast<unsigned>(m_gpioWpi), p_signal);
#endif
}

GpioValue GpioPort::read() const
{
    if(m_gpioMode != GpioMode::GpioMode_Input)
    {
        throw GpioException("You are trying to read from output port type", m_gpioWpi, m_gpioMode);
    }
#ifdef UNITTESTS
    return GpioValue::GpioValue_Low;
#else
    return static_cast<GpioValue>(digitalRead(static_cast<unsigned>(m_gpioWpi)));
#endif
}

GpioWpi GpioPort::getWpiPort() const
{
    return m_gpioWpi;
}

GpioMode GpioPort::getMode() const
{
    return m_gpioMode;
}

}
