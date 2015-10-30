#include "Feature.h"

Feature::Feature()
{
    //ctor
}

Feature::~Feature()
{
    //dtor
}



/*
void Feature::calculateSplittedFeature(const Mat& img, const int splitNum, vector<int>& featureVec)
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
*/

/*
void Feature::numberAndSizeOfShapes(const Mat& img)
{

}
*/
/*
void Features::siftFeature(const Mat img){


//    const cv::Mat input = cv::imread("input.jpg", 0); //Load as grayscale
    //const cv::Mat img1 = imread("bone_sample2.jpg");
    cv::SiftFeatureDetector detector;
    std::vector<cv::KeyPoint> keypoints;
    detector.detect(img, keypoints);

    // Add results to image and save.
    cv::Mat output;
    cv::drawKeypoints(img, keypoints, output);
    cv::imwrite("sift_result.jpg", output);
}
*/


/*
ostream& operator<<(ostream& out, const vector<int>& vec) // output
{
    for(int i=0;i<vec.size();i++){
        out << vec[i]<<" ";
    }
    return out;
}
*/


