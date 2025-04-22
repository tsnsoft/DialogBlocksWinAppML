/////////////////////////////////////////////////////////////////////////////
// Name:        form2.cpp
// Purpose:     
// Author:      Talipov S.N.
// Modified by: 
// Created:     22.04.2025 12:56:55
// RCS-ID:      
// Copyright:   Talipov S.N.
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

#include "form2.h"

////@begin XPM images
#include "tsnsoft.xpm"
////@end XPM images


/*
 * Form2 type definition
 */

IMPLEMENT_CLASS( Form2, wxFrame )


/*
 * Form2 event table definition
 */

BEGIN_EVENT_TABLE( Form2, wxFrame )

////@begin Form2 event table entries
    EVT_BUTTON( ID_BUTTON, Form2::OnButtonClick )
////@end Form2 event table entries

END_EVENT_TABLE()


/*
 * Form2 constructors
 */

Form2::Form2()
{
    Init();
}

Form2::Form2( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
    Init();
    Create( parent, id, caption, pos, size, style );
    this->SetTitle(_("The second window"));
}


/*
 * Form2 creator
 */

bool Form2::Create( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
////@begin Form2 creation
    wxFrame::Create( parent, id, caption, pos, size, style );

    CreateControls();
    SetIcon(GetIconResource(wxT("tsnsoft.xpm")));
    Centre();
////@end Form2 creation
    return true;
}


/*
 * Form2 destructor
 */

Form2::~Form2()
{
////@begin Form2 destruction
////@end Form2 destruction
}


/*
 * Member initialisation
 */

void Form2::Init()
{
////@begin Form2 member initialisation
////@end Form2 member initialisation
}


/*
 * Control creation for Form2
 */

void Form2::CreateControls()
{    
////@begin Form2 content construction
    Form2* itemFrame1 = this;

    wxGridBagSizer* itemGridBagSizer1 = new wxGridBagSizer(0, 0);
    itemGridBagSizer1->SetEmptyCellSize(wxSize(10, 20));
    itemFrame1->SetSizer(itemGridBagSizer1);

    wxStaticText* itemStaticText2 = new wxStaticText( itemFrame1, wxID_STATIC, _("I love wxWidgets"), wxDefaultPosition, wxDefaultSize, 0 );
    itemGridBagSizer1->Add(itemStaticText2, wxGBPosition(2, 9), wxGBSpan(1, 1), wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText3 = new wxStaticText( itemFrame1, wxID_STATIC, _("C++ is cool!"), wxDefaultPosition, wxDefaultSize, 0 );
    itemGridBagSizer1->Add(itemStaticText3, wxGBPosition(5, 1), wxGBSpan(1, 1), wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxButton* itemButton4 = new wxButton( itemFrame1, ID_BUTTON, _("Click it!"), wxDefaultPosition, wxDefaultSize, 0 );
    itemGridBagSizer1->Add(itemButton4, wxGBPosition(8, 9), wxGBSpan(1, 1), wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

////@end Form2 content construction
}


/*
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON
 */

void Form2::OnButtonClick( wxCommandEvent& event )
{
////@begin wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON in Form2.
    // Before editing this code, remove the block markers.
    Destroy();
////@end wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON in Form2. 
}


/*
 * Should we show tooltips?
 */

bool Form2::ShowToolTips()
{
    return true;
}

/*
 * Get bitmap resources
 */

wxBitmap Form2::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin Form2 bitmap retrieval
    wxUnusedVar(name);
    return wxNullBitmap;
////@end Form2 bitmap retrieval
}

/*
 * Get icon resources
 */

wxIcon Form2::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin Form2 icon retrieval
    wxUnusedVar(name);
    if (name == wxT("tsnsoft.xpm"))
    {
        wxIcon icon(tsnsoft_xpm);
        return icon;
    }
    return wxNullIcon;
////@end Form2 icon retrieval
}
