#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

void mouse_event(int event, int x, int y, int flags, void*);        //마우스 이벤트 처리를 위한 함수
Point image_cut(Point start, Point end);        //Point 클래스를 통해 이미지의 너비와 높이를 가져오기 위함
Mat calcGrayHist(const Mat& img);           //히스토그램을 구하는 함수
Mat getGrayHistImage(const Mat& hist);      //구한 히스토그램을 그래프로 표시해주는 함수

Point startPoint;       //이미지의 시작점
Point endPoint;         //이미지의 끝 점
int main()
{
    Mat original = imread("sample.jpeg", IMREAD_COLOR);     //칼라로 이미지를 읽어오기
    Mat gray;
    cvtColor(original, gray, COLOR_BGR2GRAY);       //칼라로 읽어온 이미지를 그레이스케일로 전환

    imshow("original", original);
    waitKey();
    destroyAllWindows();
    imshow("gray", gray);
    setMouseCallback("gray", mouse_event);      //마우스 이벤트 처리

    waitKey();
    cout << "S, " << startPoint << endl << "E, " << endPoint << endl;       //마우스 이벤트 처리를 통해서 startPoint와 endPoint를 구해 표시해줌

    Point WH = image_cut(startPoint, endPoint);     //image_cut함수를 통해 받은 수치를 WH라는 Point 클래스에 대입
    Mat cut = gray(Range(startPoint.y, startPoint.y + WH.y), Range(startPoint.x, startPoint.x + WH.x)); //cut이라는 Mat 객체에 구한 이미지 적용
                                //이때 먼저 오는 Range는 이미지의 열(col)의 크기에 대해. 즉 높이에 대해 연산하며
                                //두번째로 오는 Range는 이미지의 행(row)의 크기. 너비에 대해 연산한다.
                                //마우스 이벤트 처리를 통해서 이미지에서의 원하는 영역을 잘라내고 잘라낸 이미지를 cut 객체 안에 넣는 과정이다. 
    imshow("cut", cut);
    waitKey();
    
    Mat hist = calcGrayHist(cut);
    Mat hist_img = getGrayHistImage(hist);      //히스토그램 그래프 구현

    imshow("cut hist", hist_img);
    waitKey();
    destroyAllWindows();
}

void mouse_event(int event, int x, int y, int flags, void*)     //마우스 버튼이 눌렸을때 시작점, 떨어졌을때 끝점을 개개의 startPoint, endPoint에 입력받는다
{
    switch(event){
    case EVENT_LBUTTONDOWN:     //마우스 왼쪽 버튼이 눌렸을 때
        startPoint = Point(x, y);
        cout << "startPoint : " << startPoint << endl;
        break;
    case EVENT_LBUTTONUP:       //마우스 왼쪽 버튼이 떨어졌을 때
        endPoint = Point(x, y);
        cout << "endPoint : " << endPoint << endl;
        break;
    }
}

Point image_cut(Point start, Point end)     //두 개의 Point를 입력받고 이를 통해 widht와 height를 계산하여 이를 하나의 Point로 변환해서 return한다
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