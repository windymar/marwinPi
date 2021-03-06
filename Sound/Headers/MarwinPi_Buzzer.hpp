#ifndef MARWINPI_BUZZER_HPP
#define MARWINPI_BUZZER_HPP

#include "MarwinPi_IBuzzer.hpp"
#include "MarwinPi_Types.hpp"
#include "MarwinPi_IGpioPort.hpp"
#include <memory>

namespace MarwinPi
{

class Buzzer : public IBuzzer
{
public:
    Buzzer(std::unique_ptr<IGpioPort> p_gpioPort);

    void play() override;
    bool isPlaying() const override;
    void stopPlaying() override;

private:
    std::unique_ptr<IGpioPort> m_gpioPort;
    bool m_isPlaying = false;
};

}

#endif // MARWINPI_BUZZER_HPP
