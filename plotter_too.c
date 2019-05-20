/* **************************************************************** */
/* Plot some SPS histograms, comparing the same histogram for each  */
/* degrader setting. This is all for 'data runs', not beam check.   */
/* run on histogram files that have been hadded together.           */
/* Execute in ROOT, using .x plotter_too.c                          */
/* **************************************************************** */

#include <TCanvas.h>
#include <TGraph.h>
#include <TF1.h>
#include <fstream>
#include <iostream>

using namespace std;
int plotter_too(){

TFile *f0 = new TFile("/disks/1/gwilson/25Al/sorted/chain_run/B8.5_D0.root");
TFile *f2 = new TFile("/disks/1/gwilson/25Al/sorted/chain_run/B8.43_D2.root");
TFile *f4 = new TFile("/disks/1/gwilson/25Al/sorted/chain_run/B8.4_D4.root");
TFile *f8 = new TFile("/disks/1/gwilson/25Al/sorted/chain_run/B8.25_D8.root");
TFile *f12 = new TFile("/disks/1/gwilson/25Al/sorted/chain_run/B8.1_D12.root");


/* ************************************************************** */
 TCanvas *c1 = new TCanvas("c1","ionisation chamber",2000,2000);
 c1->Divide(5,5);
 f0->cd();
 c1->cd(1); gPad->SetLogy(); he_de1->Draw();
 c1->cd(2); gPad->SetLogy(); he_de2->Draw();
 c1->cd(3); gPad->SetLogy(); he_de3->Draw();
 c1->cd(4); gPad->SetLogy(); he_de4->Draw();
 c1->cd(5); gPad->SetLogy(); he_de5->Draw();
 f2->cd();
 c1->cd(6); gPad->SetLogy(); he_de1->Draw();
 c1->cd(7); gPad->SetLogy(); he_de2->Draw();
 c1->cd(8); gPad->SetLogy(); he_de3->Draw();
 c1->cd(9); gPad->SetLogy(); he_de4->Draw();
 c1->cd(10); gPad->SetLogy(); he_de5->Draw();
 f4->cd();
 c1->cd(11); gPad->SetLogy(); he_de1->Draw();
 c1->cd(12); gPad->SetLogy(); he_de2->Draw();
 c1->cd(13); gPad->SetLogy(); he_de3->Draw();
 c1->cd(14); gPad->SetLogy(); he_de4->Draw();
 c1->cd(15); gPad->SetLogy(); he_de5->Draw();
 f8->cd();
 c1->cd(16); gPad->SetLogy(); he_de1->Draw();
 c1->cd(17); gPad->SetLogy(); he_de2->Draw();
 c1->cd(18); gPad->SetLogy(); he_de3->Draw();
 c1->cd(19); gPad->SetLogy(); he_de4->Draw();
 c1->cd(20); gPad->SetLogy(); he_de5->Draw();
 f12->cd();
 c1->cd(21); gPad->SetLogy(); he_de1->Draw();
 c1->cd(22); gPad->SetLogy(); he_de2->Draw();
 c1->cd(23); gPad->SetLogy(); he_de3->Draw();
 c1->cd(24); gPad->SetLogy(); he_de4->Draw();
 c1->cd(25); gPad->SetLogy(); he_de5->Draw();
 c1->Update();

/* ************************************************************** */

 TCanvas *c2 = new TCanvas("c2","cath/grid/spare",1600,800);
 c2->Divide(5,3);
 f0->cd(); c2->cd(1); gPad->SetLogy(); h1_cath->Draw();
 f2->cd(); c2->cd(2); gPad->SetLogy(); h1_cath->Draw();
 f4->cd(); c2->cd(3); gPad->SetLogy(); h1_cath->Draw();
 f8->cd(); c2->cd(4); gPad->SetLogy(); h1_cath->Draw();
 f12->cd(); c2->cd(5); gPad->SetLogy(); h1_cath->Draw();
 f0->cd(); c2->cd(6); gPad->SetLogy(); h1_grid->Draw();
 f2->cd(); c2->cd(7); gPad->SetLogy(); h1_grid->Draw();
 f4->cd(); c2->cd(8); gPad->SetLogy(); h1_grid->Draw();
 f8->cd(); c2->cd(9); gPad->SetLogy(); h1_grid->Draw();
 f12->cd(); c2->cd(10); gPad->SetLogy(); h1_grid->Draw();
 f0->cd(); c2->cd(11); gPad->SetLogy(); h1_rftof->Draw();
 f2->cd(); c2->cd(12); gPad->SetLogy(); h1_rftof->Draw();
 f4->cd(); c2->cd(13); gPad->SetLogy(); h1_rftof->Draw();
 f8->cd(); c2->cd(14); gPad->SetLogy(); h1_rftof->Draw();
 f12->cd(); c2->cd(15); gPad->SetLogy(); h1_rftof->Draw();

/* ************************************************************** */

/* ************************************************************** */
 c1->SaveAs("images/IC_alldegrader.png");
 c2->SaveAs("images/cathgridspare.png");
/* ************************************************************** */
 return 0;
}
