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
		RoomItem* item = room->createRoomItem();
	}

	bool addItem(float x, float y, std::string name);

	bool killItem(long idItem);
	bool killItem(RoomItem* item);
	bool killItems(int idObject);
	bool killItems(std::string name);
};