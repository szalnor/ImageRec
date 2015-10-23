#ifndef OSZTALYOZO_H
#define OSZTALYOZO_H

#include<vector>
#include<string>
#include<map>
#include<iterator>

using namespace std;



class Osztalyozo
{
    public:
        Osztalyozo();
        virtual ~Osztalyozo();
        void calculateSimilarity(string posDir, string test_imgDir, map<string, double>& results);
        double distance(const vector<int>& vec1, const vector<int>& vec2, int method);
        void printResults(map<string,double>& results);
    protected:
    private:
};

#endif // OSZTALYOZO_H
