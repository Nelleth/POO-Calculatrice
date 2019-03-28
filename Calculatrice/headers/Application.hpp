#ifndef APPLICATION_H
#define APPLICATION_H

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "Display.hpp"



class Application : public wxApp{ //dérivée de wxApp
	public:
		virtual bool OnInit();
	protected:
                Display *myWindow;


};


DECLARE_APP(Application); // déclaration en classe principale


#endif
