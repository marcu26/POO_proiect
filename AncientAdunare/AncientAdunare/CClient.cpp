#include "CClient.h"
#include "CShop.h"

void CClient::buy(const int& cerere)
{
	CShop& shop = CShop::getInstance();
	shop.showAutorizatii();
	shop.showMuncitori();

	if (cerere == 1)
	{
		if (resurse.getGalbeni() >= 100)
		{
			resurse.addAutorizatie("AutorizatieScoalaMilitara");
			resurse.subGalbeni(100);
		}
		else
			std::cout << "Nu aveti destui galbeni\n";
	}
	else if (cerere == 2)
	{
		if (resurse.getGalbeni() >= 100)
		{
			resurse.addAutorizatie("AutorizatieScoalaMedici");
			resurse.subGalbeni(100);
		}
		else
			std::cout << "Nu aveti destui galbeni\n";
	}
	else if (cerere == 3)
	{
		if (resurse.getGalbeni() >= 20)
		{
			resurse.subGalbeni(20);
			resurse.addMuncitor();
		}
		else
			std::cout << "Nu aveti destui galbeni\n";
	}
}
