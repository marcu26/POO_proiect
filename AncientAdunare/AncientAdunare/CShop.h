#pragma once
#include <iostream>
#include <string>
#include <vector>

class CShop
{
private:
	CShop();
	~CShop() {}

	static CShop* instance;

	CShop(const CShop& obj) = delete;
	CShop(CShop&& obj) = delete;

private:

	std::vector<std::string> autorizatii;
	std::string muncitori;

public:
	static CShop& getInstance();
	void destroy();

	void showAutorizatii();
	void showMuncitori();

};

