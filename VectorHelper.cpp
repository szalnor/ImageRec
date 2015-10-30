/*
#include"VectorHelper.h"


#include<stdexcept>
#include <cmath>

template<typename T>
double vectorDistance(const std::vector<T>& vec1, const std::vector<T>& vec2)
{

    double distance = 0.0;
    if(vec1.size() != vec2.size())
    {
        throw std::invalid_argument("Error! The tow vectors sizes are not equal!");
    }
    else
    {

            for(int i=0; i<vec1.size(); i++)
            {
                distance += pow(vec1[i]-vec2[i], 2.0);

            }
            distance = sqrt(distance);



    }
    return distance;

}

template<typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& numbers){

    for(unsigned int i=0;i<numbers.size();i++){
        out<< numbers[i] << " ";
    }

return out;
}
*/


