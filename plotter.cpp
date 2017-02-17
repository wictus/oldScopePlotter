#include "plotter.h"

plotter::plotter(std::string filePath):
fFilePath(filePath)
{
  fCanvas = new TCanvas();
  readFile();
}

std::string plotter::changeFilePathPostFix(std::string postfix)
{
  return fFilePath.substr( 0, fFilePath.find_last_of( "." ) ) + postfix;
}

void plotter::savePNG()
{
  fCanvas->SaveAs( changeFilePathPostFix(".png").c_str() );
}

void plotter::saveROOT()
{
  fCanvas->SaveAs( changeFilePathPostFix(".root").c_str() );
}

void plotter::readFile()
{
  std::ifstream file;
  file.open(fFilePath.c_str());
  
  int linesToIgnore = 5;
  
  if( file.is_open() )
  {
    int linesRead = 0;
    std::string firstWord, secondWord;
    
    do 
    {
      std::getline(file, firstWord);
	linesRead++;
    }while (linesRead < linesToIgnore );
    
    while( std::getline( file, firstWord, ',' )  )
    {
      std::getline( file, secondWord);     
      fPoints.push_back( std::make_pair<double,double>( atof(firstWord.c_str()) , atof(secondWord.c_str()) ) );
    }
      
    file.close();
  }

}

