#pragma once
#include "observer.h"
#include <vector>
#include <iostream>


class Distributor
{
	public:
		virtual void Register(Dealer* opDealer) = 0;
		virtual void UnRegister(Dealer* opDealer) = 0;
		virtual void Notify() = 0;

	protected:
		std::vector<Dealer*> m_vecDealers;
		int m_nBasePrice;
};

class ComputerDistributor : public Distributor
{
	public:
		ComputerDistributor();

		virtual void Register(Dealer* opDealer);
		virtual void UnRegister(Dealer* opDealer);
		virtual void Notify();
};
