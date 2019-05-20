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
 
  TFile *f = new TFile("cal_305.root");
  TFile *ouf = new TFile("processed/Run305_sbs.root","RECREATE");



  f->cd();
  TH2F *h_ELudR1 = (TH2F *)f->Get("hELudR1");
  TH2F *h_ELudR2 = (TH2F *)f->Get("hELudR2");
  TH2F *h_ELudW1 = (TH2F *)f->Get("hELudW1");
  TH2F *h_ELudW2 = (TH2F *)f->Get("hELudW2");
  TH2F *h_ER1 = (TH2F *)f->Get("hER1");
  TH2F *h_ER2 = (TH2F *)f->Get("hER2");
  TH2F *h_EW1 = (TH2F *)f->Get("hEW1");
  TH2F *h_EW2 = (TH2F *)f->Get("hEW2");

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

  TH1D *hER1_1 = new TH1D("hER1_1","ringcal1_1 ",2000,0,80);
  TH1D *hER1_2 = new TH1D("hER1_2","ringcal1_2 ",2000,0,80);
  TH1D *hER1_3 = new TH1D("hER1_3","ringcal1_3 ",2000,0,80);
  TH1D *hER1_4 = new TH1D("hER1_4","ringcal1_4 ",2000,0,80);
  TH1D *hER1_5 = new TH1D("hER1_5","ringcal1_5 ",2000,0,80);
  TH1D *hER1_6 = new TH1D("hER1_6","ringcal1_6 ",2000,0,80);
  TH1D *hER1_7 = new TH1D("hER1_7","ringcal1_7 ",2000,0,80);
  TH1D *hER1_8 = new TH1D("hER1_8","ringcal1_8 ",2000,0,80);
  TH1D *hER1_9 = new TH1D("hER1_9","ringcal1_9 ",2000,0,80);
  TH1D *hER1_10 = new TH1D("hER1_10","ringcal1_10 ",2000,0,80);
  TH1D *hER1_11 = new TH1D("hER1_11","ringcal1_11 ",2000,0,80);
  TH1D *hER1_12 = new TH1D("hER1_12","ringcal1_12 ",2000,0,80);
  TH1D *hER1_13 = new TH1D("hER1_13","ringcal1_13 ",2000,0,80);
  TH1D *hER1_14 = new TH1D("hER1_14","ringcal1_14 ",2000,0,80);
  TH1D *hER1_15 = new TH1D("hER1_15","ringcal1_15 ",2000,0,80);
  TH1D *hER1_16 = new TH1D("hER1_16","ringcal1_16 ",2000,0,80);

  TH1D *hER2_1 = new TH1D("hER2_1","ringcal2_1 ",2000,0,50);
  TH1D *hER2_2 = new TH1D("hER2_2","ringcal2_2 ",2000,0,50);
  TH1D *hER2_3 = new TH1D("hER2_3","ringcal2_3 ",2000,0,50);
  TH1D *hER2_4 = new TH1D("hER2_4","ringcal2_4 ",2000,0,50);
  TH1D *hER2_5 = new TH1D("hER2_5","ringcal2_5 ",2000,0,50);
  TH1D *hER2_6 = new TH1D("hER2_6","ringcal2_6 ",2000,0,50);
  TH1D *hER2_7 = new TH1D("hER2_7","ringcal2_7 ",2000,0,50);
  TH1D *hER2_8 = new TH1D("hER2_8","ringcal2_8 ",2000,0,50);
  TH1D *hER2_9 = new TH1D("hER2_9","ringcal2_9 ",2000,0,50);
  TH1D *hER2_10 = new TH1D("hER2_10","ringcal2_10 ",2000,0,50);
  TH1D *hER2_11 = new TH1D("hER2_11","ringcal2_11 ",2000,0,50);
  TH1D *hER2_12 = new TH1D("hER2_12","ringcal2_12 ",2000,0,50);
  TH1D *hER2_13 = new TH1D("hER2_13","ringcal2_13 ",2000,0,50);
  TH1D *hER2_14 = new TH1D("hER2_14","ringcal2_14 ",2000,0,50);
  TH1D *hER2_15 = new TH1D("hER2_15","ringcal2_15 ",2000,0,50);
  TH1D *hER2_16 = new TH1D("hER2_16","ringcal2_16 ",2000,0,50);

  TH1D *hEW1_1 = new TH1D("hEW1_1","wedgecal1_1 ",2000,0,80);
  TH1D *hEW1_2 = new TH1D("hEW1_2","wedgecal1_2 ",2000,0,80);
  TH1D *hEW1_3 = new TH1D("hEW1_3","wedgecal1_3 ",2000,0,80);
  TH1D *hEW1_4 = new TH1D("hEW1_4","wedgecal1_4 ",2000,0,80);
  TH1D *hEW1_5 = new TH1D("hEW1_5","wedgecal1_5 ",2000,0,80);
  TH1D *hEW1_6 = new TH1D("hEW1_6","wedgecal1_6 ",2000,0,80);
  TH1D *hEW1_7 = new TH1D("hEW1_7","wedgecal1_7 ",2000,0,80);
  TH1D *hEW1_8 = new TH1D("hEW1_8","wedgecal1_8 ",2000,0,80);
  TH1D *hEW1_9 = new TH1D("hEW1_9","wedgecal1_9 ",2000,0,80);
  TH1D *hEW1_10 = new TH1D("hEW1_10","wedgecal1_10 ",2000,0,80);
  TH1D *hEW1_11 = new TH1D("hEW1_11","wedgecal1_11 ",2000,0,80);
  TH1D *hEW1_12 = new TH1D("hEW1_12","wedgecal1_12 ",2000,0,80);
  TH1D *hEW1_13 = new TH1D("hEW1_13","wedgecal1_13 ",2000,0,80);
  TH1D *hEW1_14 = new TH1D("hEW1_14","wedgecal1_14 ",2000,0,80);
  TH1D *hEW1_15 = new TH1D("hEW1_15","wedgecal1_15 ",2000,0,80);
  TH1D *hEW1_16 = new TH1D("hEW1_16","wedgecal1_16 ",2000,0,80);

  TH1D *hEW2_1 = new TH1D("hEW2_1","wedgecal2_1 ",2000,0,50);
  TH1D *hEW2_2 = new TH1D("hEW2_2","wedgecal2_2 ",2000,0,50);
  TH1D *hEW2_3 = new TH1D("hEW2_3","wedgecal2_3 ",2000,0,50);
  TH1D *hEW2_4 = new TH1D("hEW2_4","wedgecal2_4 ",2000,0,50);
  TH1D *hEW2_5 = new TH1D("hEW2_5","wedgecal2_5 ",2000,0,50);
  TH1D *hEW2_6 = new TH1D("hEW2_6","wedgecal2_6 ",2000,0,50);
  TH1D *hEW2_7 = new TH1D("hEW2_7","wedgecal2_7 ",2000,0,50);
  TH1D *hEW2_8 = new TH1D("hEW2_8","wedgecal2_8 ",2000,0,50);
  TH1D *hEW2_9 = new TH1D("hEW2_9","wedgecal2_9 ",2000,0,50);
  TH1D *hEW2_10 = new TH1D("hEW2_10","wedgecal2_10 ",2000,0,50);
  TH1D *hEW2_11 = new TH1D("hEW2_11","wedgecal2_11 ",2000,0,50);
  TH1D *hEW2_12 = new TH1D("hEW2_12","wedgecal2_12 ",2000,0,50);
  TH1D *hEW2_13 = new TH1D("hEW2_13","wedgecal2_13 ",2000,0,50);
  TH1D *hEW2_14 = new TH1D("hEW2_14","wedgecal2_14 ",2000,0,50);
  TH1D *hEW2_15 = new TH1D("hEW2_15","wedgecal2_15 ",2000,0,50);
  TH1D *hEW2_16 = new TH1D("hEW2_16","wedgecal2_16 ",2000,0,50);

  h_ELudR1->ProjectionX("hELudR1_1",1,1);
  h_ELudR1->ProjectionX("hELudR1_2",2,2);
  h_ELudR1->ProjectionX("hELudR1_3",3,3);
  h_ELudR1->ProjectionX("hELudR1_4",4,4);
  h_ELudR1->ProjectionX("hELudR1_5",5,5);
  h_ELudR1->ProjectionX("hELudR1_6",6,6);
  h_ELudR1->ProjectionX("hELudR1_7",7,7);
  h_ELudR1->ProjectionX("hELudR1_8",8,8);
  h_ELudR1->ProjectionX("hELudR1_9",9,9);  
  h_ELudR1->ProjectionX("hELudR1_10",10,10);
  h_ELudR1->ProjectionX("hELudR1_11",11,11);
  h_ELudR1->ProjectionX("hELudR1_12",12,12);
  h_ELudR1->ProjectionX("hELudR1_13",13,13);
  h_ELudR1->ProjectionX("hELudR1_14",14,14);
  h_ELudR1->ProjectionX("hELudR1_15",15,15);
  h_ELudR1->ProjectionX("hELudR1_16",16,16);

  h_ELudR2->ProjectionX("hELudR2_1",1,1);
  h_ELudR2->ProjectionX("hELudR2_2",2,2);
  h_ELudR2->ProjectionX("hELudR2_3",3,3);
  h_ELudR2->ProjectionX("hELudR2_4",4,4);
  h_ELudR2->ProjectionX("hELudR2_5",5,5);
  h_ELudR2->ProjectionX("hELudR2_6",6,6);
  h_ELudR2->ProjectionX("hELudR2_7",7,7);
  h_ELudR2->ProjectionX("hELudR2_8",8,8);
  h_ELudR2->ProjectionX("hELudR2_9",9,9);  
  h_ELudR2->ProjectionX("hELudR2_10",10,10);
  h_ELudR2->ProjectionX("hELudR2_11",11,11);
  h_ELudR2->ProjectionX("hELudR2_12",12,12);
  h_ELudR2->ProjectionX("hELudR2_13",13,13);
  h_ELudR2->ProjectionX("hELudR2_14",14,14);
  h_ELudR2->ProjectionX("hELudR2_15",15,15);
  h_ELudR2->ProjectionX("hELudR2_16",16,16);

  h_ELudW1->ProjectionX("hELudW1_1",1,1);
  h_ELudW1->ProjectionX("hELudW1_2",2,2);
  h_ELudW1->ProjectionX("hELudW1_3",3,3);
  h_ELudW1->ProjectionX("hELudW1_4",4,4);
  h_ELudW1->ProjectionX("hELudW1_5",5,5);
  h_ELudW1->ProjectionX("hELudW1_6",6,6);
  h_ELudW1->ProjectionX("hELudW1_7",7,7);
  h_ELudW1->ProjectionX("hELudW1_8",8,8);
  h_ELudW1->ProjectionX("hELudW1_9",9,9);  
  h_ELudW1->ProjectionX("hELudW1_10",10,10);
  h_ELudW1->ProjectionX("hELudW1_11",11,11);
  h_ELudW1->ProjectionX("hELudW1_12",12,12);
  h_ELudW1->ProjectionX("hELudW1_13",13,13);
  h_ELudW1->ProjectionX("hELudW1_14",14,14);
  h_ELudW1->ProjectionX("hELudW1_15",15,15);
  h_ELudW1->ProjectionX("hELudW1_16",16,16);

  h_ELudW2->ProjectionX("hELudW2_1",1,1);
  h_ELudW2->ProjectionX("hELudW2_2",2,2);
  h_ELudW2->ProjectionX("hELudW2_3",3,3);
  h_ELudW2->ProjectionX("hELudW2_4",4,4);
  h_ELudW2->ProjectionX("hELudW2_5",5,5);
  h_ELudW2->ProjectionX("hELudW2_6",6,6);
  h_ELudW2->ProjectionX("hELudW2_7",7,7);
  h_ELudW2->ProjectionX("hELudW2_8",8,8);
  h_ELudW2->ProjectionX("hELudW2_9",9,9);  
  h_ELudW2->ProjectionX("hELudW2_10",10,10);
  h_ELudW2->ProjectionX("hELudW2_11",11,11);
  h_ELudW2->ProjectionX("hELudW2_12",12,12);
  h_ELudW2->ProjectionX("hELudW2_13",13,13);
  h_ELudW2->ProjectionX("hELudW2_14",14,14);
  h_ELudW2->ProjectionX("hELudW2_15",15,15);
  h_ELudW2->ProjectionX("hELudW2_16",16,16);

 
  h_ER1->ProjectionX("hER1_1",1,1);
  h_ER1->ProjectionX("hER1_2",2,2);
  h_ER1->ProjectionX("hER1_3",3,3);
  h_ER1->ProjectionX("hER1_4",4,4);
  h_ER1->ProjectionX("hER1_5",5,5);
  h_ER1->ProjectionX("hER1_6",6,6);
  h_ER1->ProjectionX("hER1_7",7,7);
  h_ER1->ProjectionX("hER1_8",8,8);
  h_ER1->ProjectionX("hER1_9",9,9);  
  h_ER1->ProjectionX("hER1_10",10,10);
  h_ER1->ProjectionX("hER1_11",11,11);
  h_ER1->ProjectionX("hER1_12",12,12);
  h_ER1->ProjectionX("hER1_13",13,13);
  h_ER1->ProjectionX("hER1_14",14,14);
  h_ER1->ProjectionX("hER1_15",15,15);
  h_ER1->ProjectionX("hER1_16",16,16);
 
  h_ER2->ProjectionX("hER2_1",1,1);
  h_ER2->ProjectionX("hER2_2",2,2);
  h_ER2->ProjectionX("hER2_3",3,3);
  h_ER2->ProjectionX("hER2_4",4,4);
  h_ER2->ProjectionX("hER2_5",5,5);
  h_ER2->ProjectionX("hER2_6",6,6);
  h_ER2->ProjectionX("hER2_7",7,7);
  h_ER2->ProjectionX("hER2_8",8,8);
  h_ER2->ProjectionX("hER2_9",9,9);  
  h_ER2->ProjectionX("hER2_10",10,10);
  h_ER2->ProjectionX("hER2_11",11,11);
  h_ER2->ProjectionX("hER2_12",12,12);
  h_ER2->ProjectionX("hER2_13",13,13);
  h_ER2->ProjectionX("hER2_14",14,14);
  h_ER2->ProjectionX("hER2_15",15,15);
  h_ER2->ProjectionX("hER2_16",16,16);

  h_EW1->ProjectionX("hEW1_1",1,1);
  h_EW1->ProjectionX("hEW1_2",2,2);
  h_EW1->ProjectionX("hEW1_3",3,3);
  h_EW1->ProjectionX("hEW1_4",4,4);
  h_EW1->ProjectionX("hEW1_5",5,5);
  h_EW1->ProjectionX("hEW1_6",6,6);
  h_EW1->ProjectionX("hEW1_7",7,7);
  h_EW1->ProjectionX("hEW1_8",8,8);
  h_EW1->ProjectionX("hEW1_9",9,9);  
  h_EW1->ProjectionX("hEW1_10",10,10);
  h_EW1->ProjectionX("hEW1_11",11,11);
  h_EW1->ProjectionX("hEW1_12",12,12);
  h_EW1->ProjectionX("hEW1_13",13,13);
  h_EW1->ProjectionX("hEW1_14",14,14);
  h_EW1->ProjectionX("hEW1_15",15,15);
  h_EW1->ProjectionX("hEW1_16",16,16);
 
  h_EW2->ProjectionX("hEW2_1",1,1);
  h_EW2->ProjectionX("hEW2_2",2,2);
  h_EW2->ProjectionX("hEW2_3",3,3);
  h_EW2->ProjectionX("hEW2_4",4,4);
  h_EW2->ProjectionX("hEW2_5",5,5);
  h_EW2->ProjectionX("hEW2_6",6,6);
  h_EW2->ProjectionX("hEW2_7",7,7);
  h_EW2->ProjectionX("hEW2_8",8,8);
  h_EW2->ProjectionX("hEW2_9",9,9);  
  h_EW2->ProjectionX("hEW2_10",10,10);
  h_EW2->ProjectionX("hEW2_11",11,11);
  h_EW2->ProjectionX("hEW2_12",12,12);
  h_EW2->ProjectionX("hEW2_13",13,13);
  h_EW2->ProjectionX("hEW2_14",14,14);
  h_EW2->ProjectionX("hEW2_15",15,15);
  h_EW2->ProjectionX("hEW2_16",16,16);


  ouf->cd();

  TCanvas *c1 = new TCanvas("c1","Det1 R, uncal",1600,1200); c1->Divide(4,4);
  TCanvas *c2 = new TCanvas("c2","Det2 R, uncal",1600,1200); c2->Divide(4,4);
  TCanvas *c3 = new TCanvas("c3","Det1 W, uncal",1600,1200); c3->Divide(4,4);
  TCanvas *c4 = new TCanvas("c4","Det2 W, uncal",1600,1200); c4->Divide(4,4);
   TCanvas *c5 = new TCanvas("c5","Det1 R, cal",1600,1200); c5->Divide(4,4);
  TCanvas *c6 = new TCanvas("c6","Det2 R, cal",1600,1200); c6->Divide(4,4);
  TCanvas *c7 = new TCanvas("c7","Det1 W, cal",1600,1200); c7->Divide(4,4);
  TCanvas *c8 = new TCanvas("c8","Det2 W, cal",1600,1200); c8->Divide(4,4);
  

  c1->cd(1);  /* gPad->SetLogy(); */ hELudR1_1->Draw(); hELudR1_1->GetXaxis()->SetRange(100,1000);	 
  c1->cd(2);  /* gPad->SetLogy(); */ hELudR1_2->Draw(); hELudR1_2->GetXaxis()->SetRange(100,1000);	 
  c1->cd(3);  /* gPad->SetLogy(); */ hELudR1_3->Draw(); hELudR1_3->GetXaxis()->SetRange(100,1000);	 
  c1->cd(4);  /* gPad->SetLogy(); */ hELudR1_4->Draw(); hELudR1_4->GetXaxis()->SetRange(100,1000);	 
  c1->cd(5);  /* gPad->SetLogy(); */ hELudR1_5->Draw(); hELudR1_5->GetXaxis()->SetRange(100,1000);	 
  c1->cd(6);  /* gPad->SetLogy(); */ hELudR1_6->Draw(); hELudR1_6->GetXaxis()->SetRange(100,1000);	 
  c1->cd(7);  /* gPad->SetLogy(); */ hELudR1_7->Draw(); hELudR1_7->GetXaxis()->SetRange(100,1000);	 
  c1->cd(8);  /* gPad->SetLogy(); */ hELudR1_8->Draw(); hELudR1_8->GetXaxis()->SetRange(100,1000);	 
  c1->cd(9);  /* gPad->SetLogy(); */ hELudR1_9->Draw(); hELudR1_9->GetXaxis()->SetRange(100,1000);	 
  c1->cd(10); /* gPad->SetLogy(); */ hELudR1_10->Draw(); hELudR1_10->GetXaxis()->SetRange(100,1000);
  c1->cd(11); /* gPad->SetLogy(); */ hELudR1_11->Draw(); hELudR1_11->GetXaxis()->SetRange(100,1000);
  c1->cd(12); /* gPad->SetLogy(); */ hELudR1_12->Draw(); hELudR1_12->GetXaxis()->SetRange(100,1000);
  c1->cd(13); /* gPad->SetLogy(); */ hELudR1_13->Draw(); hELudR1_13->GetXaxis()->SetRange(100,1000);
  c1->cd(14); /* gPad->SetLogy(); */ hELudR1_14->Draw(); hELudR1_14->GetXaxis()->SetRange(100,1000);
  c1->cd(15); /* gPad->SetLogy(); */ hELudR1_15->Draw(); hELudR1_15->GetXaxis()->SetRange(100,1000);
  c1->cd(16); /* gPad->SetLogy(); */ hELudR1_16->Draw(); hELudR1_16->GetXaxis()->SetRange(100,1000);
  c1->Update();

  c2->cd(1);  /* gPad->SetLogy(); */ hELudR2_1->Draw();hELudR2_1->GetXaxis()->SetRange(100,1000);	 
  c2->cd(2);  /* gPad->SetLogy(); */ hELudR2_2->Draw();hELudR2_2->GetXaxis()->SetRange(100,1000);	 
  c2->cd(3);  /* gPad->SetLogy(); */ hELudR2_3->Draw();hELudR2_3->GetXaxis()->SetRange(100,1000);	 
  c2->cd(4);  /* gPad->SetLogy(); */ hELudR2_4->Draw();hELudR2_4->GetXaxis()->SetRange(100,1000);	 
  c2->cd(5);  /* gPad->SetLogy(); */ hELudR2_5->Draw();hELudR2_5->GetXaxis()->SetRange(100,1000);	 
  c2->cd(6);  /* gPad->SetLogy(); */ hELudR2_6->Draw();hELudR2_6->GetXaxis()->SetRange(100,1000);	 
  c2->cd(7);  /* gPad->SetLogy(); */ hELudR2_7->Draw();hELudR2_7->GetXaxis()->SetRange(100,1000);	 
  c2->cd(8);  /* gPad->SetLogy(); */ hELudR2_8->Draw();hELudR2_8->GetXaxis()->SetRange(100,1000);	 
  c2->cd(9);  /* gPad->SetLogy(); */ hELudR2_9->Draw();hELudR2_9->GetXaxis()->SetRange(100,1000);	 
  c2->cd(10); /* gPad->SetLogy(); */ hELudR2_10->Draw(); hELudR2_10->GetXaxis()->SetRange(100,1000);
  c2->cd(11); /* gPad->SetLogy(); */ hELudR2_11->Draw(); hELudR2_11->GetXaxis()->SetRange(100,1000);
  c2->cd(12); /* gPad->SetLogy(); */ hELudR2_12->Draw(); hELudR2_12->GetXaxis()->SetRange(100,1000);
  c2->cd(13); /* gPad->SetLogy(); */ hELudR2_13->Draw(); hELudR2_13->GetXaxis()->SetRange(100,1000);
  c2->cd(14); /* gPad->SetLogy(); */ hELudR2_14->Draw(); hELudR2_14->GetXaxis()->SetRange(100,1000);
  c2->cd(15); /* gPad->SetLogy(); */ hELudR2_15->Draw(); hELudR2_15->GetXaxis()->SetRange(100,1000);
  c2->cd(16); /* gPad->SetLogy(); */ hELudR2_16->Draw(); hELudR2_16->GetXaxis()->SetRange(100,1000);
  c2->Update();

  c3->cd(1); /* gPad->SetLogy(); */ hELudW1_1->Draw(); hELudW1_1->GetXaxis()->SetRange(100,1000);	 
  c3->cd(2); /* gPad->SetLogy(); */ hELudW1_2->Draw(); hELudW1_2->GetXaxis()->SetRange(100,1000);	 
  c3->cd(3); /* gPad->SetLogy(); */ hELudW1_3->Draw(); hELudW1_3->GetXaxis()->SetRange(100,1000);	 
  c3->cd(4); /* gPad->SetLogy(); */ hELudW1_4->Draw(); hELudW1_4->GetXaxis()->SetRange(100,1000);	 
  c3->cd(5); /* gPad->SetLogy(); */ hELudW1_5->Draw(); hELudW1_5->GetXaxis()->SetRange(100,1000);	 
  c3->cd(6); /* gPad->SetLogy(); */ hELudW1_6->Draw(); hELudW1_6->GetXaxis()->SetRange(100,1000);	 
  c3->cd(7); /* gPad->SetLogy(); */ hELudW1_7->Draw(); hELudW1_7->GetXaxis()->SetRange(100,1000);	 
  c3->cd(8); /* gPad->SetLogy(); */ hELudW1_8->Draw(); hELudW1_8->GetXaxis()->SetRange(100,1000);	 
  c3->cd(9); /* gPad->SetLogy(); */ hELudW1_9->Draw(); hELudW1_9->GetXaxis()->SetRange(100,1000);	 
  c3->cd(10);/* gPad->SetLogy(); */ hELudW1_10->Draw(); hELudW1_10->GetXaxis()->SetRange(100,1000);
  c3->cd(11);/* gPad->SetLogy(); */ hELudW1_11->Draw(); hELudW1_11->GetXaxis()->SetRange(100,1000);
  c3->cd(12);/* gPad->SetLogy(); */ hELudW1_12->Draw(); hELudW1_12->GetXaxis()->SetRange(100,1000);
  c3->cd(13);/* gPad->SetLogy(); */ hELudW1_13->Draw(); hELudW1_13->GetXaxis()->SetRange(100,1000);
  c3->cd(14);/* gPad->SetLogy(); */ hELudW1_14->Draw(); hELudW1_14->GetXaxis()->SetRange(100,1000);
  c3->cd(15);/* gPad->SetLogy(); */ hELudW1_15->Draw(); hELudW1_15->GetXaxis()->SetRange(100,1000);
  c3->cd(16);/* gPad->SetLogy(); */ hELudW1_16->Draw(); hELudW1_16->GetXaxis()->SetRange(100,1000);
  c3->Update();

  c4->cd(1);  /* gPad->SetLogy(); */ hELudW2_1->Draw();  hELudW2_1->GetXaxis()->SetRange(100,1000);	 
  c4->cd(2);  /* gPad->SetLogy(); */ hELudW2_2->Draw();  hELudW2_2->GetXaxis()->SetRange(100,1000);	 
  c4->cd(3);  /* gPad->SetLogy(); */ hELudW2_3->Draw();  hELudW2_3->GetXaxis()->SetRange(100,1000);	 
  c4->cd(4);  /* gPad->SetLogy(); */ hELudW2_4->Draw();  hELudW2_4->GetXaxis()->SetRange(100,1000);	 
  c4->cd(5);  /* gPad->SetLogy(); */ hELudW2_5->Draw();  hELudW2_5->GetXaxis()->SetRange(100,1000);	 
  c4->cd(6);  /* gPad->SetLogy(); */ hELudW2_6->Draw();  hELudW2_6->GetXaxis()->SetRange(100,1000);	 
  c4->cd(7);  /* gPad->SetLogy(); */ hELudW2_7->Draw();  hELudW2_7->GetXaxis()->SetRange(100,1000);	 
  c4->cd(8);  /* gPad->SetLogy(); */ hELudW2_8->Draw();  hELudW2_8->GetXaxis()->SetRange(100,1000);	 
  c4->cd(9);  /* gPad->SetLogy(); */ hELudW2_9->Draw();  hELudW2_9->GetXaxis()->SetRange(100,1000);	 
  c4->cd(10); /* gPad->SetLogy(); */ hELudW2_10->Draw(); hELudW2_10->GetXaxis()->SetRange(100,1000);
  c4->cd(11); /* gPad->SetLogy(); */ hELudW2_11->Draw(); hELudW2_11->GetXaxis()->SetRange(100,1000);
  c4->cd(12); /* gPad->SetLogy(); */ hELudW2_12->Draw(); hELudW2_12->GetXaxis()->SetRange(100,1000);
  c4->cd(13); /* gPad->SetLogy(); */ hELudW2_13->Draw(); hELudW2_13->GetXaxis()->SetRange(100,1000);
  c4->cd(14); /* gPad->SetLogy(); */ hELudW2_14->Draw(); hELudW2_14->GetXaxis()->SetRange(100,1000);
  c4->cd(15); /* gPad->SetLogy(); */ hELudW2_15->Draw(); hELudW2_15->GetXaxis()->SetRange(100,1000);
  c4->cd(16); /* gPad->SetLogy(); */ hELudW2_16->Draw(); hELudW2_16->GetXaxis()->SetRange(100,1000);
  c4->Update();

  c5->cd(1);  /* gPad->SetLogy(); */ hER1_1->Draw(); hER1_1->GetXaxis()->SetRange(100,1000);
  c5->cd(2);  /* gPad->SetLogy(); */ hER1_2->Draw(); hER1_2->GetXaxis()->SetRange(100,1000);
  c5->cd(3);  /* gPad->SetLogy(); */ hER1_3->Draw(); hER1_3->GetXaxis()->SetRange(100,1000);
  c5->cd(4);  /* gPad->SetLogy(); */ hER1_4->Draw(); hER1_4->GetXaxis()->SetRange(100,1000);
  c5->cd(5);  /* gPad->SetLogy(); */ hER1_5->Draw(); hER1_5->GetXaxis()->SetRange(100,1000);
  c5->cd(6);  /* gPad->SetLogy(); */ hER1_6->Draw(); hER1_6->GetXaxis()->SetRange(100,1000);
  c5->cd(7);  /* gPad->SetLogy(); */ hER1_7->Draw(); hER1_7->GetXaxis()->SetRange(100,1000);
  c5->cd(8);  /* gPad->SetLogy(); */ hER1_8->Draw(); hER1_8->GetXaxis()->SetRange(100,1000);
  c5->cd(9);  /* gPad->SetLogy(); */ hER1_9->Draw(); hER1_9->GetXaxis()->SetRange(100,1000);
  c5->cd(10); /* gPad->SetLogy(); */ hER1_10->Draw(); hER1_10->GetXaxis()->SetRange(100,1000);
  c5->cd(11); /* gPad->SetLogy(); */ hER1_11->Draw(); hER1_11->GetXaxis()->SetRange(100,1000);
  c5->cd(12); /* gPad->SetLogy(); */ hER1_12->Draw(); hER1_12->GetXaxis()->SetRange(100,1000);
  c5->cd(13); /* gPad->SetLogy(); */ hER1_13->Draw(); hER1_13->GetXaxis()->SetRange(100,1000);
  c5->cd(14); /* gPad->SetLogy(); */ hER1_14->Draw(); hER1_14->GetXaxis()->SetRange(100,1000);
  c5->cd(15); /* gPad->SetLogy(); */ hER1_15->Draw(); hER1_15->GetXaxis()->SetRange(100,1000);
  c5->cd(16); /* gPad->SetLogy(); */ hER1_16->Draw(); hER1_16->GetXaxis()->SetRange(100,1000);
  c5->Update();

  c6->cd(1);  /* gPad->SetLogy(); */ hER2_1->Draw(); hER2_1->GetXaxis()->SetRange(100,1000);
  c6->cd(2);  /* gPad->SetLogy(); */ hER2_2->Draw(); hER2_2->GetXaxis()->SetRange(100,1000);
  c6->cd(3);  /* gPad->SetLogy(); */ hER2_3->Draw(); hER2_3->GetXaxis()->SetRange(100,1000);
  c6->cd(4);  /* gPad->SetLogy(); */ hER2_4->Draw(); hER2_4->GetXaxis()->SetRange(100,1000);
  c6->cd(5);  /* gPad->SetLogy(); */ hER2_5->Draw(); hER2_5->GetXaxis()->SetRange(100,1000);
  c6->cd(6);  /* gPad->SetLogy(); */ hER2_6->Draw(); hER2_6->GetXaxis()->SetRange(100,1000);
  c6->cd(7);  /* gPad->SetLogy(); */ hER2_7->Draw(); hER2_7->GetXaxis()->SetRange(100,1000);
  c6->cd(8);  /* gPad->SetLogy(); */ hER2_8->Draw(); hER2_8->GetXaxis()->SetRange(100,1000);
  c6->cd(9);  /* gPad->SetLogy(); */ hER2_9->Draw(); hER2_9->GetXaxis()->SetRange(100,1000);
  c6->cd(10); /* gPad->SetLogy(); */ hER2_10->Draw(); hER2_10->GetXaxis()->SetRange(100,1000);
  c6->cd(11); /* gPad->SetLogy(); */ hER2_11->Draw(); hER2_11->GetXaxis()->SetRange(100,1000);
  c6->cd(12); /* gPad->SetLogy(); */ hER2_12->Draw(); hER2_12->GetXaxis()->SetRange(100,1000);
  c6->cd(13); /* gPad->SetLogy(); */ hER2_13->Draw(); hER2_13->GetXaxis()->SetRange(100,1000);
  c6->cd(14); /* gPad->SetLogy(); */ hER2_14->Draw(); hER2_14->GetXaxis()->SetRange(100,1000);
  c6->cd(15); /* gPad->SetLogy(); */ hER2_15->Draw(); hER2_15->GetXaxis()->SetRange(100,1000);
  c6->cd(16); /* gPad->SetLogy(); */ hER2_16->Draw(); hER2_16->GetXaxis()->SetRange(100,1000);
  c6->Update();

  c7->cd(1);  /* gPad->SetLogy(); */ hEW1_1->Draw(); hEW1_1->GetXaxis()->SetRange(100,1000);
  c7->cd(2);  /* gPad->SetLogy(); */ hEW1_2->Draw(); hEW1_2->GetXaxis()->SetRange(100,1000);
  c7->cd(3);  /* gPad->SetLogy(); */ hEW1_3->Draw(); hEW1_3->GetXaxis()->SetRange(100,1000);
  c7->cd(4);  /* gPad->SetLogy(); */ hEW1_4->Draw(); hEW1_4->GetXaxis()->SetRange(100,1000);
  c7->cd(5);  /* gPad->SetLogy(); */ hEW1_5->Draw(); hEW1_5->GetXaxis()->SetRange(100,1000);
  c7->cd(6);  /* gPad->SetLogy(); */ hEW1_6->Draw(); hEW1_6->GetXaxis()->SetRange(100,1000);
  c7->cd(7);  /* gPad->SetLogy(); */ hEW1_7->Draw(); hEW1_7->GetXaxis()->SetRange(100,1000);
  c7->cd(8);  /* gPad->SetLogy(); */ hEW1_8->Draw(); hEW1_8->GetXaxis()->SetRange(100,1000);
  c7->cd(9);  /* gPad->SetLogy(); */ hEW1_9->Draw(); hEW1_9->GetXaxis()->SetRange(100,1000);
  c7->cd(10); /* gPad->SetLogy(); */ hEW1_10->Draw(); hEW1_10->GetXaxis()->SetRange(100,1000);
  c7->cd(11); /* gPad->SetLogy(); */ hEW1_11->Draw(); hEW1_11->GetXaxis()->SetRange(100,1000);
  c7->cd(12); /* gPad->SetLogy(); */ hEW1_12->Draw(); hEW1_12->GetXaxis()->SetRange(100,1000);
  c7->cd(13); /* gPad->SetLogy(); */ hEW1_13->Draw(); hEW1_13->GetXaxis()->SetRange(100,1000);
  c7->cd(14); /* gPad->SetLogy(); */ hEW1_14->Draw(); hEW1_14->GetXaxis()->SetRange(100,1000);
  c7->cd(15); /* gPad->SetLogy(); */ hEW1_15->Draw(); hEW1_15->GetXaxis()->SetRange(100,1000);
  c7->cd(16); /* gPad->SetLogy(); */ hEW1_16->Draw(); hEW1_16->GetXaxis()->SetRange(100,1000);
  c7->Update();

  c8->cd(1);  /* gPad->SetLogy(); */ hEW2_1->Draw(); hEW2_1->GetXaxis()->SetRange(100,1000);
  c8->cd(2);  /* gPad->SetLogy(); */ hEW2_2->Draw(); hEW2_2->GetXaxis()->SetRange(100,1000);
  c8->cd(3);  /* gPad->SetLogy(); */ hEW2_3->Draw(); hEW2_3->GetXaxis()->SetRange(100,1000);
  c8->cd(4);  /* gPad->SetLogy(); */ hEW2_4->Draw(); hEW2_4->GetXaxis()->SetRange(100,1000);
  c8->cd(5);  /* gPad->SetLogy(); */ hEW2_5->Draw(); hEW2_5->GetXaxis()->SetRange(100,1000);
  c8->cd(6);  /* gPad->SetLogy(); */ hEW2_6->Draw(); hEW2_6->GetXaxis()->SetRange(100,1000);
  c8->cd(7);  /* gPad->SetLogy(); */ hEW2_7->Draw(); hEW2_7->GetXaxis()->SetRange(100,1000);
  c8->cd(8);  /* gPad->SetLogy(); */ hEW2_8->Draw(); hEW2_8->GetXaxis()->SetRange(100,1000);
  c8->cd(9);  /* gPad->SetLogy(); */ hEW2_9->Draw(); hEW2_9->GetXaxis()->SetRange(100,1000);
  c8->cd(10); /* gPad->SetLogy(); */ hEW2_10->Draw(); hEW2_10->GetXaxis()->SetRange(100,1000);
  c8->cd(11); /* gPad->SetLogy(); */ hEW2_11->Draw(); hEW2_11->GetXaxis()->SetRange(100,1000);
  c8->cd(12); /* gPad->SetLogy(); */ hEW2_12->Draw(); hEW2_12->GetXaxis()->SetRange(100,1000);
  c8->cd(13); /* gPad->SetLogy(); */ hEW2_13->Draw(); hEW2_13->GetXaxis()->SetRange(100,1000);
  c8->cd(14); /* gPad->SetLogy(); */ hEW2_14->Draw(); hEW2_14->GetXaxis()->SetRange(100,1000);
  c8->cd(15); /* gPad->SetLogy(); */ hEW2_15->Draw(); hEW2_15->GetXaxis()->SetRange(100,1000);
  c8->cd(16); /* gPad->SetLogy(); */ hEW2_16->Draw(); hEW2_16->GetXaxis()->SetRange(100,1000);
  c8->Update();


  /* ****************************************************** */


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

  hER1_1->Write();
  hER1_2->Write();
  hER1_3->Write();
  hER1_4->Write();
  hER1_5->Write();
  hER1_6->Write();
  hER1_7->Write();
  hER1_8->Write();
  hER1_9->Write();
  hER1_10->Write();
  hER1_11->Write();
  hER1_12->Write();
  hER1_13->Write();
  hER1_14->Write();
  hER1_15->Write();
  hER1_16->Write();

  hER2_1->Write();
  hER2_2->Write();
  hER2_3->Write();
  hER2_4->Write();
  hER2_5->Write();
  hER2_6->Write();
  hER2_7->Write();
  hER2_8->Write();
  hER2_9->Write();
  hER2_10->Write();
  hER2_11->Write();
  hER2_12->Write();
  hER2_13->Write();
  hER2_14->Write();
  hER2_15->Write();
  hER2_16->Write();

  hEW1_1->Write();
  hEW1_2->Write();
  hEW1_3->Write();
  hEW1_4->Write();
  hEW1_5->Write();
  hEW1_6->Write();
  hEW1_7->Write();
  hEW1_8->Write();
  hEW1_9->Write();
  hEW1_10->Write();
  hEW1_11->Write();
  hEW1_12->Write();
  hEW1_13->Write();
  hEW1_14->Write();
  hEW1_15->Write();
  hEW1_16->Write();

  hEW2_1->Write();
  hEW2_2->Write();
  hEW2_3->Write();
  hEW2_4->Write();
  hEW2_5->Write();
  hEW2_6->Write();
  hEW2_7->Write();
  hEW2_8->Write();
  hEW2_9->Write();
  hEW2_10->Write();
  hEW2_11->Write();
  hEW2_12->Write();
  hEW2_13->Write();
  hEW2_14->Write();
  hEW2_15->Write();
  hEW2_16->Write();

  c1->SaveAs("images/R1uncal305.png");
  c2->SaveAs("images/R2uncal305.png");
  c3->SaveAs("images/W1uncal305.png");
  c4->SaveAs("images/W2uncal305.png");
  c5->SaveAs("images/R1cal305.png");
  c6->SaveAs("images/R2cal305.png");
  c7->SaveAs("images/W1cal305.png");
  c8->SaveAs("images/W2cal305.png");

  return 0;

}
