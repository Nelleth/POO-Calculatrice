#ifndef DISPLAY_H
#define DISPLAY_H

using namespace std;

/* //////////////////////////////////////////////////// ENUM DES BOUTONS \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ */

enum{
        ID_BTN_PUISS,ID_BTN_DEL, ID_BTN_AC, ID_BTN_ENTER,
        ID_BTN_X,ID_BTN_DIV,ID_BTN_PLUS,ID_BTN_MOINS,
        ID_BTN_POINT,ID_BTN_MODULO,	ID_BTN_0,ID_BTN_1,
        ID_BTN_2,ID_BTN_3,ID_BTN_4,	ID_BTN_5,ID_BTN_6,
        ID_BTN_7,ID_BTN_8,ID_BTN_9,ID_BTN_PI,ID_BTN_MPLUS,
        ID_BTN_MR, ID_BTN_MCLEAR,ID_TXT_CALCINPUT
};

class Display : public wxFrame{
        public:
                Display(const wxString title,const wxPoint& pos, const wxSize& size);
                virtual ~Display();

        protected:

                string calcul;
                wxTextCtrl *txtCalcInput, *textValeur; //Zone de la GUI
                wxBoxSizer *sizer_principal; // Sizer principal
                wxGridSizer *gridButton; // Matrice boutons
                wxString save=wxT("");

                wxButton *btnPuiss,*btnDel,*btnAc,*btnEnter;
                wxButton *btnX,*btnDiv,*btnPlus,*btnMoins;
                wxButton *btnPoint,*btnModulo,*btn0,*btn1;
                wxButton *btn2,*btn3,*btn4,*btn5,*btn6,*btn7,*btn8;
                wxButton *btn9,*btnPi,*btnMplus,*btnMr,*btnMclear;
                wxStaticText *btnVide;


/* //////////////////////////////////////////////////// EVENEMENTS BOUTONS \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ */

                void OnButton_PUISS_Clicked(wxCommandEvent &event);
                void OnButton_DEL_Clicked(wxCommandEvent &event);
                void OnButton_AC_Clicked(wxCommandEvent &event);
                void OnButton_ENTER_Clicked(wxCommandEvent &event);
                void OnButton_X_Clicked(wxCommandEvent &event);
                void OnButton_DIV_Clicked(wxCommandEvent &event);
                void OnButton_PLUS_Clicked(wxCommandEvent &event);
                void OnButton_MOINS_Clicked(wxCommandEvent &event);
                void OnButton_POINT_Clicked(wxCommandEvent &event);
                void OnButton_MODULO_Clicked(wxCommandEvent &event);
                void OnButton_0_Clicked(wxCommandEvent &event);
                void OnButton_1_Clicked(wxCommandEvent &event);
                void OnButton_2_Clicked(wxCommandEvent &event);
                void OnButton_3_Clicked(wxCommandEvent &event);
                void OnButton_4_Clicked(wxCommandEvent &event);
                void OnButton_5_Clicked(wxCommandEvent &event);
                void OnButton_6_Clicked(wxCommandEvent &event);
                void OnButton_7_Clicked(wxCommandEvent &event);
                void OnButton_8_Clicked(wxCommandEvent &event);
                void OnButton_9_Clicked(wxCommandEvent &event);
                void OnButton_PI_Clicked(wxCommandEvent &event);
                void OnButton_MPLUS_Clicked(wxCommandEvent &event);
                void OnButton_MCLEAR_Clicked(wxCommandEvent &event);
                void OnButton_MR_Clicked(wxCommandEvent &event);

                DECLARE_EVENT_TABLE()
};



#endif //DISPLAY_H
