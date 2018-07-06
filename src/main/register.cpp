#include "include/register.h"

namespace CasGD {
	Register::Register(int count) {
		this->objectsCount = count;
		this->objects = new GameObject*[this->objectsCount];
	}

	int Register::getObjectsCount() {
		return this->objectsCount;
	}

	GameObject* Register::getObject(int id) {
		if (id < 0 || id > this->objectsCount - 1) return 0;
		return this->objects[id];
	}

	bool Register::setObject(int id, GameObject* obj) {
		if (id < 0 || id > this->objectsCount - 1 || obj == 0) return false;
		this->objects[id] = obj;
	}

	int Register::getIDFromObject(GameObject* obj) {
		for (int i = 0; i < this->objectsCount; i++) {
			if (objects[i] == obj) {
				return i;
			}
		}
	}

	int Register::getIDFromName(char* name) {
		for (int i = 0; i < this->objectsCount; i++) {
			if (objects[i] == name) {
				return i;
			}
		}
	}
}