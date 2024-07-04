#include "RobotDealer.h"
#include "RobotFactory.h"
#include <conio.h>


using namespace Robot;
using namespace std;

int main()
{
	std::vector<const char*> v_RobotDetails;

	RobotFactory* factory = new IndianRobotFactory();
	RobotDealer* dealer = new RobotDealer(factory);

	v_RobotDetails = dealer->assembleRobot();

	std::vector<const char*>::iterator it = v_RobotDetails.begin();

	cout << "Robot Details are given ;- \n";

	for(it; it != v_RobotDetails.end(); it++)
	{
		cout << *it << endl;
	}

	delete factory;
	factory = NULL;

	delete dealer;

	_getch();
	return 0;
}