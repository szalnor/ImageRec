#include "Trainer.h"
#include "Feature.h"
/*
Trainer::Trainer(const Feature &feature)
{
    this->feature = feature;
    //ctor
}


Feature *Trainer::getFeature() const
{
    return feature;
}

void Trainer::setFeature(Feature *value)
{
    feature = value;
}
*/
Trainer::Trainer()
{

}

Trainer::~Trainer()
{
    //delete feature;
    //dtor
}


/*
std::unique_ptr<Feature> Trainer::getFeature() const
{
    return feature;
}

void Trainer::setFeature(const std::unique_ptr<Feature> &value)
{
    feature = value;
}
*/





/*
void Trainer::tanit(map<string,Mat>& pos, vector<int>& result){

// eloszor pos-ban lévő képek feature vektorait számoljuk ki, majd ebből egy "középértéket", így a sok feature-ből
// létrehozunk egy átlagos feature vektort.

Feature f;
vector<vector<int>> featureDatas;
map<string,Mat>::iterator it;


// jellemzők számolása
//for(int i=0;i<pos.size();i++){
//vector<int> seged;
for( it = pos.begin(); it != pos.end(); it++){
    vector<int> seged;
    f.calculateSplittedFeature(it->second,4,seged);
    //seged = f.getFeatureVec();
    featureDatas.push_back(seged);
    //seged.clear();
}

// átlagos jellemző számolása

int komponens_atlag;
vector<int> seged;
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
    result.push_back(komponens_atlag);
    seged.clear();
}


}
*/


