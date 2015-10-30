#ifndef FEATURE_H
#define FEATURE_H

#include <vector>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/imgproc/imgproc.hpp"
//#include "opencv2/nonfree/nonfree.hpp"
#include <iostream>

//using namespace std;
//using namespace cv;

//#include "ImageHandler.h"

using namespace cv;
using namespace std;

class Feature
{
public:
    Feature();
    virtual ~Feature();

    //void siftFeature(const Mat img);

    virtual void generateFeatureVector(const Mat& img, vector<double>& featureVec) const = 0;
    //friend ostream& operator<<(ostream& out, const vector<int>& vec);
    //const vector<int>& getFeatureVec() const { return featureVec;};
    //void setFeatureVec(const vector<int> & vec){featureVec = vec;};
    //vector<double> getFeatureVec() const;

protected:
    //vector<double> featureVec;
private:

    //vector<int> featureVec;
    //void calculateSplittedFeature(const Mat& img, const int splitNum, vector<int>& featureVec);
    //void numberAndSizeOfShapes(const Mat& img);


};

#endif // FEATURE_H
