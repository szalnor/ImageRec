#ifndef SIMANNOPTIMIZER_H
#define SIMANNOPTIMIZER_H

#include <cmath>
#include <math.h>
#include <random>
#include <utility>
#include <algorithm>
#include <gsl/gsl_siman.h>
#include <memory.h>
#include "OptimizerDatas.h"

class SimannOptimizer
{
public:
    //SimannOptimizer(OptimizerDatas& optimizerDatas);

    static double energyFunction(void *xp);
    static double metric(void *xp, void *yp);
    static void generateNeighbourState(const gsl_rng * r, void *xp, double step_size);
    static void copyFunc(void* source, void* dest);
    static void* copyConstructor(void* xp);
    static void destroy(void* xp);
    static double simannSolver();

    //static OptimizerDatas *getOptimizerDatas();

    static void changeImagePixelValue(Mat &img, int row, int col);
    static void P1(void *xp);
    static OptimizerDatas* optimizerDatas;

private:


};

#endif // SIMANNOPTIMIZER_H
