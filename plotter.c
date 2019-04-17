/* **************************************************************** */
/* Plot some SPS histograms, to check differences between beam on   */
/* and beam off runs, for each degrader setting.                    */
/* run on histogram files that have been hadded together.           */
/* Execute in ROOT, using .x plotter.c                              */
/* **************************************************************** */

#include <TCanvas.h>
#include <TGraph.h>
#include <TF1.h>
#include <fstream>
#include <iostream>

using namespace std;
int plotter(){

TFile *f = new TFile("/disks/1/gwilson/25Al/hadd_v7/B8.5_D0.root");
TFile *fB = new TFile("/disks/1/gwilson/25Al/hadd_v7/bmck_B9.8_D0.root");

/* ************************************************************** */
 TCanvas *c1 = new TCanvas("c1","ionisation chamber",1600,1200);
 c1->Divide(3,2);
 c1->cd(1);
 gPad->SetLogy();
 f->cd(); h1_de1->Draw(); h1_de1->SetLineColor(kRed);
 fB->cd(); h1_de1->Draw("same"); h1_de1->SetLineColor(kBlue);
 c1->Update();

 c1->cd(2);
 gPad->SetLogy();
 f->cd(); h1_de2->Draw(); h1_de2->SetLineColor(kRed); h1_de2->GetXaxis()->SetRange(0,100);
 fB->cd(); h1_de2->Draw("same"); h1_de2->SetLineColor(kBlue); h1_de2->GetXaxis()->SetRange(0,100);
 c1->Update();

 c1->cd(3);
 gPad->SetLogy();
 f->cd(); h1_de3->Draw(); h1_de3->SetLineColor(kRed);
 fB->cd(); h1_de3->Draw("same"); h1_de3->SetLineColor(kBlue);
 c1->Update();

 c1->cd(4);
 gPad->SetLogy();
 f->cd(); h1_de4->Draw(); h1_de4->SetLineColor(kRed);h1_de4->GetXaxis()->SetRange(0,100);
 fB->cd(); h1_de4->Draw("same"); h1_de4->SetLineColor(kBlue);h1_de4->GetXaxis()->SetRange(0,100);
 c1->Update();

 c1->cd(5);
 gPad->SetLogy();
 f->cd(); h1_de5->Draw(); h1_de5->SetLineColor(kRed);
 fB->cd(); h1_de5->Draw("same"); h1_de5->SetLineColor(kBlue);
 c1->Update();








/* ************************************************************** */
 c1->SaveAs("images/IC_D0.png");
 return 0;
}
