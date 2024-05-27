#include "lab3_oop.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]

int main() {
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	lab3oop::lab3_oop form;
	Application::Run(% form); 

	return 0;
}
