#pragma once

#include <iostream>
#include <vector>


namespace NAMESPACE_PARENTHESES
{
	typedef enum Brackets
	{
		SMALL_OPEN = '(',
		SMALL_CLOSE = ')',
		ANGLE_OPEN = '{',
		ANGLE_CLOSE = '}',
		SQUARE_OPEN = '[',
		SQUARE_CLOSE = ']',
		INVALID = ' '
	}BRACKET;

	typedef enum BraketType
	{
		OPEN = 0,
		CLOSE = 1
	}TYPE;

	class Parentheses
	{
	public:
		Parentheses();
		~Parentheses();

		BRACKET getClosedPairedBracket(char cType);
		bool isClosedBracket(char cType);
		bool isPairedSuccessfull(char firstBracket, BRACKET secondBracket);

		bool areParenthesesBalanced(std::string strBrackets);

	private:
		std::vector<char> m_vecBrackets;
	};
};
