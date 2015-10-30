#ifndef TRAINER_H
#define TRAINER_H

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "Feature.h"
#include<iterator>

using namespace std;
using namespace cv;

class Trainer
{
    public:
        //Trainer(const Feature &feature);
        Trainer();
        virtual ~Trainer();
        virtual void train() = 0;
        // void tanit(map<string,Mat>& pos, vector<int>& result);
        // friend ostream& operator<<(ostream& out, const vector<int> numbers);
        virtual const Feature &getFeature() const = 0;
        virtual const vector<double>& getTrainedFeatureVector() const = 0;

protected:
        //const Feature& feature;
private:

};

#endif // TRAINER_H
