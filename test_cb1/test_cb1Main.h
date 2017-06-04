/***************************************************************
 * Name:      test_cb1Main.h
 * Purpose:   Defines Application Frame
 * Author:    czfshine (czfshine@outlook.com)
 * Created:   2017-06-04
 * Copyright: czfshine ()
 * License:
 **************************************************************/

#ifndef TEST_CB1MAIN_H
#define TEST_CB1MAIN_H



#include "test_cb1App.h"


#include "GUIFrame.h"

class test_cb1Frame: public GUIFrame
{
    public:
        test_cb1Frame(wxFrame *frame);
        ~test_cb1Frame();
    private:
        virtual void OnClose(wxCloseEvent& event);
        virtual void OnQuit(wxCommandEvent& event);
        virtual void OnAbout(wxCommandEvent& event);
};

#endif // TEST_CB1MAIN_H
