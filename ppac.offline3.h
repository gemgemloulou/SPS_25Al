// Program: PPAC.h
// Class: PPAC
//        Created  by Xiaodong Tang,   July 2006
//        Modified by Masahiro Notani, Aug. 2006 (146Sm M.Paul's exp)
//        Modified by HY Lee Feb. 2008
// Purpose:
//        PPAC Data Analysis
//
// Input  values: hepo,hepi,
//                lepo,lepi
// Input  params: hecent,scalehe,ocalhe,
//                lecent,scalele,ocalle     (Read from "ppac.setup")
// Output params: pospp
// Internal params: hesum,he, poshe (flag)
//                  lesum,le, posle (flag)

// Header files
#include "math.h"
#include "fstream"
#include "iostream"
#include "string"

using namespace std;

class PPAC {
 public:
  //  PPAC() {};
  PPAC(float Hecent, float Scalehe, float Ocalhe, float Lecent, float Scalele, float Ocalle, float Udcent) {
    hecent = Hecent;
    scalehe = Scalehe;
    ocalhe = Ocalhe;
    lecent = Lecent;
    scalele = Scalele;
    ocalle = Ocalle;
    udcent = Udcent;
  };
  PPAC(char *ppac_config_file) { 
    ifstream fin(ppac_config_file);
    if( !( fin.is_open() ) ) {
      cout<<"ppac.config does not exist. please make one."<<endl;
      cout<<"hecent 1000\nscalehe 1.0\nocalhe 1000\nlecent 1000\nscalele 1.0\nocalle 1000"<<endl;
    }
    string tempstr;
    fin>>tempstr>>hecent;
    cout<<tempstr<<" : "<<hecent<<endl;
    fin>>tempstr>>scalehe;
    cout<<tempstr<<" : "<<scalehe<<endl;
    fin>>tempstr>>ocalhe;
    cout<<tempstr<<" : "<<ocalhe<<endl;
    fin>>tempstr>>lecent;
    cout<<tempstr<<" : "<<lecent<<endl;
    fin>>tempstr>>scalele;
    cout<<tempstr<<" : "<<scalele<<endl;
    fin>>tempstr>>ocalle;
    cout<<tempstr<<" : "<<ocalle<<endl;
    fin>>tempstr>>udcent;
    cout<<tempstr<<" : "<<udcent<<endl;
  };

  float GetPosition(float Hepo, float Hepi, float Lepo, float Lepi, float Up, float Down) {
    lepo=Lepo;
    lepi=Lepi;
    hepo=Hepo;
    hepi=Hepi;
    up=Up;
    down=Down;
    Bool_t good_he=kFALSE, good_le=kFALSE, single_hepo=kFALSE, single_hepi=kFALSE;    
    Bool_t poshe=kFALSE, posle=kFALSE, single_lepo=kFALSE, single_lepi=kFALSE;
    Bool_t single_up=kFALSE, single_down=kFALSE;

    // Gate conditon has changed 100< XX <4000 to 50<= XX <=4094, 4095=over
    /*    if(  ( hepo>=50 && hepo<=4000 ) // Changed fact 0.75 to 0.25
       || ( hepi>=50 && hepi<=4000 ) ) {
      poshe = kTRUE;
    }
    if(  ( lepo>=50 && lepo<=4000 )
      || ( lepi>=50 && lepi<=4000 ) ) {
      posle = kTRUE;
      }*/
    if(hepo>=50 && hepo<=4000) single_hepo=kTRUE;
    if(hepi>=50 && hepi<=4000) single_hepi=kTRUE;
    if(lepo>=50 && lepo<=4000) single_lepo=kTRUE;
    if(lepi>=50 && lepi<=4000) single_lepi=kTRUE;
    if(up>=50   && up<=4000)   single_up=kTRUE;
    if(down>=50 && down<=4000) single_down=kTRUE;

    le=0.0, he=0.0, pospp=0.0, ud=0.0, uu=0.0, dd=0.0;
    if(single_hepo){
      if(single_hepi){
         he = 0.25*(hepo-hepi) + 2048;
         hesum = 0.25*(hepo + hepi);
         pospp = scalehe*he + ocalhe;
      }
      else{
         he = 0.5*hepo - hecent + 2048.;
         pospp = scalehe*he + ocalhe;
      }
    }
    else if(single_hepi) {
      he = hecent - 0.5*hepi + 2048.;
      pospp = scalehe*he + ocalhe;
    }

    if(single_lepo){
      if(single_lepi){
         le = 0.25*(lepo-lepi) + 2048;
         lesum = 0.25*(lepo + lepi);
         pospp = scalele*le + ocalle;
      }
      else{
         le = 0.5*lepo - lecent + 2048.;
         pospp = scalele*le + ocalle;
      }
    }
    else if(single_lepi) {
      le = lecent - 0.5*lepi + 2048.;
      pospp = scalele*le + ocalle;
    }
 
    if(single_up){
      if(single_down){
        ud = 0.5*(up-down) + 2048;
      }
      else{uu = up - udcent + 2048; ud=uu;}
    }
    else if(single_down){
      dd = udcent - down + 2048; ud=dd;
    }
   /*   he = 0;
    if(  ( hepo>=50 && hepo<=4000 ) // Changed fact 0.75 to 0.25, 1024 to 2048
      && ( hepi>=50 && hepi<=4000 ) ) {
      he = 0.25*(hepi-hepo) + 2048;
      hesum = 0.25*(hepo + hepi);
      pospp = scalehe*he + ocalhe;
      good_he=kTRUE;
    }
    le = 0;
    if(  ( lepo>=50 && lepo<=4000 )
      && ( lepi>=50 && lepi<=4000 ) ) {
      le = 0.25*(lepo-lepi) + 2048;
      lesum = 0.25*(lepo + lepi);
      pospp = scalele*le + ocalle;
      good_le=kTRUE;
      } // Changed fact 1.5 to 0.5, 1024 to 2048 
    if(poshe) {
      if( hepi<50 || hepi>4056 )
        he = hecent - 0.5*hepo + 2048.;
      if( hepo<50 || hepo>4056 )
        he = 0.5*hepi - hecent + 2048.;
        pospp = scalehe*he + ocalhe;
    }
    if(posle) {
      if( lepo<50 || lepo>4056 )
        le = lecent - 0.5*lepi + 2048.;
      if( lepi<50 || lepi>4056 )
        le = 0.5*lepo - lecent + 2048.;
        pospp = scalele*le + ocalle;
	}*/

    //    cout<<"poshe="<<poshe<<" posle="<<posle<<endl;
    return pospp;
  };


  float pospp, ud;
  float hesum, lesum;
  float he, le, uu, dd;
  Bool_t single_hepo, single_hepi, single_lepo, single_lepi, single_up, single_down;

 private:
  float lepo, lepi, hepo, hepi, up, down;
  float hecent, scalehe, ocalhe;
  float lecent, scalele, ocalle, udcent;
  int poshe, posle;
};
