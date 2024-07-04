/*
########Laddu#######3

You might have heard about our new goodie distribution program aka the "Laddu Accrual System". This problem is designed to give you a glimpse of its rules. You can read the page once before attempting the problem if you wish, nonetheless we will be providing all the information needed here itself.
Laddu Accrual System is our new goodie distribution program. In this program, we will be distributing Laddus in place of goodies for your winnings and various other activities (described below), that you perform on our system. Once you collect enough number of Laddus, you can then redeem them to get yourself anything from a wide range of CodeChef goodies.
Let us know about various activities and amount of laddus you get corresponding to them.
Contest Win (CodeChef’s Long, Cook-Off, LTIME, or any contest hosted with us) : 300 + Bonus (Bonus = 20 - contest rank). Note that if your rank is > 20, then you won't get any bonus.
Top Contributor on Discuss : 300
Bug Finder	: 50 - 1000 (depending on the bug severity). It may also fetch you a CodeChef internship!
Contest Hosting	: 50
You can do a checkout for redeeming laddus once a month. The minimum laddus redeemable at Check Out are 200 for Indians and 400 for the rest of the world.
You are given history of various activities of a user. The user has not redeemed any of the its laddus accrued.. Now the user just wants to redeem as less amount of laddus he/she can, so that the laddus can last for as long as possible. Find out for how many maximum number of months he can redeem the laddus.
Input

The first line of input contains a single integer T denoting number of test cases
For each test case:
First line contains an integer followed by a string denoting activities, origin respectively, where activities denotes number of activities of the user, origin denotes whether the user is Indian or the rest of the world. origin can be "INDIAN" or "NON_INDIAN".
For each of the next activities lines, each line contains an activity.
An activity can be of four types as defined above.
Contest Win : Input will be of form of CONTEST_WON rank, where rank denotes the rank of the user.
Top Contributor : Input will be of form of TOP_CONTRIBUTOR.
Bug Finder : Input will be of form of BUG_FOUND severity, where severity denotes the severity of the bug.
Contest Hosting : Input will be of form of CONTEST_HOSTED.
Output

For each test case, find out the maximum number of months for which the user can redeem the laddus accrued.
Constraints

1 ≤ T, activities ≤ 100
1 ≤ rank ≤ 5000
50 ≤ severity ≤ 1000
Subtasks

There is only a single subtask with 100 points.
Example

Input:
2
4 INDIAN
CONTEST_WON 1
TOP_CONTRIBUTOR
BUG_FOUND 100
CONTEST_HOSTED
4 NON_INDIAN
CONTEST_WON 1
TOP_CONTRIBUTOR
BUG_FOUND 100
CONTEST_HOSTED

Output:
3
1
Explanation

In the first example,
For winning contest with rank 1, user gets 300 + 20 - 1 = 319 laddus.
For top contributor, user gets 300 laddus.
For finding a bug with severity of 100, user gets 100 laddus.
For hosting a contest, user gets 50 laddus.
So, overall user gets 319 + 300 + 100 + 50 = 769 laddus.
Now, the user is an Indian user, he can redeem only 200 laddus per month. So, for first three months, he will redeem 200 * 3 = 600 laddus. The remaining 169 laddus, he can not redeem as he requires at least 200 laddues in a month to redeem.
So, answer is 3.
In the second example, user is a non-Indian user, he can redeem 400 laddues per month. So, in the first month, he will redeem 400 laddus. The remaining 369 laddus, he can not redeem as he requires at least 400 laddues in a month to redeem.
So, answer is 1.

Source : https://www.codechef.com/problems/LADDU
*/

#include "laddu.h"
#include <conio.h>

using namespace LadduAccrualSystem;

int main()
{
	int nT;
	short ethinicity;
	int numberOfActivities = 0;
	int activityType = 0;
	int rank = 0;
	int bugSeverity = 0;
	
	UserDetail detail;

	std::cout << "Enter value of T (number of games to play) --> ";
	std::cin >> nT;
	std::cout << std::endl;


	for (short playCount = 0; playCount < nT; playCount++)
	{
		std::cout << "Enter No of Activities --> ";
		std::cin >> numberOfActivities;

		std::cout << "\n\n";

		std::cout << "Ethinicity detail...\n";
		std::cout << "1. Indian\n";
		std::cout << "2. NON INDIAN\n";	
		std::cin >> ethinicity;

		switch (ethinicity)
		{
			case UserEthinicity::INDIAN:
				detail.UserEthinicity = UserEthinicity::INDIAN;
				break;
			case UserEthinicity::NON_INDIAN:
				detail.UserEthinicity = UserEthinicity::NON_INDIAN;
				break;
			default:
				std::cout << "Invalid Input\n";
				break;
		}
		std::cout << "\n\n";

		int i = 0;

		while (numberOfActivities--)
		{
			std::cout << "Activity Type...\n";
			std::cout << "1. Contest Won\n";
			std::cout << "2. Top Contributor\n";
			std::cout << "3. Bug Found\n";
			std::cout << "4. Contest Hosted\n";

			std::cout << "Enter Activity Type " << ++i << " -->";
			std::cin >> activityType;
			std::cout << "\n";

			switch (activityType)
			{
				case UserActivity::CONTEST_WON:
					detail.UserContest.bWon = true;

					std::cout << "Enter Rank\n";
					std::cin >> rank;
					
					detail.UserContest.rank = rank;
					break;

				case UserActivity::TOP_CONTRIBUTOR:
					detail.topContibutor = true;
					break;

				case UserActivity::BUG_FOUND:
					detail.bugDetails.bFound = true;

					std::cout << "Enter Bug severity\n";
					std::cin >> bugSeverity;

					detail.bugDetails.severity = bugSeverity;

					break;
				case UserActivity::CONTEST_HOSTED:
					detail.contestHosted = true;
					break;

				default:
					std::cout << "Invalid Input\n";
					break;
			}
			std::cout << "\n\n";
		}		
	}

	LadduRedeem ladoo;

	ladoo.addUserDetails(detail);

	int maxRedeemMonths = ladoo.getMaxNoOfMonthForRedeem();

	std::cout << "Max no of redeem months --> " << maxRedeemMonths << std::endl;

	_getch();
	return 0;
}