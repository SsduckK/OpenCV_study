#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

#if 0
void on_threshold(int pos, void* userdata);

int main(int argc, char* argv[])
{
    Mat src;

    if (argc < 2)
        src = imread("sample3.jpg", IMREAD_GRAYSCALE);
    else
        src = imread(argv[1], IMREAD_GRAYSCALE);

    resize(src, src, Size(), 0.5, 0.5);
    imshow("src", src);
    namedWindow("dst");
    createTrackbar("Threshhold", "dst", 0, 255, on_threshold, (void*)&src);
    //setTrackbarPos("Threshold", "dst", 128);

    waitKey();
    return 0;
}

void on_threshold(int pos, void* userdata)
{
    Mat src = *(Mat*)userdata;

    int bsize = pos;
    if (bsize % 2 == 0) bsize--;
    if (bsize < 3) bsize = 3;

    Mat dst;
    //threshold(src, dst, pos, 255, THRESH_BINARY);
    adaptiveThreshold(src, dst, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, bsize, 5);

    imshow("dst", dst);
}
#endif

int main()
{
    Mat src = imread("sample4.bmp", IMREAD_GRAYSCALE);

    Mat bin;
    threshold(src, bin, 0, 255, THRESH_BINARY | THRESH_OTSU);

    Mat dst1, dst2;
    erode(bin, dst1, Mat());
    dilate(bin, dst2, Mat());

    imshow("src", src);
    imshow("bin", bin);
    imshow("erode", dst1);
    imshow("dilate", dst2);

    waitKey();
    destroyAllWindows();
}