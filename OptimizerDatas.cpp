#include "OptimizerDatas.h"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <exception>
#include <iostream>
#include "ProjectionHandler.h"
#include "Feature.h"
#include "Osztalyozo.h"
#include "VectorHelper.h"

#include <functional>   // std::plus

using namespace cv;



OptimizerDatas::OptimizerDatas(Trainer &trainer, ProjectionHandler &projHandler, const Mat initial_img, const vector<double> lambdas)
    : trainer(&trainer), projHandler(&projHandler), initial_image(initial_img), lambdas(lambdas)
{

}
ProjectionHandler *OptimizerDatas::getProjHandler() const
{
    return projHandler;
}
Trainer *OptimizerDatas::getTrainer() const
{
    return trainer;
}
Mat OptimizerDatas::getInitial_image() const
{
    return initial_image;
}
vector<double> OptimizerDatas::getLambdas() const
{
    return lambdas;
}





/*
extern ProjectionHandler* projHandler;
extern Trainer* trainer;
extern vector<double> lambdas;
extern Mat initial_image;
extern const vector<double> getLambdas();
extern double simannSolver();
*/
/*
void Optimizer::setParameters(Trainer &trainer, ProjectionHandler &projHandler, const Mat initial_img,  const vector<double> lambdas)
{
    Optimizer::initial_image = initial_img;
    Optimizer::trainer  = &trainer;
    Optimizer::projHandler = &projHandler;
    Optimizer::lambdas = lambdas;

}
*/



/*
vector<int> Optimizer::horizontalProjectionIdxs;
vector<int> Optimizer::horizontalProjectionValues;
vector<int> Optimizer::verticalProjectionIdxs;
vector<int> Optimizer::verticalProjectionValues;

vector<double> Optimizer::lambdas;
Mat Optimizer::initial_image;

Feature* Optimizer::feature;
vector<double> Optimizer::composed_featureVec;


vector<int> Optimizer::getHorizontalProjectionIdxs()
{
    return horizontalProjectionIdxs;
}

void Optimizer::setHorizontalProjectionIdxs(const vector<int> &value)
{
    horizontalProjectionIdxs = value;
}
vector<int> Optimizer::getHorizontalProjectionValues()
{
    return horizontalProjectionValues;
}

void Optimizer::setHorizontalProjectionValues(const vector<int> &value)
{
    horizontalProjectionValues = value;
}
vector<int> Optimizer::getVerticalProjectionIdxs()
{
    return verticalProjectionIdxs;
}

void Optimizer::setVerticalProjectionIdxs(const vector<int> &value)
{
    verticalProjectionIdxs = value;
}
vector<int> Optimizer::getVerticalProjectionValues()
{
    return verticalProjectionValues;
}

void Optimizer::setVerticalProjectionValues(const vector<int> &value)
{
    verticalProjectionValues = value;
}
vector<double> Optimizer::getLambdas()
{
    return lambdas;
}

void Optimizer::setLambdas(const vector<double> &value)
{
    lambdas = value;
}
Mat Optimizer::getInitial_image()
{
    return initial_image;
}

void Optimizer::setInitial_image(const Mat &value)
{
    initial_image = value;
}
vector<double> Optimizer::getComposed_featureVec()
{
    return composed_featureVec;
}

void Optimizer::setComposed_featureVec(const vector<double> &value)
{
    composed_featureVec = value;
}
Feature *Optimizer::getFeature()
{
    return feature;
}

void Optimizer::setFeature(Feature *value)
{
    feature = value;
}

*/










OptimizerDatas::~OptimizerDatas()
{
    delete projHandler;
    delete trainer;
    //dtor
}


/* now some functions to test in one dimension */

/*
double E1(void *xp)
{
    double x = * ((double *) xp);
    return exp(-pow((x-1.0),2.0))*sin(8*x);
}
*/

/*
double energyFunction(void *xp){

    using namespace vectorHelper;

    Mat x = * ((Mat *) xp);
    vector<int> newHorProjVals;
    vector<int> newVertProjVals;

    vector<int> horProjVals = projHandler->getHorizontalProjectionValues();
    vector<int> vertProjVals = projHandler->getVerticalProjectionValues();

    double horProjDist = 0.0;
    double vertProjDist = 0.0;
    double featureDist = 0.0;

    projHandler->generateHorizontalProjValues(x,projHandler->getHorizontalProjectionIdxs(),newHorProjVals);
    projHandler->generateVerticalProjValues(x,projHandler->getVerticalProjectionIdxs(),newVertProjVals);

    //transform(newHorProjVals.begin(),newHorProjVals.end(), horProjVals.begin(),horRes.begin(),std::minus<int>());
    //transform(newVertProjVals.begin(),newVertProjVals.end(), vertProjVals.begin(),vertRes.begin(),std::minus<int>());

    horProjDist = vectorDistance<int>(newHorProjVals,horProjVals);
    vertProjDist = vectorDistance<int>(newVertProjVals,vertProjVals);


    double energy=0.0;
    //Feature feat = new SplittedFeature(4);
    vector<double> newFeatureVec;
    trainer->getFeature().generateFeatureVector(x,newFeatureVec);
    featureDist = vectorDistance<double>(newFeatureVec,trainer->getTrainedFeatureVector());

    energy = OptimizerDatas::getLambdas()[0] * std::pow(horProjDist,2) + OptimizerDatas::getLambdas()[1] * std::pow(vertProjDist,2) +
            OptimizerDatas::getLambdas()[2] * std::pow(featureDist,2);

    return energy;

}
*/

/*
double M1(void *xp, void *yp)
{
    double x = *((double *) xp);
    double y = *((double *) yp);

    return fabs(x - y);
}
*/

/*
double metric(void *xp, void *yp)
{
    Mat x = *((Mat *) xp);
    Mat y = *((Mat *) yp);
    return norm(x,y,NORM_L1);
}
*/

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

/*
void changeImagePixelValue(Mat& img, int row, int col){


    if(img.at<uchar>(row,col) == 1){
        img.at<uchar>(row,col) = 0;
    }

    if(img.at<uchar>(row,col) == 0){
        img.at<uchar>(row,col) = 1;
    }
    else
        throw invalid_argument("The image given is not binary image!");


}


void generateNeighbourState(const gsl_rng * r, void *xp, double step_size){

    Mat old_x = *((Mat *) xp);

    Mat new_x = old_x.clone();

    double rowIdx,colIdx;


    try{
        for(int i=0;i<step_size;i++){
            rowIdx = floor(new_x.rows*gsl_rng_uniform(r));
            colIdx = floor(new_x.cols*gsl_rng_uniform(r));

            changeImagePixelValue(new_x,rowIdx,colIdx);
        }
    }catch(const exception& e){
        std::cerr << e.what();
    }

    memcpy(xp, &new_x, sizeof(new_x));

}
*/

/*
void P1(void *xp)
{
    printf ("%12g", *((double *) xp));
}
*/

/*
void P1(void *xp)
{
    //printf ("%12g", *((double *) xp));
    Mat img = *((Mat *) xp);
    namedWindow( "Display window", WINDOW_AUTOSIZE );// Create a window for display.
    imshow( "Display window", img );
}
*/
/*
double OptimizerDatas::simannSolver(){


    const gsl_rng_type * T;
    gsl_rng * r;

    //double x_initial = 15.5;
    //Mat img_initial = imread("init_img.jpg");
    //Mat img_initial = Mat::zeros( 120, 120, CV_8UC3 );


    //foo = &Optimizer::energyFunction;

    gsl_rng_env_setup();

    T = gsl_rng_default;
    r = gsl_rng_alloc(T);

    //gsl_siman_solve(r, &x_initial, E1, S1, M1, P1,
    //                NULL, NULL, NULL,
    //                sizeof(double), params);


    gsl_siman_solve(r, &OptimizerDatas::initial_image, energyFunction, generateNeighbourState, metric, P1,
                    NULL, NULL, NULL,
                    sizeof(Mat), params);

    gsl_rng_free (r);

    return 1.0;
}
*/








/*
// To find a status with lower energy according to the given condition
template<typename status, typename count, typename energy_function, typename temperature_function, typename next_function, typename generator>
status Optimization::simulated_annealing(status i_old, count c, const energy_function& ef, const temperature_function& tf, const next_function& nf, generator& g){

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
    return(i_best);
}
*/




