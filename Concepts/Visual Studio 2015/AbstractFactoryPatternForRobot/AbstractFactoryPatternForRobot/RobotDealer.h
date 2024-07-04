#include "Robot.h"
#include "RobotFactory.h"
#include <vector>
#include <iostream>

#ifndef _ROBOT_DEALER__H_
#define _ROBOT_DEALER__H_


namespace Robot
{
	class  RobotDealer
	{
		public:
			 RobotDealer(RobotFactory* robotFactory);
			~RobotDealer();

			std::vector<const char*> assembleRobot();

		private:
			RobotFactory* m_RobotFactory;
			Brain* m_Brain;
			Body* m_Body;
			Movement* m_Movement;
	};
};

#endif _ROBOT_DEALER__H_