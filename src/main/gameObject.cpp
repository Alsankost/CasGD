#include "include/gameObject.h"

GameObject::GameObject(Listeners* lst, int mvc, int dl) {
	if (lst == 0) {
		listeners = new Listeners;
	} else {
		listeners = lst;
	}
	if (mvc < 0) {
		maskVertexCount = 0;
	} else {
		maskVertexCount = mvc;
	}

	if (dl < 0) {
		dataLength = 0;
	} else {
		dataLength = dl;
	}

	location = {};
}

GameObject::GameObject(int mvc, int dl) {
	GameObject(new Listeners, mvc, dl);
}

GameObject::GameObject(int dl) {
	GameObject(0, dl);
}

GameObject::GameObject() {
	GameObject(0, 0);		
}

Listeners* GameObject::getListeners() {
	return listeners;
}

void* GameObject::getData(int i) {
	if (i < 0 || i >= dataLength) return 0;
		return data[i];
	}

void GameObject::setData(int i, void* val) {
	if (i < 0 || i >= dataLength) return;
	data[i] = val;
}

int GameObject::getDataLenght() {
	return dataLength;
}

Point GameObject::getMaskVertex(int i) {
	if (i < 0 || i >= maskVertexCount) return {0, 0, 0};
	return mask[i];
}

void GameObject::setMaskVertex(int i, int x, int y, int z) {
	if (i < 0 || i >= maskVertexCount) return;		
	Point tmp;
	tmp.x = x;
	tmp.y = y;
	tmp.z = z;
	mask[i] = tmp;
}

void GameObject::setMaskVertex(int i, Point p) {
	if (i < 0 || i >= maskVertexCount) return;
	mask[i] = p;
}

int GameObject::getMaskVertexCount() {
	return maskVertexCount;
}

Point GameObject::getLocation() {
	return location;
}

void GameObject::setLocation(int x, int y, int z) {
	location.x = x;
	location.y = y;
	location.z = z;
}

void GameObject::setLocation(Point p) {
	location = p;		
}

GameObject::~GameObject() {
	delete[] mask;
	for (int i = 0; i < dataLength; i++) {
		delete data[i];			
	}
	delete[] data;
}		
