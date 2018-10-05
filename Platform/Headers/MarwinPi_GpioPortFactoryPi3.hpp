#ifndef MARWINPI_GPIOPORTFACTORYPI3_HPP
#define MARWINPI_GPIOPORTFACTORYPI3_HPP

#include "MarwinPi_IGpioPortFactory.hpp"
#include "MarwinPi_IWiringPiWrapper.hpp"
#include <map>

namespace MarwinPi
{

class GpioPortFactoryPi3 : public IGpioPortFactory
{
public:
    GpioPortFactoryPi3(IWiringPiWrapper& p_wiringPiWrapper);

    std::unique_ptr<IGpioPort> createGpioPort(GpioWpi, GpioMode) override;

private:
    bool isGpioUsed(GpioWpi);
    void markGpioUsed(GpioWpi);

    std::map<GpioWpi, bool> m_gpioUsageMap {
        { GpioWpi::GpioWpi_0, false },
        { GpioWpi::GpioWpi_1, false },
        { GpioWpi::GpioWpi_2, false },
        { GpioWpi::GpioWpi_3, false },
        { GpioWpi::GpioWpi_4, false },
        { GpioWpi::GpioWpi_5, false },
        { GpioWpi::GpioWpi_6, false },
        { GpioWpi::GpioWpi_7, false },
        { GpioWpi::GpioWpi_21, false },
        { GpioWpi::GpioWpi_22, false },
        { GpioWpi::GpioWpi_23, false },
        { GpioWpi::GpioWpi_24, false },
        { GpioWpi::GpioWpi_25, false },
        { GpioWpi::GpioWpi_26, false },
        { GpioWpi::GpioWpi_27, false },
        { GpioWpi::GpioWpi_28, false },
        { GpioWpi::GpioWpi_29, false }
    };

    IWiringPiWrapper& m_wiringPiWrapper;
};

}

#endif // MARWINPI_GPIOPORTFACTORYPI3_HPP
