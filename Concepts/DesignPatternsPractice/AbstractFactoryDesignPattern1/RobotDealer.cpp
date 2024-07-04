#include "Robot.h"
#include "RobotFactory.h"
#include "RobotDealer.h"


using namespace Robot;

RobotDealer::RobotDealer(RobotFactory* robotFactory) : m_RobotFactory(robotFactory)
{

}

RobotDealer::~RobotDealer()
{
	delete m_Brain;
	delete m_Body;
	delete m_Movement;

	m_Brain = NULL;
	m_Body = NULL;
	m_Movement = NULL;
}

std::vector<const char*> RobotDealer::assembleRobot()
{
	m_Brain = m_RobotFactory->getBrain();
	m_Body = m_RobotFactory->getBody();
	m_Movement = m_RobotFactory->getMovement();

	const char* brainType = m_Brain->getBrain();
	const char* bodyType = m_Body->getBody();
	const char* movementType = m_Movement->getMovement();

	std::vector<const char*> v_RobotDetails;

	v_RobotDetails.push_back(brainType);
	v_RobotDetails.push_back(bodyType);
	v_RobotDetails.push_back(movementType);

	return v_RobotDetails;
}