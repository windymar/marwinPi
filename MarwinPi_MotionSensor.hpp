#ifndef MARWINPI_MOTIONSENSOR_HPP
#define MARWINPI_MOTIONSENSOR_HPP

#include "MarwinPi_IMotionSensor.hpp"

namespace MarwinPi
{

class MotionSensor : public IMotionSensor
{
public:
    MotionSensor(unsigned p_gpio = 0);

    bool motionDetected() override;

private:
    unsigned m_gpio = 0;
};

}

#endif // MARWINPI_MOTIONSENSOR_HPP
