namespace CasGD {
	class Render {
		private:
			Room* current;
		public:
			virtual void init(Room* room);
			virtual void update();

			//Drawing:
			virtual void draw_Line(const Point& p1, const Point& p2, float w);
			virtual void draw_Rectangle(const Rectangle& rect, float w);
			virtual void draw_Shape(const std::vector<Point>& vertex, float w);
			virtual void draw_Elepse(const Point& p1, float w);

			virtual void fill_Rectangle(const Rectangle& rect, float w);
			virtual void fill_Shape(const std::vector<Point>& vertex, float w);
			virtual void fill_Elepse(const Point& p1, float w);
	};
}