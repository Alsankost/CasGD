namespace CasGD {
	class Drawing {
		private:
			Room* current;
			float lineWidth = 1; //px
		public:
			void setRoom(Room* room);
			Room* getRoom();

			void setLineWidth(float w);

			virtual void update();

			//Drawing:
			virtual void draw_Line(const Point& p1, const Point& p2);
			virtual void draw_Rectangle(const Rectangle& rect);
			virtual void draw_Shape(const std::vector<Point>& vertex);
			virtual void draw_Elepse(const Point& pos, float wr, float hr);
			virtual void draw_Text(const Point& pos, std::string str); 

			virtual void fill_Rectangle(const Rectangle& rect);
			virtual void fill_Shape(const std::vector<Point>& vertex);
			virtual void fill_Elepse(const Point& pos, );
	};
}