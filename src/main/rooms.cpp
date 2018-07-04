#include "include/rooms.h"

namespace CasGD {
	//==RoomItem===========================================================================
	RoomItem::RoomItem(long id) {
		this->id = id;
	}

	RoomItem::RoomItem(long id, int x, int y) {
		this->id = id;
		this->position = {x, y};
	}

	RoomItem::PoomItem(long id, Point position) {
		this->id = id;
		this->position = position;
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
		this->setData(id, static_cast<void*>(data));
	}

	template <typename type>
	void RoomItem::addDataPointer(type* data) {
		this->addData(static_cast<void*>(data));
	}
	
	void* RoomItem::getData(int id) {
		if (id < 0 && id > this->data.size() - 1) return 0;
		return this->data[id];
	}

	void RoomItem::setData(int id, void* data) {
		if (id < 0 && id > this->data.size() - 1) return 0;
		this->data[id] = data;
	}

	void RoomItem::addData(void* data) {
		this->data.insert(this->data.end(), data);
	}

	//Params:
	Point RoomItem::getPosition() {
		return position;
	}

	void  RoomItem::setPosition(Point position) {
		this->position = position;
	}

	void  RoomItem::setPosition(int x, int y) {
		this->position = {x, y};
	}

	int RoomItem::getX() {
		return this->position.x;
	}

	int RoomItem::setX(int x) {
		this->position.x = x;
	}

	int RoomItem::getY() {
		return this->position.y;
	}

	int RoomItem::setY(int y) {
		this->position.y = y;
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


	//==ViewRoom==================================================================================			
	ViewRoom::ViewRoom(Rectangle bounce, int idTarget) {
		this->setBounce(bounce);
		this->idTarget = idTarget;
	}

	ViewRoom::ViewRoom(Rectangle bounce, int idTarget, bool isIDType) {
		ViewRoom::RoomItem(bounce, idTarget);
		this->isIDType = isIDType;
	}

	ViewRoom::ViewRoom(Point position, Resolution size, int idTarget) {
		ViewRoom::RoomItem(Rectangle{padding, size}, idTarget);
	}

	ViewRoom::ViewRoom(Point position, Resolution size, int idTarget, bool isIDType) {
		ViewRoom::RoomItem(Rectangle{padding, size}, idTarget, isIDType);
	}

	ViewRoom::ViewRoom(float x, float y, float w, float h, int idTarget) {
		ViewRoom::RoomItem(Rectangle{Point(x, y), Size(w, h)}, idTarget);
	}

	ViewRoom::ViewRoom(float x, float y, float w, float h, int idTarget, bool isIDType) {
		ViewRoom::RoomItem(Rectangle{Point(x, y), Size(w, h)}, idTarget, isIDType);
	}

	Point ViewRoom::getPosition() {
		return this->bounce.position;
	}

	Resolution ViewRoom::getSize() {
		return this->bounce.size;
	}

	Rectangle ViewRoom::getBounce() {
		return this->bounce;
	}
	
	float ViewRoom::getBorder(BorderSide side) {
		switch (side) {
			case BORDER_RIGTH:
				return this->padding[0];
			case BORDER_TOP:
				return this->padding[1];
			case BORDER_LEFT:
				return this->padding[2];
			case BORDER_BOTTOM:
				return this->padding[3];
		}
	}

	void ViewRoom::setPosition(Point position) {
		if (position.x < 0 || position.y < 0) return;
		this->bounce.position = position;
	}
	
	void ViewRoom::setPosition(float x, float y) {
		this->setPosition({x, y});
	}
	
	void ViewRoom::setSize(Resolution size) {
		if (size.w < 0 || size.y < 0) return;
		this->bounce.size = size;
	}

	void ViewRoom::setSize(float w, float h) {
		this->setSize({w, h});
	}

	void ViewRoom::setBounce(Rectangle bounce) {
		if (bounce.position.x < 0 || bounce.position.y < 0 || bounce.size.w < 0 || bounce.size.h < 0) return;
		this->bounce = bounce;
	}

	void ViewRoom::setBounce(float x, float y, float w, float h) {
		this->setBounce({{x, y}, {w, h}});
	}
	
	void ViewRoom::setBorder(BorderSide side, float width) {
		if (width < 0) return;
		switch (side) {
			case BORDER_RIGTH:
				this->padding[0] = width;
				break;
			case BORDER_TOP:
				this->padding[1] = width;
				break;
			case BORDER_LEFT:
				this->padding[2] = width;
				break;
			case BORDER_BOTTOM:
				this->padding[3] = width;
				break;
		}
	}

	
	long ViewRoom::getTargetID() {
		return this->idTarget;
	}

	void ViewRoom::setTargetID(long idTarget) {
		this->idTarget = idTarget;
	}

	bool ViewRoom::isGameObjectTarget() {
		return this->isIDType;
	}
}