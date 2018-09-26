#include "MarwinPi_DiodeRgb.hpp"

namespace MarwinPi
{

DiodeRgb::DiodeRgb(
        std::unique_ptr<IGpioPort>& p_redGpioPort,
        std::unique_ptr<IGpioPort>& p_greenGpioPort,
        std::unique_ptr<IGpioPort>& p_blueGpioPort) :
    m_redGpioPort(p_redGpioPort),
    m_greenGpioPort(p_greenGpioPort),
    m_blueGpioPort(p_blueGpioPort)
{

}

void DiodeRgb::switchOnRed()
{
    m_redGpioPort->write(GpioValue::GpioValue_High);
}

void DiodeRgb::switchOnGreen()
{
    m_greenGpioPort->write(GpioValue::GpioValue_High);
}

void DiodeRgb::switchOnBlue()
{
    m_blueGpioPort->write(GpioValue::GpioValue_High);
}

void DiodeRgb::switchOffRed()
{
    m_redGpioPort->write(GpioValue::GpioValue_Low);
}

void DiodeRgb::switchOffGreen()
{
    m_greenGpioPort->write(GpioValue::GpioValue_Low);
}

void DiodeRgb::switchOffBlue()
{
    m_blueGpioPort->write(GpioValue::GpioValue_Low);
}

}
