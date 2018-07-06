#include "include/rooms.h"

namespace CasGD {
	//==RoomItem===========================================================================
	RoomItem::RoomItem(int gameObjectID, long id) {
		this->gameObjectID = gameObjectID;
		this->id = id;
	}

	RoomItem::RoomItem(int gameObjectID, long id, int x, int y) {
		this->gameObjectID = gameObjectID;
		this->id = id;
		this->position = {x, y};
	}

	RoomItem::PoomItem(int gameObjectID, long id, Point position) {
		this->gameObjectID = gameObjectID;
		this->id = id;
		this->position = position;
	}

	int getGameObjectID() {
		return this->gameObjectID;
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

	long RoomItem::getID() {
		return this->id;
	}

	void RoomItem::disableNew() {
		this->flagNew = false;
	}

	bool RoomItem::isNew() {
		return this->flagNew;
	}


	//==RoomView==================================================================================			
	RoomView::RoomView(Rectangle bounce, int idTarget) {
		this->setBounce(bounce);
		this->idTarget = idTarget;
	}

	RoomView::RoomView(Rectangle bounce, int idTarget, bool isIDType) {
		RoomView::RoomItem(bounce, idTarget);
		this->isIDType = isIDType;
	}

	RoomView::RoomView(Point position, Resolution size, int idTarget) {
		RoomView::RoomItem(Rectangle{padding, size}, idTarget);
	}

	RoomView::RoomView(Point position, Resolution size, int idTarget, bool isIDType) {
		RoomView::RoomItem(Rectangle{padding, size}, idTarget, isIDType);
	}

	RoomView::RoomView(float x, float y, float w, float h, int idTarget) {
		RoomView::RoomItem(Rectangle{Point(x, y), Size(w, h)}, idTarget);
	}

	RoomView::RoomView(float x, float y, float w, float h, int idTarget, bool isIDType) {
		RoomView::RoomItem(Rectangle{Point(x, y), Size(w, h)}, idTarget, isIDType);
	}

	Point RoomView::getPosition() {
		return this->bounce.position;
	}

	Resolution RoomView::getRoomPort() {
		return this->roomPort;
	}

	Resolution RoomView::getScreenPort() {
		return this->screenPort;
	}
	
	float RoomView::getBorder(BorderSide side) {
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

	void RoomView::setPosition(Point position) {
		if (position.x < 0 || position.y < 0) return;
		this->bounce.position = position;
	}
	
	void RoomView::setPosition(float x, float y) {
		this->setPosition({x, y});
	}
	
	void RoomView::setRoomPort(Resolution size) {
		if (size.w < 0 || size.y < 0) return;
		this->roomPort = size;
	}

	void RoomView::setRoomPort(float w, float h) {
		this->setRoomPort({w, h});
	}

	void RoomView::setScreenPort(Resolution size) {
		if (size.w < 0 || size.y < 0) return;
		this->screenPort = size;
	}

	void RoomView::setScreenPort(float w, float h) {
		this->setScreenPort({w, h});
	}
	
	void RoomView::setBorder(BorderSide side, float width) {
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

	
	long RoomView::getTargetID() {
		return this->idTarget;
	}

	void RoomView::setTargetID(long idTarget) {
		this->idTarget = idTarget;
	}

	bool RoomView::isGameObjectTarget() {
		return this->isIDType;
	}

	//==Room=====================================================================================
	Room::Room(Resolution size) {
		this->setSize(size);
		this->setView(this->createView());

	}

	Room::Room(float w, float h) {
		this->setSize(w, h);
		this->setView(this->createView());
	}

	Resolution Room::getSize() {
		return this->size;
	}

	//Resolution Room::getViewPoint() { }

	void Room::setSize(Resolution size) {
		if (size.w <= 0 && size.h <= 0) return;
		this->size = size;
	}

	void Room::setSize(float w, float h) {
		this->setSize(Resolution{w, h});
	}

	void Room::setView(RoomView* view) {
		if (view == 0) return;
		this->curretView = view;
	}

	/*
	void Room::setViewPort(Resolution size) {
		if (size.w <= 0 && size.h <= 0) return;
		this->viewPort = size;
	}

	void Room::setViewPort(float w, float h) {
		this->setViewPort(Resolution{w, h});
	}
	
	void setCurrentView(int id) {
		if (id < this->getViewsCount() - 1) return;
		this->curretView = views[id];
	}

	void setCurrentView(RoomView* view) {

	}*/

	int Room::getItemsCount() {
		return items.size();
	}

	/*
	int Room::getViewsCount() {
		return views.size();
	}*/

	RoomItem* Room::getItemFromIndex(int i) {
		if (i > this->getItemsCount() - 1) return 0;
		return items[i];
	}

	RoomItem* Room::getItemFromID(long id) {
		for (vector<RoomItem*>::iterator it = views.begin(); it !=views.end(); it++) {
			RoomView* tmp = *it;
			if (tmp->getID() == id) return tmp;
		}
		return 0;
	}

	RoomView* Room::getView() {
		return this->curretView;
	}

	RoomItem* Room::createItem(Register* reg, float x, float y, int idObject) {
		if (reg == 0 || reg->getObject(idObject) == 0) return 0;
		RoomItem* item = new RoomItem(reg.getGameObject(idObject), this->items[this->getItemsCount() - 1]->getID() + 1, x, y);
	}

	RoomItem* Room::createItem(Register* reg, float x, float y, std::string name) {
		if (reg == 0) return 0;
		return this->createItem(reg, x, y, reg->getIDFromName(name));
	}

	RoomView* Room::createViewFormObjectID(int objectID) {
		return new RoomView(this->getSize(), objectID, true);
	}

	RoomView* Room::createViewFormItemID(long itemID) {
		return new RoomView(this->getSize(), objectID);
	}

	RoomView* Room::createView() {
		return new RoomView(this->getSize(), -1, true);
	}

	bool Room::killItem(long itemID) {
		for (vector<RoomItem*>::iterator it = views.begin(); it != views.end(); it++) {
			RoomView* tmp = *it;
			if (tmp->getID() == itemID) {
				items.erase(it);
				return true;
			}
		}
		return false;
	}
	
	bool Room::killItems(int objectID) {
		for (vector<RoomItem*>::iterator it = views.begin(); it != views.end(); it++) {
			RoomView* tmp = *it;
			if (tmp->getGameObjectID() == objectID) {
				items.erase(it);
				return true;
			}
		}
		return false;
	}
}