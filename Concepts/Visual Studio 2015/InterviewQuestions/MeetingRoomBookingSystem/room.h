#ifndef __ROOM_H__
#define __ROOM_H__


namespace RoomBookingSystem
{
	class Room
	{
		public:
			virtual const char* getRoomName() = 0;
			virtual void bookRoom(int time) = 0;
	};

	class Ganga : public Room
	{
		public:
			virtual const char* getRoomName();
			virtual void bookRoom(int time);

		private:
			bool m_bAvailable;
	};

	class Cauvery : public Room
	{
		public:
			virtual const char* getRoomName();
			virtual void bookRoom(int time);

		private:
			bool m_bAvailable;
	};
};

#endif __ROOM_H__



