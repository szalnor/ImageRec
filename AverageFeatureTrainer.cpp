#include "AverageFeatureTrainer.h"

AverageFeatureTrainer::AverageFeatureTrainer(const Feature &feature, const map<string, Mat> &pos) : feature(feature), pos(pos)
{

}

void AverageFeatureTrainer::train()
{

    // eloszor pos-ban lévő képek feature vektorait számoljuk ki, majd ebből egy "középértéket", így a sok feature-ből
    // létrehozunk egy átlagos feature vektort.

    vector<vector<double>> featureDatas;
    map<string,Mat>::const_iterator it;


    // jellemzők számolása
    //for(int i=0;i<pos.size();i++){
    //vector<int> seged;
    for( it = pos.begin(); it != pos.end(); it++){
        vector<double> seged;
        feature.generateFeatureVector(it->second,seged);
        //f.calculateSplittedFeature(it->second,4,seged);
        //seged = f.getFeatureVec();
        featureDatas.push_back(seged);
        //seged.clear();
    }

    // átlagos jellemző számolása

    int komponens_atlag;
    vector<double> seged;
    // 16 a mérete 4x4-es split esetén
    for(unsigned int i=0;i<featureDatas[0].size();i++){

        // pos.size()
        for(unsigned int j=0;j<featureDatas.size();j++){
            seged.push_back(featureDatas[j][i]);
        }
        //cout<<"seged: "<< seged<<endl;
        //cout<<"sum(seged) [0] : " << sum(seged) [0] <<endl;

        komponens_atlag = sum(seged)[0] / featureDatas.size();

        //cout<<"komponens_atlag: " << komponens_atlag<<endl;
        trainedFeatureVector.push_back(komponens_atlag);
        seged.clear();
    }

}
const Feature &AverageFeatureTrainer::getFeature() const
{
    return feature;
}
const vector<double> &AverageFeatureTrainer::getTrainedFeatureVector() const
{
    return trainedFeatureVector;
}




