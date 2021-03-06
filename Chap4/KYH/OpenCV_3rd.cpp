#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void Scalar0p()
{
    Scalar gray = 128;
    cout << "gray : " << gray << endl;
    
    Scalar yellow(0, 255, 255);
    cout << "yellow : " << yellow << endl;

    Mat img1(256, 256, CV_8UC3, yellow);

    for (int i = 0; i < 4; ++i)
        cout << yellow[i] << endl;

    waitKey();
}

void printMat(InputArray _mat)
{
    Mat mat = _mat.getMat();
    cout << mat << endl;
}

void InputArrayOp()
{
    uchar data1[] = {1, 2, 3, 4, 5, 6};
    Mat mat1(2, 3, CV_8U, data1);
    printMat(mat1);

    vector<float> vec1 = {1.2f, 3.4f, -2.1f};
    printMat(vec1);
    
}

void camera_in()
{
    VideoCapture cap(0);

    if(!cap.isOpened())
    {
        cerr << "Camera open failed" << endl;
        return;
    }

    cout << "Frame width : " << cvRound(cap.get(CAP_PROP_FRAME_WIDTH)) << endl;
    cout << "Frame height : " << cvRound(cap.get(CAP_PROP_FRAME_HEIGHT)) << endl;

    Mat frame, inversed;
    while(true) 
    {
        cap >> frame;
        if (frame.empty())
            break;
        
        inversed = ~frame;

        imshow("frame", frame);
        imshow("inversed", inversed);

        if (waitKey(10) == 27)
            break;
    }
}

void video_in()
{
    VideoCapture cap("./output.avi");

    if (! cap.isOpened())
    {
        cerr << "Video open failed" << endl;
        return;
    }

    cout << "Frame width : " << cvRound(cap.get(CAP_PROP_FRAME_WIDTH)) << endl;
    cout << "Frame height : " << cvRound(cap.get(CAP_PROP_FRAME_HEIGHT)) << endl;
    cout << "Frame count : " << cvRound(cap.get(CAP_PROP_FRAME_COUNT)) << endl;

    double fps = cap.get(CAP_PROP_FPS);
    cout << "FPS : " << fps << endl;

    int delay = cvRound(1000 / fps);

    Mat frame, inversed;
    while(true)
    {
        cap >> frame;
        if(frame.empty())
            break;
        
        inversed = ~frame;
        
        imshow("frame", frame);
        imshow("inversed", inversed);

        if (waitKey(delay) == 27)
            break;
    }
    destroyAllWindows();
}

void camera_in_video_out()
{
    VideoCapture cap(0);

    if(!cap.isOpened())
    {
        cerr << "Camera open failed" << endl;
        return;
    }

    int w = cvRound(cap.get(CAP_PROP_FRAME_WIDTH));
    int h = cvRound(cap.get(CAP_PROP_FRAME_HEIGHT));
    double fps = cap.get(CAP_PROP_FPS);

    int fourcc = VideoWriter::fourcc('D', 'I', 'V', 'X');
    int delay = cvRound(1000 / fps);

    VideoWriter outputVideo("output.avi", fourcc, fps, Size(w, h));

    if (!outputVideo.isOpened())
    {
        cout << "File open failed" << endl;
        return;
    }

    Mat frame, inversed;
    while (true)
    {
        cap >> frame;
        if(frame.empty())
            break;

        inversed = ~frame;
        outputVideo << inversed;
        
        imshow("frame", frame);
        imshow("inversed", inversed);

        if (waitKey(delay) == 27)
            break;
    }

    destroyAllWindows();
}

void drawLines()
{
    Mat img(400, 400, CV_8UC3, Scalar(255,255,255));
    
    line(img, Point(50, 50), Point(200, 50), Scalar(0,0,255));
    line(img, Point(50, 100), Point(200, 100), Scalar(255,0,255), 3);
    line(img, Point(50, 150), Point(200, 150), Scalar(255,0,0) , 10);
    
    line(img, Point(250, 50), Point(350, 100), Scalar(0,0,255), 1, LINE_4);
    line(img, Point(250, 70), Point(350, 120), Scalar(255,0,255), 1, LINE_8);
    line(img, Point(250, 90), Point(350, 140), Scalar(255,0,0), 1, LINE_AA);
    
    arrowedLine(img, Point(50, 200), Point(150, 200), Scalar(0,0,255), 1);
    arrowedLine(img, Point(50, 250), Point(350, 250), Scalar(255,0,255), 1);
    arrowedLine(img, Point(50, 300), Point(350, 300), Scalar(255,0,0), 1, LINE_8, 0, 0.05);
    
    drawMarker(img, Point(50, 350), Scalar(0, 0, 255), MARKER_CROSS);
    drawMarker(img, Point(100, 350), Scalar(0, 0, 255), MARKER_TILTED_CROSS);
    drawMarker(img, Point(150, 350), Scalar(0, 0, 255), MARKER_STAR);
    drawMarker(img, Point(200, 350), Scalar(0, 0, 255), MARKER_DIAMOND);
    drawMarker(img, Point(250, 350), Scalar(0, 0, 255), MARKER_SQUARE);
    drawMarker(img, Point(300, 350), Scalar(0, 0, 255), MARKER_TRIANGLE_UP);
    drawMarker(img, Point(350, 350), Scalar(0, 0, 255), MARKER_TRIANGLE_DOWN);
    
    imshow("img", img);
    waitKey(0);
    
    destroyAllWindows();
}

void drawPolys()
{
    Mat img(400, 400, CV_8UC3, Scalar(255, 255, 255));
    
    rectangle(img, Rect(50, 50, 100, 50), Scalar(0, 0, 255), 2);
    rectangle(img, Rect(50, 150, 100, 50), Scalar(0, 0, 128), -1);
    
    circle(img, Point(300, 120), 30, Scalar(255, 255, 0), -1, LINE_AA);
    circle(img, Point(300, 120), 60, Scalar(255, 0, 0), 3, LINE_AA);
    
    ellipse(img, Point(120, 300), Size(60, 30), 20, 0, 270, Scalar(255, 255, 0), -1, LINE_AA);
    ellipse(img, Point(120, 300), Size(100, 50), 20, 0, 360, Scalar(0, 255, 0), 2, LINE_AA);
        
    vector<Point> pts;
    pts.push_back(Point(250, 250));
    pts.push_back(Point(300, 250));
    pts.push_back(Point(300, 300));
    pts.push_back(Point(350, 300));
    pts.push_back(Point(350, 350));
    pts.push_back(Point(250, 350));
    
    polylines(img, pts, true, Scalar(255, 0 ,255), 2);
    
    imshow("img", img);
    waitKey(0);
    
    destroyAllWindows();
}

void drawText1()
{
    Mat img(500, 800, CV_8UC3, Scalar(255, 255, 255));
    
    putText(img, "FONT_HERSHEY_SIMPLEX", Point(20, 50), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 0, 255));
    putText(img, "FONT_HERSHEY_PLAIN", Point(20, 100), FONT_HERSHEY_PLAIN, 1, Scalar(0, 0, 255));
    putText(img, "FONT_HERSHEY_DUPLEX", Point(20, 150), FONT_HERSHEY_DUPLEX, 1, Scalar(0, 0, 255));
    putText(img, "FONT_HERSHEY_COMPLEX", Point(20, 200), FONT_HERSHEY_COMPLEX, 1, Scalar(255, 0, 0));
    putText(img, "FONT_HERSHEY_TRIPLEX", Point(20, 250), FONT_HERSHEY_TRIPLEX, 1, Scalar(255, 0, 0));
    putText(img, "FONT_HERSHEY_COMPLEX_SMALL", Point(20, 300), FONT_HERSHEY_COMPLEX_SMALL, 1, Scalar(255, 0, 0));
    putText(img, "FONT_HERSHEY_COMPLEX_SIMPLEX", Point(20, 350), FONT_HERSHEY_SCRIPT_SIMPLEX, 1, Scalar(255, 0, 255));
    putText(img, "FONT_HERSHEY_COMPLEX_COMPLEX", Point(20, 400), FONT_HERSHEY_SCRIPT_COMPLEX, 1, Scalar(255, 0, 255));
    putText(img, "FONT_HERSHEY_COMPLEX | FONT_ITALIC", Point(20, 450), FONT_HERSHEY_COMPLEX | FONT_ITALIC, 1, Scalar(255, 0, 0));
    
    imshow("img", img);
    waitKey(0);
}

void drawText2()
{
    Mat img(200, 640, CV_8UC3, Scalar(255, 255, 255));
    
    const String text = "Hello, OpenCV";
    int fontFace = FONT_HERSHEY_TRIPLEX;
    double fontScale = 2.0;
    int thickness = 1;
    
    Size sizeText = getTextSize(text, fontFace, fontScale, thickness, 0);
    Size sizeImg = img.size();
    
    Point org((sizeImg.width - sizeText.width) / 2, (sizeImg.height + sizeText.height) / 2);
    putText(img, text, org, fontFace, fontScale, Scalar(255, 0, 0), thickness);
    rectangle(img, org, org + Point(sizeText.width, -sizeText.height), Scalar(255, 0, 0), 1);
    
    imshow("img", img);
    waitKey(0);
    
    destroyAllWindows();
}

Mat global_img;
Point ptOld;
void on_mouse(int event, int x, int y, int flags, void*)
{
    switch(event){
        case EVENT_LBUTTONDOWN:
            ptOld = Point(x, y);
            cout<<"EVENT_LBUTTONDOWN: "<<x<<", "<<y<<endl;
            break;
        case EVENT_LBUTTONUP:
            cout<<"EVENT_LBUTTONUP: "<<x<<", "<<y<<endl;
            break;
        case EVENT_MOUSEMOVE:
            if(flags & EVENT_FLAG_LBUTTON){
                line(global_img, ptOld, Point(x,y), Scalar(0,255,255), 2);
                imshow("img", global_img);
                ptOld = Point(x,y);
            }
            break;
        default:
            break;
    }
}

void on_level_change(int pos, void* userdata)
{
    Mat img = *(Mat*)userdata;

    img.setTo(pos* 16);
    imshow("image", img);
}

String filename = "mydata.json";
void writeData()
{
	String name = "Jane";
	int age = 10;
	Point pt1(100, 200);
	vector<int> scores = { 80, 90, 50 };
	Mat mat1 = (Mat_<float>(2, 2) << 1.0f, 1.5f, 2.0f, 3.2f);

	FileStorage fs;
	fs.open(filename, FileStorage::WRITE);

	if (!fs.isOpened()) {
		cerr << "File open failed!" << endl;
		return;
	}

	fs << "name" << name;
	fs << "age" << age;
	fs << "point" << pt1;
	fs << "scores" << scores;
	fs << "data" << mat1;

	fs.release();
}

void readData()
{
	String name;
	int age;
	Point pt1;
	vector<int> scores;
	Mat mat1;

	FileStorage fs(filename, FileStorage::READ);

	if (!fs.isOpened()) {
		cerr << "File open failed!" << endl;
		return;
	}
	
	fs["name"] >> name;
	fs["age"] >> age;
	fs["point"] >> pt1;
	fs["scores"] >> scores;
	fs["data"] >> mat1;

	fs.release();

	cout << "name: " << name << endl;
	cout << "age: " << age << endl;
	cout << "point: " << pt1 << endl;
	cout << "scores: " << Mat(scores).t() << endl;
	cout << "data:\n" << mat1 << endl;
}

void mask_setTo()
{
	Mat src = imread("lenna.bmp", IMREAD_COLOR);
	Mat mask = imread("mask_smile.bmp", IMREAD_GRAYSCALE);

	if (src.empty() || mask.empty()) {
		cerr << "Image load failed!" << endl;
		return;
	}

	src.setTo(Scalar(0, 255, 255), mask);

	imshow("src", src);
	imshow("mask", mask);

	waitKey(0);
	destroyAllWindows();
}

void mask_copyTo()
{
	Mat src = imread("airplane.bmp", IMREAD_COLOR);
	Mat mask = imread("mask_plane.bmp", IMREAD_GRAYSCALE);
	Mat dst = imread("field.bmp", IMREAD_COLOR);

	if (src.empty() || mask.empty() || dst.empty()) {
		cerr << "Image load failed!" << endl;
		return;
	}

	src.copyTo(dst, mask);

	imshow("src", src);
	imshow("dst", dst);
	imshow("mask", mask);

	waitKey(0);
	destroyAllWindows();
}

void time_inverse()
{
	Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);

	if (src.empty()) {
		cerr << "Image load failed!" << endl;
		return;
	}

	Mat dst(src.rows, src.cols, src.type());

	TickMeter tm;
	tm.start();

	for (int j = 0; j < src.rows; j++) {
		for (int i = 0; i < src.cols; i++) {
			dst.at<uchar>(j, i) = 255 - src.at<uchar>(j, i);
		}
	}

	tm.stop();
	cout << "Image inverse took " << tm.getTimeMilli() << "ms." << endl;
}

void useful_func()
{
	Mat img = imread("lenna.bmp", IMREAD_GRAYSCALE);

	cout << "Sum: " << (int)sum(img)[0] << endl;
	cout << "Mean: " << (int)mean(img)[0] << endl;

	double minVal, maxVal;
	Point minPos, maxPos;
	minMaxLoc(img, &minVal, &maxVal, &minPos, &maxPos);

	cout << "minVal: " << minVal << " at " << minPos << endl;
	cout << "maxVal: " << maxVal << " at " << maxPos << endl;

	Mat src = Mat_<float>({ 1, 5 }, { -1.f, -0.5f, 0.f, 0.5f, 1.f });

	Mat dst;
	normalize(src, dst, 0, 255, NORM_MINMAX, CV_8UC1);

	cout << "src: " << src << endl;
	cout << "dst: " << dst << endl;

	cout << "cvRound(2.5): " << cvRound(2.5) << endl;
	cout << "cvRound(2.51): " << cvRound(2.51) << endl;
	cout << "cvRound(3.4999): " << cvRound(3.4999) << endl;
	cout << "cvRound(3.5): " << cvRound(3.5) << endl;
}



int main()
{
    Scalar0p();
    InputArrayOp();
    camera_in();
    video_in();
    camera_in_video_out();
    drawLines();
    drawPolys();
    drawText1();
    drawText2();

    // on_mouse
    global_img = imread("./sample.jpg");
   
    if(global_img.empty()){
        cerr<<"Image load failed!"<<endl;
        return -1;
    }
   
    namedWindow("img");
    setMouseCallback("img", on_mouse);
   
    imshow("img", global_img);
    waitKey();

    Mat img = Mat::zeros(400, 400, CV_8UC1);

    namedWindow("image");
    createTrackbar("level", "image", 0, 16, on_level_change, (void*)&img);

    imshow("image", img);
    waitKey();

    writeData();
    readData();

    mask_setTo();
    mask_copyTo();
    time_inverse();
    useful_func();
}

