#ifndef MARWINPI_IGPIOPORTFACTORY_HPP
#define MARWINPI_IGPIOPORTFACTORY_HPP

#include "MarwinPi_IGpioPort.hpp"
#include <memory>

namespace MarwinPi
{

class IGpioPortFactory
{
public:
    virtual std::unique_ptr<IGpioPort> createGpioPort(GpioWpi, GpioMode) = 0;
};

}

#endif // MARWINPI_IGPIOPORTFACTORY_HPP
