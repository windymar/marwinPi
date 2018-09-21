#ifndef MARWINPI_IBUZZER_HPP
#define MARWINPI_IBUZZER_HPP

namespace MarwinPi
{

class IBuzzer
{
public:
    virtual ~IBuzzer() { }
    virtual void play(unsigned p_power) = 0;
    virtual bool isPlaying() const = 0;
    virtual void stop() = 0;
};

}

#endif // MARWINPI_IBUZZER_HPP
