#pragma once

using namespace System::Drawing;

class CCircle {
private:
	int x;
	int y;
	const int radius = 45;
public:
	CCircle() : x(0), y(0) {};
	CCircle(int x, int y) : x(x), y(y) {};
	CCircle(const CCircle& c) : x(c.x), y(c.y) {};
	~CCircle() {
		x = 0;
		y = 0;
	};
	CCircle& operator=(const CCircle& c) {
		if (this != &c) {
			x = c.x;
			y = c.y;
		}
		return *this;
	}
};