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
 // FILE NAME           :		PasswordDecryption.h
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

#ifndef __PASS_DCRP_H_
#define __PASS_DCRP_H_

#include <iostream>
#include <vector>

namespace GIDInterface
{
	class CPasswordDecryption
	{
		public:
			CPasswordDecryption(){};
			~CPasswordDecryption(){};

			static std::string GetDecryptedPassword(std::string &r_strEncryptedPassword);
			static std::string FilterPassword(std::string &r_strEncryptedPassword);

			static int StringToInt(std::string strValue);
			static std::string CharToString(char cChar);
			static std::string ConvertToString();

			static int GetPasswordLength();
			static void SplitPasswordTokens(std::string &r_strEncryptedPassword);

			static void SplitPassword();

			static void DecryptPassword();

			

		private:
		
			static std::vector<std::string> m_stat_v_strPasswordTokens;

			static const unsigned int m_stat_const_unLengthIndex;
			static unsigned int m_stat_unPasswordLength;

			static const int m_stat_const_nPasswordKeys[24];

			static std::string m_stat_strPasswordLength;
			static std::string decPass;
	};
};
#endif __PASS_DCRP_H_