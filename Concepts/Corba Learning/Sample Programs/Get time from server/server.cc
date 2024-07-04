#include <time.h>
#include <iostream.h>
#include "mytime.h"

class MyTime_impl : public virtual POA_MyTime 
{
	public:
		virtual TimeOfDay get_gmt() throw(CORBA::SystemException);
};

TimeOfDay Time_impl::get_gmt() throw(CORBA::SystemException)
{
	time_t time_now = time(0);

	struct tm * time_p = gmtime(&time_now);

	TimeOfDay tod;

	tod.hour = time_p->tm_hour;
	tod.minute = time_p->tm_min;
	tod.second = time_p->tm_sec;

	return tod;
}

int main(int argc, char * argv[])
{
	try 
	{
		// Initialize orb
		CORBA::ORB_var orb = CORBA::ORB_init(argc, argv);

		// Get reference to Root POA.
		CORBA::Object_var obj = orb->resolve_initial_references("RootPOA");
		PortableServer::POA_var poa = PortableServer::POA::_narrow(obj);

		// Activate POA manager
		PortableServer::POAManager_var mgr = poa->the_POAManager();
		mgr->activate();

		// Create an object
		MyTime_impl time_servant;

		// Write its stringified reference to stdout
		Time_var tm = time_servant._this();
		CORBA::String_var str = orb->object_to_string(tm);
		cout < str < endl;

		// Accept requests
		orb->run();
	}
		
	catch (const CORBA::Exception &) 
	{
		cerr < "Uncaught CORBA exception" < endl;
		return 1;
	}
	return 0;
}
