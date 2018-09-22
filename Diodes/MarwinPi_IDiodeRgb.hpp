#ifndef MARWINPI_IDIODERGB_HPP
#define MARWINPI_IDIODERGB_HPP

namespace MarwinPi
{

class IDiodeRgb
{
public:
    virtual ~IDiodeRgb() { }

    virtual void switchOnRed() = 0;
    virtual void switchOnGreen() = 0;
    virtual void switchOnBlue() = 0;

    virtual void switchOffRed() = 0;
    virtual void switchOffGreen() = 0;
    virtual void switchOffBlue() = 0;
};

}

#endif // MARWINPI_IDIODERGB_HPP
