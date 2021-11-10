#include <TGraphErrors.h>     
#include <TAxis.h>           
#include <TCanvas.h>         
#include <TF1.h>             
#include <TH1.h>             
#include <TStyle.h>
#include <TFitResultPtr.h>
#include <TLine.h>

#include <cmath>
#include <iomanip>
#include <array>
#include<iostream>
#include<string>
#include<fstream>

#include<sugodata.hpp>



using namespace std;

void gen_hist(DataErrors &data, int frequency){
   /* Sort Data to make hist */
    double min = data.min(), max=data.max();

    
    const double dispersione_max = max - min; 
    const double ampiezza_classe = 1;
    const int n_classi = ceil(dispersione_max / ampiezza_classe);

    const double dispersione_ist = n_classi * ampiezza_classe;
  
    cout << "\033[1;33m";
    cout << "Istogramma: data " << endl 
        << "\tmin = " << min << endl
        << "\tmax = " << max << endl
        << "\tN Classi = " << n_classi << endl 
        << "\tApprossimato da: " << dispersione_max << " / " << ampiezza_classe << " = " << dispersione_max/ampiezza_classe << endl
        << "\tDispersione istogramma = " << dispersione_ist << endl << endl;
    cout << "\033[0;m";
         

    TCanvas *canvas = new TCanvas("canvas data" , "canvas data", 0,0, 1920, 1080); 
    canvas->cd(); 

    /* TH1F *hist_data = new TH1F("data","data", n_classi, min, max + 1);  */
    TH1F *hist_data = new TH1F("","data", n_classi-1, min+1, max);
   
    for(PairDatumError pde : data)
       hist_data->Fill(pde.d, 1); 
    
    /* Estetica grafico */
    hist_data->SetTitle(("Frequenza di clock " + to_string(frequency) + " Hz").c_str()); 
    hist_data->GetXaxis()->SetTitle("codice"); 
    hist_data->GetYaxis()->SetTitle("frequenza codice"); 
    
    DataErrors frequencies;
    cout << endl << "Frequenze bin" << endl;
    for(int i=1; i<n_classi; i++){
        frequencies +=  PairDatumError(hist_data->GetBinContent(i), 0);
        cout << i << ": " << hist_data->GetBinContent(i) << endl;
    }

    cout << "\033[1;32m";
    cout << "Media: " << frequencies.mean() << endl;
    cout << "Dev Std: " << frequencies.sigma() << endl;
    cout << "\033[0;m";

    DataErrors pond_freq;
    double mean = frequencies.mean().d;
    for(PairDatumError pde : frequencies){
        pond_freq += pde / frequencies.mean().d;
    }

    cout << endl << "Frequenze [normate]" << endl;
    cout << pond_freq << endl;

    cout << "\033[1;34m";
    cout << "Media [normata]: " << pond_freq.mean() << endl;
    cout << "Dev Std [normata]: " << pond_freq.sigma() << endl; 
    cout << "\033[0;m";

    /* Range */
    hist_data->Scale(1./frequencies.mean().d);
    hist_data->GetYaxis()->SetRangeUser(0, 1.6);

    /* Disegna */
    gStyle->SetOptStat(10); 
    hist_data->Draw();

    /* Line */
    TLine *line = new TLine(1, pond_freq.mean().d, 15, pond_freq.mean().d);
    line->SetLineColor(2);
    line->SetLineStyle(7);
    line->SetLineWidth(2);
    line->Draw();
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

    g->SetLineColor(1);
 
    g->GetYaxis()->SetRangeUser(0, 0.18);

    g->Draw("APL");
}

int hist_arduino(int name=0){
    DataErrors freq("../data-source/9-11-21/freq_G.csv", 0, "");
    DataErrors devstd("../data-source/9-11-21/dev_std_G.csv", 0, "");
   
    if(name < 1 || name > 9){
        plot_devstd(freq.d_toptr(), devstd.d_toptr(), freq.size());
        return 0;
    }

    /* Read data */
    string fname = "../data-source/9-11-21/G" + to_string(name) + "_single.csv";
    DataErrors data(fname, 0, "");
    gen_hist(data, int(freq[name-1].d * 1000));

    return 0;
}
