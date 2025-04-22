/////////////////////////////////////////////////////////////////////////////
// Name:        DialogBlocksWinAppMLapp.h
// Purpose:     
// Author:      Talipov S.N.
// Modified by: 
// Created:     22.04.2025 13:00:38
// RCS-ID:      
// Copyright:   Talipov S.N.
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#ifndef _DIALOGBLOCKSWINAPPMLAPP_H_
#define _DIALOGBLOCKSWINAPPMLAPP_H_


/*!
 * Includes
 */

////@begin includes
#include "wx/image.h"
#include "form1.h"
////@end includes

/*!
 * Forward declarations
 */

////@begin forward declarations
////@end forward declarations

/*!
 * Control identifiers
 */

////@begin control identifiers
////@end control identifiers

/*!
 * DialogBlocksWinAppMLApp class declaration
 */

class DialogBlocksWinAppMLApp: public wxApp
{    
    DECLARE_CLASS( DialogBlocksWinAppMLApp )
    DECLARE_EVENT_TABLE()

public:
    // --- Создать объект локализации приложения для подсистемы wxWidgets ---
    wxLocale m_locale; 

    /// Constructor
    DialogBlocksWinAppMLApp();

    void Init();

    /// Initialises the application
    virtual bool OnInit();

    /// Called on exit
    virtual int OnExit();

////@begin DialogBlocksWinAppMLApp event handler declarations

////@end DialogBlocksWinAppMLApp event handler declarations

////@begin DialogBlocksWinAppMLApp member function declarations

////@end DialogBlocksWinAppMLApp member function declarations

////@begin DialogBlocksWinAppMLApp member variables
////@end DialogBlocksWinAppMLApp member variables
};

/*!
 * Application instance declaration 
 */

////@begin declare app
DECLARE_APP(DialogBlocksWinAppMLApp)
////@end declare app

#endif
    // _DIALOGBLOCKSWINAPPMLAPP_H_
