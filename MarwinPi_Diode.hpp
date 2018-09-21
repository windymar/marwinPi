#ifndef MARWINPI_DIODE_HPP
#define MARWINPI_DIODE_HPP

#include "MarwinPi_IDiode.hpp"
#include "MarwinPi_Types.hpp"

namespace MarwinPi
{

class Diode : public IDiode
{
public:
    Diode(GPIO_WPI p_gpio);
    ~Diode();

    void switchOn() override;
    void switchOff() override;
    bool isSwitchedOn() override;

private:
    GPIO_WPI m_gpio = GPIO_WPI::GPIO_WPI_0;
    bool m_isSwichedOn = false;
};

}

#endif // MARWINPI_DIODE_HPP
