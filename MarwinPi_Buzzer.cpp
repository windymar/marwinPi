#include "MarwinPi_Buzzer.hpp"
#include <wiringPi.h>

namespace MarwinPi
{

Buzzer::Buzzer(unsigned p_gpio) : m_gpio(p_gpio)
{
}

Buzzer::~Buzzer()
{
    digitalWrite(m_gpio, LOW);
    stop();
}

void Buzzer::play(unsigned p_power)
{
    pinMode(m_gpio, OUTPUT);
    digitalWrite(m_gpio, LOW);
    m_isPlaying = true;
}

bool Buzzer::isPlaying() const
{
    return m_isPlaying;
}

void Buzzer::stop()
{
    digitalWrite(m_gpio, HIGH);
    pinMode(m_gpio, INPUT);
    m_isPlaying = false;
}


}
