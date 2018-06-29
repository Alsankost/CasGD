#include "include/rooms.h"

namespace CasGD {
	//==RoomItem
	RoomItem::RoomItem(long id) {
		this->id = id;
	}

	RoomItem::RoomItem(long id, int x, int y) {
		this->id = id;
		this->location = {x, y};
	}

	RoomItem::PoomItem(long id, Point location) {
		this->id = id;
		this->location = location;
	}

	//Data:
	int RoomItem::getDataCount() {
		return this->data.size();
	}

	template <typename type> type*
	RoomItem::getDataPointer(int id) {
		if (id < 0 && id > this->data.size() - 1) return 0;
		return static_cast<type*>(this->data[id]);
	}

	template <typename type>
	void RoomItem::setDataPointer(int id, type* data) {
		if (id < 0 && id > this->data.size() - 1) return 0;
		this->data[id] = static_cast<void*>(data);
	}

	template <typename type>
	void RoomItem::addDataPointer(int id, type* data) {
		if (id < 0 && id > this->data.size() - 1) return 0;
		this->data.insert(this->data.end() ,static_cast<void*>(data));
	}
	
	void* RoomItem::getData(int id) {
		if (id < 0 && id > this->data.size() - 1) return 0;
		return this->data[id];
	}

	void RoomItem::setData(int id, void* data) {
		if (id < 0 && id > this->data.size() - 1) return 0;
		//this->dataList[id] = data;

		//HZ....
	}

	void RoomItem::addData(void* data);

	//Params:
	Point RoomItem::getLocation() {
		return location;
	}

	void  RoomItem::setLocation(Point location) {
		this->location = location;
	}

	void  RoomItem::setLocation(int x, int y) {
		this->location = {x, y};
	}

	int RoomItem::getX() {
		return this->location.x;
	}

	int RoomItem::setX(int x) {
		this->location.x = x;
	}

	int RoomItem::getY() {
		return this->location.y;
	}

	int RoomItem::setY(int y) {
		this->location.y = y;
	}

	float RoomItem::getDirection() {
		return this->direction;
	}

	void  RoomItem::setDirection(float direction) {
		this->direction = direction;
	}

	float RoomItem::getSpeed() {
		return this->speed;
	}

	void  RoomItem::setSpeed(float speed) {
		this->speed = speed;
	}

	//==ViewRoom
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
}