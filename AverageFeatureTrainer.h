#ifndef AVERAGEFEATURETRAINER_H
#define AVERAGEFEATURETRAINER_H

#include <map>
#include <string>
#include "Trainer.h"

using namespace std;

class AverageFeatureTrainer : public Trainer{

public:
    AverageFeatureTrainer(const Feature& feature, const map<string,Mat>& pos);
    virtual void train();

    const Feature &getFeature() const;

    const vector<double>& getTrainedFeatureVector() const;

private:
    map<string,Mat> pos;
    const Feature& feature;
    vector<double> trainedFeatureVector;

};

#endif // AVERAGEFEATURETRAINER_H
