#ifndef MARWINPI_IDIODE_HPP
#define MARWINPI_IDIODE_HPP

namespace MarwinPi
{

class IDiode
{
public:
    virtual ~IDiode() { }

    virtual void switchOn() = 0;
    virtual void switchOff() = 0;
};

}

#endif // MARWINPI_IDIODE_HPP
