#include <gtest/gtest.h>
#include "MarwinPi_Diode.hpp"
#include "MarwinPi_GpioPortMock.hpp"

namespace MarwinPi
{

class DiodeTestSuite : public ::testing::Test
{
public:
    DiodeTestSuite() :
        m_gpioPortMock(new GpioPortMock),
        m_portRawPtr(m_gpioPortMock.get()),
        m_sut(std::move(m_gpioPortMock))
    {
    }

    std::unique_ptr<GpioPortMock> m_gpioPortMock;
    GpioPortMock* m_portRawPtr;
    Diode m_sut;
};

TEST_F(DiodeTestSuite, shouldWriteHighToPortWhenSwitchOn)
{
    EXPECT_CALL(*m_portRawPtr, write(GpioValue::GpioValue_High));
    m_sut.switchOn();
    EXPECT_EQ(m_sut.isSwitchedOn(), true);
}

TEST_F(DiodeTestSuite, shouldWriteLowToPortWhenShwitchOff)
{
    EXPECT_CALL(*m_portRawPtr, write(GpioValue::GpioValue_Low));
    m_sut.switchOff();
    EXPECT_EQ(m_sut.isSwitchedOn(), false);
}

}
