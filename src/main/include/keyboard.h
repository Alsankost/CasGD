namespace CasGD_IO {
	enum KeyboardListenerType {
		SIMPLE,
		PRESS,
		RELEASE
	};

	struct KeyboardListener {
		KeyboardListenerType type;
		int key;
		void (*action)(GameObject*, int key);
	};

	KeyboardListener* createKeyboardListener(KeyboardListenerType type, int key, void (*action)(GameObject*, int key));
}