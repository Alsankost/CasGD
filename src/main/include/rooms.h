namespace CasGD {
	class RoomItem {
		private:
			int gameObjectId;

			Point location = {0, 0};
			float direction = 0;
			float speed = 0;

			int dataCount = 0;
			long* dataList = 0;

		public:
			RoomItem();
			RoomItem(int x, int y);
			PoomItem(Point location);

			//Data:
			void initData(int count);
			int getDataCount();

			template <typename type>
			type* getDataPointer(int id);

			template <typename type>
			void setDataPointer(int id, type* data);

			long getData(int id);
			void setData(int id, long data);

			//Params:
			Point getLocation();
			void  setLocation(Point location);
			void  setLocation(int x, int y);
			int getX();
			int setX(int x);
			int getY();
			int setY(int y);
			float getDirection();
			void  setDirection(float direction);
			float getSpeed();
			void  setSpeed(float speed);
	};

	class Room {
		
	}
}