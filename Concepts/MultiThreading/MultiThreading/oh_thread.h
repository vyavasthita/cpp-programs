#include <iostream>

namespace openutils 
{
	class ThreadException;
	class Mutex;

	/** class Thread
	  * Represents a thread of execution
	  * in the process. To create a new Thread
	  * write an inherited class ot Thread and
	  * override the run() function
	**/
	class Thread 
	{
		private:
			// unsigned long* to the low-level thread object
			unsigned long* m_hThread;

			// a name to identify the thread
			std::string m_strName;

		public:
			Thread();
			Thread(const char* nm);
			virtual ~Thread();
			void setName(const char* nm);
			std::string getName() const;
			void start();
			virtual void run();
			void sleep(long ms);
			void suspend();
			void resume();
			void stop();

			void setPriority(int p);

			bool wait(const char* m, long ms = 5000);
			void release(const char* m);

		public:
			// Thread priorities
			static const int P_ABOVE_NORMAL;
			static const int P_BELOW_NORMAL;
			static const int P_HIGHEST;
			static const int P_IDLE;
			static const int P_LOWEST;
			static const int P_NORMAL;
			static const int P_CRITICAL;
						
	};// class Thread	

	/** class Mutex
	  * Represents a Mutex object to synchronize
	  * access to shaed resources.
	**/
	class Mutex 
	{
		private:
			// unsigned long* to the low-level mutex object
			unsigned long* m_hMutex;

			// name to identify the mutex
			std::string m_strName;

		public:
			Mutex();
			Mutex(const char* nm);

			void create(const char* nm);
			unsigned long* getMutexHandle();
			std::string getName();
			void release();
			~Mutex();
	};

	/** class ThreadException
	  * thrown by Thread and Mutex function 
	  * calls
	**/
	class ThreadException 
	{
		private:
			std::string msg;
		public:
			ThreadException(const char* m);
			std::string getMessage() const;
	};	
} // namespace openutils

// global function called by the thread object.
// this in turn calls the overridden run()
extern "C" 
{
	unsigned int _ou_thread_proc(void* param);
}


				
