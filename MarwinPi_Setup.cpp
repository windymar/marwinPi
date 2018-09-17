#include "MarwinPi_Setup.hpp"
#include <wiringPi.h>

namespace MarwinPi
{

Setup::Setup()
{
    wiringPiSetup();
}

void Setup::sleep(unsigned p_miliseconds)
{
    delay(p_miliseconds);
}

}
