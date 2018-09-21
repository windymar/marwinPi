#ifndef MARWINPI_MOTIONSENSOR_HPP
#define MARWINPI_MOTIONSENSOR_HPP

#include "MarwinPi_IMotionSensor.hpp"
#include "MarwinPi_Types.hpp"

namespace MarwinPi
{

class MotionSensor : public IMotionSensor
{
public:
    MotionSensor(GPIO_WPI p_gpio);

    bool motionDetected() override;

private:
    GPIO_WPI m_gpio = GPIO_WPI::GPIO_WPI_0;
};

}

#endif // MARWINPI_MOTIONSENSOR_HPP
