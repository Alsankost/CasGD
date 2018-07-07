#include <stdio.h>
#include <vector>

namespace CasGD {
	class RoomItem {
		private:
			bool flagNew = true;
			
			int gameObjectID;

			Point position = {0, 0};
			float direction = 0;
			float speed = 0;

			std::std::vector<void*> data;

			long id = 0;

		public:
			RoomItem(int gameObjectID, long id);
			RoomItem(int gameObjectID, long id, int x, int y);
			PoomItem(int gameObjectID, long id, Point position);

			int getGameObjectID();

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

			long getID();

			void disableNew();
			bool isNew();
	};

	enum BorderSide {
		BORDER_RIGTH,
		BORDER_TOP,
		BORDER_LEFT,
		BORDER_BOTTOM
	}

	class RoomView {
		private:
			bool isIDType = true;
			Point position = {0, 0};
			Resolution roomPort;
			Resolution winPort;
			long idTarget;

			float* padding = new float[4]{32, 32, 32, 32}; //px
		public:
			RoomView(Resolution screenPort, long idTarget);
			RoomView(Resolution screenPort, long idTarget, bool isIDType);
			RoomView(float w, float h, long idTarget);
			RoomView(float w, float h, long idTarget, bool isIDType);

			Point getPosition();
			Resolution getRoomPort();
			Resolution getScreenPort();
			float getBorder(BorderSide side);

			void setPosition(Point position);
			void setPosition(float x, float y);
			void setRoomPort(Resolution size);
			void setRoomPort(float w, float h);
			void setScreenPort(Resolution size);
			void setScreenPort(float w, float h);
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
			//std::vector<RoomView*> views;
			RoomView* currentView;

		public:
			Room(Resolution size);
			Room(float w, float h);

			Resolution getSize();
			//Resolution getViewPoint();

			void setSize(Resolution size);
			void setSize(float w, float h);

			void setView(RoomView* view);
			//void setViewPort(Resolution size);
			//void setViewPort(float w, float h);

			//void setCurrentView(int id);
			//void setCurrentView(RoomView* view);

			int getItemsCount();
			//int getViewsCount();
			RoomItem* getItemFromIndex(int i);
			RoomItem* getItemFromID(long id);

			RoomView* getView();
			//RoomView* getCurrentView();

			RoomItem* createItem(Register* reg, float x, float y, int idObject);
			RoomItem* createItem(Register* reg, float x, float y, std::string name);	

			RoomView* createViewFormObjectID(int objectID);
			RoomView* createViewFormItemID(long itemID);
			RoomView* createView();

			bool killItem(long itemID);
			bool killItems(int objectID);

			void observe(Game* game);
	};
}