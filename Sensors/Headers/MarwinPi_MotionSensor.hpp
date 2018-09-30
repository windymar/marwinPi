#ifndef MARWINPI_MOTIONSENSOR_HPP
#define MARWINPI_MOTIONSENSOR_HPP

#include "MarwinPi_IMotionSensor.hpp"
#include "MarwinPi_Types.hpp"
#include "MarwinPi_IGpioPort.hpp"
#include <memory>

namespace MarwinPi
{

class MotionSensor : public IMotionSensor
{
public:
    MotionSensor(std::unique_ptr<IGpioPort> p_gpioPort);

    bool motionDetected() override;

private:
    std::unique_ptr<IGpioPort> m_gpioPort;
};

}

#endif // MARWINPI_MOTIONSENSOR_HPP
