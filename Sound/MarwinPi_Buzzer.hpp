#ifndef MARWINPI_BUZZER_HPP
#define MARWINPI_BUZZER_HPP

#include "MarwinPi_IBuzzer.hpp"
#include "Platform/MarwinPi_Types.hpp"
#include "Platform/MarwinPi_IGpioPort.hpp"
#include <memory>

namespace MarwinPi
{

class Buzzer : public IBuzzer
{
public:
    Buzzer(std::unique_ptr<IGpioPort>& p_gpioPort);
    ~Buzzer();

    void play() override;
    bool isPlaying() const override;
    void stopPlaying() override;

private:
    std::unique_ptr<IGpioPort>& m_gpioPort;
    bool m_isPlaying = false;
};

}

#endif // MARWINPI_BUZZER_HPP
