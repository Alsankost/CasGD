#include "geometry.h"

class GameObject;
/*Объект, попсывающий поведение сущностей, пренадлежащих ему*/
struct Listeners {
	/*
	  Слушатели событий, получают в качестве параметра - ссылку на сущность
	*/
	
	void (*e_create)(GameObject*);
	/*
	  Слушатель события создания, вызывается при создании сущности в комнате
	*/

	void (*e_step)(GameObject*);
	/*
	  Слушатель шага, вызывается каждую итерацию потокоа логики
	*/

	void (*e_keyBoard)(GameObject*, unsigned char key, int x, int y);
	/*
	  Слушатель клавиатуры, вызывается при событии клавиатуры,
	  получает в качестве параметров - unsigned
	*/

	void (*e_specialKey)(GameObject*, unsigned char key, int x, int y);
	/*
	  Слушатель клавиатуры, вызывается при событии клавиатуры "специальной" клавиши,
	  получает в качестве параметров - unsigned
	*/

	void (*e_mouseClick)(GameObject*, int button, int state, int x, int y);
	/*
	  Слушатель мыши, вызывается при клику по сущности
	*/

	void (*e_mouseEnter)(GameObject*, int x,int y);
	/*
	  Слушатель мыши, вызывается при наведении курсора на сущность
	*/

	void (*e_mouseDrag)(GameObject*, int x, int y);
	/*
	  Слушатель мыши, вызывается при "драге" по сущности
	*/

	void (*e_dead)(GameObject*);
	/*
	  Слушатель смерти, вызывается при уничтожении сущности
	*/
};

class GameObject {
	private:
		Listeners* listeners;

		int maskVertexCount;
		Point* mask;

		int dataLength;
		void** data;

		Point location;
		int direction;
		int speed;
		

	public:
		GameObject(Listeners* lst, int mvc, int dl);
		GameObject(int mvc, int dl);
		GameObject(int dl);
		GameObject();

		Listeners* getListeners();
		void* getData(int i);
		void  setData(int i, void* val);
		int   getDataLenght();
		Point getMaskVertex(int i);
		void  setMaskVertex(int i, int x, int y, int z);
		void  setMaskVertex(int i, Point p);
		int   getMaskVertexCount();
		Point getLocation();
		void  setLocation(int x, int y, int z);
		void  setLocation(Point p);
		~GameObject();
};
