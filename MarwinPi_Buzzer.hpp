#ifndef MARWINPI_BUZZER_HPP
#define MARWINPI_BUZZER_HPP

#include "MarwinPi_IBuzzer.hpp"
#include "MarwinPi_Types.hpp"

namespace MarwinPi
{

class Buzzer : public IBuzzer
{
public:
    Buzzer(GPIO_WPI p_gpio);
    ~Buzzer();

    void play() override;
    bool isPlaying() const override;
    void stop() override;

private:
    GPIO_WPI m_gpio = GPIO_WPI::GPIO_WPI_0;
    bool m_isPlaying = false;
};

}

#endif // MARWINPI_BUZZER_HPP
