#include"MyForm.h"
using namespace System; using namespace System::Windows::Forms;
[STAThreadAttribute]
int main() {
	Application::SetCompatibleTextRenderingDefault(false); Application::EnableVisualStyles();
	lab5::lab5 form; Application::Run(% form);
	return 0;
}