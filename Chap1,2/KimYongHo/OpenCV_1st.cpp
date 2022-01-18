#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    Mat img; //Mat class img 변수 선언
    img = cv::imread("../sample.jpg"); // cv namespace의 imread 함수를 사용하여, sample.png 파일을 img 변수에 저장
    if (img.empty())
    {
        cout << "x" << endl;
        return 0;
    }
    namedWindow("image"); // namedWindow()함수를 사용하여 화면에 새로운 창을 생성하고 그 창에 image라는 이름을 부여
    imshow("image", img); // imshow()함수를 사용하여, image창에 img 객체의 sample.png를 전달
    waitKey(); // 무작위 입력이 들어오기 전까지 정지
    return 0;
}