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

TFile *f0 = new TFile("0ug.root","read");
TFile *f2 = new TFile("2ug.root","read");
TFile *f4 = new TFile("4ug.root","read");
TFile *f8 = new TFile("8ug.root","read");
TFile *f12 = new TFile("12ug.root","read");
TFile *fcuts = new TFile("cuts_0.root","read");


    int i;
    TCanvas *c[37];
    char can[2];
    char save[6];
    
    TCutG *beamcut = (TCutG*)fcuts->Get("beam");
    TCutG *uppercut = (TCutG*)fcuts->Get("upper");
    TCutG *lowercut = (TCutG*)fcuts->Get("lower");
    TCutG *dEEcut = (TCutG*)fcuts->Get("dE-Ecut");
    
    
    for(i=1;i<38;i++){
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
    c[7]->cd(2); gPad->SetLogz(); hFP_TACg1->Draw("col");
    c[7]->cd(3); f2->cd(); gPad->SetLogz(); hFP_TACg1->Draw("col");
    c[7]->cd(4); f4->cd(); gPad->SetLogz(); hFP_TACg1->Draw("col");
    c[7]->cd(5); f8->cd(); gPad->SetLogz(); hFP_TACg1->Draw("col");
    c[7]->cd(6); f12->cd(); gPad->SetLogz(); hFP_TACg1->Draw("col");
    
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
    c[13]->cd(3); f2->cd(); gPad->SetLogz(); hEvTh_TACg1->Draw();
    c[13]->cd(4); f4->cd(); gPad->SetLogz(); hEvTh_TACg1->Draw();
    c[13]->cd(5); f8->cd(); gPad->SetLogz(); hEvTh_TACg1->Draw();
    c[13]->cd(6); f12->cd(); gPad->SetLogz(); hEvTh_TACg1->Draw();
    
    c[14]->cd(1); f0->cd(); gPad->SetLogy(); hTACg2->Draw();
    c[14]->cd(2); hEvTh_TACg2->Draw();
    c[14]->cd(3); f2->cd(); hEvTh_TACg2->Draw();
    c[14]->cd(4); f4->cd(); hEvTh_TACg2->Draw();
    c[14]->cd(5); f8->cd(); hEvTh_TACg2->Draw();
    c[14]->cd(6); f12->cd(); hEvTh_TACg2->Draw();
    
    c[15]->cd(1); f0->cd(); gPad->SetLogy(); hTACg3->Draw();
    c[15]->cd(2); hEvTh_TACg3->Draw();
    c[15]->cd(3); f2->cd(); hEvTh_TACg3->Draw();
    c[15]->cd(4); f4->cd(); hEvTh_TACg3->Draw();
    c[15]->cd(5); f8->cd(); hEvTh_TACg3->Draw();
    c[15]->cd(6); f12->cd(); hEvTh_TACg3->Draw();
    
    c[16]->cd(1); f0->cd(); gPad->SetLogy(); hTACg4->Draw();
    c[16]->cd(2); hEvTh_TACg4->Draw();
    c[16]->cd(3); f2->cd(); hEvTh_TACg4->Draw();
    c[16]->cd(4); f4->cd(); hEvTh_TACg4->Draw();
    c[16]->cd(5); f8->cd(); hEvTh_TACg4->Draw();
    c[16]->cd(6); f12->cd();hEvTh_TACg4->Draw();
    
    c[17]->cd(1); f0->cd(); gPad->SetLogy(); hTACg5->Draw();
    c[17]->cd(2); hEvTh_TACg5->Draw();
    c[17]->cd(3); f2->cd(); hEvTh_TACg5->Draw();
    c[17]->cd(4); f4->cd(); hEvTh_TACg5->Draw();
    c[17]->cd(5); f8->cd(); hEvTh_TACg5->Draw();
    c[17]->cd(6); f12->cd();hEvTh_TACg5->Draw();
    
    c[18]->cd(1); f0->cd(); gPad->SetLogy(); hTACg6->Draw();
    c[18]->cd(2); hEvTh_TACg6->Draw();
    c[18]->cd(3); f2->cd(); hEvTh_TACg6->Draw();
    c[18]->cd(4); f4->cd(); hEvTh_TACg6->Draw();
    c[18]->cd(5); f8->cd(); hEvTh_TACg6->Draw();
    c[18]->cd(6); f12->cd(); hEvTh_TACg6->Draw();

    // dE vs Theta, gated on 6 TAC gates
    
    c[19]->cd(1); f0->cd(); gPad->SetLogy(); hTACg1->Draw();
    c[19]->cd(2); gPad->SetLogz(); hdEvTh_TACg1->Draw("col");
    c[19]->cd(3); f2->cd(); gPad->SetLogz(); hdEvTh_TACg1->Draw("col");
    c[19]->cd(4); f4->cd(); gPad->SetLogz(); hdEvTh_TACg1->Draw("col");
    c[19]->cd(5); f8->cd(); gPad->SetLogz(); hdEvTh_TACg1->Draw("col");
    c[19]->cd(6); f12->cd(); gPad->SetLogz(); hdEvTh_TACg1->Draw("col");
    
    c[20]->cd(1); f0->cd(); gPad->SetLogy(); hTACg2->Draw();
    c[20]->cd(2); hdEvTh_TACg2->Draw();
    c[20]->cd(3); f2->cd(); hdEvTh_TACg2->Draw();
    c[20]->cd(4); f4->cd(); hdEvTh_TACg2->Draw();
    c[20]->cd(5); f8->cd(); hdEvTh_TACg2->Draw();
    c[20]->cd(6); f12->cd(); hdEvTh_TACg2->Draw();
    
    c[21]->cd(1); f0->cd(); gPad->SetLogy(); hTACg3->Draw();
    c[21]->cd(2); hdEvTh_TACg3->Draw();
    c[21]->cd(3); f2->cd(); hdEvTh_TACg3->Draw();
    c[21]->cd(4); f4->cd(); hdEvTh_TACg3->Draw();
    c[21]->cd(5); f8->cd(); hdEvTh_TACg3->Draw();
    c[21]->cd(6); f12->cd(); hdEvTh_TACg3->Draw();
    
    c[22]->cd(1); f0->cd(); gPad->SetLogy(); hTACg4->Draw();
    c[22]->cd(2); hdEvTh_TACg4->Draw();
    c[22]->cd(3); f2->cd(); hdEvTh_TACg4->Draw();
    c[22]->cd(4); f4->cd(); hdEvTh_TACg4->Draw();
    c[22]->cd(5); f8->cd(); hdEvTh_TACg4->Draw();
    c[22]->cd(6); f12->cd();hdEvTh_TACg4->Draw();
    
    c[23]->cd(1); f0->cd(); gPad->SetLogy(); hTACg5->Draw();
    c[23]->cd(2); hdEvTh_TACg5->Draw();
    c[23]->cd(3); f2->cd(); hdEvTh_TACg5->Draw();
    c[23]->cd(4); f4->cd(); hdEvTh_TACg5->Draw();
    c[23]->cd(5); f8->cd(); hdEvTh_TACg5->Draw();
    c[23]->cd(6); f12->cd();hdEvTh_TACg5->Draw();
   
    c[24]->cd(1); f0->cd(); gPad->SetLogy(); hTACg6->Draw();
    c[24]->cd(2); hdEvTh_TACg6->Draw();
    c[24]->cd(3); f2->cd(); hdEvTh_TACg6->Draw();
    c[24]->cd(4); f4->cd(); hdEvTh_TACg6->Draw();
    c[24]->cd(5); f8->cd(); hdEvTh_TACg6->Draw();
    c[24]->cd(6); f12->cd(); hdEvTh_TACg6->Draw();

    /* ************************************************************** */
    
    // gated on dE-E
    c[25]->cd(1); f0->cd(); gPad->SetLogz(); hdE_E_rings->Draw("col"); dEEcut->Draw("same");
    c[25]->cd(2); gPad->SetLogy(); hTAC_dEEg->Draw();
    c[25]->cd(3); f2->cd(); gPad->SetLogy(); hTAC_dEEg->Draw();
    c[25]->cd(4); f4->cd(); gPad->SetLogy(); hTAC_dEEg->Draw();
    c[25]->cd(5); f8->cd(); gPad->SetLogy(); hTAC_dEEg->Draw();
    c[25]->cd(6); f12->cd(); gPad->SetLogy(); hTAC_dEEg->Draw();
    
    c[26]->cd(1); f0->cd(); gPad->SetLogz(); hdE_E_rings->Draw("col"); dEEcut->Draw("same");
    c[26]->cd(2); gPad->SetLogz(); hFP_dEEg->Draw("col");
    c[26]->cd(3); f2->cd(); gPad->SetLogz(); hFP_dEEg->Draw("col");
    c[26]->cd(4); f4->cd(); gPad->SetLogz(); hFP_dEEg->Draw("col");
    c[26]->cd(5); f8->cd(); gPad->SetLogz(); hFP_dEEg->Draw("col");
    c[26]->cd(6); f12->cd();gPad->SetLogz(); hFP_dEEg->Draw("col");
    
    c[27]->cd(1); f0->cd(); gPad->SetLogz(); hdE_E_rings->Draw("col"); dEEcut->Draw("same");
    c[27]->cd(2); gPad->SetLogz(); hEvTh_dEEg->Draw("col");
    c[27]->cd(3); f2->cd(); gPad->SetLogz(); hEvTh_dEEg->Draw("col");
    c[27]->cd(4); f4->cd(); gPad->SetLogz(); hEvTh_dEEg->Draw("col");
    c[27]->cd(5); f8->cd(); gPad->SetLogz(); hEvTh_dEEg->Draw("col");
    c[27]->cd(6); f12->cd();gPad->SetLogz(); hEvTh_dEEg->Draw("col");
    
    c[28]->cd(1); f0->cd(); gPad->SetLogz(); hdE_E_rings->Draw("col"); dEEcut->Draw("same");
    c[28]->cd(2); gPad->SetLogz(); hdEvTh_dEEg->Draw("col");
    c[28]->cd(3); f2->cd(); gPad->SetLogz(); hdEvTh_dEEg->Draw("col");
    c[28]->cd(4); f4->cd(); gPad->SetLogz(); hdEvTh_dEEg->Draw("col");
    c[28]->cd(5); f8->cd(); gPad->SetLogz(); hdEvTh_dEEg->Draw("col");
    c[28]->cd(6); f12->cd(); gPad->SetLogz(); hdEvTh_dEEg->Draw("col");
    


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

/* ************************************************************** */
    for(i=1;i<38;i++){
        sprintf(save,"histograms/c%d.png",i);
        c[i]->SaveAs(save);
    }

    f0->Close(); f2->Close(); f4->Close(); f8->Close(); f12->Close(); fcuts->Close();
 return 0;
}
