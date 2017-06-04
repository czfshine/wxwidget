/*
* This file is part of wxSmith plugin for Code::Blocks Studio
* Copyright (C) 2006-2007  Bartlomiej Swiecki
*
* wxSmith is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 3 of the License, or
* (at your option) any later version.
*
* wxSmith is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with wxSmith. If not, see <http://www.gnu.org/licenses/>.
*
* $Revision: 10272 $
* $Id: wxwidgetsguiconfigpanel.h 10272 2015-05-15 10:57:25Z jenslody $
* $HeadURL: http://svn.code.sf.net/p/codeblocks/code/branches/release-16.xx/src/plugins/contrib/wxSmith/wxwidgets/wxwidgetsguiconfigpanel.h $
*/

#ifndef WXWIDGETSGUICONFIGPANEL_H
#define WXWIDGETSGUICONFIGPANEL_H

//(*Headers(wxWidgetsGUIConfigPanel)
#include <wx/combobox.h>
#include <wx/checkbox.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/panel.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

#include "wxwidgetsgui.h"

/** \brief Configuration panel for wxWidgetsGUI class */
class wxWidgetsGUIConfigPanel: public cbConfigurationPanel
{
    public:

        wxWidgetsGUIConfigPanel(wxWindow* parent,wxWidgetsGUI* GUI);
        virtual ~wxWidgetsGUIConfigPanel();

        //(*Identifiers(wxWidgetsGUIConfigPanel)
        static const long ID_TEXTCTRL1;
        static const long ID_BUTTON1;
        static const long ID_BUTTON2;
        static const long ID_COMBOBOX1;
        static const long ID_CHECKBOX2;
        static const long ID_CHECKBOX1;
        //*)

    private:

        virtual wxString GetTitle() const;
        virtual wxString GetBitmapBaseName() const;
        virtual void OnApply();
        virtual void OnCancel();

        //(*Handlers(wxWidgetsGUIConfigPanel)
        void OnInitAllChange(wxCommandEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        void OnButton2Click(wxCommandEvent& event);
        //*)

        //(*Declarations(wxWidgetsGUIConfigPanel)
        wxTextCtrl* AutoLoad;
        wxCheckBox* InitAll;
        wxCheckBox* InitAllNecessary;
        wxComboBox* MainRes;
        //*)

        wxWidgetsGUI* m_GUI;

        DECLARE_EVENT_TABLE()
};

#endif
