#include "MarwinPi_Diode.hpp"
#include <wiringPi.h>

namespace MarwinPi
{

Diode::Diode(unsigned p_gpio) : m_gpio(p_gpio)
{
    pinMode(m_gpio, OUTPUT);
}

Diode::~Diode()
{
    switchOff();
    pinMode(m_gpio, INPUT);
}

void Diode::switchOn()
{
    digitalWrite(m_gpio, HIGH);
    m_isSwichedOn = true;
}

void Diode::switchOff()
{
    digitalWrite(m_gpio, LOW);
    m_isSwichedOn = false;
}

bool Diode::isSwitchedOn()
{
    return m_isSwichedOn;
}

}
