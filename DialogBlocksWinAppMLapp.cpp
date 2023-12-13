/////////////////////////////////////////////////////////////////////////////
// Name:        DialogBlocksWinAppMLapp.cpp
// Purpose:     
// Author:      Talipov S.N.
// Modified by: 
// Created:     12/12/2023 17:27:14
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

#include "DialogBlocksWinAppMLapp.h"
#include <wx/fileconf.h>
#include <wx/stdpaths.h>
#include <wx/config.h>


////@begin XPM images
////@end XPM images


/*
 * Application instance implementation
 */

 ////@begin implement app
IMPLEMENT_APP(DialogBlocksWinAppMLApp)
////@end implement app


/*
 * DialogBlocksWinAppMLApp type definition
 */

	IMPLEMENT_CLASS(DialogBlocksWinAppMLApp, wxApp)


	/*
	 * DialogBlocksWinAppMLApp event table definition
	 */

	BEGIN_EVENT_TABLE(DialogBlocksWinAppMLApp, wxApp)

	////@begin DialogBlocksWinAppMLApp event table entries
	////@end DialogBlocksWinAppMLApp event table entries

	END_EVENT_TABLE()


	/*
	 * Constructor for DialogBlocksWinAppMLApp
	 */

	DialogBlocksWinAppMLApp::DialogBlocksWinAppMLApp()
{
	Init();
}

// --- Объявление указателя на объект конфигурации ---
wxFileConfig* m_fileconfig;
// -------


/*
 * Member initialisation
 */


void DialogBlocksWinAppMLApp::Init()
{
	// --- ЛОКАЛИЗАЦИЯ ПРИЛОЖЕНИЯ, ЧТЕНИЕ ИЗ ФАЙЛА НАСТРОЕК ---

	// Добавить путь к каталогу с переводами в список поиска каталогов с переводами
	m_locale.AddCatalogLookupPathPrefix(wxT("locale"));

	// Создать имя для файла конфигурации приложения
	wxFileName fn = wxFileName(wxPathOnly(wxStandardPaths::Get().GetExecutablePath()), GetAppName(), wxT("ini"));

	// Создать объект конфигурации приложения
	m_fileconfig = new wxFileConfig(wxEmptyString, wxEmptyString, fn.GetFullPath(), wxEmptyString,
		wxCONFIG_USE_LOCAL_FILE | wxCONFIG_USE_NO_ESCAPE_CHARACTERS);

	wxConfigBase::Set(m_fileconfig); // Установить объект конфигурации приложения

	wxString user_lang; // Объявить переменную для хранения языка пользователя

	if (m_fileconfig) { // Если объект конфигурации приложения создан
		user_lang = (m_fileconfig->Read(wxT("language"), wxT("en"))); // Прочитать язык пользователя из конфигурации

		if (user_lang == L"ru") // Если язык пользователя русский
		{
			setlocale(LC_ALL, "ru_RU.UTF-8"); // Установить локаль по умолчанию для Linux на русский язык
			m_locale.Init(wxLANGUAGE_RUSSIAN); // Установить локализацию приложения на русский язык
			m_locale.AddCatalog(wxT("ru")); // Добавить каталог с переводами на русский язык	
		}
		else
			if (user_lang == L"de") // Если язык пользователя немецкий
			{
				setlocale(LC_ALL, "de_DE.UTF-8"); // Установить локаль по умолчанию для Linux на немецкий язык
				m_locale.Init(wxLANGUAGE_GERMAN); // Установить локализацию приложения на немецкий язык
				m_locale.AddCatalog(wxT("de")); // Добавить каталог с переводами на немецкий язык
			}
			else
			{
				setlocale(LC_ALL, "en_US.UTF-8"); // Установить локаль по умолчанию для Linux на английский язык
				m_locale.Init(wxLANGUAGE_ENGLISH); // Установить локализацию приложения на английский язык
			}
	}
	// -------------------------------

}

/*
 * Initialisation for DialogBlocksWinAppMLApp
 */

bool DialogBlocksWinAppMLApp::OnInit()
{
	////@begin DialogBlocksWinAppMLApp initialisation
	// Remove the comment markers above and below this block
	// to make permanent changes to the code.

#if wxUSE_XPM
	wxImage::AddHandler(new wxXPMHandler);
#endif
#if wxUSE_LIBPNG
	wxImage::AddHandler(new wxPNGHandler);
#endif
#if wxUSE_LIBJPEG
	wxImage::AddHandler(new wxJPEGHandler);
#endif
#if wxUSE_GIF
	wxImage::AddHandler(new wxGIFHandler);
#endif
	Form1* mainWindow = new Form1(NULL);
	mainWindow->Show(true);
	////@end DialogBlocksWinAppMLApp initialisation

	return true;
}


/*
 * Cleanup for DialogBlocksWinAppMLApp
 */

int DialogBlocksWinAppMLApp::OnExit()
{
	// --- СОХРАНИТЬ НАСТРОЙКИ В ФАЙЛ КОНФИГУРАЦИИ ПРИ ВЫХОДЕ ИЗ ПРОГРАММЫ ---
	if (m_fileconfig) { // Если объект конфигурации приложения создан
		m_fileconfig->Flush(); // Сохранить настройки в файл
		delete m_fileconfig; // Удалить объект конфигурации приложения
		m_fileconfig = NULL; // Установить указатель на объект конфигурации приложения в NULL
	}
	wxConfigBase::Set(NULL); // Установить объект конфигурации приложения в NULL
	// ------------------------------------------------------------------

	return wxApp::OnExit(); // Вызвать функцию OnExit() базового класса
}

