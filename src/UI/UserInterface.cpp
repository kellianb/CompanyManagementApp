#include "UserInterface.h"

using namespace System;
using namespace System::Windows::Forms;


[STAThreadAttribute]
int __clrcall main(array<String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Projet::UserInterface monFormulaire;
    Application::Run(%monFormulaire);

    return 0;
}
