#pragma once
#include "CCircle.h"

namespace CirclesOnForms {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;

	/// <summary>
	/// —водка дл€ CirclesPaint
	/// </summary>

	public ref class CirclesPaint : public System::Windows::Forms::Form
	{
	public:
		CirclesPaint(void) {
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~CirclesPaint() {
			if (components) {
				delete components;
			}
		}
	private: System::Windows::Forms::CheckBox^ checkBoxCtrlEnabling;
	private: System::Windows::Forms::CheckBox^ checkBoxIntersactionSelecting;
	private: System::Windows::Forms::PictureBox^ paintBox;


	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void) {
			this->checkBoxCtrlEnabling = (gcnew System::Windows::Forms::CheckBox());
			this->checkBoxIntersactionSelecting = (gcnew System::Windows::Forms::CheckBox());
			this->paintBox = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->paintBox))->BeginInit();
			this->SuspendLayout();
			// 
			// checkBoxCtrlEnabling
			// 
			this->checkBoxCtrlEnabling->AutoSize = true;
			this->checkBoxCtrlEnabling->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->checkBoxCtrlEnabling->Location = System::Drawing::Point(12, 12);
			this->checkBoxCtrlEnabling->Name = L"checkBoxCtrlEnabling";
			this->checkBoxCtrlEnabling->Size = System::Drawing::Size(176, 20);
			this->checkBoxCtrlEnabling->TabIndex = 0;
			this->checkBoxCtrlEnabling->Text = L"Multiple selection with Ctrl";
			this->checkBoxCtrlEnabling->UseVisualStyleBackColor = true;
			// 
			// checkBoxIntersactionSelecting
			// 
			this->checkBoxIntersactionSelecting->AutoSize = true;
			this->checkBoxIntersactionSelecting->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->checkBoxIntersactionSelecting->Location = System::Drawing::Point(194, 12);
			this->checkBoxIntersactionSelecting->Name = L"checkBoxIntersactionSelecting";
			this->checkBoxIntersactionSelecting->Size = System::Drawing::Size(252, 20);
			this->checkBoxIntersactionSelecting->TabIndex = 1;
			this->checkBoxIntersactionSelecting->Text = L"Selecting all objects at the intersection";
			this->checkBoxIntersactionSelecting->UseVisualStyleBackColor = true;
			// 
			// paintBox
			// 
			this->paintBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->paintBox->BackColor = System::Drawing::Color::White;
			this->paintBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->paintBox->Location = System::Drawing::Point(12, 38);
			this->paintBox->Name = L"paintBox";
			this->paintBox->Size = System::Drawing::Size(763, 503);
			this->paintBox->TabIndex = 2;
			this->paintBox->TabStop = false;
			this->paintBox->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &CirclesPaint::PaintBox_Paint);
			this->paintBox->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &CirclesPaint::PaintBox_MouseClick);
			this->paintBox->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &CirclesPaint::paintBox_MouseMove);
			// 
			// CirclesPaint
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::GhostWhite;
			this->ClientSize = System::Drawing::Size(787, 553);
			this->Controls->Add(this->paintBox);
			this->Controls->Add(this->checkBoxIntersactionSelecting);
			this->Controls->Add(this->checkBoxCtrlEnabling);
			this->KeyPreview = true;
			this->Name = L"CirclesPaint";
			this->Text = L"Circles Paint";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &CirclesPaint::CirclesPaint_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &CirclesPaint::CirclesPaint_KeyUp);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->paintBox))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		List<CCircle^>^ circles = gcnew List<CCircle^>;
		bool ctrlPressed = false;

	private: System::Void PaintBox_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		int countOfUnselected = 0;
		int countList = circles->Count;
		bool check_act = false;
		List<CCircle^>^ objects = gcnew List<CCircle^>;
		for each (CCircle ^ circle in circles) {
			if (!circle->check_selected()) countOfUnselected++;
			if (circle->check_entry()) {
				if (!checkBoxIntersactionSelecting->Checked) objects->Clear();
				objects->Add(circle);
				check_act = true;
			}
		}
		if (check_act) {
			for each (CCircle ^ object in objects) {
				if (object->check_selected() && countList > countOfUnselected + 1) {
					object->clicked();
					countOfUnselected++;
				}
				else if (!object->check_selected()) {
					if (!ctrlPressed) {
						for each (CCircle ^ circle in circles) {
							if (circle->check_selected()) circle->clicked();
						}
					}
					object->clicked();
				}
			}
		}
		else {
			for each (CCircle ^ circle in circles) {
				if (circle->check_selected()) circle->clicked();
			}
			circles->Add(gcnew CCircle(e->X, e->Y));
			paintBox->Invalidate();
		}
	}
	private: System::Void PaintBox_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		Bitmap^ b = gcnew Bitmap(paintBox->Width, paintBox->Height);
		for each (CCircle^ circle in circles) {
			circle->draw(paintBox, b);
		}
		if (circles->Count == 0 && paintBox->Image != nullptr) paintBox->Image = b;
	}
	private: System::Void paintBox_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		for each (CCircle^ circle in circles) {
			circle->send_mouse_coords(e->X, e->Y);
		}
	}
	private: System::Void CirclesPaint_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::Delete) {
			List<CCircle^>^ selectedCircles = gcnew List<CCircle^>;
			CCircle^ object;
			for each (CCircle ^ circle in circles) {
				if (circle->check_selected()) selectedCircles->Add(circle);
				else object = circle;
			}
			for each (CCircle ^ circle in selectedCircles) {
				circles->Remove(circle);
			}
			if (object != nullptr) object->clicked();
		}
		if (checkBoxCtrlEnabling->Checked) {
			if (e->KeyCode == Keys::ControlKey) ctrlPressed = true;
		}
	}
	private: System::Void CirclesPaint_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (ctrlPressed && e->KeyCode == Keys::ControlKey) ctrlPressed = false;
	}
	};
}
