//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Thu Aug 29 08:59:44 2019 by ROOT version 5.32/03
// from TTree tree/sorted data
// found on file: testoutput.root
//////////////////////////////////////////////////////////

#ifndef analysis_h
#define analysis_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <iomanip>
#include <iostream>

// Header file for the classes stored in the TTree if any.

// Fixed size dimensions of array or collections stored in the TTree if any.

class analysis {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   UInt_t          dE_FMult;
   UInt_t          dE_BMult;
   Float_t         dE_Fenergy[16];   //[dE_Fmult]
   Float_t         dE_Benergy[16];   //[dE_Bmult]
   UInt_t          dE_Fnum[16];   //[dE_Fmult]
   UInt_t          dE_Bnum[16];   //[dE_Bmult]
   Float_t         dE_Fenergy_raw[16];   //[dE_Fmult]
   Float_t         dE_Benergy_raw[16];   //[dE_Bmult]
   UInt_t          E_FMult;
   UInt_t          E_BMult;
   Float_t         E_Fenergy[16];   //[E_Fmult]
   Float_t         E_Benergy[16];   //[E_Bmult]
   UInt_t          E_Fnum[16];   //[E_Fmult]
   UInt_t          E_Bnum[16];   //[E_Bmult]
   Float_t         E_Fenergy_raw[16];   //[E_Fmult]
   Float_t         E_Benergy_raw[16];   //[E_Bmult]
   Float_t         E_Fmax;
   Float_t         E_Bmax;
   Float_t         dE_Fmax;
   Float_t         dE_Bmax;
   UInt_t          E_Fmaxnum;
   UInt_t          E_Bmaxnum;
   UInt_t          dE_Fmaxnum;
   UInt_t          dE_Bmaxnum;
   Float_t         de[5];
   Float_t         cathode;
   Float_t         grid;
   Float_t         x;
   Float_t         y;
   Float_t         rftof;
   Float_t         mon;
   Float_t         spare;
   Float_t         t1;
   Float_t         t2;
   Float_t         E;
   Float_t         DE;
   Float_t         up;
   Float_t         stime0;
   Float_t         stime1;
   Float_t         stime2;
   Float_t         hepo;
   Float_t         hepi;
   Float_t         lepo;
   Float_t         lepi;
   Float_t         down;

   Int_t i,j,k;

   // List of branches
   TBranch        *b_dE_Fmult;   //!
   TBranch        *b_dE_Bmult;   //!
   TBranch        *b_dE_Fenergy;   //!
   TBranch        *b_dE_Benergy;   //!
   TBranch        *b_dE_Fnum;   //!
   TBranch        *b_dE_Bnum;   //!
   TBranch        *b_dE_Fenergy_raw;   //!
   TBranch        *b_dE_Benergy_raw;   //!
   TBranch        *b_E_Fmult;   //!
   TBranch        *b_E_Bmult;   //!
   TBranch        *b_E_Fenergy;   //!
   TBranch        *b_E_Benergy;   //!
   TBranch        *b_E_Fnum;   //!
   TBranch        *b_E_Bnum;   //!
   TBranch        *b_E_Fenergy_raw;   //!
   TBranch        *b_E_Benergy_raw;   //!
   TBranch        *b_E_Fmax;   //!
   TBranch        *b_E_Bmax;   //!
   TBranch        *b_dE_Fmax;   //!
   TBranch        *b_dE_Bmax;   //!
   TBranch        *b_E_Fmaxnum;   //!
   TBranch        *b_E_Bmaxnum;   //!
   TBranch        *b_dE_Fmaxnum;   //!
   TBranch        *b_dE_Bmaxnum;   //!
   TBranch        *b_de;   //!
   TBranch        *b_cathode;   //!
   TBranch        *b_grid;   //!
   TBranch        *b_x;   //!
   TBranch        *b_y;   //!
   TBranch        *b_rftof;   //!
   TBranch        *b_mon;   //!
   TBranch        *b_spare;   //!
   TBranch        *b_t1;   //!
   TBranch        *b_t2;   //!
   TBranch        *b_E;   //!
   TBranch        *b_DE;   //!
   TBranch        *b_up;   //!
   TBranch        *b_stime0;   //!
   TBranch        *b_stime1;   //!
   TBranch        *b_stime2;   //!
   TBranch        *b_hepo;   //!
   TBranch        *b_hepi;   //!
   TBranch        *b_lepo;   //!
   TBranch        *b_lepi;   //!
   TBranch        *b_down;   //!

   analysis(TTree *t=0);
   virtual ~analysis();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *t);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef analysis_c
analysis::analysis(TTree *t) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (t == 0) {
     #ifdef SINGLE_TREE
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("/disks/1/gwilson/25Al/sorted/run101.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("/disks/1/gwilson/25Al/sorted/run101.root");
      }
      f->GetObject("tree",t);
      #else
      TChain *chain = new TChain("tree","");
      // 12ug
      /* 
      chain->Add("/disks/1/gwilson/25Al/sorted/run265.root"); 
      chain->Add("/disks/1/gwilson/25Al/sorted/run266.root"); 
      chain->Add("/disks/1/gwilson/25Al/sorted/run267.root"); 
      chain->Add("/disks/1/gwilson/25Al/sorted/run268.root"); 
      chain->Add("/disks/1/gwilson/25Al/sorted/run270.root"); 
      chain->Add("/disks/1/gwilson/25Al/sorted/run271.root"); 
      chain->Add("/disks/1/gwilson/25Al/sorted/run273.root"); 
      chain->Add("/disks/1/gwilson/25Al/sorted/run275.root");
      */
      // 8ug
      /* 
      chain->Add("/disks/1/gwilson/25Al/sorted/run230.root"); 
      chain->Add("/disks/1/gwilson/25Al/sorted/run234.root"); 
      chain->Add("/disks/1/gwilson/25Al/sorted/run236.root"); 
      chain->Add("/disks/1/gwilson/25Al/sorted/run243.root"); 
      chain->Add("/disks/1/gwilson/25Al/sorted/run244.root"); 
      chain->Add("/disks/1/gwilson/25Al/sorted/run246.root"); 
      chain->Add("/disks/1/gwilson/25Al/sorted/run247.root"); 
      chain->Add("/disks/1/gwilson/25Al/sorted/run249.root");
      chain->Add("/disks/1/gwilson/25Al/sorted/run250.root"); 
      chain->Add("/disks/1/gwilson/25Al/sorted/run252.root"); 
      chain->Add("/disks/1/gwilson/25Al/sorted/run253.root"); 
      chain->Add("/disks/1/gwilson/25Al/sorted/run257.root"); 
      chain->Add("/disks/1/gwilson/25Al/sorted/run258.root");
      chain->Add("/disks/1/gwilson/25Al/sorted/run231.root"); 
      chain->Add("/disks/1/gwilson/25Al/sorted/run232.root"); 
      chain->Add("/disks/1/gwilson/25Al/sorted/run259.root"); 
      */
      //4ug
      /*
      chain->Add("/disks/1/gwilson/25Al/sorted/run197.root"); 
      chain->Add("/disks/1/gwilson/25Al/sorted/run200.root"); 
      chain->Add("/disks/1/gwilson/25Al/sorted/run201.root"); 
      chain->Add("/disks/1/gwilson/25Al/sorted/run203.root"); 
      chain->Add("/disks/1/gwilson/25Al/sorted/run204.root"); 
      chain->Add("/disks/1/gwilson/25Al/sorted/run206.root"); 
      chain->Add("/disks/1/gwilson/25Al/sorted/run207.root"); 
      chain->Add("/disks/1/gwilson/25Al/sorted/run209.root");
      chain->Add("/disks/1/gwilson/25Al/sorted/run210.root"); 
      chain->Add("/disks/1/gwilson/25Al/sorted/run213.root"); 
      chain->Add("/disks/1/gwilson/25Al/sorted/run214.root"); 
      chain->Add("/disks/1/gwilson/25Al/sorted/run215.root"); 
      chain->Add("/disks/1/gwilson/25Al/sorted/run223.root");
      */
      //2ug 
      /* 
      chain->Add("/disks/1/gwilson/25Al/sorted/run147.root"); 
      chain->Add("/disks/1/gwilson/25Al/sorted/run148.root"); 
      chain->Add("/disks/1/gwilson/25Al/sorted/run150.root"); 
      chain->Add("/disks/1/gwilson/25Al/sorted/run153.root"); 
      chain->Add("/disks/1/gwilson/25Al/sorted/run154.root"); 
      chain->Add("/disks/1/gwilson/25Al/sorted/run155.root"); 
      chain->Add("/disks/1/gwilson/25Al/sorted/run157.root"); 
      chain->Add("/disks/1/gwilson/25Al/sorted/run158.root");
      chain->Add("/disks/1/gwilson/25Al/sorted/run160.root"); 
      chain->Add("/disks/1/gwilson/25Al/sorted/run161.root"); 
      chain->Add("/disks/1/gwilson/25Al/sorted/run162.root"); 
      chain->Add("/disks/1/gwilson/25Al/sorted/run164.root"); 
      chain->Add("/disks/1/gwilson/25Al/sorted/run165.root");
      chain->Add("/disks/1/gwilson/25Al/sorted/run167.root"); 
      chain->Add("/disks/1/gwilson/25Al/sorted/run169.root"); 
      chain->Add("/disks/1/gwilson/25Al/sorted/run170.root"); 
      chain->Add("/disks/1/gwilson/25Al/sorted/run172.root"); 
      chain->Add("/disks/1/gwilson/25Al/sorted/run173.root"); 
      chain->Add("/disks/1/gwilson/25Al/sorted/run175.root");
      chain->Add("/disks/1/gwilson/25Al/sorted/run176.root"); 
      chain->Add("/disks/1/gwilson/25Al/sorted/run179.root"); 
      chain->Add("/disks/1/gwilson/25Al/sorted/run182.root"); 
      chain->Add("/disks/1/gwilson/25Al/sorted/run183.root"); 
      */  
      // no degrader 
      	  
       chain->Add("/disks/1/gwilson/25Al/sorted/run99.root"); 
       chain->Add("/disks/1/gwilson/25Al/sorted/run100.root"); 
       chain->Add("/disks/1/gwilson/25Al/sorted/run101.root"); 
       chain->Add("/disks/1/gwilson/25Al/sorted/run105.root"); 
       chain->Add("/disks/1/gwilson/25Al/sorted/run106.root"); 
       chain->Add("/disks/1/gwilson/25Al/sorted/run113.root"); 
       chain->Add("/disks/1/gwilson/25Al/sorted/run116.root"); 
       chain->Add("/disks/1/gwilson/25Al/sorted/run117.root");
     
       t = chain;
       #endif
   }
   Init(t);
}

analysis::~analysis()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t analysis::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t analysis::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void analysis::Init(TTree *t)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!t) return;
   fChain = t;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("dE_FMult", &dE_FMult, &b_dE_Fmult);
   fChain->SetBranchAddress("dE_BMult", &dE_BMult, &b_dE_Bmult);
   fChain->SetBranchAddress("dE_Fenergy", dE_Fenergy, &b_dE_Fenergy);
   fChain->SetBranchAddress("dE_Benergy", dE_Benergy, &b_dE_Benergy);
   fChain->SetBranchAddress("dE_Fnum", dE_Fnum, &b_dE_Fnum);
   fChain->SetBranchAddress("dE_Bnum", dE_Bnum, &b_dE_Bnum);
   fChain->SetBranchAddress("dE_Fenergy_raw", dE_Fenergy_raw, &b_dE_Fenergy_raw);
   fChain->SetBranchAddress("dE_Benergy_raw", dE_Benergy_raw, &b_dE_Benergy_raw);
   fChain->SetBranchAddress("E_FMult", &E_FMult, &b_E_Fmult);
   fChain->SetBranchAddress("E_BMult", &E_BMult, &b_E_Bmult);
   fChain->SetBranchAddress("E_Fenergy", E_Fenergy, &b_E_Fenergy);
   fChain->SetBranchAddress("E_Benergy", E_Benergy, &b_E_Benergy);
   fChain->SetBranchAddress("E_Fnum", E_Fnum, &b_E_Fnum);
   fChain->SetBranchAddress("E_Bnum", E_Bnum, &b_E_Bnum);
   fChain->SetBranchAddress("E_Fenergy_raw", E_Fenergy_raw, &b_E_Fenergy_raw);
   fChain->SetBranchAddress("E_Benergy_raw", E_Benergy_raw, &b_E_Benergy_raw);
   fChain->SetBranchAddress("E_Fmax", &E_Fmax, &b_E_Fmax);
   fChain->SetBranchAddress("E_Bmax", &E_Bmax, &b_E_Bmax);
   fChain->SetBranchAddress("dE_Fmax", &dE_Fmax, &b_dE_Fmax);
   fChain->SetBranchAddress("dE_Bmax", &dE_Bmax, &b_dE_Bmax);
   fChain->SetBranchAddress("E_Fmaxnum", &E_Fmaxnum, &b_E_Fmaxnum);
   fChain->SetBranchAddress("E_Bmaxnum", &E_Bmaxnum, &b_E_Bmaxnum);
   fChain->SetBranchAddress("dE_Fmaxnum", &dE_Fmaxnum, &b_dE_Fmaxnum);
   fChain->SetBranchAddress("dE_Bmaxnum", &dE_Bmaxnum, &b_dE_Bmaxnum);
   fChain->SetBranchAddress("de", de, &b_de);
   fChain->SetBranchAddress("cathode", &cathode, &b_cathode);
   fChain->SetBranchAddress("grid", &grid, &b_grid);
   fChain->SetBranchAddress("x", &x, &b_x);
   fChain->SetBranchAddress("y", &y, &b_y);
   fChain->SetBranchAddress("rftof", &rftof, &b_rftof);
   fChain->SetBranchAddress("mon", &mon, &b_mon);
   fChain->SetBranchAddress("spare", &spare, &b_spare);
   fChain->SetBranchAddress("t1", &t1, &b_t1);
   fChain->SetBranchAddress("t2", &t2, &b_t2);
   fChain->SetBranchAddress("E", &E, &b_E);
   fChain->SetBranchAddress("DE", &DE, &b_DE);
   fChain->SetBranchAddress("up", &up, &b_up);
   fChain->SetBranchAddress("stime0", &stime0, &b_stime0);
   fChain->SetBranchAddress("stime1", &stime1, &b_stime1);
   fChain->SetBranchAddress("stime2", &stime2, &b_stime2);
   fChain->SetBranchAddress("hepo", &hepo, &b_hepo);
   fChain->SetBranchAddress("hepi", &hepi, &b_hepi);
   fChain->SetBranchAddress("lepo", &lepo, &b_lepo);
   fChain->SetBranchAddress("lepi", &lepi, &b_lepi);
   fChain->SetBranchAddress("down", &down, &b_down);
   Notify();
}

Bool_t analysis::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void analysis::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t analysis::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef analysis_c
