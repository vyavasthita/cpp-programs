#include <iostream>
#include "mytime.hh"

class MyTimeImpl : public virtual POA_MyTime
{
	public:
		virtual TimeOfDay getTime() throw(CORBA::SystemException);
};

