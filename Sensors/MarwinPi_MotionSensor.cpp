#include "MarwinPi_MotionSensor.hpp"
#include <wiringPi.h>

namespace MarwinPi
{

MotionSensor::MotionSensor(std::unique_ptr<IGpioPort>& p_gpioPort) :
    m_gpioPort(p_gpioPort)
{
}

bool MotionSensor::motionDetected()
{
    return (m_gpioPort->read() == GpioValue::GpioValue_High);
}

}
