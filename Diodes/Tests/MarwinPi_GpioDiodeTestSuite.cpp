#include <gtest/gtest.h>
#include "MarwinPi_Diode.hpp"
#include "MarwinPi_GpioPortMock.hpp"

namespace MarwinPi
{

class DiodeTestSuite : public ::testing::Test
{
public:
    //DiodeTestSuite() :
        //m_gpioPortMock(new GpioPortMock)
    //{
    //}

    //std::unique_ptr<GpioPortMock> m_gpioPortMock;
};

TEST(DiodeTestSuite, shouldWriteHighToPortWhenSwitchOn)
{
    std::unique_ptr<GpioPortMock> m_gpioPortMock(new GpioPortMock);
    GpioPortMock* rawPtr = m_gpioPortMock.get();
    Diode diode(std::move(m_gpioPortMock));
    EXPECT_CALL(*rawPtr, write(GpioValue::GpioValue_High));
    EXPECT_CALL(*rawPtr, write(GpioValue::GpioValue_Low));
    diode.switchOn();
}

}
