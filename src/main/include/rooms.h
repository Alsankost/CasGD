#include <stdio.h>
#include <vector>

namespace CasGD {
	class RoomItem {
		private:
			int gameObjectId;

			Point position = {0, 0};
			float direction = 0;
			float speed = 0;

			std::std::vector<void*> data;

			long id = 0;

		public:
			RoomItem(long id);
			RoomItem(long id, int x, int y);
			PoomItem(long id, Point position);

			//Data:
			int getDataCount();

			template <typename type>
			type* getDataPointer(int id);

			template <typename type>
			void setDataPointer(int id, type* data);

			template <typename type>
			void addDataPointer(type* data);

			long getData(int id);
			void setData(int id, void* data);
			void addData(void* data);

			//Params:
			Point getPosition();
			void  setPosition(Point position);
			void  setPosition(int x, int y);
			int getX();
			int setX(int x);
			int getY();
			int setY(int y);
			float getDirection();
			void  setDirection(float direction);
			float getSpeed();
			void  setSpeed(float speed);
	};

	enum BorderSide {
		BORDER_RIGTH,
		BORDER_TOP,
		BORDER_LEFT,
		BORDER_BOTTOM
	}

	class ViewRoom {
		private:
			bool isIDType = true;
			Rectangle bounce;
			long idTarget;

			float* padding = new float[4]{32, 32, 32, 32}; //px
		public:
			ViewRoom(Rectangle bounce, long idTarget);
			ViewRoom(Rectangle bounce, long idTarget, bool isIDType);
			ViewRoom(Point position, Resolution size, long idTarget);
			ViewRoom(Point position, Resolution size, long idTarget, bool isIDType);
			ViewRoom(float x, float y, float w, float h, long idTarget);
			ViewRoom(float x, float y, float w, float h, long idTarget, bool isIDType);

			Point getposition();
			Resolution getSize();
			Rectangle getBounce();
			float getBorder(BorderSide side);

			void setPosition(Point position);
			void setPosition(float x, float y);
			void setSize(Resolution size);
			void setSize(float w, float h);
			void setBounce(Rectangle bounce);
			void setBounce(float x, float y, float w, float h);
			void setBorder(BorderSide side, float width);

			long getTargetID();
			void setTargetID(long idTarget);

			bool isGameObjectTarget();
	};

	class Room {
		private:
			Resolution size;
			Resolution viewPort = {640, 480};
			float dalay = 100; //ms
			std::vector<RoomItem*> items;
			std::vector<ViewRoom*> views;
			ViewRoom* currentView;

		public:
			Room(Resolution size);
			Room(float w, float h);

			Resolution getSize();
			Resolution getViewPoint();

			void setSize(Resolution size);
			void setSize(float w, float h);
			void setViewPort(Resolution size);
			void setViewPort(float w, float h);

			int getItemsCount();
			int getViewsCount();
			RoomItem* getItemFromIndex(int i);
			RoomItem* getItemFromID(long id);
			ViewRoom* getView(int index);

			void createItem(Register register, float x, float y, int id);
			void createItem(Register register, float x, float y, std::string name);	

			ViewRoom* createViewFormObjectID(int objectID);
			ViewRoom* createViewFormItemID(long itemID);

			bool killItem(long itemID);
			bool killItems(int objectID);
	};
}