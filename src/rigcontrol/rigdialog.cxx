// generated by Fast Light User Interface Designer (fluid) version 1.0109

#include "gettext.h"
#include "rigdialog.h"
#include <config.h>
#include <string>
#include <FL/Fl_Box.H>
#include "rigsupport.h"
#include "fl_digi.h"
#include "flmisc.h"
using namespace std;

cFreqControl *FreqDisp=(cFreqControl *)0;

Fl_Browser *FreqSelect=(Fl_Browser *)0;

static void cb_FreqSelect(Fl_Browser*, void*) {
  if (FreqSelect->value()) {
  switch (Fl::event_button()) {
  case FL_MIDDLE_MOUSE:
    delFreq();
    addFreq();
    break;
  case FL_LEFT_MOUSE: default:
    if (Fl::event_state() & FL_SHIFT)
      delFreq();
    else
      selectFreq();
    break;
  }
};
}

Fl_ComboBox *opMODE=(Fl_ComboBox *)0;

static void cb_opMODE(Fl_ComboBox*, void*) {
  setMode();
}

Fl_ComboBox *opBW=(Fl_ComboBox *)0;

static void cb_opBW(Fl_ComboBox*, void*) {
  setBW();
}

Fl_Button *btnAddFreq=(Fl_Button *)0;

static void cb_btnAddFreq(Fl_Button*, void*) {
  addFreq();
}

Fl_Button *btnDelFreq=(Fl_Button *)0;

static void cb_btnDelFreq(Fl_Button*, void*) {
  delFreq();
}

Fl_Button *btnClearList=(Fl_Button *)0;

static void cb_btnClearList(Fl_Button*, void*) {
  if (quick_choice(_("Clear list?"), 2, _("Confirm"), _("Cancel"), NULL) == 1)
    clearList();
}

Fl_Button *btnRCclose=(Fl_Button *)0;

static void cb_btnRCclose(Fl_Button*, void*) {
  closeRigDialog();
}

Fl_Double_Window* rig_dialog() {
  Fl_Double_Window* w;
  { Fl_Double_Window* o = new Fl_Double_Window(560, 80, _("Rig Controller"));
    w = o;
    o->box(FL_DOWN_BOX);
    { cFreqControl* o = FreqDisp = new cFreqControl(4, 31, 253, 44, _("9"));
      FreqDisp->box(FL_DOWN_BOX);
      FreqDisp->color(FL_BACKGROUND_COLOR);
      FreqDisp->selection_color(FL_BACKGROUND_COLOR);
      FreqDisp->labeltype(FL_NORMAL_LABEL);
      FreqDisp->labelfont(0);
      FreqDisp->labelsize(14);
      FreqDisp->labelcolor(FL_FOREGROUND_COLOR);
      FreqDisp->align(FL_ALIGN_CENTER);
      FreqDisp->when(FL_WHEN_RELEASE);
      o->callback(movFreq);
      o->SetONOFFCOLOR( FL_RED, FL_BLACK);
    } // cFreqControl* FreqDisp
    { FreqSelect = new Fl_Browser(278, 5, 280, 70);
      FreqSelect->tooltip(_("Select operating mode and frequency\nMiddle click to replace, Shift-left clic\
k to delete"));
      FreqSelect->type(2);
      FreqSelect->box(FL_DOWN_BOX);
      FreqSelect->labelfont(4);
      FreqSelect->labelsize(12);
      FreqSelect->textfont(4);
      FreqSelect->callback((Fl_Callback*)cb_FreqSelect);
    } // Fl_Browser* FreqSelect
    { opMODE = new Fl_ComboBox(69, 5, 96, 20);
      opMODE->box(FL_DOWN_BOX);
      opMODE->color(FL_BACKGROUND2_COLOR);
      opMODE->selection_color(FL_BACKGROUND_COLOR);
      opMODE->labeltype(FL_NORMAL_LABEL);
      opMODE->labelfont(0);
      opMODE->labelsize(14);
      opMODE->labelcolor(FL_FOREGROUND_COLOR);
      opMODE->callback((Fl_Callback*)cb_opMODE);
      opMODE->align(FL_ALIGN_TOP);
      opMODE->when(FL_WHEN_RELEASE);
      opMODE->end();
    } // Fl_ComboBox* opMODE
    { opBW = new Fl_ComboBox(170, 5, 85, 20);
      opBW->box(FL_DOWN_BOX);
      opBW->color(FL_BACKGROUND2_COLOR);
      opBW->selection_color(FL_BACKGROUND_COLOR);
      opBW->labeltype(FL_NORMAL_LABEL);
      opBW->labelfont(0);
      opBW->labelsize(14);
      opBW->labelcolor(FL_FOREGROUND_COLOR);
      opBW->callback((Fl_Callback*)cb_opBW);
      opBW->align(FL_ALIGN_TOP);
      opBW->when(FL_WHEN_RELEASE);
      opBW->end();
    } // Fl_ComboBox* opBW
    { btnAddFreq = new Fl_Button(257, 5, 20, 20, _("@|>"));
      btnAddFreq->tooltip(_("Add to list"));
      btnAddFreq->labelsize(10);
      btnAddFreq->callback((Fl_Callback*)cb_btnAddFreq);
    } // Fl_Button* btnAddFreq
    { btnDelFreq = new Fl_Button(257, 30, 20, 20, _("@-11+"));
      btnDelFreq->tooltip(_("Delete from list"));
      btnDelFreq->labelsize(10);
      btnDelFreq->callback((Fl_Callback*)cb_btnDelFreq);
    } // Fl_Button* btnDelFreq
    { btnClearList = new Fl_Button(257, 54, 20, 20, _("@-1square"));
      btnClearList->tooltip(_("Clear list"));
      btnClearList->labelsize(10);
      btnClearList->callback((Fl_Callback*)cb_btnClearList);
    } // Fl_Button* btnClearList
    { btnRCclose = new Fl_Button(4, 5, 50, 20, _("Close"));
      btnRCclose->callback((Fl_Callback*)cb_btnRCclose);
    } // Fl_Button* btnRCclose
    o->end();
  } // Fl_Double_Window* o
  // Resizable kludge
// Move FreqSelect one pixel down so that we can define a box
// that will be used to resize this widget only. There has to be
// a better way of doing this...
{
FreqSelect->resize(FreqSelect->x(), FreqSelect->y() + 1, FreqSelect->w(), FreqSelect->h());
Fl_Box* b_ = new Fl_Box(FreqSelect->x() + FreqSelect->w() - 1, FreqSelect->y() + FreqSelect->h() - 1, 1, 1);
w->add_resizable(*b_);
// make the minimum width equal to that of the frequency display
w->size_range(FreqDisp->x() + FreqDisp->w(), w->h());
// get rid of the horizontal scrollbar, we will resize the window instead
FreqSelect->has_scrollbar(Fl_Browser_::VERTICAL);
}
  return w;
}
