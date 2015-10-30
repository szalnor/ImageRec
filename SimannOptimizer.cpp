#include "SimannOptimizer.h"



#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <exception>
#include <iostream>
#include "ProjectionHandler.h"
#include "Feature.h"
#include "Osztalyozo.h"
#include "VectorHelper.h"

//#include <functional>   // std::plus

using namespace cv;
using namespace vectorHelper;
/* set up parameters for this simulated annealing run */

/* how many points do we try before stepping */
//#define N_TRIES 20
#define N_TRIES 50
/* how many iterations for each T? */
#define ITERS_FIXED_T 200

/* max step size in random walk */
//#define STEP_SIZE 1.0
#define STEP_SIZE 1.0

/* Boltzmann constant */
#define K 1.0

/* initial temperature */
#define T_INITIAL 0.008
//#define T_INITIAL 1.05

/* damping factor for temperature */
//#define MU_T 1.003
#define MU_T 1.003
//#define T_MIN 2.0e-6
#define T_MIN 2.0e-4

gsl_siman_params_t params
= {N_TRIES, ITERS_FIXED_T, STEP_SIZE,
   K, T_INITIAL, MU_T, T_MIN};








/*
SimannOptimizer::~SimannOptimizer()
{
    delete projHandler;
    delete trainer;
    //dtor
}
*/
OptimizerDatas* SimannOptimizer::optimizerDatas;

/*
Trainer* trainer = SimannOptimizer::optimizerDatas->getTrainer();
ProjectionHandler* projHandler = SimannOptimizer::optimizerDatas->getProjHandler();
vector<double> lambdas = SimannOptimizer::optimizerDatas->getLambdas();
Mat initial_image = SimannOptimizer::optimizerDatas->getInitial_image();
*/


void SimannOptimizer::copyFunc(void* source, void* dest)
{
     (*(Mat *) dest) = (* ((Mat *) source)).clone() ;
}

void *SimannOptimizer::copyConstructor(void *xp)
{
    Mat x = *((Mat*) xp);
    Mat* y = new Mat(x.rows,x.cols, x.type());

    *y = x.clone();
    return (void*) y;

}

void SimannOptimizer::destroy(void *xp)
{
    ((Mat*) xp)->release();
    //delete ((Mat*) xp);
}



double SimannOptimizer::energyFunction(void *xp){

    Mat x = * ((Mat *) xp);
    vector<int> newHorProjVals;
    vector<int> newVertProjVals;

    vector<int> horProjVals = SimannOptimizer::optimizerDatas->getProjHandler()->getHorizontalProjectionValues();
    vector<int> vertProjVals = SimannOptimizer::optimizerDatas->getProjHandler()->getVerticalProjectionValues();

    double horProjDist = 0.0;
    double vertProjDist = 0.0;
    double featureDist = 0.0;

    vector<int> horProjIdxs = SimannOptimizer::optimizerDatas->getProjHandler()->getHorizontalProjectionIdxs();
    vector<int> vertProjIdxs = SimannOptimizer::optimizerDatas->getProjHandler()->getVerticalProjectionIdxs();

    SimannOptimizer::optimizerDatas->getProjHandler()->generateHorizontalProjValues(x,horProjIdxs,newHorProjVals);
    SimannOptimizer::optimizerDatas->getProjHandler()->generateVerticalProjValues(x,vertProjIdxs,newVertProjVals);

    //transform(newHorProjVals.begin(),newHorProjVals.end(), horProjVals.begin(),horRes.begin(),std::minus<int>());
    //transform(newVertProjVals.begin(),newVertProjVals.end(), vertProjVals.begin(),vertRes.begin(),std::minus<int>());

    horProjDist = vectorDistance<int>(newHorProjVals,horProjVals);
    vertProjDist = vectorDistance<int>(newVertProjVals,vertProjVals);


    double energy=0.0;
    //Feature feat = new SplittedFeature(4);
    vector<double> newFeatureVec;
    SimannOptimizer::optimizerDatas->getTrainer()->getFeature().generateFeatureVector(x,newFeatureVec);

    vector<double> trainedFeatureVector = SimannOptimizer::optimizerDatas->getTrainer()->getTrainedFeatureVector();

    featureDist = vectorHelper::vectorDistance<double>(newFeatureVec,trainedFeatureVector);
    vector<double> lambdas = SimannOptimizer::optimizerDatas->getLambdas();

    energy = lambdas[0] * std::pow(horProjDist,2) + lambdas[1] * std::pow(vertProjDist,2) +
           lambdas[2] * std::pow(featureDist,2);

    cout<<"old: "<<horProjIdxs<<" "<<horProjVals<<endl;
    cout<<"old: "<<vertProjIdxs<<" "<<vertProjVals<<endl;
    cout<<"new: "<<horProjIdxs<<" "<<newHorProjVals<<endl;
    cout<<"new: "<<vertProjIdxs<<" "<<newVertProjVals<<endl;
    cout<<"trained_feature: "<<trainedFeatureVector<<endl;
    cout<<"new_feature: "<<newFeatureVec<<endl;
    cout<<endl;

    return energy;

}



double SimannOptimizer::metric(void *xp, void *yp)
{
    Mat x = *((Mat *) xp);
    Mat y = *((Mat *) yp);
    return norm(x,y,NORM_L1);
}

/*
void S1(const gsl_rng * r, void *xp, double step_size)
{
    double old_x = *((double *) xp);
    double new_x;

    double u = gsl_rng_uniform(r);
    new_x = u * 2 * step_size - step_size + old_x;
    memcpy(xp, &new_x, sizeof(new_x));
}
*/

void SimannOptimizer::changeImagePixelValue(Mat& img, int row, int col){


    if(img.at<uchar>(row,col) == 1){
        img.at<uchar>(row,col) = 0;
    }

    if(img.at<uchar>(row,col) == 0){
        img.at<uchar>(row,col) = 1;
    }
    else
        throw invalid_argument("The image given is not binary image!");


}


void SimannOptimizer::generateNeighbourState(const gsl_rng * r, void *xp, double step_size){

    Mat old_x = *((Mat *) xp);
    Mat* new_x = new Mat(old_x.rows,old_x.cols,old_x.type());
    *new_x = old_x.clone();
    //Mat new_x = old_x.clone();

    double rowIdx,colIdx;


    try{
        for(int i=0;i<floor(step_size);i++){
            rowIdx = floor((*new_x).rows*gsl_rng_uniform(r));
            colIdx = floor((*new_x).cols*gsl_rng_uniform(r));

            SimannOptimizer::changeImagePixelValue(*new_x,rowIdx,colIdx);
        }
    }catch(const exception& e){
        std::cerr << e.what();
    }

    memcpy(xp, new_x, sizeof(*new_x));

}





void SimannOptimizer::P1(void *xp)
{
    //printf ("%12g", *((double *) xp));
    Mat img = *((Mat *) xp);
    Mat img1 = img*255;
    imwrite("result.jpg",img1);
    //cout<<sum(img)[0];
    double summa = sum(img)[0];
    printf("%12g", summa );

    //namedWindow( "Display window", WINDOW_AUTOSIZE );// Create a window for display.
    //imshow( "Display window", img );
}


double SimannOptimizer::simannSolver(){


    const gsl_rng_type * T;
    gsl_rng * r;

    //double x_initial = 15.5;
    //Mat img_initial = imread("init_img.jpg");
    //Mat img_initial = Mat::zeros( 120, 120, CV_8UC3 );


    //foo = &Optimizer::energyFunction;

    gsl_rng_env_setup();

    T = gsl_rng_default;
    r = gsl_rng_alloc(T);
    /*
    gsl_siman_solve(r, &x_initial, E1, S1, M1, P1,
                    NULL, NULL, NULL,
                    sizeof(double), params);
    */
    Mat initial_image = SimannOptimizer::optimizerDatas->getInitial_image();
    gsl_siman_solve(r, &initial_image, energyFunction, generateNeighbourState, metric, P1,
                    copyFunc, copyConstructor, destroy,
                    sizeof(Mat(120,120,CV_8U)), params);

    gsl_rng_free (r);

    return 1.0;
}

/*
OptimizerDatas *SimannOptimizer::getOptimizerDatas()
{
    return optDatas;
}
*/





