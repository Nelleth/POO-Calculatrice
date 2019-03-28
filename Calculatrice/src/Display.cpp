#include "../headers/Display.hpp"
#include "../headers/Stack.hpp"
#include "../headers/Operations.hpp"

// Construction de l'objet par déclaration de la stack
stack <float> argt;
// Création de l'objet stack_1
Stack stack_1(argt);

Display::~Display() {}
Display::Display(const wxString title,const wxPoint& pos, const wxSize& size) : wxFrame(NULL,wxID_ANY,title,pos,size){


	sizer_principal = new wxBoxSizer(wxVERTICAL);
 
	txtCalcInput = new wxTextCtrl(this, ID_TXT_CALCINPUT, wxT(""), wxPoint(-1, -1), wxSize(-1, -1), wxTE_RIGHT);
	txtCalcInput->SetEditable(false); //On protège la zone d'affichage


        sizer_principal->Add(txtCalcInput, 0, wxEXPAND | wxTOP | wxBOTTOM, 4); // zone affichage

        gridButton = new wxGridSizer(5, 5, 5, 5); // Création d'une matrice 5 lignes 5 colonnes, espacement de 5

/* //////////////////////////////////////////////////// LIGNE 1 \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ */

        btnMclear = new wxButton(this, ID_BTN_MCLEAR, _T("MC")); // bouton MCLEAR
	btnMclear->Disable();
        btnMplus = new wxButton(this, ID_BTN_MPLUS, _T("M+")); // bouton MPLUS,
        btnMr = new wxButton(this, ID_BTN_MR, _T("MR")); // bouton MR
	btnMr->Disable();
	btnDel = new wxButton(this, ID_BTN_DEL, _T("DEL")); // bouton DEL
	btnAc = new wxButton(this, ID_BTN_AC, _T("RST")); // bouton RST

	btnDel->SetBackgroundColour(wxColour(255,175,0,255));
	btnAc->SetBackgroundColour(wxColour(255,175,0,255));

	gridButton->Add(btnMclear,0,wxEXPAND);
	gridButton->Add(btnMplus,0,wxEXPAND);
	gridButton->Add(btnMr,0,wxEXPAND);
	gridButton->Add(btnDel,0,wxEXPAND);
	gridButton->Add(btnAc,0,wxEXPAND);

/* //////////////////////////////////////////////////// LIGNE 2 \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ */

	btn7 = new wxButton(this, ID_BTN_7, _T("7")); // bouton 7
	btn8 = new wxButton(this, ID_BTN_8, _T("8")); // bouton 8
	btn9 = new wxButton(this, ID_BTN_9, _T("9")); // bouton 9
        btnModulo = new wxButton(this, ID_BTN_MODULO, _T("%")); // bouton modulo
        btnPuiss = new wxButton(this, ID_BTN_PUISS, _T("Puiss")); // bouton puissance
	
	btnMclear->SetBackgroundColour(wxColour(0,0,0,20));
	btnMplus->SetBackgroundColour(wxColour(0,0,0,15));
	btnMr->SetBackgroundColour(wxColour(0,0,0,15));
	btnModulo->SetBackgroundColour(wxColour(0,255,255,255));
	btnPuiss->SetBackgroundColour(wxColour(0,255,255,255));

	gridButton->Add(btn7,0,wxEXPAND);
	gridButton->Add(btn8,0,wxEXPAND);
	gridButton->Add(btn9,0,wxEXPAND);
	gridButton->Add(btnPuiss,0,wxEXPAND);
	gridButton->Add(btnModulo,0,wxEXPAND);

/* //////////////////////////////////////////////////// LIGNE 3 \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ */

        btn4 = new wxButton(this, ID_BTN_4, _T("4")); // bouton 4
        btn5 = new wxButton(this, ID_BTN_5, _T("5")); // bouton 5
        btn6 = new wxButton(this, ID_BTN_6, _T("6")); // bouton 6
        btnX = new wxButton(this, ID_BTN_X, _T("X")); // bouton multiplier
        btnDiv = new wxButton(this, ID_BTN_DIV, _T("/")); //  bouton diviser


	btnX->SetBackgroundColour(wxColour(0,255,255,255));
	btnDiv->SetBackgroundColour(wxColour(0,255,255,255));

	gridButton->Add(btn4,0,wxEXPAND);
	gridButton->Add(btn5,0,wxEXPAND);
	gridButton->Add(btn6,0,wxEXPAND);
	gridButton->Add(btnX,0,wxEXPAND);
	gridButton->Add(btnDiv,0,wxEXPAND);

/* //////////////////////////////////////////////////// LIGNE 4 \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ */

	btn1 = new wxButton(this, ID_BTN_1, _T("1")); // bouton 1
	btn2 = new wxButton(this, ID_BTN_2, _T("2")); // bouton 2
	btn3 = new wxButton(this, ID_BTN_3, _T("3")); // bouton 3
	btnPlus = new wxButton(this, ID_BTN_PLUS, _T("+")); // bouton plus
	btnMoins = new wxButton(this, ID_BTN_MOINS, _T("_")); // bouton moins

	btnPlus->SetBackgroundColour(wxColour(0,255,255,255));
	btnMoins->SetBackgroundColour(wxColour(0,255,255,255));

	gridButton->Add(btn1,0,wxEXPAND);
	gridButton->Add(btn2,0,wxEXPAND);
	gridButton->Add(btn3,0,wxEXPAND);
	gridButton->Add(btnPlus,0,wxEXPAND);
	gridButton->Add(btnMoins,0,wxEXPAND);

/* //////////////////////////////////////////////////// LIGNE 5 \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ */

	btnPi = new wxButton(this, ID_BTN_PI, wxString::FromUTF8("\xF0\x9D\x9B\x91")); // bouton Pi
	btn0 = new wxButton(this, ID_BTN_0, _T("0")); // bouton zero
	btnPoint = new wxButton(this, ID_BTN_POINT, _T(".")); // bouton point
        btnEnter = new wxButton(this, ID_BTN_ENTER, _T("ENTER")); // bouton enter
	btnVide = new wxStaticText(this, -1, _T("\n        SUPER\nCALCULATOR\n         3000")); // bouton Badge

        btnEnter->SetBackgroundColour(wxColour(0,55,255,255));

	gridButton->Add(btnPi,0,wxEXPAND);
	gridButton->Add(btn0,0,wxEXPAND);
	gridButton->Add(btnPoint,0,wxEXPAND);
        gridButton->Add(btnEnter,0,wxEXPAND);
	gridButton->Add(btnVide,0,wxALIGN_CENTRE_HORIZONTAL);

/* //////////////////////////////////////////////////// FONCTIONS BOUTONS \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ */

	
	sizer_principal->Add(gridButton, 1, wxEXPAND); //On met la matrice dans le sizer principal
	SetSizer(sizer_principal); //Extension du sizer principal
	SetMinSize(wxSize(550, 500)); //Taille mini fenêtre
	Centre(); //Centrage de la fenêtre
}

void Display::OnButton_PUISS_Clicked(wxCommandEvent &event){
	*txtCalcInput << "^";
	calcul+="^";
}
void Display::OnButton_X_Clicked(wxCommandEvent &event){
	*txtCalcInput << "*";
	calcul+="*";
}
void Display::OnButton_DIV_Clicked(wxCommandEvent &event){
	*txtCalcInput << "/";
	calcul+="/";
}
void Display::OnButton_PLUS_Clicked(wxCommandEvent &event){
	*txtCalcInput << "+";
	calcul+="+";
}
void Display::OnButton_MOINS_Clicked(wxCommandEvent &event){
	*txtCalcInput << "-";
	calcul+="-";
}
void Display::OnButton_MODULO_Clicked(wxCommandEvent &event){
 *txtCalcInput << "%";
 calcul+="%";
}
void Display::OnButton_POINT_Clicked(wxCommandEvent &event){
	*txtCalcInput << ".";
	calcul+=".";
}
void Display::OnButton_0_Clicked(wxCommandEvent &event){
	*txtCalcInput << "0";
	calcul+="0";
}
void Display::OnButton_1_Clicked(wxCommandEvent &event){
	*txtCalcInput << "1";
	calcul+="1";
}
void Display::OnButton_2_Clicked(wxCommandEvent &event){
	*txtCalcInput << "2";
	calcul+="2";
}
void Display::OnButton_3_Clicked(wxCommandEvent &event){
	*txtCalcInput << "3";
	calcul+="3";
}
void Display::OnButton_4_Clicked(wxCommandEvent &event){
	*txtCalcInput << "4";
	calcul+="4";
}
void Display::OnButton_5_Clicked(wxCommandEvent &event){
	*txtCalcInput << "5";
	calcul+="5";
}
void Display::OnButton_6_Clicked(wxCommandEvent &event){
	*txtCalcInput << "6";
	calcul+="6";
}
void Display::OnButton_7_Clicked(wxCommandEvent &event){
	*txtCalcInput << "7";
	calcul+="7";
}
void Display::OnButton_8_Clicked(wxCommandEvent &event){
	*txtCalcInput << "8";
	calcul+="8";
}
void Display::OnButton_9_Clicked(wxCommandEvent &event){
	*txtCalcInput << "9";
	calcul+="9";
}
void Display::OnButton_PI_Clicked(wxCommandEvent &event){
	*txtCalcInput << wxString::FromUTF8("\xF0\x9D\x9B\x91"); //PI en UTF8
	calcul+=PI; 
}
void Display::OnButton_DEL_Clicked(wxCommandEvent &event){

	if(!calcul.empty()){
		calcul.pop_back();
		txtCalcInput->Clear();
		*txtCalcInput << calcul;	
	}
	
}

void Display::OnButton_AC_Clicked(wxCommandEvent &event){
txtCalcInput->Clear();
calcul.clear();

while(!stack_1.argument.empty())
{
 stack_1.argument.pop();
}
}
void Display::OnButton_ENTER_Clicked(wxCommandEvent &event){
if(!calcul.empty())
{

string buffer = calcul;

// On verifie qu'il n'y ait pas d'erreurs

if(isOperator(buffer)
   || isValidNumber(buffer))
{
 if(hasNoOperator(buffer))
 {
  stack_1.argument.push(stof(buffer));
  cout << stack_1.argument.size() << " nombre" << endl;
  buffer = "";
 }
 else
 {
  buffer = stack_1.Operation(buffer);
  if(!isError(buffer))
  {
   try
   {
    stack_1.argument.push(stof(buffer));
    if(stack_1.argument.size() == 1)
     stack_1.argument.pop();
    else
     buffer = "";
   }
   catch(const out_of_range& oor)
   {
    buffer = "OUT OF RANGE";
   }
  }
 }
}
txtCalcInput->Clear(); // On efface les données à l'écran
	*txtCalcInput << buffer; //On affiche le résultat
	
	// to do : est-ce que le buffer "calcul" ci dessous est utile ?
	calcul=buffer; //Stock le resultat dans calcul pour faire un nouveau calcul avec le resultat
}
}

void Display::OnButton_MCLEAR_Clicked(wxCommandEvent &event){
// On efface la mémoire en cas d'appuie sur Memory Clear
if(!save.empty())
 {save.clear();}
 btnMclear->Disable();
 btnMr->Disable();


}
void Display::OnButton_MPLUS_Clicked(wxCommandEvent &event){
// Grâce a Memory + on ajoute le nombre actuellement affiché à la maémoire
double val;
if(txtCalcInput->GetValue() .ToDouble(&val))
    {  
  if(!save.empty()){
      save.clear(); //On efface le contenu si non vide
     }
     save <<val;
    btnMclear->Enable();
     btnMr->Enable();
}
}
void Display::OnButton_MR_Clicked(wxCommandEvent &event){

   // Avec Memory Result, on affiche le contenu de la mémoire à l'écran	
   txtCalcInput->SetValue(save);
   calcul+=save; //On sauvegarde l'élément dans le calcul
}

/* //////////////////////////////////////////////////// EVENT TABLE \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ */

BEGIN_EVENT_TABLE(Display,wxFrame)

EVT_BUTTON(ID_BTN_PUISS, Display::OnButton_PUISS_Clicked)
EVT_BUTTON(ID_BTN_X, Display::OnButton_X_Clicked)
EVT_BUTTON(ID_BTN_DIV, Display::OnButton_DIV_Clicked)
EVT_BUTTON(ID_BTN_PLUS, Display::OnButton_PLUS_Clicked)
EVT_BUTTON(ID_BTN_MOINS, Display::OnButton_MOINS_Clicked)
EVT_BUTTON(ID_BTN_MODULO, Display::OnButton_MODULO_Clicked)
EVT_BUTTON(ID_BTN_POINT, Display::OnButton_POINT_Clicked)
EVT_BUTTON(ID_BTN_0, Display::OnButton_0_Clicked)
EVT_BUTTON(ID_BTN_1, Display::OnButton_1_Clicked)
EVT_BUTTON(ID_BTN_2, Display::OnButton_2_Clicked)
EVT_BUTTON(ID_BTN_3, Display::OnButton_3_Clicked)
EVT_BUTTON(ID_BTN_4, Display::OnButton_4_Clicked)
EVT_BUTTON(ID_BTN_5, Display::OnButton_5_Clicked)
EVT_BUTTON(ID_BTN_6, Display::OnButton_6_Clicked)
EVT_BUTTON(ID_BTN_7, Display::OnButton_7_Clicked)
EVT_BUTTON(ID_BTN_8, Display::OnButton_8_Clicked)
EVT_BUTTON(ID_BTN_9, Display::OnButton_9_Clicked)
EVT_BUTTON(ID_BTN_PI, Display::OnButton_PI_Clicked)
EVT_BUTTON(ID_BTN_DEL, Display::OnButton_DEL_Clicked)
EVT_BUTTON(ID_BTN_AC, Display::OnButton_AC_Clicked)
EVT_BUTTON(ID_BTN_ENTER, Display::OnButton_ENTER_Clicked)
EVT_BUTTON(ID_BTN_MPLUS, Display::OnButton_MPLUS_Clicked)
EVT_BUTTON(ID_BTN_MCLEAR, Display::OnButton_MCLEAR_Clicked)
EVT_BUTTON(ID_BTN_MR, Display::OnButton_MR_Clicked)

END_EVENT_TABLE()
