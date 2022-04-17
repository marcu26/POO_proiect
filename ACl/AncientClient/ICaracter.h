#pragma once
class ICaracter
{
public:
	virtual void doAction(ICaracter *caracter) = 0;
	virtual void modifyNumber(int number) = 0;
	virtual int getNumber() = 0;
};

