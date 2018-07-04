namespace CasGD {
	struct Point {
		float x, y;
	};

	struct Polygon {
		Point v1, v2, v3;
	};

	struct Line {
		Point p1, p2;
	};

	struct Resolution {
		float w, h;
	};

	struct Redrangle {
		Point position;
		Resolution size;
	};

	struct Mask {
		Point* points;
		int pointsCount;
	};
}