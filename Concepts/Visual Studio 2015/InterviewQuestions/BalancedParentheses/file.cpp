#include "file.h"

using namespace NAMESPACE_PARENTHESES;

Parentheses::Parentheses()
{
}

Parentheses::~Parentheses()
{
}

BRACKET Parentheses::getClosedPairedBracket(char cType)
{
	if (cType == BRACKET::SMALL_CLOSE)
	{
		return BRACKET::SMALL_OPEN;
	}
	else if (cType == BRACKET::ANGLE_CLOSE)
	{
		return BRACKET::ANGLE_OPEN;
	}
	else if (cType == BRACKET::SQUARE_CLOSE)
	{
		return BRACKET::SQUARE_OPEN;
	}
	else
	{
		return BRACKET::INVALID;
	}
}

bool Parentheses::isClosedBracket(char cType)
{
	if (
		(cType == BRACKET::SMALL_CLOSE) ||
		(cType == BRACKET::ANGLE_CLOSE) ||
		(cType == BRACKET::SQUARE_CLOSE)
		)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Parentheses::isPairedSuccessfull(char firstBracket, BRACKET secondBracket)
{
	if (firstBracket == secondBracket)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Parentheses::areParenthesesBalanced(std::string strBrackets)
{
	BRACKET currentBracket = BRACKET::INVALID;
	char lastOpenBracket = ' ';
	bool isSuccess = false;
	

	for (int i = 0; i < strBrackets.size(); i++)
	{
		if (isClosedBracket(strBrackets[i]))
		{
			if (m_vecBrackets.size() == 0)
			{
				return false;
			}
		
			currentBracket = getClosedPairedBracket(strBrackets[i]);
			lastOpenBracket = m_vecBrackets.back();
			m_vecBrackets.pop_back();

			if (isPairedSuccessfull(lastOpenBracket, currentBracket))
			{
				isSuccess = true;
			}			
			else
			{
				return false;
			}
		}
		else
		{
			m_vecBrackets.push_back(strBrackets[i]);
			isSuccess = false;
		}
	}
	return isSuccess;
}