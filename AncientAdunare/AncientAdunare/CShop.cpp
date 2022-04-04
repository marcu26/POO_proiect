#include "CShop.h"

CShop* CShop::instance = nullptr;
CShop::CShop()
{
	autorizatii.push_back("AutorizatieScoalaMilitara");
	autorizatii.push_back("AutorizatieScoalaMedici");

	muncitori = "Muncitori";
}

CShop& CShop::getInstance()
{
	if (instance == nullptr)
	{
		instance = new CShop();
	}
	return *instance;
}

void CShop::destroy()
{
	if (instance != nullptr)
		delete instance;
	instance = nullptr;
}

void CShop::showAutorizatii()
{
	for (auto& it : autorizatii)
		std::cout << it << " -- 100 galbeni\n";
	std::cout << "\n";
}

void CShop::showMuncitori()
{
	std::cout << muncitori << " -- 20 galbeni\n";
}
