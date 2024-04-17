#include "CirclesPaint.h"

using namespace System;
using namespace System::Windows::Forms;

int main(array<String^>^ args) {
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	CirclesOnForms::CirclesPaint form;
	Application::Run(% form);
}