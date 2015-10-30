#include "Osztalyozo.h"
#include "Trainer.h"
#include "Feature.h"
#include "ImageHandler.h"
//#include<map>
//#include<iterator>

//#include "VectorHelper.h"
//using namespace vectorHelper;

Osztalyozo::Osztalyozo(const Trainer &trainer) : trainer(trainer)
{

    //ctor
}

Osztalyozo::~Osztalyozo()
{

}


/*
void Osztalyozo::calculateSimilarity(const map<string, Mat> &sample_images, map<string, double>& results) const
{

    //Trainer tanito;


    vector<double> combined_FeatureVec;
    double res;
    /*
    if(imgh.readMultipleImages(pos_images,posDir) == 1){

    cerr<<"Hiba a kepek beolvasasa soran!"<<endl;

    }
    else{
    */

/*
    trainer.train();


    // egyes képek távolságainak számolása
    //for(int i=0; i<sample_images.size(); i++)
    map<string, Mat>::const_iterator it;
    for(it = sample_images.begin(); it != sample_images.end(); it++)
    {

        vector<double> imgFeatureVec;
        //feature.calculateSplittedFeature(sample_images[i],4, imgFeatureVec);
        //feature.calculateSplittedFeature(it->second, 4, imgFeatureVec);
        //imgFeatureVec = feature.getFeatureVec();

        res = vectorDistance(combined_FeatureVec, imgFeatureVec);
        results[it->first] = res;
        //results.push_back(res);
    }

//}



}
*/



void Osztalyozo::printResults(const map<string,double>& results) const{

map<string,double>::const_iterator it;
for(it = results.begin(); it != results.end(); it++){

cout<<it->first<<"     "<< it->second<<endl;

}
/*
for(int i=0;i<results.size();i++){

cout<<results[i]<<endl;

}
*/



}



