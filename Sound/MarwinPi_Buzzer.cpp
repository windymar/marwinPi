#include "MarwinPi_Buzzer.hpp"
#include <wiringPi.h>

namespace MarwinPi
{

Buzzer::Buzzer(GPIO_WPI p_gpio) : m_gpio(p_gpio)
{
}

Buzzer::~Buzzer()
{
    digitalWrite(static_cast<unsigned>(m_gpio), LOW);
    stop();
}

void Buzzer::play()
{
    pinMode(static_cast<unsigned>(m_gpio), OUTPUT);
    digitalWrite(static_cast<unsigned>(m_gpio), LOW);
    m_isPlaying = true;
}

bool Buzzer::isPlaying() const
{
    return m_isPlaying;
}

void Buzzer::stop()
{
    digitalWrite(static_cast<unsigned>(m_gpio), HIGH);
    pinMode(static_cast<unsigned>(m_gpio), INPUT);
    m_isPlaying = false;
}


}
