#ifndef FEATURES_H
#define FEATURES_H

#include <vector>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/imgproc/imgproc.hpp"
//#include "opencv2/nonfree/nonfree.hpp"
#include <iostream>

using namespace std;
using namespace cv;

//#include "ImageHandler.h"
#include <vector>

class Features
{
    public:
        Features();
        virtual ~Features();
        void calculateSplittedFeature(const Mat& img, const int splitNum, vector<int>& featureVec);
        void siftFeature(const Mat img);
        //friend ostream& operator<<(ostream& out, const vector<int>& vec);
        //const vector<int>& getFeatureVec() const { return featureVec;};
        //void setFeatureVec(const vector<int> & vec){featureVec = vec;};
    protected:
    private:
        //vector<int> featureVec;
};

#endif // FEATURES_H
