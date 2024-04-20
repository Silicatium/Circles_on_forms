#pragma once
#include <cmath>

using namespace System::Windows::Forms;
using namespace System::Drawing;

ref class CCircle {
private:
	int x;
	int y;
	int mouse_X;
	int mouse_Y;
	const int radius = 45;
	Bitmap^ b;
	Graphics^ g;
public:
	CCircle() : x(0), y(0) {};
	CCircle(int x, int y) : x(x), y(y) {};
	CCircle(const CCircle% c) : x(c.x), y(c.y) {};
	~CCircle() {
		x = 0;
		y = 0;
	};
	Color color = Color::Blue;
	void draw(PictureBox^ box, Bitmap^ b) {
		g = Graphics::FromImage(b);
		Pen^ pen = gcnew Pen(color, 3.f);
		g->DrawEllipse(pen, x - radius, y - radius, 2 * radius, 2 * radius);
		box->Image = b;
	}
	void send_mouse_coords(int mouse_X, int mouse_Y) {
		this->mouse_X = mouse_X;
		this->mouse_Y = mouse_Y;
	}
	bool remove() {
		return (sqrt(pow(x - mouse_X, 2) + pow(y - mouse_Y, 2))) <= radius;
	}
};