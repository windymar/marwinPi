#include <gtest/gtest.h>
#include "MarwinPi_MotionSensor.hpp"
#include "MarwinPi_GpioPortMock.hpp"

namespace MarwinPi
{

using ::testing::Return;

class MotionSensorTestSuite : public ::testing::Test
{
public:
    MotionSensorTestSuite() :
        m_gpioPortMock(new GpioPortMock),
        m_portRawPtr(m_gpioPortMock.get()),
        m_sut(std::move(m_gpioPortMock))
    {
    }

    std::unique_ptr<GpioPortMock> m_gpioPortMock;
    GpioPortMock* m_portRawPtr;
    MotionSensor m_sut;
};

TEST_F(MotionSensorTestSuite, shouldDetectMotionWhenHighOnPort)
{
    EXPECT_CALL(*m_portRawPtr, read()).WillOnce(Return(GpioValue::GpioValue_High));
    EXPECT_EQ(m_sut.motionDetected(), true);
}

TEST_F(MotionSensorTestSuite, shouldNotDetectMotionWhenLowOnPort)
{
    EXPECT_CALL(*m_portRawPtr, read()).WillOnce(Return(GpioValue::GpioValue_Low));
    EXPECT_EQ(m_sut.motionDetected(), false);
}

}
