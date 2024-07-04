#include "JuiceOrder.h"
#include "JuiceFactory.h"
#include <iostream>

void CJuiceOrder::WelcomeToJuiceCenter()
{
	short int nUserChoice = 0;
	bool bChoice = true;

	printf("Welcome to DK Juice Center\n\n");
	
	while(bChoice)
	{
		printf("Please Select you choice\n");
	
		std::cout << "1. Mango" << std::endl;
		std::cout << "2. Orange" << std::endl;
		std::cout << "3. Apple" << std::endl;
		std::cout << "4. Exit" << std::endl;

		std::cin >> nUserChoice;

		switch(nUserChoice)
		{
			case 1 :
				ProcessOrder(nUserChoice);
				break;
			case 2 :
				ProcessOrder(nUserChoice);
				break;
			case 3 :
				ProcessOrder(nUserChoice);
				bChoice = false;
				break;
			case 4 :
				bChoice = false;
				break;
			default :
				std::cout << "Wrong Choice" << std::endl;
				break;
		}
	}
}

void CJuiceOrder::ProcessOrder(short int nJuiceChoice)
{
	pCJuiceFactory = oCCreateJuiceObject.GetJuiceObject(nJuiceChoice);

	PrepareJuice(pCJuiceFactory);
}

void CJuiceOrder::PrepareJuice(CJuiceFactory* poCJuiceFactory)
{
	std::string strJuice = "";

	strJuice = poCJuiceFactory->MakeJuice();

	std::cout << strJuice.c_str() << std::endl << std::endl;
}