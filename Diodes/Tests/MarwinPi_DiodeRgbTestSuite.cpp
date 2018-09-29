#include <gtest/gtest.h>
#include "MarwinPi_DiodeRgb.hpp"
#include "MarwinPi_GpioPortMock.hpp"

namespace MarwinPi
{

class DiodeRgbTestSuite : public ::testing::Test
{
public:
    DiodeRgbTestSuite() :
        m_redGpioPortMock(new GpioPortMock),
        m_greenGpioPortMock(new GpioPortMock),
        m_blueGpioPortMock(new GpioPortMock),
        m_redPortRawPtr(m_redGpioPortMock.get()),
        m_greenPortRawPtr(m_greenGpioPortMock.get()),
        m_bluePortRawPtr(m_blueGpioPortMock.get()),
        m_sut(std::move(m_redGpioPortMock), std::move(m_greenGpioPortMock), std::move(m_blueGpioPortMock))
    {
    }

    std::unique_ptr<GpioPortMock> m_redGpioPortMock;
    std::unique_ptr<GpioPortMock> m_greenGpioPortMock;
    std::unique_ptr<GpioPortMock> m_blueGpioPortMock;
    GpioPortMock* m_redPortRawPtr;
    GpioPortMock* m_greenPortRawPtr;
    GpioPortMock* m_bluePortRawPtr;
    DiodeRgb m_sut;
};

TEST_F(DiodeRgbTestSuite, shouldWriteHighToRedPortWhenSwitchOnRed)
{
    EXPECT_CALL(*m_redPortRawPtr, write(GpioValue::GpioValue_High));
    m_sut.switchOnRed();
}

}
