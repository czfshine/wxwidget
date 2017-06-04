/***************************************************************
 * Name:      test_cb1App.cpp
 * Purpose:   Code for Application Class
 * Author:    czfshine (czfshine@outlook.com)
 * Created:   2017-06-04
 * Copyright: czfshine ()
 * License:
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "test_cb1App.h"
#include "test_cb1Main.h"

IMPLEMENT_APP(test_cb1App);

bool test_cb1App::OnInit()
{
    test_cb1Frame* frame = new test_cb1Frame(0L);
    frame->SetIcon(wxICON(aaaa)); // To Set App Icon
    frame->Show();
    
    return true;
}
