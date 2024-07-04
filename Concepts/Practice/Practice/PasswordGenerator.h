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
			/*
			* Default Ctor
			*/
			CPasswordGenerator();

			/*
			* Default Dtor
			*/
			~CPasswordGenerator();

			/*
			*  To Get Decrypted Password
			*/
			static std::string GetDecryptedPassword(std::string &r_strEncryptedPassword);
			
			/*
			*  To filter password
			*/
			static void FilterPassword(std::string &r_strEncryptedPassword);

			/*
			*  To split password
			*/
			static void SplitIndexTokens(std::string &r_strPasswordIndex);

			/*
			*  To Decrypt password
			*/
			static void DecryptPassword();	

			/*
			*  To Get Random Number
			*/
			static unsigned int GetRandomNumber(const unsigned int &const_r_unMinLimit, const unsigned int const_r_unMaxLimit);

			/*
			*  To gernarate random password
			*/
			static std::string GenerateRandomPassword();

			/*
			*  Process random password generation
			*/
			static void ProcessRandomPassword();

			/*
			*  Fill password with random characters
			*/
			static void FillPasswordWithRandomChars(const unsigned int &const_r_unPasswordLength);

			/*
			*  Fill password with random capital characters
			*/
			static void FillPasswordWithCapitalChars();

			/*
			*  Fill password with random numbers
			*/
			static void FillPasswordWithNumbers();

			/*
			*  To generate Random number for chapital char
			*/
			static unsigned int CapitalCharRandomNumber();

			static bool GetUniqueRandomNumberIndex(unsigned int unNumber);

		protected:
		
			/*
			*  To hold password tokens
			*/
			static std::vector<std::string> m_stat_v_strPasswordTokens;

			/*
			*  Fixed char keys to decrypt password
			*/
			static const unsigned int m_stat_const_unPasswordKeys[24];

			/*
			*  To hold decrypt password
			*/
			static std::string m_stat_strDecryptPassword;

			/*
			*  To hold decrypt password index
			*/
			static std::string m_stat_strPasswordIndex;

			/*
			*  Random Password Minimum Length
			*/
			static const unsigned int m_stat_const_unPasswordMinLength;

			/*
			*  Random Password Max Length
			*/
			static const unsigned int m_stat_const_unPasswordMaxLength;

			/*
			*  To hold current Random Password Length
			*/
			static unsigned int m_stat_unRandomPasswordLength;

			/*
			*  Random characters min length
			*/
			static const unsigned int m_stat_const_unAlphabetsMinLength;
			/*
			*  Random characters max length
			*/
			static const unsigned int m_stat_const_unAlphabetsMaxLength;

			/*
			*  Random numbers min length
			*/
			static const unsigned int m_stat_const_unNumbersMinLength;
			/*
			*  Random characters max length
			*/
			static const unsigned int m_stat_const_unNumbersMaxLength;

			/*
			*  Random capital characters min count
			*/

			static const unsigned int m_stat_const_unCapCharsMinCount; 
			/*
			*  Random numbers min count
			*/
			static const unsigned int m_stat_const_unNumberMinCount;
			
			/*
			*  Random capital characters count
			*/
			static unsigned int m_stat_unCapCharsCount;

			/*
			*  Random numbers count
			*/
			static unsigned int m_stat_unNumberscount;

			/*
			*  Array of Numbers to generate random numbers
			*/
			static const char m_stat_const_cszNumbers[10];

			/*
			*  Alphabets to generate random characters
			*/
			static const char *m_stat_const_pcAlphabets; 
			
			/*
			*  To hold random password
			*/
			static std::string m_stat_strRandomPassword;

			/*
			*  To hold indexs of randomly generated number
			*/
			static std::vector<unsigned int> m_stat_v_unPasswordRandomNumberIndex;

			static unsigned int unDiff;
	};
};
#endif __PASS_DCRP_H_