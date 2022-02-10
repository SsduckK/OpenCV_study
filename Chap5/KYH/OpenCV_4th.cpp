#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;


void brightness()
{
    Mat src = imread("sample.jpg", IMREAD_GRAYSCALE);
    
    if(src.empty())
    {
        std::cerr << "Image load failed." << std::endl;
        return;
    }
    
    Mat dst = src + 100;
    imshow("src", src);
    imshow("dst", dst);
    waitKey();
    
    destroyAllWindows();
}

void brightness2()
{
    Mat src = imread("sample.jpg", IMREAD_GRAYSCALE);
    
    if(src.empty())
    {
        std::cerr << "Image load failed" << std::endl;
        return;
    }
    
    Mat dst(src.rows, src.cols, src.type()); // src의 rows, cols, type을 직접적으로 받아서 dst 행렬 생성
    
    for (int j = 0; j < src.rows; j++)
        for (int i = 0; i < src.cols; i++)
            dst.at<uchar>(j, i) = src.at<uchar>(j, i) + 100; // 반복 연산으로 해당하는 픽셀 하나 하나에 100을 더함
    
    imshow("src", src);
    imshow("dst", dst);
    waitKey();
    
    destroyAllWindows();
}

void on_brightness(int pos, void* userdata)
{
    Mat src = *(Mat*)userdata;
    Mat dst = src + pos;
    
    imshow("dst", dst);
}

void brightness3()
{
    Mat src = imread("sample.jpg", IMREAD_GRAYSCALE);
    
    if(src.empty())
    {
        std::cerr << "Image load failed" << std::endl;
        return;
    }
    
    namedWindow("dst");
    createTrackbar("Brightness", "dst", 0, 100, on_brightness, (void*)&src);
    on_brightness(0, (void*)&src);
    
    waitKey();
    destroyAllWindows();
}

void contrast()
{
    Mat src = imread("sample.jpg", IMREAD_GRAYSCALE);
    
    if(src.empty())
    {
        std::cerr << "Image load failed" << std::endl;
        return;
    }

    float s = 2.f;
    Mat dst = s * src;
    imshow("src", src);
    imshow("dst", dst);

    waitKey();
    destroyAllWindows();
}

void contrast2()
{
    Mat src = imread("sample.jpg", IMREAD_GRAYSCALE);

    if(src.empty())
    {
        std::cerr << "Image load failed" << std::endl;
        return;
    }

    float alpha = 1.f;
    Mat dst = src + (src - 128) * alpha;

    imshow("src", src);
    imshow("dst", dst);

    waitKey();
    destroyAllWindows();
}

Mat calcGrayHist(const Mat& img)
{
	CV_Assert(img.type() == CV_8UC1);

	Mat hist;
	int channels[] = { 0 };
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
	for (int i = 0; i < 256; i++) {
		line(imgHist, Point(i, 100), Point(i, 100 - cvRound(hist.at<float>(i, 0) * 100 / histMax)), Scalar(0));
	}

	return imgHist;
}

void histgoram_stretching()
{
	Mat src = imread("sample.bmp", IMREAD_GRAYSCALE);

	if (src.empty()) {
		std::cerr << "Image load failed!" << std::endl;
		return;
	}

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

void histgoram_equalization()
{
	Mat src = imread("sample.jpg", IMREAD_GRAYSCALE);

	if (src.empty()) {
		std::cerr << "Image load failed!" << std::endl;
		return;
	}

	Mat dst;
	equalizeHist(src, dst);

	imshow("src", src);
	imshow("srcHist", getGrayHistImage(calcGrayHist(src)));

	imshow("dst", dst);
	imshow("dstHist", getGrayHistImage(calcGrayHist(dst)));

	waitKey();
	destroyAllWindows();
}


int main()
{
    brightness();
    brightness2();
    brightness3();
    contrast();
    contrast2();

    Mat src = imread("sample.jpg", IMREAD_GRAYSCALE);
    Mat hist = calcGrayHist(src);
    Mat hist_img = getGrayHistImage(hist);

    imshow("src", src);
    imshow("srcHist", hist_img); // == imshow("srcHist", getGrayHistImage(calcGrayHist(src)));
    waitKey();
    
    destroyAllWindows();
    histgoram_stretching();
    histgoram_equalization();
}