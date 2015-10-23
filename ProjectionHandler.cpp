#include "ProjectionHandler.h"

using namespace std;

ProjectionHandler::ProjectionHandler(Mat img)
{
    if(img.channels()!=1)
        throw invalid_argument("Error! The given image is not a grey image!");

    inputImg = img;
    //ctor
}

ProjectionHandler::~ProjectionHandler()
{
    //dtor
}

vector<vector<int> > ProjectionHandler::getVerticalProjections()
{
    return verticalProjections;
}

vector<vector<int> > ProjectionHandler::getHorizontalProjections()
{
    return horizontalProjections;
}



void ProjectionHandler::generateProjections(int horProjNum, int vertProjNum)
{
    if(horProjNum>=inputImg.rows || vertProjNum>=inputImg.cols)
        throw invalid_argument("The parameters for generating projections are invalid!");

    int verticalIndex = inputImg.cols/(vertProjNum+1);
    int horizontalIndex = inputImg.rows/(horProjNum+1);
    int projValue = 0;
    cout<<horizontalIndex<<"    "<<verticalIndex<<endl;

    vector<int> temp;
    for(auto i = 1; i<=horProjNum; i++)
    {

        horizontalIndex*=i;
        horizontalProjValue = sum(InputImg.rows(horizontalIndex-1))[0];

        temp.push_back(horizontalIndex-1);
        temp.push_back(horizontalProjValue);
        horizontalProjections.push_back(temp);
        temp.clear();

    }


    for(auto i = 1; i<=vertProjNum; i++)
    {
        verticalIndex*=i;
        verticalProjValue = sum(InputImg.cols(verticalIndex-1))[0];
        temp.push_back(verticalIndex-1);
        temp.push_back(verticalProjValue);
        hverticalProjections.push_back(temp);
        temp.clear();
    }


for(auto it = horizontalProjections.begin();it<horizontalProjections.end();it++){

cout<<"index: "<<it->first<<"   "<<it->second

}

}


