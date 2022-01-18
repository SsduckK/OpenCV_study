#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;


#if 0
int main()
{
    Point pt1;
    pt1.x = 5;
    pt1.y = 10;

    Point pt2(10, 30);

    cout << pt1 << ", " << pt2 << endl;

    Point pt3 = pt1 + pt2;

    Point pt4 = pt1 * 2;

    int dot = pt1.dot(pt2);
    int cross = pt1.cross(pt2);

    cout << pt3 << ", " << pt4 << endl;
    cout << dot << ", " << cross << endl;
}
#endif

#if 0
int main()
{
    Size sz1, sz2(10, 20);
    sz1.width = 5; sz1.height = 10;

    cout << sz1 << ", " << sz2 << endl;

    Size sz3 = sz1 + sz2;
    Size sz4 = sz1 * 2;

    int area = sz1.area();

    cout << sz3 << ", " << sz4 << endl;
    cout << area << endl;
}
#endif

#if 0
int main()
{
    Rect rc1;
    Rect rc2(10, 10, 60, 40);

    rc1.x = 10;
    rc1.y = 10;
    rc1.width = 20;
    rc1.height = 30;

    Rect rc3 = rc1 + Size(50, 40);
    Rect rc4 = rc2 + Size(10, 10);

    cout << rc1 << ", " << rc2 << endl;
    cout << rc3 << ", " << rc4 << endl;

    Rect rc5 = rc3 & rc4;
    Rect rc6 = rc3 | rc4;

    cout << rc5 << ", " << rc6 << endl;

    Mat img1(100, 100, CV_8UC3, Scalar(255, 255, 255));
    Mat img2(100, 100, CV_8UC3, Scalar(255, 255, 255));
    Mat img3(100, 100, CV_8UC3, Scalar(255, 255, 255));

    rectangle(img1, rc1, Scalar(0, 0, 255), 2);
    rectangle(img1, rc2, Scalar(255, 0, 0), 2);

    rectangle(img2, rc3, Scalar(0, 255, 255), 2);
    rectangle(img2, rc4, Scalar(255, 255, 0), 2);

    rectangle(img3, rc5, Scalar(255, 0, 255), 2);
    rectangle(img3, rc6, Scalar(0, 255, 0), 2);

    imshow("1", img1);
    imshow("2", img2);
    imshow("3", img3);
    waitKey();

    destroyAllWindows();
}
#endif

#if 0
int main()
{
    RotatedRect rr(Point2f(40, 30), Size2f(40, 20), 30.f);
    Point2f pts[4];
    rr.points(pts);
    for (int i =0 ; i < 5; i++)
    {
        cout << pts[i] << endl;
    }
}
#endif

#if 0
int main()
{
    Range r1(0, 10);
    cout << r1 << endl;
}
#endif

#if 0
int main()
{
	Mat img1(480, 640, CV_8UC1);
    Mat img2(480, 640, CV_8UC3);
    
    Mat img3(Size(640, 480), CV_8UC3);	

    Mat img4(480, 640, CV_8UC1, Scalar(128));
    Mat img5(480, 640, CV_8UC3, Scalar(255, 0, 0));
        
    Mat mat1 = Mat::zeros(3, 3, CV_32SC1);
    Mat mat2 = Mat::ones(3, 3, CV_32FC1);
    Mat mat3 = Mat::eye(3, 3, CV_32FC1);

    cout << mat1 << endl<< endl << mat2 << endl<< endl << mat3 << endl;	
}
#endif


int main()
{
    Mat img1 = imread("sample2.png");
    Mat img2 = img1;
    
    Mat img3 = img1.clone();
    Mat img4;
    Mat img5;
    img1.copyTo(img4);
    img1.copyTo(img5);

    img1.setTo(Scalar(255, 255, 0));

    Mat img6 = img5(Rect(50, 50, 100, 100));
    Mat img7;
    img6.copyTo(img7);
    img7 = ~img7;

    imshow("img1", img1);
    imshow("img2", img2);
    imshow("img3", img3);
    imshow("img4", img4);
    imshow("img5", img5);
    imshow("6", img6);
    imshow("7", img7);
    

    waitKey();

}