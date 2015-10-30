#ifndef PROJECTIONHANDLER_H
#define PROJECTIONHANDLER_H

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include<vector>
#include<cstdlib>

using namespace cv;
using namespace std;

class ProjectionHandler
{
    public:
        ProjectionHandler(const Mat& img);

        ProjectionHandler(const vector<int>& horizontalProjectionIdxs,
        const vector<int>& horizontalProjectionValues,
        const vector<int>& verticalProjectionIdxs,
        const vector<int>& verticalProjectionValues);

        virtual ~ProjectionHandler();
        void generateProjections(int horProjNum, int vertProjNum);
        //void generateProjections(const vector<int>& projectionRows, const vector<int>& projectionCols);


        static void generateHorizontalProjValues(const Mat& img, const vector<int>& projectionRows, vector<int>& result);
        static void generateVerticalProjValues(const Mat& img, const vector<int>& projectionCols, vector<int>& result);


        const vector<int> &getHorizontalProjectionIdxs() const;
        const vector<int> &getHorizontalProjectionValues() const;
        const vector<int> &getVerticalProjectionIdxs() const;
        const vector<int> &getVerticalProjectionValues() const;

        //void setHorizontalProjections(const vector<int> &horizontalIdxs, const vector<int> horizontalProjValues);
        //void setVerticalProjections(const vector<int> &verticalIdxs, const vector<int> &verticalProjValues);


        void setHorizontalProjectionIdxs(const vector<int> &value);
        void setVerticalProjectionIdxs(const vector<int> &value);

        void setVerticalProjectionValues(const vector<int> &value);

        void setHorizontalProjectionValues(const vector<int> &value);

protected:
private:
        Mat inputImg;

        vector<int> horizontalProjectionIdxs;
        vector<int> horizontalProjectionValues;
        vector<int> verticalProjectionIdxs;
        vector<int> verticalProjectionValues;

        //vector<vector<int> > horizontalProjections;
        //vector<vector<int> > verticalProjections;
};



#endif // PROJECTIONHANDLER_H
