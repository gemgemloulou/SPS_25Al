#define analysis_c
#include "analysis.h"
#include <TH2.h>
#include <TH1.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TCutG.h>

// h->SetMarkerStyle(21) changes the marker to a big black square
// then you can change the size with h->SetMarkerSize(0.8)

// separate chain for beam check runs? Do I chain them together or look at the separately?

void analysis::Loop()
{
   if (fChain == 0) return;
   TFile *output = new TFile("0mg.root","recreate");
    TFile *fcuts = new TFile("cuts_0.root","read");
    //  TFile *fcuts = new TFile("cuts_2.root","read");
    // TFile *fcuts = new TFile("cuts_4.root","read");
    //  TFile *fcuts = new TFile("cuts_8.root","read");
   // TFile *fcuts = new TFile("cuts_12.root","read");
//-----------------------------------------------------------------------
   // define output histograms

   // ungated
   TH2D *hdE_E_rings = new TH2D("hdE_E_rings","dE-E rings, ungated, 0mg/cm2",700,0,70,320,0.3,3.5);
   TH1D *hTAC = new TH1D("hTAC","TAC, ungated, 0mg/cm2",256,0,4096);
   TH2D *hEvTh = new TH2D("hEvTh","E v Ring num, ungated, 0mg/cm2",700,0,70,16,0,16);
   TH2D *hdEvTh = new TH2D("hdEvTh","dE v Ring num, ungated, 0mg/cm2",200,0,20,16,0,16);
   TH2D *hxvrftof = new TH2D("hxvrftof","X vs RFTOF, ungated, 0mg/cm2",1000,0,1000,4000,0,4000);

   // gate on TAC, look at dE-E
   TH2D *hdEE_TACg1 = new TH2D("hdEE_TACg1","dE-E rings, 50<TAC<500, 0mg/cm2",700,0,70,320,0.3,3.5);
   TH2D *hdEE_TACg2 = new TH2D("hdEE_TACg2","dE-E rings, 500<TAC<1200, 0mg/cm2",700,0,70,320,0.3,3.5);
   TH2D *hdEE_TACg3 = new TH2D("hdEE_TACg3","dE-E rings, 1600<TAC<2000, 0mg/cm2",700,0,70,320,0.3,3.5);
   TH2D *hdEE_TACg4 = new TH2D("hdEE_TACg4","dE-E rings, 2300<TAC<2700, 0mg/cm2",700,0,70,320,0.3,3.5);
   TH2D *hdEE_TACg5 = new TH2D("hdEE_TACg5","dE-E rings, 3100<TAC<3500, 0mg/cm2",700,0,70,320,0.3,3.5);
   TH2D *hdEE_TACg6 = new TH2D("hdEE_TACg6","dE-E rings, 3800<TAC<4096, 0mg/cm2",700,0,70,320,0.3,3.5);

   TH1D *hTACg1 = new TH1D("hTACg1","50<TAC<500, 0mg/cm2",256,0,4096);
   TH1D *hTACg2 = new TH1D("hTACg2","500<TAC<1200, 0mg/cm2",256,0,4096);
   TH1D *hTACg3 = new TH1D("hTACg3","1600<TAC<2000, 0mg/cm2",256,0,4096);
   TH1D *hTACg4 = new TH1D("hTACg4","2300<TAC<2700, 0mg/cm2",256,0,4096);
   TH1D *hTACg5 = new TH1D("hTACg5","3100<TAC<3500, 0mg/cm2",256,0,4096);
   TH1D *hTACg6 = new TH1D("hTACg6","3800<TAC<4096, 0mg/cm2",256,0,4096);

   // gate on TAC, look at focal plane
   TH2D *hFP_TACg1 = new TH2D("hFP_TACg1","Focal Plane, 50<TAC<500, 0mg/cm2",1000,0,1000,4000,0,4000);
   TH2D *hFP_TACg2 = new TH2D("hFP_TACg2","Focal Plane, 500<TAC<1200, 0mg/cm2",1000,0,1000,4000,0,4000);
   TH2D *hFP_TACg3 = new TH2D("hFP_TACg3","Focal Plane, 1600<TAC<2000, 0mg/cm2",1000,0,1000,4000,0,4000);
   TH2D *hFP_TACg4 = new TH2D("hFP_TACg4","Focal Plane, 2300<TAC<2700, 0mg/cm2",1000,0,1000,4000,0,4000);
   TH2D *hFP_TACg5 = new TH2D("hFP_TACg5","Focal Plane, 3100<TAC<3500, 0mg/cm2",1000,0,1000,4000,0,4000);
   TH2D *hFP_TACg6 = new TH2D("hFP_TACg6","Focal Plane, 3800<TAC<4096, 0mg/cm2",1000,0,1000,4000,0,4000);

   // gate on TAC, look at E v Theta
   TH2D *hEvTh_TACg1 = new TH2D("hEvTh_TACg1","E v Theta, 50<TAC<500, 0mg/cm2",700,0,70,16,0,16);
   TH2D *hEvTh_TACg2 = new TH2D("hEvTh_TACg2","E v Theta, 500<TAC<1200, 0mg/cm2",700,0,70,16,0,16);
   TH2D *hEvTh_TACg3 = new TH2D("hEvTh_TACg3","E v Theta, 1600<TAC<2000, 0mg/cm2",700,0,70,16,0,16);
   TH2D *hEvTh_TACg4 = new TH2D("hEvTh_TACg4","E v Theta, 2300<TAC<2700, 0mg/cm2",700,0,70,16,0,16);
   TH2D *hEvTh_TACg5 = new TH2D("hEvTh_TACg5","E v Theta, 3100<TAC<3500, 0mg/cm2",700,0,70,16,0,16);
   TH2D *hEvTh_TACg6 = new TH2D("hEvTh_TACg6","E v Theta, 3800<TAC<4096, 0mg/cm2",700,0,70,16,0,16);

   // gate on TAC, look at dE v Theta
   TH2D *hdEvTh_TACg1 = new TH2D("hdEvTh_TACg1","dE v Theta, TAC<500, 0mg/cm2",200,0,20,16,0,16);
   TH2D *hdEvTh_TACg2 = new TH2D("hdEvTh_TACg2","dE v Theta, 500<TAC<1200, 0mg/cm2",200,0,20,16,0,16);
   TH2D *hdEvTh_TACg3 = new TH2D("hdEvTh_TACg3","dE v Theta, 1600<TAC<2000, 0mg/cm2",200,0,20,16,0,16);
   TH2D *hdEvTh_TACg4 = new TH2D("hdEvTh_TACg4","dE v Theta, 2300<TAC<2700, 0mg/cm2",200,0,20,16,0,16);
   TH2D *hdEvTh_TACg5 = new TH2D("hdEvTh_TACg5","dE v Theta, 3100<TAC<3500, 0mg/cm2",200,0,20,16,0,16);
   TH2D *hdEvTh_TACg6 = new TH2D("hdEvTh_TACg6","dE v Theta, 3800<TAC<4096, 0mg/cm2",200,0,20,16,0,16);

   // gate on dE-E
   TH1D *hTAC_dEEg = new TH1D("hTAC_dEEg","TAC, gated on dE-E locus, 0mg/cm2",256,0,4096);
   TH2D *hFP_dEEg = new TH2D("hFP_dEEg","Focal plane, gated on dE-E locus, 0mg/cm2",1000,0,1000,4000,0,4000);
   TH2D *hEvTh_dEEg = new TH2D("hEvTh_dEEg","EvTh, gated on dE-E locus, 0mg/cm2",700,0,70,16,0,16);
   TH2D *hdEvTh_dEEg = new TH2D("hdEvTh_dEEg","dEvTh, gated on dE-E locus, 0mg/cm2",200,0,20,16,0,16);

   // gate on EvTh
   TH1D *hTAC_EvTg = new TH1D("hTAC_EvTg","TAC, gated on EvTheta locus, 0mg/cm2",256,0,4096);
   TH2D *hFP_EvTg = new TH2D("hFP_dEvTg","Focal plane, gated on EvTheta locus, 0mg/cm2",1000,0,1000,4000,0,4000);
   TH2D *hdEE_EvTg = new TH2D("hdEE_EvTg","dE-E, gated on EvTh locus, 0mg/cm2",700,0,70,320,0.3,3.5);
   TH2D *hdEvTh_EvTg = new TH2D("hdEvTh_EvTg","dEvTh, gated on EvTh locus, 0mg/cm2",200,0,20,16,0,16);

   // gate on FP
   TH2D *hdEE_FPgb = new TH2D("hdEE_FPgb","dE-E, gate on beam FP, 0mg/cm2",700,0,70,320,0.3,3.5);
   TH2D *hdEE_FPgu = new TH2D("hdEE_FPgu","dE-E, gate on upper FP, 0mg/cm2",700,0,70,320,0.3,3.5);
   TH2D *hdEE_FPgl = new TH2D("hdEE_FPgl","dE-E, gate on lower FP, 0mg/cm2",700,0,70,320,0.3,3.5);

   TH1D *hTAC_FPgb = new TH1D("hTAC_FPgb","TAC, gated on beam FP, 0mg/cm2",256,0,4096);
   TH1D *hTAC_FPgu = new TH1D("hTAC_FPgu","TAC, gated on upper FP, 0mg/cm2",256,0,4096);
   TH1D *hTAC_FPgl = new TH1D("hTAC_FPgl","TAC, gated on lower FP, 0mg/cm2",256,0,4096);

   TH2D *hEvTh_FPgb = new TH2D("hEvTh_FPgb","E v Theta, gated on beam FP, 0mg/cm2",700,0,70,16,0,16);
   TH2D *hEvTh_FPgu = new TH2D("hEvTh_FPgu","E v Theta, gated on upper FP, 0mg/cm2",700,0,70,16,0,16);
   TH2D *hEvTh_FPgl = new TH2D("hEvTh_FPgl","E v Theta, gated on lower FP, 0mg/cm2",700,0,70,16,0,16);

   TH2D *hdEvTh_FPgb = new TH2D("hdEvTh_FPgb","dE v Theta, gated on beam FP, 0mg/cm2",200,0,20,16,0,16);
   TH2D *hdEvTh_FPgu = new TH2D("hdEvTh_FPgu","dE v Theta, gated on upper FP, 0mg/cm2",200,0,20,16,0,16);
   TH2D *hdEvTh_FPgl = new TH2D("hdEvTh_FPgl","dE v Theta, gated on lower FP, 0mg/cm2",200,0,20,16,0,16);

   // double gates
   TH2D *hdEE_TAC1_FPb = new TH2D("hdEE_TAC1_FPb","dE-E, 50<TAC<500, beam FP, 0mg/cm2",700,0,70,320,0.3,3.5);
   TH2D *hdEE_TAC1_FPu = new TH2D("hdEE_TAC1_FPu","dE-E, 50<TAC<500, upper FP, 0mg/cm2",700,0,70,320,0.3,3.5);
   TH2D *hdEE_TAC1_FPl = new TH2D("hdEE_TAC1_FPl","dE-E, 50<TAC<500, lower FP, 0mg/cm2",700,0,70,320,0.3,3.5);
   TH2D *hdEE_TAC2_FPb = new TH2D("hdEE_TAC2_FPb","dE-E, 500<TAC<1200, beam FP, 0mg/cm2",700,0,70,320,0.3,3.5);
   TH2D *hdEE_TAC2_FPu = new TH2D("hdEE_TAC2_FPu","dE-E, 500<TAC<1200, upper FP, 0mg/cm2",700,0,70,320,0.3,3.5);
   TH2D *hdEE_TAC2_FPl = new TH2D("hdEE_TAC2_FPl","dE-E, 500<TAC<1200, lower FP, 0mg/cm2",700,0,70,320,0.3,3.5);
   TH2D *hdEE_TAC3_FPb = new TH2D("hdEE_TAC3_FPb","dE-E, 1600<TAC<2000, beam FP, 0mg/cm2",700,0,70,320,0.3,3.5);
   TH2D *hdEE_TAC3_FPu = new TH2D("hdEE_TAC3_FPu","dE-E, 1600<TAC<2000, upper FP, 0mg/cm2",700,0,70,320,0.3,3.5);
   TH2D *hdEE_TAC3_FPl = new TH2D("hdEE_TAC3_FPl","dE-E, 1600<TAC<2000, lower FP, 0mg/cm2",700,0,70,320,0.3,3.5);
   TH2D *hdEE_TAC4_FPb = new TH2D("hdEE_TAC4_FPb","dE-E, 2300<TAC<2700, beam FP, 0mg/cm2",700,0,70,320,0.3,3.5);
   TH2D *hdEE_TAC4_FPu = new TH2D("hdEE_TAC4_FPu","dE-E, 2300<TAC<2700, upper FP, 0mg/cm2",700,0,70,320,0.3,3.5);
   TH2D *hdEE_TAC4_FPl = new TH2D("hdEE_TAC4_FPl","dE-E, 2300<TAC<2700, lower FP, 0mg/cm2",700,0,70,320,0.3,3.5);
   TH2D *hdEE_TAC5_FPb = new TH2D("hdEE_TAC5_FPb","dE-E, 3100<TAC<3500, beam FP, 0mg/cm2",700,0,70,320,0.3,3.5);
   TH2D *hdEE_TAC5_FPu = new TH2D("hdEE_TAC5_FPu","dE-E, 3100<TAC<3500, upper FP, 0mg/cm2",700,0,70,320,0.3,3.5);
   TH2D *hdEE_TAC5_FPl = new TH2D("hdEE_TAC5_FPl","dE-E, 3100<TAC<3500, lower FP, 0mg/cm2",700,0,70,320,0.3,3.5);
   TH2D *hdEE_TAC6_FPb = new TH2D("hdEE_TAC6_FPb","dE-E, 3800<TAC<4096, beam FP, 0mg/cm2",700,0,70,320,0.3,3.5);
   TH2D *hdEE_TAC6_FPu = new TH2D("hdEE_TAC6_FPu","dE-E, 3800<TAC<4096, upper FP, 0mg/cm2",700,0,70,320,0.3,3.5);
   TH2D *hdEE_TAC6_FPl = new TH2D("hdEE_TAC6_FPl","dE-E, 3800<TAC<4096, lower FP, 0mg/cm2",700,0,70,320,0.3,3.5);

   // Emax, etc
   TH2D *hEFmax_EBmax = new TH2D("hEFmax_EBmax","Max front v Back, E",700,0,70,700,0,70);
   TH2D *hEF_EB = new TH2D("hEF_EB","front v Back, E",700,0,70,700,0,70);
   TH2D *hdEFmax_dEBmax = new TH2D("hdEFmax_dEBmax","Max front v Back, dE",700,0,70,700,0,70);
   TH2D *hdEF_dEB = new TH2D("hdEF_dEB","front v Back, dE",700,0,70,700,0,70);
   TH2D *hdEFmax_EFmax = new TH2D("hdEFmax_EFmax","Max front dE v E",700,0,70,700,0,70);
   TH2D *hdEBmax_EBmax = new TH2D("hdEBmax_EBmax","Max back dE v E",700,0,70,700,0,70);
   TH2D *hEFmaxvTh = new TH2D("hEFmaxvTh","Emax v Ring num, ungated, 0mg/cm2",700,0,70,16,0,16);
   TH2D *hdEFmaxvTh = new TH2D("hdEFmaxvTh","dEmax v Ring num, ungated, 0mg/cm2",200,0,20,16,0,16);
   TH2D *hEBmaxvTh = new TH2D("hEBmaxvTh","Emax v wedge num, ungated, 0mg/cm2",700,0,70,16,0,16);
   TH2D *hdEBmaxvTh = new TH2D("hdEBmaxvTh","dEmax v wedge num, ungated, 0mg/cm2",200,0,20,16,0,16);
  
//-----------------------------------------------------------------------

   TCutG *beamcut = (TCutG*)fcuts->Get("beam");
   TCutG *uppercut = (TCutG*)fcuts->Get("upper");
   TCutG *lowercut = (TCutG*)fcuts->Get("lower");
   TCutG *dEEcut = (TCutG*)fcuts->Get("dE-Ecut");
   TCutG *EvThcut = (TCutG*)fcuts->Get("EvTh");

//----------------------------------------------------------------------- 
   Long64_t nentries = fChain->GetEntries();
   output->cd();

   // define variables

   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      //fChain->GetEntry(jentry);
      b_dE_Fmult->GetEntry(ientry);
      b_dE_Fnum->GetEntry(ientry);
      b_dE_Fenergy->GetEntry(ientry);
      b_E_Fmult->GetEntry(ientry);
      b_E_Fnum->GetEntry(ientry);
      b_E_Fenergy->GetEntry(ientry);
      b_dE_Bmult->GetEntry(ientry);
      b_dE_Bnum->GetEntry(ientry);
      b_dE_Benergy->GetEntry(ientry);
      b_E_Bmult->GetEntry(ientry);
      b_E_Bnum->GetEntry(ientry);
      b_E_Benergy->GetEntry(ientry);
      b_rftof->GetEntry(ientry);
      b_spare->GetEntry(ientry);
      b_x->GetEntry(ientry);


      emaxF_E = emaxF_dE = emaxB_E = emaxB_dE = 0;
      nmaxF_E = nmaxF_dE = nmaxB_E = nmaxB_dE = -5;

//-----------------------------------------------------------------------
   
   for(j=0;j<E_FMult;j++){
    for(k=0;k<dE_FMult;k++){
      hdE_E_rings->Fill(E_Fenergy[j],dE_Fenergy[k]);  // dE-E ungated
      if(spare>50 && spare<500){
	hdEE_TACg1->Fill(E_Fenergy[j],dE_Fenergy[k]); // dE-E TAC gated
	if(beamcut->IsInside(x,rftof)) hdEE_TAC1_FPb->Fill(E_Fenergy[j],dE_Fenergy[k]);
	if(uppercut->IsInside(x,rftof)) hdEE_TAC1_FPu->Fill(E_Fenergy[j],dE_Fenergy[k]);
	if(lowercut->IsInside(x,rftof)) hdEE_TAC1_FPl->Fill(E_Fenergy[j],dE_Fenergy[k]);
      } else if(spare>500 && spare<1200){
	hdEE_TACg2->Fill(E_Fenergy[j],dE_Fenergy[k]);
	if(beamcut->IsInside(x,rftof)) hdEE_TAC2_FPb->Fill(E_Fenergy[j],dE_Fenergy[k]);
	if(uppercut->IsInside(x,rftof)) hdEE_TAC2_FPu->Fill(E_Fenergy[j],dE_Fenergy[k]);
	if(lowercut->IsInside(x,rftof)) hdEE_TAC2_FPl->Fill(E_Fenergy[j],dE_Fenergy[k]);
      }else if(spare>1600 && spare<2000){
	hdEE_TACg3->Fill(E_Fenergy[j],dE_Fenergy[k]);
	if(beamcut->IsInside(x,rftof)) hdEE_TAC3_FPb->Fill(E_Fenergy[j],dE_Fenergy[k]);
	if(uppercut->IsInside(x,rftof)) hdEE_TAC3_FPu->Fill(E_Fenergy[j],dE_Fenergy[k]);
	if(lowercut->IsInside(x,rftof)) hdEE_TAC3_FPl->Fill(E_Fenergy[j],dE_Fenergy[k]);
      }else if(spare>2300 && spare<2700){
	hdEE_TACg4->Fill(E_Fenergy[j],dE_Fenergy[k]);
	if(beamcut->IsInside(x,rftof)) hdEE_TAC4_FPb->Fill(E_Fenergy[j],dE_Fenergy[k]);
	if(uppercut->IsInside(x,rftof)) hdEE_TAC4_FPu->Fill(E_Fenergy[j],dE_Fenergy[k]);
	if(lowercut->IsInside(x,rftof)) hdEE_TAC4_FPl->Fill(E_Fenergy[j],dE_Fenergy[k]);
      }else if(spare>3100 && spare<3500){
	hdEE_TACg5->Fill(E_Fenergy[j],dE_Fenergy[k]);
	if(beamcut->IsInside(x,rftof)) hdEE_TAC5_FPb->Fill(E_Fenergy[j],dE_Fenergy[k]);
	if(uppercut->IsInside(x,rftof)) hdEE_TAC5_FPu->Fill(E_Fenergy[j],dE_Fenergy[k]);
	if(lowercut->IsInside(x,rftof)) hdEE_TAC5_FPl->Fill(E_Fenergy[j],dE_Fenergy[k]);
      }else if(spare>3800 && spare<4096){
	hdEE_TACg6->Fill(E_Fenergy[j],dE_Fenergy[k]);
	if(beamcut->IsInside(x,rftof)) hdEE_TAC6_FPb->Fill(E_Fenergy[j],dE_Fenergy[k]);
	if(uppercut->IsInside(x,rftof)) hdEE_TAC6_FPu->Fill(E_Fenergy[j],dE_Fenergy[k]);
	if(lowercut->IsInside(x,rftof)) hdEE_TAC6_FPl->Fill(E_Fenergy[j],dE_Fenergy[k]);
      }
      if(dEEcut->IsInside(E_Fenergy[j],dE_Fenergy[k])){
	hTAC_dEEg->Fill(spare);
	hFP_dEEg->Fill(x,rftof);
	hEvTh_dEEg->Fill(E_Fenergy[j],E_Fnum[j]);
	hdEvTh_dEEg->Fill(dE_Fenergy[k],dE_Fnum[k]);
      }
    }}

 for(j=0;j<E_FMult;j++){
   hEvTh->Fill(E_Fenergy[j],E_Fnum[j]);
    if(spare>50 && spare<500) hEvTh_TACg1->Fill(E_Fenergy[j],E_Fnum[j]);
    if(spare>500 && spare<1200) hEvTh_TACg2->Fill(E_Fenergy[j],E_Fnum[j]);
    if(spare>1600 && spare<2000) hEvTh_TACg3->Fill(E_Fenergy[j],E_Fnum[j]);
    if(spare>2300 && spare<2700) hEvTh_TACg4->Fill(E_Fenergy[j],E_Fnum[j]);
    if(spare>3100 && spare<3500) hEvTh_TACg5->Fill(E_Fenergy[j],E_Fnum[j]);
    if(spare>3800 && spare<4096) hEvTh_TACg6->Fill(E_Fenergy[j],E_Fnum[j]);
 }

 for(j=0;j<E_FMult;j++){
   if(EvThcut->IsInside(E_Fenergy[j],E_Fnum[j])){
     hTAC_EvTg->Fill(spare);
     hFP_EvTg->Fill(x,rftof);
        for(k=0;k<dE_FMult;k++){
	  hdEE_EvTg->Fill(E_Fenergy[j],dE_Fenergy[k]);
	  hdEvTh_EvTg->Fill(dE_Fenergy[k],dE_Fnum[k]);
	}
   }
 }

 for(k=0;k<dE_FMult;k++){
   hdEvTh->Fill(dE_Fenergy[k],dE_Fnum[k]);
    if(spare<500) hdEvTh_TACg1->Fill(dE_Fenergy[k],dE_Fnum[k]);
    if(spare>500 && spare<1200) hdEvTh_TACg2->Fill(dE_Fenergy[k],dE_Fnum[k]);
    if(spare>1600 && spare<2000) hdEvTh_TACg3->Fill(dE_Fenergy[k],dE_Fnum[k]);
    if(spare>2300 && spare<2700) hdEvTh_TACg4->Fill(dE_Fenergy[k],dE_Fnum[k]);
    if(spare>3100 && spare<3500) hdEvTh_TACg5->Fill(dE_Fenergy[k],dE_Fnum[k]);
    if(spare>3800 && spare<4096) hdEvTh_TACg6->Fill(dE_Fenergy[k],dE_Fnum[k]);
 }

  if(spare>50 && spare<500){ 
     hTACg1->Fill(spare); // TAC gated (for colour plotting purposes)
     hFP_TACg1->Fill(x,rftof);} // Focal plane, TAC gated
   if(spare>500 && spare<1200){
     hTACg2->Fill(spare);
     hFP_TACg2->Fill(x,rftof);}
   if(spare>1600 && spare<2000){ 
     hTACg3->Fill(spare);
     hFP_TACg3->Fill(x,rftof);}
   if(spare>2300 && spare<2700) {
     hTACg4->Fill(spare);
     hFP_TACg4->Fill(x,rftof);}
   if(spare>3100 && spare<3500){
     hTACg5->Fill(spare);
     hFP_TACg5->Fill(x,rftof);}
   if(spare>3800 && spare<4096){
     hTACg6->Fill(spare);
     hFP_TACg6->Fill(x,rftof);}

   hTAC->Fill(spare);
   hxvrftof->Fill(x,rftof);

   // gate on focal plane
  for(j=0;j<E_FMult;j++){
    for(k=0;k<dE_FMult;k++){  
      if(beamcut->IsInside(x,rftof)) hdEE_FPgb->Fill(E_Fenergy[j],dE_Fenergy[k]);
      if(uppercut->IsInside(x,rftof)) hdEE_FPgu->Fill(E_Fenergy[j],dE_Fenergy[k]);
      if(lowercut->IsInside(x,rftof)) hdEE_FPgl->Fill(E_Fenergy[j],dE_Fenergy[k]);
	 }
    }

 for(j=0;j<E_FMult;j++){
   if(beamcut->IsInside(x,rftof)) hEvTh_FPgb->Fill(E_Fenergy[j],E_Fnum[j]);
   if(uppercut->IsInside(x,rftof)) hEvTh_FPgu->Fill(E_Fenergy[j],E_Fnum[j]);
   if(lowercut->IsInside(x,rftof)) hEvTh_FPgl->Fill(E_Fenergy[j],E_Fnum[j]);
 }

for(k=0;k<dE_FMult;k++){
   if(beamcut->IsInside(x,rftof)) hdEvTh_FPgb->Fill(dE_Fenergy[k],dE_Fnum[k]);
   if(uppercut->IsInside(x,rftof)) hdEvTh_FPgu->Fill(dE_Fenergy[k],dE_Fnum[k]);
   if(lowercut->IsInside(x,rftof)) hdEvTh_FPgl->Fill(dE_Fenergy[k],dE_Fnum[k]);
 }

  if(beamcut->IsInside(x,rftof)) hTAC_FPgb->Fill(spare);
 if(uppercut->IsInside(x,rftof)) hTAC_FPgu->Fill(spare);
 if(lowercut->IsInside(x,rftof)) hTAC_FPgl->Fill(spare);
     
    // TAC regions:
    // 0mg/cm2: 50<t<500 | 500<t<1200 | 1600<t<2000 | 2300<t<2700 | 3100<t<3500 | 3800<t<4096
//-----------------------------------------------------------------------

 for(i=0;i<E_FMult;i++){
   if(E_Fenergy[i]>emaxF_E){
     emaxF_E = E_Fenergy[i];
     nmaxF_E = E_Fnum[i];
   }}

for(i=0;i<E_BMult;i++){
   if(E_Benergy[i]>emaxB_E){
     emaxB_E = E_Benergy[i];
     nmaxB_E = E_Bnum[i];
   }}

 for(i=0;i<dE_FMult;i++){
   if(dE_Fenergy[i]>emaxF_dE){
     emaxF_dE = dE_Fenergy[i];
     nmaxF_dE = dE_Fnum[i];
   }}

for(i=0;i<dE_BMult;i++){
   if(dE_Benergy[i]>emaxB_dE){
     emaxB_dE = dE_Benergy[i];
     nmaxB_dE = dE_Bnum[i];
   }}


 hEFmax_EBmax->Fill(emaxF_E,emaxB_E);
 hdEFmax_dEBmax->Fill(emaxF_dE,emaxB_dE);
 hdEFmax_EFmax->Fill(emaxF_dE,emaxF_E);
 hdEBmax_EBmax->Fill(emaxB_dE,emaxB_E);
 hEFmaxvTh->Fill(emaxF_E,nmaxF_E);
 hdEFmaxvTh->Fill(emaxF_dE,nmaxF_dE);
 hEBmaxvTh->Fill(emaxB_E,nmaxB_E);
 hdEBmaxvTh->Fill(emaxB_dE,nmaxB_dE);

 for(i=0;i<E_FMult;i++){
   for(j=0;j<E_BMult;j++){
     hEF_EB->Fill(E_Fenergy[i],E_Benergy[j]);
   }}

 for(i=0;i<dE_FMult;i++){
   for(j=0;j<dE_BMult;j++){
     hdEF_dEB->Fill(dE_Fenergy[i],dE_Benergy[j]);
   }}

 
//-----------------------------------------------------------------------
  if((jentry+1)%100000==0||jentry%(nentries-1)==0){
   cout << "\rProcessing. Event: " << jentry+1 << "/" << nentries << ", Done: ";
   cout << ((float) (jentry+1))/((float) nentries)*100. << "%";
   cout.flush();
   }
}
//-----------------------------------------------------------------------


   hdE_E_rings->Write();
   hTAC->Write();
   hEvTh->Write();
   hdEvTh->Write();
   hxvrftof->Write();
   hdEE_TACg1->Write(); 
   hdEE_TACg2->Write(); 
   hdEE_TACg3->Write(); 
   hdEE_TACg4->Write(); 
   hdEE_TACg5->Write(); 
   hdEE_TACg6->Write(); 
   hTAC_EvTg->Write();
   hFP_EvTg->Write();
   hdEE_EvTg->Write();
   hdEvTh_EvTg->Write();
   hTACg1->Write();
   hTACg2->Write();
   hTACg3->Write();
   hTACg4->Write();
   hTACg5->Write();
   hTACg6->Write();
   hFP_TACg1->Write();
   hFP_TACg2->Write();
   hFP_TACg3->Write();
   hFP_TACg4->Write();
   hFP_TACg5->Write();
   hFP_TACg6->Write();
   hEvTh_TACg1->Write();
   hEvTh_TACg2->Write();
   hEvTh_TACg3->Write();
   hEvTh_TACg4->Write();
   hEvTh_TACg5->Write();
   hEvTh_TACg6->Write();
   hdEvTh_TACg1->Write(); 
   hdEvTh_TACg2->Write(); 
   hdEvTh_TACg3->Write(); 
   hdEvTh_TACg4->Write(); 
   hdEvTh_TACg5->Write(); 
   hdEvTh_TACg6->Write(); 
   hTAC_dEEg->Write();
   hFP_dEEg->Write();
   hEvTh_dEEg->Write();
   hdEvTh_dEEg->Write();
   hdEE_FPgb->Write(); 
   hdEE_FPgu->Write(); 
   hdEE_FPgl->Write(); 
   hTAC_FPgb->Write();
   hTAC_FPgu->Write();
   hTAC_FPgl->Write();
   hEvTh_FPgb->Write();
   hEvTh_FPgu->Write();
   hEvTh_FPgl->Write();
   hdEvTh_FPgb->Write();
   hdEvTh_FPgu->Write();
   hdEvTh_FPgl->Write();

   hdEE_TAC1_FPb->Write();
   hdEE_TAC1_FPu->Write();
   hdEE_TAC1_FPl->Write();
   hdEE_TAC2_FPb->Write();
   hdEE_TAC2_FPu->Write();
   hdEE_TAC2_FPl->Write();
   hdEE_TAC3_FPb->Write();
   hdEE_TAC3_FPu->Write();
   hdEE_TAC3_FPl->Write();
   hdEE_TAC4_FPb->Write();
   hdEE_TAC4_FPu->Write();
   hdEE_TAC4_FPl->Write();
   hdEE_TAC5_FPb->Write();
   hdEE_TAC5_FPu->Write();
   hdEE_TAC5_FPl->Write();
   hdEE_TAC6_FPb->Write();
   hdEE_TAC6_FPu->Write();
   hdEE_TAC6_FPl->Write();

 hEFmax_EBmax->Write();
 hEF_EB->Write();
 hdEFmax_dEBmax->Write();
 hdEF_dEB->Write();
 hdEFmax_EFmax->Write();
 hdEBmax_EBmax->Write();
 hEFmaxvTh->Write();
 hdEFmaxvTh->Write();
 hEBmaxvTh->Write();
 hdEBmaxvTh->Write();
//-----------------------------------------------------------------------
   output->Close();
   fcuts->Close();
}
