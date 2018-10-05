#include <gtest/gtest.h>
#include "MarwinPi_GpioPortFactoryPi3.hpp"
#include "MarwinPi_GpioException.hpp"
#include "MarwinPi_WiringPiWrapperMock.hpp"

using ::testing::_;
using ::testing::AtLeast;

namespace MarwinPi
{

constexpr GpioWpi GPIO_WPI = GpioWpi::GpioWpi_2;
constexpr GpioMode GPIO_MODE = GpioMode::GpioMode_Output;

class GpioPortFactoryPi3TestSuite : public ::testing::Test
{
public:
    GpioPortFactoryPi3TestSuite() : m_sut(m_wiringPiWrapperMock)
    {
        EXPECT_CALL(m_wiringPiWrapperMock, pinMode(_, _)).Times(AtLeast(2));
    }

    WiringPiWrapperMock m_wiringPiWrapperMock;
    GpioPortFactoryPi3 m_sut;
};

TEST_F(GpioPortFactoryPi3TestSuite, shouldCreateProperGpioPort)
{
    std::unique_ptr<IGpioPort> l_port = m_sut.createGpioPort(GPIO_WPI, GPIO_MODE);
    EXPECT_EQ(l_port->getWpiPort(), GPIO_WPI);
    EXPECT_EQ(l_port->getMode(), GPIO_MODE);
}

TEST_F(GpioPortFactoryPi3TestSuite, shouldThrowWhenGpioPortAlreadyUsed)
{
    m_sut.createGpioPort(GPIO_WPI, GPIO_MODE);
    EXPECT_THROW(m_sut.createGpioPort(GPIO_WPI, GPIO_MODE), GpioException);
}

}
