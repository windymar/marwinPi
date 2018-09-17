#include "MarwinPi_MotionSensor.hpp"
#include <wiringPi.h>

namespace MarwinPi
{

MotionSensor::MotionSensor(unsigned p_gpio) : m_gpio(p_gpio)
{
    pinMode(m_gpio, INPUT);
}

bool MotionSensor::motionDetected()
{
    return (digitalRead(m_gpio) == HIGH);
}

}
