#ifndef OPTIMIZATION_H
#define OPTIMIZATION_H

//#pragma once



#include "opencv2/core/core.hpp"
#include "Feature.h"
#include "ProjectionHandler.h"
#include "Trainer.h"




//double energyFunction(void *xp);


class OptimizerDatas
{
public:


    virtual ~OptimizerDatas();
    OptimizerDatas(Trainer &trainer, ProjectionHandler &projHandler, const cv::Mat initial_img,  const std::vector<double> lambdas);


    ProjectionHandler *getProjHandler() const;

    Trainer *getTrainer() const;

    cv::Mat getInitial_image() const;

    std::vector<double> getLambdas() const;

protected:

private:
    ProjectionHandler* projHandler;
    Trainer* trainer;
    std::vector<double> lambdas;
    cv::Mat initial_image;


};

#endif // OPTIMIZATION_H
