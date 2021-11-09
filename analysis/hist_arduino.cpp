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

    double min = data.min(), max=data.max();

    cout << "min = " << min << endl;
    cout << "max = " << max << endl;


    const double dispersione_max = max - min; 
    const double ampiezza_classe = 1;
    const int n_classi = ceil(dispersione_max / ampiezza_classe);

    const double dispersione_ist = n_classi * ampiezza_classe;
  
    cout << "Istogramma: data " << endl 
         << "\tN Classi = " << n_classi << endl 
         << "\tApprossimato da: " << dispersione_max << " / " << ampiezza_classe << " = " << dispersione_max/ampiezza_classe << endl
         << "\tDispersione istogramma = " << dispersione_ist << endl << endl;
         

    TCanvas *canvas = new TCanvas("canvas data" , "canvas data", 0,0, 1920, 1080); 
    canvas->cd(); 

    /* TH1F *hist_data = new TH1F("data","data", n_classi, min, max + 1);  */
    TH1F *hist_data = new TH1F("","data", n_classi-1, min+1, max);
   
    for(PairDatumError pde : data)
       hist_data->Fill(pde.d, 1); 
    
    /* Estetica grafico */
    hist_data->SetTitle(""); 
    hist_data->GetXaxis()->SetTitle("codice"); 
    hist_data->GetYaxis()->SetTitle("frequenza"); 
    
    /* Range */
    hist_data->GetYaxis()->SetRangeUser(0, 1000);

    DataErrors frequencies;
    cout << "Frequenze bin" << endl;
    for(int i=1; i<n_classi; i++){
        frequencies +=  PairDatumError(hist_data->GetBinContent(i), 0); 
        cout << i << ": " << hist_data->GetBinContent(i) << endl;
    }

    cout << "Media: " << frequencies.mean();
    TLine *l1 = new TLine(1, frequencies.mean().d, 15, frequencies.mean().d);

    /* Disegna */
    gStyle->SetOptStat(10); 
    hist_data->Draw();
    l1->Draw();
}

int hist_arduino(){
    /* Read data */
    DataErrors data("../data-source/4-11-21/800_Hz_clock", 0, "");
    gen_hist(data);

    return 0;
}
