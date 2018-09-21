#ifndef MARWINPI_BUZZER_HPP
#define MARWINPI_BUZZER_HPP

#include "MarwinPi_IBuzzer.hpp"

namespace MarwinPi
{

class Buzzer : public IBuzzer
{
public:
    Buzzer(unsigned p_gpio = 0);
    ~Buzzer();

    void play() override;
    bool isPlaying() const override;
    void stop() override;

private:
    unsigned m_gpio = 0;
    bool m_isPlaying = false;
};

}

#endif // MARWINPI_BUZZER_HPP
