#pragma once

class Dealer
{
	public:
		virtual void update(int basePrice) = 0;

	protected:
		int m_nPrice;
		int m_nProfit;
};

class RamComputers : public Dealer
{
	public:
		RamComputers();
		virtual void update(int basePrice);
};

class RahimComputers : public Dealer
{
	public:
		RahimComputers();
		virtual void update(int basePrice);
};
