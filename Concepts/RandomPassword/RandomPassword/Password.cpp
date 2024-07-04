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
 //*******************************************************************************

#include "Password.h"
#include <sstream>
#include <stdexcept>
#include <conio.h>
#include <time.h>

using namespace GIDInterface;

//Password Decryption
std::string CPasswordGenerator::m_stat_strDecryptPassword = "";
std::string CPasswordGenerator::m_stat_strPasswordIndex = "";
std::vector<std::string> CPasswordGenerator::m_stat_v_strPasswordTokens;
const unsigned int CPasswordGenerator::m_stat_const_unPasswordKeys[] = { 19, 6, 24, 9, 20, 5, 30, 12, 29, 10, 27, 7, 25, 8, 28, 11, 26, 21, 13, 23, 15, 22, 14, 16 };

//Random Password
unsigned int CPasswordGenerator::m_stat_unRandomPasswordLength = 0;

 unsigned int CPasswordGenerator::m_stat_const_unPasswordMinLength = 8;
 unsigned int CPasswordGenerator::m_stat_const_unPasswordMaxLength = 24;

 unsigned int CPasswordGenerator::m_stat_const_unAlphabetsMinLength = 0;
 unsigned int CPasswordGenerator::m_stat_const_unAlphabetsMaxLength = 25;

 unsigned int CPasswordGenerator::m_stat_const_unNumbersMinLength = 0;
 unsigned int CPasswordGenerator::m_stat_const_unNumbersMaxLength = 9;

 unsigned int CPasswordGenerator::m_stat_const_unCapCharsMinCount = 1;
 unsigned int CPasswordGenerator::m_stat_const_unNumberMinCount = 1;

unsigned int CPasswordGenerator::m_stat_unCapCharsCount = 0;
unsigned int CPasswordGenerator::m_stat_unNumberscount = 0;

const char *CPasswordGenerator::m_stat_const_pcAlphabets = "abcdefghijklmnopqrstuvwxyz";
const char CPasswordGenerator::m_stat_const_cszNumbers[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

std::string	CPasswordGenerator::m_stat_strRandomPassword;

CPasswordGenerator::CPasswordGenerator()
{
	srand(time(NULL));
}

CPasswordGenerator::~CPasswordGenerator()
{
	//m_stat_strRandomPassword.clear();
}

unsigned int CPasswordGenerator::GetRandomNumber(const unsigned int &const_r_unMinLimit, const unsigned int const_r_unMaxLimit)
{
	unsigned int unRandomNumber = 0;

	unRandomNumber = rand() % (const_r_unMaxLimit - const_r_unMinLimit + 1) + const_r_unMinLimit;
	return (unRandomNumber);
}

std::string CPasswordGenerator::GenerateRandomPassword()
{
	
	m_stat_strRandomPassword.clear();
	ProcessRandomPassword();

	return (m_stat_strRandomPassword);
}

void CPasswordGenerator::ProcessRandomPassword()
{
	m_stat_unRandomPasswordLength = GetRandomNumber(m_stat_const_unPasswordMinLength, m_stat_const_unPasswordMaxLength);
	FillPasswordWithRandomChars(m_stat_unRandomPasswordLength);
	FillPasswordWithCapitalChars();
	FillPasswordWithNumbers();
}

void CPasswordGenerator::FillPasswordWithRandomChars(const unsigned int &const_r_unPasswordLength)
{
	unsigned int unRandomAlphabetIndex = 0;
	
	for(unsigned int uiIterator = 0; uiIterator < const_r_unPasswordLength; uiIterator++)
	{
	   unRandomAlphabetIndex = GetRandomNumber(m_stat_const_unAlphabetsMinLength, m_stat_const_unAlphabetsMaxLength);
	   m_stat_strRandomPassword.push_back(m_stat_const_pcAlphabets[unRandomAlphabetIndex]);
	}
}

void CPasswordGenerator::FillPasswordWithCapitalChars()
{
	m_stat_unCapCharsCount = GetRandomNumber(m_stat_const_unCapCharsMinCount, m_stat_unRandomPasswordLength - 1);
	unsigned int unRandomCapitalLetterIndex = 0;

	for(unsigned int uiIterator = 0; uiIterator < m_stat_unCapCharsCount; uiIterator++)
	{
		unRandomCapitalLetterIndex = GetRandomNumber(m_stat_const_unAlphabetsMinLength, m_stat_unRandomPasswordLength - 1);
		m_stat_strRandomPassword.at(unRandomCapitalLetterIndex) = toupper(m_stat_strRandomPassword.at(unRandomCapitalLetterIndex));
	}
}

void CPasswordGenerator::FillPasswordWithNumbers()
{
	m_stat_unNumberscount = GetRandomNumber(m_stat_const_unNumberMinCount, m_stat_unRandomPasswordLength - 1);

	while(m_stat_unNumberscount == m_stat_unCapCharsCount)
	{
		m_stat_unNumberscount = GetRandomNumber(m_stat_const_unNumberMinCount, m_stat_unRandomPasswordLength - 1);
	}

	unsigned int unRandomNumbersIndex = 0;

	for(unsigned int uiIterator = 0; uiIterator < m_stat_unNumberscount; uiIterator++)
	{
		unRandomNumbersIndex = GetRandomNumber(m_stat_const_unNumbersMinLength, m_stat_const_unNumbersMaxLength);
		m_stat_strRandomPassword.at(unRandomNumbersIndex) = m_stat_const_cszNumbers[unRandomNumbersIndex];
	}
}

void main()
{
	CPasswordGenerator ob;

	std::string pass = CPasswordGenerator::GenerateRandomPassword();
	std::string pass2 = CPasswordGenerator::GenerateRandomPassword();
	std::string pass3 = CPasswordGenerator::GenerateRandomPassword();
	std::cout<<pass<<std::endl;
	std::cout<<pass2<<std::endl;
	std::cout<<pass3<<std::endl;
	getch();
}