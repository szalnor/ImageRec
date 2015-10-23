#include "WrongImageException.h"

WrongImageException::WrongImageException()
{
    //ctor
}

const char* WrongImageException::what() const throw()
{
    return "Invalid Image!";
}

const char* EmptyImageException::what() const throw()
{
    return "Invalid Image! The image is empty!";
}

WrongImageException::~WrongImageException()
{
    //dtor
}
