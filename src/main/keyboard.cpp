namespace CasGD {
	KeyboardListener* createKeyboardListener(KeyboardListenerType type, int key, void (*action)(GameObject*, int key)) {
		KeyboardListener* tmp = new KeyboardListener;
		tmp->type   = type;
		tmp->key    = key;
		tmp->action = action;
		return tmp;
	}
}