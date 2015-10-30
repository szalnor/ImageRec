#include "mainwindow.h"
#include <QApplication>

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"


#include "ImageHandler.h"
#include "TemplateMatcher.h"
#include "Feature.h"
#include "SplittedFeature.h"

#include "Osztalyozo.h"
#include "Trainer.h"
#include "AverageFeatureTrainer.h"
#include "ProjectionHandler.h"
#include "OptimizerDatas.h"
#include "SimannOptimizer.h"

#include <chrono>
#include <iostream>
#include <sstream>
#include <algorithm> // for copy
#include <iterator> // for ostream_iterator
#include "Timer.h"

#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <gsl/gsl_siman.h>
#include <gsl/gsl_machine.h>
#include <gsl/gsl_rng.h>
#include "VectorHelper.h"

using namespace cv;
using namespace std;
using namespace vectorHelper;

void printVector(const vector<int>& vec);

template<typename status, typename count, typename energy_function, typename temperature_function, typename next_function, typename generator>
status simulated_annealing(status i_old, count c, const energy_function& ef, const temperature_function& tf, const next_function& nf, generator& g);


auto ef = [](long double x){
    //return std::abs( (x - 10)*(x + 20)*(x - 30) );
    return exp(-pow((x-1.0),2.0))*sin(8*x);
    //return (x-5)*(x-5);
};

auto tf = [](long double k){
    return std::exp( -20 * k );
};

template<typename generator>
long double nf(long double x, generator& g){
    std::normal_distribution<decltype(x)> d(0, 1);
    return x + d(g);
}








int main( int argc, char* argv[] )
{
    /*
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    */


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

    //Tanito t;
    //Feature feature;


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
    map<string,Mat> pos_images;
    map<string,Mat> test_images;
    //Features feat;
    //feat.siftFeature(img1);


    ImageHandler::readMultipleImages(pos_dirPath, pos_images, 120, 120);
    //ImageHandler::readMultipleImages(imgDir, test_images, 120, 120);

    /*
    imgh.WriteImagesToFile("/media/szalnor/TANANYAGOK/KEPFELDOLGOZAS/BinaryImageReconstruction/img_samples/", test_images);
    imgh.WriteImagesToFile("/media/szalnor/TANANYAGOK/KEPFELDOLGOZAS/BinaryImageReconstruction/bone_samples/", pos_images);
    Osztalyozo oszt;
    oszt.calculateSimilarity(pos_images,test_images, results);
    oszt.printResults(results);
    */

    string dir = "/media/szalnor/TANANYAGOK/KEPFELDOLGOZAS/BinaryImageReconstruction/bone_samples/";
    string str = dir + "BONE_001.jpg";
    Mat bone_sample = imread("bone_005.jpg");
    ImageHandler::transformToBinaryImage(bone_sample,bone_sample,120,120);
    //cout<<bone_sample.channels()<<" "<<bone_sample.type()<<endl;
    Mat bone_sample1 = bone_sample*255;
    imwrite("source.jpg",bone_sample1);
    ProjectionHandler projHandler(bone_sample);


    /*
    projHandler.generateProjections(2,2);
    cout<<"idxs: "<<projHandler.getHorizontalProjectionIdxs()<<"    "<<projHandler.getVerticalProjectionIdxs()<<endl;
    cout<<"values: "<<projHandler.getHorizontalProjectionValues()<<"    "<<projHandler.getVerticalProjectionValues()<<endl;
    */

    projHandler.generateProjections(10,10);
    cout<<"idxs: "<<projHandler.getHorizontalProjectionIdxs()<<"    "<<projHandler.getVerticalProjectionIdxs()<<endl;
    cout<<"values: "<<projHandler.getHorizontalProjectionValues()<<"    "<<projHandler.getVerticalProjectionValues()<<endl;

    Mat initial_image = Mat::zeros( 120, 120, CV_8U);
    int splitNum = 4;
    SplittedFeature feature(splitNum);
    AverageFeatureTrainer trainer(feature,pos_images);
    trainer.train();
    cout<<"trained feature vector: " << trainer.getTrainedFeatureVector()<<endl;

    vector<double> lambdas = {1.0,1.0,1.0};
    OptimizerDatas* optDatas = new OptimizerDatas(trainer,projHandler,initial_image,lambdas);

    SimannOptimizer::optimizerDatas = optDatas;
    int a = SimannOptimizer::simannSolver();
    std::cout<<a<<std::endl;

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
    //return a.exec();
    /*
    std::random_device rd;
    std::mt19937_64 g(rd());
    //Timer<std::chrono::high_resolution_clock> t;
    Timer<std::chrono::system_clock> t;
    long double root   = std::atof(argv[1]);
    std::size_t count  = std::atoi(argv[2]);
    //Optimization optimizer;
    t.start();
    root = simulated_annealing(root, count, ef, tf, nf<decltype(g)>, g);
    t.finish();

    std::cout << "Result: " << root << std::endl;
    std::cout << "Time elapaed: " << t.count<double>() << '\n';
    */


    //Optimizer opt;
    //opt.simannSolver();

    double x,y=14.0;
    //(void)y;
    //Optimizer E1((void*)&y);




    return 0;
}


void printVector(const vector<int>& vec){

for(unsigned int i=0;i<vec.size();i++){
    cout<<vec[i]<<" ";
}
cout<<endl;
}

template<typename status, typename count, typename energy_function, typename temperature_function, typename next_function, typename generator>
status simulated_annealing(status i_old, count c, const energy_function& ef, const temperature_function& tf, const next_function& nf, generator& g){

    auto   e_old  = ef(i_old);

    status i_best = i_old;
    auto   e_best = e_old;

    std::uniform_real_distribution<decltype(e_old)> rf(0, 1);

    for(; c > 0; --c){
        status i_new = nf(i_old, g);
        auto   e_new = ef(i_new);

        if(e_new < e_best){
            i_best =           i_new ;
            e_best =           e_new ;
        }

        if( e_new < e_old || std::exp( (e_old - e_new) / tf(c) ) > rf(g) ){
            i_old  = std::move(i_new);
            e_old  = std::move(e_new);
        }
    }
    std::cout<< i_best << " " <<e_best <<endl;
    return(i_best);
}
