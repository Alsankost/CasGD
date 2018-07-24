#include "./include/draw.h";
#include "./include/game.h";

namespace CasGD {
	class glut_Draw : public Draw {
		public:
			virtual void update() {

			}

			//Drawing:=============================================================
			virtual void draw_Line(const Point& p1, const Point& p2) {

			}

			virtual void draw_Rectangle(const Rectangle& rect) {
				/*float w = this->lineWidth / 2;
				glBegin(GL_QUADS);
					glVertex3f(rect.position.x - w, rect.position.y - w, 0);
					glVertex3f(rect.position.x + rect.size.w + w, rect.position.y - w, 0);
					glVertex3f(rect.position.x + rect.size.w + w, rect.position.y + rect.size.height + w, 0);
					glVertex3f(rect.position.x - w, rect.position.y + rect.size.height + w, 0);
				glEnd();*/
				glBegin(GL_LINES);
					glVertex3f(rect.position.x, rect.position.y, 0);
					glVertex3f(rect.position.x + rect.size.w, rect.position.y, 0);
					glVertex3f(rect.position.x + rect.size.w, rect.position.y + rect.size.height, 0);
					glVertex3f(rect.position.x, rect.position.y + rect.size.height, 0);
				glEnd();
			}

			virtual void draw_Shape(const std::vector<Point>& vertex) {
				glBegin(GL_LINES);
					glVertex3f(rect.position.x, rect.position.y, 0);
					glVertex3f(rect.position.x + rect.size.w, rect.position.y, 0);
					glVertex3f(rect.position.x + rect.size.w, rect.position.y + rect.size.height, 0);
					glVertex3f(rect.position.x, rect.position.y + rect.size.height, 0);
				glEnd();
			}

			virtual void draw_Elepse(const Point& pos, float wr, float hr) {

			}

			virtual void draw_Text(const Point& pos, std::string str) {

			}
			//====================================================================

			virtual void fill_Rectangle(const Rectangle& rect) {

			}

			virtual void fill_Shape(const std::vector<Point>& vertex) {

			}

			virtual void fill_Elepse(const Point& pos, float wr, float hr) {

			}
	};

	class glut_Game : public Game {
		public:
			virtual bool init() {

			}

			virtual bool launch() {
				
			}
	};
}