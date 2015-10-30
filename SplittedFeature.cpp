#include "SplittedFeature.h"


SplittedFeature::SplittedFeature(const int splitNum) : splitNum(splitNum)
{

}

void SplittedFeature::generateFeatureVector(const Mat& img, vector<double> &featureVec) const
{

    int rows = img.rows;
    int cols = img.cols;
    int subImg_rows = rows / splitNum;
    int subImg_cols = cols / splitNum;
    int numOfPixels=0;

    for(int i=0; i<splitNum; i++)
    {
        for(int j=0; j<splitNum; j++)
        {

            Mat subImg(img,cv::Rect(subImg_rows*i,subImg_cols*j,subImg_rows,subImg_cols));
            numOfPixels = cv::sum(subImg)[0];
            featureVec.push_back(numOfPixels);

        }
    }

}
