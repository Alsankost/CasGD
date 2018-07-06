namespace CasGD {
	class Game {
		private:
			Render* render;
			std::std::vector<Room*> rooms;
			Room* selectedRoom;
			Register* reg;

		public:
			Game(Render* render);

			void render();
			void observe();

			Render*   getRender();
			Register* getRegister();

			int getRoomCount();
			Room* getRoom(int i);
			Room* getSelectedRoom();
			void selectRoom(int i);

			void newRoom(Resolution size);
			void newRoom(float w, float h);
	};
}