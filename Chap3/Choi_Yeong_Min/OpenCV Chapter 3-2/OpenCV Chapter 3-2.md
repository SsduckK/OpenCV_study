# 3장 OpenCV 주요 클래스



### 3.2 Mat 클래스



#### Mat 클래스 개요

- Mat 클래스는 OpenCV 라이브러리에서 가장 많이 사용하는 클래스

- 일반적인 2차원 행렬뿐만 아니라 고차원 행렬을 표현 할 수 있으며, 한개 이상의 채널을 가질 수 있음
- 정수, 실수, 복소수 등으로 구성된 행렬 또는 벡터를 저장할 수 있고, 그레이스케일 또는 컬러 영상을 저장할 수 있음
- 경우에 따라서 벡터 필드, 포인트 클라우드, 텐서, 히스토그램 등 정보를 저장하는 용도로 사용됨
- 하지만, 실제로는 2차원 영상 데이터를 저장하고 처리하는 용도로 가장 많이 사용됨.



```c++
class Mat
{
    public:
    Mat();
    Mat(int rows, int cols, int type);
    Mat(Size size, int type);
    Mat(int rows, int cols, int type, const Scalar& s);
    Mat(Size size, int tupe, const Scalar& s);
    Mat(const Mat& m);
    ~Mat();
    // Mat 클래스의 다양한 생성자와 소멸자
    
    void vreate(int rows, int cols, int type);
    bool empty() const;
    
    Mat clone() const;
    void copyTo(OutputArray m) const;
    Mat& setTo(InputArray value, InputArray mask=noArray());
    
    static MatExpr zeros(int rows, int cols, int type);
    static MatExpr ones(int rows, int cols, int type);
    
    Mat& operator = (const Mat& m);
    Mat operator()( const Rect& roi ) const;
    
    template<typename _Tp> _Tp* ptr(int i0 = 0);
    template<typename _Tp> _Tp& at(int row, int col);
    // Mat 클래스의 멤버함수, 연산자 재정의 함수와 정적 멤버함수도 포함됨
    
    int dims;
    introws, cols;
    uchar* data;
    Matsize size;
    // 이후 코드 생략됨
    // Mat클래스의 주요 멤버 변수
    
};
```



##### Mat 클래스 멤버 변수

- Mat 클래스 멤버 변수
  - Mat::dims : Mat 행렬의 차원을 나타내며, 영상과 같은 2차원 행렬의 경우 Mat::dims 값은 2가 된다
  - Mat::rows : 2차원 행렬의 행의 개수를 나타냄
  - Mat::cols   : 2차원 행렬의 열의 개수를 나타냄
    - rows와 cols는 Mat의 객체가 2차원 행렬인 경우에만 의미를 가지며, 3차원 이상의 행렬은 -1이 저장됨
  - Mat::size   : 3차원 이상의 행렬 크기 정보 참조 가능size : 
    - Mat::size 멤버 변수 타입인 MatSize는 3차원 이상의 행렬 크기를 표현하기 위해 사용되는 클래스
  - Mat::data  : 행렬의 원소 데이터가 저장되어있는 메모리 공간을 가르키는 포인터형 멤버 변수
    - 행렬에 아무것도 저장되지 않은 상태라면 data는 0(NULL) 값을 가짐
- Mat 클래스의 모든 멤버 변수는 public 접근 지시자로 선언되어 있어서 클래스 외부에서 직접 접근할 수 있음
- 위 코드에서 소개되지 않은 멤버 변수들은 활용성이 높지 않기 때문에 생략함



##### Mat 클래스의 원소에 대해서

- Mat 행렬은 다양한 자료형 원소를 가질 수 있음
  - unsigned char, signed char, unsigned short, signed short, int, float, double 자료형 사용 가능
  - OpenCV 4.0 부터는 16비트 실수형 자료 사용 가능

- Mat 클래스에서 행렬이 어떤 자료형을 사용하는지에 대한 정보를 '깊이'라고 부름

- OpenCV에서 Mat 행렬의 깊이는 매크로 상수를 이용하여 표현함

  - ```c++
    CV_<bit-depth>{U|S|F}
    
    # define CV_8U		// unsigned char	부호 없는 1바이트 정수
    # define CV_8S		// signed char		부호 있는 1바이트 정수
    # define CV_16U		// unsigned short	부호 없는 2바이트 정수
    # define CV_16S		// signed short		부호 있는 2바이트 정수
    # define CV_32S		// int				부호 있는 4바이트 정수
    # define CV_32F		// float			부호 있는 4바이트 실수
    # define CV_64F		// double			부호 있는 8바이트 실수
    # define CV_16F		// float16_t		부호 있는 2바이트 실수
    ```

- Mat 행렬 원소를 구성하는 각각의 값을 '채널'이라고 부름
  - 하나의 행렬을 구성하는 각 채널은 모두 같은 자료형을 사용해야함

- Mat 행렬의 깊이 정보와 채널 수 정보를 합쳐서 Mat 객체의 '타입'이라고 부름

- OpenCV에서 Mat 행렬의 타입은 매크로 상수를 이용하여 표현함

  - ```c++
    CV_<bit-depth>{U|S|F}C(<number_of_channels>)
    
    #define CV_8UC1		// 채널이 1개인 8비트 unsigned char
    #define CV_8UC3		// unsigned char 자료형 B, G, R 3개의 색상 성분을 가지고 있는 컬러 영상
    ```



##### 행렬의 생성과 초기화

- ```c++
  Mat img1;
  ```

  - Mat 클래스 기본 생성자

    - img1.rows와 img1.cols 값은 0이고, img1.data에도 0(NULL)이 저장됨

    - 비어있는 행렬의 원소값을 참조시 에러 발생할 수 있음으로 주의

- ```c++
  Mat::Mat(int rows, int cols, int type);
  
  Mat img2(480, 640, CV_8UC1);  // unsigned char, 1-channel, 640 x 480
  ```

  - Mat 클래스 생성자

    - rows : 새로 만들 행렬의 행 개수 (영상의 세로 크기)

    - cols : 새로 만들 행렬의 열 개수 (영상의 가로 크기)

    - type : 새로 만들 행렬의 타입

- ```c++
  Mat::Mat(Size size, int type);
  
  Mat img4(Size(640, 480), CV_8UC3);  // Size(width, height), 640 x 480
  ```

  - Mat 클래스 생성자에서 행렬의 크기를 지정할 때 Size 클래스 사용 가능
    - size : 새로 만들 행렬의 크기
    - type : 새로 만들 행렬의 타입

- ```c++
  Mat::Mat(int rows, int cols, int type, const Scalar& s);
  Mat::Mat(Size size, int type, const Scalar& s);
  
  Mat img5(480, 640, CV_8UC1, Scalar(128));		// initial values, 128
  Mat img6(480, 640, CV_8UC3, Scalar(0, 0, 255));	// initial values, red
  ```

  - 정해진 크기와 타입의 Mat객체를 생성하고 모든 원소 값을 초기화
    - rows : 새로 만들 행렬의 행 개수 (영상의 세로 크기)
    - cols : 새로 만들 행렬의 열 개수 (영상의 가로 크기)
    - size : 새로 만들 행렬의 크기
    - type : 새로 만들 행렬의 타입
    - s : 행렬 원소 초기값



##### 행렬의 복사

![](/home/kevin/workspace/OpenCV_Study/Study notes/OpenCV Chapter 3-2/MatOp2.png)



##### 부분 행렬 추출

![](/home/kevin/workspace/OpenCV_Study/Study notes/OpenCV Chapter 3-2/MatOp3.png)



##### 행렬의 원소 값 참조

![](/home/kevin/workspace/OpenCV_Study/Study notes/OpenCV Chapter 3-2/MatOp4.png)



##### 행렬 정보 참조하기

![](/home/kevin/workspace/OpenCV_Study/Study notes/OpenCV Chapter 3-2/MatOp5.png)



##### 행렬 연산

![](/home/kevin/workspace/OpenCV_Study/Study notes/OpenCV Chapter 3-2/MatOp6.png)



##### 크기 및 타입 변환 함수

![](/home/kevin/workspace/OpenCV_Study/Study notes/OpenCV Chapter 3-2/MatOp7.png)



