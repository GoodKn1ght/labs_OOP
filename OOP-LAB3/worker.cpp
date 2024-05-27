#include"lab3_oop.h"



System::Void lab3oop::lab3_oop::menuStrip1_ItemClicked(System::Object^ sender, System::Windows::Forms::ToolStripItemClickedEventArgs^ e) {
}
System::Void lab3oop::lab3_oop::button_fill_click(System::Object^ sender, System::EventArgs^ e) {
	int r = this->tablepanel->RowCount;
	int c = this->tablepanel->ColumnCount;
	this->tablepanel->RowCount = 0;
	this->tablepanel->ColumnCount = 0;
	int i = 0;
	Int32::TryParse(this->textRows->Text, i);
	int j = 0;
	Int32::TryParse(this->textColums->Text, j);
	if (i == 0 || j == 0) {
		MessageBox::Show("Invalid row or column count.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
	this->tablepanel->RowCount = i;
	this->tablepanel->ColumnCount = j;
	double sizeR = (double)(100.0f / i);
	double sizeC = (double)(100.0f / j);
	int k1 = 0, k2 = 0;
	while (k1 < r) {
		tablepanel->RowStyles[k1] = gcnew RowStyle(SizeType::Percent, sizeR);
		k1++;
	}
	while (k2 < c) {
		tablepanel->ColumnStyles[k2] = gcnew ColumnStyle(SizeType::Percent, sizeC);
		k2++;
	}
	for (int k = k1; k < i; k++) {
		this->tablepanel->RowStyles->Add(gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, sizeR));
	}
	for (int k = k2; k < j; k++) {
		this->tablepanel->ColumnStyles->Add(gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, sizeC));
	}
}

System::Void lab3oop::lab3_oop::FillTableWithZeros() {
	this->tablepanel->Controls->Clear();
	int rowCount = this->tablepanel->RowCount;
	int columnCount = this->tablepanel->ColumnCount;
	int k = 0;
	int i1 = 0;
	int j1 = columnCount - 1;
	int l = 0;
	while (k < (rowCount - 1) / 2) {
		i1 = (rowCount / 2) - l - 1;
		j1 = (columnCount / 2) + l + 1;
		while (j1 < columnCount) {
			Label^ label = gcnew Label();
			label->Font = gcnew System::Drawing::Font(label->Font->FontFamily, 26, FontStyle::Bold);
			label->AutoEllipsis = false;
			label->AutoSize = false;
			label->Dock = DockStyle::Fill;
			label->TextAlign = ContentAlignment::MiddleCenter;
			label->Text = "0";
			this->tablepanel->Controls->Add(label, i1, k);
			if (i1 != j1) {
				Label^ label1 = gcnew Label();
				label1->Font = gcnew System::Drawing::Font(label->Font->FontFamily, 26, FontStyle::Bold);
				label1->AutoEllipsis = false;
				label1->AutoSize = false;
				label1->Dock = DockStyle::Fill;
				label1->TextAlign = ContentAlignment::MiddleCenter;
				label1->Text = "0";
				this->tablepanel->Controls->Add(label1, j1, k);
			}
			i1--;
			j1++;
		}
		l++;
		k++;
	}
	j1--; i1++;
	k++;
	int i2 = i1, j2 = j1;
	while (k < columnCount) {
		l = k;
		i1 = i2;
		j1 = j2;
		while (l > (rowCount - 1) / 2) {
			Label^ label = gcnew Label();
			label->Font = gcnew System::Drawing::Font(label->Font->FontFamily, 26, FontStyle::Bold);
			label->AutoEllipsis = false;
			label->AutoSize = false;       label->Dock = DockStyle::Fill;
			label->TextAlign = ContentAlignment::MiddleCenter;       label->Text = "0";
			this->tablepanel->Controls->Add(label, i1, k);
			if (i1 != j1) {
				Label^ label1 = gcnew Label();
				label1->Font = gcnew System::Drawing::Font(label->Font->FontFamily, 26, FontStyle::Bold);
				label1->AutoEllipsis = false;
				label1->AutoSize = false;
				label1->Dock = DockStyle::Fill;
				label1->TextAlign = ContentAlignment::MiddleCenter;
				label1->Text = "0";
				this->tablepanel->Controls->Add(label1, j1, k);
			}
			else break;
			i1++;
			j1--;
			l--;
		}
		k++;
	}
	for (int i = 0; i < rowCount; i++) {
		for (int j = 0; j < columnCount; j++) {
			Control^ control = tablepanel->GetControlFromPosition(i, j);
			if (control == nullptr) {
				Label^ label = gcnew Label();
				label->Font = gcnew System::Drawing::Font(label->Font->FontFamily, 26, FontStyle::Bold);
				label->AutoEllipsis = false;
				label->AutoSize = false;
				label->Dock = DockStyle::Fill;
				label->TextAlign = ContentAlignment::MiddleCenter;
				label->Text = "1";
				this->tablepanel->Controls->Add(label, i, j);
			}
		}
	}
}




System::Void lab3oop::lab3_oop::button_setvalue_Click(System::Object^ sender, System::EventArgs^ e) {
	int i = 0;
	Int32::TryParse(this->texti->Text, i);
	int j = 0;
	Int32::TryParse(this->textj->Text, j);
	if (i < this->tablepanel->RowCount && tablepanel->ColumnCount > j && j >= 0 && i >= 0) {
		Control^ control = this->tablepanel->GetControlFromPosition(j, i);
		if (control != nullptr) {
			this->tablepanel->Controls->Remove(control);
		}
		Label^ label = gcnew Label();
		label->Font = gcnew System::Drawing::Font(label->Font->FontFamily, 26, FontStyle::Bold);
		label->AutoEllipsis = false;
		label->AutoSize = false;
		label->Dock = DockStyle::Fill;
		label->TextAlign = ContentAlignment::MiddleCenter;
		label->Text = this->textNewvalue->Text;
		this->tablepanel->Controls->Add(label, j, i);
	}
	else MessageBox::Show("Invalid row or column index.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
}
System::Void lab3oop::lab3_oop::button_clear_click(System::Object^ sender, System::EventArgs^ e) {
	this->tablepanel->Controls->Clear();
}
System::Void lab3oop::lab3_oop::button_getvalue_click(System::Object^ sender, System::EventArgs^ e) {
	String^ str = "";
	int i = 0;
	Int32::TryParse(this->texti->Text, i);
	int j = 0;
	Int32::TryParse(this->textj->Text, j);

	Control^ control = tablepanel->GetControlFromPosition(j, i);

	if (control != nullptr) {
		str = control->Text;
		MessageBox::Show("Your value is " + str, "Get value", MessageBoxButtons::OK);
	}
	else {
		MessageBox::Show("Nothink", "Get value", MessageBoxButtons::OK);
	}
}
System::Void lab3oop::lab3_oop::fillToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	button_fill_click(sender, e);
}
System::Void lab3oop::lab3_oop::getValueToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	button_getvalue_click(sender, e);
}
System::Void lab3oop::lab3_oop::setValueToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	button_setvalue_Click(sender, e);
}
System::Void lab3oop::lab3_oop::clearToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	button_clear_click(sender, e);
}
System::Void lab3oop::lab3_oop::exitToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	this->~lab3_oop();
}
System::Void lab3oop::lab3_oop::readToolStripMenuItem_click(System::Object^ sender, System::EventArgs^ e) {
	if (openFileDialog2->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		this->tablepanel->Controls->Clear();
		// Отримуємо шлях вибраного файлу
		String^ selectedFileName = openFileDialog2->FileName;

		StreamReader^ reader = gcnew StreamReader(selectedFileName);

		// Зчитуємо вміст файлу по рядках і виводимо їх на консоль
		String^ line = reader->ReadLine();
		int r = this->tablepanel->RowCount;
		int c = this->tablepanel->ColumnCount;
		this->tablepanel->RowCount = 0;
		this->tablepanel->ColumnCount = 0;

		int i = 0;
		Int32::TryParse(line, i);
		int j = i;
		if (i == 0 || j == 0) {
			MessageBox::Show("Invalid row or column count.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		this->tablepanel->RowCount = i;
		this->tablepanel->ColumnCount = j;
		double sizeR = (double)(100.0f / i);
		double sizeC = (double)(100.0f / j);
		int k1 = 0, k2 = 0;
		while (k1 < r) {
			tablepanel->RowStyles[k1] = gcnew RowStyle(SizeType::Percent, sizeR);
			k1++;
		}
		while (k2 < c) {
			tablepanel->ColumnStyles[k2] = gcnew ColumnStyle(SizeType::Percent, sizeC);
			k2++;
		}
		for (int k = k1; k < i; k++) {
			this->tablepanel->RowStyles->Add(gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, sizeR));
		}
		for (int k = k2; k < j; k++) {
			this->tablepanel->ColumnStyles->Add(gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, sizeC));
		}
		int i1 = 0, j1 = 0;
		while ((line = reader->ReadLine()) != nullptr) {
			Label^ label = gcnew Label();
			label->Font = gcnew System::Drawing::Font(label->Font->FontFamily, 26, FontStyle::Bold);
			label->AutoEllipsis = false;
			label->AutoSize = false;
			label->Dock = DockStyle::Fill;
			label->TextAlign = ContentAlignment::MiddleCenter;
			label->Text = line;
			this->tablepanel->Controls->Add(label, j1, i1);
			j1++;
			if (j1 == i) {
				i1++;
				j1 = 0;
			}
		}
		reader->Close();
	}

}
System::Void lab3oop::lab3_oop::writeToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {

		String^ selectedFileName = saveFileDialog1->FileName;

		StreamWriter^ writer = gcnew StreamWriter(selectedFileName);

		writer->WriteLine(this->tablepanel->RowCount.ToString());

		for (int i = 0; i < this->tablepanel->RowCount; i++) {
			for (int j = 0; j < this->tablepanel->ColumnCount; j++) {
				Control^ control = this->tablepanel->GetControlFromPosition(j, i);
				if (control != nullptr) {
					writer->WriteLine(control->Text);
				}
			}
		}

		writer->Close();
	}
}
System::Void lab3oop::lab3_oop::setZeroes_click(System::Object^ sender, System::EventArgs^ e) {
	if (this->tablepanel->RowCount % 2 != 0 && this->tablepanel->ColumnCount % 2 != 0) {
		FillTableWithZeros();
	}
	else MessageBox::Show("Invalid row or column index.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
}