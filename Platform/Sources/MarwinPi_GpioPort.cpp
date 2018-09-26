#include "MarwinPi_GpioPort.hpp"
#include <wiringPi.h>
#include <iostream>
#include <stdexcept>

namespace MarwinPi
{

GpioPort::GpioPort(GpioWpi p_gpioWpi, GpioMode p_gpioMode) :
    m_gpioWpi(p_gpioWpi),
    m_gpioMode(p_gpioMode)
{
    pinMode(static_cast<unsigned>(p_gpioWpi), static_cast<unsigned>(p_gpioMode));
}

GpioPort::~GpioPort()
{
    std::cout << "dddd" << std::endl;
    pinMode(static_cast<unsigned>(m_gpioWpi), static_cast<unsigned>(GpioMode::GpioMode_Input));
}

void GpioPort::write(GpioValue p_value) const
{
    if(m_gpioMode == GpioMode::GpioMode_Input)
    {
        std::cout << "ERROR: You are trying to write to input port type." << std::endl;
        throw std::exception();
    }
    digitalWrite(static_cast<unsigned>(m_gpioWpi),
                 static_cast<unsigned>(p_value));
}

void GpioPort::write(unsigned p_signal) const
{
    if(m_gpioMode != GpioMode::GpioMode_Pwm)
    {
        std::cout << "ERROR: Port is not PWM." << std::endl;
        throw std::exception();
    }
    pwmWrite(static_cast<unsigned>(m_gpioWpi), p_signal);
}

GpioValue GpioPort::read() const
{
    if(m_gpioMode == GpioMode::GpioMode_Output)
    {
        std::cout << "ERROR: You are trying to read from output port type." << std::endl;
        throw std::exception();
    }
    return static_cast<GpioValue>(digitalRead(static_cast<unsigned>(m_gpioWpi)));
}

}
