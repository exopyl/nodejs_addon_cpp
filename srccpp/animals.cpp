#include <stdio.h>
#include <string.h>
#include "animals.h"

CDog::~CDog()
{
    printf("CDog::~CDog\n");
}

const std::string CDog::Speak() const
{
    return "wouaf";
}

CCat::~CCat()
{
    printf("CCat::~CCat\n");
}

const std::string CCat::Speak() const
{
    return "miaou";
}
