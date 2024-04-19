#pragma once

using namespace System::Windows::Forms;
using namespace System::Drawing;

ref class CCircle {
private:
	int x;
	int y;
	const int radius = 45;
	Color color;
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
	void draw(PictureBox^ box) {
		color = Color::Black;
		b = gcnew Bitmap(box->Width, box->Height);
		g = Graphics::FromImage(b);
		Pen^ pen = gcnew Pen(color, 3.f);
		g->DrawEllipse(pen, x - radius, y - radius, 2 * radius, 2 * radius);
		box->Image = b;
	}
};