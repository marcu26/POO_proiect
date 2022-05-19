#pragma once
#include "ICaracter.h"
class ACaracter: public ICaracter
{
protected:

    int number=0;

public:

	ACaracter() {};
	ACaracter(int number):ICaracter() {this->number = number; };
	void modifyNumber(int number) override { this->number += number; };

	int getNumber() override { return number; };
    ACaracter &operator=(int number)
    {
        this->number=number;
        return *this;
    }

};

