#pragma once

namespace CirclesOnForms {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

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
	private: System::Windows::Forms::PictureBox^ PaintBox;


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
			this->PaintBox = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PaintBox))->BeginInit();
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
			// PaintBox
			// 
			this->PaintBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->PaintBox->BackColor = System::Drawing::Color::White;
			this->PaintBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->PaintBox->Location = System::Drawing::Point(12, 38);
			this->PaintBox->Name = L"PaintBox";
			this->PaintBox->Size = System::Drawing::Size(763, 503);
			this->PaintBox->TabIndex = 2;
			this->PaintBox->TabStop = false;
			// 
			// CirclesPaint
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::GhostWhite;
			this->ClientSize = System::Drawing::Size(787, 553);
			this->Controls->Add(this->PaintBox);
			this->Controls->Add(this->checkBoxIntersactionSelecting);
			this->Controls->Add(this->checkBoxCtrlEnabling);
			this->Name = L"CirclesPaint";
			this->Text = L"Circles Paint";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PaintBox))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};

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

	};
}
