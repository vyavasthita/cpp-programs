#include "Robot.h"


#ifndef _ROBOT_FACT__H_
#define _ROBOT_FACT__H_


namespace Robot
{
	class RobotFactory
	{
		public:
			virtual Brain* getBrain() = 0;
			virtual Body* getBody() = 0;
			virtual Movement* getMovement() = 0;
	};

	class JapaneseRobotFactory : public RobotFactory
	{
		public:
			virtual Brain* getBrain();
			virtual Body* getBody();
			virtual Movement* getMovement();
	};

	class IndianRobotFactory : public RobotFactory
	{
		public:
			virtual Brain* getBrain();
			virtual Body* getBody();
			virtual Movement* getMovement();
	};

	class ChineseRobotFactory : public RobotFactory
	{
		public:
			virtual Brain* getBrain();
			virtual Body* getBody();
			virtual Movement* getMovement();
	};
};

#endif _ROBOT_FACT__H_