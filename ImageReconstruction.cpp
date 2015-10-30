#include "ImageReconstruction.h"
//#include "WrongImageException.h"
#include <stdexcept>


ImageReconstruction::ImageReconstruction(const vector<vector<int> > &verticalProjections, const vector<vector<int> > &horizontalProjections, const Feature &feature)
{

}

ImageReconstruction::~ImageReconstruction()
{
    //dtor
}

/*
double ImageReconstruction::distance(const Point2f& P1, const Point2f& P2)
{

    return sqrt((P2.x - P1.x)* (P2.x - P1.x) + (P2.y - P1.y)*(P2.y - P1.y));
}
*/





/*
// W*x = p -ben a p vektor bővítése a megadott számmal, valamint W megfelelő elemeinek kitöltése
void ImageReconstruction::calculateWeightMatrix()
{



}

Mat ImageReconstruction::getWeightMatrix()
{
    return weightMatrix;
}
*/

/*
double ImageReconstruction::IntensityFromProjection(Mat img, double alfa, double r){

// y = m*x + b egyenes egyenlete
Size imgSize = img.size();

// ha nem négyzetes a kép
if(imgSize.height != imgSize.width)
    return 0;

int N = imgSize.height;

     //throw new NotSquareImageException();

// amikor a sugár nem metszi a képet
if(alfa == M_PI/2){


}



double m = tan(alfa);
if((m>=0 && b>=0) || (m>=0 && b<= -(m+1)*N) || (m<=0 && b>= -N) || (m<=0 && b>= -m*N))
    return 0;

// Kezdőérték megadása (belépő pont)
double x1;
double y1;

// kilépési pont
double x2,y2;
Scalar intensity;
double projection_value = 0.0;
// ha a bal oldalt érinti először
if(m>0){


    if(b<0 && b >=-N){
    x1 = 0.0;
    y1 = b;
    x2 = x1;
    y2 = y1;
    if(y1 != ceil(y1)){
        intensity = img.at<uchar>(abs(ceil(y1)), x1);
    }else{
        intensity = img.at<uchar>(abs(y1+1), x1);
    }
    }

    if(b<-N && b>-N*(m+1)){
    x1 = (abs(b)-N)/m;
    y1 = -N;
    x2 = x1;
    y2 = y1;

    if(x1 != floor(x1)){
        intensity = img.at<uchar>(y1, floor(x1));
    }else{
        intensity = img.at<uchar>(y1, x1);
    }

    }

    do{


    Point2f P1(x1,y1);


    //Point2f ImagePoint((int)x1,ceil(y1));
    // kilépőpont meghatározása
    if(y1 + m > ceil(y1)){
        x2 = (ceil(y1) - y1) / (m + y1) + x1;
        y2 = ceil(y1);
    }
    else{
        y2 = y1 + m;
        x2 = x1 + 1;
    }

    Point2f P2(x2,y2);

    // ha a P1P2 szakasz által metszett képpont értéke 1, akkor távolság számolása a pontok között
    //Scalar intensity = img.at<uchar>(y, x);
    if(intensity[0] == 1){
        projection_value += distance(P1,P2);
    }

    }while(x2<=N || y2<=0);


}
}
*/


