#include "Osztalyozo.h"
#include "Tanito.h"
#include "Features.h"
#include "ImageHandler.h"
//#include<map>
//#include<iterator>


Osztalyozo::Osztalyozo()
{
    //ctor
}

Osztalyozo::~Osztalyozo()
{
    //dtor
}



void Osztalyozo::calculateSimilarity(string posDir, string imgDir, map<string, double>& results)
{

    Tanito tanito;
    Features feature;
    ImageHandler imgh;

    map<string, Mat>::iterator it;
    map<string,Mat> pos_images;
    map<string,Mat> sample_images;
    vector<int> combined_FeatureVec;
    double res;
    /*
    if(imgh.readMultipleImages(pos_images,posDir) == 1){

    cerr<<"Hiba a kepek beolvasasa soran!"<<endl;

    }
    else{
    */
    imgh.readMultipleImages(pos_images,posDir, 120, 120);
    imgh.readMultipleImages(sample_images,imgDir,120, 120);


    imgh.WriteImagesToFile("/media/szalnor/TANANYAGOK/KEPFELDOLGOZAS/BinaryImageReconstruction/img_samples/", sample_images);
    imgh.WriteImagesToFile("/media/szalnor/TANANYAGOK/KEPFELDOLGOZAS/BinaryImageReconstruction/bone_samples/", pos_images);

    tanito.tanit(pos_images,combined_FeatureVec);


    // egyes képek távolságainak számolása
    //for(int i=0; i<sample_images.size(); i++)
    for(it = sample_images.begin(); it != sample_images.end(); it++)
    {

        vector<int> imgFeatureVec;
        //feature.calculateSplittedFeature(sample_images[i],4, imgFeatureVec);
        feature.calculateSplittedFeature(it->second, 4, imgFeatureVec);
        //imgFeatureVec = feature.getFeatureVec();

        res = distance(combined_FeatureVec, imgFeatureVec,0);
        results[it->first] = res;
        //results.push_back(res);
    }
//}



}



double Osztalyozo::distance(const vector<int>& vec1, const vector<int>& vec2, int method)
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

void Osztalyozo::printResults(map<string,double>& results){

map<string,double>::iterator it;
for(it = results.begin(); it != results.end(); it++){

cout<<it->first<<"     "<< it->second<<endl;

}
/*
for(int i=0;i<results.size();i++){

cout<<results[i]<<endl;

}
*/



}



