#include <gtest/gtest.h>
#include "MarwinPi_Buzzer.hpp"
#include "MarwinPi_GpioPortMock.hpp"

namespace MarwinPi
{

class BuzzerTestSuite : public ::testing::Test
{
public:
    BuzzerTestSuite() :
        m_gpioPortMock(new GpioPortMock),
        m_portRawPtr(m_gpioPortMock.get()),
        m_sut(std::move(m_gpioPortMock))
    {

    }

    std::unique_ptr<GpioPortMock> m_gpioPortMock;
    GpioPortMock* m_portRawPtr;
    Buzzer m_sut;
};

TEST_F(BuzzerTestSuite, shouldPlayWhenLowOnPort)
{
    EXPECT_CALL(*m_portRawPtr, write(GpioValue::GpioValue_Low));
    m_sut.play();
    EXPECT_EQ(m_sut.isPlaying(), true);
}

TEST_F(BuzzerTestSuite, shouldNotPlayWhenHighOnPort)
{
    EXPECT_CALL(*m_portRawPtr, write(GpioValue::GpioValue_High));
    m_sut.stopPlaying();
    EXPECT_EQ(m_sut.isPlaying(), false);
}


}
