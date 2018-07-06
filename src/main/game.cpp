#include "./include/game.h"

namespace CasGD {
			Render* render;
			std::std::vector<Room*> rooms;
			Register* reg;

	Game::Game(Render* render) {
		this->render = render;
	}

	void Game::render() {
		//TMP!!!
		for (int i = 0; i < selectedRoom.getItemsCount(); i++) {
			RoomItem* item = selectedRoom
			GameObject* gameObject = reg->getObject();
		}
	}

	void observe();

	Render*   getRender();
	Register* getRegister();

	int getRoomCount();
	Room* getRoom(int i);
	Room* getSelectedRoom();
	void selectRoom(int i);



	void newRoom(Resolution size);
	void newRoom(float w, float h);
}