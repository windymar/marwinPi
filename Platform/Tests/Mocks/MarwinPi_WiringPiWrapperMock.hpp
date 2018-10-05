#ifndef MARWINPI_WIRINGPIWRAPPERMOCK_HPP
#define MARWINPI_WIRINGPIWRAPPERMOCK_HPP

#include <gmock/gmock.h>
#include "MarwinPi_IWiringPiWrapper.hpp"

namespace MarwinPi
{

class WiringPiWrapperMock : public IWiringPiWrapper
{
public:
    MOCK_CONST_METHOD2(pinMode, void(GpioWpi, GpioMode));
    MOCK_CONST_METHOD2(digitalWrite, void(GpioWpi, GpioValue));
    MOCK_CONST_METHOD2(pwmWrite, void(GpioWpi, unsigned));
    MOCK_CONST_METHOD1(digitalRead, GpioValue(GpioWpi));
};

}

#endif // MARWINPI_WIRINGPIWRAPPERMOCK_HPP
