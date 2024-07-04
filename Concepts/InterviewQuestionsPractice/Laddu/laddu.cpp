#include "laddu.h"

using namespace LadduAccrualSystem;

LadduRedeem::LadduRedeem() : 
	m_nUserPoints(0), m_nBonus(0)
{
}

LadduRedeem::~LadduRedeem()
{
}

void LadduRedeem::addUserDetails(UserDetail detail)
{
	if (detail.UserEthinicity == ethinicity::INDIAN)
	{
		m_ethinicity = ethinicity::INDIAN;
		m_nMaxReedeemLadoosPerMonth = 200;
	}
	else
	{
		m_ethinicity = ethinicity::NON_INDIAN;
		m_nMaxReedeemLadoosPerMonth = 400;
	}

	if (detail.UserContest.bWon == UserActivity::CONTEST_WON)
	{
		if (detail.UserContest.rank < 20)
		{
			m_nBonus = 20 - detail.UserContest.rank;			
		}
		m_nUserPoints += 300 + m_nBonus;
	}
	if (detail.topContibutor)
	{
		m_nUserPoints += 300;
	}
	if (detail.bugDetails.bFound)
	{
		m_nUserPoints += detail.bugDetails.severity;
	}
	if (detail.contestHosted)
	{
		m_nUserPoints += 50;
	}
	std::cout << "Total Points -->" << m_nUserPoints << std::endl;
}

int LadduRedeem::getMaxNoOfMonthForRedeem()
{
	if (m_ethinicity == ethinicity::INDIAN)
	{
		return (m_nUserPoints / 200);
	}
	else
	{
		return (m_nUserPoints / 400);
	}
}