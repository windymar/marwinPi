#include "MarwinPi_Setup.hpp"
#include <wiringPi.h>

namespace MarwinPi
{

Setup::Setup()
{
#ifdef UNITTESTS
#else
    wiringPiSetup();
#endif
}

void Setup::sleep(unsigned p_miliseconds)
{
#ifdef UNITTESTS
#else
    delay(p_miliseconds);
#endif
}

}
