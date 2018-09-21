#include "MarwinPi_Diode.hpp"
#include <wiringPi.h>

namespace MarwinPi
{

Diode::Diode(GPIO_WPI p_gpio) : m_gpio(p_gpio)
{
    pinMode(static_cast<unsigned>(m_gpio), OUTPUT);
}

Diode::~Diode()
{
    switchOff();
    pinMode(static_cast<unsigned>(m_gpio), INPUT);
}

void Diode::switchOn()
{
    digitalWrite(static_cast<unsigned>(m_gpio), HIGH);
    m_isSwichedOn = true;
}

void Diode::switchOff()
{
    digitalWrite(static_cast<unsigned>(m_gpio), LOW);
    m_isSwichedOn = false;
}

bool Diode::isSwitchedOn()
{
    return m_isSwichedOn;
}

}
