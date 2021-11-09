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
    
    DataErrors frequencies;
    cout << "Frequenze bin" << endl;
    for(int i=1; i<n_classi; i++){
        frequencies +=  PairDatumError(hist_data->GetBinContent(i), 0);
        cout << i << ": " << hist_data->GetBinContent(i) << endl;
    }
    cout << "Media: " << frequencies.mean() << endl;

    DataErrors pond_freq;
    double mean = frequencies.mean().d;
    for(PairDatumError pde : frequencies){
        pond_freq += pde / frequencies.mean().d;
    }

    cout << "Frequenze [normate]" << endl;
    cout << pond_freq << endl;

    cout << "Media [normata]: " << pond_freq.mean() << endl;
    cout << "Dev Std [normata]: " << pond_freq.sigma() << endl; 


    TH1D *dst = new TH1D("dst", "dst", 10000, 0.5, 1.5);
    for(PairDatumError pde : pond_freq)
       dst->Fill(pde.d); 

    cout << dst->GetStdDev() << endl;

    /* Range */
    hist_data->Scale(1./frequencies.mean().d);
    hist_data->GetYaxis()->SetRangeUser(0, 2);

    /* Disegna */
    gStyle->SetOptStat(10); 
    hist_data->Draw();

    /* TLine *l1 = new TLine(1, frequencies.mean().d, 15, frequencies.mean().d); */
    TLine *l1 = new TLine(1, pond_freq.mean().d, 15, pond_freq.mean().d);
    l1->SetLineColor(2);
    l1->SetLineStyle(7);
    l1->SetLineWidth(2);
    l1->Draw();
}

void plot_devstd(double *freq, double *devstd, const int size){

    TCanvas *canvas = new TCanvas("canvas data" , "canvas data", 0,0, 1920, 1080); 
    canvas->cd();

    canvas->SetGrid();

    TGraph *g = new TGraph(size, freq, devstd);
    g->SetTitle("Distribuzione dev std"); 
    g->GetXaxis()->SetTitle("Frequenza (kHz)"); 
    g->GetYaxis()->SetTitle("Dev Std"); 

    g->SetMarkerSize(0.8);
    g->SetMarkerStyle(21);
    g->SetMarkerColor(4);
 
    g->Draw("APL");
}

int hist_arduino(){
    /* Read data */
    DataErrors data("../data-source/9-11-21/R1_single.csv", 0, "");
    gen_hist(data);
    
/*     DataErrors freq("../data-source/9-11-21/freq_R.csv", 0, ""); */
    /* DataErrors devstd("../data-source/9-11-21/dev_std_R.csv", 0, ""); */
/*  */
    /* plot_devstd(freq.d_toptr(), devstd.d_toptr(), freq.size()); */

    return 0;
}
