/* **************************************************************** */
/* Plotter for looking at the dE gain shift after Run 119           */
/* As a check, it will plot dE for *all runs* and then get the gain */
/* **************************************************************** */
#include <TFile.h>
#include <TTree.h>
#include <TCanvas.h>
#include <TGraph.h>
#include <TF1.h>
#include <TH1.h>
#include <fstream>
#include <iostream>
#include <TSpectrum.h>

using namespace std;
int gainshift(){
  ofstream output;
  output.open("peaks.txt");

  //  TCanvas *c1 = new TCanvas("c1","c1",1600,800);
  TFile *f[275];
    TH1F *h[275];
TSpectrum *sp[275];
  
  char runbuf[100];
  int i;

  

  /* f[96] = new TFile("/disks/1/gwilson/25Al/sorted/run96.root");
  t[96] = (TTree *)f[96]->Get("tree");
  t[96]->Draw("dE_Fenergy>>h96(1000,0,10)","E_Fenergy>30&&E_Fenergy<60");
  for(i=119;i<200;i++){
    sprintf(runbuf,"/disks/1/gwilson/25Al/sorted/run%d.root",i);
    sprintf(hist,"h%d",i);
   
    f[i] = new TFile(runbuf);
    t[i] = (TTree *)f[i]->Get("tree");
    t[i]->Draw("dE_Fenergy>>h[i](1000,0,10)","E_Fenergy>30&&E_Fenergy<60","same");
    
    
}
  */

  for(i=96;i<276;i++){
     sprintf(runbuf,"/disks/1/gwilson/25Al/sorted/run%d.root",i);
     f[i] = new TFile(runbuf);
     h[i] = (TH1F *)f[i]->Get("hdEshift");
     sp[i]= new TSpectrum();
     sp[i]->Search(h[i],2,"",0.05);

     if(sp[i]->GetNPeaks()==2){
     float *chan = sp[i]->GetPositionX();
     output << i;
     for(int n=0;n<2;n++){
       output << " " << chan[n];
     }
     output << endl;
     }
     f[i]->Close();
  }
  
     output.close();
     return 0;

}

