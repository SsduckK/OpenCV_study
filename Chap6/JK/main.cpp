#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

#if 0
int main()
{
    Mat src1 = imread("sample1.jpeg", IMREAD_GRAYSCALE);
    Mat src2 = imread("sample2.png", IMREAD_GRAYSCALE);

    cout << src1.size() << endl;
    cout << src2.size() << endl;

    resize(src1, src1, Size(300, 300));
    resize(src2, src2, Size(300, 300));

    Mat dst;
    add(src1, src2, dst);

    imshow("src1", src1);
    imshow("src2", src2);
    imshow("image", dst);
    waitKey();
    destroyAllWindows();
}

#endif

#if 0
int main()
{
    Mat src1 = imread("sample2.png", IMREAD_GRAYSCALE);
    Mat src2 = imread("square.png", IMREAD_GRAYSCALE);
    
    resize(src1, src1, Size(src2.size()));

    Mat dst;
    absdiff(src1, src2, dst);

    imshow("src1", src1);
    imshow("src2", src2);
    imshow("image", dst);
    waitKey();
    destroyAllWindows(); 
}
#endif


int main()
{
    Mat src1 = imread("sample2.png", IMREAD_GRAYSCALE);
    Mat src2 = imread("square.png", IMREAD_GRAYSCALE);
    
    resize(src1, src1, Size(src2.size()));

    Mat dstAND, dstOR, dstXOR, dstNOT;

    bitwise_and(src1, src2, dstAND);
    bitwise_or(src1, src2, dstOR);
    bitwise_xor(src1, src2, dstXOR);
    bitwise_not(src1, dstNOT);

    imshow("AND", dstAND);
    imshow("OR", dstOR);
    imshow("XOR", dstXOR);
    imshow("NOT", dstNOT);

    waitKey();
    destroyAllWindows();
}
