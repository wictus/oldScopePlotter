#ifndef HISTOPLOTTER
#define HISTOPLOTTER


#include <string>
#include "TH1F.h"
#include "plotter.h"


class histoPlotter: public plotter
{
public:
  histoPlotter(std::string filePath);
  void savePNG();
  void saveROOT();
protected:
  void fillHisto();
  TH1F* histo;
  
};

#endif //HISTOPLOTTER