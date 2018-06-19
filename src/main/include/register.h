namespace CasGD {
	class Register {
		private:
			CasGD::GameObject** objects;
			int objectsCount;

		public:
			Register(int count);

			int getObjectsCount();
			CasGD::GameObject* getObject(int id);
			CasGD::GameObject* setObject(int id, GasGD::GameObject* obj);
	};
}