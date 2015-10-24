#ifndef TANITO_H
#define TANITO_H

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include<map>
#include<iterator>

using namespace std;
using namespace cv;

class Tanito
{
    public:
        Tanito();
        virtual ~Tanito();
        void tanit(map<string,Mat>& pos, vector<int>& result);
        friend ostream& operator<<(ostream& out, const vector<int> numbers);
    protected:
    private:
};

#endif // TANITO_H
