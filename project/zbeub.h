#ifndef ZBEUB_H
#define ZBEUB_H

#include "aruco"
#include <array>
#include <fstream>
#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <string>
#include <stdexcept>

using namespace cv;
using namespace std;
using namespace aruco;

class Zbeub {
public:
  // Constructeurs
  Zbeub(int camIndex);
  Zbeub(int camIndex, string calibFile);

  //fonctions
  void init(); // init video stream and variables
  void setMarkerSize(float x);
  double detected()[4][]; // return marker detected as double: [(markerID, x, y, dist)]
  
private: 
  bool calibrated;
  string calibrationFile
  int camID, markerID;
  float markerSize;
  double x, y, dist;
};

#endif