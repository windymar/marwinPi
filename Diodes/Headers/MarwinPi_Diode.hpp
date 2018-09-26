#ifndef MARWINPI_DIODE_HPP
#define MARWINPI_DIODE_HPP

#include "MarwinPi_IDiode.hpp"
#include "MarwinPi_Types.hpp"
#include "MarwinPi_IGpioPort.hpp"
#include <memory>

namespace MarwinPi
{

class Diode : public IDiode
{
public:
    Diode(std::unique_ptr<IGpioPort>& p_gpioPort);
    ~Diode();

    void switchOn() override;
    void switchOff() override;
    bool isSwitchedOn() override;

private:
    std::unique_ptr<IGpioPort>& m_gpioPort;
    bool m_isSwichedOn = false;
};

}

#endif // MARWINPI_DIODE_HPP
