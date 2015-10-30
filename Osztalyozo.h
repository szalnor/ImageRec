#ifndef OSZTALYOZO_H
#define OSZTALYOZO_H

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include<vector>
#include<string>
#include<map>
#include<iterator>
#include "Trainer.h"
using namespace std;
using namespace cv;


class Osztalyozo
{
    public:
        Osztalyozo(const Trainer &trainer);
        virtual ~Osztalyozo();
       // void calculateSimilarity(const map<string,Mat>& sample_images, map<string, double>& results) const;

        void printResults(const map<string,double>& results) const;
    protected:
    private:
        const Trainer &trainer;
};





#endif // OSZTALYOZO_H
