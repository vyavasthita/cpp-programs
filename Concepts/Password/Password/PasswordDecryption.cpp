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

#include "PasswordDecryption.h"

#include <sstream>
#include <conio.h>

using namespace GIDInterface;

const unsigned int CPasswordDecryption::m_stat_const_unLengthIndex = 2;
unsigned int CPasswordDecryption::m_stat_unPasswordLength = 0;

std::string CPasswordDecryption::m_stat_strPasswordLength = "";
std::vector<std::string> CPasswordDecryption::m_stat_v_strPasswordTokens;

std::string CPasswordDecryption::decPass = "";

const int CPasswordDecryption::m_stat_const_nPasswordKeys[] = { 19, 6, 24, 9, 20, 5, 30, 12, 29, 10, 27, 7, 25, 8, 28, 11, 26, 21, 13, 23, 15, 22, 14, 16 };


std::string CPasswordDecryption::GetDecryptedPassword(std::string &r_strEncryptedPassword)
{
	std::string strFilterPassword = "";

	strFilterPassword = FilterPassword(r_strEncryptedPassword);
	SplitPasswordTokens(strFilterPassword);
	SplitPassword();
	DecryptPassword();

	return (decPass);
}

std::string CPasswordDecryption::FilterPassword(std::string &r_strEncryptedPassword)
{
	std::string filterPassword = "";

	for(unsigned int uiIterator = 0; uiIterator < r_strEncryptedPassword.size(); ++uiIterator)
	{
		if(uiIterator + m_stat_const_unLengthIndex < r_strEncryptedPassword.size())
		{
			filterPassword.push_back(r_strEncryptedPassword.at(uiIterator));
		}
		else
		{
			m_stat_strPasswordLength.push_back(r_strEncryptedPassword.at(uiIterator));
		}
	}
	return (filterPassword);
}

int CPasswordDecryption::StringToInt(std::string strValue)
{
	int nValue = 0;

	std::istringstream ss(strValue);
	ss>>nValue;

	return (nValue);
}

int CPasswordDecryption::GetPasswordLength()
{		   
	int nLength = StringToInt(m_stat_strPasswordLength);
	return (nLength);
}

void main()
{
	std::string str = "|t~xxgC6,07";

	CPasswordDecryption ob;
	std::string s = ob.GetDecryptedPassword(str);

	const int nPasswordKeys[] = { 19, 6, 24, 9, 20, 5, 30, 12, 29, 10, 27, 7, 25, 8, 28, 11, 26, 21, 13, 23, 15, 22, 14, 16 };
	std::string length = str.substr(str.size() - 2, str.size());
	int len = ob.StringToInt(length);

	str.erase(str.size() - 2, str.size());

	std::string pass = str.substr(0, len);

	std::string index = str.substr(len, str.size());

	std::string tempValue;
	std::istringstream sstrStream(index);
	std::vector<std::string> vec;
	
	while(!sstrStream.eof())
	{
		getline(sstrStream, tempValue, ',');	

		if(tempValue.empty() == false)
		{
			vec.push_back(tempValue);
		}
	}

	for(int uiIterator = 0; uiIterator < pass.size(); ++uiIterator)
	{
		bool found = false;

		for(unsigned int i = 0; i < vec.size(); i++)
		{ 
			if(uiIterator == ob.StringToInt(vec.at(i)))
			{
				found = true;
				break;
			}			
		}

		if(found)
		{
			pass.at(uiIterator) = pass.at(uiIterator) + nPasswordKeys[uiIterator];
		}
		else
		{
			pass.at(uiIterator) = pass.at(uiIterator) - nPasswordKeys[uiIterator];
		}
	}

	std::cout<<pass<<std::endl;

	getch();
}