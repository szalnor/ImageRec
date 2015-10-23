

/*
#include "PatternRecognizer.h"
#include <algorithm>

PatternRecognizer::PatternRecognizer()
{
    //ctor
}

PatternRecognizer::~PatternRecognizer()
{
    //dtor-
}


double PatternRecognizer::distance(const Mat& img1, const Mat& img2, int method)
{

    double dist=0.0;
    int numch1 = img1.channels();
    int numch2 = img2.channels();
    unsigned char img_data1, img_data2;


    if(img1.cols != img2.cols || img1.rows != img2.rows || numch1 != 1 || numch2 != 1)
    {
        cout<<"Hiba! A két kép nem egyforma méretű!"<<endl;
        return -1;
    }
    else
    {

        for(int i=0; i<img1.rows; i++)
        {
            for(int j=0; j<img1.cols; j++)
            {
                img_data1 = *(img1.data + img1.step[0]*i + img1.step[1]*j);
                img_data2 = *(img2.data + img2.step[0]*i + img2.step[1]*j);
                dist += (img_data1 == img_data2) ? 0 : 1;
            }
        }

    }

    return dist;

}

double PatternRecognizer::distance(const vector<int> & img1, const vector<int> & img2, int method)
{

    double dist = 0.0;

    if(img1.size() != img2.size())
    {
        cout<<"Hiba! A két kép mérete különböző!"<<endl;
        return -1;
    }

    for(int i=0; i<img1.size(); i++)
    {

        dist += (img1[i] == img2[i]) ? 0 : 1;
        //dist+=abs(img1[i]-img2[i]);

    }

    //return dist/(img1.size()*img1.size());
    return dist;
}


/**
Két kép hasonlóságának számolásához segédmetódus
*/

/*
double PatternRecognizer::calculateSimilarity(const vector< vector<Mat> > & subImages, const vector< vector<Mat> > & patterns, int method)
{

// méretek egyeztetése
    Mat pattern_img;
    double similarity=0.0;
// számolás
    int meret=0;
    for(int i=0; i<subImages.size(); i++)
    {
        for(int j=0; j<subImages[i].size(); j++)
        {

            for(int k=0; k<patterns.size(); k++)
            {
                for(int l=0; l<patterns[k].size(); l++)
                {
                    //cout<<i<<" "<<j<<" "<<k<<" "<<l<<endl;
                    similarity+=distance(subImages[i][j],patterns[k][l],0);
                    meret+=1;

                }
            }

        }

    }

    similarity /= meret;
    return similarity;

}

double PatternRecognizer::calculateSimilarity(map<string,vector<int>> & subImages, map<string, vector<int>> & patterns, int method)
{
    map<string, vector<int>>::iterator it1;
    map<string, vector<int>>::iterator it2;
    double similarity=0.0;
    int meret = 0;

    if(method==0)
    {
        // mindegyiket mindegyikkel összehasonlító
        for(it1=subImages.begin(); it1!=subImages.end(); ++it1)
        {
            for(it2=patterns.begin(); it2!=patterns.end(); ++it2)
            {
                //cout<<it1<<" "<<it2<<endl;
                cout<<"meret: "<<meret<<endl;
                cout<<"similarity: "<<similarity<<endl;
                similarity+=distance(it1->second,it2->second,0);
                meret+=1;


            }

        }

        similarity /= meret;
    }
    else if(method==1)
    {

        // max hasonlóságok kiválasztása
        for(it1=subImages.begin(); it1!=subImages.end(); ++it1)
        {
            for(it2=patterns.begin(); it2!=patterns.end(); ++it2)
            {
                //cout<<it1<<" "<<it2<<endl;
                cout<<"meret: "<<meret<<endl;
                cout<<"similarity: "<<similarity<<endl;
                similarity+=distance(it1->second,it2->second,0);
                meret+=1;

            }

        }

        similarity /= meret;
    }

    return similarity;

}



double PatternRecognizer::calculateSimilarity(const vector< vector<int> > & subImages, const vector< vector<int> > & patterns, int method)
{

    double dist = 0.0;
    int meret=subImages.size()*patterns.size();
    double similarity;

    if(method==0)
    {
        meret = subImages.size()*patterns.size();

        for(int i=0; i<subImages.size(); i++)
        {
            for(int j=0; j<patterns.size(); j++)
            {
                //cout<<i<<" "<<j<<" "<<distance(subImages[i],patterns[j],0)<<endl;

                dist+=distance(subImages[i],patterns[j],0);
                //cout<<i<<" "<<j<<" "<<distance(subImages[i],patterns[j],0)<<endl;
                //cout<<i<<" "<<j<<" "<<dist<<endl;

            }
        }

        return dist/meret;
    }

    int idx1, idx2;
    int meret1 = 1000;
    dist = 0.0;
    double exp;
    int dst;
    // min tav 0, max tav kep merete
    // megszamoljuk, mibol mennyi lett
    int* dst_count = new int[subImages[0].size()];
    int* dst_array = new int[meret1];
    // random értékek generálása
    for(int k=0; k<meret1; k++)
    {
        idx1 = rand() % subImages.size();
        idx2 = rand() % patterns.size();
        dst = (int)distance(subImages[idx1], patterns[idx2],0);
        dst_array[k] = dst;
        //dst_count[dst]++;
        //dist+= distance;
        //cout<<idx1<<" "<<idx2<<" "<<distance(subImages[idx1], patterns[idx2],0)<<endl;
    }
    int dst_max = *max_element(dst_array, dst_array+meret1);




    return dist/meret1;

}

default:
return dist/meret;


}



}
*/





