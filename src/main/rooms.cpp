#include "include/rooms.h"

namespace CasGD {
	RoomItem::RoomItem() {
		//HZ...
	}

	RoomItem::RoomItem(int x, int y) {
		this->location = {x, y};
	}

	RoomItem::PoomItem(Point location) {
		this->location = location;
	}

	//Data:
	void RoomItem::initData(int count) {
		if (count < 0) return;
		this->dataCount = count;
		this->dataList = new long[this->dataCount];
	}

	int  RoomItem::getDataCount() {
		return this->dataCount;
	}

	template <typename type> type*
	RoomItem::getDataPointer(int id) {
		if (id < 0 && id > this->dataCount - 1) return 0;
		return (type*) dataList[id];
	}

	template <typename type>
	void RoomItem::setDataPointer(int id, type* data) {
		if (id < 0 && id > this->dataCount - 1) return 0;
		this->dataList[id] = (long) data;
	}
	
	long RoomItem::getData(int id) {
		if (id < 0 && id > this->dataCount - 1) return 0;
		return this->dataList[id];
	}

	void RoomItem::setData(int id, long data) {
		if (id < 0 && id > this->dataCount - 1) return 0;
		this->dataList[id] = data;
	}

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
}