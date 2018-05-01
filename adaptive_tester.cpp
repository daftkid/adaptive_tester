// adaptive_tester.cpp : main project file.

#include "stdafx.h"
#include "StartForm.h"

using namespace adaptive_tester;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Create the main window and run it
	Application::Run(gcnew StartForm());
	return 0;
}
