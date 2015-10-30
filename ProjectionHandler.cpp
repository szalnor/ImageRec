#include "ProjectionHandler.h"
#include <iostream>
#include <exception>

ProjectionHandler::ProjectionHandler(const Mat &img)
{
    if(img.channels()!=1)
    {

        throw invalid_argument("Error! The given image is not a grey or binary image!");
    }


    inputImg = img;
    //ctor
}

ProjectionHandler::ProjectionHandler(const vector<int> &horizontalProjectionIdxs, const vector<int> &horizontalProjectionValues, const vector<int> &verticalProjectionIdxs, const vector<int> &verticalProjectionValues)
    : horizontalProjectionIdxs(horizontalProjectionIdxs), verticalProjectionIdxs(verticalProjectionIdxs),
      horizontalProjectionValues(horizontalProjectionValues), verticalProjectionValues(verticalProjectionValues)
{
    if((horizontalProjectionIdxs.size() != horizontalProjectionValues.size()) || (verticalProjectionIdxs.size() != verticalProjectionValues.size())  )
    {
        throw invalid_argument("Error! The given parameters for constructing ProjectionHandler object are wrong!");
    }

}


ProjectionHandler::~ProjectionHandler()
{
    //dtor
}



void ProjectionHandler::generateHorizontalProjValues(const Mat &img, const vector<int> &projectionRows, vector<int>& result)
{
    if(img.rows < *max_element(projectionRows.begin(), projectionRows.end()) || *min_element(projectionRows.begin(), projectionRows.end()) < 0){
        throw invalid_argument("Error! The projectionRows parameter is wrong!");
    }
    int projValue = 0;
    for(vector<int>::const_iterator it = projectionRows.begin(); it != projectionRows.end();it++){
        projValue = sum(img.row(*it))[0];
        result.push_back(projValue);
    }

}



void ProjectionHandler::generateVerticalProjValues(const Mat &img, const vector<int> &projectionCols, vector<int>& result)
{
    if(img.cols < *max_element(projectionCols.begin(),projectionCols.end()) || *min_element(projectionCols.begin(), projectionCols.end()) < 0){
        throw invalid_argument("Error! The projectionCols parameter is wrong!");
    }
    int projValue = 0;
    for(vector<int>::const_iterator it = projectionCols.begin(); it != projectionCols.end();it++){
        projValue = sum(img.col(*it))[0];
        result.push_back(projValue);
    }
}


/*
void ProjectionHandler::setHorizontalProjectionIdxs(const vector<int>& horizontalIdxs, const vector<int> horizontalProjValues){

    if(horizontalIdxs.size()!=horizontalProjValues.size()){
        throw invalid_argument("Wrong parameters! Their sizes are not equal!");
    }

    this->horizontalProjectionIdxs = horizontalIdxs;


}
*/



/*
void ProjectionHandler::setVerticalProjections(const vector<int>& verticalIdxs, const vector<int>& verticalProjValues){

    if(verticalIdxs.size()!=verticalProjValues.size()){
        throw invalid_argument("Wrong parameters! Their sizes are not equal!");
    }

    this->verticalProjectionIdxs = verticalIdxs;

}
*/




const vector<int>& ProjectionHandler::getHorizontalProjectionIdxs() const
{
    return horizontalProjectionIdxs;
}




const vector<int> &ProjectionHandler::getHorizontalProjectionValues() const
{
    return horizontalProjectionValues;
}



void ProjectionHandler::setHorizontalProjectionIdxs(const vector<int> &value)
{
    horizontalProjectionIdxs = value;
}



const vector<int> &ProjectionHandler::getVerticalProjectionIdxs() const
{
    return verticalProjectionIdxs;
}



const vector<int> &ProjectionHandler::getVerticalProjectionValues() const
{
    return verticalProjectionValues;
}



void ProjectionHandler::setVerticalProjectionIdxs(const vector<int> &value)
{
    verticalProjectionIdxs = value;
}



void ProjectionHandler::setVerticalProjectionValues(const vector<int> &value)
{
    verticalProjectionValues = value;
}



void ProjectionHandler::setHorizontalProjectionValues(const vector<int> &value)
{
    horizontalProjectionValues = value;
}







void ProjectionHandler::generateProjections(int horProjNum, int vertProjNum)
{
    if(horProjNum>=inputImg.rows || vertProjNum>=inputImg.cols)
        throw invalid_argument("The parameters for generating projections are invalid!");


    horizontalProjectionIdxs.clear();
    horizontalProjectionValues.clear();
    verticalProjectionIdxs.clear();
    verticalProjectionValues.clear();


    const int verticalIndex = inputImg.cols/(vertProjNum+1);
    const int horizontalIndex = inputImg.rows/(horProjNum+1);
    int index = 0;
    //std::cout<<horizontalIndex<<"    "<<verticalIndex<<std::endl;
    //cout<<endl;
    //vector<int> temp;
    int horizontalProjValue = 0;

    for(auto i = 1; i<=horProjNum; i++)
    {

        index = horizontalIndex*i;
        horizontalProjectionIdxs.push_back(index);
        horizontalProjValue = sum(inputImg.row(index-1))[0];
        horizontalProjectionValues.push_back(horizontalProjValue);
        /*
        temp.push_back(horizontalIndex-1);
        temp.push_back(horizontalProjValue);
        horizontalProjections.push_back(temp);
        temp.clear();
        */
    }

    int verticalProjValue = 0;
    index = 0;
    for(auto i = 1; i<=vertProjNum; i++)
    {
        index = verticalIndex*i;
        verticalProjectionIdxs.push_back(index);
        verticalProjValue = sum(inputImg.col(index-1))[0];
        verticalProjectionValues.push_back(verticalProjValue);
        /*
        temp.push_back(verticalIndex-1);
        temp.push_back(verticalProjValue);
        verticalProjections.push_back(temp);
        temp.clear();
        */
    }


    /*
    for(auto it=horizontalProjections.begin();it!=horizontalProjections.end();it++){
        for(auto it1 = it->begin();it1!=it->end();it1++){
            std::cout<<*it1<<" ";
        }
        std::cout<<std::endl;
    }
    cout<<endl;
    for(auto it=verticalProjections.begin();it!=verticalProjections.end();it++){
        for(auto it1 = it->begin();it1!=it->end();it1++){
            std::cout<<*it1<<" ";
        }
        std::cout<<std::endl;
    }
    */
}




