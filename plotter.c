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

TFile *f = new TFile("/disks/1/gwilson/25Al/hadd_v7/B8.1_D12.root");
TFile *fB = new TFile("/disks/1/gwilson/25Al/hadd_v7/bmck_B9.05_D12.root");

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



 return 0;
}
