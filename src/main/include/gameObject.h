#include "geometry.h"

namespace CasGD {
	class RoomItem;
	class Game;

	class GameObject {
		private:
			char* name;

		public:
			GameObject(char* n);

			char* getName();

			//Events:
			virtual void e_create(RoomItem*, Game*);
			virtual void e_step(RoomItem*, Game*);
			virtual void e_dead(RoomItem*, Game*);

			virtual void draw(RoomItem*, Game*, Render*);

			virtual GasGD::Mask* getMask();
	};
}