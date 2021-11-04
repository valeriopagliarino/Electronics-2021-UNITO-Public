#include <TGraphErrors.h>     
#include <TAxis.h>           
#include <TCanvas.h>         
#include <TF1.h>             
#include <TH1.h>             
#include <TStyle.h>
#include <TFitResultPtr.h>

#include <cmath>
#include <iomanip>
#include <array>
#include<iostream>
#include<string>
#include<fstream>

#include<sugodata.hpp>

using namespace std;

void gen_hist(DataErrors &data){
   /* Sort Data to make hist */
    data.sort();
    
    cout << "min = " << data[0] << endl;
    cout << "max = " << data[-1] << endl;


    const double dispersione_max = data[-1].d - data[0].d;
    const double ampiezza_classe = 1 * 3;  /* 3 volte dato */
    const int n_classi = ceil(dispersione_max / ampiezza_classe);

    const double dispersione_ist = n_classi * ampiezza_classe;
  
/*     static int color = 2; */
    /* cout << "\033[1;3" + to_string(color++) + "m";  */
    cout << "Istogramma: data " << endl 
         << "\tN Classi = " << n_classi << endl 
         << "\tApprossimato da: " << dispersione_max << " / " << ampiezza_classe << " = " << dispersione_max/ampiezza_classe << endl
         << "\tDispersione istogramma = " << dispersione_ist << endl << endl;
         

    TCanvas *canvas = new TCanvas("canvas data" , "canvas data", 0,0, 1920, 1080); 
    canvas->cd(); 

    TH1F *hist_data = new TH1F("data","data", n_classi, data[0].d, data[-1].d); 
   
    for(PairDatumError pde : data)
       hist_data->Fill(pde.d, 1); 
    
    /* definisco la funzione di fit g1 come gaussiana: 
     * [0]=normalizzazione
     * [1]=media
     * [2]=sigma
     */
    /* TF1 *gauss = new TF1(("gauss #data_" + name).c_str() , "gaus");  */
    /* hist_data->Fit(("gauss #theta_" + name).c_str(), "L"); */
    /* gStyle->SetOptFit(1); */
    /*  */
/*     */
   
    /* Estetica grafico */
    hist_data->SetTitle("data" ); 
    hist_data->GetXaxis()->SetTitle("data"); 
    hist_data->GetYaxis()->SetTitle("Ampiezza"); 
    
    /* Range */
/*     hist_data->GetXaxis()->SetRangeUser(6.22, 6.60);  */
    /* hist_data->GetYaxis()->SetRangeUser(0,110);   */
/*      */

    /* Disegna */
    hist_data->Draw(); 

    /* PairDatumError mean (gauss->GetParameter(1), gauss->GetParError(1), "deg"); */
    /* return mean; */
}

int hist_arduino(){
    /* Read data */
    DataErrors data("../data-source/4-11-21/data.csv", 0, "");
    
    gen_hist(data);

    return 0;
}
