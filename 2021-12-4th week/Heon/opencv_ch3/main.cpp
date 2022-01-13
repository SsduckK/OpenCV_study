#include <opencv2/opencv.hpp>
#include <iostream>
// int main()
// {
// cv::Mat mat(200, 200, CV_8UC3);
// mat(cv::Rect(0, 0, 100, 200)) = cv::Vec3b(255, 255, 255);
// cv::imshow("mat", mat);
// cv::waitKey(0);
// return 0;
// }




void Pointop();
void Sizeop();
void Rectop();
void RotatedRectop();
void Stringop();


//Point_클래스
void Pointop()
{
    cv::Point pt1;
    pt1.x = 5;
    pt1.y = 10;
    cv::Point pt2(10, 30);

    cv::Point pt3 = pt1 + pt2;
    cv::Point pt4 = pt1 * 2;
    int d1 = pt1.dot(pt2);
    bool bi = (pt1 == pt2);

    std::cout << "pt1: " << pt1 << std::endl;
    std::cout << "pt2: " << pt2 << std::endl;

}
//Size_클래스
void Sizeop()
{
    cv::Size sz1, sz2(10, 20);
    sz1.width = 5; sz1.height = 10;
    cv::Size sz3 = sz1 + sz2;
    cv::Size sz4 = sz1 * 2;
    int area1 = sz4.area();

    std::cout << "sz3: " << sz3 << std::endl;
    std::cout << "sz4: " << sz4 << std::endl;
}

void Rectop()
{
    cv::Rect rc1;
    cv::Rect rc2(10,10,60,40);
    cv::Rect rc3 = rc1 + cv::Size(50, 40);
    cv::Rect rc4 = rc2 + cv::Point(10, 10);
    cv::Rect rc5 = rc3 & rc4;
    cv::Rect rc6 = rc3 | rc4;

    std::cout << "rc5: " << rc5 << std::endl;
    std::cout << "rc6: " << rc6 << std::endl;
}

void RotatedRectop()
{   
    cv::RotatedRect rr1(cv::Point2f(40,30), cv::Size2f(40, 20), 30.f);
    cv::Point2f pts[4];
    rr1.points(pts);
    cv::Rect br = rr1.boundingRect();

    std::cout << "br: " << br << std::endl;

}
void Rangeop()
{
    cv::Range r1(0, 10);
}

void Stringop()
{
    typedef std::string String;

    String str1 ="Hello";
    String str2 = "world";
    String str3 = str1 + " " + str2;

    bool ret = (str2 == "WORLD");
}





int main()
{
    Pointop();
    Sizeop();
    Rectop();
    RotatedRectop();
    Stringop();
    return 0;
}

