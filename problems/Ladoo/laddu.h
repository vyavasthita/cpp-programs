#pragma once

#include <iostream>

namespace LadduAccrualSystem
{
	typedef enum UserEthinicity
	{
		INDIAN = 1,
		NON_INDIAN = 2
	}ethinicity;

	typedef enum UserActivity
	{
		CONTEST_WON = 1,
		TOP_CONTRIBUTOR = 2,
		BUG_FOUND = 3,
		CONTEST_HOSTED = 4
	}activity;

	typedef struct ContestWon
	{
		bool bWon;
		short rank;
	}contest;

	typedef struct BugFinder
	{
		bool bFound;
		short severity;
	}bug;

	typedef struct UserDetail
	{
		ethinicity UserEthinicity;
		contest UserContest;
		bool topContibutor;
		bug bugDetails;
		bool contestHosted;
	}DETAILS;

	class LadduRedeem
	{
		public:
			LadduRedeem();
			~LadduRedeem();

			void addUserDetails(UserDetail detail);

			int getMaxNoOfMonthForRedeem();

		private:
			int m_nMaxReedeemLadoosPerMonth;
			int m_nBonus;
			int m_nUserPoints;

			ethinicity m_ethinicity;
	};
};
