/*
 * This file is part of the Code::Blocks IDE and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 *
 * $Revision: 10543 $
 * $Id: dlgaboutplugin.cpp 10543 2015-10-21 05:52:42Z mortenmacfly $
 * $HeadURL: http://svn.code.sf.net/p/codeblocks/code/branches/release-16.xx/src/src/dlgaboutplugin.cpp $
 */

#include "sdk.h"
#ifndef CB_PRECOMP
#include <wx/intl.h>
#include <wx/stattext.h>
#include <wx/string.h>
#include <wx/textctrl.h>
#include <wx/xrc/xmlres.h>
#endif

#include "cbplugin.h"
#include "dlgaboutplugin.h" // class's header file

// class constructor
dlgAboutPlugin::dlgAboutPlugin(wxWindow* parent, const PluginInfo* pi)
{
	wxXmlResource::Get()->LoadObject(this, parent, _T("dlgAboutPlugin"),_T("wxScrollingDialog"));

	XRCCTRL(*this, "lblTitle", wxStaticText)->SetLabel(pi->title);
	XRCCTRL(*this, "txtDescription", wxTextCtrl)->SetValue(pi->description);
	XRCCTRL(*this, "txtThanksTo", wxTextCtrl)->SetValue(pi->thanksTo);
	XRCCTRL(*this, "txtLicense", wxTextCtrl)->SetValue(pi->license);
	XRCCTRL(*this, "lblName", wxStaticText)->SetLabel(pi->name);
	XRCCTRL(*this, "lblVersion", wxStaticText)->SetLabel(pi->version);
	XRCCTRL(*this, "lblAuthor", wxStaticText)->SetLabel(pi->author);
	XRCCTRL(*this, "lblEmail", wxStaticText)->SetLabel(pi->authorEmail);
	XRCCTRL(*this, "lblWebsite", wxStaticText)->SetLabel(pi->authorWebsite);

	Fit();
}

// class destructor
dlgAboutPlugin::~dlgAboutPlugin()
{
	// insert your code here
}
