#include <conio.h>
#include <iostream>
#include <Windows.h>
#include <string>
#include <sstream>


 // COPYRIGHT NOTICE:
 // Copyright (c) 2013 L&T IES
 // ALL RIGHTS RESERVED
 //
 // PROPRIETARY RIGHTS NOTICE:
 //      The software and information contained herein are proprietary to, and
 //      comprise valuable trade secrets of, L&T IES.
 //
 //
 //***************************************************************************
 // FILE NAME           :		PasswordDecryption.cpp
 // DESCRIPTION         :		Decrypts password contained by Config.ini file.
 // Product				:		GID
 // MODULE              :		MUU.exe
 // SINCE               : 
 // ENVIRONMENT         :		C++
 // CREATED BY			:		Dilip Sharma
 //	CREATED DATE		:		09/01/13
 // VERSION
 // NOTE                :
 // FUNCTION LIST       :
 //
 //
 // Change Log
 //      Author                 DDMMYY  Description
 //		---------------------   ------  ---------------------------------------
 //      Dilip Sharma	        090113  Added New file.
 //      Dilip Sharma	        170113  Changes done in ProcessRandomPassword().
 //      Dilip Sharma	        170113  Changes done in FillPasswordWithNumbers().
 //*******************************************************************************

#include "PasswordGenerator.h"

#include <sstream>
#include <stdexcept>
#include <time.h>

using namespace GIDInterface;

//Password Decryption
std::string CPasswordGenerator::m_stat_strDecryptPassword = "";
std::string CPasswordGenerator::m_stat_strPasswordIndex = "";
std::vector<std::string> CPasswordGenerator::m_stat_v_strPasswordTokens;
std::vector<unsigned int> CPasswordGenerator::m_stat_v_unPasswordRandomNumberIndex;

const unsigned int CPasswordGenerator::m_stat_const_unPasswordKeys[] = { 19, 6, 24, 9, 20, 5, 30, 12, 29, 10, 27, 7, 25, 8, 28, 11, 26, 21, 13, 23, 15, 22, 14, 16 };

//Random Password
unsigned int CPasswordGenerator::m_stat_unRandomPasswordLength = 0;

const unsigned int CPasswordGenerator::m_stat_const_unPasswordMinLength = 8;
const unsigned int CPasswordGenerator::m_stat_const_unPasswordMaxLength = 24;

const unsigned int CPasswordGenerator::m_stat_const_unAlphabetsMinLength = 0;
const unsigned int CPasswordGenerator::m_stat_const_unAlphabetsMaxLength = 25;

const unsigned int CPasswordGenerator::m_stat_const_unNumbersMinLength = 0;
const unsigned int CPasswordGenerator::m_stat_const_unNumbersMaxLength = 9;

const unsigned int CPasswordGenerator::m_stat_const_unCapCharsMinCount = 1;
const unsigned int CPasswordGenerator::m_stat_const_unNumberMinCount = 1;

unsigned int CPasswordGenerator::m_stat_unCapCharsCount = 0;
unsigned int CPasswordGenerator::m_stat_unNumberscount = 0;

unsigned int CPasswordGenerator::unDiff = 0;

const char *CPasswordGenerator::m_stat_const_pcAlphabets = "abcdefghijklmnopqrstuvwxyz";
const char CPasswordGenerator::m_stat_const_cszNumbers[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

std::string	CPasswordGenerator::m_stat_strRandomPassword = "NewUser123";

CPasswordGenerator::CPasswordGenerator()
{
	srand((unsigned int)time(NULL));
}

CPasswordGenerator::~CPasswordGenerator()
{
}

/******************************************************************************
	FUNCTION NAME			:		GetRandomNumber
	PERPOSE OF FUNCTION		:		To get random number used to generate random password.
	AUTHOR					:		Dilip Sharma
	INPUT PARAMS			:		const unsigned int &, const unsigned int &
	RETURNS					:		unsigned int
	FUNCTIONS CALLED		:		none.
							
	History					:

	  Date          Name            Description of Change
  10-01-2013	Dilip Sharma		Initial Creation.
*******************************************************************************/
unsigned int CPasswordGenerator::GetRandomNumber(const unsigned int &const_r_unMinLimit, const unsigned int const_r_unMaxLimit)
{
	unsigned int unRandomNumber = 0;

	unRandomNumber = rand() % (const_r_unMaxLimit - const_r_unMinLimit + 1) + const_r_unMinLimit;
	return (unRandomNumber);
}

/******************************************************************************
	FUNCTION NAME			:		GenerateRandomPassword
	PERPOSE OF FUNCTION		:		Generates random password.
	AUTHOR					:		Dilip Sharma
	INPUT PARAMS			:		none.
	RETURNS					:		std::string
	FUNCTIONS CALLED		:		ProcessRandomPassword.
							
	History					:

	  Date          Name            Description of Change
  10-01-2013	Dilip Sharma		Initial Creation.
*******************************************************************************/
std::string CPasswordGenerator::GenerateRandomPassword()
{
	ProcessRandomPassword();

	return (m_stat_strRandomPassword);
}

/******************************************************************************
	FUNCTION NAME			:		ProcessRandomPassword
	PERPOSE OF FUNCTION		:		Process random password generation.
	AUTHOR					:		Dilip Sharma
	INPUT PARAMS			:		none.
	RETURNS					:		void
	FUNCTIONS CALLED		:		GetRandomNumber, FillPasswordWithRandomChars,
									FillPasswordWithCapitalChars, FillPasswordWithNumbers
							
	History					:

	  Date          Name            Description of Change
  10-01-2013	Dilip Sharma		Initial Creation.
  17-01-2013	Dilip Sharma		Changes done for password min length, TC 
									preference is used to decide min no of chars in password.
  17-01-2013	Dilip Sharma		changes done for capital letter, TC preference
									decides the use of capital letter in password.
*******************************************************************************/
void CPasswordGenerator::ProcessRandomPassword()
{
	bool bCapLetterReqd = false;

	bCapLetterReqd = true;

	const unsigned int const_unPasswordMinLength = 8;
	const unsigned int const_unPasswordMinDigit = 1;

	unsigned int unPasswordLength = const_unPasswordMinLength;

	m_stat_strRandomPassword.clear();
	
	m_stat_unRandomPasswordLength = GetRandomNumber(unPasswordLength, m_stat_const_unPasswordMaxLength);

	if (m_stat_unRandomPasswordLength == 0)
	{
		m_stat_unRandomPasswordLength = unPasswordLength;
	}

	if (m_stat_unRandomPasswordLength < m_stat_const_unNumbersMaxLength)
	{
		m_stat_unRandomPasswordLength = m_stat_const_unNumbersMaxLength;
	}

	FillPasswordWithRandomChars(m_stat_unRandomPasswordLength);

	FillPasswordWithNumbers();

	if (bCapLetterReqd == true)
	{
		FillPasswordWithCapitalChars();
	}
}

/******************************************************************************
	FUNCTION NAME			:		FillPasswordWithRandomChars
	PERPOSE OF FUNCTION		:		Fills password with random small characters.
	AUTHOR					:		Dilip Sharma
	INPUT PARAMS			:		const unsigned int &
	RETURNS					:		void
	FUNCTIONS CALLED		:		GetRandomNumber
							
	History					:

	  Date          Name            Description of Change
  10-01-2013	Dilip Sharma		Initial Creation.
*******************************************************************************/
void CPasswordGenerator::FillPasswordWithRandomChars(const unsigned int &const_r_unPasswordLength)
{
	unsigned int unRandomAlphabetIndex = 0;
	
	for (unsigned int unIterator = 0; unIterator < const_r_unPasswordLength; unIterator++)
	{
	   unRandomAlphabetIndex = GetRandomNumber(m_stat_const_unAlphabetsMinLength, m_stat_const_unAlphabetsMaxLength);
	   m_stat_strRandomPassword.push_back(m_stat_const_pcAlphabets[unRandomAlphabetIndex]);
	}
}

/******************************************************************************
	FUNCTION NAME			:		FillPasswordWithNumbers
	PERPOSE OF FUNCTION		:		Fills password with numbers
	AUTHOR					:		Dilip Sharma
	INPUT PARAMS			:		none.
	RETURNS					:		void
	FUNCTIONS CALLED		:		GetRandomNumber
							
	History					:

	  Date          Name            Description of Change
  10-01-2013	Dilip Sharma		Initial Creation.
  17-01-2013	Dilip Sharma		No of Min digits for password were taken from
									TC preference.
*******************************************************************************/
void CPasswordGenerator::FillPasswordWithNumbers()
{
	const unsigned int const_unPasswordMinLength = 8;
	const unsigned int const_unPasswordMinDigit = 5;

	unDiff = const_unPasswordMinLength - const_unPasswordMinDigit;

	m_stat_unNumberscount = GetRandomNumber(const_unPasswordMinDigit, m_stat_unRandomPasswordLength - unDiff - 1);

	unsigned int unRandomNumbersIndex = 0;
	unsigned int unRandomPasswordIndex = 0;

	m_stat_v_unPasswordRandomNumberIndex.clear();

	for (unsigned int unIterator = 0; unIterator < m_stat_unNumberscount; unIterator++)
	{
		unRandomNumbersIndex = GetRandomNumber(m_stat_const_unNumbersMinLength, m_stat_const_unNumbersMaxLength);

		unRandomPasswordIndex = GetRandomNumber(0, m_stat_unRandomPasswordLength - unDiff - 1);
		
		while(GetUniqueRandomNumberIndex(unRandomPasswordIndex))
		{
			unRandomPasswordIndex = GetRandomNumber(0, m_stat_unRandomPasswordLength - unDiff - 1);
		}

		m_stat_v_unPasswordRandomNumberIndex.push_back(unRandomPasswordIndex);

		try
		{
			m_stat_strRandomPassword.at(unRandomPasswordIndex) = m_stat_const_cszNumbers[unRandomNumbersIndex];	
		}
		catch(const std::out_of_range &r_const_OutOfRange)
		{
		}
	}
}

bool CPasswordGenerator::GetUniqueRandomNumberIndex(unsigned int unNumber)
{
	bool bFound = false;

	std::vector<unsigned int>::iterator it = m_stat_v_unPasswordRandomNumberIndex.begin();

	for (it; it != m_stat_v_unPasswordRandomNumberIndex.end(); it++)
	{
		if (unNumber == *it)
		{
			bFound = true;
			break;
		}
	}

	return bFound;
}

void CPasswordGenerator::FillPasswordWithCapitalChars()
{
	unsigned int unRandomPasswordIndex = 0;

	unRandomPasswordIndex = GetRandomNumber(0, m_stat_unRandomPasswordLength - unDiff);

	while(GetUniqueRandomNumberIndex(unRandomPasswordIndex))
	{
		unRandomPasswordIndex = GetRandomNumber(0, m_stat_unRandomPasswordLength - unDiff);
	}	

	try
	{
		m_stat_strRandomPassword.at(unRandomPasswordIndex) = 
			toupper(m_stat_strRandomPassword.at(unRandomPasswordIndex));
	}
	catch(const std::out_of_range &r_const_OutOfRange)
	{
	}
}

void main()
{
	std::string password;
	for (int i = 0; i < 200; i++)
	{
		password = CPasswordGenerator::GenerateRandomPassword();
		std::cout<<"Password "<<i + 1 <<" "<<password<<std::endl;
	}
	getch();
}