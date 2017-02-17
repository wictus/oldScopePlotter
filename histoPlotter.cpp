#include "histoPlotter.h"

histoPlotter::histoPlotter(std::string filePath):
plotter(filePath)
{
  double start, stop;
  int bins = fPoints.size();
  
  stop = fPoints[0].first;
  start = fPoints.end()->first;

  histo = new TH1F("histo","histo", bins, start,stop);
  fillHisto();
 
}

void histoPlotter::fillHisto()
{
  for(unsigned int i = 0; i < fPoints.size(); i++ )
  {
      histo->Fill(fPoints[i].first, fPoints[i].second);
  }
}

void histoPlotter::savePNG()
{
  histo->Draw();
  fCanvas->SaveAs( changeFilePathPostFix(".png").c_str() );
}

void histoPlotter::saveROOT()
{
  histo->Draw();
  fCanvas->SaveAs( changeFilePathPostFix(".root").c_str() );
}
