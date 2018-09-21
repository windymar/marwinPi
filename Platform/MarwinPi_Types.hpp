#ifndef MARWINPI_TYPES_HPP
#define MARWINPI_TYPES_HPP

namespace MarwinPi
{

enum class GpioBcm
{
    GpioBcm_4 = 4,
    GpioBcm_17 = 17,
    GpioBcm_27 = 27,
    GpioBcm_22 = 22,
    GpioBcm_5 = 5,
    GpioBcm_6 = 6,
    GpioBcm_13 = 13,
    GpioBcm_19 = 19,
    GpioBcm_26 = 26,
    GpioBcm_18 = 18,
    GpioBcm_23 = 23,
    GpioBcm_24 = 24,
    GpioBcm_25 = 25,
    GpioBcm_12 = 12,
    GpioBcm_16 = 16,
    GpioBcm_20 = 20,
    GpioBcm_21 = 21
};

enum class GpioWpi
{
    GpioWpi_7 = 7,
    GpioWpi_0 = 0,
    GpioWpi_2 = 2,
    GpioWpi_3 = 3,
    GpioWpi_21 = 21,
    GpioWpi_22 = 22,
    GpioWpi_23 = 23,
    GpioWpi_24 = 24,
    GpioWpi_25 = 25,
    GpioWpi_1 = 1,
    GpioWpi_4 = 4,
    GpioWpi_5 = 5,
    GpioWpi_6 = 6,
    GpioWpi_26 = 26,
    GpioWpi_27 = 27,
    GpioWpi_28 = 28,
    GpioWpi_29 = 29
};

enum class GpioMode
{
    GpioMode_Input = 0,
    GpioMode_Output = 1
};

enum class GpioValue
{
    GpioValue_Low = 0,
    GpioValue_High = 1
};

}

#endif // MARWINPI_TYPES_HPP
