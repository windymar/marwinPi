#include "MarwinPi_MotionSensor.hpp"
#include <wiringPi.h>

namespace MarwinPi
{

MotionSensor::MotionSensor(GPIO_WPI p_gpio) : m_gpio(p_gpio)
{
    pinMode(static_cast<unsigned>(m_gpio), INPUT);
}

bool MotionSensor::motionDetected()
{
    return (digitalRead(static_cast<unsigned>(m_gpio)) == HIGH);
}

}
