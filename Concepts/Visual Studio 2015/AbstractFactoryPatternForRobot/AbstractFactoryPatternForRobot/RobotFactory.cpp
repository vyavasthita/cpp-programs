#include "RobotFactory.h"

using namespace Robot;


Brain* JapaneseRobotFactory::getBrain()
{
	return new StrongBrain();
}

Body* JapaneseRobotFactory::getBody()
{
	return new StrongBody();
}

Movement* JapaneseRobotFactory::getMovement()
{
	return new StrongMovement();
}

////////////////////

Brain* IndianRobotFactory::getBrain()
{
	return new MediumBrain();
}

Body* IndianRobotFactory::getBody()
{
	return new MediumBody();
}

Movement* IndianRobotFactory::getMovement()
{
	return new MediumMovement();
}

////////////////////

Brain* ChineseRobotFactory::getBrain()
{
	return new WeakBrain();
}

Body* ChineseRobotFactory::getBody()
{
	return new WeakBody();
}

Movement* ChineseRobotFactory::getMovement()
{
	return new WeakMovement();
}