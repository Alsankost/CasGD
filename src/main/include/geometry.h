namespace CasGD {
	struct Point {
		int x, y, z;
	};

	struct Polygon {
		Point p1, p2, p3;
	};

	struct Line {
		Point p1, p2;
	};

	struct Mask {
		Point* points;
		int pointsCount;
	};
}