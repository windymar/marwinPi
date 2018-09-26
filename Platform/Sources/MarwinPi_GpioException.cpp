#include "MarwinPi_GpioException.hpp"
#include <sstream>

namespace MarwinPi
{

GpioException::GpioException(std::string p_msg, GpioWpi p_gpio, GpioMode p_mode) :
    logic_error(p_msg), m_gpio(p_gpio), m_mode(p_mode)
{
}

const char* GpioException::what() const throw()
{
    std::ostringstream o;
    o << logic_error::what() << ", gpio wpi port " << static_cast<unsigned>(m_gpio)
      << ", port mode " << static_cast<unsigned>(m_mode) << std::endl;
    return o.str().c_str();
}

}
