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
	class CPasswordGenerator
	{
		public:
			CPasswordGenerator();
			~CPasswordGenerator();

			//Password Decryption
			static std::string GetDecryptedPassword(std::string &r_strEncryptedPassword);
			
			static void FilterPassword(std::string &r_strEncryptedPassword);

			static void SplitIndexTokens(std::string &r_strPasswordIndex);

			static void DecryptPassword();	

			//Random Password
			static unsigned int GetRandomNumber(const unsigned int &const_r_unMinLimit, const unsigned int const_r_unMaxLimit);
			static std::string GenerateRandomPassword();
			static void ProcessRandomPassword();
			static void FillPasswordWithRandomChars(const unsigned int &const_r_unPasswordLength);
			static void FillPasswordWithCapitalChars();
			static void FillPasswordWithNumbers();

		protected:
		
			//Password Decryption
			static std::vector<std::string> m_stat_v_strPasswordTokens;

			static const unsigned int m_stat_const_unPasswordKeys[24];

			static std::string m_stat_strDecryptPassword;
			static std::string m_stat_strPasswordIndex;

			//Random Password
			static  unsigned int m_stat_const_unPasswordMinLength;
			static  unsigned int m_stat_const_unPasswordMaxLength;
			static unsigned int m_stat_unRandomPasswordLength;

			static  unsigned int m_stat_const_unAlphabetsMinLength;
			static  unsigned int m_stat_const_unAlphabetsMaxLength;

			static  unsigned int m_stat_const_unNumbersMinLength;
			static  unsigned int m_stat_const_unNumbersMaxLength;

			static  unsigned int m_stat_const_unCapCharsMinCount; 
			static  unsigned int m_stat_const_unNumberMinCount;
			
			static unsigned int m_stat_unCapCharsCount;
			static unsigned int m_stat_unNumberscount;



			static const char m_stat_const_cszNumbers[10];
			static const char *m_stat_const_pcAlphabets; 
			
			static std::string m_stat_strRandomPassword;
	};
};
#endif __PASS_DCRP_H_