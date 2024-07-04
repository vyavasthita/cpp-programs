#include "product.h"
#include "productfactory.h"
#include <iostream>

ProductFactory::ProductFactory()
{
}

ProductFactory::~ProductFactory()
{
}

TataProductFactory::TataProductFactory() :
    m_opAC(NULL), m_opTubeLight(NULL)
{

}

TataProductFactory::~TataProductFactory()
{
    if (m_opAC != NULL)
    {
        delete m_opAC;
        m_opAC = NULL;
    }

    if (m_opTubeLight != NULL)
    {
        delete m_opTubeLight;
        m_opTubeLight = NULL;
    }
}

AC* TataProductFactory::createAC()
{
    m_opAC = new TataAC();
    return m_opAC;
}

TubeLight* TataProductFactory::createTubelight()
{
    m_opTubeLight = new TataTubeLight();
    return m_opTubeLight;
}

HoneywellProductFactory::HoneywellProductFactory() :
    m_opAC(NULL), m_opTubeLight(NULL)
{

}

HoneywellProductFactory::~HoneywellProductFactory()
{
    if (m_opAC != NULL)
    {
        delete m_opAC;
        m_opAC = NULL;
    }

    if (m_opTubeLight != NULL)
    {
        delete m_opTubeLight;
        m_opTubeLight = NULL;
    }
}

AC* HoneywellProductFactory::createAC()
{
    m_opAC = new HoneywellAC();
    return m_opAC;
}

TubeLight* HoneywellProductFactory::createTubelight()
{
    m_opTubeLight = new HoneywellTubeLight();
    return m_opTubeLight;
}
