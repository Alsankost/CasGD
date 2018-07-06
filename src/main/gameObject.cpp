#include <cstring>

#include "include/gameObject.h"

namespace CasGD {
	bool comapreStr

	GameObject::GameObject(std::string n) {
		this->name = n;
	}

	std::string GameObject::getName() {
		return this->name;
	}

	bool operator==(const GameObject* go, std::string str) {
		return str.compare(go->getName()) == 0;
	}

	bool operator==(std::string str, const GameObject* go) {
		return go == name;
	}
}