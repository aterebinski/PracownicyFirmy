#include "PracownicyForm.h"
using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void Main(array<String^>^ args)

{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	PracownicyFirmy::PracownicyForm form;
	Application::Run(% form);
}
