#define gatingplotter_c
#include <TH2.h>
#include <TH1.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TCutG.h>

void gatingplotter::Loop(){
  if (fChain ==0) return;
   TFile *output = new TFile("0mg_post119.root","recreate");
   TFile *fcuts = new TFile("/disks/1/gwilson/25Al/sorted/cuts_0_post.root","read");

   // define output histograms

   //ungated
   TH2F *hdEvE = new TH2F("hdEvE","dE_FmaxVE_Fmax, ungated, 0mg/cm2",7000,0,70,1400,0,14);
   TH2F *hepohepi = new TH2F("hepohepi","hepoVhepi, ungated, 0mg/cm2",4000,0,4000,4000,0,4000);
   TH2F *lepolepi = new TH2F("lepolepi","lepoVlepi, ungated, 0mg/cm2",4500,0,4500,4500,0,4500);
   TH2F *hxrftof = new TH2F("hxrftof","xVrftof, ungated, 0mg/cm2",3000,0,3000,700,0,700);
   TH2F *hesumlesum = new TH2F("hesumlesum","hepo+hepiVlepo+lepi, ungated, 0mg/cm2",9000,0,9000,9000,0,9000);
   TH2F *tacrftof = new TH2F("tacrftof","spareVrftof, ungated, 0mg/cm2",3000,0,3000,3000,0,3000);
   TH2F *cathx = new TH2F("cathx","cathodeVx, ungated, 0mg/cm2",7000,0,700,4500,0,4500);
   TH2F *hde0Vx = new TH2F("hde0Vx","de0Vx, ungated, 0mg/cm2",600,100,700,4000,0,4000);
   TH2F *hde1Vx = new TH2F("hde1Vx","de1Vx, ungated, 0mg/cm2",1000,0,1000,50,0,50);
   TH2F *hde2Vx = new TH2F("hde2Vx","de2Vx, ungated, 0mg/cm2",650,0,650,1000,0,1000);
   TH2F *hde3Vx = new TH2F("hde3Vx","de3Vx, ungated, 0mg/cm2",650,0,650,5000,0,5000);
   TH2F *hde4Vx = new TH2F("hde4Vx","de4Vx, ungated, 0mg/cm2",1000,0,1000,50,0,50);
   
   TH2F *hde4rf = new TH2F("hde4rf","de4Vrftof, ungated, 0mg/cm2",3000,0,3000,50,0,50);
   TH2F *hde3rf = new TH2F("hde3rf","de3Vrftof, ungated, 0mg/cm2",300,0,3000,500,0,5000);
   TH2F *hde2rf = new TH2F("hde2rf","de2Vrftof, ungated, 0mg/cm2",300,0,3000,500,0,1000);
   TH2F *hde1rf = new TH2F("hde1rf","de1Vrftof, ungated, 0mg/cm2",300,0,3000,500,0,5000);
   TH2F *hde0rf = new TH2F("hde0rf","de0Vrftof, ungated, 0mg/cm2",300,0,3000,500,0,5000);
   
   TH2F *hde1de2x = new TH2F("hde1de2","de1+de2Vx, ungated, 0mg/cm2",700,0,700,1000,0,1000);
   TH2F *hde1vde2 = new TH2F("hde1vde2","de1Vde2, ungated, 0mg/cm2",1000,0,1000,50,0,50);
   TH2F *hyvx = new TH2F("hyvx","yVx, ungated, 0mg/cm2",800,0,800,50,0,50);

 //gated
   TH2F *hdEvEg = new TH2F("hdEvEg","dE_FmaxVE_Fmax, gated, 0mg/cm2",7000,0,70,1400,0,14);
   TH2F *hepohepig = new TH2F("hepohepig","hepoVhepi, gated, 0mg/cm2",4000,0,4000,4000,0,4000);
   TH2F *lepolepig = new TH2F("lepolepig","lepoVlepi, gated, 0mg/cm2",4500,0,4500,4500,0,4500);
   TH2F *hxrftofg = new TH2F("hxrftofg","xVrftof, gated, 0mg/cm2",3000,0,3000,700,0,700);
   TH2F *hesumlesumg = new TH2F("hesumlesumg","hepo+hepiVlepo+lepi, gated, 0mg/cm2",9000,0,9000,9000,0,9000);
   TH2F *tacrftofg = new TH2F("tacrftofg","spareVrftof, gated, 0mg/cm2",3000,0,3000,3000,0,3000);
   TH2F *cathxg = new TH2F("cathxg","cathodeVx, gated, 0mg/cm2",7000,0,700,4500,0,4500);
   TH2F *hde0Vxg = new TH2F("hde0Vxg","de0Vx, gated, 0mg/cm2",600,100,700,4000,0,4000);
   TH2F *hde1Vxg = new TH2F("hde1Vxg","de1Vx, gated, 0mg/cm2",1000,0,1000,50,0,50);
   TH2F *hde2Vxg = new TH2F("hde2Vxg","de2Vx, gated, 0mg/cm2",650,0,650,1000,0,1000);
   TH2F *hde3Vxg = new TH2F("hde3Vxg","de3Vx, gated, 0mg/cm2",650,0,650,5000,0,5000);
   TH2F *hde4Vxg = new TH2F("hde4Vxg","de4Vx, gated, 0mg/cm2",1000,0,1000,50,0,50);
   
   TH2F *hde4rfg = new TH2F("hde4rfg","de4Vrftof, gated, 0mg/cm2",3000,0,3000,50,0,50);
   TH2F *hde3rfg = new TH2F("hde3rfg","de3Vrftof, gated, 0mg/cm2",300,0,3000,500,0,5000);
   TH2F *hde2rfg = new TH2F("hde2rfg","de2Vrftof, gated, 0mg/cm2",300,0,3000,500,0,1000);
   TH2F *hde1rfg = new TH2F("hde1rfg","de1Vrftof, gated, 0mg/cm2",300,0,3000,500,0,5000);
   TH2F *hde0rfg = new TH2F("hde0rfg","de0Vrftof, gated, 0mg/cm2",300,0,3000,500,0,5000);
   
   TH2F *hde1de2xg = new TH2F("hde1de2g","de1+de2Vx, gated, 0mg/cm2",700,0,700,1000,0,1000);
   TH2F *hde1vde2g = new TH2F("hde1vde2g","de1Vde2, gated, 0mg/cm2",1000,0,1000,50,0,50);
   TH2F *hyvxg = new TH2F("hyvxg","yVx, gated, 0mg/cm2",800,0,800,50,0,50);

   TH2D *hEFmax_EBmax = new TH2D("hEFmax_EBmax","Max front v Back, E",700,0,12,700,0,70);
   TH2D *hEF_EB = new TH2D("hEF_EB","front v Back, E",700,0,70,700,0,70);
   TH2D *hdEFmax_dEBmax = new TH2D("hdEFmax_dEBmax","Max front v Back, dE",700,0,70,700,0,70);
   TH2D *hdEF_dEB = new TH2D("hdEF_dEB","front v Back, dE",700,0,70,700,0,70);
   TH2D *hdEFmax_EFmax = new TH2D("hdEFmax_EFmax","Max front dE v E",700,0,70,700,0,70);
   TH2D *hdEBmax_EBmax = new TH2D("hdEBmax_EBmax","Max back dE v E",700,0,70,700,0,70);
   TH2D *hEFmaxvTh = new TH2D("hEFmaxvTh","Emax v Ring num, ungated, 0mg/cm2",700,0,70,16,0,16);
   TH2D *hdEFmaxvTh = new TH2D("hdEFmaxvTh","dEmax v Ring num, ungated, 0mg/cm2",200,0,20,16,0,16);
   TH2D *hEBmaxvTh = new TH2D("hEBmaxvTh","Emax v wedge num, ungated, 0mg/cm2",700,0,70,16,0,16);
   TH2D *hdEBmaxvTh = new TH2D("hdEBmaxvTh","dEmax v wedge num, ungated, 0mg/cm2",200,0,20,16,0,16);
   TH1D *hEFmax = new TH1D("hEFmax","E front max",700,0,70);
   TH1D *hEBmax = new TH1D("hEBmax","E back max",700,0,70);

   // Cuts
   //  TCutG *beamcut = (TCutG*)fcuts->Get("beam");
   // TCutG *uppercut = (TCutG*)fcuts->Get("upper");
   // TCutG *lowercut = (TCutG*)fcuts->Get("lower");
   // TCutG *dEEcut = (TCutG*)fcuts->Get("dE-Ecut");
   // TCutG *EvThcut = (TCutG*)fcuts->Get("EvTh");
   // TCutG *FB = (TCutG*)fcuts->Get("frontback");
   // TCutG *fpR = (TCutG*)fcuts->Get("rightdiag"); // that right diagonal bit... 
   // TCutG *fpL = (TCutG*)fcuts->Get("leftdiag"); // that right diagonal bit... 

----------------------------------------------------------------------- 
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
      // b_dE_Bmult->GetEntry(ientry);
      // b_dE_Bnum->GetEntry(ientry);
      // b_dE_Benergy->GetEntry(ientry);
      b_E_Bmult->GetEntry(ientry);
      b_E_Bnum->GetEntry(ientry);
      b_E_Benergy->GetEntry(ientry);
      b_rftof->GetEntry(ientry);
      b_spare->GetEntry(ientry);
      b_x->GetEntry(ientry);
       b_dE_Fmax->GetEntry(ientry);
       b_dE_Bmax->GetEntry(ientry);
      b_E_Fmax->GetEntry(ientry);
      b_E_Bmax->GetEntry(ientry);


      emaxF_E = emaxF_dE = emaxB_E = emaxB_dE = 0;
      nmaxF_E = nmaxF_dE = nmaxB_E = nmaxB_dE = -5;

       for (int i=0; i<dE_Fmult;i++){
           hdEvE->Fill(E_Fmax[i],dE_Fmax[i]);
           
       }
       hepohepi->Fill(hepo,hepi);
       lepolepi->Fill(lepo,lepi);
       hxrftof->Fill(x,rftof)
       hesumlesum->Fill((hepi+hepo),(lepi+lepo));
       tacrftof->Fill(spare,rftof);
       cathx->Fill(cathode,x)
       hde0Vx->Fill(de[0],x);
       hde1Vx->Fill(de[1],x);
       hde2Vx->Fill(de[2],x);
       hde3Vx->Fill(de[3],x);
       hde4Vx->Fill(de[4],x);

       hde4rf->Fill(de[4],rftof);
       hde3rf->Fill(de[3],rftof);
       hde2rf->Fill(de[2],rftof);
       hde1rf->Fill(de[1],rftof);
       hde0rf->Fill(de[4],rftof);
       
       hde1de2x->Fill(de[1]+de[2],x)
       hde1vde2->Fill(de[1],de[2])
       hyvx->Fill(x,y);

       
       
       output->cd();
       hdEvE->Write();
       hepohepi->Write();
       lepolepi->Write();
       hxrftof->Write();
       hesumlesum->Write();
       tacrftof->Write();
       cathx->Write();
       hde0Vx->Write();
       hde1Vx->Write();
       hde2Vx->Write();
       hde3Vx->Write();
       hde4Vx->Write();
       hde4rf->Write();
       hde3rf->Write();
       hde2rf->Write();
       hde1rf->Write();
       hde0rf->Write();
       hde1de2x->Write();
       hde1vde2->Write();
       hyvx->Write();

       output->close();
       
       return 0;
   }
