#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include "histoPlotter.h"
#include "plotter.h"
#include "specificPlotters.h"

void checkArgsNumber(int argNumber);
void checkFileType(std::string fileType);
void checkFilePath(std::string filePath);

int main(int argc, char **argv) {


  checkArgsNumber(argc);
  checkFileType(argv[2]);
  checkFilePath(argv[1]);
  
  /*
   * Some if which will decide if this is a signal of histo plotter
   */
  chargePlotter test( argv[1] );
  test.savePNG();
  test.saveROOT();
  
  return 0;
}

void checkArgsNumber(int argNumber)
{
  if( 3 != argNumber )
  {
      std::cout << "Please provide path to data file and its type" << std::endl;
      std::cout << "Accepted file types are: charge " << std::endl;
      std::exit(1);
  }
}

void checkFileType(std::string fileType)
{
  std::map<std::string, int> fileTypes;
  fileTypes["unknown"]=0;
  fileTypes["amplitude"]=1;
  fileTypes["charge"]=2;
  fileTypes["riseTime"]=3;
  fileTypes["fallTime"]=4;
  fileTypes["timeDifference"]=5;
  fileTypes["signal"]=6;
  std::map<std::string,int>::iterator it = fileTypes.find(fileType); 
  if( fileTypes.end() == it )
  {
      std::cout << "Not known type of file"<<std::endl;
      std::cout << "Accepted file types are: charge " << std::endl;
      std::exit(2);
  }
}

void checkFilePath(std::string filePath)
{
  std::ifstream f(filePath.c_str());
  if( !f.good() )
  {
     std::cout << "Wrong path to file " << filePath << std::endl;
     std::exit(3);
  }
}
