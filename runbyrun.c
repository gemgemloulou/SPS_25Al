/* **************************************************************** */
/* Code to check certain histograms run by run, rather than chained */
/* Execute in ROOT, using .x runbyrun.c                             */
/* **************************************************************** */

#include <TCanvas.h>
#include <TGraph.h>
#include <TF1.h>
#include <fstream>
#include <iostream>

using namespace std;
int runbyrun(){

  TFile *f = new TFile("/disks/1/gwilson/25Al/sorted/2mg.root");
  TFile *f99 = new TFile("/disks/1/gwilson/25Al/sorted/run147.root");
  TFile *f100 = new TFile("/disks/1/gwilson/25Al/sorted/run148.root");
  TFile *f101 = new TFile("/disks/1/gwilson/25Al/sorted/run150.root");
  TFile *f105 = new TFile("/disks/1/gwilson/25Al/sorted/run151.root");
  TFile *f106 = new TFile("/disks/1/gwilson/25Al/sorted/run153.root");
  TFile *f113 = new TFile("/disks/1/gwilson/25Al/sorted/run154.root");
  TFile *f116 = new TFile("/disks/1/gwilson/25Al/sorted/run155.root");
  TFile *f117 = new TFile("/disks/1/gwilson/25Al/sorted/run157.root");


/* ************************************************************** */
 TCanvas *c1 = new TCanvas("c1","c1",1600,1200);
 c1->Divide(2,2);
 c1->cd(1); f->cd(); hEFmax_EBmax->Draw("col"); 
 f99->cd(); tree->Draw("E_Bmax:E_Fmax>>h1(700,0,70,100,0,10)","","same");
 h1->SetMarkerStyle(21); h1->SetMarkerSize(0.8);c1->Update();
 c1->cd(2); f->cd(); hEFmax_EBmax->Draw("col");
 f100->cd(); tree->Draw("E_Bmax:E_Fmax>>h2(700,0,70,100,0,10)","","same");
 h2->SetMarkerStyle(21); h2->SetMarkerSize(0.8);c1->Update();
 c1->cd(3); f->cd(); hEFmax_EBmax->Draw("col");
 f101->cd(); tree->Draw("E_Bmax:E_Fmax>>h3(700,0,70,100,0,10)","","same");
 h3->SetMarkerStyle(21); h3->SetMarkerSize(0.8);c1->Update();
 c1->cd(4); f->cd(); hEFmax_EBmax->Draw("col");
 f105->cd(); tree->Draw("E_Bmax:E_Fmax>>h4(700,0,70,100,0,10)","","same");
 h4->SetMarkerStyle(21); h4->SetMarkerSize(0.8);c1->Update();

 TCanvas *c2 = new TCanvas("c2","c2",1600,1200);
 c2->Divide(2,2);
 c2->cd(1);  f->cd(); hEFmax_EBmax->Draw("col");
 f106->cd(); tree->Draw("E_Bmax:E_Fmax>>h5(700,0,70,100,0,10)","","same");
 h5->SetMarkerStyle(21); h5->SetMarkerSize(0.8);c2->Update();
 c2->cd(2); f->cd(); hEFmax_EBmax->Draw("col");
 f113->cd(); tree->Draw("E_Bmax:E_Fmax>>h6(700,0,70,100,0,10)","","same");
 h6->SetMarkerStyle(21); h6->SetMarkerSize(0.8);c2->Update();
 c2->cd(3);  f->cd(); hEFmax_EBmax->Draw("col");
 f116->cd(); tree->Draw("E_Bmax:E_Fmax>>h7(700,0,70,100,0,10)","","same");
 h7->SetMarkerStyle(21); h7->SetMarkerSize(0.8);c2->Update();
 c2->cd(4); f->cd(); hEFmax_EBmax->Draw("col");
 f117->cd(); tree->Draw("E_Bmax:E_Fmax>>h8(700,0,70,100,0,10)","","same");
 h8->SetMarkerStyle(21); h8->SetMarkerSize(0.8);c2->Update();

/* ************************************************************** */
 c1->SaveAs("histograms/Front_back_0mg_1.png");
 c2->SaveAs("histograms/Front_back_0mg_2.png");

 return 0;
}
