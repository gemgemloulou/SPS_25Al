/* **************************************************************** */
/* Project all rings and wedges into their own histograms for       */
/* alpha calibration purposes. Might be a waste of time.            */
/* **************************************************************** */

#include <TCanvas.h>
#include <TGraph.h>
#include <TF1.h>
#include <fstream>
#include <iostream>

using namespace std;
int stripmaker(){
 
  TFile *f = new TFile("/disks/1/gwilson/25Al/sorted/post275/run300.root");
  TFile *ouf = new TFile("Run300_sbs.root","RECREATE");



  f->cd();
  TH2F *hELudR1 = (TH2F *)f->Get("hELudR1");
  TH2F *hELudR2 = (TH2F *)f->Get("hELudR2");
  TH2F *hELudW1 = (TH2F *)f->Get("hELudW1");
  TH2F *hELudW2 = (TH2F *)f->Get("hELudW2");


  ouf->cd();
  TH1D *hELudR1_1 = new TH1D("hELudR1_1","ring1_1 ",4096,0,4096);
  TH1D *hELudR1_2 = new TH1D("hELudR1_2","ring1_2 ",4096,0,4096);
  TH1D *hELudR1_3 = new TH1D("hELudR1_3","ring1_3 ",4096,0,4096);
  TH1D *hELudR1_4 = new TH1D("hELudR1_4","ring1_4 ",4096,0,4096);
  TH1D *hELudR1_5 = new TH1D("hELudR1_5","ring1_5 ",4096,0,4096);
  TH1D *hELudR1_6 = new TH1D("hELudR1_6","ring1_6 ",4096,0,4096);
  TH1D *hELudR1_7 = new TH1D("hELudR1_7","ring1_7 ",4096,0,4096);
  TH1D *hELudR1_8 = new TH1D("hELudR1_8","ring1_8 ",4096,0,4096);
  TH1D *hELudR1_9 = new TH1D("hELudR1_9","ring1_9 ",4096,0,4096);
  TH1D *hELudR1_10 = new TH1D("hELudR1_10","ring1_10 ",4096,0,4096);
  TH1D *hELudR1_11 = new TH1D("hELudR1_11","ring1_11 ",4096,0,4096);
  TH1D *hELudR1_12 = new TH1D("hELudR1_12","ring1_12 ",4096,0,4096);
  TH1D *hELudR1_13 = new TH1D("hELudR1_13","ring1_13 ",4096,0,4096);
  TH1D *hELudR1_14 = new TH1D("hELudR1_14","ring1_14 ",4096,0,4096);
  TH1D *hELudR1_15 = new TH1D("hELudR1_15","ring1_15 ",4096,0,4096);
  TH1D *hELudR1_16 = new TH1D("hELudR1_16","ring1_16 ",4096,0,4096);

  TH1D *hELudR2_1 = new TH1D("hELudR2_1","ring2_1 ",4096,0,4096);
  TH1D *hELudR2_2 = new TH1D("hELudR2_2","ring2_2 ",4096,0,4096);
  TH1D *hELudR2_3 = new TH1D("hELudR2_3","ring2_3 ",4096,0,4096);
  TH1D *hELudR2_4 = new TH1D("hELudR2_4","ring2_4 ",4096,0,4096);
  TH1D *hELudR2_5 = new TH1D("hELudR2_5","ring2_5 ",4096,0,4096);
  TH1D *hELudR2_6 = new TH1D("hELudR2_6","ring2_6 ",4096,0,4096);
  TH1D *hELudR2_7 = new TH1D("hELudR2_7","ring2_7 ",4096,0,4096);
  TH1D *hELudR2_8 = new TH1D("hELudR2_8","ring2_8 ",4096,0,4096);
  TH1D *hELudR2_9 = new TH1D("hELudR2_9","ring2_9 ",4096,0,4096);
  TH1D *hELudR2_10 = new TH1D("hELudR2_10","ring2_10 ",4096,0,4096);
  TH1D *hELudR2_11 = new TH1D("hELudR2_11","ring2_11 ",4096,0,4096);
  TH1D *hELudR2_12 = new TH1D("hELudR2_12","ring2_12 ",4096,0,4096);
  TH1D *hELudR2_13 = new TH1D("hELudR2_13","ring2_13 ",4096,0,4096);
  TH1D *hELudR2_14 = new TH1D("hELudR2_14","ring2_14 ",4096,0,4096);
  TH1D *hELudR2_15 = new TH1D("hELudR2_15","ring2_15 ",4096,0,4096);
  TH1D *hELudR2_16 = new TH1D("hELudR2_16","ring2_16 ",4096,0,4096);

  TH1D *hELudW1_1 = new TH1D("hELudW1_1","wedge1_1 ",4096,0,4096);
  TH1D *hELudW1_2 = new TH1D("hELudW1_2","wedge1_2 ",4096,0,4096);
  TH1D *hELudW1_3 = new TH1D("hELudW1_3","wedge1_3 ",4096,0,4096);
  TH1D *hELudW1_4 = new TH1D("hELudW1_4","wedge1_4 ",4096,0,4096);
  TH1D *hELudW1_5 = new TH1D("hELudW1_5","wedge1_5 ",4096,0,4096);
  TH1D *hELudW1_6 = new TH1D("hELudW1_6","wedge1_6 ",4096,0,4096);
  TH1D *hELudW1_7 = new TH1D("hELudW1_7","wedge1_7 ",4096,0,4096);
  TH1D *hELudW1_8 = new TH1D("hELudW1_8","wedge1_8 ",4096,0,4096);
  TH1D *hELudW1_9 = new TH1D("hELudW1_9","wedge1_9 ",4096,0,4096);
  TH1D *hELudW1_10 = new TH1D("hELudW1_10","wedge1_10 ",4096,0,4096);
  TH1D *hELudW1_11 = new TH1D("hELudW1_11","wedge1_11 ",4096,0,4096);
  TH1D *hELudW1_12 = new TH1D("hELudW1_12","wedge1_12 ",4096,0,4096);
  TH1D *hELudW1_13 = new TH1D("hELudW1_13","wedge1_13 ",4096,0,4096);
  TH1D *hELudW1_14 = new TH1D("hELudW1_14","wedge1_14 ",4096,0,4096);
  TH1D *hELudW1_15 = new TH1D("hELudW1_15","wedge1_15 ",4096,0,4096);
  TH1D *hELudW1_16 = new TH1D("hELudW1_16","wedge1_16 ",4096,0,4096);

  TH1D *hELudW2_1 = new TH1D("hELudW2_1","wedge2_1 ",4096,0,4096);
  TH1D *hELudW2_2 = new TH1D("hELudW2_2","wedge2_2 ",4096,0,4096);
  TH1D *hELudW2_3 = new TH1D("hELudW2_3","wedge2_3 ",4096,0,4096);
  TH1D *hELudW2_4 = new TH1D("hELudW2_4","wedge2_4 ",4096,0,4096);
  TH1D *hELudW2_5 = new TH1D("hELudW2_5","wedge2_5 ",4096,0,4096);
  TH1D *hELudW2_6 = new TH1D("hELudW2_6","wedge2_6 ",4096,0,4096);
  TH1D *hELudW2_7 = new TH1D("hELudW2_7","wedge2_7 ",4096,0,4096);
  TH1D *hELudW2_8 = new TH1D("hELudW2_8","wedge2_8 ",4096,0,4096);
  TH1D *hELudW2_9 = new TH1D("hELudW2_9","wedge2_9 ",4096,0,4096);
  TH1D *hELudW2_10 = new TH1D("hELudW2_10","wedge2_10 ",4096,0,4096);
  TH1D *hELudW2_11 = new TH1D("hELudW2_11","wedge2_11 ",4096,0,4096);
  TH1D *hELudW2_12 = new TH1D("hELudW2_12","wedge2_12 ",4096,0,4096);
  TH1D *hELudW2_13 = new TH1D("hELudW2_13","wedge2_13 ",4096,0,4096);
  TH1D *hELudW2_14 = new TH1D("hELudW2_14","wedge2_14 ",4096,0,4096);
  TH1D *hELudW2_15 = new TH1D("hELudW2_15","wedge2_15 ",4096,0,4096);
  TH1D *hELudW2_16 = new TH1D("hELudW2_16","wedge2_16 ",4096,0,4096);

  ouf->cd();

  hELudR1_1->Write();
  hELudR1_2->Write();
  hELudR1_3->Write();
  hELudR1_4->Write();
  hELudR1_5->Write();
  hELudR1_6->Write();
  hELudR1_7->Write();
  hELudR1_8->Write();
  hELudR1_9->Write();
  hELudR1_10->Write();
  hELudR1_11->Write();
  hELudR1_12->Write();
  hELudR1_13->Write();
  hELudR1_14->Write();
  hELudR1_15->Write();
  hELudR1_16->Write();

  hELudR2_1->Write();
  hELudR2_2->Write();
  hELudR2_3->Write();
  hELudR2_4->Write();
  hELudR2_5->Write();
  hELudR2_6->Write();
  hELudR2_7->Write();
  hELudR2_8->Write();
  hELudR2_9->Write();
  hELudR2_10->Write();
  hELudR2_11->Write();
  hELudR2_12->Write();
  hELudR2_13->Write();
  hELudR2_14->Write();
  hELudR2_15->Write();
  hELudR2_16->Write();

  hELudW1_1->Write();
  hELudW1_2->Write();
  hELudW1_3->Write();
  hELudW1_4->Write();
  hELudW1_5->Write();
  hELudW1_6->Write();
  hELudW1_7->Write();
  hELudW1_8->Write();
  hELudW1_9->Write();
  hELudW1_10->Write();
  hELudW1_11->Write();
  hELudW1_12->Write();
  hELudW1_13->Write();
  hELudW1_14->Write();
  hELudW1_15->Write();
  hELudW1_16->Write();

  hELudW2_1->Write();
  hELudW2_2->Write();
  hELudW2_3->Write();
  hELudW2_4->Write();
  hELudW2_5->Write();
  hELudW2_6->Write();
  hELudW2_7->Write();
  hELudW2_8->Write();
  hELudW2_9->Write();
  hELudW2_10->Write();
  hELudW2_11->Write();
  hELudW2_12->Write();
  hELudW2_13->Write();
  hELudW2_14->Write();
  hELudW2_15->Write();
  hELudW2_16->Write();


  return 0;
}
