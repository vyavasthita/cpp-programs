#pragma once

using namespace std;


class IceCream
{
	public:
		virtual const char* getIcream() = 0;
};

class ChoclateIceCream : public IceCream
{
	public:
		virtual const char* getIcream();
};


class VanillaIceCream : public IceCream
{
	public:
		virtual const char* getIcream();
};

