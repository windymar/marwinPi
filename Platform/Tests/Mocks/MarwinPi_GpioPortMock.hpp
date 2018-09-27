#ifndef MARWINPI_GPIOPORTMOCK_HPP
#define MARWINPI_GPIOPORTMOCK_HPP

#include <gmock/gmock.h>
#include "MarwinPi_IGpioPort.hpp"

namespace MarwinPi
{

class GpioPortMock : public IGpioPort
{
public:
    MOCK_CONST_METHOD1(write, void(GpioValue));
    MOCK_CONST_METHOD1(write, void(unsigned));
    MOCK_CONST_METHOD0(read, GpioValue());
};

}

#endif // MARWINPI_GPIOPORTMOCK_HPP
