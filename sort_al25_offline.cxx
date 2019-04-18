/* Program: example.cxx
 *       Created  by Ken Teh,         Aug. 2005
 *       Modified by Xiaodong Tang,   July 2006
 *       Modified by Masahiro Notani, Aug. 2006 (146Sm M.Paul's exp)
 *       Modified by Hyeyoung Lee,    Jan. 2008 
 *       Modified by Scott Marley,    Oct. 2008
 *       Modified by Gemma Wilson,    Nov. 2017
 * Purpose: 
 *       SCARLET Data Aquisition & Histograming for experiments
 *       with Enge Split-Pole Spectrograph (SPS) and DSSD at ATLAS/ANL
 *
 * ROOT-daphne example sort program.  This program to be used with the
 * fakebldr program in this directory.
 *
 * The user must define userfunc() which is called for each event.  In
 * addition, the user may define userentry() and userexit() which are called
 * once at the start of a sort and when it terminates if defined.  The
 * functions return an int and should return 0.  A non-zero return value
 * terminates the sort.
 */

// Header Files
#include <sys/stat.h>
#include <cstdio>
#include "userfunc.h" //glw
#include "ScarletEvnt.h"
#include "TROOT.h" //glw
#include "TFile.h"
#include "TH1.h"
#include "TH2.h"
//#include "ppac.aug07.h"
#include "ppac.offline3.h"
#include "TCutG.h"
#include "TRandom.h"
#include "TMath.h"
#include "TDirectory.h"

// Macro Definition
#define NSCALERS 12


// Declaration of 1D/2D Histograms for SPS
TFile *f, *cutfile;
TH1F *h1_de[5];
TH1F *h1_cathode, *h1_grid, *h1_y, *h1_rftof, *h1_mon, *h1_spare;
TH1F *h1_x, *h1_posppb, *h1_pospp, *h1_time1s, *h1_target;
TH1F *h1_hepo,*h1_hepi,*h1_lepo,*h1_lepi,*h1_up,*h1_down;
TH1F *h1_hesum,*h1_lesum,*h1_udsum,*h1_he,*h1_le,*h1_ud;

TH2F *h2_updown, *h2_hepohepi, *h2_lepolepi, *h2_hesumlesum, *h2_hele;

TH2F *h2_xrftof, *h2_xcath, *h2_xde1, *h2_xde23, *h2_xde4, *h2_xYpos,*h2_xde4g;
TH2F *h2_de4rftof, *h2_cathde1, *h2_cathde23, *h2_cathde4, *h2_cathde5, *h2_cathrftof, *h2_de23;
TH2F *xrftofg;
TH2F *xrftofg1, *xrftofg2;
TH2F *h2_xde23_g, *hSSBt, *h2_Erf, *h2_DErf, *h2_DErfg;
TH2F *h2_rftof_spare;
/* calibration constants, stored as slope, offset, resolution for DSSD*/
Float_t DEGRAD=0.017453293;
Float_t Rslope[3][16];
Float_t Roffset[3][16];
Float_t Rresolution[3][16];
Float_t Wslope[3][16];
Float_t Woffset[3][16];
Float_t Wresolution[3][16];
Float_t Abeam=25.; Float_t Aeject=4.; Float_t Aresidue=22.; Float_t Atgt=1.;
Float_t ebeam=275.;
Int_t Tlow=300,Thi=700;
Int_t nevent=0;
Float_t edifflow=-2.,ediffhi=1.;

// Declaration of 1D/2D Histograms for DSSD

/* 1-D histograms: */

TH1F *hNR1,*hNR2, *hNR3, *hNW1, *hNW2, *hNW3;
TH1F *hTRFEDE;
TH1F *h1_E, *h1_DE, *h1_ESUM;

/* 2-D histograms */
TH2F *hHitR,*hHitW;
TH2F *hNR, *hNW;
TH2F *hELudR1, *hELudR2, *hELudR3, *hELudW1, *hELudW2, *hELudW3;
TH2F *hER1, *hER2, *hER3, *hEW1, *hEW2, *hEW3;
TH2F *hER1g,*hER1g2, *hER2g, *hER3g, *hEW1g, *hEW2g, *hEW3g;
TH2F *hEPixel1g, *hEDiff1g;
TH2F *hQTheta, *hQ_elastic, *hQTheta3; 
TH2F *hHitxy1, *hHitxy2, *hHitxy3;
TH2F *hEDiff;
TH2F *hEDiffR,*hEDiffW;
TH2F *test, *hEDE, *hEDEg, *hEDEg2;
TH2F *hER, *hEW, *hTAC, *hERg, *hERg1,*hERg2, *hERg3;
TH2F *hERtheta;
TH2F *hTRF,*hTRFg,*hT0RF,*hT0RFg;
TH2F *hADC2, *hADC3;
TH2F *h2_EDE;
TH2F *hER1_gtxrf1, *hER1_gtxrf2;
TH2F *hER1_gtxde41, *hER1_gtxde42, *hER1_gtxde43, *hER1_gtxde44;
TH2F *hER1_gtde4rf1, *hER1_gtde4rf2, *hER1_gtde4rf3, *hER1_gtde4rf4;

PPAC *myppac = new PPAC("/disks/1/gwilson/25Al/offline/ppac.offline3.setup");

// beginning of scaler part
Float_t totals[NSCALERS], rates[NSCALERS];
int stopped;

TCutG *xrfcut1, *xrfcut2,*xde4g1, *xde4g2, *xde4g3, *xde4g4, *de4rfg1, *de4rfg2, *de4rfg3, *de4rfg4, *alpha;

Bool_t icut = kTRUE;

// read the cut
Int_t readcuts(Char_t *cutfilename="/disks/1/gwilson/25Al/offline/25Al_cuts_new.root")
{
  const char* path = gROOT->GetPath();
  cutfile=new TFile(cutfilename,"read");
  cutfile->ls();
  xrfcut1 = (TCutG*) gROOT->FindObject("xrfcut1");
  xrfcut2 = (TCutG*) gROOT->FindObject("xrfcut2");
  xde4g1 = (TCutG*) gROOT->FindObject("xde4g1");
  xde4g2 = (TCutG*) gROOT->FindObject("xde4g2");
  xde4g3 = (TCutG*) gROOT->FindObject("xde4g3");
  xde4g4 = (TCutG*) gROOT->FindObject("xde4g4");
  de4rfg1 = (TCutG*) gROOT->FindObject("de4rfg1");
  de4rfg2 = (TCutG*) gROOT->FindObject("de4rfg2");
  de4rfg3 = (TCutG*) gROOT->FindObject("de4rfg3");
  de4rfg4 = (TCutG*) gROOT->FindObject("de4rfg4");
  alpha = (TCutG*) gROOT->FindObject("alpha");
  // if( cxde23 == 0 ) cout<<"cut_xde23 does not exist! please check !\n";
  cutfile->Close();
  gROOT->cd(path);
  cout<<gDirectory->GetPath()<<endl;
}

// check if the cut exist
Bool_t cexists(Char_t *cutname)
{
  Bool_t returnvalue=kFALSE;
  if (gROOT->FindObjectClassName(cutname)) returnvalue=kTRUE;
  return returnvalue;
}

// check if x,y in the cut
Bool_t checkcutg(Char_t *cutname,Float_t x, Float_t y)
{
  Bool_t returnvalue=kFALSE;
  if (cexists(cutname)) {
    TCutG *gcut=(TCutG *) gROOT->GetListOfSpecials()->FindObject(cutname);
    if (gcut->IsInside(x,y)==1) returnvalue=kTRUE;
    return returnvalue;
  } else {
    return returnvalue;
  }
}

/* Read calibration constants for DSSD */
int readcal(Char_t *calfile, Int_t iverbose=0)
{
  Float_t dummy;
  ifstream infile(calfile);
  for (Int_t idet=0;idet<2;idet++) {
    cout <<"Reading Detector "<<idet<<" calibrations"<<endl;
    if (iverbose==1) cout <<"Ring calibration constants:"<<endl;
    for(Int_t ring=0;ring<16;ring++) {
      infile>>dummy;
      infile>>dummy;
      infile>>Rslope[idet][ring];
      infile>>Roffset[idet][ring];
      infile>>Rresolution[idet][ring];
      if (iverbose==1) cout << Rslope[idet][ring]<<" "<<Roffset[idet][ring]<<endl;
    }
    if (iverbose==1) cout <<"Wedge calibration constants:"<<endl;
    for(Int_t wedge=0;wedge<16;wedge++) {
      infile>>dummy;
      infile>>dummy;
      infile>>Wslope[idet][wedge];
      infile>>Woffset[idet][wedge];
      infile>>Wresolution[idet][wedge];
      if (iverbose==1) cout << Wslope[idet][wedge]<<" "<<Woffset[idet][wedge]<<endl;
    }
  }
  return 0; 

}

/* function to count the number of set bits in a 16 bit word */

Int_t cntbit(Int_t word)
{
  Int_t pp,nbits=0;
  for (Int_t ibit=0; ibit<16; ibit++) {
    if (word & (Int_t) TMath::Power(2,ibit)) {nbits++;}
  }
  return nbits;
}

/* function to calculate the Q value given e, theta, ebeam & masses */
Float_t qcalc(Float_t e, Float_t theta, Float_t eb, Float_t ab, Float_t a1, 
	      Float_t a2)
{
  Float_t a,b,c,q;
  a=1+a1/a2;
  b=ab/a2-1;
  c=2*TMath::Sqrt(a1*ab)/a2;
  q=a*e + b*eb - c*TMath::Cos(theta*DEGRAD)*TMath::Sqrt(e*eb);
  return q;
}

/* function to deal with scalers, adapted from Elliot's program */
void scalers(ScarletEvnt &e)
{
  /* Adapted from Kanter's scaler program
   */
  unsigned int *p = reinterpret_cast<unsigned int*>(e.body());
  unsigned int ttotal, tdiff, ithscaler, ithrate;
  FILE *sf;

  /* On the first sync event after a stop, the following tests for the
   * existence of a file called scalers.zap.  If it exists, the scaler
   * totals are reset.
   */
  if (stopped) {
    struct stat st;
    stopped = 0;
    if (stat("scalers.zap", &st) == 0) {
      printf("Clearing scalers...\n");
      for (int i = 0; i < NSCALERS; ++i) {totals[i] = 0.0; rates[i]=0.0;}
    }
  }

  if ((sf = fopen("scalers.dat", "w")) == 0) return;
  ttotal = *p++;
  tdiff = *p++;
  fprintf(sf, "%u %u\n", ttotal, tdiff);
  for (int i = 0; i < NSCALERS; ++i) {
    int dataword = *p++;
    ithscaler = dataword & 0x00ffffff;
    totals[i] += ithscaler;
    ithrate = tdiff != 0 ? ithscaler/tdiff : 0;
    if(i==10) totals[10]=totals[8]/totals[6]*1000;
    fprintf(sf, "%.0f %u\n", totals[i], ithrate);
  }
  fclose(sf);
}
// end of scaler part

/* The userentry() function:  Create your ROOT objects here.  ROOT objects
 * should always be created on the heap.  That is, always allocate the
 * objects via the new operator.  If you intend to save your histograms to a
 * root file, create the file in userentry().  You can also use this
 * function to load gates and conditions from other root files.
 */
int userentry()
{
  float px, py;
  
  // read cuts from cut_file.root
  
  if(icut) readcuts();

  Bool_t ical=kTRUE;
  if (ical) 
    // {readcal("k37_dssd.cal");}
    {readcal("calglw.dat");}
  else {
    for (Int_t idet=0;idet<3; idet++) {
      for (Int_t ichan=0; ichan<16; ichan++) {
	Rslope[idet][ichan]=500.0;
	Roffset[idet][ichan]=0.0;
	Wslope[idet][ichan]=500.0;
	Woffset[idet][ichan]=0.0;
      }
    }
  }
  
  // Open ROOT file
  f = new TFile("output.root", "recreate");
  
  // 1d histograms
  h1_de[0] = new TH1F("h1_de1","de1", 4096,0,4096);
  h1_de[1] = new TH1F("h1_de2","de2", 4096,0,4096);
  h1_de[2] = new TH1F("h1_de3","de3", 4096,0,4096);
  h1_de[3] = new TH1F("h1_de4","de4", 4096,0,4096);
  h1_de[4] = new TH1F("h1_de5","de5", 4096,0,4096);
  
  h1_cathode = new TH1F("h1_cath","cathode",4096,0,4096);
  h1_grid    = new TH1F("h1_grid","TAC-SSB-RF",   4096,0,4096);
  //  h1_y       = new TH1F("h1_y","y",         4096,0,4096);
  h1_rftof   = new TH1F("h1_rftof","rftof", 4096,0,4096);
  h1_mon     = new TH1F("h1_mon","SSB",     4096,0,4096);
  h1_spare   = new TH1F("h1_spare","TAC-PPAC-DSSD", 4096,0,4096);
  
  //  h1_time1s = new TH1F("h1_time1s","time(10s)",1500,500000,20000000);
  //  h1_target = new TH1F("h1_target","time(10s)",1500,500000,20000000);
  h1_x      = new TH1F("h1_x","x",          4096,0,4096);
  h1_pospp  = new TH1F("h1_pospp","pospp",4096,0,4096);
  h1_posppb  = new TH1F("h1_posppb","posppb",4096,0,4096);
  
  h1_hepo   = new TH1F("h1_hepo","hepo",4096,0,4096);
  h1_hepi   = new TH1F("h1_hepi","hepi",4096,0,4096);
  h1_lepo   = new TH1F("h1_lepo","lepo",4096,0,4096);
  h1_lepi   = new TH1F("h1_lepi","lepi",4096,0,4096);
  h1_up     = new TH1F("h1_up",  "up",  4096,0,4096);
  h1_down   = new TH1F("h1_down","down",4096,0,4096);
  h1_hesum  = new TH1F("h1_hesum","hesum",4096,0,4096);
  h1_lesum  = new TH1F("h1_lesum","lesum",4096,0,4096);
  h1_udsum  = new TH1F("h1_udsum","udsum",4096,0,4096);
  h1_he     = new TH1F("h1_he","he",4096,0,4096);
  h1_le     = new TH1F("h1_le","le",4096,0,4096);
  h1_ud     = new TH1F("h1_ud","ud",4096,0,4096);
    
  // 2d histograms
  h2_updown   = new TH2F("h2_updown","down:up",    512,0.,4096.,512,0.,4096.);
  h2_hepohepi = new TH2F("h2_hepohepi","hepi:hepo",512,0.,4096.,512,0.,4096.);
  h2_lepolepi = new TH2F("h2_lepolepi","lepi:lepo",512,0.,4096.,512,0.,4096.);
  h2_hesumlesum= new TH2F("h2_hesumlesum","lesum:hesum",512,0.,4096.,512,0.,4096.);
  h2_hele     = new TH2F("h2_hele","le:he",512,0,4096,512,0,4096);
  
  h2_xrftof = new TH2F("h2_xrftof","rftof:x",512, 0., 1024.,1024, 0., 4096.);
  h2_rftof_spare= new TH2F("h2_rftof_spare","rftof:dssd-ppac",1024, 0., 4096,1024, 0., 4096.);

  xrftofg = new TH2F("xrftofg","rftof:x(Time gated)",512, 0., 1024.,1024, 0., 4096.);
  xrftofg1 = new TH2F("xrftofg1","rftof:x(Time gated && proton)",512, 0., 1024.,1024, 0., 4096.);
  //xrftofg2 = new TH2F("xrftofg2","rftof:x(Time gated && alpha)",512, 0., 1024.,1024, 0., 4096.);
  h2_xcath  = new TH2F("h2_xcath", "cath:x",512, 0., 1024.,512, 0., 4096.);
  h2_xde1   = new TH2F("h2_xde1",  "de1:x", 512, 0., 1024.,512, 0., 4096.);
  h2_xde23  = new TH2F("h2_xde23", "de23:x", 512, 0., 1024.,512, 0., 4096.);
  h2_xde4   = new TH2F("h2_xde4",  "de4:x",  512, 0., 1024.,512, 0., 4096.);
  h2_xYpos   = new TH2F("h2_xYpos",  "Ypos:x",  512, 0., 1024.,512, 0., 4096.);
  h2_xde4g   = new TH2F("h2_xde4g",  "de4:x",  512, 0., 1024.,512, 0., 4096.);  
  h2_de4rftof = new TH2F("h2_de4rftof","rftof:de4", 1024, 0., 4096.,512, 0., 4096.);
  /* h2_cathde1  = new TH2F("h2_cathde1","de1:cath",  1024, 0., 4096.,1024, 0., 4096.);
     h2_cathde23  = new TH2F("h2_cathde23","de23:cath",  1024, 0., 4096.,1024, 0., 4096.);
     h2_cathde4  = new TH2F("h2_cathde4","de4:cath",   1024, 0., 4096.,1024, 0., 4096.);
     h2_cathde5  = new TH2F("h2_cathde5","de5:cath",   1024, 0., 4096.,1024, 0., 4096.);
     h2_cathrftof= new TH2F("h2_cathrftof","rftof:cath",1024, 0., 4096.,1024, 0., 4096.);
  */
  h2_de23     = new TH2F("h2_de23","de3:de2",       1024, 0., 4096.,1024, 0., 4096.);
  

  h1_E = new TH1F("h1_E","E",1024, 0., 4096.);
  h1_DE = new TH1F("h1_DE","DE",1024, 0., 4096.);
  h1_ESUM = new TH1F("h1_ESUM","h1_ESUM",1024,0,4096);
  h2_EDE = new TH2F("h2_EDE","DE vs. E",1024, 0., 4096.,1024, 0., 4096.);
  h2_Erf = new TH2F("h2_Erf","rf vs. E",512, 0., 4096.,512, 0., 4096.); 
  h2_DErf = new TH2F("h2_DErf","rf vs. DE",512, 0., 4096.,512, 0., 4096.); 
  h2_DErfg = new TH2F("h2_DErfg","rf vs. DE",512, 0., 4096.,512, 0., 4096.); 
  /******************DSSD histograms***************************/

  
  
  //  hHitR=new TH2F("hHitR","Ludwig ring hits",17,0,17,4,0,4);
  //  hHitW=new TH2F("hHitW","Ludwig wedge hits",17,0,17,4,0,4);
  //  hNR=new TH2F("hNR","N hits Ludwig rings",17,0,17,4,0,4);
  //  hNW=new TH2F("hNW","N hits Ludwig wedges",17,0,17,4,0,4);

  hELudR1=new TH2F("hELudR1","Ring1 vs E raw",4096,0,4096,17,0,17);   
  hELudW1=new TH2F("hELudW1","Wedge1 vs E raw",4096,0,4096,17,0,17); 
 
  hELudR2=new TH2F("hELudR2","Ring2 vs E raw",4096,0,4096,17,0,17);   
  hELudW2=new TH2F("hELudW2","Wedge2 vs E raw",4096,0,4096,17,0,17); 
 
  //  hEDiff=new TH2F("hEDiff","Ludwig ER-EW",1000,-5,5,4,0,4);
  //  hEDiffR=new TH2F("hEDiffR","Ludwig ER-EW vs ring",500,-2.5,2.5,17,0,17);
  //  hEDiffW=new TH2F("hEDiffW","Ludwig ER-EW vs wedge",500,-2.5,2.5,17,0,17);

  hER1=new TH2F("hER1","Ring1 vs E calib",2000,0,80,17,0,17);  
  hER2=new TH2F("hER2","Ring2 vs E calib",2000,0,50,17,0,17);
  hEW1=new TH2F("hEW1","Wedge1 vs E calib",2000,0,80,17,0,17);
  hEW2=new TH2F("hEW2","Wedge2 vs E calib",2000,0,50,17,0,17); 

  hER=new TH2F("hER","Ring vs Energy all",1000,0,10,50,0,50);
  //hERg=new TH2F("hERg","Ring vs Energy Time gated",1500,0,30,30,5,15);
  //hERg1=new TH2F("hERg1","theta vs Energy Ne21+Time gated",1500,0,30,30,5,15);
  //hERg2=new TH2F("hERg2","theta vs Energy F18+Time gated",1500,0,30,30,5,15);
  //hERg3=new TH2F("hERg3","theta vs Energy F18+Time gated",1500,0,30,30,5,15);

  //hEW=new TH2F("hEW","Wedge vs Energy all",1000,0,10,50,0,50);
  hTAC=new TH2F("hTAC","T(DSSD-PPAC)",512,0,4096,512,0,4096);
  //  hSSBt=new TH2F("hSSBt","E(SSB) vs. TAC", 512,0,4096,512,0,4096);
  //hEDE=new TH2F("hEDE","E vs. DE", 512,0,37,512,0,12);
  //hEDEg=new TH2F("hEDEg","E vs. DE(gated)", 512,0,37,512,0,12);
  //hEDEg2=new TH2F("hEDEg2","E vs. DE(gated)", 512,0,37,512,0,12);
  //hTRF=new TH2F("hTRF","T(EDE-RF)",512,0,4096,512,0,4096);
  //hT0RF=new TH2F("hT0RF","T0 vs DE0",512,0,4096,512,0,4096);
  //hT0RFg=new TH2F("hT0RFg","T0 vs DE0 B12 gated",512,0,4096,512,0,4096);
  //hTRFg=new TH2F("hTRFg","T(EDE-RF) gated",512,0,4096,512,0,4096);
  //hERtheta=new TH2F("hERtheta","Theta vs Energy",1000,0,10,90,90,180);
  
  hER1g=new TH2F("hER1g","Ring1 vs E calib gated",1000,0,80,17,0,17);  
  hER1g2=new TH2F("hER1g2","Ring1 vs E calib time and pid gated",1000,0,50,17,0,17);  
  hEW1g=new TH2F("hEW1g","Wedge1 vs E calib gated",1000,0,80,17,0,17);
  hER1_gtxrf1=new TH2F("hER1_gtxrf1","Ring1 vs E calib gated, time and xrfcut1",1000,0,80,17,0,17);  
  hER1_gtxrf2=new TH2F("hER1_gtxrf2","Ring1 vs E calib gated time and xrfcut2",1000,0,80,17,0,17);  
  hER1_gtxde41=new TH2F("hER1_gtxde41","Ring1 vs E calib gated, time and xde4g1",1000,0,80,17,0,17);  
  hER1_gtxde42=new TH2F("hER1_gtxde42","Ring1 vs E calib gated, time and xde4g2",1000,0,80,17,0,17);  
  hER1_gtxde43=new TH2F("hER1_gtxde43","Ring1 vs E calib gated, time and xde4g3",1000,0,80,17,0,17);  
  hER1_gtxde44=new TH2F("hER1_gtxde44","Ring1 vs E calib gated, time and xde4g4",1000,0,80,17,0,17);  
  hER1_gtde4rf1=new TH2F("hER1_gtde4rf1","Ring1 vs E calib gated, time and de4rfg1",1000,0,80,17,0,17);  
  hER1_gtde4rf2=new TH2F("hER1_gtde4rf2","Ring1 vs E calib gated, time and de4rfg2",1000,0,80,17,0,17);  
  hER1_gtde4rf3=new TH2F("hER1_gtde4rf3","Ring1 vs E calib gated, time and de4rfg3",1000,0,80,17,0,17);  
  hER1_gtde4rf4=new TH2F("hER1_gtde4rf4","Ring1 vs E calib gated, time and de4rfg4",1000,0,80,17,0,17);  

  //hQTheta=new TH2F("hQTheta","Theta versus Q(18F)",500,-5,5,30,5,15);
  //hQTheta3=new TH2F("hQTheta3","Theta versus Q(18F)",500,-5,5,30,5,15);
  //hQ_elastic=new TH2F("hQ_elastic","Theta versus Q(21Ne)",500,-5,5,30,5,15);

  //hEPixel1g=new TH2F("hEPixel1g","Energy vs Pixel detector 1",2000,0,20,300,0,300);
  //hEDiff1g =new TH2F("hEDiff1g","E-diff vs Pixel detector 1",1000,-5,5,300,0,300);
  hHitxy1=new TH2F("hHitxy1","Y vs X DSSD (goodediff)",200,-50,50,200,-50,50);
  hHitxy2=new TH2F("hHitxy2","Y vs X DSSD (goodediff&goodT)",200,-50,50,200,-50,50);
  //hHitxy3=new TH2F("hHitxy3","Y vs X DSSD (goodediff&goodT&goodNe)",200,-50,50,200,-50,50);

  hADC2=new TH2F("hADC2","Raw ADC2 (Wedges)",1024,0,4096,16,0,16);
  hADC3=new TH2F("hADC3","Raw ADC3 (Rings)",1024,0,4096,16,0,16);

  // histograms with gate
  // h2_xde23_g  = new TH2F("h2_xde23_g", "de23:x with gate", 512, 0., 4096.,512, 0., 4096.);
  
  /* stopped flag for Elliot's scaler program */
  for (Int_t i=0; i<NSCALERS; i++) totals[i]=0;
  stopped = 1;
  
  return 0;
}

int userdecode(ScarletEvnt &event) {

  ScarletEvnt subevent1;
  Int_t dataword;
    
  TRandom *rannum = new TRandom();

  subevent1=event[1];
  int *p1 = reinterpret_cast<int*>(subevent1.body());
  int *p;
  
  Float_t lowthresh=100;
  
  Bool_t done=kFALSE;
  Float_t ering,ewedge;
  Float_t ediff;
  Float_t phi[16];
  Float_t Qvalue, Qvalue1;
  Int_t Rpat[3],Wpat[3],Rbitcnt[3]={0,0,0},Wbitcnt[3]={0,0,0};
  Int_t RRawData[3][16],WRawData[3][16];
  Int_t RChan[3][16],WChan[3][16];
  Float_t RData[3][16],WData[3][16];
  Float_t emaxR=0,emaxW=0,theta_max;
  Float_t emaxrawR=0, emaxrawW=0, DSSD_E=0., DSSD_DE=0.;
  Int_t nmaxR=-1,nmaxW=-1,detmaxR=-1,detmaxW=-1;
  Int_t DSSD_E_ring, DSSD_DE_ring;
  Int_t ndet=0;
  Int_t ipixel[3]={-1,-1,-1};
  Int_t Rremap[3][16]={{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15},
		       {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15},
		       {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15}};
  Int_t Wremap[3][16]={{11,12,13,14,15,0,1,2,3,4,5,6,7,8,9,10},
		       {3,4,5,6,7,8,9,10,11,12,13,14,15,0,1,2},
		       //{11,12,13,14,15,0,1,2,3,4,5,6,7,8,9,10},
		       //{15,16,13,14,11,12,9,10,7,8,5,6,3,4,1,2},
		       {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15}};

  //theta needs to be changed for the setup to 33Cl(p,a) ....
  Float_t theta[3][16]={{4.95,5.57,6.2,6.82,7.45,8.07,8.67,9.30,9.92,
			 10.5,11.1,11.75,12.36,12.96,13.56,14.16},
			{146.2,144.6,142.1,141.7,140.3,138.9,137.6,136.4,
			 135.2,134.0,132.9,131.9,130.9,129.9,130.0,128.0},
			{126.0,124.4,123.0,121.6,120.3,119.2,118.1,117.1,
			 116.1,115.2,114.4,113.6,112.8,112.1,111.5,110.9}};

  // de1..5, cathode, grid, y, RFTOF, MON, SPARE
  float de[5], cathode, grid, y, rftof, mon, spare, t1, t2;
  float E,DE;
  float hepo, hepi, lepo, lepi, up, down;
  float stime0, stime1, stime2;
  double stime, stime_1s;
  Bool_t goodCl=kFALSE;
  Bool_t goodAr=kFALSE;
  Bool_t garbage=kFALSE;
 
  nevent++;
  //  cout <<"Event "<<nevent<<endl;

  //  cout <<"Enter unpack..."<<endl;

  /* unpack fixed length beginning of subevent 1 */
  // ADC part
  dataword=*p1++; 
  de[0]=(dataword & 0x00000fff); //#1
  dataword=*p1++; 
  de[1]=(dataword & 0x00000fff); //#2
  dataword=*p1++; 
  de[2]=(dataword & 0x00000fff); //#3
  dataword=*p1++; 
  de[3]=(dataword & 0x00000fff); //#4
  dataword=*p1++; 
  de[4]=(dataword & 0x00000fff); //#5
  dataword=*p1++; 
  cathode=(dataword & 0x00000fff); //#6
  dataword=*p1++; 
  grid=(dataword & 0x00000fff); //#7
  dataword=*p1++; 
  y=(dataword & 0x00000fff); //#8
  dataword=*p1++; 
  rftof=(dataword & 0x00000fff); //#9
  dataword=*p1++; 
  mon=(dataword & 0x00000fff); //#10
  dataword=*p1++; 
  spare=(dataword & 0x00000fff); //#11
  dataword=*p1++; 
  DE=(dataword & 0x00000fff); //#12
  dataword=*p1++; 
  E=(dataword & 0x00000fff); //#13
   

  p=p1;

  //unpack DSSD(s)
  for (Int_t ndet=0; ndet<2; ++ndet) {

    // p=(ndet==0)=p1;  //:p2; //Since there is no ROC2!
    //p=p1;

    /* get Wedge hit pattern, count bits, then store data & channel */
    /* calibration constants put the energy into MeV */
    /* emaxW, nmaxW and detmaxW have similar meanings to emaxR etc below */

    Wpat[ndet]=*p++;
      
    Wbitcnt[ndet]=cntbit(Wpat[ndet]);
    for (Int_t ndat=0;ndat<Wbitcnt[ndet];ndat++) {
      dataword=*p++;
      WChan[ndet][ndat]=((dataword & 0x0000f000)>>12);
      //hHitW->Fill(1+((dataword & 0x0000f000)>>12),ndet);
      WRawData[ndet][ndat]=(dataword & 0x00000fff);
      WData[ndet][ndat]=
	(WRawData[ndet][ndat] - Woffset[ndet][WChan[ndet][ndat]])/
	Wslope[ndet][WChan[ndet][ndat]];
      if (WData[ndet][ndat]>emaxW) {
	emaxW=WData[ndet][ndat];
	emaxrawW=WRawData[ndet][ndat];
	nmaxW=WChan[ndet][ndat];
	detmaxW=ndet;
      }
      //hADC2->Fill(emaxrawW,nmaxW);
      if(ndet==0){
	hELudW1->Fill(WRawData[ndet][ndat],WChan[ndet][ndat]);
	hEW1->Fill(WData[ndet][ndat],WChan[ndet][ndat]);
	//hEW2->Fill(emaxW,nmaxW);
      }
      if(ndet==1){
	hELudW2->Fill(WRawData[ndet][ndat],WChan[ndet][ndat]);
	hEW2->Fill(WData[ndet][ndat],WChan[ndet][ndat]);
	//hEW2->Fill(emaxW,nmaxW);
      }
	    
    }

    /* get Ring hit pattern, count bits, then store data & channel */
    /* calibration constants put the energy into MeV */
    /* emaxR holds largest Ring energy, nmaxR holds ring number of */
    /* largest Ring energy, detmaxR holds detector number */

    Rpat[ndet]=*p++;
    Rbitcnt[ndet]=cntbit(Rpat[ndet]);
    for (Int_t ndat=0;ndat<Rbitcnt[ndet];ndat++) {
      dataword=*p++;
      RChan[ndet][ndat]=((dataword & 0x0000f000)>>12);
      //hHitR->Fill(1+((dataword & 0x0000f000)>>12),ndet);
      RRawData[ndet][ndat]=(dataword & 0x00000fff);
      RData[ndet][ndat]=
	(RRawData[ndet][ndat] - Roffset[ndet][RChan[ndet][ndat]])/
	Rslope[ndet][RChan[ndet][ndat]];
      if( fabs(Rslope[ndet][RChan[ndet][ndat]])<0.0001)
	{ cout<<"problem "<<ndet<<" "<<RChan[ndet][ndat]<<endl;}

      if (RData[ndet][ndat]>emaxR) {
	//  cout<<"hi this "<<RData[ndet][ndat]<<endl;
	emaxR=RData[ndet][ndat];
	emaxrawR=RRawData[ndet][ndat];
	nmaxR=RChan[ndet][ndat];
	detmaxR=ndet;
      }

      //hADC3->Fill(emaxrawR,nmaxR);
      if(ndet==0)
	{
	  hELudR1->Fill(RRawData[ndet][ndat],RChan[ndet][ndat]);
	  hER1->Fill(RData[ndet][ndat],RChan[ndet][ndat]);
	  //hER2->Fill(emaxR,nmaxR);
	}
      if(ndet==1){
	hELudR2->Fill(RRawData[ndet][ndat],RChan[ndet][ndat]);
	hER2->Fill(RData[ndet][ndat],RChan[ndet][ndat]);
	//hER2->Fill(emaxR,nmaxR);
      }
	
    }

    // if (ndet>0) p2=p;
  }
  p1=p;

  // TDC part
  dataword=*p1++;
  hepo=(dataword & 0x00000fff);
  dataword=*p1++;
  hepi=(dataword & 0x00000fff);
  dataword=*p1++;
  lepo=(dataword & 0x00000fff);
  dataword=*p1++;
  lepi=(dataword & 0x00000fff);
  dataword=*p1++;
  up=(dataword & 0x00000fff);
  dataword=*p1++;
  down=(dataword & 0x00000fff);

  // Latching scaler
  dataword=*p1++;
  stime0=(dataword & 0x0000ffff);
  dataword=*p1++;
  stime1=(dataword & 0x0000ffff);
  dataword=*p1++;
  stime2=(dataword & 0x0000ffff);


  stime = (stime2*65536.0 + stime1)*65536.0 + stime0;
  stime_1s = stime/1e6;

  myppac->GetPosition(hepo,hepi,lepo,lepi,up,down); // old version

  // select whether high/low/both (he/le/pospp) energy side  
  float x = myppac->pospp;
  float Ypos=0.;
  Ypos=0.5*(up-down)+2000.;
  Ypos=myppac->ud;

  float posppb = 0.0;
  if( de[1] > 2 && de[1] < 4000 && de[2] > 2 && de[2]< 4000 ) 
    posppb = 1000.0*(de[1]-de[2])/(de[1]+de[2]);

  // fill 1d histograms
  for(int i=0;i<5;i++) { h1_de[i]->Fill(de[i]);}
  h1_cathode->Fill(cathode);
  h1_grid->Fill(grid);
  t2=grid; // grid is TAC between RF and SSB =t2
  //hSSBt->Fill(t2,y);
  //  h1_y->Fill(y);
  h1_rftof->Fill(rftof);
  h1_mon->Fill(mon);
  // if(mon>50 && mon<120) h1_target->Fill(stime_1s);
  h1_spare->Fill(spare); //spare is TAC between DSSD and PPAC =t1
  t1=spare;

  h1_E->Fill(E);
  h1_DE->Fill(DE);
  h1_ESUM->Fill(E+DE);
  //h1_posppb->Fill(posppb);
  h1_pospp->Fill(myppac->pospp);

  h1_hepo->Fill(hepo);
  h1_hepi->Fill(hepi);
  h1_lepo->Fill(lepo);
  h1_lepi->Fill(lepi);
  h1_up->Fill(up);
  h1_down->Fill(down);
  if((hepo>=50 && hepo<=4000 )&&(hepi>=50 && hepi<=4000)) {
    h1_hesum->Fill(0.25*(hepo+hepi));}
  if((lepo>=50 && lepo<=4000 )&&(lepi>=50 && lepi<=4000)) {
    h1_lesum->Fill(0.25*(lepo+lepi));}
  if((up>0)&&(up<4000)&&(down>0)&&(down<4000)){
    h1_udsum->Fill(0.5*(up+down));}    
  //if(0.25*(lepo+lepi)>880) {
  //  h1_ud->Fill(lepo*0.5);
  //  h1_ud->Fill(lepi*0.5+2000);}
  //  if((up>0)&&(up<4000)&&(down>0)&&(down<4000)){
  //  h1_ud->Fill(0.5*(up-down)+2048.);
  //}

  h1_he->Fill(myppac->he);
  h2_hele->Fill(myppac->he,myppac->le);
  h1_le->Fill(myppac->le);
  h1_ud->Fill(Ypos); 
  //  h1_time1s->Fill(stime_1s);


  // fill 2d histograms
  h2_EDE->Fill(E,DE);
  h2_Erf->Fill(E,rftof);
  h2_DErf->Fill(DE,rftof);
  if(E>900 && E<1150 && DE>2600 && DE<2850) h2_DErfg->Fill(DE,rftof); 

  h2_hepohepi->Fill(hepo,hepi);
  h2_lepolepi->Fill(lepo,lepi);
  h2_hesumlesum->Fill(myppac->hesum,myppac->lesum);
  //  h2_hele->Fill(myppac->he,myppac->le);
  h2_updown->Fill(up,down);
  
  h2_xrftof->Fill(x, rftof);
  if(de[3]>1800) xrftofg1->Fill(x, rftof);
  h2_xcath->Fill(x,cathode);
  h2_xde1->Fill(x,de[0]);
  h2_xde23->Fill(x,de[1]+de[2]);
  h2_xde4->Fill(x,de[3]);
  h2_xYpos->Fill(x, Ypos);
  

  h2_rftof_spare->Fill(spare, rftof);


  h2_de4rftof->Fill(de[3],rftof);
  //h2_cathde1->Fill(cathode,de[0]);
  //h2_cathde23->Fill(cathode,de[1]+de[2]);
  //h2_cathde4->Fill(cathode,de[3]);
  //h2_cathde5->Fill(cathode,de[4]);
  //h2_cathrftof->Fill(cathode, rftof);
  //h2_de23->Fill(de[1], de[2]);
  


  // fill with gated histograms
  //if( checkcutg("cut_xde23", x, de[1]+de[2]) ){
  //    h2_xde23_g->Fill(x, de[1]+de[2]);
  //}
  //  cout<<"Start big loop..."<<endl;
  // here starts the big unpacking loop for DSSD


  Bool_t goodA=kFALSE;
  Bool_t goodT=kFALSE;
  Bool_t anygood=kFALSE;
  Bool_t goodediff=kFALSE; 
 
  if(de[3]<700) garbage=kTRUE;
  if(rftof<1200) goodAr=kTRUE;
  if(x>450) goodCl=kTRUE;
  if(t1>1000 && t1<2000) goodT=kTRUE; 

  if(goodT){
    h1_posppb->Fill(rftof);
    xrftofg->Fill(x, rftof);
    h2_xde4g->Fill(x,de[3]);
    hER1g->Fill(emaxR,nmaxR);
    //  cout<<"this is the output test"<<emaxR<<" "<<nmaxR<<endl;
    if (rftof>2000 && rftof<3500) hER1g2->Fill(emaxR,nmaxR);
    hEW1g->Fill(emaxW,nmaxW);
    if(checkcutg("xrfcut1",x,rftof)){
      hER1_gtxrf1->Fill(emaxR,nmaxR);}
    if(checkcutg("xrfcut2",x,rftof)){
      hER1_gtxrf2->Fill(emaxR,nmaxR);}
    if(checkcutg("xde4g1",x,de[3])){
      hER1_gtxde41->Fill(emaxR,nmaxR);}
    if(checkcutg("xde4g2",x,de[3])){
      hER1_gtxde42->Fill(emaxR,nmaxR);}
    if(checkcutg("xde4g3",x,de[3])){
      hER1_gtxde43->Fill(emaxR,nmaxR);}
    if(checkcutg("xde4g4",x,de[3])){
      hER1_gtxde44->Fill(emaxR,nmaxR);}
    if(checkcutg("de4rfg1",de[3],rftof)){
      hER1_gtde4rf1->Fill(emaxR,nmaxR);}
    if(checkcutg("de4rfg2",de[3],rftof)){
      hER1_gtde4rf2->Fill(emaxR,nmaxR);}
    if(checkcutg("de4rfg3",de[3],rftof)){
      hER1_gtde4rf3->Fill(emaxR,nmaxR);}
    if(checkcutg("de4rfg4",de[3],rftof)){
      hER1_gtde4rf4->Fill(emaxR,nmaxR);}
  }
  
  
  //fill x-y hit patterns here;

  //if (goodediff) {
  //  if (t1>50) hTAC->Fill(t1,detmaxR);
  //hEPixel1g->Fill(emaxR,ipixel[0]);
  Float_t ran1,ran2,newR, newW;
  ran1 = 1.5 *(rand()%10000)/10000;
  ran2 = 22.5 *(rand()%10000)/10000;
  newR=Rremap[detmaxR][nmaxR];
  newW=Wremap[detmaxW][nmaxW];
  Float_t rad=11.75 + (15-newR-1)*1.5 + ran1;
  Float_t phi2=0 + (newW+1)*22.5 + ran2;
  //Float_t phi=0 + nmaxW*22.5 + ran2;
  Float_t x2=rad*cos(phi2*DEGRAD);
  Float_t y2=rad*sin(phi2*DEGRAD);
  switch(detmaxR)
    {
    case 0:
      hHitxy1->Fill(x2,y2);
      if(goodT) hHitxy2->Fill(x2,y2);
      break;
    }
  /*if(goodT) { 
    hHitxy2->Fill(x,y);
    if(goodNe) hHitxy3->Fill(x,y);
    }*/
  //} 		   
  delete rannum;
  return 0;
}

/* The userfunc() function:  This function is called per event.  The event
 * is supplied by daphne.  Unpack the event and fill your histograms here.
 */
//int userfunc(const struct ScarletEvntHdr* h)
int userfunc(const struct ScarletEvntHdr *h, const struct ScarletDataBufHdr *b) //glw
{
  ScarletEvnt event, subevent;
  event = h;
 
  switch (event.eventtype()) {

  case SE_TYPE_TRIGGERED: 
    userdecode(event);   
    break;

  case SE_TYPE_SYNC:
    subevent=event[1];
    scalers(subevent);
    break;

  case SE_TYPE_STOP:
    stopped=1;
    printf("received stop signal.\n");
    break;
  }

  return 0;
}

/* The userexit() function:  This function is called when the sort thread is
 * stopped.  The sort thread is stopped either by explicitly stopping it or
 * when a new sort is started.  It is not stopped if the sorting completes
 * or terminates.  By not stopping, the user retains access to the ROOT
 * objects even after a sort finishes.  Typically, the userexit() function
 * is used to close whatever root files were opened in userentry().
 */
int userexit()
{
  f->Write();
  f->Close();
  delete f;
  return 0;
}
