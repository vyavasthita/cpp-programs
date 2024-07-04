#pragma once

class CData
{
	public:
		CData(void);
		virtual ~CData(void);

		void printData(const char* pcThreadName);

	protected:
		static int value1;
		static int value2;
};

