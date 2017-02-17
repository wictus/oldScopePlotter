#ifndef PLOTTER
#define PLOTTER

#include <string>
#include <iostream>
#include <fstream>
#include <utility>
#include <stdlib.h>
#include "TCanvas.h"



class plotter
{
public:
  plotter(std::string filePath);
  void savePNG();
  void saveROOT();
  
protected:
  std::vector<std::pair<double,double> > fPoints;
  std::string changeFilePathPostFix(std::string postfix);
  void readFile();
  std::string fFilePath;
  TCanvas* fCanvas;
  
};

#endif //PLOTTER