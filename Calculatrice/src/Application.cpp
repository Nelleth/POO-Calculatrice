#include "../headers/Application.hpp"

IMPLEMENT_APP(Application);

bool Application::OnInit(){
        wxSize default_size(550,500);
        myWindow=new Display(_T("SC - 3000"),wxDefaultPosition, default_size);
	myWindow->Show();
        return true; // Permet de garder le programme actif
}
