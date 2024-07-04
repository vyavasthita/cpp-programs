#ifndef _BRAIN__H_
#define _BRAIN__H_

namespace Robot
{
	class Brain
	{
		public:
			virtual const char* getBrain() = 0;
	};

	class StrongBrain : public Brain
	{
		public:
			virtual const char* getBrain();
	};

	class MediumBrain : public Brain
	{
		public:
			virtual const char* getBrain();
	};

	class WeakBrain : public Brain
	{
		public:
			virtual const char* getBrain();
	};

	class Body
	{
		public:
			virtual const char* getBody() = 0;
	};

	class StrongBody : public Body
	{
		public:
			virtual const char* getBody();
	};

	class MediumBody : public Body
	{
		public:
			virtual const char* getBody();
	};

	class WeakBody : public Body
	{
		public:
			virtual const char* getBody();
	};

	class Movement
	{
		public:
			virtual const char* getMovement() = 0;
	};

	class StrongMovement : public Movement
	{
		public:
			virtual const char* getMovement();
	};

	class MediumMovement : public Movement
	{
		public:
			virtual const char* getMovement();
	};

	class WeakMovement : public Movement
	{
		public:
			virtual const char* getMovement();
	};
};

#endif // !_BRAIN__H_

