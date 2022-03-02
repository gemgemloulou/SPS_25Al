/* Program: example.cxx
 *       Created  by Ken Teh,         Aug. 2005
 *       Modified by Xiaodong Tang,   July 2006
 *       Modified by Masahiro Notani, Aug. 2006 (146Sm M.Paul's exp)
 *       Modified by Hyeyoung Lee,    Jan. 2008 
 *       Modified by Scott Marley,    Oct. 2008
 *       Modified by Gemma Wilson,    Nov. 2017 (to get it to run)
 *       Modified by Gemma Wilson,    Dec. 2017 (to include trees)
 *       MOdified by Gemma Wilson,    Jan. 2018 (including pospp (or x) as a branch
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
#include "TTree.h" // glw

// Macro Definition
#define NSCALERS 12

/********************************
 ********************************/
/****/ Bool_t iverb = 1; /****/
/********************************
 ********************************/

// Declaration of 1D/2D Histograms for SPS
TFile *f;
TTree *tree;
TFile *cutfile;
TH1F *h1_de[5];
//TH1F *h1_de0, *h1_de1, *h1_de2, h1_de3, *h1_de4;
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
//Float_t dE_Fgain[16], dE_Foffset[16], dE_Bgain[16], dE_Boffset[16];
//Float_t E_Fgain[16], E_Foffset[16], E_Bgain[16], E_Boffset[16];
Float_t Rslope[2][16];
Float_t Roffset[2][16];
Float_t Wslope[2][16];
Float_t Woffset[2][16];

Int_t Tlow=300; Int_t Thi=700;
Int_t nevent=0;
Float_t edifflow=-2.; Float_t ediffhi=1.;

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
TH2F *hER1_gtxrf1, *hER1_gtxrf2, *hER1_gtxde41, *hER1_gtxde42, *hER1_gtxde43, *hER1_gtxde44, *hER1_gtde4rf1, *hER1_gtde4rf2, *hER1_gtde4rf3, *hER1_gtde4rf4;

PPAC *myppac = new PPAC("/disks/1/gwilson/25Al/offline/ppac.offline3.setup");

// beginning of scaler part
Float_t totals[NSCALERS], rates[NSCALERS];
int stopped;

TCutG *xrfcut1, *xrfcut2,*xde4g1, *xde4g2, *xde4g3, *xde4g4, *de4rfg1, *de4rfg2, *de4rfg3, *de4rfg4, *alpha;

Bool_t icut = kTRUE;

// ********************************************************************************
// branch variables - put more things here and organise int
Int_t dE_Fmult;
Int_t dE_Bmult;
Int_t dE_Fnum[16];
Int_t dE_Bnum[16];
Float_t dE_Fenergy[16];
Float_t dE_Benergy[16];
Float_t dE_Fenergy_raw[16];
Float_t dE_Benergy_raw[16];
Int_t E_Fmult;
Int_t E_Bmult;
Int_t E_Fnum[16];
Int_t E_Bnum[16];
Float_t E_Fenergy[16];
Float_t E_Benergy[16];
Float_t E_Fenergy_raw[16];
Float_t E_Benergy_raw[16];
Float_t E_Fmax;
Float_t E_Bmax;
Float_t dE_Fmax;
Float_t dE_Bmax;
Float_t E_Fmaxnum;
Float_t E_Bmaxnum;
Float_t dE_Fmaxnum;
Float_t dE_Bmaxnum;

Float_t de[5], cathode, grid, y, rftof, mon, spare, t1, t2;
Float_t E, DE;
Float_t hepo, hepi, lepo, lepi, up, down;
Float_t stime0, stime1, stime2;
Float_t x;
Int_t testrmult0, testrmult1, testwmult0, testwmult1;
Int_t i;

void treeinit(){
    if(iverb) cout << "in treeinit" << endl;
    for(Int_t i=0;i<16;i++){
      dE_Fnum[i] = -5;
      dE_Bnum[i] = -5;
      dE_Fenergy[i] = 0;
      dE_Benergy[i] = 0;
      dE_Fenergy_raw[i] = 0;
      dE_Benergy_raw[i] = 0;
      E_Fnum[i] = -5;
      E_Bnum[i] = -5;
      E_Fenergy[i] = 0;
      E_Benergy[i] = 0;
      E_Fenergy_raw[i] = 0;
      E_Benergy_raw[i] = 0; 
    }
    dE_Fmult = 0; dE_Bmult = 0;
    E_Fmult = 0; E_Bmult = 0;
    dE_Bmax = 0; dE_Fmax = 0; E_Bmax = 0; E_Fmax = 0;
    dE_Bmaxnum = -5; dE_Fmaxnum = -5; E_Fmaxnum = -5; E_Bmaxnum = -5;

  cathode = grid = y = rftof = mon = spare = t1 = t2 = 0;
  hepo = hepi = lepo = lepi = up = down = 0;
  stime0 = stime1 = stime2 = 0;
  x = 0;
  for(Int_t i=0;i<5;i++){ de[i] = 0;}
//if(iverb) cout << "dE_Fmult = " << dE_Fmult << ", E_Fmult = " << E_Fmult << endl;
}



// ********************************************************************************

// read the cut
Int_t readcuts(Char_t *cutfilename="/disks/1/gwilson/25Al/offline/25Al_cuts_new.root")
{
  if(iverb) cout << "reading cuts" << endl;
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

/* function to count the number of set bits in a 16 bit word */

Int_t cntbit(Int_t word)
{
  Int_t pp,nbits=0;
  for (Int_t ibit=0; ibit<16; ibit++) {
    if (word & (Int_t) TMath::Power(2,ibit)) {nbits++;}
  }
  return nbits;
}

/* function to deal with scalers, adapted from Elliot's program */
void scalers(ScarletEvnt &e){
    /* Adapted from Kanter's scaler program   */
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
  float_t px, py;
  
  // read cuts from cut_file.root
  if(icut) readcuts();

// read in calibration coefficients
ifstream in_dEf; ifstream in_dEb;
ifstream in_Ef; ifstream in_Eb;
in_dEf.open("dEfrontcal.dat");
in_dEb.open("dEcal.dat");
in_Ef.open("Efrontcal.dat");
in_Eb.open("Ebackcal.dat");

// using old cal for dE backs
for (int i=0;i<16;i++){
    in_dEf >> Rslope[1][i] >> Roffset[1][i];
    in_Ef >> Rslope[0][i] >> Roffset[0][i];
    in_Eb >> Wslope[0][i] >> Woffset[0][i];
    if (Rslope[1][i] != 0) Rslope[1][i] = 1/Rslope[1][i];
    if (Rslope[0][i] != 0) Rslope[0][i] = 1/Rslope[0][i];
    if (Wslope[0][i] != 0) Wslope[0][i] = 1/Wslope[0][i];
    }
       
for(int i=16;i<32;i++){ // old values - which I don't think are right. I'm not sure there are dE backs
    in_dEb >> Woffset[1][i-16] >> Wslope[1][i-16];
    }
    
in_dEf.close(); in_Ef.close(); in_dEb.close(); in_Eb.close();
    
for(int i=0;i<16;i++) cout << Roffset[0][i] << "\t" << Rslope[0][i] << "\t" << Roffset[1][i] << "\t" << Rslope[1][i] << endl;
for(int i=0;i<16;i++) cout << Woffset[0][i] << "\t" << Wslope[0][i] << "\t" << Woffset[1][i] << "\t" << Wslope[1][i] << endl;

  // ************************************************************************************  
  // Open ROOT file
  
  f = new TFile("output.root","recreate");
  tree = new TTree("tree","sorted data");

  tree->Branch("dE_FMult",&dE_Fmult,"dE_Fmult/i");
  tree->Branch("dE_BMult",&dE_Bmult,"dE_Bmult/i");
  tree->Branch("dE_Fenergy",dE_Fenergy,"dE_Fenergy[dE_Fmult]/f");
  tree->Branch("dE_Benergy",dE_Benergy,"dE_Benergy[dE_Bmult]/f");
  tree->Branch("dE_Fnum",dE_Fnum,"dE_Fnum[dE_Fmult]/i");
  tree->Branch("dE_Bnum",dE_Bnum,"dE_Bnum[dE_Bmult]/i");
  tree->Branch("dE_Fenergy_raw",dE_Fenergy_raw,"dE_Fenergy_raw[dE_Fmult]/f");
  tree->Branch("dE_Benergy_raw",dE_Benergy_raw,"dE_Benergy_raw[dE_Bmult]/f");

  tree->Branch("E_FMult",&E_Fmult,"E_Fmult/i");
  tree->Branch("E_BMult",&E_Bmult,"E_Bmult/i");
  tree->Branch("E_Fenergy",E_Fenergy,"E_Fenergy[E_Fmult]/f");
  tree->Branch("E_Benergy",E_Benergy,"E_Benergy[E_Bmult]/f");
  tree->Branch("E_Fnum",E_Fnum,"E_Fnum[E_Fmult]/i");
  tree->Branch("E_Bnum",E_Bnum,"E_Bnum[E_Bmult]/i");
  tree->Branch("E_Fenergy_raw",E_Fenergy_raw,"E_Fenergy_raw[E_Fmult]/f");
  tree->Branch("E_Benergy_raw",E_Benergy_raw,"E_Benergy_raw[E_Bmult]/f");

  tree->Branch("E_Fmax",&E_Fmax,"E_Fmax/f");
  tree->Branch("E_Bmax",&E_Bmax,"E_Bmax/f");
  tree->Branch("dE_Fmax",&dE_Fmax,"dE_Fmax/f");
  tree->Branch("dE_Bmax",&dE_Bmax,"dE_Bmax/f");
  tree->Branch("E_Fmaxnum",&E_Fmaxnum,"E_Fmaxnum/i");
  tree->Branch("E_Bmaxnum",&E_Bmaxnum,"E_Bmaxnum/i");
  tree->Branch("dE_Fmaxnum",&dE_Fmaxnum,"dE_Fmaxnum/i");
  tree->Branch("dE_Bmaxnum",&dE_Bmaxnum,"dE_Bmaxnum/i");

  tree->Branch("de",de,"de[5]/f");
  tree->Branch("cathode",&cathode,"cathode/f");
  tree->Branch("grid",&grid,"grid/f");
  tree->Branch("x",&x,"x/f");
  tree->Branch("y",&y,"y/f");
  tree->Branch("rftof",&rftof,"rftof/f");
  tree->Branch("mon",&mon,"mon/f");
  tree->Branch("spare",&spare,"spare/f");
  tree->Branch("t1",&t1,"t1/f");
  tree->Branch("t2",&t2,"t2/f");
  tree->Branch("E",&E,"E/f");
  tree->Branch("DE",&DE,"DE/f");
  tree->Branch("up",&up,"up/f");
  tree->Branch("stime0",&stime0,"stime0/f");
  tree->Branch("stime1",&stime1,"stime1/f");
  tree->Branch("stime2",&stime2,"stime2/f");
  tree->Branch("hepo",&hepo,"hepo/f");
  tree->Branch("hepi",&hepi,"hepi/f");
  tree->Branch("lepo",&lepo,"lepo/f");
  tree->Branch("lepi",&lepi,"lepi/f");
  tree->Branch("down",&down,"down/f");

  // ************************************************************************************  

  // 1d histograms
  h1_de[0] = new TH1F("h1_de1","de1",4096,0,4096);
  h1_de[1] = new TH1F("h1_de2","de2",4096,0,4096);
  h1_de[2] = new TH1F("h1_de3","de3",4096,0,4096);
  h1_de[3] = new TH1F("h1_de4","de4",4096,0,4096);
  h1_de[4] = new TH1F("h1_de5","de5",4096,0,4096);
  
  h1_cathode = new TH1F("h1_cath","cathode",4096,0,4096);
  h1_grid = new TH1F("h1_grid","TAC-SSB-RF",4096,0,4096);
  h1_rftof = new TH1F("h1_rftof","rftof",4096,0,4096);
  h1_mon = new TH1F("h1_mon","SSB",4096,0,4096);
  h1_spare = new TH1F("h1_spare","TAC-PPAC-DSSD",4096,0,4096);
 
  h1_x = new TH1F("h1_x","x",4096,0,4096);
  h1_pospp = new TH1F("h1_pospp","pospp",4096,0,4096);
  h1_posppb = new TH1F("h1_posppb","posppb",4096,0,4096);
  
  h1_hepo = new TH1F("h1_hepo","hepo",4096,0,4096);
  h1_hepi = new TH1F("h1_hepi","hepi",4096,0,4096);
  h1_lepo = new TH1F("h1_lepo","lepo",4096,0,4096);
  h1_lepi = new TH1F("h1_lepi","lepi",4096,0,4096);
  h1_up = new TH1F("h1_up","up",4096,0,4096);
  h1_down = new TH1F("h1_down","down",4096,0,4096);
  h1_hesum = new TH1F("h1_hesum","hesum",4096,0,4096);
  h1_lesum = new TH1F("h1_lesum","lesum",4096,0,4096);
  h1_udsum = new TH1F("h1_udsum","udsum",4096,0,4096);
  h1_he = new TH1F("h1_he","he",4096,0,4096);
  h1_le = new TH1F("h1_le","le",4096,0,4096);
  h1_ud = new TH1F("h1_ud","ud",4096,0,4096);
    
  // 2d histograms
  h2_updown = new TH2F("h2_updown","down:up",512,0.,4096.,512,0.,4096.);
  h2_hepohepi = new TH2F("h2_hepohepi","hepi:hepo",512,0.,4096.,512,0.,4096.);
  h2_lepolepi = new TH2F("h2_lepolepi","lepi:lepo",512,0.,4096.,512,0.,4096.);
  h2_hesumlesum= new TH2F("h2_hesumlesum","lesum:hesum",512,0.,4096.,512,0.,4096.);
  h2_hele = new TH2F("h2_hele","le:he",512,0,4096,512,0,4096);
  
  h2_xrftof = new TH2F("h2_xrftof","rftof:x",512, 0.,1024.,1024,0.,4096.);
  h2_rftof_spare= new TH2F("h2_rftof_spare","rftof:dssd-ppac",1024, 0.,4096,1024,0.,4096.);

  xrftofg = new TH2F("xrftofg","rftof:x(Time gated)",512,0.,1024.,1024,0.,4096.);
  xrftofg1 = new TH2F("xrftofg1","rftof:x(Time gated && proton)",512,0.,1024.,1024,0.,4096.);
  h2_xcath = new TH2F("h2_xcath", "cath:x",512,0.,1024.,512,0.,4096.);
  h2_xde1 = new TH2F("h2_xde1","de1:x",512,0.,1024.,512,0.,4096.);
  h2_xde23 = new TH2F("h2_xde23","de23:x",512,0.,1024.,512,0.,4096.);
  h2_xde4= new TH2F("h2_xde4","de4:x",512,0.,1024.,512,0.,4096.);
  h2_xYpos= new TH2F("h2_xYpos","Ypos:x",512,0.,1024.,512,0.,4096.);
  h2_xde4g = new TH2F("h2_xde4g","de4:x",512,0.,1024.,512,0.,4096.);
  h2_de4rftof = new TH2F("h2_de4rftof","rftof:de4",1024,0.,4096.,512,0.,4096.);
  h2_de23 = new TH2F("h2_de23","de3:de2",1024,0.,4096.,1024,0.,4096.);
  

  h1_E = new TH1F("h1_E","E",1024,0.,4096.);
  h1_DE = new TH1F("h1_DE","DE",1024,0., 4096.);
  h1_ESUM = new TH1F("h1_ESUM","h1_ESUM",1024,0,4096);
  h2_EDE = new TH2F("h2_EDE","DE vs. E",1024,0.,4096.,1024,0.,4096.);
  h2_Erf = new TH2F("h2_Erf","rf vs. E",512,0.,4096.,512,0.,4096.);
  h2_DErf = new TH2F("h2_DErf","rf vs. DE",512,0.,4096.,512,0.,4096.);
  h2_DErfg = new TH2F("h2_DErfg","rf vs. DE",512,0.,4096.,512,0.,4096.);
 
  // DSSD histograms

  hELudR1=new TH2F("hELudR1","Ring1 vs E raw",4096,0,4096,17,0,17); 
  hELudW1=new TH2F("hELudW1","Wedge1 vs E raw",4096,0,4096,17,0,17); 
 
  hELudR2=new TH2F("hELudR2","Ring2 vs E raw",4096,0,4096,17,0,17); 
  hELudW2=new TH2F("hELudW2","Wedge2 vs E raw",4096,0,4096,17,0,17);

  hER1=new TH2F("hER1","Ring1 vs E calib",4000,0,100,17,0,17);  
  hER2=new TH2F("hER2","Ring2 vs E calib",4000,0,100,17,0,17);
  hEW1=new TH2F("hEW1","Wedge1 vs E calib",4000,0,100,17,0,17);
  hEW2=new TH2F("hEW2","Wedge2 vs E calib",4000,0,100,17,0,17); 

  hER=new TH2F("hER","Ring vs Energy all",1000,0,10,50,0,50);
 
  hTAC=new TH2F("hTAC","T(DSSD-PPAC)",512,0,4096,512,0,4096);
 
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

  hHitxy1=new TH2F("hHitxy1","Y vs X DSSD (goodediff)",200,-50,50,200,-50,50);
  hHitxy2=new TH2F("hHitxy2","Y vs X DSSD (goodediff&goodT)",200,-50,50,200,-50,50);

  hADC2=new TH2F("hADC2","Raw ADC2 (Wedges)",1024,0,4096,16,0,16);
  hADC3=new TH2F("hADC3","Raw ADC3 (Rings)",1024,0,4096,16,0,16);
  
  /* stopped flag for Elliot's scaler program */
  for (Int_t i=0; i<NSCALERS; i++) totals[i]=0;
  stopped = 1;
  
  return 0;
}

int userdecode(ScarletEvnt &event) {

  if(iverb) cout << "_______________________________________ " << endl;
  if(iverb) cout << "Event " << nevent << endl << endl;
  treeinit();
  ScarletEvnt subevent1;
  Int_t dataword;
    
  TRandom *rannum = new TRandom();

  subevent1=event[1];
  int *p1 = reinterpret_cast<int*>(subevent1.body());
  int *p;
  
  Float_t lowthresh=100;
  
  Bool_t done=kFALSE;
  
  Float_t ediff;

  Int_t Rpat[3],Wpat[3],Rbitcnt[3]={0,0,0},Wbitcnt[3]={0,0,0};
  Int_t RRawData[3][16],WRawData[3][16];
  Int_t RChan[3][16],WChan[3][16];
  Float_t RData[3][16],WData[3][16];
  
  Int_t ndet=0;
 
  double stime, stime_1s;
  Bool_t goodCl=kFALSE;
  Bool_t goodAr=kFALSE;
  Bool_t garbage=kFALSE;
 
  nevent++;

  if(iverb) cout << "enter unpacking routine" << endl;
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
  if(iverb) cout << "unpacking DSSDs" << endl;
  for (Int_t ndet=0; ndet<2; ++ndet) {
    /* get Wedge hit pattern, count bits, then store data & channel */
    /* calibration constants put the energy into MeV */
    /* E_Bmax, nmaxW and detmaxW have similar meanings to emaxR etc below */

    Wpat[ndet]=*p++;
      
    Wbitcnt[ndet]=cntbit(Wpat[ndet]);
      cout << "before wedge ndat" << endl;
for (Int_t ndat=0; ndat<Wbitcnt[ndet]; ndat++) {
      if(iverb) cout << "wedge " << ndet << endl;
      dataword=*p++;
      WChan[ndet][ndat] = ((dataword & 0x0000f000)>>12);
      WRawData[ndet][ndat] = (dataword & 0x00000fff);
    
        WData[ndet][ndat] = (WRawData[ndet][ndat] - Woffset[ndet][WChan[ndet][ndat]])*Wslope[ndet][WChan[ndet][ndat]];
    WData[ndet][ndat] = WData[ndet][ndat]/1000;
   // WData[ndet][ndat] = Woffset[ndet][WChan[ndet][ndat]] + Wslope[ndet][WChan[ndet][ndat]]*WRawData[ndet][ndat];
        
    if(ndet==1){ //dE
        //if(WData[ndet][ndat]>0.1){  // threshold of 0.1 MeV in calibrated wedge energy
           
            dE_Benergy_raw[dE_Bmult] = WRawData[ndet][ndat];
            dE_Bnum[dE_Bmult] = WChan[ndet][ndat];
            dE_Benergy[dE_Bmult] = WData[ndet][ndat]; //MeV
         dE_Bmult++; // there's an event, so start at mult = 1
        //}
    }else if(ndet==0){ //E
        //if(WData[ndet][ndat]>0.1){
            E_Benergy_raw[E_Bmult] = WRawData[ndet][ndat];
            E_Bnum[E_Bmult] = WChan[ndet][ndat];
            E_Benergy[E_Bmult] = WData[ndet][ndat]; // MeV
            E_Bmult++;
        //}
    }
       
    for(i=0;i<dE_Bmult;i++){
     if (dE_Benergy[i]>dE_Bmax){
         dE_Bmax=dE_Benergy[i];
         dE_Bmaxnum = dE_Bnum[i];
     }}
     for(i=0;i<E_Bmult;i++){
     if (E_Benergy[i]>E_Bmax){
         E_Bmax=E_Benergy[i];
         E_Bmaxnum = E_Bnum[i];
     }}
    
       if(iverb){
       	cout << "WChan["<<ndet<<"]["<<ndat<<"] = " << WChan[ndet][ndat] << endl;
       	cout << "WRawData["<<ndet<<"]["<<ndat<<"] = " << WRawData[ndet][ndat] << endl;
        for(i=0;i<dE_Bmult;i++) cout << "dE_Benergy["<<i<<"]["<<dE_Bnum[i]<<"] = " << dE_Benergy[i] << endl;
       	for(i=0;i<E_Bmult;i++) cout << ", E_Benergy["<<i<<"]["<<E_Bnum[i]<<"] = " << E_Benergy[i] << endl;
       	cout << "dE_Bmax = " << dE_Bmax << ", dE_Bmaxnum = " << dE_Bmaxnum << endl;
        cout << "E_Bmax = " << E_Bmax << ", E_Bmaxnum = " << E_Bmaxnum << endl;
       }
      
	hELudW1->Fill(WRawData[0][ndat],WChan[0][ndat]);
	hEW1->Fill(WData[0][ndat],WChan[0][ndat]);
	hELudW2->Fill(WRawData[1][ndat],WChan[1][ndat]);
	hEW2->Fill(WData[1][ndat],WChan[1][ndat]);
    }
  }

for (Int_t ndet=0; ndet<2; ++ndet) {
    /* get Ring hit pattern, count bits, then store data & channel */
    /* calibration constants put the energy into MeV */
    
    Rpat[ndet]=*p++;
    Rbitcnt[ndet]=cntbit(Rpat[ndet]);

    for (Int_t ndat=0;ndat<Rbitcnt[ndet];ndat++) {
        if(iverb) cout << "Ring " << ndet << endl;
        dataword=*p++;
      
        RChan[ndet][ndat]=((dataword & 0x0000f000)>>12);
        RRawData[ndet][ndat]=(dataword & 0x00000fff);
       // RData[ndet][ndat]= Roffset[ndet][RChan[ndet][ndat]]+Rslope[ndet][RChan[ndet][ndat]]*RRawData[ndet][ndat];
        RData[ndet][ndat] = (RRawData[ndet][ndat] - Roffset[ndet][RChan[ndet][ndat]])*Rslope[ndet][RChan[ndet][ndat]];
        RData[ndet][ndat] = RData[ndet][ndat]/1000;
        
        if(ndet==1){ //dE
              //if(RData[ndet][ndat]>0.1){  // threshold of 0.1 MeV in calibrated ring energy
                  
                  dE_Fenergy_raw[dE_Fmult] = RRawData[ndet][ndat];
                  dE_Fnum[dE_Fmult] = RChan[ndet][ndat];
                  dE_Fenergy[dE_Fmult] = RData[ndet][ndat]; //MeV
                dE_Fmult++; // there's an event, so start at mult = 1
              //}
          }else if(ndet==0){ //E
              //if(RData[ndet][ndat]>0.1){
                 
                  E_Fenergy_raw[E_Fmult] = RRawData[ndet][ndat];
                  E_Fnum[E_Fmult] = RChan[ndet][ndat];
                  E_Fenergy[E_Fmult] = RData[ndet][ndat]; // MeV
                E_Fmult++;
              //}
          }
             
          for(i=0;i<dE_Fmult;i++){
           if (dE_Fenergy[i]>dE_Fmax){
               dE_Fmax=dE_Fenergy[i];
               dE_Fmaxnum = dE_Fnum[i];
           }}
           for(i=0;i<E_Fmult;i++){
           if (E_Fenergy[i]>E_Fmax){
               E_Fmax=E_Fenergy[i];
               E_Fmaxnum = E_Fnum[i];
           }}
          
             if(iverb){
              cout << "RChan["<<ndet<<"]["<<ndat<<"] = " << RChan[ndet][ndat] << endl;
              cout << "RRawData["<<ndet<<"]["<<ndat<<"] = " << RRawData[ndet][ndat] << endl;
              cout << "Rdata["<<ndet<<"]["<<ndat<<"] = " << RData[ndet][ndat] << endl;
              for(i=0;i<dE_Fmult;i++) cout << "dE_Fenergy["<<i<<"]["<<dE_Fnum[i]<<"] = " << dE_Fenergy[i] << endl;
              for(i=0;i<E_Fmult;i++) cout << "E_Fenergy["<<i<<"]["<<E_Fnum[i]<<"] = " << E_Fenergy[i] << endl;
              cout << "dE_Fmax = " << dE_Fmax << ", dE_Fmaxnum = " << dE_Fmaxnum << endl;
              cout << "E_Fmax = " << E_Fmax << ", E_Fmaxnum = " << E_Fmaxnum << endl;
             }
            
          hELudR1->Fill(RRawData[0][ndat],RChan[0][ndat]);
          hER1->Fill(RData[0][ndat],RChan[0][ndat]);
          hELudR2->Fill(RRawData[1][ndat],RChan[1][ndat]);
          hER2->Fill(RData[1][ndat],RChan[1][ndat]);
    }
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
  if(iverb) cout << endl << "myppac routine: " << hepo << " " << hepi << " " << lepo << " " << lepi << " " << up << " " << down << endl;

  // select whether high/low/both (he/le/pospp) energy side  
  //Float_t x = myppac->pospp;
  x = myppac->pospp;
  Float_t Ypos=0.;
  Ypos=0.5*(up-down)+2000.;
  Ypos=myppac->ud;

  Float_t posppb = 0.0;
  if( de[1] > 2 && de[1] < 4000 && de[2] > 2 && de[2]< 4000 ) 
    posppb = 1000.0*(de[1]-de[2])/(de[1]+de[2]);

  if(iverb) cout << "filling premade histograms... " << endl;
  // fill 1d histograms
  for(int i=0;i<5;i++) { h1_de[i]->Fill(de[i]);}
  h1_cathode->Fill(cathode);
  h1_grid->Fill(grid);
  t2=grid; // grid is TAC between RF and SSB =t2
if(iverb) cout << "TAC between RF and SSB = " << grid << endl;
  h1_rftof->Fill(rftof);
  h1_mon->Fill(mon);
  h1_spare->Fill(spare); //spare is TAC between DSSD and PPAC =t1
if(iverb) cout << "spare = TAC between DSSD and PPAC = " << spare << endl;
  t1=spare;

  h1_E->Fill(E);
  h1_DE->Fill(DE);
  h1_ESUM->Fill(E+DE);
  h1_pospp->Fill(myppac->pospp);

  h1_hepo->Fill(hepo);
  h1_hepi->Fill(hepi);
  h1_lepo->Fill(lepo);
  h1_lepi->Fill(lepi);
  h1_up->Fill(up);
  h1_down->Fill(down);
  if((hepo>=50 && hepo<=4000 )&&(hepi>=50 && hepi<=4000)) h1_hesum->Fill(0.25*(hepo+hepi));
  if((lepo>=50 && lepo<=4000 )&&(lepi>=50 && lepi<=4000)) h1_lesum->Fill(0.25*(lepo+lepi));
  if((up>0)&&(up<4000)&&(down>0)&&(down<4000)) h1_udsum->Fill(0.5*(up+down));

  h1_he->Fill(myppac->he);
  h2_hele->Fill(myppac->he,myppac->le);
  h1_le->Fill(myppac->le);
  h1_ud->Fill(Ypos); 
 
  // fill 2d histograms
  h2_EDE->Fill(E,DE);
  h2_Erf->Fill(E,rftof);
  h2_DErf->Fill(DE,rftof);
  if(E>900 && E<1150 && DE>2600 && DE<2850) h2_DErfg->Fill(DE,rftof); 

  h2_hepohepi->Fill(hepo,hepi);
  h2_lepolepi->Fill(lepo,lepi);
  h2_hesumlesum->Fill(myppac->hesum,myppac->lesum);
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
    hER1g->Fill(E_Fmax,E_Fmaxnum);
    if (rftof>2000 && rftof<3500) hER1g2->Fill(E_Fmax,E_Bmaxnum);
    hEW1g->Fill(E_Bmax,E_Bmaxnum);
    if(checkcutg("xrfcut1",x,rftof)){ hER1_gtxrf1->Fill(E_Fmax,E_Bmaxnum);}
    if(checkcutg("xrfcut2",x,rftof)){ hER1_gtxrf2->Fill(E_Fmax,E_Bmaxnum);}
    if(checkcutg("xde4g1",x,de[3])){ hER1_gtxde41->Fill(E_Fmax,E_Bmaxnum);}
    if(checkcutg("xde4g2",x,de[3])){ hER1_gtxde42->Fill(E_Fmax,E_Bmaxnum);}
    if(checkcutg("xde4g3",x,de[3])){ hER1_gtxde43->Fill(E_Fmax,E_Bmaxnum);}
    if(checkcutg("xde4g4",x,de[3])){ hER1_gtxde44->Fill(E_Fmax,E_Bmaxnum);}
    if(checkcutg("de4rfg1",de[3],rftof)){ hER1_gtde4rf1->Fill(E_Fmax,E_Bmaxnum);}
    if(checkcutg("de4rfg2",de[3],rftof)){ hER1_gtde4rf2->Fill(E_Fmax,E_Bmaxnum);}
    if(checkcutg("de4rfg3",de[3],rftof)){ hER1_gtde4rf3->Fill(E_Fmax,E_Bmaxnum);}
    if(checkcutg("de4rfg4",de[3],rftof)){ hER1_gtde4rf4->Fill(E_Fmax,E_Bmaxnum);}
  }
  
 
  tree->Fill();
    if(iverb) cout << "treefill" << endl;
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
