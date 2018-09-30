#include <gtest/gtest.h>
#include "MarwinPi_GpioPort.hpp"
#include "MarwinPi_GpioException.hpp"

namespace MarwinPi
{

class GpioPortTestSuite : public ::testing::Test
{
public:
    GpioPortTestSuite() :
        gpioPortOutput(GpioWpi::GpioWpi_1, GpioMode::GpioMode_Output),
        gpioPortInput(GpioWpi::GpioWpi_2, GpioMode::GpioMode_Input),
        gpioPortPwm(GpioWpi::GpioWpi_3, GpioMode::GpioMode_Pwm)
    {
    }

    GpioPort gpioPortOutput;
    GpioPort gpioPortInput;
    GpioPort gpioPortPwm;
};

TEST_F(GpioPortTestSuite, checkWpiNumberAndGpioMode)
{
    EXPECT_EQ(gpioPortOutput.getWpiPort(), GpioWpi::GpioWpi_1);
    EXPECT_EQ(gpioPortOutput.getMode(), GpioMode::GpioMode_Output);
    EXPECT_EQ(gpioPortInput.getMode(), GpioMode::GpioMode_Input);
    EXPECT_EQ(gpioPortPwm.getMode(), GpioMode::GpioMode_Pwm);
}

TEST_F(GpioPortTestSuite, shouldNotThrowExceptionWhenWirtingToOutputPort)
{
    EXPECT_NO_THROW(gpioPortOutput.write(GpioValue::GpioValue_High));
}

TEST_F(GpioPortTestSuite, shouldThrowExceptionWhenWritingPwmSignalToOutputPort)
{
    EXPECT_THROW(gpioPortOutput.write(123), GpioException);
}

TEST_F(GpioPortTestSuite, shouldThrowExceptionWhenReadingFromOutputPort)
{
    EXPECT_THROW(gpioPortOutput.read(), GpioException);
}

TEST_F(GpioPortTestSuite, shouldNotThrowExceptionWhenReadingFromInputPort)
{
    EXPECT_NO_THROW(gpioPortInput.read());
}

TEST_F(GpioPortTestSuite, shouldThrowExceptionWhenWritingToInputPort)
{
    EXPECT_THROW(gpioPortInput.write(GpioValue::GpioValue_High), std::exception);
}

TEST_F(GpioPortTestSuite, shouldThrowExceptionWhenWritingPwmSignalToInputPort)
{
    EXPECT_THROW(gpioPortInput.write(123), GpioException);
}

TEST_F(GpioPortTestSuite, shouldNotThrowExceptionWhenWritingPwmSignalToPwmPort)
{
    EXPECT_NO_THROW(gpioPortPwm.write(123));
}

TEST_F(GpioPortTestSuite, shouldThrowExceptionWhenWritingToPwmPort)
{
    EXPECT_THROW(gpioPortPwm.write(GpioValue::GpioValue_High), std::exception);
}

TEST_F(GpioPortTestSuite, shouldThrowExceptionWhenReadingFromPwmPort)
{
    EXPECT_THROW(gpioPortPwm.read(), GpioException);
}

}
