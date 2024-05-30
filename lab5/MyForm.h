#pragma once

#include"lab5.h"

CStack<unsigned char> un;
CStack<long long> lo;
CStack<CRectangle> cr;

CStack<unsigned char> savedun;
CStack<long long> savedlo;
CStack<CRectangle> savedcr;

int nlo = 0, nun = 0, ncr = 0;

CStack<unsigned char>* masun;
CStack<long long>* maslo;
CStack<CRectangle>* mascr;

namespace lab5 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for lab5
	/// </summary>
	public ref class lab5 : public System::Windows::Forms::Form
	{
	public:
		lab5(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~lab5()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button_unsigned_char;
	private: System::Windows::Forms::Button^ button_long_long;
	private: System::Windows::Forms::Button^ button_CRectangle;
	private: System::Windows::Forms::Label^ labelCStack;
	private: System::Windows::Forms::Label^ label_type;
	private: System::Windows::Forms::Button^ button_push;
	private: System::Windows::Forms::TextBox^ text_newvalue1;
	private: System::Windows::Forms::TextBox^ text_newvalue2;
	private: System::Windows::Forms::Label^ label_newvalue1;
	private: System::Windows::Forms::Label^ label_newvalue2;
	private: System::Windows::Forms::Button^ button_pop;

	private: System::Windows::Forms::Button^ button_get;
	private: System::Windows::Forms::Button^ button_save;

	private: System::Windows::Forms::Button^ button_find;
	private: System::Windows::Forms::Button^ button_savetostack;






	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button_unsigned_char = (gcnew System::Windows::Forms::Button());
			this->button_long_long = (gcnew System::Windows::Forms::Button());
			this->button_CRectangle = (gcnew System::Windows::Forms::Button());
			this->labelCStack = (gcnew System::Windows::Forms::Label());
			this->label_type = (gcnew System::Windows::Forms::Label());
			this->button_push = (gcnew System::Windows::Forms::Button());
			this->text_newvalue1 = (gcnew System::Windows::Forms::TextBox());
			this->text_newvalue2 = (gcnew System::Windows::Forms::TextBox());
			this->label_newvalue1 = (gcnew System::Windows::Forms::Label());
			this->label_newvalue2 = (gcnew System::Windows::Forms::Label());
			this->button_pop = (gcnew System::Windows::Forms::Button());
			this->button_get = (gcnew System::Windows::Forms::Button());
			this->button_save = (gcnew System::Windows::Forms::Button());
			this->button_find = (gcnew System::Windows::Forms::Button());
			this->button_savetostack = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button_unsigned_char
			// 
			this->button_unsigned_char->Location = System::Drawing::Point(80, 70);
			this->button_unsigned_char->Name = L"button_unsigned_char";
			this->button_unsigned_char->Size = System::Drawing::Size(124, 43);
			this->button_unsigned_char->TabIndex = 0;
			this->button_unsigned_char->Text = L"unsigned char";
			this->button_unsigned_char->UseVisualStyleBackColor = true;
			this->button_unsigned_char->Click += gcnew System::EventHandler(this, &lab5::button_unsigned_char_click);
			// 
			// button_long_long
			// 
			this->button_long_long->Location = System::Drawing::Point(80, 119);
			this->button_long_long->Name = L"button_long_long";
			this->button_long_long->Size = System::Drawing::Size(124, 43);
			this->button_long_long->TabIndex = 1;
			this->button_long_long->Text = L"long long";
			this->button_long_long->UseVisualStyleBackColor = true;
			this->button_long_long->Click += gcnew System::EventHandler(this, &lab5::button_long_long_click);
			// 
			// button_CRectangle
			// 
			this->button_CRectangle->Location = System::Drawing::Point(80, 168);
			this->button_CRectangle->Name = L"button_CRectangle";
			this->button_CRectangle->Size = System::Drawing::Size(124, 43);
			this->button_CRectangle->TabIndex = 2;
			this->button_CRectangle->Text = L"CRectangle";
			this->button_CRectangle->UseVisualStyleBackColor = true;
			this->button_CRectangle->Click += gcnew System::EventHandler(this, &lab5::button_CRectangle_click);
			// 
			// labelCStack
			// 
			this->labelCStack->AutoSize = true;
			this->labelCStack->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19.8F, System::Drawing::FontStyle::Bold));
			this->labelCStack->Location = System::Drawing::Point(340, 51);
			this->labelCStack->Name = L"labelCStack";
			this->labelCStack->Size = System::Drawing::Size(130, 38);
			this->labelCStack->TabIndex = 9;
			this->labelCStack->Text = L"CStack";
			// 
			// label_type
			// 
			this->label_type->AutoSize = true;
			this->label_type->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_type->Location = System::Drawing::Point(476, 60);
			this->label_type->Name = L"label_type";
			this->label_type->Size = System::Drawing::Size(62, 29);
			this->label_type->TabIndex = 10;
			this->label_type->Text = L"type";
			// 
			// button_push
			// 
			this->button_push->Location = System::Drawing::Point(568, 293);
			this->button_push->Name = L"button_push";
			this->button_push->Size = System::Drawing::Size(124, 43);
			this->button_push->TabIndex = 11;
			this->button_push->Text = L"push";
			this->button_push->UseVisualStyleBackColor = true;
			this->button_push->Click += gcnew System::EventHandler(this, &lab5::button_push_click);
			// 
			// text_newvalue1
			// 
			this->text_newvalue1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->text_newvalue1->Location = System::Drawing::Point(564, 159);
			this->text_newvalue1->Name = L"text_newvalue1";
			this->text_newvalue1->Size = System::Drawing::Size(128, 34);
			this->text_newvalue1->TabIndex = 12;
			this->text_newvalue1->Visible = false;
			this->text_newvalue1->TextChanged += gcnew System::EventHandler(this, &lab5::text_newvalue1_TextChanged);
			// 
			// text_newvalue2
			// 
			this->text_newvalue2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->text_newvalue2->Location = System::Drawing::Point(564, 218);
			this->text_newvalue2->Name = L"text_newvalue2";
			this->text_newvalue2->Size = System::Drawing::Size(128, 34);
			this->text_newvalue2->TabIndex = 13;
			this->text_newvalue2->Visible = false;
			// 
			// label_newvalue1
			// 
			this->label_newvalue1->AutoSize = true;
			this->label_newvalue1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_newvalue1->Location = System::Drawing::Point(364, 159);
			this->label_newvalue1->Name = L"label_newvalue1";
			this->label_newvalue1->Size = System::Drawing::Size(194, 29);
			this->label_newvalue1->TabIndex = 14;
			this->label_newvalue1->Text = L"label_newvalue1";
			this->label_newvalue1->Visible = false;
			// 
			// label_newvalue2
			// 
			this->label_newvalue2->AutoSize = true;
			this->label_newvalue2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_newvalue2->Location = System::Drawing::Point(364, 218);
			this->label_newvalue2->Name = L"label_newvalue2";
			this->label_newvalue2->Size = System::Drawing::Size(194, 29);
			this->label_newvalue2->TabIndex = 15;
			this->label_newvalue2->Text = L"label_newvalue2";
			this->label_newvalue2->Visible = false;
			// 
			// button_pop
			// 
			this->button_pop->Location = System::Drawing::Point(434, 293);
			this->button_pop->Name = L"button_pop";
			this->button_pop->Size = System::Drawing::Size(124, 43);
			this->button_pop->TabIndex = 16;
			this->button_pop->Text = L"pop";
			this->button_pop->UseVisualStyleBackColor = true;
			this->button_pop->Click += gcnew System::EventHandler(this, &lab5::button_pop_click);
			// 
			// button_get
			// 
			this->button_get->Location = System::Drawing::Point(304, 293);
			this->button_get->Name = L"button_get";
			this->button_get->Size = System::Drawing::Size(124, 43);
			this->button_get->TabIndex = 17;
			this->button_get->Text = L"get";
			this->button_get->UseVisualStyleBackColor = true;
			this->button_get->Click += gcnew System::EventHandler(this, &lab5::button_get_click);
			// 
			// button_save
			// 
			this->button_save->Location = System::Drawing::Point(12, 261);
			this->button_save->Name = L"button_save";
			this->button_save->Size = System::Drawing::Size(124, 43);
			this->button_save->TabIndex = 18;
			this->button_save->Text = L"save";
			this->button_save->UseVisualStyleBackColor = true;
			this->button_save->Click += gcnew System::EventHandler(this, &lab5::button_save_click);
			// 
			// button_find
			// 
			this->button_find->Location = System::Drawing::Point(142, 310);
			this->button_find->Name = L"button_find";
			this->button_find->Size = System::Drawing::Size(124, 43);
			this->button_find->TabIndex = 20;
			this->button_find->Text = L"find";
			this->button_find->UseVisualStyleBackColor = true;
			this->button_find->Click += gcnew System::EventHandler(this, &lab5::button_find_click);
			// 
			// button_savetostack
			// 
			this->button_savetostack->Location = System::Drawing::Point(12, 310);
			this->button_savetostack->Name = L"button_savetostack";
			this->button_savetostack->Size = System::Drawing::Size(124, 43);
			this->button_savetostack->TabIndex = 21;
			this->button_savetostack->Text = L"savetostack";
			this->button_savetostack->UseVisualStyleBackColor = true;
			this->button_savetostack->Click += gcnew System::EventHandler(this, &lab5::button_savetostack_click);
			// 
			// lab10_oop
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(711, 365);
			this->Controls->Add(this->button_savetostack);
			this->Controls->Add(this->button_find);
			this->Controls->Add(this->button_save);
			this->Controls->Add(this->button_get);
			this->Controls->Add(this->button_pop);
			this->Controls->Add(this->label_newvalue2);
			this->Controls->Add(this->label_newvalue1);
			this->Controls->Add(this->text_newvalue2);
			this->Controls->Add(this->text_newvalue1);
			this->Controls->Add(this->button_push);
			this->Controls->Add(this->label_type);
			this->Controls->Add(this->labelCStack);
			this->Controls->Add(this->button_CRectangle);
			this->Controls->Add(this->button_long_long);
			this->Controls->Add(this->button_unsigned_char);
			this->Name = L"lab5_oop";
			this->Text = L"lab5_oop";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button_unsigned_char_click(System::Object^ sender, System::EventArgs^ e) {
		this->label_type->Text = "unsigned char";

		this->label_newvalue1->Visible = true;
		this->text_newvalue1->Visible = true;

		this->label_newvalue2->Visible = false;
		this->text_newvalue2->Visible = false;
	}
	private: System::Void button_long_long_click(System::Object^ sender, System::EventArgs^ e) {
		this->label_type->Text = "long long";

		this->label_newvalue1->Visible = true;
		this->text_newvalue1->Visible = true;

		this->label_newvalue2->Visible = false;
		this->text_newvalue2->Visible = false;
	}
	private: System::Void button_CRectangle_click(System::Object^ sender, System::EventArgs^ e) {
		this->label_type->Text = "CRectangle";

		this->label_newvalue1->Visible = true;
		this->text_newvalue1->Visible = true;

		this->label_newvalue2->Visible = true;
		this->text_newvalue2->Visible = true;
	}
	private: System::Void button_push_click(System::Object^ sender, System::EventArgs^ e) {
		if (this->label_type->Text == "CRectangle") {
			double newvalueA = Convert::ToDouble(text_newvalue1->Text);
			double newvalueB = Convert::ToDouble(text_newvalue2->Text);
			CRectangle newvalue(newvalueA, newvalueB);
			cr.push(newvalue);
		}
		else if (this->label_type->Text == "long long") {
			long long newvalue = Convert::ToInt64(text_newvalue1->Text);
			lo.push(newvalue);
		}
		else if (this->label_type->Text == "unsigned char") {
			char charValue = Convert::ToChar(text_newvalue1->Text);
			unsigned char newValue = static_cast<unsigned char>(charValue);
			un.push(newValue);
		}

	}
	private: System::Void button_get_click(System::Object^ sender, System::EventArgs^ e) {
		if (this->label_type->Text == "CRectangle") {
			std::cout << cr.getn() << "\n";
			cr.get();
			std::cout << savedcr.getn() << "\n";
			savedcr.get();
		}
		else if (this->label_type->Text == "long long") {
			std::cout << "mas long long" << "\n";
			for (int i = 0; i < nlo; i++) {
				std::cout << "index" << i << ": \n"; maslo[i].get();
			}
			std::cout << "current" << "\n";
			lo.get(); std::cout << "\n";
		}
		else if (this->label_type->Text == "unsigned char") {
			std::cout << un.getn() << "\n";
			un.get();
			std::cout << savedun.getn() << "\n";
			savedun.get();
		}
	}
	private: System::Void button_pop_click(System::Object^ sender, System::EventArgs^ e) {
		if (this->label_type->Text == "CRectangle") {
			cr.pop();
		}
		else if (this->label_type->Text == "long long") {
			lo.pop();
		}
		else if (this->label_type->Text == "unsigned char") {
			un.pop();
		}
	}
	private: System::Void button_save_click(System::Object^ sender, System::EventArgs^ e) {
		if (this->label_type->Text == "CRectangle") {
			savedcr = cr;
		}
		else if (this->label_type->Text == "long long") {
			savedlo = lo;
		}
		else if (this->label_type->Text == "unsigned char") {
			savedun = un;
		}
	}

	private: System::Void button_find_click(System::Object^ sender, System::EventArgs^ e) {
		if (this->label_type->Text == "CRectangle") {
			std::cout << "mas CRectangle" << "\n";
			for (int i = 0; i < ncr; i++) {
				std::cout << "index" << i << ": \n"; mascr[i].get();
			}
			std::cout << "tofind" << "\n";
			cr.get(); std::cout << "\n";
			MessageBox::Show("find with index " + FindElementInArray(mascr, ncr, cr), "find", MessageBoxButtons::OK);
		}
		else if (this->label_type->Text == "long long") {
			std::cout << "mas long long" << "\n";
			for (int i = 0; i < nlo; i++) {
				std::cout << "index" << i << ": \n"; maslo[i].get();
			}
			std::cout << "tofind" << "\n";
			lo.get(); std::cout << "\n";
			MessageBox::Show("find with index " + FindElementInArray(maslo, nlo, lo), "find", MessageBoxButtons::OK);
		}
		else if (this->label_type->Text == "unsigned char") {
			std::cout << "mas unsigned char" << "\n";
			for (int i = 0; i < nun; i++) {
				std::cout << "index" << i << ": \n"; masun[i].get();
			}
			std::cout << "tofind" << "\n";
			un.get(); std::cout << "\n";
			MessageBox::Show("find with index " + FindElementInArray(masun, nun, un), "find", MessageBoxButtons::OK);
		}
	}
	private: System::Void text_newvalue1_TextChanged(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void button_savetostack_click(System::Object^ sender, System::EventArgs^ e) {
		if (this->label_type->Text == "CRectangle") {
			ncr++;
			CStack<CRectangle>* masnew = new CStack<CRectangle>[ncr];
			for (int i = 0; i < ncr - 1; i++) {
				masnew[i] = mascr[i];
			}
			masnew[ncr - 1] = savedcr;
			mascr = masnew;
		}
		else if (this->label_type->Text == "long long") {
			nlo++;
			CStack<long long>* masnew = new CStack<long long>[nlo];
			for (int i = 0; i < nlo - 1; i++) {
				masnew[i] = maslo[i];
			}
			masnew[nlo - 1] = savedlo;
			maslo = masnew;
		}
		else if (this->label_type->Text == "unsigned char") {
			nun++;
			CStack<unsigned char>* masnew = new CStack<unsigned char>[nun];
			for (int i = 0; i < nun - 1; i++) {
				masnew[i] = masun[i];
			}
			masnew[nun - 1] = savedun;
			masun = masnew;
		}
	}
	};
}
