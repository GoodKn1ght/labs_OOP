#pragma once
#include <cstdlib>
#include <string.h>
#include <msclr\marshal_cppstd.h>
#include <iostream>


using namespace System::IO;
using namespace msclr::interop;

namespace lab3oop {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for lab6_oop
	/// </summary>
	public ref class lab3_oop : public System::Windows::Forms::Form
	{
	public:
		lab3_oop(void)
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
		~lab3_oop()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^ fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ tableToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ helpToolStripMenuItem;
	private: System::Windows::Forms::SplitContainer^ splitContainer1;
	private: System::Windows::Forms::Button^ button_fill;
	private: System::Windows::Forms::Button^ button_clear;
	private: System::Windows::Forms::TextBox^ texti;

	private: System::Windows::Forms::Label^ labelj;

	private: System::Windows::Forms::Label^ labeli;
	private: System::Windows::Forms::Label^ labelColums;
	private: System::Windows::Forms::Label^ labelRows;
	private: System::Windows::Forms::TextBox^ textColums;
	private: System::Windows::Forms::TextBox^ textRows;
	private: System::Windows::Forms::TextBox^ textj;
	private: System::Windows::Forms::Button^ button_getvalue;
	private: System::Windows::Forms::Button^ button_setvalue;
	private: System::Windows::Forms::TextBox^ textNewvalue;
	private: System::Windows::Forms::Label^ label_newvalue;
	private: System::Windows::Forms::Label^ label_valueis;
	private: System::Windows::Forms::TableLayoutPanel^ tablepanel;
	private: System::Windows::Forms::ToolStripMenuItem^ readToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ writeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ exitToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ fillToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ getValueToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ setValueToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ clearToolStripMenuItem;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog2;
	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog1;
	private: System::Windows::Forms::ToolStripMenuItem^ setZeroes;
	private: System::Windows::Forms::ContextMenuStrip^ contextMenuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ fillToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ clearToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ setZeroesToolStripMenuItem;
	private: System::ComponentModel::IContainer^ components;










	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->readToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->writeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tableToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->fillToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->getValueToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->setValueToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->clearToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->setZeroes = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->fillToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->clearToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->setZeroesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tablepanel = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->button_getvalue = (gcnew System::Windows::Forms::Button());
			this->button_setvalue = (gcnew System::Windows::Forms::Button());
			this->textNewvalue = (gcnew System::Windows::Forms::TextBox());
			this->label_newvalue = (gcnew System::Windows::Forms::Label());
			this->label_valueis = (gcnew System::Windows::Forms::Label());
			this->textj = (gcnew System::Windows::Forms::TextBox());
			this->texti = (gcnew System::Windows::Forms::TextBox());
			this->labelj = (gcnew System::Windows::Forms::Label());
			this->labeli = (gcnew System::Windows::Forms::Label());
			this->labelColums = (gcnew System::Windows::Forms::Label());
			this->labelRows = (gcnew System::Windows::Forms::Label());
			this->textColums = (gcnew System::Windows::Forms::TextBox());
			this->textRows = (gcnew System::Windows::Forms::TextBox());
			this->button_clear = (gcnew System::Windows::Forms::Button());
			this->button_fill = (gcnew System::Windows::Forms::Button());
			this->openFileDialog2 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->BeginInit();
			this->splitContainer1->Panel1->SuspendLayout();
			this->splitContainer1->Panel2->SuspendLayout();
			this->splitContainer1->SuspendLayout();
			this->contextMenuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->fileToolStripMenuItem,
					this->tableToolStripMenuItem, this->helpToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(776, 28);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			this->menuStrip1->ItemClicked += gcnew System::Windows::Forms::ToolStripItemClickedEventHandler(this, &lab3_oop::menuStrip1_ItemClicked);
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->readToolStripMenuItem,
					this->writeToolStripMenuItem, this->exitToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(46, 24);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// readToolStripMenuItem
			// 
			this->readToolStripMenuItem->Name = L"readToolStripMenuItem";
			this->readToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::R));
			this->readToolStripMenuItem->Size = System::Drawing::Size(184, 26);
			this->readToolStripMenuItem->Text = L"Read";
			this->readToolStripMenuItem->Click += gcnew System::EventHandler(this, &lab3_oop::readToolStripMenuItem_click);
			// 
			// writeToolStripMenuItem
			// 
			this->writeToolStripMenuItem->Name = L"writeToolStripMenuItem";
			this->writeToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::W));
			this->writeToolStripMenuItem->Size = System::Drawing::Size(184, 26);
			this->writeToolStripMenuItem->Text = L"Write";
			this->writeToolStripMenuItem->Click += gcnew System::EventHandler(this, &lab3_oop::writeToolStripMenuItem_Click);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Alt | System::Windows::Forms::Keys::F4));
			this->exitToolStripMenuItem->Size = System::Drawing::Size(184, 26);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &lab3_oop::exitToolStripMenuItem_Click);
			// 
			// tableToolStripMenuItem
			// 
			this->tableToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->fillToolStripMenuItem,
					this->getValueToolStripMenuItem, this->setValueToolStripMenuItem, this->clearToolStripMenuItem
			});
			this->tableToolStripMenuItem->Name = L"tableToolStripMenuItem";
			this->tableToolStripMenuItem->Size = System::Drawing::Size(58, 24);
			this->tableToolStripMenuItem->Text = L"Table";
			// 
			// fillToolStripMenuItem
			// 
			this->fillToolStripMenuItem->Name = L"fillToolStripMenuItem";
			this->fillToolStripMenuItem->Size = System::Drawing::Size(154, 26);
			this->fillToolStripMenuItem->Text = L"Fill";
			this->fillToolStripMenuItem->Click += gcnew System::EventHandler(this, &lab3_oop::fillToolStripMenuItem_Click);
			// 
			// getValueToolStripMenuItem
			// 
			this->getValueToolStripMenuItem->Name = L"getValueToolStripMenuItem";
			this->getValueToolStripMenuItem->Size = System::Drawing::Size(154, 26);
			this->getValueToolStripMenuItem->Text = L"Get value";
			this->getValueToolStripMenuItem->Click += gcnew System::EventHandler(this, &lab3_oop::getValueToolStripMenuItem_Click);
			// 
			// setValueToolStripMenuItem
			// 
			this->setValueToolStripMenuItem->Name = L"setValueToolStripMenuItem";
			this->setValueToolStripMenuItem->Size = System::Drawing::Size(154, 26);
			this->setValueToolStripMenuItem->Text = L"Set value";
			this->setValueToolStripMenuItem->Click += gcnew System::EventHandler(this, &lab3_oop::setValueToolStripMenuItem_Click);
			// 
			// clearToolStripMenuItem
			// 
			this->clearToolStripMenuItem->Name = L"clearToolStripMenuItem";
			this->clearToolStripMenuItem->Size = System::Drawing::Size(154, 26);
			this->clearToolStripMenuItem->Text = L"Clear";
			this->clearToolStripMenuItem->Click += gcnew System::EventHandler(this, &lab3_oop::clearToolStripMenuItem_Click);
			// 
			// helpToolStripMenuItem
			// 
			this->helpToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->setZeroes });
			this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
			this->helpToolStripMenuItem->Size = System::Drawing::Size(55, 24);
			this->helpToolStripMenuItem->Text = L"Help";
			// 
			// setZeroes
			// 
			this->setZeroes->Name = L"setZeroes";
			this->setZeroes->Size = System::Drawing::Size(158, 26);
			this->setZeroes->Text = L"set zeroes";
			this->setZeroes->Click += gcnew System::EventHandler(this, &lab3_oop::setZeroes_click);
			// 
			// splitContainer1
			// 
			this->splitContainer1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer1->Location = System::Drawing::Point(0, 0);
			this->splitContainer1->Name = L"splitContainer1";
			// 
			// splitContainer1.Panel1
			// 
			this->splitContainer1->Panel1->ContextMenuStrip = this->contextMenuStrip1;
			this->splitContainer1->Panel1->Controls->Add(this->tablepanel);
			// 
			// splitContainer1.Panel2
			// 
			this->splitContainer1->Panel2->Controls->Add(this->button_getvalue);
			this->splitContainer1->Panel2->Controls->Add(this->button_setvalue);
			this->splitContainer1->Panel2->Controls->Add(this->textNewvalue);
			this->splitContainer1->Panel2->Controls->Add(this->label_newvalue);
			this->splitContainer1->Panel2->Controls->Add(this->label_valueis);
			this->splitContainer1->Panel2->Controls->Add(this->textj);
			this->splitContainer1->Panel2->Controls->Add(this->texti);
			this->splitContainer1->Panel2->Controls->Add(this->labelj);
			this->splitContainer1->Panel2->Controls->Add(this->labeli);
			this->splitContainer1->Panel2->Controls->Add(this->labelColums);
			this->splitContainer1->Panel2->Controls->Add(this->labelRows);
			this->splitContainer1->Panel2->Controls->Add(this->textColums);
			this->splitContainer1->Panel2->Controls->Add(this->textRows);
			this->splitContainer1->Panel2->Controls->Add(this->button_clear);
			this->splitContainer1->Panel2->Controls->Add(this->button_fill);
			this->splitContainer1->Size = System::Drawing::Size(776, 442);
			this->splitContainer1->SplitterDistance = 504;
			this->splitContainer1->TabIndex = 1;
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->ImageScalingSize = System::Drawing::Size(30, 20);
			this->contextMenuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->fillToolStripMenuItem1,
					this->clearToolStripMenuItem1, this->setZeroesToolStripMenuItem
			});
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(147, 76);
			// 
			// fillToolStripMenuItem1
			// 
			this->fillToolStripMenuItem1->Name = L"fillToolStripMenuItem1";
			this->fillToolStripMenuItem1->Size = System::Drawing::Size(146, 24);
			this->fillToolStripMenuItem1->Text = L"Fill";
			this->fillToolStripMenuItem1->Click += gcnew System::EventHandler(this, &lab3_oop::fillToolStripMenuItem1_Click);
			// 
			// clearToolStripMenuItem1
			// 
			this->clearToolStripMenuItem1->Name = L"clearToolStripMenuItem1";
			this->clearToolStripMenuItem1->Size = System::Drawing::Size(146, 24);
			this->clearToolStripMenuItem1->Text = L"Clear";
			this->clearToolStripMenuItem1->Click += gcnew System::EventHandler(this, &lab3_oop::clearToolStripMenuItem1_Click);
			// 
			// setZeroesToolStripMenuItem
			// 
			this->setZeroesToolStripMenuItem->Name = L"setZeroesToolStripMenuItem";
			this->setZeroesToolStripMenuItem->Size = System::Drawing::Size(146, 24);
			this->setZeroesToolStripMenuItem->Text = L"Set zeroes";
			this->setZeroesToolStripMenuItem->Click += gcnew System::EventHandler(this, &lab3_oop::setZeroesToolStripMenuItem_Click);
			// 
			// tablepanel
			// 
			this->tablepanel->CellBorderStyle = System::Windows::Forms::TableLayoutPanelCellBorderStyle::Inset;
			this->tablepanel->ColumnCount = 2;
			this->tablepanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tablepanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tablepanel->ContextMenuStrip = this->contextMenuStrip1;
			this->tablepanel->Location = System::Drawing::Point(105, 105);
			this->tablepanel->Name = L"tablepanel";
			this->tablepanel->RowCount = 2;
			this->tablepanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tablepanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tablepanel->Size = System::Drawing::Size(309, 251);
			this->tablepanel->TabIndex = 0;
			// 
			// button_getvalue
			// 
			this->button_getvalue->BackColor = System::Drawing::SystemColors::ControlDark;
			this->button_getvalue->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button_getvalue->Location = System::Drawing::Point(151, 323);
			this->button_getvalue->Name = L"button_getvalue";
			this->button_getvalue->Size = System::Drawing::Size(92, 33);
			this->button_getvalue->TabIndex = 14;
			this->button_getvalue->Text = L"Get value";
			this->button_getvalue->UseVisualStyleBackColor = false;
			this->button_getvalue->Click += gcnew System::EventHandler(this, &lab3_oop::button_getvalue_click);
			// 
			// button_setvalue
			// 
			this->button_setvalue->BackColor = System::Drawing::SystemColors::ControlDark;
			this->button_setvalue->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button_setvalue->Location = System::Drawing::Point(28, 323);
			this->button_setvalue->Name = L"button_setvalue";
			this->button_setvalue->Size = System::Drawing::Size(92, 33);
			this->button_setvalue->TabIndex = 13;
			this->button_setvalue->Text = L"Set value";
			this->button_setvalue->UseVisualStyleBackColor = false;
			this->button_setvalue->Click += gcnew System::EventHandler(this, &lab3_oop::button_setvalue_Click);
			// 
			// textNewvalue
			// 
			this->textNewvalue->Location = System::Drawing::Point(98, 261);
			this->textNewvalue->Name = L"textNewvalue";
			this->textNewvalue->Size = System::Drawing::Size(91, 22);
			this->textNewvalue->TabIndex = 12;
			// 
			// label_newvalue
			// 
			this->label_newvalue->AutoSize = true;
			this->label_newvalue->Location = System::Drawing::Point(25, 264);
			this->label_newvalue->Name = L"label_newvalue";
			this->label_newvalue->Size = System::Drawing::Size(67, 16);
			this->label_newvalue->TabIndex = 11;
			this->label_newvalue->Text = L"new value";
			// 
			// label_valueis
			// 
			this->label_valueis->AutoSize = true;
			this->label_valueis->Location = System::Drawing::Point(195, 190);
			this->label_valueis->Name = L"label_valueis";
			this->label_valueis->Size = System::Drawing::Size(53, 16);
			this->label_valueis->TabIndex = 10;
			this->label_valueis->Text = L"value is";
			// 
			// textj
			// 
			this->textj->Location = System::Drawing::Point(146, 187);
			this->textj->Name = L"textj";
			this->textj->Size = System::Drawing::Size(43, 22);
			this->textj->TabIndex = 9;
			// 
			// texti
			// 
			this->texti->Location = System::Drawing::Point(50, 187);
			this->texti->Name = L"texti";
			this->texti->Size = System::Drawing::Size(43, 22);
			this->texti->TabIndex = 8;
			// 
			// labelj
			// 
			this->labelj->AutoSize = true;
			this->labelj->Location = System::Drawing::Point(117, 190);
			this->labelj->Name = L"labelj";
			this->labelj->Size = System::Drawing::Size(23, 16);
			this->labelj->TabIndex = 7;
			this->labelj->Text = L"j = ";
			// 
			// labeli
			// 
			this->labeli->AutoSize = true;
			this->labeli->Location = System::Drawing::Point(25, 190);
			this->labeli->Name = L"labeli";
			this->labeli->Size = System::Drawing::Size(23, 16);
			this->labeli->TabIndex = 6;
			this->labeli->Text = L"i = ";
			// 
			// labelColums
			// 
			this->labelColums->AutoSize = true;
			this->labelColums->Location = System::Drawing::Point(170, 61);
			this->labelColums->Name = L"labelColums";
			this->labelColums->Size = System::Drawing::Size(52, 16);
			this->labelColums->TabIndex = 5;
			this->labelColums->Text = L"Colums";
			// 
			// labelRows
			// 
			this->labelRows->AutoSize = true;
			this->labelRows->Location = System::Drawing::Point(52, 61);
			this->labelRows->Name = L"labelRows";
			this->labelRows->Size = System::Drawing::Size(41, 16);
			this->labelRows->TabIndex = 4;
			this->labelRows->Text = L"Rows";
			// 
			// textColums
			// 
			this->textColums->Location = System::Drawing::Point(151, 80);
			this->textColums->Name = L"textColums";
			this->textColums->Size = System::Drawing::Size(92, 22);
			this->textColums->TabIndex = 1;
			// 
			// textRows
			// 
			this->textRows->Location = System::Drawing::Point(28, 80);
			this->textRows->Name = L"textRows";
			this->textRows->Size = System::Drawing::Size(92, 22);
			this->textRows->TabIndex = 0;
			this->textRows->TextChanged += gcnew System::EventHandler(this, &lab3_oop::textRows_TextChanged);
			// 
			// button_clear
			// 
			this->button_clear->BackColor = System::Drawing::SystemColors::ControlDark;
			this->button_clear->FlatAppearance->BorderColor = System::Drawing::SystemColors::ControlDarkDark;
			this->button_clear->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button_clear->Location = System::Drawing::Point(151, 115);
			this->button_clear->Name = L"button_clear";
			this->button_clear->Size = System::Drawing::Size(92, 33);
			this->button_clear->TabIndex = 3;
			this->button_clear->Text = L"Clear";
			this->button_clear->UseVisualStyleBackColor = false;
			this->button_clear->Click += gcnew System::EventHandler(this, &lab3_oop::button_clear_click);
			// 
			// button_fill
			// 
			this->button_fill->BackColor = System::Drawing::SystemColors::ControlDark;
			this->button_fill->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button_fill->Location = System::Drawing::Point(28, 115);
			this->button_fill->Name = L"button_fill";
			this->button_fill->Size = System::Drawing::Size(92, 33);
			this->button_fill->TabIndex = 2;
			this->button_fill->Text = L"Fill";
			this->button_fill->UseVisualStyleBackColor = false;
			this->button_fill->Click += gcnew System::EventHandler(this, &lab3_oop::button_fill_click);
			// 
			// openFileDialog2
			// 
			this->openFileDialog2->FileName = L"openFileDialog2";
			this->openFileDialog2->Filter = L"\"Text files (*.txt)|*.txt|All files (*.*)|*.*\"";
			// 
			// lab3_oop
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->ClientSize = System::Drawing::Size(776, 442);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->splitContainer1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"lab3_oop";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"lab3_oop";
			this->Load += gcnew System::EventHandler(this, &lab3_oop::lab3_oop_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->splitContainer1->Panel1->ResumeLayout(false);
			this->splitContainer1->Panel2->ResumeLayout(false);
			this->splitContainer1->Panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->EndInit();
			this->splitContainer1->ResumeLayout(false);
			this->contextMenuStrip1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private:System::Void menuStrip1_ItemClicked(System::Object^ sender, System::Windows::Forms::ToolStripItemClickedEventArgs^ e);
		System::Void button_fill_click(System::Object^ sender, System::EventArgs^ e);

		System::Void FillTableWithZeros();



		System::Void button_setvalue_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void button_clear_click(System::Object^ sender, System::EventArgs^ e);
		System::Void button_getvalue_click(System::Object^ sender, System::EventArgs^ e);
		System::Void fillToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void getValueToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void setValueToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void clearToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void exitToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void readToolStripMenuItem_click(System::Object^ sender, System::EventArgs^ e);
		System::Void writeToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);



		System::Void setZeroes_click(System::Object^ sender, System::EventArgs^ e);



private: System::Void fillToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e) {
	button_fill_click(sender, e);
}
private: System::Void clearToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e) {
	button_clear_click(sender, e);
}
private: System::Void setZeroesToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	FillTableWithZeros();
}
private: System::Void textRows_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void lab3_oop_Load(System::Object^ sender, System::EventArgs^ e) {
}
};
}
