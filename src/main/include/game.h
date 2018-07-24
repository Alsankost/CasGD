#include <vector>
#include <string>

namespace CasGD {
	class Drawing;
	class Room;
	class Register;

	class Game {
		private:
			Drawing* drawing;
			Room* room;
			Register* reg;

		public:
			Game();

			virtual bool init();
			virtual bool launch();

			void setRoom(Room* room);

			Drawing* getDrawing();
			Register* getRegister();
			Room* getRoom();

			bool addItem(float x, float y, int idObject);
			bool addItem(float x, float y, std::string name);

			bool killItem(long idItem);
			bool killItem(RoomItem* item);
			//bool killItems(int idObject);
			//bool killItems(std::string name);
	};
}