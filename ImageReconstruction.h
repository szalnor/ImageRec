#ifndef IMAGERECONSTRUCTION_H
#define IMAGERECONSTRUCTION_H

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include <iostream>
#include <vector>
#include <math.h>


using namespace std;
using namespace cv;

class ImageReconstruction
{
    public:
        ImageReconstruction(Mat inputImg);
        virtual ~ImageReconstruction();
        vector<int> getVerticalProjectionVector()
        vector<int> getHorizontalProjectionVector()


        double getProjectionValue(Mat img, double alfa, double r);
        double getProjectionValue(int sorOszl, int index);

        double distance(const Point2f& P1, const Point2f& P2);
        double calculateProjectionValue(int sorOszl, int index);
        void calculateWeightMatrix();
        Mat convertImageToOneDim(Mat img);
        Mat getWeightMatrix();
        Mat getReconstructedImage();
    protected:
    private:
        Mat weightMatrix;
        Mat projectionVector;
        vector<int> verticalProjectionVector;
        vector<int> horizontalProjectionVector;
        Mat inputImg;
        Mat reconstructedImg;

};

#endif // IMAGERECONSTRUCTION_H
