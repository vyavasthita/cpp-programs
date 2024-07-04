#pragma once

class ReferenceCount
{
	public:
		ReferenceCount();
		~ReferenceCount();

		void setReferenceCount(int count);
		int getReferenceCount();
		void incrementRefCount();
		void decrementRefCount();

	private:
		int m_nRefCount;
};

