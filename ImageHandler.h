#ifndef IMAGEHANDLER_H
#define IMAGEHANDLER_H

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <sstream>
#include <fstream>
#include <sys/stat.h>
#include <vector>
#include <map>
#include <math.h>
//#include <boost/tokenizer.hpp>
//#include <boost/foreach.hpp>
//#include <boost/algorithm/string.hpp>

using namespace std;
using namespace cv;
//using namespace boost;

class ImageHandler
{
    public:
        int WriteImagesToFile();
        void WriteImagesToFile(string imgDir, map<string,Mat>& images);
        void WriteImageMatrixToFile(Mat& img, int i, int j);
        void WriteImageVectorToFile(map<string,vector<int> >& subImages);
        static bool transformToBinaryImage(Mat& oldImage, Mat& newImage, int width, int height);
        void saveSubImages(map<string,vector<int> >& subImages);
        void saveSubImages(vector< vector<Mat> > & subImages);
        void saveSubImages(vector< vector<int> > & subImages);
        void saveSubImages(vector<Mat> & subImages);
        static bool readMultipleImages(string image_dirPath, map<string,Mat>& images, int width, int height);
        Mat convertImageToOneDim(Mat img);
        static string removeDirName(string fullName);
        static string intToStr(int i,string path);

        ImageHandler(const Mat& img, const int nSize);
        ImageHandler();
        ~ImageHandler();


    protected:
    private:
        int nSize;
        Mat img;
        const string dirs[2] = {"images","imageDatas"};
};

#endif // IMAGEHANDLER_H
