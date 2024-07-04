#include "vendor.h"
#include "distributor.h"


Vendor::Vendor()
{
}

Vendor::~Vendor()
{
}

Chroma::Chroma()
{
    AllInOneDistributor::getInstance()->registorVendor(this);
}

Chroma::~Chroma()
{
}

void Chroma::notify()
{
}

RelianceDigital::RelianceDigital()
{
    AllInOneDistributor::getInstance()->registorVendor(this);
}

RelianceDigital::~RelianceDigital()
{
}

void RelianceDigital::notify()
{
}
