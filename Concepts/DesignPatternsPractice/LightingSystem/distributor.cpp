#include "distributor.h"
#include <iostream>


AllInOneDistributor* AllInOneDistributor::m_opAllInOneDistributor = NULL;


AllInOneDistributor::AllInOneDistributor()
{
}

AllInOneDistributor::~AllInOneDistributor()
{
}

AllInOneDistributor* AllInOneDistributor::getInstance()
{
    if (m_opAllInOneDistributor == NULL)
    {
        m_opAllInOneDistributor = new AllInOneDistributor();
    }
    return m_opAllInOneDistributor;
}

void AllInOneDistributor::registorVendor(Vendor* vendor)
{
    m_oVendors.pushBack(vendor);
}

void AllInOneDistributor::unRegistorVendor(Vendor* vendor)
{
    m_oVendors.deleteNode(vendor);
}

void AllInOneDistributor::notifyVendors()
{
    it = m_oVendors.beginNode();

    for (it; it != m_oVendors.endNode(); ++it)
    {
        (*it)->notify();
    }
}
