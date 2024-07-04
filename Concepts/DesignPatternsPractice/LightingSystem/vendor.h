#ifndef VENDOR_H_INCLUDED
#define VENDOR_H_INCLUDED

#include "distributor.h"

class Vendor
{
    public:
        Vendor();
        ~Vendor();

        virtual void notify() = 0;
};

class Chroma : public Vendor
{
    public:
        Chroma();
        ~Chroma();

        virtual void notify();
};

class RelianceDigital : public Vendor
{
    public:
        RelianceDigital();
        ~RelianceDigital();

        virtual void notify();
};

#endif // VENDOR_H_INCLUDED
