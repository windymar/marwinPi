#ifndef MARWINPI_IMOTIONSENSOR_HPP
#define MARWINPI_IMOTIONSENSOR_HPP

namespace MarwinPi
{

class IMotionSensor
{
public:
    virtual ~IMotionSensor() { }

    virtual bool motionDetected() = 0;
};

}

#endif // MARWINPI_IMOTIONSENSOR_HPP
