#include "geometry.h"
#include <string>

namespace CasGD {
	class RoomItem;
	class Game;

	class GameObject {
		private:
			std::string name;

		public:
			GameObject(std::string);

			std::string getName();

			//Events:
			virtual void e_create(RoomItem*, Game*);
			virtual void e_step(RoomItem*, Game*);
			virtual void e_dead(RoomItem*, Game*);

			virtual void draw(RoomItem*, Game*, Render*);

			virtual std::vector<Point> getMask();
	};
}