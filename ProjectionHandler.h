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
        ProjectionHandler(Mat img);
        virtual ~ProjectionHandler();
        void generateProjections(int horizontalProjNum, int VerticalProjNum);
        vector<vector<int> > getHorizontalProjections();
        vector<vector<int> > getVerticalProjections();
    protected:
    private:
        Mat inputImg;
        vector<vector<int> > horizontalProjections;
        vector<vector<int> > verticalProjections;
};

#endif // PROJECTIONHANDLER_H
