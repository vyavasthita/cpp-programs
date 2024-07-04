#ifndef DISTRIBUTOR_H_INCLUDED
#define DISTRIBUTOR_H_INCLUDED

#include "vendor.h"
#include "list.h"

class Vendor;

class AllInOneDistributor
{
    public:
        ~AllInOneDistributor();
        static AllInOneDistributor* getInstance();
        void registorVendor(Vendor* vendor);
        void unRegistorVendor(Vendor* vendor);
        void notifyVendors();

    private:
        AllInOneDistributor();

        AllInOneDistributor(const AllInOneDistributor& oAllInOneDistributor);
        AllInOneDistributor& operator=(const AllInOneDistributor& oAllInOneDistributor);

        static AllInOneDistributor* m_opAllInOneDistributor;

    private:
        List<Vendor*> m_oVendors;
        List<Vendor*>::Iterator it;
};

#endif // DISTRIBUTOR_H_INCLUDED
