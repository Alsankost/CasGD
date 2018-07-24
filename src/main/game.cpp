#include "include/game.h"

namespace CasGD {
			Drawing* drawing;
			Room* selectedRoom;
			Register* reg;

	void Game::Game() {
		this->reg = new Register();
	}

	void Game::setRoom(Room* room) {
		this->room = room;
	}

	Drawing* getDrawing() {
		return drawing;
	}

	Register* getRegister() {
		return reg;
	}

	Room* getRoom() {
		return room;
	}

	bool addItem(float x, float y, int idObject) {
		RoomItem* item = this->room->createRoomItem(this->ger, x, y, idObject);
		if (!item) {
			return false;
		}
		this->room->addItem(item);
		return true;
	}

	bool addItem(float x, float y, std::string name) {
		return addItem(float x, float y, this->reg->getIDFromName(name));
	}

	bool killItem(long idItem) {
		this->killItem(this->room->getItemFromID(idItem));
	}

	bool killItem(RoomItem* item) {
		this->reg->getObject(item->getGameObjectID()).e_dead(item, this);
		this->room->removeItem(item->getID());
	}
	/*
	bool killItems(int idObject) {

	}

	bool killItems(std::string name);*/
};