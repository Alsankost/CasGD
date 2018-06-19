#include <cstring>

#include "include/gameObject.h"

namespace CasGD {
	bool comapreStr

	GameObject::GameObject(char* n) {
		this->name = n;
	}

	char* GameObject::getName() {
		return this->name;
	}

	bool operator==(const GameObject* go, char* name) {
		return strcmp(go->getName(), name) == 0;
	}

	bool operator==(char* name, const GameObject* go) {
		return go == name;
	}

	GameObject::~GameObject() {
		delete[] this->name;
	}
}	
