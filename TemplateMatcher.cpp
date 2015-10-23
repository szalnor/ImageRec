#include "TemplateMatcher.h"


TemplateMatcher::TemplateMatcher()
{
    //ctor
}

TemplateMatcher::~TemplateMatcher()
{
    //dtor
}


void TemplateMatcher::matchImages(const Mat& img, const Mat& pattern_img, const int nSize, const int metric, const int matchingMethod, const int num_rnd, double* matchResult)
{

// for ciklusban végighaladunk a pattern image ablakolt részein, minden
// összehasonlítunk a képpel -> tároljuk mátrixba -> E1: mátrixelemek összegzése
// subImage-ek kivágása
    ImageHandler imgHandler(pattern_img, nSize);
    vector<Mat> subImages;
    imgHandler.saveSubImages(subImages);
    srand (time(NULL));

    if(img.rows<pattern_img.rows || img.cols<pattern_img.cols)
    {
        throw "Pattern size dimensions exceeded image dimensions";
    }
    else
    {
        switch(matchingMethod)
        {

        // E1: mindent mindennel összehasonlítás
        case 0:
        {
            double averageMatch = 0.0;
            double minVal=0.0;
            double maxVal=0.0;
            Point minLoc;
            Point maxLoc;
            Point matchLoc;
            double minElement=0.0;
            double maxElement=0.0;
            vector<Mat> resultDatas;

            int subImgRows = img.rows-nSize+1;
            int subImgCols = img.cols-nSize+1;
            cout<<"subImgSize: "<<subImages.size()<<endl;
            cout<<"img size: "<<img.size()<<endl;


            for(int i=0; i<subImages.size(); i++)
            {
                Mat result(img.rows-nSize+1, img.cols-nSize+1, CV_32FC1);
                //Mat result;
                matchTemplate( img, subImages[i], result, metric);
                //normalize( result, result, 0, 1, NORM_MINMAX, -1, Mat() );
                averageMatch += sum(result)[0];
                minMaxLoc( result, &minVal, &maxVal, &minLoc, &maxLoc, Mat() );
                resultDatas.push_back(result);


                //cout<<result.size()<<endl;
                //cout<<minVal<<" "<<maxVal<<endl;
                if(i==0)
                {
                    minElement = minVal;
                    maxElement = maxVal;
                }

                if(minVal<minElement)
                    minElement = minVal;

                if(maxVal>maxElement)
                    maxElement = maxVal;

                result.release();
            }

            averageMatch /= (subImages.size()* subImgRows*subImgCols);
            matchResult[0] = averageMatch;
            //matchResult[1] = minElement;
            //matchResult[2] = maxElement;

            /*
            ofstream myfile;
            myfile.open ("resultDatas.txt");

            myfile << "average match:"<<"   "<<"match stdev"<<"    "<<"minMatch"<<"maxMatch"<<endl;
            //myfile<<averageMatch<<"    "<<
            //myfile <<"min: "<<resultStats[2]<<endl;
            //myfile <<"max: "<<resultStats[3]<<endl;
            myfile.close();
            */

        };
        break;

        // E2,E3: min/max(delta) : minimum/maximum távolságok
        case 1:
        {
            double minVal=0.0;
            double maxVal=0.0;
            Point minLoc;
            Point maxLoc;
            Point matchLoc;
            double minElement=0.0;
            double maxElement=0.0;

            for(int i=0; i<subImages.size(); i++)
            {
                Mat result( img.rows-nSize+1, img.cols - nSize + 1, CV_32FC1 );
                //Mat result;
                matchTemplate( img, subImages[i], result, metric);
                minMaxLoc( result, &minVal, &maxVal, &minLoc, &maxLoc, Mat() );
                result.release();
                //cout<<result.size()<<endl;
                //cout<<minVal<<" "<<maxVal<<endl;
                if(i==0)
                {
                    minElement = minVal;
                    maxElement = maxVal;
                }

                if(minVal<minElement)
                    minElement = minVal;

                if(maxVal>maxElement)
                    maxElement = maxVal;



            }

            matchResult[0] = minElement;
            matchResult[1] = maxElement;


        };
        break;

        // random E4
        case 2:
        {

            double averageMatch = 0.0;
            double standardDeviation = 0.0;
            vector<double> result_values;
            //int subImgRows = img.rows-nSize+1;
            //int subImgCols = img.cols-nSize+1;
            int idx1, idx2, idx3;

            for(int j=0; j<10; j++)
            {
                averageMatch = 0.0;
                for(int i=0; i<num_rnd; i++)
                {
                    //Mat result(1, 1, CV_32FC1);
                    Mat result;

                    idx1 = rand() % subImages.size();
                    idx2 = rand() % (img.rows-nSize+1);
                    idx3 = rand() % (img.cols-nSize+1);
                    //cout<<i<<" "<<idx1<<"  "<<idx2<<"  "<<idx3<<endl;

                    Mat sub_img(img, cv::Rect(idx2,idx3,nSize,nSize));
                    //cout<<"sub_img size: "<<sub_img.size()<<endl;
                    //cout<<"subImages size: "<<subImages[idx1].size()<<endl;
                    //cout<<sub_img<<endl;


                    matchTemplate( sub_img, subImages[idx1], result, metric);
                    //cout<<"result: "<<result<<endl;
                    //cout<<"result size: "<<result.size()<<endl;
                    //cout<<"sum(result): "<<sum(result)<<endl;

                    averageMatch += sum(result)[0];

                    result.release();
                    sub_img.release();

                }
                averageMatch /= num_rnd;
                //matchResult[0] = averageMatch;

                result_values.push_back(averageMatch);

            }

            matchResult[0] = calculateMean(result_values);
            matchResult[1] = calculateStd(result_values,matchResult[0]);
            writeResultstoFile(result_values,matchResult);


        };
        break;

        // random E2, E3
        case 3:
        {

            double minVal;
            double maxVal;
            Point minLoc;
            Point maxLoc;
            Point matchLoc;
            double minElement,maxElement;
            int idx1, idx2, idx3;

            for(int i=0; i<num_rnd; i++)
            {
                Mat result(1, 1, CV_32FC1);
                idx1 = rand() % subImages.size();
                idx2 = rand() % (img.rows-nSize+1);
                idx3 = rand() % (img.cols-nSize+1);
                //cout<<idx1<<"   "<<idx2<<"  "<<idx3<<endl;
                Mat sub_img(img, cv::Rect(idx2,idx3,nSize,nSize));
                //cout<<subImages[idx1]<<endl;
                //cout<<endl;
                //cout<<sub_img<<endl;
                matchTemplate( sub_img, subImages[idx1], result, metric);
                //matchTemplate( sub_img, subImages[idx1], result, CV_TM_CCORR_NORMED);
                minMaxLoc( result, &minVal, &maxVal, &minLoc, &maxLoc, Mat() );
                //cout<<result<<" "<<minVal<<" "<<maxVal<<endl;

                if(i==0)
                {
                    minElement = minVal;
                    maxElement = maxVal;
                }

                if(minVal<minElement)
                    minElement = minVal;

                if(maxVal>maxElement)
                    maxElement = maxVal;

                result.release();
            }

            matchResult[0] = minElement;
            matchResult[1] = maxElement;




        };
        break;

        default:
            throw "Rossz szamot adott meg! ";
            break;




        }

    }

}




double TemplateMatcher::calculateMean(const vector<double> values)
{

    double sum=0.0;
    for(int i = 0; i < values.size(); i++)
    {
        sum+=values[i];
    }

    return sum/values.size();
}




double TemplateMatcher::calculateStd(const vector<double> values, double mean)
{

    double temp = 0.0;

    for(int i=0; i<values.size(); i++)
    {
        temp+= (values[i]-mean) * (values[i]-mean);
    }

    return sqrt(temp/(values.size()-1));

}

double TemplateMatcher::distance(const vector<int> vec1, const vector<int> vec2)
{

    double distance = 0.0;
    if(vec1.size() != vec2.size())
    {
        cout<<"A két vektor nem egyforma méretű!"<<endl;
        return 0;
    }
    else
    {
        for(int i=0; i<vec1.size(); i++)
        {
            distance += pow(vec1[i]-vec2[i], 2.0);

        }
        distance = sqrt(distance);
        return distance;
    }




}









void TemplateMatcher::writeResultstoFile(vector<double> resultDatas, double* resultStats)
{

    ofstream myfile;
    myfile.open ("resultDatas.txt");
    for(int i=0; i<resultDatas.size(); i++)
    {
        //myfile<<i<<"    "<<resultDatas[i]<<endl;
        myfile<<resultDatas[i]<<endl;
    }
    myfile << "mean: "<<resultStats[0]<<endl;
    myfile << "std: "<<resultStats[1]<<endl;
    //myfile <<"min: "<<resultStats[2]<<endl;
    //myfile <<"max: "<<resultStats[3]<<endl;
    myfile.close();

}




