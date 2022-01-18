#include <opencv2/opencv.hpp>


int main() {
   cv::Mat mat(200, 200, CV_8UC3); // cv 헤더 안의 Mat 클래스로 mat 변수 선언
   mat(cv::Rect(0, 0, 100, 200)) = cv::Vec3b(255, 255, 255); //mat 변수에 값 대입
   //cv::Rect(x_coordinate, y_coordinate, width, height) (x,y)좌표에 width*height크기의 창을 띄움
   //cv::Vec3b(blue, green, red)
   cv::imshow("mat", mat); // "mat"이라는 창에 mat변수 출력
   cv::waitKey(0); // key값이 들어오기 전까지 괄호 안의 시간만큼 대기, 0은 무한 대기
   return 0;
}
