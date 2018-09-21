#include "MarwinPi_Buzzer.hpp"
#include <wiringPi.h>

namespace MarwinPi
{

Buzzer::Buzzer(std::unique_ptr<IGpioPort>& p_gpioPort) :
    m_gpioPort(p_gpioPort)
{
    stopPlaying();
}

Buzzer::~Buzzer()
{
    stopPlaying();
}

void Buzzer::play()
{   
    m_gpioPort->write(GpioValue::GpioValue_Low);
    m_isPlaying = true;
}

bool Buzzer::isPlaying() const
{
    return m_isPlaying;
}

void Buzzer::stopPlaying()
{
    m_gpioPort->write(GpioValue::GpioValue_High);
    m_isPlaying = false;
}


}
