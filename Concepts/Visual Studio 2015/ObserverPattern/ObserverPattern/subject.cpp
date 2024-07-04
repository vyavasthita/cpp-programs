#include "subject.h"

ComputerDistributor::ComputerDistributor()
{
	m_nBasePrice = 40000;
}

void ComputerDistributor::Register(Dealer* opDealer)
{
	m_vecDealers.push_back(opDealer);
}

void ComputerDistributor::UnRegister(Dealer* opDealer)
{
	std::vector<Dealer*>::iterator it = m_vecDealers.begin();

	for (it; it != m_vecDealers.end();)
	{
		if (*it == opDealer)
		{
			m_vecDealers.erase(it++);
			//break;
		}
		++it;
	}
}

void ComputerDistributor::Notify()
{
	std::vector<Dealer*>::iterator it = m_vecDealers.begin();

	for (it; it != m_vecDealers.end(); it++)
	{
		(*it)->update(m_nBasePrice);
	}
}