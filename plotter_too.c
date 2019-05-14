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
TFile *f0 = new TFile("/disks/1/gwilson/25Al/sorted/chain_run/B8.5_D0.root");
TFile *f0 = new TFile("/disks/1/gwilson/25Al/sorted/chain_run/B8.5_D0.root");
TFile *f0 = new TFile("/disks/1/gwilson/25Al/sorted/chain_run/B8.5_D0.root");


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
 f->cd(); h1_de4->Draw(); h1_de4->SetLineColor(kRed);
 fB->cd(); h1_de4->Draw("same"); h1_de4->SetLineColor(kBlue);
 c1->Update();

 c1->cd(5);
 gPad->SetLogy();
 f->cd(); h1_de5->Draw(); h1_de5->SetLineColor(kRed);h1_de5->GetXaxis()->SetRange(0,100);
 fB->cd(); h1_de5->Draw("same"); h1_de5->SetLineColor(kBlue); h1_de5->GetXaxis()->SetRange(0,100);
 c1->Update();

/* ************************************************************** */

 TCanvas *c2 = new TCanvas("c2","cath/grid/rftof/mon/spare/x",1600,1200);
 c2->Divide(3,2);
 c2->cd(1);
 gPad->SetLogy();
 f->cd(); h1_cath->Draw(); h1_cath->SetLineColor(kRed);
 fB->cd(); h1_cath->Draw("same"); h1_cath->SetLineColor(kBlue);
 c2->Update();

 c2->cd(2);
 gPad->SetLogy();
 f->cd(); h1_grid->Draw(); h1_grid->SetLineColor(kRed); h1_grid->GetXaxis()->SetRange(0,100);
 fB->cd(); h1_grid->Draw("same"); h1_grid->SetLineColor(kBlue); h1_grid->GetXaxis()->SetRange(0,100);
 c2->Update();

 c2->cd(3);
 gPad->SetLogy();
 f->cd(); h1_rftof->Draw(); h1_rftof->SetLineColor(kRed);
 fB->cd(); h1_rftof->Draw("same"); h1_rftof->SetLineColor(kBlue);
 c2->Update();

 c2->cd(4);
 gPad->SetLogy();
 f->cd(); h1_mon->Draw(); h1_mon->SetLineColor(kRed); h1_mon->GetXaxis()->SetRange(0,100);
 fB->cd(); h1_mon->Draw("same"); h1_mon->SetLineColor(kBlue); h1_mon->GetXaxis()->SetRange(0,100);
 c2->Update();

 c2->cd(5);
 gPad->SetLogy();
 f->cd(); h1_spare->Draw(); h1_spare->SetLineColor(kRed);
 fB->cd(); h1_spare->Draw("same"); h1_spare->SetLineColor(kBlue);
 c2->Update();

 c2->cd(6);
 gPad->SetLogy();
 f->cd(); h1_x->Draw(); h1_x->SetLineColor(kRed);
 fB->cd(); h1_x->Draw("same"); h1_x->SetLineColor(kBlue);
 c2->Update();


/* ************************************************************** */

 TCanvas *c3 = new TCanvas("c3","focal plane 1",1600,1200);
 c3->Divide(3,2);
 c3->cd(1);
 gPad->SetLogy();
 f->cd(); h1_pospp->Draw(); h1_pospp->SetLineColor(kRed); h1_pospp->GetXaxis()->SetRange(0,1000);
 fB->cd(); h1_pospp->Draw("same"); h1_pospp->SetLineColor(kBlue); h1_pospp->GetXaxis()->SetRange(0,1000);
 c3->Update();

 c3->cd(2);
 gPad->SetLogy();
 f->cd(); h1_posppb->Draw(); h1_posppb->SetLineColor(kRed); //h1_posppb->GetXaxis()->SetRange(0,100);
 fB->cd(); h1_posppb->Draw("same"); h1_posppb->SetLineColor(kBlue); //h1_posppb->GetXaxis()->SetRange(0,100);
 c3->Update();

 c3->cd(3);
 gPad->SetLogy();
 f->cd(); h1_hepo->Draw(); h1_hepo->SetLineColor(kRed);
 fB->cd(); h1_hepo->Draw("same"); h1_hepo->SetLineColor(kBlue);
 c3->Update();

 c3->cd(4);
 gPad->SetLogy();
 f->cd(); h1_hepi->Draw(); h1_hepi->SetLineColor(kRed); //h1_hepi->GetXaxis()->SetRange(0,100);
 fB->cd(); h1_hepi->Draw("same"); h1_hepi->SetLineColor(kBlue);// h1_hepi->GetXaxis()->SetRange(0,100);
 c3->Update();

 c3->cd(5);
 gPad->SetLogy();
 f->cd(); h1_lepo->Draw(); h1_lepo->SetLineColor(kRed);
 fB->cd(); h1_lepo->Draw("same"); h1_lepo->SetLineColor(kBlue);
 c3->Update();

 c3->cd(6);
 gPad->SetLogy();
 f->cd(); h1_lepi->Draw(); h1_lepi->SetLineColor(kRed);
 fB->cd(); h1_lepi->Draw("same"); h1_lepi->SetLineColor(kBlue);
 c3->Update();

/* ************************************************************** */

 TCanvas *c4 = new TCanvas("c4","focal plane 2",1600,1200);
 c4->Divide(4,2);
 c4->cd(1);
 gPad->SetLogy();
 f->cd(); h1_up->Draw(); h1_up->SetLineColor(kRed);
 fB->cd(); h1_up->Draw("same"); h1_up->SetLineColor(kBlue);
 c4->Update();

 c4->cd(2);
 gPad->SetLogy();
 f->cd(); h1_down->Draw(); h1_down->SetLineColor(kRed); //h1_down->GetXaxis()->SetRange(0,100);
 fB->cd(); h1_down->Draw("same"); h1_down->SetLineColor(kBlue); //h1_down->GetXaxis()->SetRange(0,100);
 c4->Update();

 c4->cd(3);
 gPad->SetLogy();
 f->cd(); h1_hesum->Draw(); h1_hesum->SetLineColor(kRed); h1_hesum->GetXaxis()->SetRange(0,2200);
 fB->cd(); h1_hesum->Draw("same"); h1_hesum->SetLineColor(kBlue); h1_hesum->GetXaxis()->SetRange(0,2200);
 c4->Update();

 c4->cd(4);
 gPad->SetLogy();
 f->cd(); h1_lesum->Draw(); h1_lesum->SetLineColor(kRed); h1_lesum->GetXaxis()->SetRange(0,2200);
 fB->cd(); h1_lesum->Draw("same"); h1_lesum->SetLineColor(kBlue); h1_lesum->GetXaxis()->SetRange(0,2200);
 c4->Update();

 c4->cd(5);
 gPad->SetLogy();
 f->cd(); h1_udsum->Draw(); h1_udsum->SetLineColor(kRed);
 fB->cd(); h1_udsum->Draw("same"); h1_udsum->SetLineColor(kBlue);
 c4->Update();

 c4->cd(6);
 gPad->SetLogy();
 f->cd(); h1_he->Draw(); h1_he->SetLineColor(kRed); h1_he->GetXaxis()->SetRange(1000,3500);
 fB->cd(); h1_he->Draw("same"); h1_he->SetLineColor(kBlue); h1_he->GetXaxis()->SetRange(1000,3500);
 c4->Update();

 c4->cd(7);
 gPad->SetLogy();
 f->cd(); h1_le->Draw(); h1_le->SetLineColor(kRed); h1_le->GetXaxis()->SetRange(750,3500);
 fB->cd(); h1_le->Draw("same"); h1_le->SetLineColor(kBlue); h1_le->GetXaxis()->SetRange(750,3500);
 c4->Update();

 c4->cd(8);
 gPad->SetLogy();
 f->cd(); h1_ud->Draw(); h1_ud->SetLineColor(kRed);
 fB->cd(); h1_ud->Draw("same"); h1_ud->SetLineColor(kBlue);
 c4->Update();

/* ************************************************************** */
TCanvas *c5 = new TCanvas("c5","",1600,1200);
 c5->Divide(4,2);
 
 c5->cd(1); gPad->SetLogz();
 f->cd(); h2_EDE->Draw("col");
 c5->cd(5); gPad->SetLogz();
 fB->cd(); h2_EDE->Draw("col");
 c5->cd(2);gPad->SetLogz();
 f->cd(); h2_Erf->Draw("col");
 c5->cd(6); gPad->SetLogz();
 fB->cd(); h2_Erf->Draw("col");
 c5->cd(3); gPad->SetLogz();
 f->cd(); h2_DErf->Draw("col");
 c5->cd(7); gPad->SetLogz();
 fB->cd(); h2_DErf->Draw("col");
 c5->cd(4); gPad->SetLogz();
 f->cd(); h2_DErfg->Draw("col");
 c5->cd(8); gPad->SetLogz();
 fB->cd(); h2_DErfg->Draw("col");
 c5->Update();

/* ************************************************************** */
TCanvas *c6 = new TCanvas("c6","",1600,1200);
 c6->Divide(4,2);
 
 c6->cd(1); gPad->SetLogz();
 f->cd(); hELudR1->Draw("col");
 c6->cd(5); gPad->SetLogz();
 fB->cd(); hELudR1->Draw("col");
 c6->cd(2); gPad->SetLogz();
 f->cd(); hELudW1->Draw("col");
 c6->cd(6); gPad->SetLogz();
 fB->cd(); hELudW1->Draw("col");
 c6->cd(3); gPad->SetLogz();
 f->cd(); hELudR2->Draw("col");
 c6->cd(7); gPad->SetLogz();
 fB->cd(); hELudR1->Draw("col");
 c6->cd(4); gPad->SetLogz();
 f->cd(); hELudW2->Draw("col");
 c6->cd(8); gPad->SetLogz();
 fB->cd(); hELudW2->Draw("col");
 c6->Update();

/* ************************************************************** */
TCanvas *c7 = new TCanvas("c7","",1600,1200);
 c7->Divide(4,2);
 
 c7->cd(1); gPad->SetLogz();
 f->cd(); hER1->Draw("col");
 c7->cd(5); gPad->SetLogz();
 fB->cd(); hER1->Draw("col");
 c7->cd(2); gPad->SetLogz();
 f->cd(); hEW1->Draw("col");
 c7->cd(6); gPad->SetLogz();
 fB->cd(); hEW1->Draw("col");
 c7->cd(3); gPad->SetLogz();
 f->cd(); hER2->Draw("col");
 c7->cd(7); gPad->SetLogz();
 fB->cd(); hER1->Draw("col");
 c7->cd(4); gPad->SetLogz();
 f->cd(); hEW2->Draw("col");
 c7->cd(8); gPad->SetLogz();
 fB->cd(); hEW2->Draw("col");
 c7->Update();
/* ************************************************************** */
TCanvas *c8 = new TCanvas("c8","",1600,1200);
 c8->Divide(2,2);
 
 c8->cd(1); gPad->SetLogz();
 f->cd(); hER->Draw("col");
 c8->cd(3); gPad->SetLogz();
 fB->cd(); hER->Draw("col");
 c8->cd(2); gPad->SetLogz();
 f->cd(); hTAC->Draw("col");
 c8->cd(4); gPad->SetLogz();
 fB->cd(); hTAC->Draw("col");
 c8->Update();

/* ************************************************************** */
TCanvas *c9 = new TCanvas("c9","",1600,1200);
 c9->Divide(3,2);
 
 c9->cd(1); gPad->SetLogz();
 f->cd(); hER1g->Draw("col");
 c9->cd(4); gPad->SetLogz();
 fB->cd(); hER1g->Draw("col");
 c9->cd(2); gPad->SetLogz();
 f->cd(); hER1g2->Draw("col");
 c9->cd(5); gPad->SetLogz();
 fB->cd(); hER1g2->Draw("col");
 c9->cd(3); gPad->SetLogz();
 f->cd(); hEW1g->Draw("col");
 c9->cd(6); gPad->SetLogz();
 fB->cd(); hEW1g->Draw("col");
 c9->Update();

/* ************************************************************** */
TCanvas *c10 = new TCanvas("c10","",1600,1200);
 c10->Divide(2,2);
 
 c10->cd(1); gPad->SetLogz();
 f->cd(); hER1_gtxrf1->Draw("col");
 c10->cd(3); gPad->SetLogz();
 fB->cd(); hER1_gtxrf1->Draw("col");
 c10->cd(2); gPad->SetLogz();
 f->cd(); hER1_gtxrf2->Draw("col");
 c10->cd(4); gPad->SetLogz();
 fB->cd(); hER1_gtxrf2->Draw("col");
 c10->Update();

/* ************************************************************** */
TCanvas *c11 = new TCanvas("c11","",1600,1200);
 c11->Divide(4,2);
 
 c11->cd(1); gPad->SetLogz();
 f->cd(); hER1_gtxde41->Draw("col");
 c11->cd(5); gPad->SetLogz();
 fB->cd(); hER1_gtxde41->Draw("col");
 c11->cd(2); gPad->SetLogz();
 f->cd(); hER1_gtxde42->Draw("col");
 c11->cd(6); gPad->SetLogz();
 fB->cd(); hER1_gtxde42->Draw("col");
 c11->cd(3); gPad->SetLogz();
 f->cd(); hER1_gtxde43->Draw("col");
 c11->cd(7); gPad->SetLogz();
 fB->cd(); hER1_gtxde43->Draw("col");
 c11->cd(4); gPad->SetLogz();
 f->cd(); hER1_gtxde44->Draw("col");
 c11->cd(8); gPad->SetLogz();
 fB->cd(); hER1_gtxde44->Draw("col");
 c11->Update();

/* ************************************************************** */
TCanvas *c12 = new TCanvas("c12","",1600,1200);
 c12->Divide(4,2);
 
 c12->cd(1); gPad->SetLogz();
 f->cd(); hER1_gtde4rf1->Draw("col");
 c12->cd(5); gPad->SetLogz();
 fB->cd(); hER1_gtde4rf1->Draw("col");
 c12->cd(2); gPad->SetLogz();
 f->cd(); hER1_gtde4rf2->Draw("col");
 c12->cd(6); gPad->SetLogz();
 fB->cd(); hER1_gtde4rf2->Draw("col");
 c12->cd(3); gPad->SetLogz();
 f->cd(); hER1_gtde4rf3->Draw("col");
 c12->cd(7); gPad->SetLogz();
 fB->cd(); hER1_gtde4rf3->Draw("col");
 c12->cd(4); gPad->SetLogz();
 f->cd(); hER1_gtde4rf4->Draw("col");
 c12->cd(8); gPad->SetLogz();
 fB->cd(); hER1_gtde4rf4->Draw("col");
 c12->Update();

/* ************************************************************** */
TCanvas *c13 = new TCanvas("c13","",1600,1200);
 c13->Divide(4,2);
 
 c13->cd(1); gPad->SetLogz();
 f->cd(); hHitxy1->Draw("col");
 c13->cd(5); gPad->SetLogz();
 fB->cd(); hHitxy1->Draw("col");
 c13->cd(2); gPad->SetLogz();
 f->cd(); hHitxy2->Draw("col");
 c13->cd(6); gPad->SetLogz();
 fB->cd(); hHitxy2->Draw("col");
 c13->cd(3); gPad->SetLogz();
 f->cd(); hADC2->Draw("col");
 c13->cd(7); gPad->SetLogz();
 fB->cd(); hADC2->Draw("col");
 c13->cd(4); gPad->SetLogz();
 f->cd(); hADC3->Draw("col");
 c13->cd(8); gPad->SetLogz();
 fB->cd(); hADC3->Draw("col");
 c13->Update();

/* ************************************************************** */
TCanvas *c14 = new TCanvas("c14","detector 1 rings, not beam check",1600,1200);
 c14->Divide(4,4);
 f->cd();
 c14->cd(1); gPad->SetLogy(); hER1->ProjectionX("hER1_1",0,1); hER1_1->Draw();
 c14->cd(2); gPad->SetLogy(); hER1->ProjectionX("hER1_2",1,2); hER1_2->Draw();
 c14->cd(3); gPad->SetLogy(); hER1->ProjectionX("hER1_3",2,3); hER1_3->Draw();
 c14->cd(4); gPad->SetLogy(); hER1->ProjectionX("hER1_4",3,4); hER1_4->Draw();
 c14->cd(5); gPad->SetLogy(); hER1->ProjectionX("hER1_5",4,5); hER1_5->Draw();
 c14->cd(6); gPad->SetLogy(); hER1->ProjectionX("hER1_6",5,6); hER1_6->Draw();
 c14->cd(7); gPad->SetLogy(); hER1->ProjectionX("hER1_7",6,7); hER1_7->Draw();
 c14->cd(8); gPad->SetLogy(); hER1->ProjectionX("hER1_8",7,8); hER1_8->Draw();
 c14->cd(9); gPad->SetLogy(); hER1->ProjectionX("hER1_9",8,9); hER1_9->Draw();
 c14->cd(10); gPad->SetLogy(); hER1->ProjectionX("hER1_10",9,10); hER1_10->Draw();
 c14->cd(11); gPad->SetLogy(); hER1->ProjectionX("hER1_11",10,11); hER1_11->Draw();
 c14->cd(12); gPad->SetLogy(); hER1->ProjectionX("hER1_12",11,12); hER1_12->Draw();
 c14->cd(13); gPad->SetLogy(); hER1->ProjectionX("hER1_13",12,13); hER1_13->Draw();
 c14->cd(14); gPad->SetLogy(); hER1->ProjectionX("hER1_14",13,14); hER1_14->Draw();
 c14->cd(15); gPad->SetLogy(); hER1->ProjectionX("hER1_15",14,15); hER1_15->Draw();
 c14->cd(16); gPad->SetLogy(); hER1->ProjectionX("hER1_16",15,16); hER1_16->Draw();
 c14->Update();

/* ************************************************************** */
TCanvas *c15 = new TCanvas("c15","detector 1 rings, beam check",1600,1200);
 c15->Divide(4,4);
 fB->cd();
 c15->cd(1); gPad->SetLogy(); hER1->ProjectionX("hER1B_1",0,1); hER1B_1->Draw();
 c15->cd(2); gPad->SetLogy(); hER1->ProjectionX("hER1B_2",1,2); hER1B_2->Draw();
 c15->cd(3); gPad->SetLogy(); hER1->ProjectionX("hER1B_3",2,3); hER1B_3->Draw();
 c15->cd(4); gPad->SetLogy(); hER1->ProjectionX("hER1B_4",3,4); hER1B_4->Draw();
 c15->cd(5); gPad->SetLogy(); hER1->ProjectionX("hER1B_5",4,5); hER1B_5->Draw();
 c15->cd(6); gPad->SetLogy(); hER1->ProjectionX("hER1B_6",5,6); hER1B_6->Draw();
 c15->cd(7); gPad->SetLogy(); hER1->ProjectionX("hER1B_7",6,7); hER1B_7->Draw();
 c15->cd(8); gPad->SetLogy(); hER1->ProjectionX("hER1B_8",7,8); hER1B_8->Draw();
 c15->cd(9); gPad->SetLogy(); hER1->ProjectionX("hER1B_9",8,9); hER1B_9->Draw();
 c15->cd(10); gPad->SetLogy(); hER1->ProjectionX("hER1B_10",9,10); hER1B_10->Draw();
 c15->cd(11); gPad->SetLogy(); hER1->ProjectionX("hER1B_11",10,11); hER1B_11->Draw();
 c15->cd(12); gPad->SetLogy(); hER1->ProjectionX("hER1B_12",11,12); hER1B_12->Draw();
 c15->cd(13); gPad->SetLogy(); hER1->ProjectionX("hER1B_13",12,13); hER1B_13->Draw();
 c15->cd(14); gPad->SetLogy(); hER1->ProjectionX("hER1B_14",13,14); hER1B_14->Draw();
 c15->cd(15); gPad->SetLogy(); hER1->ProjectionX("hER1B_15",14,15); hER1B_15->Draw();
 c15->cd(16); gPad->SetLogy(); hER1->ProjectionX("hER1B_16",15,16); hER1B_16->Draw();
 c15->Update();

/* ************************************************************** */
TCanvas *c16 = new TCanvas("c16","detector 2 rings, not beam check",1600,1200);
 c16->Divide(4,4);
 f->cd();
 c16->cd(1); gPad->SetLogy(); hER2->ProjectionX("hER2_1",0,1); hER2_1->Draw();
 c16->cd(2); gPad->SetLogy(); hER2->ProjectionX("hER2_2",1,2); hER2_2->Draw();
 c16->cd(3); gPad->SetLogy(); hER2->ProjectionX("hER2_3",2,3); hER2_3->Draw();
 c16->cd(4); gPad->SetLogy(); hER2->ProjectionX("hER2_4",3,4); hER2_4->Draw();
 c16->cd(5); gPad->SetLogy(); hER2->ProjectionX("hER2_5",4,5); hER2_5->Draw();
 c16->cd(6); gPad->SetLogy(); hER2->ProjectionX("hER2_6",5,6); hER2_6->Draw();
 c16->cd(7); gPad->SetLogy(); hER2->ProjectionX("hER2_7",6,7); hER2_7->Draw();
 c16->cd(8); gPad->SetLogy(); hER2->ProjectionX("hER2_8",7,8); hER2_8->Draw();
 c16->cd(9); gPad->SetLogy(); hER2->ProjectionX("hER2_9",8,9); hER2_9->Draw();
 c16->cd(10); gPad->SetLogy(); hER2->ProjectionX("hER2_10",9,10); hER2_10->Draw();
 c16->cd(11); gPad->SetLogy(); hER2->ProjectionX("hER2_11",10,11); hER2_11->Draw();
 c16->cd(12); gPad->SetLogy(); hER2->ProjectionX("hER2_12",11,12); hER2_12->Draw();
 c16->cd(13); gPad->SetLogy(); hER2->ProjectionX("hER2_13",12,13); hER2_13->Draw();
 c16->cd(14); gPad->SetLogy(); hER2->ProjectionX("hER2_14",13,14); hER2_14->Draw();
 c16->cd(15); gPad->SetLogy(); hER2->ProjectionX("hER2_15",14,15); hER2_15->Draw();
 c16->cd(16); gPad->SetLogy(); hER2->ProjectionX("hER2_16",15,16); hER2_16->Draw();
 c16->Update();

/* ************************************************************** */
TCanvas *c17 = new TCanvas("c17","detector 1 rings, beam check",1600,1200);
 c17->Divide(4,4);
 fB->cd();
 c17->cd(1); gPad->SetLogy(); hER2->ProjectionX("hER2B_1",0,1); hER2B_1->Draw();
 c17->cd(2); gPad->SetLogy(); hER2->ProjectionX("hER2B_2",1,2); hER2B_2->Draw();
 c17->cd(3); gPad->SetLogy(); hER2->ProjectionX("hER2B_3",2,3); hER2B_3->Draw();
 c17->cd(4); gPad->SetLogy(); hER2->ProjectionX("hER2B_4",3,4); hER2B_4->Draw();
 c17->cd(5); gPad->SetLogy(); hER2->ProjectionX("hER2B_5",4,5); hER2B_5->Draw();
 c17->cd(6); gPad->SetLogy(); hER2->ProjectionX("hER2B_6",5,6); hER2B_6->Draw();
 c17->cd(7); gPad->SetLogy(); hER2->ProjectionX("hER2B_7",6,7); hER2B_7->Draw();
 c17->cd(8); gPad->SetLogy(); hER2->ProjectionX("hER2B_8",7,8); hER2B_8->Draw();
 c17->cd(9); gPad->SetLogy(); hER2->ProjectionX("hER2B_9",8,9); hER2B_9->Draw();
 c17->cd(10); gPad->SetLogy(); hER2->ProjectionX("hER2B_10",9,10); hER2B_10->Draw();
 c17->cd(11); gPad->SetLogy(); hER2->ProjectionX("hER2B_11",10,11); hER2B_11->Draw();
 c17->cd(12); gPad->SetLogy(); hER2->ProjectionX("hER2B_12",11,12); hER2B_12->Draw();
 c17->cd(13); gPad->SetLogy(); hER2->ProjectionX("hER2B_13",12,13); hER2B_13->Draw();
 c17->cd(14); gPad->SetLogy(); hER2->ProjectionX("hER2B_14",13,14); hER2B_14->Draw();
 c17->cd(15); gPad->SetLogy(); hER2->ProjectionX("hER2B_15",14,15); hER2B_15->Draw();
 c17->cd(16); gPad->SetLogy(); hER2->ProjectionX("hER2B_16",15,16); hER2B_16->Draw();
 c17->Update();

/* ************************************************************** */
TCanvas *c18 = new TCanvas("c18","detector 2 wedges, not beam check",1600,1200);
 c18->Divide(4,4);
 f->cd(); c18->cd(1); gPad->SetLogy(); hEW2->ProjectionX("hEW2_1",0,1); hEW2_1->Draw();
 c18->cd(2); gPad->SetLogy(); hEW2->ProjectionX("hEW2_2",1,2); hEW2_2->Draw();
 c18->cd(3); gPad->SetLogy(); hEW2->ProjectionX("hEW2_3",2,3); hEW2_3->Draw();
 c18->cd(4); gPad->SetLogy(); hEW2->ProjectionX("hEW2_4",3,4); hEW2_4->Draw();
 c18->cd(5); gPad->SetLogy(); hEW2->ProjectionX("hEW2_5",4,5); hEW2_5->Draw();
 c18->cd(6); gPad->SetLogy(); hEW2->ProjectionX("hEW2_6",5,6); hEW2_6->Draw();
 c18->cd(7); gPad->SetLogy(); hEW2->ProjectionX("hEW2_7",6,7); hEW2_7->Draw();
 c18->cd(8); gPad->SetLogy(); hEW2->ProjectionX("hEW2_8",7,8); hEW2_8->Draw();
 c18->cd(9); gPad->SetLogy(); hEW2->ProjectionX("hEW2_9",8,9); hEW2_9->Draw();
 c18->cd(10); gPad->SetLogy(); hEW2->ProjectionX("hEW2_10",9,10); hEW2_10->Draw();
 c18->cd(11); gPad->SetLogy(); hEW2->ProjectionX("hEW2_11",10,11); hEW2_11->Draw();
 c18->cd(12); gPad->SetLogy(); hEW2->ProjectionX("hEW2_12",11,12); hEW2_12->Draw();
 c18->cd(13); gPad->SetLogy(); hEW2->ProjectionX("hEW2_13",12,13); hEW2_13->Draw();
 c18->cd(14); gPad->SetLogy(); hEW2->ProjectionX("hEW2_14",13,14); hEW2_14->Draw();
 c18->cd(15); gPad->SetLogy(); hEW2->ProjectionX("hEW2_15",14,15); hEW2_15->Draw();
 c18->cd(16); gPad->SetLogy(); hEW2->ProjectionX("hEW2_16",15,16); hEW2_16->Draw();
 c18->Update();

/* ************************************************************** */
TCanvas *c19 = new TCanvas("c19","detector 1 wedges, beam check",1600,1200);
 c19->Divide(4,4);
 fB->cd();
 c19->cd(1); gPad->SetLogy(); hEW2->ProjectionX("hEW2B_1",0,1); hEW2B_1->Draw();
 c19->cd(2); gPad->SetLogy(); hEW2->ProjectionX("hEW2B_2",1,2); hEW2B_2->Draw();
 c19->cd(3); gPad->SetLogy(); hEW2->ProjectionX("hEW2B_3",2,3); hEW2B_3->Draw();
 c19->cd(4); gPad->SetLogy(); hEW2->ProjectionX("hEW2B_4",3,4); hEW2B_4->Draw();
 c19->cd(5); gPad->SetLogy(); hEW2->ProjectionX("hEW2B_5",4,5); hEW2B_5->Draw();
 c19->cd(6); gPad->SetLogy(); hEW2->ProjectionX("hEW2B_6",5,6); hEW2B_6->Draw();
 c19->cd(7); gPad->SetLogy(); hEW2->ProjectionX("hEW2B_7",6,7); hEW2B_7->Draw();
 c19->cd(8); gPad->SetLogy(); hEW2->ProjectionX("hEW2B_8",7,8); hEW2B_8->Draw();
 c19->cd(9); gPad->SetLogy(); hEW2->ProjectionX("hEW2B_9",8,9); hEW2B_9->Draw();
 c19->cd(10); gPad->SetLogy(); hEW2->ProjectionX("hEW2B_10",9,10); hEW2B_10->Draw();
 c19->cd(11); gPad->SetLogy(); hEW2->ProjectionX("hEW2B_11",10,11); hEW2B_11->Draw();
 c19->cd(12); gPad->SetLogy(); hEW2->ProjectionX("hEW2B_12",11,12); hEW2B_12->Draw();
 c19->cd(13); gPad->SetLogy(); hEW2->ProjectionX("hEW2B_13",12,13); hEW2B_13->Draw();
 c19->cd(14); gPad->SetLogy(); hEW2->ProjectionX("hEW2B_14",13,14); hEW2B_14->Draw();
 c19->cd(15); gPad->SetLogy(); hEW2->ProjectionX("hEW2B_15",14,15); hEW2B_15->Draw();
 c19->cd(16); gPad->SetLogy(); hEW2->ProjectionX("hEW2B_16",15,16); hEW2B_16->Draw();
 c19->Update();


/* ************************************************************** */
 c1->SaveAs("images/IC_D12.png");
 c2->SaveAs("images/cath_grid_D12.png");
 c3->SaveAs("images/focalplane1_D12.png");
 c4->SaveAs("images/focalplane2_D12.png");
 c5->SaveAs("images/2D_1_D12.png");
 c6->SaveAs("images/2D_2_D12.png");
 c7->SaveAs("images/2D_3_D12.png");
 c8->SaveAs("images/2D_4_D12.png");
 c9->SaveAs("images/2D_5_D12.png");
 c10->SaveAs("images/2D_6_D12.png");
 c11->SaveAs("images/2D_7_D12.png");
 c12->SaveAs("images/2D_8_D12.png");
 c13->SaveAs("images/2D_9_D12.png");
 c14->SaveAs("images/ring1.png");
 c15->SaveAs("images/ring1_bmck.png");
 c16->SaveAs("images/ring2.png");
 c17->SaveAs("images/ring2_bmck.png");
 c18->SaveAs("images/wedge2.png");
 c19->SaveAs("images/wedge2_bmck.png");
 return 0;
}
