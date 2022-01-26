#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

#if 0
int main()
{
    Mat img(400, 400, CV_8UC3, Scalar(255, 255, 255));
    line(img, Point(100, 100), Point(200, 50), Scalar(0, 0, 255));

    line(img, Point(250, 250), Point(150, 150), Scalar(0, 255, 0), LINE_4);

    arrowedLine(img, Point(300, 300), Point(100, 300), Scalar(255, 0, 0));

    imshow("img", img);
    waitKey();

}
#endif

#if 0
int main()
{
    Mat img(400, 400, CV_8UC3, Scalar(255, 255, 255));

    rectangle(img, Rect(50, 50, 100, 50), Scalar(255, 0, 0), 2);
    rectangle(img, Rect(150, 250, 100, 50), Scalar(0, 255, 0), -1);

    circle(img, Point(300, 300), 30, Scalar(0, 0, 255), 2);
    circle(img, Point(300, 300), 15, Scalar(0, 50, 5), -1);

    imshow("img", img);
    waitKey();
}
#endif

#if 0
int main()
{
    Mat img(500, 800, CV_8UC3, Scalar(255, 255, 255));

    putText(img, "Test Put Text", Point(20, 50),
        FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 0, 255));
    putText(img, "Test Put Text", Point(20, 100),
        FONT_HERSHEY_PLAIN, 1, Scalar(0, 255, 0));
    putText(img, "Test Put Text", Point(20, 150),
        FONT_HERSHEY_DUPLEX, 1, Scalar(255, 0, 0));
    putText(img, "Test Put Text", Point(20, 200),
        FONT_HERSHEY_COMPLEX, 1, Scalar(255, 0, 255));
    putText(img, "Test Put Text", Point(20, 250),
        FONT_HERSHEY_TRIPLEX, 1, Scalar(0, 255, 255));
    putText(img, "Test Put Text", Point(20, 300),
        FONT_HERSHEY_COMPLEX | FONT_ITALIC, 1, Scalar(0, 0, 0));                                
    imshow("img", img);
    waitKey();
}
#endif

int main()
{
    Mat mask = imread("sample2.png", IMREAD_GRAYSCALE);
    Mat src = imread("test.png", IMREAD_COLOR);

    if (src.empty() || mask.empty()){
        cerr << "image load failed" << endl;
        return 0;
    }

    src.setTo(Scalar(255, 0, 255), mask);

    imshow("src", src);
    imshow("mask", mask);

    waitKey();
    destroyAllWindows();
}