#ifndef __STR_EXCP_H_
#define __STR_EXCP_H_

namespace MyCustomString
{
	class StringException
	{
		public:
			enum eException
			{
			/*0*/STRING_SUBSRICT_OUT_OF_RANGE = 1,
			/*1*/SUBSTRING_SUBSRICT_OUT_OF_RANGE
			};

			struct stException
			{
				enum eException eExcep;
				const char* cpErrorDesc;
			};

			static const char* getErrorMessage(enum eException eExcep)
			{
				stException arrExcpTbl[] = 
				{
					{STRING_SUBSRICT_OUT_OF_RANGE, "String Subcription Out of Range"},
					{SUBSTRING_SUBSRICT_OUT_OF_RANGE, "Sub String Subcription Out of Range"}
				};
				return (arrExcpTbl[eExcep].cpErrorDesc);
			}
	};
};
#endif __STR_EXCP_H_