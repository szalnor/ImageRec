#ifndef PATTERNRECOGNIZER_H
#define PATTERNRECOGNIZER_H


#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <vector>
#include <map>
#include <cstdlib>

using namespace std;
using namespace cv;


class PatternRecognizer
{
    public:
        PatternRecognizer();
        ~PatternRecognizer();
        double distance(const Mat& img1, const Mat& img2, int method);
        double distance(const vector<int> & img1, const vector<int> & img2, int method);
        double calculateSimilarity(const vector< vector<Mat> >& img, const vector< vector<Mat> >& patterns, int method);
        double calculateSimilarity(map< string,vector<int> >& subImages, map< string, vector<int> >& patterns, int method);
        double calculateSimilarity(const vector<vector<int> >& subImages, const vector < vector<int> >& patterns, int method);
    protected:
    private:
};

#endif // PATTERNRECOGNIZER_H
