#ifndef MARWINPI_DIODE_HPP
#define MARWINPI_DIODE_HPP

#include "MarwinPi_IDiode.hpp"

namespace MarwinPi
{

class Diode : public IDiode
{
public:
    Diode(unsigned p_gpio = 0);
    ~Diode();

    void switchOn() override;
    void switchOff() override;

private:
    unsigned m_gpio = 0;
};

}

#endif // MARWINPI_DIODE_HPP