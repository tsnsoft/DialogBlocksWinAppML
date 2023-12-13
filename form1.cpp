/////////////////////////////////////////////////////////////////////////////
// Name: form1.cpp
// Purpose:
// Author: Talipov S.N.
// Modified by:
// Created: 12/12/2023 10:40:53
// RCS-ID:
// Copyright: Talipov S.N.
// Licence:
/////////////////////////////////////////////////////////////////////////////

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

////@begin includes
////@end includes

#include "form1.h"

////@begin XPM images
#include "tsnsoft.xpm"
////@end XPM images


#include <wx/stdpaths.h>
#include <wx/fileconf.h>

/*
* Form1 type definition
*/

IMPLEMENT_CLASS(Form1, wxFrame)

/*
* Form1 event table definition
*/

BEGIN_EVENT_TABLE(Form1, wxFrame)

////@begin Form1 event table entries
    EVT_CLOSE( Form1::OnCloseWindow )
    EVT_BUTTON( button1, Form1::OnButton1Click )
    EVT_CHOICE( Choice_Lang, Form1::OnChoiceLangSelected )
////@end Form1 event table entries

END_EVENT_TABLE()

/*
* Form1 constructors
*/


Form1::Form1()
{
	Init();
}

Form1::Form1(wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style)
{
	Init();
	Create(parent, id, caption, pos, size, style);

	// --- Загрузить настройки из конфигурации и установить значения в визуальных компонентах ---
	wxConfigBase* conf = wxConfigBase::Get(false); // Получить объект конфигурации приложения
	if (conf) { // Если объект конфигурации приложения создан
		wxString user_lang = (conf->Read(wxT("language"), wxT("en"))); // Прочитать значение языка из конфигурации
		wxChoice* ch = (wxChoice*)FindWindowById(Choice_Lang); // Найти компонент с выбором языка
		if (ch) { // Если элемент найден
			ch->SetStringSelection(user_lang); // Установить язык в компоненте
		}
	}
	this->SetTitle(_("Multilingual program")); // Установить имя приложения на выбранном языке
	// ---------------------------

}


/*
* Form1 creator
*/

bool Form1::Create(wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style)
{
	////@begin Form1 creation
    wxFrame::Create( parent, id, caption, pos, size, style );

    CreateControls();
    SetIcon(GetIconResource(wxT("tsnsoft.xpm")));
    if (GetSizer())
    {
        GetSizer()->SetSizeHints(this);
    }
    Centre();
	////@end Form1 creation
	return true;
}


/*
* Form1 destructor
*/

Form1::~Form1()
{
	////@begin Form1 destruction
	////@end Form1 destruction
}


/*
* Member initialisation
*/

void Form1::Init()
{
	////@begin Form1 member initialisation
	////@end Form1 member initialisation
}


/*
* Control creation for Form1
*/

void Form1::CreateControls()
{
	////@begin Form1 content construction
    Form1* itemFrame1 = this;

    wxBoxSizer* itemBoxSizer1 = new wxBoxSizer(wxVERTICAL);
    itemFrame1->SetSizer(itemBoxSizer1);

    wxButton* itemButton2 = new wxButton( itemFrame1, button1, _("Press me"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer1->Add(itemButton2, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer1->Add(itemBoxSizer3, 0, 0, 0);

    wxStaticText* itemStaticText4 = new wxStaticText( itemFrame1, StaticText1, _("Hello everyone, I'm a C++ program with wxWidgets!"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer3->Add(itemStaticText4, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemBoxSizer3->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxArrayString itemChoice6Strings;
    itemChoice6Strings.Add(_("ru"));
    itemChoice6Strings.Add(_("en"));
    itemChoice6Strings.Add(_("de"));
    wxChoice* itemChoice6 = new wxChoice( itemFrame1, Choice_Lang, wxDefaultPosition, wxDefaultSize, itemChoice6Strings, 0 );
    itemChoice6->SetStringSelection(_("en"));
    itemBoxSizer3->Add(itemChoice6, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

	////@end Form1 content construction
}


/*
* Should we show tooltips?
*/

bool Form1::ShowToolTips()
{
	return true;
}

/*
* Get bitmap resources
*/

wxBitmap Form1::GetBitmapResource(const wxString& name)
{
	// Bitmap retrieval
	////@begin Form1 bitmap retrieval
    wxUnusedVar(name);
    return wxNullBitmap;
	////@end Form1 bitmap retrieval
}

/*
* Get icon resources
*/

wxIcon Form1::GetIconResource(const wxString& name)
{
	// Icon retrieval
	////@begin Form1 icon retrieval
    wxUnusedVar(name);
    if (name == wxT("tsnsoft.xpm"))
    {
        wxIcon icon(tsnsoft_xpm);
        return icon;
    }
    return wxNullIcon;
	////@end Form1 icon retrieval
}


/*
* wxEVT_COMMAND_BUTTON_CLICKED event handler for button1
*/

// Обработчик события нажатия на кнопку
void Form1::OnButton1Click(wxCommandEvent& event)
{
	wxMessageBox(_("Hello")); // Выдать локализованное сообщение
}

/*
 * wxEVT_CLOSE_WINDOW event handler for form1
 */

void Form1::OnCloseWindow(wxCloseEvent& event)
{
	// --- Сохранить настройки из визуальных компонент в конфигурацию ---
	wxConfigBase* conf = wxConfigBase::Get(false); // Получить объект конфигурации приложения
	if (!conf) return; // Если объект конфигурации приложения не создан, то выход

	wxChoice* ch = (wxChoice*)FindWindowById(Choice_Lang); // Найти компонент с выбором языка
	if (ch) { // Если компонент найден
		conf->Write(wxT("language"), ch->GetStringSelection()); // Записать значение из компонента в конфигурацию
	}
	// ---------------------------

	Destroy(); // Закрыть окно
}

/*
 * wxEVT_COMMAND_CHOICE_SELECTED event handler for Choice_Lang
 */

// Обработчик события выбора языка
void Form1::OnChoiceLangSelected(wxCommandEvent& event)
{
	wxMessageBox(_("Restart the program")); // Выдать локализованное сообщение
}

