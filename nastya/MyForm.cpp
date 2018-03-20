#include "MyForm.h"



using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]
void Main(array<String^>^ args) {
	setlocale(LC_ALL, "Russian");
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	nastya::MyForm form;
	Application::Run(%form);
}