
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"


#include "ImageHandler.h"
#include "TemplateMatcher.h"
#include "Features.h"
#include "Osztalyozo.h"
#include "Tanito.h"

#include <chrono>
#include <iostream>
#include<sstream>
#include <algorithm> // for copy
#include <iterator> // for ostream_iterator

using namespace cv;
using namespace std;

void printVector(const vector<int>& vec);


int main( int argc, const char** argv )
{

    int width, height;
    width = 120;
    height = 120;

    /*
    Mat img1 = imread("bone_sample2.jpg");



    //Mat img2 = imread("fantomkep1.jpg");
    //Mat img2 = imread("virag.jpg");
    Mat img2 = imread("bone_sample4.jpg");
    Mat img3 = imread("einstein.jpg");

    ImageHandler::transformToBinaryImage(img1,img1,width, height);
    ImageHandler::transformToBinaryImage(img2,img2,width, height);
    ImageHandler::transformToBinaryImage(img3,img3,width, height);
    */
    /*
    namedWindow( "Display window1", WINDOW_AUTOSIZE );// Create a window for display.
    imshow( "Display window1", img1 );                   // Show our image inside it.

    namedWindow( "Display window2", WINDOW_AUTOSIZE );// Create a window for display.
    imshow( "Display window2", img2 );                   // Show our image inside it.
    waitKey(0);
    */

    vector<int> combined_FeatureVec;
    vector<int> result1;
    vector<int> result2;
    vector<int> imgFeatureVec;
    double dist1, dist2;

    Tanito t;
    Features feature;

    vector<Mat> pos_images;
    /*
    pos_images.push_back(img1);
    pos_images.push_back(img2);
    pos_images.push_back(img3);
    */
    /*
    t.tanit(pos_images, combined_FeatureVec);
    feature.calculateSplittedFeature(img2,4, imgFeatureVec);
    dist1 = oszt.distance(combined_FeatureVec, imgFeatureVec,0);

    vector<int> featureVec2;
    //feature.calculateSplittedFeature(img2,4, imgFeatureVec);
    feature.calculateSplittedFeature(img1,4, featureVec2);

    dist2 = oszt.distance(featureVec2, imgFeatureVec,0);

    cout<<"dist1: "<<dist1<<"   "<<"dist2: "<<dist2<<endl;

    for(int i=0;i<pos_images.size();i++){
        vector<int> featureVec3;
        feature.calculateSplittedFeature(pos_images[i],4, featureVec3);
        printVector(featureVec3);
        featureVec3.clear();
    }
    cout<<endl;
    printVector(combined_FeatureVec);
    */


  //  string pos_dirPath = "/media/szalnor/TANANYAGOK/KEPFELDOLGOZAS/BinaryImageReconstruction/bone_samples/bone_000.jpg";
  //  string test_images_dirPath = "/media/szalnor/TANANYAGOK/KEPFELDOLGOZAS/BinaryImageReconstruction/img_samples/img_000.jpg";

    string pos_dirPath = "/media/szalnor/TANANYAGOK/KEPFELDOLGOZAS/BinaryImageReconstruction/bone_samples/bone_";
    string test_images_dirPath = "/media/szalnor/TANANYAGOK/KEPFELDOLGOZAS/BinaryImageReconstruction/img_samples/img_";
    map<string,double> results;

    //Features feat;
    //feat.siftFeature(img1);

    Osztalyozo oszt;
    oszt.calculateSimilarity(pos_dirPath,test_images_dirPath, results);
    oszt.printResults(results);

    /*
    ImageHandler imgh;
    map<string,Mat> sample_images;
    //imgh.readMultipleImages(pos_images,posDir, 120, 120);

    imgh.readMultipleImages(sample_images,test_images_dirPath,120, 120);
    imgh.WriteImagesToFile("/media/szalnor/TANANYAGOK/KEPFELDOLGOZAS/BinaryImageReconstruction/img_samples/", sample_images);



    Mat oneDimImg;
    oneDimImg = imgh.convertImageToOneDim(img1);

    cout<<img1.size()<<endl;
    cout<<endl;
    cout<<oneDimImg.size()<<endl;
    */
    return 0;
}


void printVector(const vector<int>& vec){

for(int i=0;i<vec.size();i++){
    cout<<vec[i]<<" ";
}
cout<<endl;
}

