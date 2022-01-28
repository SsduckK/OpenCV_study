#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

#if 0
int main()
{
    Mat img1 = imread("sample2.png", IMREAD_COLOR);
    Mat img2 = imread("sample2.png", IMREAD_GRAYSCALE);
    Mat img3 = imread("sample2.png", IMREAD_COLOR);
    Mat img4;

    cvtColor(img3, img4, COLOR_BGR2GRAY);
    imshow("img1", img1);
    imshow("img2", img2);
    imshow("img3", img3);
    imshow("img4", img4);
    waitKey();
    destroyAllWindows();
}
#endif

#if 0
int main()
{
    Mat src = imread("sample2.png", IMREAD_GRAYSCALE);

    if(src.empty()){
        cerr << "Image load failed" << endl;
        return 0;
    }

    Mat dst = src + 100;

    imshow("src", src);
    imshow("dst", dst);
    waitKey();

    destroyAllWindows();
}
#endif

#if 0
int main()
{
    Mat src = imread("sample2.png", IMREAD_GRAYSCALE);

    if(src.empty())
    {
        cerr << "Image load failed" << endl;
    }

    float alpha = 1.f;
    Mat dst = src + (src - 128) * alpha;

    imshow("src", src);
    imshow("dst", dst);

    waitKey();
    destroyAllWindows();
}
#endif


Mat calcGrayHist(const Mat& img)
{
    CV_Assert(img.type() == CV_8UC1);

    Mat hist;
    int channels[] = {0};
    int dims = 1;
    const int histSize[] = { 256 };
    float graylevel[] = { 0, 256 };
    const float* ranges[] = { graylevel };

    calcHist(&img, 1, channels, noArray(), hist, dims, histSize, ranges);

    return hist;
}

Mat getGrayHistImage(const Mat& hist)
{
    CV_Assert(hist.type() == CV_32FC1);
    CV_Assert(hist.size() == Size(1, 256));

    double histMax;
    minMaxLoc(hist, 0, &histMax);

    Mat imgHist(100, 256, CV_8UC1, Scalar(255));

    for (int i = 0; i< 256; i++){
        line(imgHist, Point(i, 100),
        Point(i, 100 - cvRound(hist.at<float>(i, 0)*100/histMax)), Scalar(0));
    }

    return imgHist;
}

#if 0
int main()
{
    Mat src = imread("sample1.jpg", IMREAD_GRAYSCALE);
    Mat hist = calcGrayHist(src);
    Mat hist_img = getGrayHistImage(hist);

    imshow("src", src);
    imshow("srcHist", hist_img);

    waitKey();
    destroyAllWindows();
}
#endif

#if 0
int main()
{
    Mat src = imread("sample1.jpg", IMREAD_GRAYSCALE);

    double gmin, gmax;
    minMaxLoc(src, &gmin, &gmax);

    Mat dst = (src - gmin) * 255 / (gmax - gmin);

    imshow("src", src);
    imshow("srcHist", getGrayHistImage(calcGrayHist(src)));

    imshow("dst", dst);
    imshow("dstHist", getGrayHistImage(calcGrayHist(dst)));

    waitKey();
    destroyAllWindows();
}
#endif


int main()
{
    Mat src = imread("sample1.jpg", IMREAD_GRAYSCALE);
    

    Mat dst;
    equalizeHist(src, dst);

    imshow("src", src);
    imshow("srcHIst", getGrayHistImage(calcGrayHist(src)));

    imshow("dst", dst);
    imshow("dstHist", getGrayHistImage(calcGrayHist(dst)));

    waitKey();
    destroyAllWindows();
}