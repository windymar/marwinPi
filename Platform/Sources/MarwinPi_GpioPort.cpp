#include "MarwinPi_GpioPort.hpp"
#include <wiringPi.h>
#include <iostream>
#include "MarwinPi_GpioException.hpp"

namespace MarwinPi
{

GpioPort::GpioPort(IWiringPiWrapper& p_wpiWrapper, GpioWpi p_gpioWpi, GpioMode p_gpioMode) :
    m_wiringPiWrapper(p_wpiWrapper),
    m_gpioWpi(p_gpioWpi),
    m_gpioMode(p_gpioMode)
{
    m_wiringPiWrapper.pinMode(p_gpioWpi, p_gpioMode);
}

GpioPort::~GpioPort()
{
    m_wiringPiWrapper.pinMode(m_gpioWpi, GpioMode::GpioMode_Input);
}

void GpioPort::write(GpioValue p_value) const
{
    if(m_gpioMode != GpioMode::GpioMode_Output)
    {
        throw GpioException("You are trying to write to input port type", m_gpioWpi, m_gpioMode);
    }
    m_wiringPiWrapper.digitalWrite(m_gpioWpi, p_value);
}

void GpioPort::write(unsigned p_signal) const
{
    if(m_gpioMode != GpioMode::GpioMode_Pwm)
    {
        throw GpioException("Port is not PWM type", m_gpioWpi, m_gpioMode);
    }
    m_wiringPiWrapper.pwmWrite(m_gpioWpi, p_signal);
}

GpioValue GpioPort::read() const
{
    if(m_gpioMode != GpioMode::GpioMode_Input)
    {
        throw GpioException("You are trying to read from output port type", m_gpioWpi, m_gpioMode);
    }
    return m_wiringPiWrapper.digitalRead(m_gpioWpi);
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
