#ifndef SPLITTEDFEATURE
#define SPLITTEDFEATURE

#include "Feature.h"

class SplittedFeature : public Feature{

public:
    SplittedFeature(const int splitNum);
    void generateFeatureVector(const Mat& img, vector<double>& featureVec) const;
private:

    int splitNum;


};
#endif // SPLITTEDFEATURE

