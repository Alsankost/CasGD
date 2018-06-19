namespace CasGD {
	class Register {
		private:
			CasGD::GameObject** objects;
			int objectsCount;

		public:
			Register(int count);

			int getObjectsCount();
			CasGD::GameObject* getObject(int id);
			bool setObject(int id, GasGD::GameObject* obj);

			int getIdFromObject(CasGD::GameObject* obj);
			int getIdFromName(char* name);
	};
}