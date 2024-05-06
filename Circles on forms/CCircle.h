#pragma once

using namespace System::Windows::Forms;
using namespace System::Drawing;

ref class CCircle {
private:
	int x;
	int y;
	const int radius = 45;
	bool selected = true;
	Color color;
public:
	CCircle() : x(0), y(0) {};
	CCircle(int x, int y) : x(x), y(y) {};
	CCircle(const CCircle% c) : x(c.x), y(c.y) {};
	~CCircle() {
		x = 0;
		y = 0;
	};
	void draw(Graphics^ g) {
		if (selected) color = Color::Blue;
		else color = Color::Black;
		Pen^ pen = gcnew Pen(color, 3.f);
		g->DrawEllipse(pen, x - radius, y - radius, 2 * radius, 2 * radius);
	}
	bool check_entry(int mouse_X, int mouse_Y) {
		return ((x - mouse_X) * (x - mouse_X) + (y - mouse_Y) * (y - mouse_Y)) <= radius * radius;
	}
	void clicked() {
		selected = !selected;
	}
	bool check_selected() {
		return selected;
	}
};