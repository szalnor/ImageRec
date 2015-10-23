#ifndef TEMPLATEMATCHER_H
#define TEMPLATEMATCHER_H

#include "ImageHandler.h"
#include <stdlib.h>
#include <ctime>

class TemplateMatcher
{
    public:
        TemplateMatcher();
        virtual ~TemplateMatcher();
        void matchImages(const Mat& img, const Mat& pattern_img, const int nSize, const int metric, const int matchingMethod, const int k, double* matchResult);
        double calculateMean(const vector<double> values);
        double calculateStd(const vector<double> values, double mean);
        double distance(const vector<int> vec1, const vector<int> vec2);
        void writeResultstoFile(vector<double> resultDatas, double* resultStats);
    protected:
    private:
        Mat img, pattern_img;
        int nSize;
        double* matchValue;

};

#endif // TEMPLATEMATCHER_H
