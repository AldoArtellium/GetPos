#include "zbeub.h"
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

Zbeub::Zbeub(int camIndex){
	camID = camIndex;
	markerSize = -1;
}

Zbeub::Zbeub(int camIndex, string calibFile){
	camID = camIndex;
	calibrationFile = calibFile;
	markerSize = -1;
}

void Zbeub::init(){
	try{
		aruco::CameraParameters CamParam;
		cv::Mat InImage;
		VideoCapture vreader(camID); // a refaire totalement faux
		if (vreader.isOpened()) vreader >> InImage; // remplacer par flux video
		else throw std::runtime_error("Could not open input");

		CamParam.readFromXMLFile(calibrationFile);

		float MarkerSize = std::stof(markerSize);


		MarkerDetector MDetector;
		if (calibrationFile) {
			MDetector.loadParamsFromFile(calibrationFile);
		}

	}catch ( const std::exception& e){
		cout << e.what() << endl;
	}
}

double Zbeub::detected()[4][]{
	try{
		double detection[4][];
		vector<Marker> Markers = MDetector.detect(InImage, CamParam, markerSize);
		for (unsigned int i = 0; i < Markers.size(); i++)
		{
			// detection += [Markers[i].];
			cout << Markers[i] << endl;
		}
		return detection;
	}catch ( const std::exception& e){
		cout << e.what() << endl;
	}
}
