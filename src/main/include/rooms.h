#include <stdio.h>
#include <vector>

namespace CasGD {
	class RoomItem {
		private:
			int gameObjectId;

			Point location = {0, 0};
			float direction = 0;
			float speed = 0;

			int dataCount = 0;
			long* dataList = 0;

			long id = 0;

		public:
			RoomItem(long id);
			RoomItem(long id, int x, int y);
			PoomItem(long id, Point location);

			//Data:
			void initData(int count);
			int getDataCount();

			template <typename type>
			type* getDataPointer(int id);

			template <typename type>
			void setDataPointer(int id, type* data);

			long getData(int id);
			void setData(int id, long data);

			//Params:
			Point getLocation();
			void  setLocation(Point location);
			void  setLocation(int x, int y);
			int getX();
			int setX(int x);
			int getY();
			int setY(int y);
			float getDirection();
			void  setDirection(float direction);
			float getSpeed();
			void  setSpeed(float speed);
	};

	class ViewRoom {
		private:
			bool isIDType = true;
			Rectangle bounce;
			int idTarget;

			float* padding = new float[4]{32, 32, 32, 32}; //px
		public:
			ViewRoom(Rectangle bounce, int idTarget);
			ViewRoom(Rectangle bounce, int idTarget, bool isIDType);
			ViewRoom(Point location, Resolution size, float h, int idTarget);
			ViewRoom(Point location, Resolution size, float h, int idTarget, bool isIDType);
			ViewRoom(float x, float y, float w, float h, int idTarget);
			ViewRoom(float x, float y, float w, float h, int idTarget, bool isIDType);

			Point getLocation();
			Resolution getSize();
			Rectangle getBounce();

			void setLocation(Point location);
			void setLocation(float x, float y);
			void setSize(Resolution size);
			void setSize(float w, float h);
			void setBounce(Rectangle bounce);
			void setBounce(float x, float y, float w, float h);

			int  getTargetID();
			void setTargetID(int idTarget);

			bool isGameObjectTarget();
	};

	class Room {
		private:
			Resolution size;
			std::vector<RoomItem> items;
			std::vector<ViewRoom> views;

		public:
			

	};
}