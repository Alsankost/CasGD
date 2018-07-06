#include <string>

namespace CasGD {
	class Register {
		private:
			CasGD::GameObject** objects;
			int objectsCount;

		public:
			Register(int count);

			int getObjectsCount();
			GameObject* getObject(int id);
			bool setObject(int id, GameObject* obj);

			int getIDFromObject(GameObject* obj);
			int getIDFromName(std::string name);
	};
}