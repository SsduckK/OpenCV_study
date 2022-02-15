#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

#if 0
int main()
{
    Mat src = imread("sample2.png");
    Mat dst1;
    Mat dst2;
    Mat dst3;
    Mat other;

    Mat kernel = Mat::ones(3, 3, CV_32F);
    Mat Bigkernel = Mat::ones(5, 5, CV_32F);
    filter2D(src, dst1, CV_8U, kernel, Point(-1, -1), (0, 0), BORDER_DEFAULT);
    filter2D(src, dst2, CV_8U, kernel, Point(-1, -1), (128, 128), BORDER_DEFAULT);
    filter2D(src, dst3, CV_8U, kernel, Point(-1, -1), (64, 64), BORDER_DEFAULT);

    filter2D(src, other, CV_8U, Bigkernel, Point(-1, -1), (0, 0), BORDER_DEFAULT);

    imshow("original", src);
    imshow("result1", dst1);
    imshow("result2", dst2);
    imshow("result3", dst3);
    imshow("big", other);
    waitKey();
    destroyAllWindows;
}
#endif

#if 0
int main()
{
    Mat src = imread("sample2.png", IMREAD_GRAYSCALE);
    Mat dst;

    float data[] = {-1, -1, 0, -1, 0, 1, 0, 1, 1};
    Mat emboss(3, 3, CV_32FC1, data);

    filter2D(src, dst, -1, emboss, Point(-1, -1), 128);

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
    Mat dst;

    imshow("src", src);
    for (int size = 3; size <= 7; size += 2){
        blur(src, dst, Size(size, size));

        imshow("dst", dst);
        waitKey();
    }

    destroyAllWindows();
}
#endif

#if 0
int main()
{
    Mat src = imread("sample2.png", IMREAD_GRAYSCALE);

    Mat dst1;
    Mat dst2;
    Mat dst3;

    imshow("src", src);

    GaussianBlur(src, dst1, Size(), 3);
    GaussianBlur(src, dst2, Size(), 5);
    GaussianBlur(src, dst3, Size(), 7);

    imshow("dst1", dst1);
    imshow("dst2", dst2);
    imshow("dst3", dst3);

    waitKey();
    destroyAllWindows();
}
#endif

#if 0
int main()
{
    Mat src = imread("sample2.png", IMREAD_GRAYSCALE);

    Mat dst1, dst2, dst3;
    Mat sharp1, sharp2, sharp3;
    imshow("src", src);

    GaussianBlur(src, dst1, Size(), 3);
    GaussianBlur(src, dst2, Size(), 5);
    GaussianBlur(src, dst3, Size(), 7);

    float alpha = 1.f;
    sharp1 = (1 + alpha) * src - alpha * dst1;
    sharp2 = (1 + alpha) * src - alpha * dst2;
    sharp3 = (1 + alpha) * src - alpha * dst3;

    imshow("dst1", dst1);
    imshow("dst2", dst2);
    imshow("dst3", dst3);
    imshow("sharp1", sharp1);
    imshow("sharp2", sharp2);
    imshow("sharp3", sharp3);
    
    waitKey();
    destroyAllWindows();
}
#endif

#if 0
int main()
{
    Mat src = imread("sample2.png", IMREAD_GRAYSCALE);

    imshow("src", src);

    Mat noise(src.size(), CV_32SC1);
    randn(noise, 0, 30);

    Mat dst;
    add(src, noise, dst, Mat(), CV_8U);

    imshow("dst", dst);
    waitKey();
    destroyAllWindows();
}
#endif

#if 0
int main()
{
    Mat src = imread("sample2.png", IMREAD_GRAYSCALE);

    Mat Noise(src.size(), CV_32SC1);
    randn(Noise, 0, 15);
    add(src, Noise, src, Mat(), CV_8U);

    Mat dst1;
    GaussianBlur(src, dst1, Size(), 5);

    Mat dst2;
    bilateralFilter(src, dst2, -1, 10, 5);

    imshow("src", src);
    imshow("dst1", dst1);
    imshow("dst2", dst2);

    waitKey();
    destroyAllWindows();
}
#endif


int main()
{
    Mat src = imread("sample2.png", IMREAD_GRAYSCALE);

    int num = (int)(src.total() * 0.1);
    for (int i = 0; i < num; i ++){
        int x = rand() % src.cols;
        int y = rand() % src.rows;

        src.at<uchar>(y, x) = (i % 2) * 255;
    }

    Mat dst1;
    GaussianBlur(src, dst1, Size(), 1);

    Mat dst2;
    medianBlur(src, dst2, 3);
    
    imshow("src", src);
    imshow("dst1", dst1);
    imshow("dst2", dst2);

    waitKey();
    destroyAllWindows();
}