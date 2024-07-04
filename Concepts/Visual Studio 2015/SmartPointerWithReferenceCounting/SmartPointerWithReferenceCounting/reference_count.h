#pragma once
class ReferenceCount
{
	public:
		ReferenceCount();

		void incrementCount();
		void decrementCount();

		int getCount();

	private:
		int count;
};