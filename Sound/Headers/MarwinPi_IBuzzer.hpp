#ifndef MARWINPI_IBUZZER_HPP
#define MARWINPI_IBUZZER_HPP

namespace MarwinPi
{

class IBuzzer
{
public:
    virtual ~IBuzzer() { }
    virtual void play() = 0;
    virtual bool isPlaying() const = 0;
    virtual void stopPlaying() = 0;
};

}

#endif // MARWINPI_IBUZZER_HPP
