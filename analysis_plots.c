/* **************************************************************** */
/* Plot some SPS histograms, comparing the same histogram for each  */
/* degrader setting. This is all for 'data runs', not beam check.   */
/* run on histogram files that have been hadded together.           */
/* Execute in ROOT, using .x analysis_plots.c                       */
/* **************************************************************** */
#include <TFile.h>
#include <TCanvas.h>
#include <TGraph.h>
#include <TF1.h>
#include <TH1.h>
#include <TCutG.h>
#include <fstream>
#include <iostream>

using namespace std;

int analysis_plots(){

TFile *f0 = new TFile("0mg.root","read");
TFile *f2 = new TFile("2mg.root","read");
TFile *f4 = new TFile("4mg.root","read");
TFile *f8 = new TFile("8mg.root","read");
TFile *f12 = new TFile("12mg.root","read");
 TFile *fcuts = new TFile("cuts_0.root","read"); // this is just for illustrating!


    int i;
    TCanvas *c[41];
    char can[2];
    char save[6];
    
    TCutG *beamcut = (TCutG*)fcuts->Get("beam");
    TCutG *uppercut = (TCutG*)fcuts->Get("upper");
    TCutG *lowercut = (TCutG*)fcuts->Get("lower");
    TCutG *dEEcut = (TCutG*)fcuts->Get("dE-Ecut");
    TCutG *FB = (TCutG*)fcuts->Get("frontback");
    
    
    for(i=1;i<41;i++){
        sprintf(can,"c%d",i);
        c[i] = new TCanvas(can,can,1600,800);
        c[i]->Divide(3,2);
    }
/* ************************************************************** */
   
// dE-E, gated on 6 TAC gates
    c[1]->cd(1); f0->cd(); gPad->SetLogy(); hTACg1->Draw();
    c[1]->cd(2); gPad->SetLogz(); hdEE_TACg1->Draw();
    c[1]->cd(3); f2->cd(); gPad->SetLogz(); hdEE_TACg1->Draw();
    c[1]->cd(4); f4->cd(); gPad->SetLogz(); hdEE_TACg1->Draw();
    c[1]->cd(5); f8->cd(); gPad->SetLogz(); hdEE_TACg1->Draw();
    c[1]->cd(6); f12->cd(); gPad->SetLogz(); hdEE_TACg1->Draw();
   
    c[2]->cd(1); f0->cd(); gPad->SetLogy(); hTACg2->Draw();
    c[2]->cd(2); hdEE_TACg2->Draw();
    c[2]->cd(3); f2->cd(); hdEE_TACg2->Draw();
    c[2]->cd(4); f4->cd(); hdEE_TACg2->Draw();
    c[2]->cd(5); f8->cd(); hdEE_TACg2->Draw();
    c[2]->cd(6); f12->cd(); hdEE_TACg2->Draw();
   
    c[3]->cd(1); f0->cd(); gPad->SetLogy(); hTACg3->Draw();
    c[3]->cd(2); hdEE_TACg3->Draw();
    c[3]->cd(3); f2->cd(); hdEE_TACg3->Draw();
    c[3]->cd(4); f4->cd(); hdEE_TACg3->Draw();
    c[3]->cd(5); f8->cd(); hdEE_TACg3->Draw();
    c[3]->cd(6); f12->cd(); hdEE_TACg3->Draw();
    
    c[4]->cd(1); f0->cd(); gPad->SetLogy(); hTACg4->Draw();
    c[4]->cd(2); hdEE_TACg4->Draw();
    c[4]->cd(3); f2->cd(); hdEE_TACg4->Draw();
    c[4]->cd(4); f4->cd(); hdEE_TACg4->Draw();
    c[4]->cd(5); f8->cd(); hdEE_TACg4->Draw();
    c[4]->cd(6); f12->cd();hdEE_TACg4->Draw();
    
    c[5]->cd(1); f0->cd(); gPad->SetLogy(); hTACg5->Draw();
    c[5]->cd(2); hdEE_TACg5->Draw();
    c[5]->cd(3); f2->cd(); hdEE_TACg5->Draw();
    c[5]->cd(4); f4->cd(); hdEE_TACg5->Draw();
    c[5]->cd(5); f8->cd(); hdEE_TACg5->Draw();
    c[5]->cd(6); f12->cd();hdEE_TACg5->Draw();

    c[6]->cd(1); f0->cd(); gPad->SetLogy(); hTACg6->Draw();
    c[6]->cd(2); hdEE_TACg6->Draw();
    c[6]->cd(3); f2->cd(); hdEE_TACg6->Draw();
    c[6]->cd(4); f4->cd(); hdEE_TACg6->Draw();
    c[6]->cd(5); f8->cd(); hdEE_TACg6->Draw();
    c[6]->cd(6); f12->cd(); hdEE_TACg6->Draw();
    
    // FP, gated on 6 TAC gates
 
    c[7]->cd(1); f0->cd(); gPad->SetLogy(); hTACg1->Draw();
    c[7]->cd(2); hFP_TACg1->Draw(); hFP_TACg1->SetMarkerStyle(21); 
    c[7]->cd(3); f2->cd(); hFP_TACg1->Draw();hFP_TACg1->SetMarkerStyle(21);
    c[7]->cd(4); f4->cd(); hFP_TACg1->Draw(); hFP_TACg1->SetMarkerStyle(21);
    c[7]->cd(5); f8->cd(); hFP_TACg1->Draw(); hFP_TACg1->SetMarkerStyle(21);
    c[7]->cd(6); f12->cd(); hFP_TACg1->Draw(); hFP_TACg1->SetMarkerStyle(21);
    
    c[8]->cd(1); f0->cd(); gPad->SetLogy(); hTACg2->Draw();
    c[8]->cd(2); hFP_TACg2->Draw();
    c[8]->cd(3); f2->cd(); hFP_TACg2->Draw();
    c[8]->cd(4); f4->cd(); hFP_TACg2->Draw();
    c[8]->cd(5); f8->cd(); hFP_TACg2->Draw();
    c[8]->cd(6); f12->cd(); hFP_TACg2->Draw();
    
    c[9]->cd(1); f0->cd(); gPad->SetLogy(); hTACg3->Draw();
    c[9]->cd(2); hFP_TACg3->Draw();
    c[9]->cd(3); f2->cd(); hFP_TACg3->Draw();
    c[9]->cd(4); f4->cd(); hFP_TACg3->Draw();
    c[9]->cd(5); f8->cd(); hFP_TACg3->Draw();
    c[9]->cd(6); f12->cd(); hFP_TACg3->Draw();
    
    c[10]->cd(1); f0->cd(); gPad->SetLogy(); hTACg4->Draw();
    c[10]->cd(2); hFP_TACg4->Draw();
    c[10]->cd(3); f2->cd(); hFP_TACg4->Draw();
    c[10]->cd(4); f4->cd(); hFP_TACg4->Draw();
    c[10]->cd(5); f8->cd(); hFP_TACg4->Draw();
    c[10]->cd(6); f12->cd();hFP_TACg4->Draw();
    
    c[11]->cd(1); f0->cd(); gPad->SetLogy(); hTACg5->Draw();
    c[11]->cd(2); hFP_TACg5->Draw();
    c[11]->cd(3); f2->cd(); hFP_TACg5->Draw();
    c[11]->cd(4); f4->cd(); hFP_TACg5->Draw();
    c[11]->cd(5); f8->cd(); hFP_TACg5->Draw();
    c[11]->cd(6); f12->cd();hFP_TACg5->Draw();
    
    c[12]->cd(1); f0->cd(); gPad->SetLogy(); hTACg6->Draw();
    c[12]->cd(2); hFP_TACg6->Draw();
    c[12]->cd(3); f2->cd(); hFP_TACg6->Draw();
    c[12]->cd(4); f4->cd(); hFP_TACg6->Draw();
    c[12]->cd(5); f8->cd(); hFP_TACg6->Draw();
    c[12]->cd(6); f12->cd(); hFP_TACg6->Draw();
    
    // E vs Theta, gated on 6 TAC gates
    
    c[13]->cd(1); f0->cd(); gPad->SetLogy(); hTACg1->Draw();
    c[13]->cd(2); gPad->SetLogz(); hEvTh_TACg1->Draw();
    hdEvTh_TACg1->SetMarkerStyle(21); hdEvTh_TACg1->SetMarkerSize(0.8);
    c[13]->cd(3); f2->cd(); gPad->SetLogz(); hEvTh_TACg1->Draw();
    hdEvTh_TACg1->SetMarkerStyle(21); hdEvTh_TACg1->SetMarkerSize(0.8);
    c[13]->cd(4); f4->cd(); gPad->SetLogz(); hEvTh_TACg1->Draw();
    hdEvTh_TACg1->SetMarkerStyle(21); hdEvTh_TACg1->SetMarkerSize(0.8);
    c[13]->cd(5); f8->cd(); gPad->SetLogz(); hEvTh_TACg1->Draw();
    hdEvTh_TACg1->SetMarkerStyle(21); hdEvTh_TACg1->SetMarkerSize(0.8);
    c[13]->cd(6); f12->cd(); gPad->SetLogz(); hEvTh_TACg1->Draw();
    hdEvTh_TACg1->SetMarkerStyle(21); hdEvTh_TACg1->SetMarkerSize(0.8);
    c[13]->Update();
    
    c[14]->cd(1); f0->cd(); gPad->SetLogy(); hTACg2->Draw();
    c[14]->cd(2); hEvTh_TACg2->Draw();
    hdEvTh_TACg2->SetMarkerStyle(21); hdEvTh_TACg2->SetMarkerSize(0.8);
    c[14]->cd(3); f2->cd(); hEvTh_TACg2->Draw();
    hdEvTh_TACg2->SetMarkerStyle(21); hdEvTh_TACg2->SetMarkerSize(0.8);
    c[14]->cd(4); f4->cd(); hEvTh_TACg2->Draw();
    hdEvTh_TACg2->SetMarkerStyle(21); hdEvTh_TACg2->SetMarkerSize(0.8);
    c[14]->cd(5); f8->cd(); hEvTh_TACg2->Draw();
    hdEvTh_TACg2->SetMarkerStyle(21); hdEvTh_TACg2->SetMarkerSize(0.8);
    c[14]->cd(6); f12->cd(); hEvTh_TACg2->Draw();
    hdEvTh_TACg2->SetMarkerStyle(21); hdEvTh_TACg2->SetMarkerSize(0.8);
    c[14]->Update();
    
    c[15]->cd(1); f0->cd(); gPad->SetLogy(); hTACg3->Draw();
    c[15]->cd(2); hEvTh_TACg3->Draw();
    hdEvTh_TACg3->SetMarkerStyle(21); hdEvTh_TACg3->SetMarkerSize(0.8);
    c[15]->cd(3); f2->cd(); hEvTh_TACg3->Draw();
    hdEvTh_TACg3->SetMarkerStyle(21); hdEvTh_TACg3->SetMarkerSize(0.8);
    c[15]->cd(4); f4->cd(); hEvTh_TACg3->Draw();
    hdEvTh_TACg3->SetMarkerStyle(21); hdEvTh_TACg3->SetMarkerSize(0.8);
    c[15]->cd(5); f8->cd(); hEvTh_TACg3->Draw();
    hdEvTh_TACg3->SetMarkerStyle(21); hdEvTh_TACg3->SetMarkerSize(0.8);
    c[15]->cd(6); f12->cd(); hEvTh_TACg3->Draw();
    hdEvTh_TACg3->SetMarkerStyle(21); hdEvTh_TACg3->SetMarkerSize(0.8);
    c[15]->Update();
    
    c[16]->cd(1); f0->cd(); gPad->SetLogy(); hTACg4->Draw();
    c[16]->cd(2); hEvTh_TACg4->Draw();
    hdEvTh_TACg4->SetMarkerStyle(21); hdEvTh_TACg4->SetMarkerSize(0.8);
    c[16]->cd(3); f2->cd(); hEvTh_TACg4->Draw();
    hdEvTh_TACg4->SetMarkerStyle(21); hdEvTh_TACg4->SetMarkerSize(0.8);
    c[16]->cd(4); f4->cd(); hEvTh_TACg4->Draw();
    hdEvTh_TACg4->SetMarkerStyle(21); hdEvTh_TACg4->SetMarkerSize(0.8);
    c[16]->cd(5); f8->cd(); hEvTh_TACg4->Draw();
    hdEvTh_TACg4->SetMarkerStyle(21); hdEvTh_TACg4->SetMarkerSize(0.8);
    c[16]->cd(6); f12->cd();hEvTh_TACg4->Draw();
    hdEvTh_TACg4->SetMarkerStyle(21); hdEvTh_TACg4->SetMarkerSize(0.8);
    c[16]->Update();
    
    c[17]->cd(1); f0->cd(); gPad->SetLogy(); hTACg5->Draw();
    c[17]->cd(2); hEvTh_TACg5->Draw();
    hdEvTh_TACg5->SetMarkerStyle(21); hdEvTh_TACg5->SetMarkerSize(0.8);
    c[17]->cd(3); f2->cd(); hEvTh_TACg5->Draw();
    hdEvTh_TACg5->SetMarkerStyle(21); hdEvTh_TACg5->SetMarkerSize(0.8);
    c[17]->cd(4); f4->cd(); hEvTh_TACg5->Draw();
    hdEvTh_TACg5->SetMarkerStyle(21); hdEvTh_TACg5->SetMarkerSize(0.8);
    c[17]->cd(5); f8->cd(); hEvTh_TACg5->Draw();
    hdEvTh_TACg5->SetMarkerStyle(21); hdEvTh_TACg5->SetMarkerSize(0.8);
    c[17]->cd(6); f12->cd();hEvTh_TACg5->Draw();
    hdEvTh_TACg5->SetMarkerStyle(21); hdEvTh_TACg5->SetMarkerSize(0.8);
    c[17]->Update();
    
    c[18]->cd(1); f0->cd(); gPad->SetLogy(); hTACg6->Draw();
    c[18]->cd(2); hEvTh_TACg6->Draw();
    hdEvTh_TACg6->SetMarkerStyle(21); hdEvTh_TACg6->SetMarkerSize(0.8);
    c[18]->cd(3); f2->cd(); hEvTh_TACg6->Draw();
    hdEvTh_TACg6->SetMarkerStyle(21); hdEvTh_TACg6->SetMarkerSize(0.8);
    c[18]->cd(4); f4->cd(); hEvTh_TACg6->Draw();
    hdEvTh_TACg6->SetMarkerStyle(21); hdEvTh_TACg6->SetMarkerSize(0.8);
    c[18]->cd(5); f8->cd(); hEvTh_TACg6->Draw();
    hdEvTh_TACg6->SetMarkerStyle(21); hdEvTh_TACg6->SetMarkerSize(0.8);
    c[18]->cd(6); f12->cd(); hEvTh_TACg6->Draw();
    hdEvTh_TACg6->SetMarkerStyle(21); hdEvTh_TACg6->SetMarkerSize(0.8);
    c[18]->Update();

    // dE vs Theta, gated on 6 TAC gates
    
    c[19]->cd(1); f0->cd(); gPad->SetLogy(); hTACg1->Draw();
    c[19]->cd(2); gPad->SetLogz(); hdEvTh_TACg1->Draw("col");
    c[19]->cd(3); f2->cd(); gPad->SetLogz(); hdEvTh_TACg1->Draw("col");
    c[19]->cd(4); f4->cd(); gPad->SetLogz(); hdEvTh_TACg1->Draw("col");
    c[19]->cd(5); f8->cd(); gPad->SetLogz(); hdEvTh_TACg1->Draw("col");
    c[19]->cd(6); f12->cd(); gPad->SetLogz(); hdEvTh_TACg1->Draw("col");
    
    c[20]->cd(1); f0->cd(); gPad->SetLogy(); hTACg2->Draw();
    c[20]->cd(2); hdEvTh_TACg2->Draw(); 
    hdEvTh_TACg2->SetMarkerStyle(21); hdEvTh_TACg2->SetMarkerSize(0.8);
    c[20]->cd(3); f2->cd(); hdEvTh_TACg2->Draw(); 
    hdEvTh_TACg2->SetMarkerStyle(21); hdEvTh_TACg2->SetMarkerSize(0.8);
    c[20]->cd(4); f4->cd(); hdEvTh_TACg2->Draw();
    hdEvTh_TACg2->SetMarkerStyle(21); hdEvTh_TACg2->SetMarkerSize(0.8);
    c[20]->cd(5); f8->cd(); hdEvTh_TACg2->Draw();
    hdEvTh_TACg2->SetMarkerStyle(21); hdEvTh_TACg2->SetMarkerSize(0.8);
    c[20]->cd(6); f12->cd(); hdEvTh_TACg2->Draw();
    hdEvTh_TACg2->SetMarkerStyle(21); hdEvTh_TACg2->SetMarkerSize(0.8);
    c[20]->Update();

    c[21]->cd(1); f0->cd(); gPad->SetLogy(); hTACg3->Draw();
    c[21]->cd(2); hdEvTh_TACg3->Draw(); 
    hdEvTh_TACg3->SetMarkerStyle(21); hdEvTh_TACg3->SetMarkerSize(0.8);
    c[21]->cd(3); f2->cd(); hdEvTh_TACg3->Draw();
    hdEvTh_TACg3->SetMarkerStyle(21); hdEvTh_TACg3->SetMarkerSize(0.8);
    c[21]->cd(4); f4->cd(); hdEvTh_TACg3->Draw();
    hdEvTh_TACg3->SetMarkerStyle(21); hdEvTh_TACg3->SetMarkerSize(0.8);
    c[21]->cd(5); f8->cd(); hdEvTh_TACg3->Draw();
    hdEvTh_TACg3->SetMarkerStyle(21); hdEvTh_TACg3->SetMarkerSize(0.8);
    c[21]->cd(6); f12->cd(); hdEvTh_TACg3->Draw();
    hdEvTh_TACg3->SetMarkerStyle(21); hdEvTh_TACg3->SetMarkerSize(0.8);
    c[21]->Update();
    
    c[22]->cd(1); f0->cd(); gPad->SetLogy(); hTACg4->Draw();
    c[22]->cd(2); hdEvTh_TACg4->Draw();
    hdEvTh_TACg4->SetMarkerStyle(21); hdEvTh_TACg4->SetMarkerSize(0.8);
    c[22]->cd(3); f2->cd(); hdEvTh_TACg4->Draw();
    hdEvTh_TACg4->SetMarkerStyle(21); hdEvTh_TACg4->SetMarkerSize(0.8);
    c[22]->cd(4); f4->cd(); hdEvTh_TACg4->Draw();
    hdEvTh_TACg4->SetMarkerStyle(21); hdEvTh_TACg4->SetMarkerSize(0.8);
    c[22]->cd(5); f8->cd(); hdEvTh_TACg4->Draw();
    hdEvTh_TACg4->SetMarkerStyle(21); hdEvTh_TACg4->SetMarkerSize(0.8);
    c[22]->cd(6); f12->cd();hdEvTh_TACg4->Draw();
    hdEvTh_TACg4->SetMarkerStyle(21); hdEvTh_TACg4->SetMarkerSize(0.8);
    c[22]->Update();
    
    c[23]->cd(1); f0->cd(); gPad->SetLogy(); hTACg5->Draw();
    c[23]->cd(2); hdEvTh_TACg5->Draw();
    hdEvTh_TACg5->SetMarkerStyle(21); hdEvTh_TACg5->SetMarkerSize(0.8);
    c[23]->cd(3); f2->cd(); hdEvTh_TACg5->Draw();
    hdEvTh_TACg5->SetMarkerStyle(21); hdEvTh_TACg5->SetMarkerSize(0.8);
    c[23]->cd(4); f4->cd(); hdEvTh_TACg5->Draw();
    hdEvTh_TACg5->SetMarkerStyle(21); hdEvTh_TACg5->SetMarkerSize(0.8);
    c[23]->cd(5); f8->cd(); hdEvTh_TACg5->Draw();
    hdEvTh_TACg5->SetMarkerStyle(21); hdEvTh_TACg5->SetMarkerSize(0.8);
    c[23]->cd(6); f12->cd();hdEvTh_TACg5->Draw();
    hdEvTh_TACg5->SetMarkerStyle(21); hdEvTh_TACg5->SetMarkerSize(0.8);
    c[23]->Update();
   
    c[24]->cd(1); f0->cd(); gPad->SetLogy(); hTACg6->Draw();
    c[24]->cd(2); hdEvTh_TACg6->Draw();
    hdEvTh_TACg6->SetMarkerStyle(21); hdEvTh_TACg6->SetMarkerSize(0.8);
    c[24]->cd(3); f2->cd(); hdEvTh_TACg6->Draw();
    hdEvTh_TACg6->SetMarkerStyle(21); hdEvTh_TACg6->SetMarkerSize(0.8);
    c[24]->cd(4); f4->cd(); hdEvTh_TACg6->Draw();
    hdEvTh_TACg6->SetMarkerStyle(21); hdEvTh_TACg6->SetMarkerSize(0.8);
    c[24]->cd(5); f8->cd(); hdEvTh_TACg6->Draw();
    hdEvTh_TACg6->SetMarkerStyle(21); hdEvTh_TACg6->SetMarkerSize(0.8);
    c[24]->cd(6); f12->cd(); hdEvTh_TACg6->Draw();
    hdEvTh_TACg6->SetMarkerStyle(21); hdEvTh_TACg6->SetMarkerSize(0.8);
    c[24]->Update();

    /* ************************************************************** */
    
    // gated on dE-E
    c[25]->cd(1); f0->cd(); gPad->SetLogz(); hdE_E_rings->Draw("col"); dEEcut->Draw("same");
    c[25]->cd(2); gPad->SetLogy(); hTAC_dEEg->Draw();
    c[25]->cd(3); f2->cd(); gPad->SetLogy(); hTAC_dEEg->Draw();
    c[25]->cd(4); f4->cd(); gPad->SetLogy(); hTAC_dEEg->Draw();
    c[25]->cd(5); f8->cd(); gPad->SetLogy(); hTAC_dEEg->Draw();
    c[25]->cd(6); f12->cd(); gPad->SetLogy(); hTAC_dEEg->Draw();
    
    c[26]->cd(1); f0->cd(); gPad->SetLogz(); hdE_E_rings->Draw("col"); dEEcut->Draw("same");
    c[26]->cd(2); gPad->SetLogz(); hFP_dEEg->Draw();
    c[26]->cd(3); f2->cd(); gPad->SetLogz(); hFP_dEEg->Draw();
    c[26]->cd(4); f4->cd(); gPad->SetLogz(); hFP_dEEg->Draw();
    c[26]->cd(5); f8->cd(); gPad->SetLogz(); hFP_dEEg->Draw();
    c[26]->cd(6); f12->cd();gPad->SetLogz(); hFP_dEEg->Draw();
    
    c[27]->cd(1); f0->cd(); gPad->SetLogz(); hdE_E_rings->Draw("col"); dEEcut->Draw("same");
    c[27]->cd(2); gPad->SetLogz(); hEvTh_dEEg->Draw("col");
    c[27]->cd(3); f2->cd(); gPad->SetLogz(); hEvTh_dEEg->Draw("col");
    c[27]->cd(4); f4->cd(); gPad->SetLogz(); hEvTh_dEEg->Draw("col");
    c[27]->cd(5); f8->cd(); gPad->SetLogz(); hEvTh_dEEg->Draw("col");
    c[27]->cd(6); f12->cd();gPad->SetLogz(); hEvTh_dEEg->Draw("col");
    
    c[28]->cd(1); f0->cd(); gPad->SetLogz(); hdE_E_rings->Draw("col"); dEEcut->Draw("same");
    c[28]->cd(2); gPad->SetLogz(); hdEvTh_dEEg->Draw("col");
    hdEvTh_dEEg->GetXaxis()->SetRangeUser(0.0,6.0);
    c[28]->cd(3); f2->cd(); gPad->SetLogz(); hdEvTh_dEEg->Draw("col");
    hdEvTh_dEEg->GetXaxis()->SetRangeUser(0.0,6.0);
    c[28]->cd(4); f4->cd(); gPad->SetLogz(); hdEvTh_dEEg->Draw("col");
    hdEvTh_dEEg->GetXaxis()->SetRangeUser(0.0,6.0);
    c[28]->cd(5); f8->cd(); gPad->SetLogz(); hdEvTh_dEEg->Draw("col");
    hdEvTh_dEEg->GetXaxis()->SetRangeUser(0.0,6.0);
    c[28]->cd(6); f12->cd(); gPad->SetLogz(); hdEvTh_dEEg->Draw("col");
    hdEvTh_dEEg->GetXaxis()->SetRangeUser(0.0,6.0);
    c[28]->Update();


/* ************************************************************** */
    
    // FP gates
    c[29]->cd(1); f0->cd(); gPad->SetLogz(); hxvrftof->Draw("col"); beamcut->Draw("same");
    c[29]->cd(2); gPad->SetLogz(); hdEE_FPgb->Draw("col");
    c[29]->cd(3); f2->cd(); gPad->SetLogz(); hdEE_FPgb->Draw("col");
    c[29]->cd(4); f4->cd(); gPad->SetLogz(); hdEE_FPgb->Draw("col");
    c[29]->cd(5); f8->cd(); gPad->SetLogz(); hdEE_FPgb->Draw("col");
    c[29]->cd(6); f12->cd(); gPad->SetLogz(); hdEE_FPgb->Draw("col");
    
    c[30]->cd(1); f0->cd(); gPad->SetLogz(); hxvrftof->Draw("col"); uppercut->Draw("same");
    c[30]->cd(2); gPad->SetLogz(); hdEE_FPgu->Draw("col");
    c[30]->cd(3); f2->cd(); gPad->SetLogz(); hdEE_FPgu->Draw("col");
    c[30]->cd(4); f4->cd(); gPad->SetLogz(); hdEE_FPgu->Draw("col");
    c[30]->cd(5); f8->cd(); gPad->SetLogz(); hdEE_FPgu->Draw("col");
    c[30]->cd(6); f12->cd(); gPad->SetLogz(); hdEE_FPgu->Draw("col");
    
    c[31]->cd(1); f0->cd(); gPad->SetLogz(); hxvrftof->Draw("col"); lowercut->Draw("same");
    c[31]->cd(2); gPad->SetLogz(); hdEE_FPgl->Draw("col");
    c[31]->cd(3); f2->cd(); gPad->SetLogz(); hdEE_FPgl->Draw("col");
    c[31]->cd(4); f4->cd(); gPad->SetLogz(); hdEE_FPgl->Draw("col");
    c[31]->cd(5); f8->cd(); gPad->SetLogz(); hdEE_FPgl->Draw("col");
    c[31]->cd(6); f12->cd(); gPad->SetLogz(); hdEE_FPgl->Draw("col");
    
    c[32]->cd(1); f0->cd(); gPad->SetLogz(); hxvrftof->Draw("col"); beamcut->Draw("same");
    c[32]->cd(2); gPad->SetLogz(); hEvTh_FPgb->Draw("col");
    c[32]->cd(3); f2->cd(); gPad->SetLogz(); hEvTh_FPgb->Draw("col");
    c[32]->cd(4); f4->cd(); gPad->SetLogz(); hEvTh_FPgb->Draw("col");
    c[32]->cd(5); f8->cd(); gPad->SetLogz(); hEvTh_FPgb->Draw("col");
    c[32]->cd(6); f12->cd(); gPad->SetLogz(); hEvTh_FPgb->Draw("col");
    
    c[33]->cd(1); f0->cd(); gPad->SetLogz(); hxvrftof->Draw("col"); uppercut->Draw("same");
    c[33]->cd(2); gPad->SetLogz(); hEvTh_FPgu->Draw("col");
    c[33]->cd(3); f2->cd(); gPad->SetLogz(); hEvTh_FPgu->Draw("col");
    c[33]->cd(4); f4->cd(); gPad->SetLogz(); hEvTh_FPgu->Draw("col");
    c[33]->cd(5); f8->cd(); gPad->SetLogz(); hEvTh_FPgu->Draw("col");
    c[33]->cd(6); f12->cd(); gPad->SetLogz(); hEvTh_FPgu->Draw("col");
    
    c[34]->cd(1); f0->cd(); gPad->SetLogz(); hxvrftof->Draw("col"); lowercut->Draw("same");
    c[34]->cd(2); gPad->SetLogz(); hEvTh_FPgl->Draw("col");
    c[34]->cd(3); f2->cd(); gPad->SetLogz(); hEvTh_FPgl->Draw("col");
    c[34]->cd(4); f4->cd(); gPad->SetLogz(); hEvTh_FPgl->Draw("col");
    c[34]->cd(5); f8->cd(); gPad->SetLogz(); hEvTh_FPgl->Draw("col");
    c[34]->cd(6); f12->cd(); gPad->SetLogz(); hEvTh_FPgl->Draw("col");
    
    c[35]->cd(1); f0->cd(); gPad->SetLogz(); hxvrftof->Draw("col"); beamcut->Draw("same");
    c[35]->cd(2); gPad->SetLogy(); hTAC_FPgb->Draw();
    c[35]->cd(3); f2->cd(); gPad->SetLogy(); hTAC_FPgb->Draw();
    c[35]->cd(4); f4->cd(); gPad->SetLogy(); hTAC_FPgb->Draw();
    c[35]->cd(5); f8->cd(); gPad->SetLogy(); hTAC_FPgb->Draw();
    c[35]->cd(6); f12->cd(); gPad->SetLogy(); hTAC_FPgb->Draw();
    
    c[36]->cd(1); f0->cd(); gPad->SetLogz(); hxvrftof->Draw("col"); uppercut->Draw("same");
    c[36]->cd(2); gPad->SetLogy(); hTAC_FPgu->Draw();
    c[36]->cd(3); f2->cd(); gPad->SetLogy(); hTAC_FPgu->Draw();
    c[36]->cd(4); f4->cd(); gPad->SetLogy(); hTAC_FPgu->Draw();
    c[36]->cd(5); f8->cd(); gPad->SetLogy(); hTAC_FPgu->Draw();
    c[36]->cd(6); f12->cd(); gPad->SetLogy(); hTAC_FPgu->Draw();
    
    c[37]->cd(1); f0->cd(); gPad->SetLogz(); hxvrftof->Draw("col"); lowercut->Draw("same");
    c[37]->cd(2); gPad->SetLogy(); hTAC_FPgl->Draw();
    c[37]->cd(3); f2->cd(); gPad->SetLogy(); hTAC_FPgl->Draw();
    c[37]->cd(4); f4->cd(); gPad->SetLogy(); hTAC_FPgl->Draw();
    c[37]->cd(5); f8->cd(); gPad->SetLogy(); hTAC_FPgl->Draw();
    c[37]->cd(6); f12->cd(); gPad->SetLogy(); hTAC_FPgl->Draw();

/* ************************************************************** */
// Overlay Overlay! Arriba arriba!     
    c[38]->cd(1); f0->cd(); gPad->SetLogy(); 
    hTACg1->Draw(); hTACg1->SetLineColor(kRed);
    hTACg2->Draw("same"); hTACg2->SetLineColor(kBlue);
    hTACg3->Draw("same"); hTACg3->SetLineColor(kBlack);
    hTACg4->Draw("same"); hTACg4->SetLineColor(kGreen);
    hTACg5->Draw("same"); hTACg5->SetLineColor(kOrange);
    hTACg6->Draw("same"); hTACg6->SetLineColor(kMagenta);

    c[38]->cd(2); gPad->SetLogz(); hdE_E_rings->Draw("col");
    hdEE_TACg1->Draw("same"); hdEE_TACg1->SetMarkerStyle(21); 
    hdEE_TACg1->SetMarkerSize(0.8); hdEE_TACg1->SetMarkerColor(kRed); 

    hdEE_TACg2->Draw("same"); hdEE_TACg2->SetMarkerStyle(21); 
    hdEE_TACg2->SetMarkerSize(0.8); hdEE_TACg2->SetMarkerColor(kBlue); 

    hdEE_TACg3->Draw("same"); hdEE_TACg3->SetMarkerStyle(21); 
    hdEE_TACg3->SetMarkerSize(0.8); hdEE_TACg3->SetMarkerColor(kBlack); 

    hdEE_TACg4->Draw("same"); hdEE_TACg4->SetMarkerStyle(21); 
    hdEE_TACg4->SetMarkerSize(0.8); hdEE_TACg4->SetMarkerColor(kGreen); 

    hdEE_TACg5->Draw("same"); hdEE_TACg5->SetMarkerStyle(21); 
    hdEE_TACg5->SetMarkerSize(0.8); hdEE_TACg5->SetMarkerColor(kOrange); 

    hdEE_TACg6->Draw("same"); hdEE_TACg6->SetMarkerStyle(21); 
    hdEE_TACg6->SetMarkerSize(0.8); hdEE_TACg6->SetMarkerColor(kMagenta); 

    c[38]->cd(3); f2->cd(); gPad->SetLogz(); hdE_E_rings->Draw("col");
    hdEE_TACg1->Draw("same"); hdEE_TACg1->SetMarkerStyle(21); 
    hdEE_TACg1->SetMarkerSize(0.8); hdEE_TACg1->SetMarkerColor(kRed); 

    hdEE_TACg2->Draw("same"); hdEE_TACg2->SetMarkerStyle(21); 
    hdEE_TACg2->SetMarkerSize(0.8); hdEE_TACg2->SetMarkerColor(kBlue); 

    hdEE_TACg3->Draw("same"); hdEE_TACg3->SetMarkerStyle(21); 
    hdEE_TACg3->SetMarkerSize(0.8); hdEE_TACg3->SetMarkerColor(kBlack); 

    hdEE_TACg4->Draw("same"); hdEE_TACg4->SetMarkerStyle(21); 
    hdEE_TACg4->SetMarkerSize(0.8); hdEE_TACg4->SetMarkerColor(kGreen); 

    hdEE_TACg5->Draw("same"); hdEE_TACg5->SetMarkerStyle(21); 
    hdEE_TACg5->SetMarkerSize(0.8); hdEE_TACg5->SetMarkerColor(kOrange); 

    hdEE_TACg6->Draw("same"); hdEE_TACg6->SetMarkerStyle(21); 
    hdEE_TACg6->SetMarkerSize(0.8); hdEE_TACg6->SetMarkerColor(kMagenta); 

    c[38]->cd(4); f4->cd(); gPad->SetLogz(); hdE_E_rings->Draw("col");
    hdEE_TACg1->Draw("same"); hdEE_TACg1->SetMarkerStyle(21); 
    hdEE_TACg1->SetMarkerSize(0.8); hdEE_TACg1->SetMarkerColor(kRed); 

    hdEE_TACg2->Draw("same"); hdEE_TACg2->SetMarkerStyle(21); 
    hdEE_TACg2->SetMarkerSize(0.8); hdEE_TACg2->SetMarkerColor(kBlue); 

    hdEE_TACg3->Draw("same"); hdEE_TACg3->SetMarkerStyle(21); 
    hdEE_TACg3->SetMarkerSize(0.8); hdEE_TACg3->SetMarkerColor(kBlack); 

    hdEE_TACg4->Draw("same"); hdEE_TACg4->SetMarkerStyle(21); 
    hdEE_TACg4->SetMarkerSize(0.8); hdEE_TACg4->SetMarkerColor(kGreen); 

    hdEE_TACg5->Draw("same"); hdEE_TACg5->SetMarkerStyle(21); 
    hdEE_TACg5->SetMarkerSize(0.8); hdEE_TACg5->SetMarkerColor(kOrange); 

    hdEE_TACg6->Draw("same"); hdEE_TACg6->SetMarkerStyle(21); 
    hdEE_TACg6->SetMarkerSize(0.8); hdEE_TACg6->SetMarkerColor(kMagenta); 

    c[38]->cd(5); f8->cd(); gPad->SetLogz(); hdE_E_rings->Draw("col");
    hdEE_TACg1->Draw("same"); hdEE_TACg1->SetMarkerStyle(21); 
    hdEE_TACg1->SetMarkerSize(0.8); hdEE_TACg1->SetMarkerColor(kRed); 

    hdEE_TACg2->Draw("same"); hdEE_TACg2->SetMarkerStyle(21); 
    hdEE_TACg2->SetMarkerSize(0.8); hdEE_TACg2->SetMarkerColor(kBlue); 

    hdEE_TACg3->Draw("same"); hdEE_TACg3->SetMarkerStyle(21); 
    hdEE_TACg3->SetMarkerSize(0.8); hdEE_TACg3->SetMarkerColor(kBlack); 

    hdEE_TACg4->Draw("same"); hdEE_TACg4->SetMarkerStyle(21); 
    hdEE_TACg4->SetMarkerSize(0.8); hdEE_TACg4->SetMarkerColor(kGreen); 

    hdEE_TACg5->Draw("same"); hdEE_TACg5->SetMarkerStyle(21); 
    hdEE_TACg5->SetMarkerSize(0.8); hdEE_TACg5->SetMarkerColor(kOrange); 

    hdEE_TACg6->Draw("same"); hdEE_TACg6->SetMarkerStyle(21); 
    hdEE_TACg6->SetMarkerSize(0.8); hdEE_TACg6->SetMarkerColor(kMagenta); 

    c[38]->cd(6); f12->cd(); gPad->SetLogz(); hdE_E_rings->Draw("col");
    hdEE_TACg1->Draw("same"); hdEE_TACg1->SetMarkerStyle(21); 
    hdEE_TACg1->SetMarkerSize(0.8); hdEE_TACg1->SetMarkerColor(kRed); 

    hdEE_TACg2->Draw("same"); hdEE_TACg2->SetMarkerStyle(21); 
    hdEE_TACg2->SetMarkerSize(0.8); hdEE_TACg2->SetMarkerColor(kBlue); 

    hdEE_TACg3->Draw("same"); hdEE_TACg3->SetMarkerStyle(21); 
    hdEE_TACg3->SetMarkerSize(0.8); hdEE_TACg3->SetMarkerColor(kBlack); 

    hdEE_TACg4->Draw("same"); hdEE_TACg4->SetMarkerStyle(21); 
    hdEE_TACg4->SetMarkerSize(0.8); hdEE_TACg4->SetMarkerColor(kGreen); 

    hdEE_TACg5->Draw("same"); hdEE_TACg5->SetMarkerStyle(21); 
    hdEE_TACg5->SetMarkerSize(0.8); hdEE_TACg5->SetMarkerColor(kOrange); 

    hdEE_TACg6->Draw("same"); hdEE_TACg6->SetMarkerStyle(21); 
    hdEE_TACg6->SetMarkerSize(0.8); hdEE_TACg6->SetMarkerColor(kMagenta); 

    c[38]->Update();

    // ***********************
    
    c[39]->cd(1); f0->cd(); gPad->SetLogy(); 
    hTACg1->Draw(); hTACg1->SetLineColor(kRed);
    hTACg2->Draw("same"); hTACg2->SetLineColor(kBlue);
    hTACg3->Draw("same"); hTACg3->SetLineColor(kBlack);
    hTACg4->Draw("same"); hTACg4->SetLineColor(kGreen);
    hTACg5->Draw("same"); hTACg5->SetLineColor(kOrange);
    hTACg6->Draw("same"); hTACg6->SetLineColor(kMagenta);
   
    c[39]->cd(2); f0->cd(); gPad->SetLogz(); hxvrftof->Draw("col");
    hFP_TACg1->Draw("same"); hFP_TACg1->SetMarkerStyle(21); 
    hFP_TACg1->SetMarkerSize(0.8); hFP_TACg1->SetMarkerColor(kRed); 

    hFP_TACg2->Draw("same"); hFP_TACg2->SetMarkerStyle(21); 
    hFP_TACg2->SetMarkerSize(0.8); hFP_TACg2->SetMarkerColor(kBlue);

    hFP_TACg3->Draw("same"); hFP_TACg3->SetMarkerStyle(21); 
    hFP_TACg3->SetMarkerSize(0.8); hFP_TACg3->SetMarkerColor(kBlack);

    hFP_TACg4->Draw("same"); hFP_TACg4->SetMarkerStyle(21); 
    hFP_TACg4->SetMarkerSize(0.8); hFP_TACg4->SetMarkerColor(kGreen); 

    hFP_TACg5->Draw("same"); hFP_TACg5->SetMarkerStyle(21); 
    hFP_TACg5->SetMarkerSize(0.8); hFP_TACg5->SetMarkerColor(kOrange);

    hFP_TACg6->Draw("same"); hFP_TACg6->SetMarkerStyle(21); 
    hFP_TACg6->SetMarkerSize(0.8); hFP_TACg6->SetMarkerColor(kMagenta); 

    c[39]->cd(3); f2->cd(); gPad->SetLogz(); hxvrftof->Draw("col");
    hFP_TACg1->Draw("same"); hFP_TACg1->SetMarkerStyle(21); 
    hFP_TACg1->SetMarkerSize(0.8); hFP_TACg1->SetMarkerColor(kRed); 

    hFP_TACg2->Draw("same"); hFP_TACg2->SetMarkerStyle(21); 
    hFP_TACg2->SetMarkerSize(0.8); hFP_TACg2->SetMarkerColor(kBlue);

    hFP_TACg3->Draw("same"); hFP_TACg3->SetMarkerStyle(21); 
    hFP_TACg3->SetMarkerSize(0.8); hFP_TACg3->SetMarkerColor(kBlack);

    hFP_TACg4->Draw("same"); hFP_TACg4->SetMarkerStyle(21); 
    hFP_TACg4->SetMarkerSize(0.8); hFP_TACg4->SetMarkerColor(kGreen);

    hFP_TACg5->Draw("same"); hFP_TACg5->SetMarkerStyle(21); 
    hFP_TACg5->SetMarkerSize(0.8); hFP_TACg5->SetMarkerColor(kOrange);

    hFP_TACg6->Draw("same"); hFP_TACg6->SetMarkerStyle(21); 
    hFP_TACg6->SetMarkerSize(0.8); hFP_TACg6->SetMarkerColor(kMagenta);

    c[39]->cd(4); f4->cd(); gPad->SetLogz(); hxvrftof->Draw("col");
    hFP_TACg1->Draw("same"); hFP_TACg1->SetMarkerStyle(21); 
    hFP_TACg1->SetMarkerSize(0.8); hFP_TACg1->SetMarkerColor(kRed); 

    hFP_TACg2->Draw("same"); hFP_TACg2->SetMarkerStyle(21); 
    hFP_TACg2->SetMarkerSize(0.8); hFP_TACg2->SetMarkerColor(kBlue); 

    hFP_TACg3->Draw("same"); hFP_TACg3->SetMarkerStyle(21); 
    hFP_TACg3->SetMarkerSize(0.8); hFP_TACg3->SetMarkerColor(kBlack);

    hFP_TACg4->Draw("same"); hFP_TACg4->SetMarkerStyle(21); 
    hFP_TACg4->SetMarkerSize(0.8); hFP_TACg4->SetMarkerColor(kGreen);

    hFP_TACg5->Draw("same"); hFP_TACg5->SetMarkerStyle(21); 
    hFP_TACg5->SetMarkerSize(0.8); hFP_TACg5->SetMarkerColor(kOrange);

    hFP_TACg6->Draw("same"); hFP_TACg6->SetMarkerStyle(21); 
    hFP_TACg6->SetMarkerSize(0.8); hFP_TACg6->SetMarkerColor(kMagenta); 

    c[39]->cd(5); f8->cd(); gPad->SetLogz(); hxvrftof->Draw("col");
    hFP_TACg1->Draw("same"); hFP_TACg1->SetMarkerStyle(21); 
    hFP_TACg1->SetMarkerSize(0.8); hFP_TACg1->SetMarkerColor(kRed); 

    hFP_TACg2->Draw("same"); hFP_TACg2->SetMarkerStyle(21); 
    hFP_TACg2->SetMarkerSize(0.8); hFP_TACg2->SetMarkerColor(kBlue);

    hFP_TACg3->Draw("same"); hFP_TACg3->SetMarkerStyle(21); 
    hFP_TACg3->SetMarkerSize(0.8); hFP_TACg3->SetMarkerColor(kBlack); 

    hFP_TACg4->Draw("same"); hFP_TACg4->SetMarkerStyle(21); 
    hFP_TACg4->SetMarkerSize(0.8); hFP_TACg4->SetMarkerColor(kGreen);

    hFP_TACg5->Draw("same"); hFP_TACg5->SetMarkerStyle(21); 
    hFP_TACg5->SetMarkerSize(0.8); hFP_TACg5->SetMarkerColor(kOrange);

    hFP_TACg6->Draw("same"); hFP_TACg6->SetMarkerStyle(21); 
    hFP_TACg6->SetMarkerSize(0.8); hFP_TACg6->SetMarkerColor(kMagenta);

    c[39]->cd(6); f12->cd(); gPad->SetLogz(); hxvrftof->Draw("col");
    hFP_TACg1->Draw("same"); hFP_TACg1->SetMarkerStyle(21); 
    hFP_TACg1->SetMarkerSize(0.8); hFP_TACg1->SetMarkerColor(kRed);

    hFP_TACg2->Draw("same"); hFP_TACg2->SetMarkerStyle(21); 
    hFP_TACg2->SetMarkerSize(0.8); hFP_TACg2->SetMarkerColor(kBlue);

    hFP_TACg3->Draw("same"); hFP_TACg3->SetMarkerStyle(21); 
    hFP_TACg3->SetMarkerSize(0.8); hFP_TACg3->SetMarkerColor(kBlack);

    hFP_TACg4->Draw("same"); hFP_TACg4->SetMarkerStyle(21); 
    hFP_TACg4->SetMarkerSize(0.8); hFP_TACg4->SetMarkerColor(kGreen);

    hFP_TACg5->Draw("same"); hFP_TACg5->SetMarkerStyle(21); 
    hFP_TACg5->SetMarkerSize(0.8); hFP_TACg5->SetMarkerColor(kOrange);

    hFP_TACg6->Draw("same"); hFP_TACg6->SetMarkerStyle(21); 
    hFP_TACg6->SetMarkerSize(0.8); hFP_TACg6->SetMarkerColor(kMagenta);

    c[39]->Update();

 // ***********************
    
    c[40]->cd(1); f0->cd(); gPad->SetLogy(); 
    hTACg1->Draw(); hTACg1->SetLineColor(kRed);
    hTACg2->Draw("same"); hTACg2->SetLineColor(kBlue);
    hTACg3->Draw("same"); hTACg3->SetLineColor(kBlack);
    hTACg4->Draw("same"); hTACg4->SetLineColor(kGreen);
    hTACg5->Draw("same"); hTACg5->SetLineColor(kOrange);
    hTACg6->Draw("same"); hTACg6->SetLineColor(kMagenta);
   
    c[40]->cd(2); f0->cd(); gPad->SetLogz(); hEvTh->Draw("col");
    hEvTh_TACg1->Draw("same"); hEvTh_TACg1->SetMarkerStyle(21); 
    hEvTh_TACg1->SetMarkerSize(0.8); hEvTh_TACg1->SetMarkerColor(kRed); 

    hEvTh_TACg2->Draw("same"); hEvTh_TACg2->SetMarkerStyle(21); 
    hEvTh_TACg2->SetMarkerSize(0.8); hEvTh_TACg2->SetMarkerColor(kBlue);

    hEvTh_TACg3->Draw("same"); hEvTh_TACg3->SetMarkerStyle(21); 
    hEvTh_TACg3->SetMarkerSize(0.8); hEvTh_TACg3->SetMarkerColor(kBlack);

    hEvTh_TACg4->Draw("same"); hEvTh_TACg4->SetMarkerStyle(21); 
    hEvTh_TACg4->SetMarkerSize(0.8); hEvTh_TACg4->SetMarkerColor(kGreen); 

    hEvTh_TACg5->Draw("same"); hEvTh_TACg5->SetMarkerStyle(21); 
    hEvTh_TACg5->SetMarkerSize(0.8); hEvTh_TACg5->SetMarkerColor(kOrange);

    hEvTh_TACg6->Draw("same"); hEvTh_TACg6->SetMarkerStyle(21); 
    hEvTh_TACg6->SetMarkerSize(0.8); hEvTh_TACg6->SetMarkerColor(kMagenta); 

    c[40]->cd(3); f2->cd(); gPad->SetLogz(); hEvTh->Draw("col");
    hEvTh_TACg1->Draw("same"); hEvTh_TACg1->SetMarkerStyle(21); 
    hEvTh_TACg1->SetMarkerSize(0.8); hEvTh_TACg1->SetMarkerColor(kRed); 

    hEvTh_TACg2->Draw("same"); hEvTh_TACg2->SetMarkerStyle(21); 
    hEvTh_TACg2->SetMarkerSize(0.8); hEvTh_TACg2->SetMarkerColor(kBlue);

    hEvTh_TACg3->Draw("same"); hEvTh_TACg3->SetMarkerStyle(21); 
    hEvTh_TACg3->SetMarkerSize(0.8); hEvTh_TACg3->SetMarkerColor(kBlack);

    hEvTh_TACg4->Draw("same"); hEvTh_TACg4->SetMarkerStyle(21); 
    hEvTh_TACg4->SetMarkerSize(0.8); hEvTh_TACg4->SetMarkerColor(kGreen);

    hEvTh_TACg5->Draw("same"); hEvTh_TACg5->SetMarkerStyle(21); 
    hEvTh_TACg5->SetMarkerSize(0.8); hEvTh_TACg5->SetMarkerColor(kOrange);

    hEvTh_TACg6->Draw("same"); hEvTh_TACg6->SetMarkerStyle(21); 
    hEvTh_TACg6->SetMarkerSize(0.8); hEvTh_TACg6->SetMarkerColor(kMagenta);

    c[40]->cd(4); f4->cd(); gPad->SetLogz(); hEvTh->Draw("col");
    hEvTh_TACg1->Draw("same"); hEvTh_TACg1->SetMarkerStyle(21); 
    hEvTh_TACg1->SetMarkerSize(0.8); hEvTh_TACg1->SetMarkerColor(kRed); 

    hEvTh_TACg2->Draw("same"); hEvTh_TACg2->SetMarkerStyle(21); 
    hEvTh_TACg2->SetMarkerSize(0.8); hEvTh_TACg2->SetMarkerColor(kBlue); 

    hEvTh_TACg3->Draw("same"); hEvTh_TACg3->SetMarkerStyle(21); 
    hEvTh_TACg3->SetMarkerSize(0.8); hEvTh_TACg3->SetMarkerColor(kBlack);

    hEvTh_TACg4->Draw("same"); hEvTh_TACg4->SetMarkerStyle(21); 
    hEvTh_TACg4->SetMarkerSize(0.8); hEvTh_TACg4->SetMarkerColor(kGreen);

    hEvTh_TACg5->Draw("same"); hEvTh_TACg5->SetMarkerStyle(21); 
    hEvTh_TACg5->SetMarkerSize(0.8); hEvTh_TACg5->SetMarkerColor(kOrange);

    hEvTh_TACg6->Draw("same"); hEvTh_TACg6->SetMarkerStyle(21); 
    hEvTh_TACg6->SetMarkerSize(0.8); hEvTh_TACg6->SetMarkerColor(kMagenta); 

    c[40]->cd(5); f8->cd(); gPad->SetLogz(); hEvTh->Draw("col");
    hEvTh_TACg1->Draw("same"); hEvTh_TACg1->SetMarkerStyle(21); 
    hEvTh_TACg1->SetMarkerSize(0.8); hEvTh_TACg1->SetMarkerColor(kRed); 

    hEvTh_TACg2->Draw("same"); hEvTh_TACg2->SetMarkerStyle(21); 
    hEvTh_TACg2->SetMarkerSize(0.8); hEvTh_TACg2->SetMarkerColor(kBlue);

    hEvTh_TACg3->Draw("same"); hEvTh_TACg3->SetMarkerStyle(21); 
    hEvTh_TACg3->SetMarkerSize(0.8); hEvTh_TACg3->SetMarkerColor(kBlack); 

    hEvTh_TACg4->Draw("same"); hEvTh_TACg4->SetMarkerStyle(21); 
    hEvTh_TACg4->SetMarkerSize(0.8); hEvTh_TACg4->SetMarkerColor(kGreen);

    hEvTh_TACg5->Draw("same"); hEvTh_TACg5->SetMarkerStyle(21); 
    hEvTh_TACg5->SetMarkerSize(0.8); hEvTh_TACg5->SetMarkerColor(kOrange);

    hEvTh_TACg6->Draw("same"); hEvTh_TACg6->SetMarkerStyle(21); 
    hEvTh_TACg6->SetMarkerSize(0.8); hEvTh_TACg6->SetMarkerColor(kMagenta);

    c[40]->cd(6); f12->cd(); gPad->SetLogz(); hEvTh->Draw("col");
    hEvTh_TACg1->Draw("same"); hEvTh_TACg1->SetMarkerStyle(21); 
    hEvTh_TACg1->SetMarkerSize(0.8); hEvTh_TACg1->SetMarkerColor(kRed);

    hEvTh_TACg2->Draw("same"); hEvTh_TACg2->SetMarkerStyle(21); 
    hEvTh_TACg2->SetMarkerSize(0.8); hEvTh_TACg2->SetMarkerColor(kBlue);

    hEvTh_TACg3->Draw("same"); hEvTh_TACg3->SetMarkerStyle(21); 
    hEvTh_TACg3->SetMarkerSize(0.8); hEvTh_TACg3->SetMarkerColor(kBlack);

    hEvTh_TACg4->Draw("same"); hEvTh_TACg4->SetMarkerStyle(21); 
    hEvTh_TACg4->SetMarkerSize(0.8); hEvTh_TACg4->SetMarkerColor(kGreen);

    hEvTh_TACg5->Draw("same"); hEvTh_TACg5->SetMarkerStyle(21); 
    hEvTh_TACg5->SetMarkerSize(0.8); hEvTh_TACg5->SetMarkerColor(kOrange);

    hEvTh_TACg6->Draw("same"); hEvTh_TACg6->SetMarkerStyle(21); 
    hEvTh_TACg6->SetMarkerSize(0.8); hEvTh_TACg6->SetMarkerColor(kMagenta);

    c[40]->Update();
/* ************************************************************** */

/* ************************************************************** */
    for(i=1;i<41;i++){
        sprintf(save,"histograms/c%d.png",i);
        c[i]->SaveAs(save);
    }

    f0->Close(); f2->Close(); f4->Close(); f8->Close(); f12->Close(); fcuts->Close();
 return 0;
}
