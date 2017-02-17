#ifndef SPECIFICPLOTTERS
#define SPECIFICPLOTTERS

#include "plotter.h"
#include "histoPlotter.h"

class chargePlotter: public histoPlotter
{
public:
chargePlotter(std::string filePath);
  void savePNG();
  void saveROOT();
};

#endif // SPECIFICPLOTTERS