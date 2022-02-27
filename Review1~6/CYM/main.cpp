#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

void mouse_event(int event, int x, int y, int flags, void*);
Point image_cut(Point start, Point end);
Mat calcGrayHist(const Mat& img);
Mat getGrayHistImage(const Mat& hist);
void on_brightness(int pos, void* userdata);

Point startPoint;
Point endPoint;

int main()
{
    Mat original = imread("tycan.jpeg", IMREAD_COLOR);
    Mat gray = imread("tycan.jpeg", IMREAD_GRAYSCALE);

    imshow("original", original);
    cout << "아무 키나 누르시오" << endl;
    waitKey();
    imshow("gray", gray);

    cout << "마우스 왼쪽 버튼으로 편집 할 부분을 드래그하여 자르시오." << endl;
    setMouseCallback("gray", mouse_event);
    waitKey();
    cout << "S, " << startPoint << endl << "E, " << endPoint << endl;

    Point WH = image_cut(startPoint, endPoint);
    Mat cut = gray(Range(startPoint.y, startPoint.y + WH.y), Range(startPoint.x, startPoint.x + WH.x));
    imshow("cut", cut);
    
    Mat hist = calcGrayHist(cut);
    Mat hist_img = getGrayHistImage(hist);
    imshow("cut hist", hist_img);

    namedWindow("brightness_change");
	createTrackbar("Brightness", "brightness_change", 0, 100, on_brightness, (void*)&cut);
	on_brightness(0, (void*)&cut);

    float alpha = 1.f;
	Mat contrast_cut = cut + (cut - 128) * alpha;
	imshow("contrast_cut", contrast_cut);

    Mat hist2 = calcGrayHist(contrast_cut);
    Mat hist_img2 = getGrayHistImage(hist2);
    imshow("cut hist2", hist_img2);

    waitKey();
    destroyAllWindows();
}

void on_brightness(int pos, void* userdata)
{
	Mat cut = *(Mat*)userdata;
	Mat brightness_change = cut + pos;

	imshow("brightness_change", brightness_change);
}

void mouse_event(int event, int x, int y, int flags, void*)
{
    switch(event){
    case EVENT_LBUTTONDOWN:
        startPoint = Point(x, y);
        cout << "startPoint : " << startPoint << endl;
        break;
    case EVENT_LBUTTONUP:
        endPoint = Point(x, y);
        cout << "endPoint : " << endPoint << endl;
        break;
    }
}

Point image_cut(Point start, Point end)
{
    int width = end.x - start.x;
    int height = end.y - start.y;

    Point result(width, height);
    cout << result << endl;
    return result;
}

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