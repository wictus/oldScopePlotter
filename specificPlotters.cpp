#include "specificPlotters.h"

chargePlotter::chargePlotter(std::string filePath): histoPlotter(filePath)
{
  delete histo;
  for(int i = 0; i < fPoints.size(); i++)
  {
    fPoints[i].first = fPoints[i].first / 50 *1E9;
  }
  
  double start, stop;
  int bins = fPoints.size();
  
  stop = fPoints[0].first;
  start = fPoints.end()->first;

  histo = new TH1F("histo","histo", bins, start,stop);
  fillHisto();
}


void chargePlotter::savePNG()
{
  histo->Draw();
  histo->GetXaxis()->SetTitle("Area [nC]");
  histo->GetYaxis()->SetTitle("Counts");
  fCanvas->SaveAs( changeFilePathPostFix(".png").c_str() );
  
}

void chargePlotter::saveROOT()
{
  histo->Draw();
  histo->GetXaxis()->SetTitle("Area [nC]");
  histo->GetYaxis()->SetTitle("Counts");
  fCanvas->SaveAs( changeFilePathPostFix(".root").c_str() );
  
}

