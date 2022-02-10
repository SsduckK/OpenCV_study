### Point_ 클래스

```
template<typename _Tp> class Point_
{
    Point_(); // x,y 좌표를 0으로 초기화는 생성자
    Point_(_Tp _x, Tp _y); // (_x, _y)좌표를 인자로 받아서 초기화한다.
    Point_(const Point_& pt); // 복사 생성자 (얕은 복사)

    Point_&operarot = (const Point_& pt); // 대입 연산자 재정의

    _Tp dot(const Point_& pt) const; // 두 점 사이를 내적해서 반환한다. -> 두 점의 x, y값을 각각 곱해서 전달한다. 만약, 전달받는 계체가 int형이라면, 연산의 결과인 x, y값을 더해서 전달한다.
    double ddot(const Point_& pt) const; // 두 점 사이를 외적해서 반환한다.
    double cross(const Point_& pt) const; // 두 점 사이를 외적해서 반환한다.
    bool inside(const Rect_<Tp>& r) const; // 점의 좌표가 r안에 있으면 true를 반환합니다.

    _Tp x, y; // x, y 좌표
};

typedef Point_<int>     Point2i; // int형 Point
typedef Point_<int64>   Point2l; // int64형(부호가 있는 8바이트 int형) Point
typedef Point_<float>   Point2f; // float형 Point
typedef Point_<double>  Point2d; // double형 Point
typedef Point2i         Point; // int형 자료형은 자주 쓰이기 때문에 Point로 재정의되었다. 따라서 기본 Point형으로 선언하면 int형 Point로 정의된다.
Point(x, y) = Point(a, b) + Point(c, d); // x에는 a와 c를 더한 값이, y에는 b와 d를 더한 값이 저장된다.
Point(x, y) = Point(a, b) * 2; // x에는 a * 2의 값이, y에는 b * 2의 값이 저장된다.
```





### Size_ 클래스

``` 
tempalte<typename _Tp> class Size_
{
public:
    Size_(); // width, height를 0으로 초기화하는 생성자
    Size_(_Tp _width, _Tp _height); // _width, _height를 인자로 받아서 초기화한다
    Size_(const Size_& sz); // 복사 생성자(얕은 복사)

    Size_& operator = (const Size_& sz); // 대입 연산자 재정의

    _Tp area() const; // 사각형 크기에 해당하는 면적(width * height)를 반환합니다.
    bool empty() const; // 유효하지 않은 크기이면 true를 반환합니다.

    _Tp width, height; // x, y는 사각형 좌측 상단 점의 좌표, width, height는 가로 길이와 세로 길이를 나타낸다.
};

typedef Size_<int>      Size2i; // int형 Size
typedef Size_<int64>    Size2l; // int64형 Size
typedef Size_<float>    Size2f; // float형 Size
typedef Size_<double>   Size2d; // double형 Size
typedef Size2i          Size; // int형 Size

Size s1 = 1, s2 = 2; // s1, s2 선언
Size s3 = s1 + s2; // s3에 s1 + s2값이 저장된다.
size s4 = s1 * s2; // s4에 s1 * s2 값이 저장된다.
```





### Rect_ 클래스

``` 
template<typename _Tp> class Rect_
{
public:
    Rect_(); // 모든 멤버 변수를 0으로 초기화 하는 생성자
    Rect_(Tp_ _x, Tp_ _y, Tp_ _width,Tp_ _height); // _x, _y, _width, _height를 인자로 받아서 초기화한다.
    Rect_(const Rect_& r); // 복사 생성자(얕은 복사)
    Rect_(const Point<_Tp>& org, const Size_<_Tp>& sz); // 좌측 상단 점의 좌표와 사각형의 크기 정보를 인자로 받는다.
    Rect_(const Point_<_Tp>& pt1, const Point_<_Tp>& pt2); // 사각형에서 서로 대각에 있는 두 좌표를 인자로 받는다.
    Size_<_Tp> size() const; // 사각형의 크기 정보를 반환


    Point_<_Tp> t1() const; // 사각형의 좌측 상단 점의 좌표를 반환
    Point_<_Tp> br() const; // 사각형의 우측 하단 점의 좌표를 반환
    Size_<_Tp> size() const; // 사각형의 크기 정보를 반환
    _Tp area() const; // 사각형의 면적(width * height)을 반환
    bool empty() const; // 유효하지 않은 사각형이면 true 반환
    bool contains(const Point_<Tp>& pt) const; // 인자로 전달된 pt가 사각형 내부에 있으면 true를 반환합니다.
    _Tp s, y, width, height; // x, y는 사각형 좌측 상단 점의 좌표, width, height는 가로 길이와 세로 길이를 나타낸다.
};

typedef Rect_<int>      Rect2i; // int형 Rect
typedef Rect_<float>    Rect2f; // float형 Rect
typedef Rect_<double>   Rect2d; // double형 Rect
typedef Rect2i          Rect; // int형 Rect

Rect(x, y, w, h) += Size(a, b) // Rect(x, y, w + a, h + y)가 된다.
Rect(x, y, w, h) += Point(a, b) // Rect(x + a, y + b, w, h)가 된다.
Rect(a) & Rect(b) // Rect(a)와 Rect(b)사이에 교차하는 영역을 반환한다.
Rect(a) | Rect(b) // Rect(a)와 Rect(b)를 포함하는 가장 작은 사각형을 반환한다.
```





### RotatedRect 클래스

``` 
class RoatatedRect
{
public:
    RoatatedRect(); // 모든 멤버 변수를 0으로 초기화하는 생성자
    RoatatedRect(const Point2f _center, const Size2f& _size, float_angle); // _center, _size, _angle을 인자로 받아 초기화한다.
    RoatatedRect(const Point2f& point1, const Poin2f& point2, const Point2f& point3); // 인자로 전달된 세 점은 회전된 사각형의 세 꼭지점 좌표를 나타냅니다.

    void points(Point2f pst[]) const; // 회전된 사각형의 네 꼭지점좌표를 pst[]에 저장한다.
    Rect boundingRect() const; // 회전된 사각형을 포함하는 최소 크기의 int형 사각형 정보를 반환한다.
    Rect_<float> boundingRect2f() const; // 회전된 사각형을 포함하는 최소 크기의 float형 사각형 정보를 반환한다.

    Point2f center; // 사각형의 중심 좌표
    Size2f size; // 사각형의 크기
    float angle; // 시계 방향 회전 각도
};
```
+ RoatatedRect 클래스는 템플릿 클래스가 아니며, 모든 자료형을 float형으로 받는다.





### Range 클래스

```
class Range{
public:
    Range(); // 모든 멤버 변수를 0으로 초기화하는 생성자
    Range(int _start, int _end); // _start, _end를 인자로 받아 초기화한다.

    int size() const; // 범위의 크기를 반환한다.
    bool empty() const; // start와 end가 같으면 true를 반환한다.
    static Range all(); // start = INT_MIN, end = INT_MAX로 설정한 Range 객체를 반환한다.

    int start, end; // start는 시작, end는 끝
};
```
+ Range r(0, 10); // 0~9 까지의 범위를 갖는 Range 객체





### String 클래스

+ 원래는 std::string과 완전히 호환되는 cv::String을 정의하여 사용하였지만, OpenCV4.0버전부터는 자체적인 String 클래스를 삭제하고, typedef std::string String으로 재정의하여 사용하고 있습니다.
+ 만약 특정한 형식의 문자열을 만들고 싶다면 OpenCV에서 제공하는 format()함수를 사용할 수 있습니다.
```
String format(const char* fmt, ...); // String 클래스를 반환하고, const char* fmt문자열에 ...형식을 받아서 출력한다. (printf("%d", int a)와 유사한 구조)
```





### Mat 클래스

```
class Mat
{
public:
    Mat(); // 모든 멤버 변수를 0으로 초기화하는 생성자
    Mat(int rows, int cols, int type); // 순서대로 세로, 가로, 타입이다. 타입은 깊이를 의미한다. 
    Mat(Size size, int type); // size를 인자로 받는 2차원 행렬이다.
    Mat(int tows, int cols, int type, const Scalar& s); // 가로, 세로, 타입, 행렬 원소의 초깃값을 설정한다. 예를 들어서 세로가 480, 가로가 640이고, 모든 픽셀값이 128로 초기화된 그레이 스케일 영상의 코드는 다음과 같다. int rows와 int col대신에 Size size를 인자로 받을 수 있다.
    //Mat(480, 640, CV8UC1, Scalar(128));
    Mat(const Mat& m);
    ~Mat();

    void create(int rows, int cols, int type);
    bool empty() const;

    Mat clone();
    void copyTo(OutPutArray m) const;
    Mat& setTo(InputArray value, InputArray mask = noArray());

    Mat& opeartor = (const Mat& m);
    Mat operator()(const Rect& roi) const;

    template<typename _Tp> _Tp* ptr(int i0 = 0);
    template<typename _Tp> _Tp& at(int rows, int col);

    int dims; // 행렬의 차원(ex : 영상은 2차원)
    int rows, cols; // 2차원 행렬의 크기 (rows = 열, cols = 행) -> 3차원 이상의 행렬에서는 -1의 값을 가진다.
    uchar* data; // 행렬의 원소가 저장된 데이터의 포인터(데이터가 없다면 nullptr)
    MatSize size; // 3차원 이상 행렬의 크기 정보
    ...
};
```

+ 다양한 자료형을 원소로 가질 수 있고, 여러 개의 값이 모여서 하나의 원소로 표현되기도 한다.
+ C/C++ 기본 자료형 중에서 signed char, unsigned char, signed short, unsigned short, int, float, double형을 지원합니다. (OpenCV4.0부터는 16비트형 실수형 자료도 사용할 수 있습니다.
+ Mat행렬 원소는 하나의 값을 가질 수도 있고, 여러 개의 값을 가질 수도 있다. 이 때 행렬 원소를 구성하는 각각의 값을 채널(channel)이라고 부릅니다. 하나의 행렬을 구성하는 각 채널은 모두 같은 자료형을 사용한다. (ex : 그레이 스케일 영상은 하나의 픽셀이 밝기(휘도)만을 사용하므로, 1채널 행렬이다.)
+ Mat클래스에서 행렬이 자료형을 사용하는지에 대한 정보를 깊이(depth)라고 부릅니다. 깊이는 다음과 같은 형식의 메크로 상수를 이용하여 표현합니다.
```
CV_<bit-depth>(U|S|F)C(<number_of_channels>)
```
+ 순서대로, U는 부호 없는 정수형, S는 부호 있는 정수형, F는 부동 소수형을 의미하고, 상수는 자료형의 크기를 얘기하고, C뒤의 숫자는 채널의 개수를 얘기한다.
> #define CV_8U     0
> #define CV_8S     1
> #define CV_16U    2
> #define CV_16S    3
> #define CV_32S    4
> #define CV_32F    5
> #define CV_64F    6
> #define CV_16F    7
+ 예를 들어, B, G, R색상을 가지고 있는 unsigned char로 선언된 Mat행렬은 CV_8UC3이다.
```
static MatExpt Mat::zeros(int rows, int cols, int type); // 모든 원소를 0으로 초기화하고 자동으로 Mat 객체를 생성해주는 함수이다.(생성자는 아니다) int rows와 int col대신에 Size size를 인자로 받을 수 있다.
```
> static MatExpr Mat::ones(int rows, int cols, int type); // 모든 원소를 1로 초기화하고 자동으로 Mat 객체를 생성해주는 함수이다.(생성자는 아니다) int rows와 int col대신에 Size size를 인자로 받을 수 있다.
```
static MatExpr Mat::eye(int rows, int cols, int type); // 단위 행렬으로 Mat객체를 생성해주는 함수이다.(생성자는 아니다) int rows와 int col대신에 Size size를 인자로 받을 수 있다.
```

```
Mat::Mat(int rows, int cols, int type, void* data, size_t step=AUTO_STEP); // 새로 만드는 Mat 객체에 행, 열, 행렬의 타입, 외부 행렬 데이터의 주소, 패딩 바이트를 지정합니다. 기본값을 사용하게 되면, 패딩 바이트가 없다고 간주합니다. (생성자에서 메모리 공간을 동적으로 할당하지 않습니다. -> 소멸자를 직접적으로 만들어줘야 합니다.)
```
> 외부 메모리 행렬 원소 값의 크기와 생성할 행렬 원소 개수가 같아야 하고, 타입도 같아야 한다. 또한, 외부 데이터의 주소에 대한 참조를 하기 때문에, 외부 데이터의 값이 바뀌면, Mat 객체의 데이터도 바뀐다. 이 방식을 좀 더 쉽게 사용하기 위해서는 Mat클래스를 상속받는 Mat_클래스를 사용할 수 있다. Mat_클래스에서는 <<연산자와, ,연산자를 이용한 간단한 초기화가 가능합니다. (Mat_<float> mat_(2, 3); mat_ << 1, 2, 3, 4, 5, 6;)

+ OpenCV 4.0부터는 C++11기반의 초기화 리스트를 이용한 행렬 초기화 방법을 사용할 수 있다.

```
void Mat::create(int rows, int cols, int type); // 새로 만들 행렬의 행과 열을 받아서 행렬을 만듭니다. 기존에 있던 행렬의 크기와 타입이 기존과 동일하다면 별다른 동작을 하지 않고 종료합니다. 그렇지 않다면, 기존에 있던 데이터를 해제하고 새로 메모리 공간을 할당합니다.
```
> Mat::operator=(const Scalar& s)함수와 Mat& Mat::setTo(InputArray value, InputArray mask = noArrary())함수가 합쳐진 형태이다.


```
void MatOp()
{
	Mat img1; // 객체 생성 (nullptr)

	Mat img2(480, 640, CV_8UC1); // unsinged char, 1-channel
	Mat img3(480, 640, CV_8UC3); // unsigned char, 3-channels
	Mat img4(Size(640, 480), CV_8UC3);	// Size(width, height)함수로 배열의 크기 설정

	Mat img5(480, 640, CV_8UC1, Scalar(128)); // 초기값 설정, 128
	Mat img6(480, 640, CV_8UC3, Scalar(0, 0, 255));	// 초기값 설정, red

	Mat mat1 = Mat::zeros(3, 3, CV_32SC1); // 0으로 초기화된 3X3행렬, signed int, 1-channel 
	Mat mat2 = Mat::ones(3, 3, CV_32FC1); // 1로 초기화된 3X3행렬, float, 1-channel
	Mat mat3 = Mat::eye(3, 3, CV_32FC1); // 3X3단위 행려, float, 1-channel

	float data[] = { 1, 2, 3, 4, 5, 6 };
	Mat mat4(2, 3, CV_32FC1, data); // float, 1-channel, 배열을 받아서 초기화

	Mat mat5 = (Mat_<float>(2, 3) << 1, 2, 3, 4, 5, 6); // 함수 선언, 대입
	Mat mat6 = Mat_<uchar>({2, 3}, { 1, 2, 3, 4, 5, 6 }); // 함수 선언, 초기화 리스트

	mat4.create(256, 256, CV_8UC3);	// unsigned char, 3-channels
	mat5.create(4, 4, CV_32FC1);	// float, 1-channel

	mat4 = Scalar(255, 0, 0); // blue
	mat5.setTo(1.f); // 행렬의 모든 원소 값 1.f로 설정
}
```





### 행렬의 복사

> Mat 객체에 저장된 행렬 객체를 다른 행렬 객체에 대입하거나, 복사할 수 있습니다.

```
void MatOp()
{
	Mat img1 = imread("dog.bmp"); // 외부 이미지 저장

	Mat img2 = img1; // img2선언, img1 대입
	Mat img3; //img3 선언
	img3 = img1; // img3 대입

	Mat img4 = img1.clone(); // img1의 깊은 복사
	Mat img5;
	img1.copyTo(img5); // img1을 img5에 깊은 복사

	img1.setTo(Scalar(0, 255, 255)); // yellow

	imshow("img1", img1); // img1 출력
	imshow("img2", img2);
	imshow("img3", img3);
	imshow("img4", img4);
	imshow("img5", img5);

	waitKey(); // 입력(무작위 키보드 입력)이 들어올 때까지 대기
	destroyAllWindows(); // 모든 창 삭제
}
```





### 부분 행렬 복사

> Mat객체에 저장된 영상 중에서 사각형 모양의 부분 영상을 추출하거나, 참조하는 방법입니다.

```
void MatOp()
{
	Mat img1 = imread("cat.bmp");

	if (img1.empty()) // img1이 성공적으로 복사되었는지 확인
    { 
		cerr << "Image load failed!" << endl;
		return;
	}

	Mat img2 = img1(Rect(220, 120, 340, 240)); // (220, 120)좌표에서부터 340X240크기의 사각형 부분 영상을 추출(얕은 복사)
	Mat img3 = img1(Rect(220, 120, 340, 240)).clone(); // (220, 120)좌표에서부터 340X240크기의 사각형 부분 영상을 추출(깊은 복사) 

	img2 = ~img2; // 색상을 반전하는 operator

	imshow("img1", img1);
	imshow("img2", img2);
	imshow("img3", img3);

	waitKey();
	destroyAllWindows();
}
```

```
Mat Mat::rowRange(int startrow, int endrow) const; // 추출할 행의 시작과 끝번호를 전달합니다. 행의 상수 형태를 참조 형식으로 전달할 수도 있습니다.
Mat Mat::colRange(int startcol, int endcol) const; // 추출할 열의 시작과 끝번호를 전달합니다. 열의 상수 형태를 참조 형식으로 전달할 수도 있습니다.
```

```
Mat Mat::row(int y) const; // 부분 행렬로 추출할 행 번호
Mat Mat::col(int x) const; // 부분 행렬로 추출할 열 번호
```
> 추출한 부분 행렬을 얕은 복사하여 반환합니다.





### 행렬의 원소 값 참조

> OpenCV 라이브러리는 다양한 영상 처리에 필요한 기능을 구현한 함수와 클래스를 제공하기 때문에, 이것들만 잘 조합하여도 영상 처리 시스템을 구축할 수 있습니다. 그러나, 사용자가 직접 자신의 알고리즘을 구현해야 하는 경우도 발생하기 때문에, 영상의 픽셀값에 접근하는 기능을 통해서 알고리즘을 구현한다.

+ Mat::at() 함수 사용
```
template<typename _Tp> _Tp& Mat::at(int y, int x); // 참조할 행과 열의 원소 값을 _Tp의 참조 타입으로 반환합니다.
```

+ Mat::ptr() 함수 사용
```
template<typename _Tp>
_Tp* Mat::ptr(int y) // 참조할 행의 시작 주소를 _Tp의 주소 타입으로 반환합니다. 이 때는 1차원 행렬을 사용하는 방식으로 반환된 타입을 다룰 수 있다.
```

+ MatIterator_ 반복자 사용
> Mat::at() 함수나, Mat::ptr() 함수를 사용할 경우, 전달된 값이 행렬의 크기에서 벗어나면 오류가 일어나기 때문에, 행렬이나 영상의 크기를 벗어나지 않기 위해서 사용자가 제어해줘야 한다. 이 때, 반복자 패턴을 사용해서 접근하면 자동적으로 행렬의 데이터가 존재하는지 아닌지 확인하므로, 더 편리하게 사용할 수 있습니다. 그러나 이 방식은 동작 속도가 느리고, 임의의 위치에 자유롭게 접근할 수 없습니다.
```
	for (MatIterator_<uchar> it = mat1.begin<uchar>(); it != mat1.end<uchar>(); ++it)
		(*it)++;
// MatIterator_<uchar> 형식의 it객체를 생성하고, 시작값을 대입한 뒤에, 끝 값과 같아질 때까지 반복한다. 이 때, it는 포인터 타입이므로, 참조 연산 해주어야 값을 변경할 수 있다.
```





### 행렬 정보 참조하기

> Mat 클래스를 이용하여 만든 행렬 객체로부터 다양한 정보를 참조할 수 있습니다. 가장 자주 참조하는 정보는 행렬 또는 영상의 크기 정보입니다. Mat객체에 영상이 저장되어 있는 경우에는 rows는 x좌표를, cols는 y좌표를 의미합니다.

+ int Mat::channels() const; // 행렬의 채널 수 반환
+ int Mat::depth() const; // 행렬의 깊이(자료형) 반환
+ size_t Mat::elemSize() const; // 한 개의 원소(깊이 X 채널)가 차지하는 메모리의 크기를 바이트 단위로 반환
+ size_t Mat::elemSize1() const; // 하나의 채널에서 한 개의 원소가 차지하는 메모리의 크기를 바이트 단위로 반환
+ bool Mat::empty() const; // 비어있는 행렬이면 true를 반환
+ bool Mat::isContinuous() const; // 각 행의 연소가 연속적으로 저장되어 있으면 true 반환
+ bool Mat::isSubmatrix() const; // 행렬이 다른 행렬의 부분 집합이면 true 반환
+ Size Mat::size() const; // 행렬 크기를 Size 타입으로 반환
+ size_t Mat::total() const; // 전체 원소 개수 반환
+ int mat::type() const; // 행렬의 타입(깊이 + 자료형) 반환

```
static inline std::ostream& operator<<(std::ostream& out, const Mat& mtx)
// C++ 표준 출력 스트림 객체와 출력할 Mat객체를 참조받아서 C++표준 출력 스트림 객체의 참조로 반환합니다.
```
> Mat객체에 저장된 행렬 원소가 표준 자료형일 때, 그 값을 확인하고자 사용합니다. 또한, 행과 열이 대괄호 안에 구분되도록 출력된다. C++ 표준 출력 스트림을 받는 객체로는 std::cout등이 있다.

```
void MatOp()
{
	Mat img1 = imread("lenna.bmp");

	cout << "Width: " << img1.cols << endl; // 행 멤버 변수 출력
	cout << "Height: " << img1.rows << endl; // 열 멤버 변수 출력
	cout << "Channels: " << img1.channels() << endl;

	if (img1.type() == CV_8UC1) // img1객체의 원소의 타입을 확인
		cout << "img1 is a grayscale image." << endl;
	else if (img1.type() == CV_8UC3)
		cout << "img1 is a truecolor image." << endl;

	float data[] = { 2.f, 1.414f, 3.f, 1.732f };
	Mat mat1(2, 2, CV_32FC1, data);
	cout << "mat1:\n" << mat1 << endl; // 연산자 재정의로 <<연산자 사용
}
```





### 행렬 연산

> Mat클래스는 영상을 표현하는 용도로 사용할 수도 있지만, 일반적인 행렬 표현과 행렬 연산을 위한 기능도 충분히 제공하고 있다. 행렬 연산을 위해서 +, -, *, /연산자를 재정의하여 사용한다. 연산자의 재정의에는 OpenCV의 Scalar클래스 뿐만 아니라 표준 타입의 데이터도 들어갈 수 있다.

+ MatExpr operator+(const Mat& a, const Mat& b); // a, b객체의 타입이 같으면 각 원소의 값을 더합니다.
+ MatExpr operator+(const Mat&a, const Scalar& s); // a객체의 각 원소에 s의 값을 더합니다.
+ MatExpr operator+(const Scalar& s, const Mat&a); // a객체의 각 원소에 s의 값을 더합니다.
+ MatExpr operator-(const Mat& a, const Mat& b); // a, b객체의 타입이 같으면 각 원소의 값을 뺍니다.
+ MatExpr operator-(const Mat&a, const Scalar& s); // a객체의 각 원소에 s의 값을 뺍니다.
+ MatExpr operator-(const Scalar& s, const Mat&a); // a객체의 각 원소에 s의 값을 뺍니다.
+ MatExpr operator-(const Mat& m) // m객체의 각 원소에 -1을 곱합니다.
+ MatExpr operator*(const Mat& a, const Mat& b); // a객체와 b객체를 곱합니다. (행렬 곱)
+ MatExpr operator*(const Mat& a, double s); // a객체의 각 원소에 s를 곱합니다.
+ MatExpr operator*(double s, const Mat& a); // a객체의 각 원소에 s를 곱합니다.
+ MatExpr operator/(const Mat& a, const Mat& b); // a객체의 원소를 b객체의 해당하는 위치의 원소로 나눕니다.
+ MatExpr operator/(const Mat& a, double s); // a객체의 각 원소를 s로 나눕니다.
+ MatExpr operator/(double s, const Mat& a); // a객체의 각 원소를 s로 나눕니다.

```
MatExpr Mat::mul(InputArray m, double scale = 1) const; // *this 행렬의 크기 및 타입이 같은 행렬, 또는 행렬 표현식의 각 원소에 scale값으로 곱해서 반환한다.
```

```
MatExpr Mat::inv(int method=DECOMP_LU,) const; // 역행렬의 계산 방법에 대하여, 가우스 소거법(DECOMP_LU = 초기값), 특잇값 분해(DECOMP_SVD), 고윳값 분해(DECOMP_EIG), 촐레스키 분해(DECOMP_CHOLESKY)에 의한 역행렬 계산을 수행하고 반환합니다.
```

```
MatExpr Mat::t() const; // 전치 행렬로 반환한다.
```

```
void MatOp()
{
	float data[] = { 1, 1, 2, 3 };
	Mat mat1(2, 2, CV_32FC1, data);
	cout << "mat1:\n" << mat1 << endl;

	Mat mat2 = mat1.inv(); // 초기값(가우스 소거법)으로 역행렬 계산
	cout << "mat2:\n" << mat2 << endl;

	cout << "mat1.t():\n" << mat1.t() << endl; // 전치 행렬로 변환
	cout << "mat1 + 3:\n" << mat1 + 3 << endl; // 각 원소 3증가
	cout << "mat1 + mat2:\n" << mat1 + mat2 << endl; // mat1과 mat2의 각 원소 더하기
	cout << "mat1 * mat2:\n" << mat1 * mat2 << endl; // mat1과 mat2 행렬의 곱셈
}
```





### 크기 및 타입 변환 함수

> Mat객체의 크기 또는 타입을 변화시키는 함수들이다.

```
void Mat::convertTo(OutputArray m, int rtype, double alpha = 1, double beta = 0) const;
// alpha값을 곱하고, beta 값을 더한 뒤에, rtype으로 원하는 출력의 행렬 타입을 설정하고, m행렬을 반환합니다. m행렬이 적절한 크기와 타입이 아닌 경우 새로 할당해서 출력합니다.
```
> 일반적인 영상은 uchar차료형을 사용하여 표현하는데, 복잡한 연산의 경우, 연산의 정확도를 높이기 위해서 픽셀값을 float, double같은 실수형을 사용하여 계산하기도 한다. 혹은, 그레이 스케일과 컬러 스케일의 변환에 사용되기도 한다.

```
Mat Mat::reshape(int cn, int rows = 0) const; // cn을 통해 새로운 채널 수를 설정하고, rows를 통해 새로운 행의 수를 설정한 뒤에 참조 형식의 Mat객체를 반환합니다. cn과 rows가 0이라면 변환하지 않습니다.
```

```
void Mat::resize(size_t sz, const Scalar& s) // 행렬의 행 개수를 sz개로 변경합니다. sz가 기존 행렬의 행 개수보다 작으면 아래쪽 행을 제거하고, 기존 행렬의 행 개수보다 크면 아래쪽에 행을 추가합니다. 이 때, 추가하는 행 원소의 초깃값을 s로 지정할 수 있습니다.
```
> 기존 행렬의 행 개수보다 작으면 추가되는 값이 없으므로, s값이 없는 형태로 작성할 수 있다.

```
template<typename _Tp> void Mat::push_back(const _Tp& elem);
template<typename _Tp> void Mat::push_back(const std::vector<_Tp>& elem);
// elem값으로 행렬의 맨 마지막 행에 추가할 원소 데이터를 보내고 반환합니다. 이 때, *this는 1열 행렬이어야 합니다.
```

```
template<typename _Tp> void Mat::push_back(const Mat_<_Tp>& elem);
void Mat::push_back(const Mat& m);
// 행렬의 마지막 행에 추가할 행렬을 m, elem으로 전달합니다. 이 때, *this는 elem과 열 개수가 같아야 합니다.
```

```
void Mat::pop_back(size_t nelems = 1); // nelems의 수만큼 *this의 행을 제거합니다. 이 때, nelems는 *this의 행렬의 행 개수보다 작아야 합니다.
```

```
void MatOp()
{
	Mat img1 = imread("lenna.bmp", IMREAD_GRAYSCALE); // 외부 이미지를 가져와서 그레이 스케일로 변수에 전달

	Mat img1f;
	img1.convertTo(img1f, CV_32FC1); // 행렬의 깊이와 채널 변경

	uchar data1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
	Mat mat1(3, 4, CV_8UC1, data1); // data1 행렬을 3X4의 형태로 unsigned char, 1-channel 참조
	Mat mat2 = mat1.reshape(0, 1); // 1행짜리 행렬로 mat1 변환하고 대입

	cout << "mat1:\n" << mat1 << endl;
	cout << "mat2:\n" << mat2 << endl;

	mat1.resize(5, 100); // 행을 5줄로 바꾸고, 추가되는 원소의 값을 100으로 설정
	cout << "mat1:\n" << mat1 << endl;

	Mat mat3 = Mat::ones(1, 4, CV_8UC1) * 255; // unsigned char, 1-channel의 모든 원소를 1로 설정하고, 각 원소에 255를 곱함
	mat1.push_back(mat3); // mat1의 마지막 행에 mat3데이터를 추가
	cout << "mat1:\n" << mat1 << endl;
}
```
