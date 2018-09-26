#ifndef MARWINPI_GPIOEXCEPTION_HPP
#define MARWINPI_GPIOEXCEPTION_HPP

#include <stdexcept>
#include <string>
#include "MarwinPi_Types.hpp"

namespace MarwinPi
{

class GpioException : public std::logic_error
{
public:
    GpioException(std::string p_msg, GpioWpi p_gpio, GpioMode p_mode);

    const char* what() const throw() override;

private:
    GpioWpi m_gpio;
    GpioMode m_mode;
};

}

#endif // MARWINPI_GPIOEXCEPTION_HPP
