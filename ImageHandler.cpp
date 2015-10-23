#include "ImageHandler.h"


ImageHandler::ImageHandler(const Mat& img, const int nSize)
{

    if (img.empty()) //check whether the image is loaded or not
    {
        cout << "Error : Image cannot be loaded..!!" << endl;
        //system("pause"); //wait for a key press
    }

    if(img.rows-nSize<0 || img.cols-nSize<0)
    {
        cout<< "Error: Tul nagy subImage meret! ";
    }
    else
    {
        this->img = img;
        this->nSize = nSize;
        // konyvtarak konstrualasa
        for (int i = 0; i<2; i++)
        {
            mkdir((this->dirs[i]).c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH );
        }
    }



}


ImageHandler::ImageHandler(){

}

ImageHandler::~ImageHandler()
{
    //dtor
}


int ImageHandler::WriteImagesToFile()
{


    Mat img1;

    stringstream ss;
    stringstream dd;

    string name = "IMG_";
    string type = ".jpg";

    for(int i=0; i<=img.rows-nSize; i++)
    {
        for(int j=0; j<=img.cols-nSize; j++)
        {
            Mat subImage(img, cv::Rect(j,i,nSize,nSize));
            //subImages.push_back(subImage);
            ss<<dirs[0]<<"/IMG_"<<i<<"_"<<j<<type;

            string img_filename = ss.str();

            imwrite(img_filename,subImage);
            //WriteImageMatrixToFile(img,dirs[1],i,j);
            ss.str("");


        }
    }
    //cout<<subImages.size()<<endl;
    return 0;

}

void ImageHandler::WriteImagesToFile(string imgDir, map<string,Mat>& images)
{

    stringstream ss;
    stringstream dd;

   // string name = "IMG_";
   // string type = ".jpg";

    std::map<string,Mat>::iterator it;

    for(it = images.begin(); it!=images.end(); it++ ){
        //boost::to_upper(it->first);
        string s = it->first;
        std::transform(s.begin(), s.end(), s.begin(), ::toupper);
        ss<<imgDir<< s;
        string img_filename = ss.str();
        //cout<<img_filename<<endl;
        imwrite(img_filename, it->second);
        ss.str("");

    }
    /*
    for(int i=0;i<images.size();i++){
            ss<<imgDir<<"/IMG_"<<i<<type;

            string img_filename = ss.str();

            imwrite(img_filename, images[i]);

            ss.str("");
    }
    */



}






void ImageHandler::WriteImageMatrixToFile(Mat& img, int i, int j)
{

    ofstream myfile;
    stringstream filename;
    filename<<dirs[1]<<"/IMG_"<<i<<"_"<<j<<".txt";
    myfile.open (filename.str());
    myfile << cv::format(img, cv::Formatter::FMT_CSV); //<< std::endl;
    myfile.close();
}


void ImageHandler::WriteImageVectorToFile(map<string, vector<int>>& subImages )
{

    ofstream myfile;
    string fname = "IMG";
    stringstream filename;
    string str;

    map<string, vector<int>>::iterator it;
    for(it=subImages.begin(); it!=subImages.end(); ++it)
    {
        str.assign(it->first);

        filename<<dirs[1]<<"/"<<str.replace(0,3,fname)<<".txt";
        //cout<<filename.str()<<endl;
        myfile.open (filename.str());
        myfile<<cv::format(it->second, cv::Formatter::FMT_CSV);
        filename.str("");
        myfile.close();
    }

}




void ImageHandler::saveSubImages(map<string,vector<int>>& subImages)
{

    stringstream name;
    string name1;
    Mat subImage1;
    for(int i=0; i<=img.rows-nSize; i++)
    {
        for(int j=0; j<=img.cols-nSize; j++)
        {
            name<<"VEC_"<<i<<"_"<<j;
            Mat subImage(img, cv::Rect(j,i,nSize,nSize));

            vector<int> array;
            for(int k=0; k<subImage.rows; k++)
            {
                for(int l=0; l<subImage.cols; l++)
                {
                    array.push_back(*(subImage.data + subImage.step[0]*k + subImage.step[1]*l));

                }
            }
            //cout<<"1D vector: "<<name.str()<<"  merete: "<<array.size()<<endl;

            subImages[name.str()] = array;
            subImage.release();
            name.str("");
        }
    }


}

void ImageHandler::saveSubImages(vector<vector<int>>& subImages)
{


    for(int i=0; i<=img.rows-nSize; i++)
    {
        for(int j=0; j<=img.cols-nSize; j++)
        {

            Mat subImage(img, cv::Rect(j,i,nSize,nSize));

            vector<int> array;
            for(int k=0; k<subImage.rows; k++)
            {
                for(int l=0; l<subImage.cols; l++)
                {
                    array.push_back(*(subImage.data + subImage.step[0]*k + subImage.step[1]*l));

                }
            }
            //cout<<"1D vector: "<<name.str()<<"  merete: "<<array.size()<<endl;
            subImages.push_back(array);
            array.clear();

        }
    }


}




void ImageHandler::saveSubImages(vector< vector<Mat> > & subImages)
{
    vector<Mat> row;

    for(int i=0; i<=img.rows-nSize; i++)
    {
        for(int j=0; j<=img.cols-nSize; j++)
        {

            Mat subImage(img, cv::Rect(j,i,nSize,nSize));
            row.push_back(subImage);

        }

        subImages.push_back(row);
        row.clear();
    }


}


void ImageHandler::saveSubImages(vector<Mat> & subImages)
{
    for(int i=0; i<=img.rows-nSize; i++)
    {
        for(int j=0; j<=img.cols-nSize; j++)
        {

            Mat subImage(img, cv::Rect(i,j,nSize,nSize));
            subImages.push_back(subImage);
            subImage.release();
        }



    }
}


string ImageHandler::intToStr(int i,string path) {
    string bla = "000";
    stringstream ss;
    ss<<i;
    string ret ="";
    ss>>ret;
    string name = bla.substr(0,bla.size()-ret.size());
    name = path+name+ret+".jpg";
    return name;
}

string ImageHandler::removeDirName(string fullName){

string imgName(fullName.substr(fullName.rfind("/")+1));
//cout<<imgName<<endl;
return imgName;

}



bool ImageHandler::readMultipleImages(map<string,Mat> & images, string dirPath, int width, int height){

Mat image;
//cv::VideoCapture cap("bone_000.jpg");
/*
cv::VideoCapture cap(dirPath);

    if (!cap.isOpened())
    {
        cerr << "Failed to open Image Sequence!\n" << endl;
        return 1;
    }

    Mat image;
    //namedWindow("Image | q or esc to quit", WINDOW_AUTOSIZE);

    for(;;)
    {

        cap >> image;

        if(image.empty())
        {
            cout << "End of Sequence" << endl;
            break;
        }
    */
    int i = 1;
    for(;;){
        string curr_img_name = intToStr(i,dirPath);
        string img_name = removeDirName(curr_img_name);
        //cout<<curr_img_name<<endl;
        //cout<< img_name <<endl;

        image = imread(curr_img_name,1);
        if(!image.data){
            break;
        }

        if(transformToBinaryImage(image, image, width, height) == 0);
            images[img_name] = image;

        i++;
    }
        /*
        imshow("image | q or esc to quit", image);
        waitKey(0);
        char key = (char)waitKey(500);
        if(key == 'q' || key == 'Q' || key == 27)
            break;

        }
        */
    return 0;
}

Mat ImageHandler::convertImageToOneDim(Mat img)
{
    Mat img1;

    if(img.empty())
        throw std::invalid_argument( "The image is empty!" );
    else if(img.channels()>1)
        cvtColor(img, img1, COLOR_RGB2GRAY);
    else img1 = img;

    std::vector<uchar> oneDimData1;
    oneDimData1.assign(img1.datastart, img1.dataend);

    Mat retImg(oneDimData1);
    return retImg;
}

bool ImageHandler::transformToBinaryImage(Mat& oldImage, Mat& newImage, int width, int height)
{

    Mat img1, img2;

    //cvtColor(oldImage, img1, COLOR_RGB2GRAY);

    if(oldImage.empty())
        return 1;
    else if(oldImage.channels()>1)
        cvtColor(oldImage, img1, COLOR_RGB2GRAY);
    else img1 = oldImage;

    Size s(width,height);
    resize(img1,img2,s);

// transform to binary image
    threshold( img2, newImage, 128, 255,THRESH_BINARY);
    //newImage/=255;
    return 0;

}



