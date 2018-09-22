#ifndef MARWINPI_DIODERGB_HPP
#define MARWINPI_DIODERGB_HPP

#include "MarwinPi_IDiodeRgb.hpp"
#include "Platform/MarwinPi_IGpioPort.hpp"
#include <memory>

namespace MarwinPi
{

class DiodeRgb : IDiodeRgb
{
public:
    DiodeRgb(std::unique_ptr<IGpioPort>& p_redGpioPort,
             std::unique_ptr<IGpioPort>& p_greenGpioPort,
             std::unique_ptr<IGpioPort>& p_blueGpioPort);

    virtual void switchOnRed() override;
    virtual void switchOnGreen() override;
    virtual void switchOnBlue() override;

    virtual void switchOffRed() override;
    virtual void switchOffGreen() override;
    virtual void switchOffBlue() override;

private:
    std::unique_ptr<IGpioPort>& m_redGpioPort;
    std::unique_ptr<IGpioPort>& m_greenGpioPort;
    std::unique_ptr<IGpioPort>& m_blueGpioPort;
};

}

#endif // MARWINPI_DIODERGB_HPP
