#ifndef IMAGERECONSTRUCTION_H
#define IMAGERECONSTRUCTION_H

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include <iostream>
#include <vector>
#include <math.h>
#include "OptimizerDatas.h"
#include "ProjectionHandler.h"
#include "Feature.h"

using namespace std;
using namespace cv;

class ImageReconstruction
{
    public:
        ImageReconstruction(const vector<vector<int> >& verticalProjections, const vector<vector<int> >& horizontalProjections, const Feature& feature);
        virtual ~ImageReconstruction();
        //double distance(const Point2f& P1, const Point2f& P2);
       // Mat convertImageToOneDim(Mat img);
        Mat getReconstructedImage();
    protected:
    private:
        //Optimizer opt;
        //ProjectionHandler projHandler(Mat img);

        Mat inputImg;
        Mat reconstructedImg;

};



#endif // IMAGERECONSTRUCTION_H
