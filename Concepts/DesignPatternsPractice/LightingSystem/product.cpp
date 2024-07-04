#include "product.h"
#include <iostream>

AC::AC()
{
}

AC::~AC()
{
}

TataAC::TataAC() :
    m_opName("Tata AC"),
    m_onPrice(1000)
{
}

TataAC::~TataAC()
{
}

const char* TataAC::getName()
{
    return m_opName;
}

unsigned short TataAC::getPrice()
{
    return m_onPrice;
}

void TataAC::switchOn()
{
    std::cout << "Tata AC is Switched On" << std::endl;
}

void TataAC::switchOff()
{
    std::cout << "Tata AC is Switched Off" << std::endl;
}

HoneywellAC::HoneywellAC() :
    m_opName("Honeywell AC"),
    m_onPrice(1200)
{

}

HoneywellAC::~HoneywellAC()
{
}

const char* HoneywellAC::getName()
{
    return m_opName;
}

unsigned short HoneywellAC::getPrice()
{
    return m_onPrice;
}

void HoneywellAC::switchOn()
{
    std::cout << "Honeywell AC is Switched On" << std::endl;
}

void HoneywellAC::switchOff()
{
    std::cout << "Honeywell AC is Switched Off" << std::endl;
}

TubeLight::TubeLight()
{
}

TubeLight::~TubeLight()
{
}

TataTubeLight::TataTubeLight() :
    m_opName("Tata TubeLight"),
    m_onPrice(900)
{

}

TataTubeLight::~TataTubeLight()
{
}

const char* TataTubeLight::getName()
{
    return m_opName;
}

unsigned short TataTubeLight::getPrice()
{
    return m_onPrice;
}

void TataTubeLight::switchOn()
{
    std::cout << "Tata TubeLight is Switched On" << std::endl;
}

void TataTubeLight::switchOff()
{
    std::cout << "Tata TubeLight is Switched Off" << std::endl;
}

HoneywellTubeLight::HoneywellTubeLight() :
    m_opName("Honeywell TubeLight"),
    m_onPrice(950)
{

}

HoneywellTubeLight::~HoneywellTubeLight()
{
}

const char* HoneywellTubeLight::getName()
{
    return m_opName;
}

unsigned short HoneywellTubeLight::getPrice()
{
    return m_onPrice;
}

void HoneywellTubeLight::switchOn()
{
    std::cout << "Honeywell TubeLight is Switched On" << std::endl;
}

void HoneywellTubeLight::switchOff()
{
    std::cout << "Honeywell TubeLight is Switched Off" << std::endl;
}
