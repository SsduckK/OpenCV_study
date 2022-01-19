### Vec 클래스
> 하나의 행으로만 이루어진 행렬을 행 벡터라고 하고, 하나의 열로만 이루어진 행렬을 열 벡터라고 합니다. 행 벡터와 열 벡터를 합쳐서 벡터 또는 벡텨 행렬이라고 합니다. 즉, 벡터는 같은 자료형을 가진 원소 몇 개로 구성된 데이터 형식입니다.

```
template<typename _Tp, int m, int n> class Matx { // 작은 크기의 행렬을 표현하기 위해 만들어진 템플릿 Matx클래스
public:
    _Tp val[m*n]; // 원소
};

template<typename _Tp, int cn> class Vec : public Matx<_tp, cn, 1> { // 작은 크기의 벡터를 표현하기 위해 만들어진 Vec클래스. Matx클래스를 상속받습니다.
public:
    _Tp& opeartor[] (int i); // Vec클래스의 멤버 변수 배열에 접근할 수 있는 []연산자 재정의
};

tempalte<typename _Tp, int n> static inline
std:ostream operator << (std::ostream& out, const Vec<_tp, n>& vec); // C++ 표준 출력 스트림을 이용하여 벡터 원소를 출력하는 <<연산자 재정의
```

```
Vec<uchar, 3> p1, p2(0, 0, 255); // Vec클래스 선언 방식
```
+ 그러나 이 방식은 번거롭고 불편하기 때문에, OpenCV는 자주 사용되는 자료형과 개수에 대한 Vec클래스 템플릿의 이름 제정의를 제공합니다.

```
Vec<num-of-data> {x}
```
+ num-of-data에는 2, 3, 4등의 작은 숫자를 지정할 수 있고, {x}의 위치에는 b(uchar), s(short), w(ushort), i(int), f(float), d(double) 중에서 하나의 자료형을 골라서 적을 수 있습니다. b, s, w에는 2, 3, 4의 숫자가 재정의되어 있고, i에는 2, 3, 4, 6, 8이, f, d에는 2, 3, 4, 6이 재정의 되어있다. 따라서 위의 코드는 Vec3b p1, p2(0, 0, 255); 로 선언할 수 있습니다.

```
p.[0] = 100; // == p.val[0] = 100; // 재정의된 []연산자는 대입을 더 편하게 만들어 줍니다.
```





### Scalar 클래스

> OpenCV에서 Mat다음으로 자주 사용되는 클래스입니다. Scalar 클래스는 4채널 이하의 영상에서 픽셀 값을 표현하는 용도로 자주 사용됩니다. 이 클래스는 Vec클래스를 상속받아서 만들어집니다.
```
template<typename _Tp> class Scalar_ : public Vec<_Tp, 4>
{
public:
    Scalar_();
    Scalar_(_Tp v0); // 그레이 스케일 영상일 경우, 영상의 명도를 표현하는 용도로 자주 사용됩니다.
    Scalar_(_Tp v0, _Tp v1, _Tp v2 = 0, _Tp v3 = 0); // 순서대로 B, G, R로 사용되고 마지막은 PNG같은 파일에서의 투명도를 표현하는 용도소 사용됩니다.
    
    static Scalar_ <_Tp> all(_Tp v0); // 네 개의 val배열 값을 모두 v0로 설정한 Scalar_객체를 반환합니다.
};

typedef Scalar_<double> Scalar;
```

```
void Scalar0p()
{
    Scalar gray = 128; // gray객체 생성(gray = {128, 0, 0, 0})
    cout << "gray : " << gray << endl;
    
    Scalar yellow(0, 255, 255); // yellow객체 생성(yellow = {0, 255, 255, 0})
    cout << "yellow : " << yellow << endl;

    Mat img1(256, 256, CV_8UC3, yellow); // yellow객체를 통해서 노란색으로 초기화된 256X256 사이즈의 img1객체 생성

    for (int i = 0; i < 4; ++i)
        cout << yellow[i] << endl;
}
```





### InputArray 클래스

> OpenCV에서 Mat, vector<T>등의 다양한 타입을 표현할 수 있는 인터페이스 클래스로서, 주로 OpenCV함수의 입력 인자 자료형으로 사용됩니다. InputArray클래스를 이해하기 위해서는 _InputArray클래스의 정의부터 살펴봐야 하지만, _InputArray클래스는 단순히 사용의 편의성을 위해서 만들어진 구현체일 뿐 내부 인터페이스는 향수 필요에 따라 변경하게 될 가능성이 크므로 InputArray클래스를 어떻게 해석해야 하는지에 대해서만 이해하면 됩니다.

+ _InputArray클래스는 Mat, Mat<_Tp>, vector<T> ... 가튼 다양한 타입으로부터 생성될 수 있는 인텊이스 클래스입니다. 따라서 _InputArray클래스는 OpenCV 라이브러리내부에서 코드 편의상 사용되며, 사용자가 명시적으로 _InputArray 클래스의 인스턴스 또는 변수를 생성하여 사용하는 것을 금지하고 있습니다. 따라서 특정 함수의 인자가 InputArray타입을 받도록 설정되어 있다면, Mat객체나 vector<T>객체 등을 전달하는 형태로 코드를 작성해야 합니다. 만약에 InputArray인자에 비어 있는 행렬을 전달하려면 함수 인자에 noArray() 또는 Mat()를 입력하면 됩니다.

```
Mat _InputArray::getMat(int idx = 1) const; // idx로 참조할 행 변호를 설정하고 Mat 행렬 객체를 반홥합니다. idx < 0이면, 행렬 전체를 참조합니다.
```

```
void InputArrayOp()
{
    uchar data1[] = {1, 2, 3, 4, 5, 6};
    Mat mat1(2, 3, CV_8U, data1); // 2X3행렬을 data1을 통해서 생성
    printMat(mat1);

    vector<float> vec1 = {1.2f, 3.4f, -2.1f}; // 3개의 실수로 이루어진 vec1 벡터 생성
    printMat(vec1);
}

void printMat(InputArray _mat)
{
    Mat mat = _mat.getMat(); // InputArray타입의 _mat객체로부터 Mat타입의 mat객체에 값을 대입
    cout << mat << endl;
}
```





### OutputArray 클래스

> OpenCV의 함수는 영상을 입력으로 받아 영상 처리를 수행하고 그 결과를 다시 영상으로 생성하여 반환하는데, 이 때 출력 영상을 return이 아니라 OutputArray클래스의 참조를 함수 인자로 사용하여 결과 영상을 전달합니다. _OutputArray클래스는 계층적으로 _InputAttay클래스를 상속받아 만들어졌으므료, _OutputArray클래스도 Mat 또는 vector<T>같은 객체로부터 생성될 수 있습니다. 다만 _OutputArray클래스에는 새로운 행렬을 생성하는 _OutputArray::create()함수가 추가적으로 정의되어 있어서 새로운 행렬 을 먼저 생성한 후에 영상 처리 결과를 저장하는 형태로 OpenCV의 함수 처리를 돕습니다.

+ OutputArray클래스도 InputArray클래스와 마찬가지로 사용자가 직접 OutputArray타입의 객체를 생성해서 사용하면 안됩니다.





### VideoCapture클래스

> 컴퓨터 비전 분야에서 정지 영상 데이터 뿐만 아니라 동영상 데이터를 불러와서 처리한다거나 혹은 컴퓨터에 연결된 카메라로부터 실시간으로 영상을 불러와서 처리하는 응용이 늘어나고 이습니다. 동영상이란 일련의 정지 영상을 압축하여 파일로 저장한 형태이고, 이 때 일련의 정지 영상을 프레임이라고 합니다. 따라서 동영상을 처리하는 작업은 동영상에서 프레임을 추출한 후에 각각의 프레임에 영상 처리 기법을 적용하는 형태로 이루어집니다. 이 때 VideoCapture클래스를 통하여 카메라 또는 동영상 파일로부터 영상 프레임을 받아올 수 있습니다.

```
class VieoCaptrue
{
public:
    VideoCapture();
    ViideCapture(const String& filename, int apiPreference = CAP_ANY); // filename 동영상으로부터 사용할 비디오 캡쳐 API 백엔드를 사용하여 객체를 사용합니다. 이 때, 일련된 숫자로 구성된 다수의 영상 파일이 있을 경우, filename인자에 "...%d.jpg"를 입력하여 일련의 영상 파일을 차례대로 보거나, 비디오 스트림 URL을 지정하여 인터넷 동영상을 사용할 수도 있습니다.
    VideoCapture(int index, int apiPreference = CAP_ANY); // 컴퓨터에 연결된 카메라와 장치 사용 방식 지정번호를 받아서 카메라 캡쳐 API백엔드를 사용하여 객체를 생성합니다. 카메라가 한 대만 연결되어 있다면 index는 0이 되고, 두 대 이상이라면 0이상의 id값을 가집니다.
    virtual ~VideoCapture();

    virtual bool open(const String& filename, int apiPreference = CAP_ANY); // filename과 apiPrefernce를 대입해주는 함수입니다.
    virtual bool open(int index, int apiPreference = CAP_ANY); // index과 apiPrefernce를 대입해주는 함수입니다.
    virtual bool isOpened() const; // 카메라 또는 동영상 파일 열기를 수행한 뒤에 객체가 정상적으로 생성되었는지 판별하는 함수입니다.
    virtual void release(); // 사용하던 자원을 해제하는 함수입니다.

    virtual bool grab(); // 다음 프레임을 획득하는 명령을 내리는 함수
    virtual bool retrieve(OutputArray image, int flag = 0); // 획득한 프레임을 실제로 받아오는 함수

    virtual VideoCapture& operator>>(Mat& image); // 다음 비디오 프레임을 가져와서 Mat형식의 객체 image에 저장하는 함수입니다.
    virtual bool read(OutputArray image); // 다음 비디오 프레임을 가져와서 image에 저장하는 함수입니다.

    virtual bool set(int propId, double value); // 카메라 또는 비디오 파일 재생과 관련된 속성값을 VideoCaptureProperties 열거형 중 하나를 지정해서 받아옵니다.
    vortual double get(int PropId) const; // 카메라 또는 비디오 파일 재생과 관련된 속성값을 VideoCaptureProperties 열거형 중 하나를 지정해서 설정합니다.
};
```

+ VideoCaptureAPIs 열거형 상수
> CAP_ANY // 자동선택
> CAP_V4L, CAP_V4L2 // V4L/V4L2(리눅스)
> CAP_FIREWIRE, CAP_FIREWARE, CAP_IEEE1394 // IEEE 1394 드라이버
> CAP_DSHOW // DirectSHOW
> CAP_PVAPI // PvAPI, Prosilica GigE SDK
> CAP_OPENNI // OpenNI
> CAP_MSMF // MicroSoft edia Foundation
> CAP_GSTREAMER // GStreamer
> CAP_FFMPEG // FFMPEG 라이브러리
> CAP_IMAGES // OpenCV에서 지원하는 영상 파일
> CAP_OPENCV_MJPEG // OpenCV에 내장된 MotionJPEG코덱

+ VodeoCapture::operator>>()함수는 내부에서 VodeoCapture::read()함수를 호출하므로 사실상 같은 함수이고, VodeoCapture::read()함수는 VodeoCapture::grab()와 VodeoCapture::retrieve()함수를 합쳐놓은 형태라고 볼 수 있다. 여러 대의 장치로부터 동시에 영상을 획득하고 싶다면 >>연산자나 read()함수를 사용하기 보다는 좀 더 빠른 grab()함수와 retrieve()함수를 사용하는 것이 좋습니다. 그러나, 동기화를 고려하는 상황이 아니라면 편리하게 >>연산자나 read()함수를 사용해도 상관이 없습니다.

+ VideoCapturePropeties 열거형 상수
> CAP_PROP_POS_MSEC // 비디오 파일에서 현재 위치(밀리 초 단위)
> CAP_PROP_POS_FRAMES // 현재 프레임 위치
> CAP_PROP_POS_AVI_RATIO // [0, 1]구간으로 표현한 동영상 프레임의 상대적 위치 (0 : 시작, 1 : 끝)
> CAP_PROP_FRAME_WIDTH // 비디오 프레임의 가로 크기
> CAP_PROP_FRAME_HEIGHT // 비디오 프레임의 세로 크기
> CAP_PROP_FRAME_COUNT // 비디오 파일의 전체 프레임 수
> CAP_PROP_FPS // 초당 프레임 수
> CAP_PROP_FOURCC // fourcc 코드(코덱을 표현하는 정수 값)
> -----카메라에서 지원하는 경우에만 작동-----
> CAP_PROP_BRIGHTNESS // 밝기 조절
> CAP_PROP_CONTRAST // 명암비 조절
> CAP_PROP_SATURATION // 채도 조절
> CAP_PROP_HUE // 색상 조절
> CAP_PROP_GAIN // 감도 조절
> CAP_PROP_EXPOSURE // 노출 조절
> CAP_PROP_ZOOM // 줌 조절
> CAP_PROP_FOCUS // 초점 조절





### 카메라 입력 처리 예제 코드

> VideoCapture클래스를 사용하여 컴퓨터에 연결된 카메라로부터 프레임을 받아 와서 처리하는 예제 프로그램을 작성해보겠습니다. 객체를 생성하고, 정상적으로 생성되었는지 확인한 뒤에 한 프레임의 가로, 세로 크기를 출력하고 무한 루프를 통해서 반복적으로 프레임과 반전된 프레임을 각각의 창을 띄워서 출력합니다. 특별한 입력이 없다면 10밀리초 동안 기다린 후에 루프의 처음으로 돌아가고, 입력이 있다면 바로 루프의 처음으로 돌아갑니다. 이 때, 사용자가 원하는 시기에 종료될 수 있도록 esc키가 입력되면 루프를 탈출하도록 작성합니다.

```
void camera_in()
{
    VideoCapture cap(0); // 기본 카메라를 사용해서 객체 생성

    if(!cap.isOpened()) // cap이 정상적으로 생성되었는지 확인
    {
        cerr << "Camera open failed" << endl; // 에러 메세지 출력
        return; 
    }

    cout << "Frame width : " << cvRound(cap.get(CAP_PROP_FRAME_WIDTH)) << endl; // 프레임의 가로 크기 출력
    cout << "Frame height : " << cvRound(cap.get(CAP_PROP_FRAME_HEIGHT)) << endl; // 프레임의 세로 크기 출력

    Mat frame, inversed;
    while(true) 
    {
        cap >> frame; // cap의 한 프레임을 frame에 저장
        if (frame.empty()) // frame이 정상적으로 생성되었는지 확인
            break;
        
        inversed = ~frame; // 프레임 반전

        imshow("frame", frame); // frame창에 frame 영상 출력
        imshow("inversed", inversed); // inversed창에 inversed 영상 출력

        if (waitKey(10) == 27) // 27 == esc키
            break;
    }
}
```





### 동영상 파일 처리 예제 코드

> 대부분의 동영상 파일은 코덱을 통하여 압축된 형태로 저장됩니다. 코덱은 복잡한 알고리즘을 이용하여 대용량 동영상 데이터를 압축하거나, 압축을 해제하여 프레임을 받아오는 기능을 제공합니다. C/C++에서 복잡한 알고리즘을 불러오는 것은 간단한 작업이 아니지만, OpenCV라이브러리에서는 널리 사용되고 있는 코덱 해석 기능을 제공하여 간단히 동영상 파일을 불러와서 사용할 수 있습니다. 이제 동영상 파일을 가져와서 프레임의 가로, 세로 크기와 전체 프레임 수, 초당 프레임 값을 출력하고 프레임 사이의 시간 간격을 밀리초 단위로 계산한 뒤에 동영상과 반전된 동영상을 출력해보겠습니다. 카메라 입력 처리 예제코드에서와 같이 반복문을 작성하여 무한 루프로 계속 실행되게 작성하였습니다.

```
void video_in()
{
    VideoCapture cap("sample.avi"); // smaple.avi로 cap객체 생성

    if (! cap.isOpened()) // 객체가 정상적으로 생성되지 않으면 오류 출력
    {
        cerr << "Video open failed" << endl;
        return;
    }

    cout << "Frame width : " << cvRound(cap.get(CAP_PROP_FRAME_WIDTH)) << endl; // 프레임의 가로 출력
    cout << "Frame height : " << cvRound(cap.get(CAP_PROP_FRAME_HEIGHT)) << endl; // 프레임의 세로 출력
    cout << "Frame count : " << cvRound(cap.get(CAP_PROP_FRAME_COUNT)) << endl; // 전체 프레임 수 출력

    double fps = cap.get(CAP_PROP_FPS);
    cout << "FPS : " << fps << endl; // 초당 프레임 수 출력

    int delay = cvRound(1000 / fps); // 프레임 사이의 시간 간격 계산

    Mat frame, inversed;
    while(true)
    {
        cap >> frame;
        if(frame.empty())
            break;
        
        inversed = ~frame; // 반전
        
        imshow("frame", frame); // frame창에 프레임 출력
        imshow("inversed", inversed); // inversed창에 인버스드 출력

        if (waitKey(delay) == 27)
            break;
    }
    destroyAllWindows();
}
```





### VideoWriter 클래스

> OpenCV는 일련의 프레임을 동영상 파일로 저장하는 기능도 제공합니다. 이 기능은 VideoWriter클래스를 통해 수행됩니다.

```
class VideoWriter
{
public:
    VideoWriter();
    VideoWriter(const String& filename, int fourcc, double fps, Size frameSize, bool isColor = true); // filename의 동영상으로 fourcc(4-문자코드)로 압축해서 fps로 초당 프레임 수를 설정하고, framSize로 프레임의 가로 및 세로 크기를 지정한 뒤에 isColor가 ture면 컬러, false면 그레이스케일로 객체를 생성합니다. isColor는 Windows에서만 지원합니다.
    virtual ~VideoWriter();

    virtual bool open(const String& filename, int fourcc, double fps, Size frameSize, bool isColor = true); // filename의 동영상으로 fourcc(4-문자코드)로 압축해서 fps로 초당 프레임 수를 설정하고, framSize로 프레임의 가로 및 세로 크기를 지정한 뒤에 isColor가 ture면 컬러, false면 그레이스케일로 대입합니다. isColor는 Windows에서만 지원합니다.
    virtual bool isOpened() const; // 객체가 정상적으로 생성되었는지 확인합니다.
    virtual oid release(); // 사용하던 자원을 해제합니다.

    virtual VideoWriter& operator << (const Mat& immage); // 새로운 프레임 추가 <<연산자입니다.
    virtual void write(const Mat& image); // 새로운 프레임 추가 함수입니다.

    virtual bool set(int porpId, double value); // 현재 열린 동영상 파일에 대하여 속성값을 VideoCaptureProperties 열거형 중 하나를 지정해서 설정합니다.
    virtual double get(int porpId) const; // 현재 열린 동영상 파일에 대하여 속성값을 VideoCaptureProperties 열거형 중 하나를 지정해서 받아옵니다.

    static int fourcc(char c1, char c2, char c3, char c4); // c1, c2, c3, c4를 통해서 코덱을 표현하고 반환합니다.
};
```

+ fourcc코드와 의미
> YV12 // YUV 4:2:0 Planar (비압축)
> -----이 아래부터는 전부 코덱이다-----
> DIVX // DivX MPEG-4
> XVID //XVID MPEF-4
> FMP4 // FFMPEG MPEG4
> WMV2 // Windows Media Video 8
> MJPG // 모션 JPEG
> X264 // H.264/AVC 코덱
> AVC1 // Advanced Video





### 동영상 파일 저장 예제 코드

> OpenCV에서는 일련의 프레임을 동영상 파일로 저장하는 기능도 제공합니다. 이제 실제로 동영상 파일을 생성하는 예제 코드를 만들어 보겠습니다.

```
void camera_in_video_out()
{
    VideoCapture cap(0);

    if(!cap.isOpened()) // 객체가 정상적으로 생성되지 않으면 오류 출력
    {
        cerr << "Camera open failed" << endl;
        return;
    }

    int w = cvRound(cap.get(CAP_PROP_FRAME_WIDTH)); // 카메라 프레임의 가로 변수 선언
    int h = cvRound(cap.get(CAP_PROP_FRAME_HEIGHT)); // 카메라 프레임의 세로 변수 선언
    double fps = cap.get(CAP_PROP_FPS); // 카메라의 FPS값 변수 선언

    int fourcc = VideoWriter::fourcc('D', 'I', 'V', 'X'); // 코덱 설정
    int delay = cvRound(1000 / fps); // FPS값으로 매 프레임 사이의 시간 간격 계산

    VideoWriter outputVideo("output.avi", fourcc, fps, Size(w, h)); // 저장할 동영상 파일 생성

    if (!outputVideo.isOpened()) // 출력 파일이 정상적으로 생성되었는지 확인
    {
        cout << "File open failed" << endl;
        return;
    }

    Mat frame, inversed;
    while (true)
    {
        cap >> frame; // 카메라로부터 한 프레임을 받아와 저장
        if(frame.empty())
            break;

        inversed = ~frame; // 프레임 반전
        outputVideo << inversed; // 반전한 프레임을 출력파일에 추가
        
        imshow("frame", frame);
        imshow("inversed", inversed);

        if (waitKey(delay) == 27)
            break;
    }

    destroyAllWindows();
}
```





### 다양한 그리기 함수

> 컴퓨터 비전은 영상의 특징을 분석하여 정보를 추출하는 작업입니다. 영상으로부터 추출된 정보는 콘솔 창에 문자열 형태로 출력하거나, 텍스트 파일로 저장할 수 있지만, 영상 출력 창 위에 직접 문자열 또는 그림으로 정보를 표현하는 것이 보기 좋은 경우가 많기 때문에, OpenCV에서 제공하는 다양한 그리기 함수에 대해 알 필요가 있습니다.

```
void line(InputOutputArray img, Point pt1, Point pt2, const Scalar& color. int tickness = 1, int lineType = LINE_8, int shift = 0);
// 입출력 영상 img를 넘겨받아서 시작점 pt1과 끝점pt2을 정한 다음에 선의 색상이나 밝기를 color인자를 통해 정하고 thickness로 전달받은 선의 두께만큼 lineType으로 선의 길이에서 shift만큼 오른쪽 비트 시프트한 크기의 선을 그립니다.
```

+ LineTypes 열거형 상수
> FILLED (-1) // 내부를 채움(직선 그리기 함수에는 사용 불가)
> LINE_4 (4) // 4방향 연결
> LINE_8 (8) // 8방향 연결
> LINE_AA (18) // 안티에일리어싱 (계단 현상 방지 기술)

```
void arrowedLine(InputOutputArray img, Point pt1, Point pt2, const Scalar& color. int tickness = 1, int lineType = LINE_8, int shift = 0, double tipLength = 0.1);
// void line 함수와 같은 방식으로 작동한 뒤에, pt2부분에 전체 직선 길이에 대한 화살표 길이의 비율을 tipLength로 받아서 화살표 모양의 직선 두 개를 추가로 그린다.
```

```
void drawMarker(InputOutputArray img, Point position, const Scalar& color. int markerType = MARKER_CROSS, int markerSize = 20, int thickness = 1, int tline_type = 8);
// 입출력 영상 img를 넘겨받아서 position으로 넘겨받은 위치에 color로 결정된 색상을 markerTypes 열거형 상수 중 하나를 지정받아서 markerSize의 크기와 thickness의 두께로 line_type으로 그립니다.
```

+ Marker Types 열거형 상수
> MARKER_CROSS // 십자가(+) 모양
> MARKER_TILTED_CROSS // 45도 회전된 십자가 모양
> MARKER_STAR // MARKER_CROSS와 MARKER_TILTED_CROSS가 합쳐진 모양
> MARKER_SQUARE // 정사각형 모양
> MARKER_DIAMOND // 45도 회전된 정사각형 모양
> MARKER_TRIANGLE_UP // 위로 뾰족한 삼각형 모양
> MARKER_TRIANGLE_DOWN // 아래로 뾰족한 삼각형 모양





### 다음은 직선 그리기 예제이다.

> 여러가지 선을 그려 보겠습니다.

```
void drawLines()
{
    Mat img(400, 400, CV_8UC3, Scalar(255,255,255));
    
    line(img, Point(50, 50), Point(200, 50), Scalar(0,0,255));
    line(img, Point(50, 100), Point(200, 100), Scalar(255,0,255), 3);
    line(img, Point(50, 150), Point(200, 150), Scalar(255,0,0) , 10);
    // LineTypes의 값 다양한 직선 그리기

    line(img, Point(250, 50), Point(350, 100), Scalar(0,0,255), 1, LINE_4);
    line(img, Point(250, 70), Point(350, 120), Scalar(255,0,255), 1, LINE_8);
    line(img, Point(250, 90), Point(350, 140), Scalar(255,0,0), 1, LINE_AA);
    // LineTypes의 열거형 상수로 다양한 직선 그리기

    arrowedLine(img, Point(50, 200), Point(150, 200), Scalar(0,0,255), 1);
    arrowedLine(img, Point(50, 250), Point(350, 250), Scalar(255,0,255), 1);
    arrowedLine(img, Point(50, 300), Point(350, 300), Scalar(255,0,0), 1, LINE_8, 0, 0.05);
    // LineTypes의 값과 열거형 상수로 다양한 화살표가 달려있는 직선 그리기

    drawMarker(img, Point(50, 350), Scalar(0, 0, 255), MARKER_CROSS);
    drawMarker(img, Point(100, 350), Scalar(0, 0, 255), MARKER_TILTED_CROSS);
    drawMarker(img, Point(150, 350), Scalar(0, 0, 255), MARKER_STAR);
    drawMarker(img, Point(200, 350), Scalar(0, 0, 255), MARKER_DIAMOND);
    drawMarker(img, Point(250, 350), Scalar(0, 0, 255), MARKER_SQUARE);
    drawMarker(img, Point(300, 350), Scalar(0, 0, 255), MARKER_TRIANGLE_UP);
    drawMarker(img, Point(350, 350), Scalar(0, 0, 255), MARKER_TRIANGLE_DOWN);
    // 다양한 MarkerType으로 마커 그리기

    imshow("img", img);
    waitKey(0);
    
    destroyAllWindows();
}
```





### 도형 그리기

> 영상에 사각형, 원, 타원과 같은 도형을 그리는 OpenCV의 함수에 대해서 알아보곘습니다.

```
void rectangle(InputOutputArray img, Point pt1, Point pt2, const Scalar& color. int tickness = 1, int lineType = LINE_8, int shift = 0); // 입출력 영상 img를 넘겨받아서 점 pt1과 대각선에 있는 점 pt2을 정한 다음에 선의 색상이나 밝기를 color인자를 통해 정하고 thickness로 전달받은 선의 두께만큼 lineType으로 사각형의 크기에서 shift만큼 오른쪽 비트 시프트한 크기만큼의 사각형을 그립니다.
```

```
void Circle(InputOutputArray img, Point center, int radius, const Scalar& color. int tickness = 1, int lineType = LINE_8, int shift = 0); // img에 원의 중심을 center로 받고 반지름이 radius인 원을 그립니다. 선의 색상이나 밝기를 color인자를 통해 정하고 thickness로 전달받은 선의 두께만큼 lineType으로 원의 크기에서 shift만큼 오른쪽 비트 시프트한 크기만큼의 원을 그립니다.
```

```
void ellipse(InputOutputArray img, Point center, Size axes, double angle, double startAngle. double endAngle, const Scalar& color. int tickness = 1, int lineType = LINE_8, int shift = 0);
// img, center, color, tickness, lineType, shift는 원과 똑같은 방식으로 작동하고, axes로 Size 형태의 인자를 받아서 (x축의 반지름, y축의 반지름)으로 크기를 정한 뒤에, angle로 타원의 x축 기준 시게방향으로 회전 각도를 정하고, startAngle로 타원의 x축 기준 시계방향으로 호의 시작 각도에서 출발해서, endAngle로 x축 기준 시계방향으로 호가 끝나는 각도를 정해서 타원을 그립니다.
```

```
void polylines(InputOutputArray img, InputArrayofArray pts, bool isClosed, const Scalar& color, int thickness = 1, int lineType = LINE_8, int shift = 0);
// img에 다각형의 외곽점들의 좌표 배열을 pts로 받아서 isClosed로 다각형이 닫혀있는지 확인한 뒤에 값이 1이면 마지막 꼭지점과 첫 번째 꼭지점을 잇는 직선을 추가로 그리고, color 색으로 thickness 두께만큼 lineType 형태의 shift 값 만큼 축소된 크기의 색을 채웁니다.
```





### 도형 그리기 에제

> 여러 가지 도형을 출력해보겠습니다.

```
void drawPolys()
{
    Mat img(400, 400, CV_8UC3, Scalar(255, 255, 255));
    
    rectangle(img, Rect(50, 50, 100, 50), Scalar(0, 0, 255), 2);
    rectangle(img, Rect(50, 150, 100, 50), Scalar(0, 0, 128), -1);
    // 다양한 사각형 그리기

    circle(img, Point(300, 120), 30, Scalar(255, 255, 0), -1, LINE_AA);
    circle(img, Point(300, 120), 60, Scalar(255, 0, 0), 3, LINE_AA);
    // 다양한 원 그리기

    ellipse(img, Point(120, 300), Size(60, 30), 20, 0, 270, Scalar(255, 255, 0), -1, LINE_AA);
    ellipse(img, Point(120, 300), Size(100, 50), 20, 0, 360, Scalar(0, 255, 0), 2, LINE_AA);
    // 다양한 타원 그리기
        
    vector<Point> pts;
    pts.push_back(Point(250, 250));
    pts.push_back(Point(300, 250));
    pts.push_back(Point(300, 300));
    pts.push_back(Point(350, 300));
    pts.push_back(Point(350, 350));
    pts.push_back(Point(250, 350));
    // pts 벡터에 도형의 위치 정보 저장

    polylines(img, pts, true, Scalar(255, 0 ,255), 2);
    // 내부 색 채우기 shift

    imshow("img", img);
    waitKey(0);
    
    destroyAllWindows();
}
```





### 문자열 출력하기

> 때로는 영상에 처리 결과나 추가적인 정보를 문자열 형태로 나타나는 것이 보기 좋을 경우가 있기 때문에 OpenCV에서 지원하는 폰트로 문자열을 출력하는 putText()함수를 사용해서 문자열을 출력하는 방법을 알아보겠습니다.

```
void putText(InputOutputArray img, const String& text, Point org, int fontFace, double fontScale, Scalar color, int thickness, int lineType, bool bottomLefrOrigin = false);
// img에 text 문자열을 org로 받은 위치의 우측 상단에 fontFace의 폰트로 fontScale크기만큼 확대/축소하여 color색상으로 작성합니다. thickness로 두께를, lineType으로 선의 종류를, bottomLeftOrigine에 true값을 주는 것으로 우측 상단이 아니라 좌측 하단의 위치로 바꿔서 출력할 수 있습니다.
```

+ HersheyFonts 열거형 상수
> FONT_HERSHER_SIMPLEX // 일반 크기의 산세리프 폰트
> FONT_HERSHER_PLAIN // 작은 크기의 산세리프 폰트
> FONT_HERSHER_DUPLEX // 일반 크기의 두꺼운 산세리프 폰트
> FONT_HERSHER_COMPLEX // 일반 크기의 세리프 폰트
> FONT_HERSHER_TRIPLEX // 일반 크기의 두꺼운 세리프 폰트
> FONT_HERSHER_COMPLEX_SMALL // 작은 크기의 세리프 폰트
> FONT_HERSHER_SCRIPT_SIMPLEX // 필기체 스타일의 폰트
> FONT_HERSHER_SCRIPT_COMPLEX // 두꺼운 필기체 스타일의 폰트
> FONT_HERSHER_ITALIC // 이텔릭 폰트

```
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
    // 다양한 폰트 작성
    
    imshow("img", img);
    waitKey(0);
}
```

```
Size getTextSize(const String& text, int fontFace, double fontScale, int thickness, int* baseLine);
// text 문자열을 fontFace의 폰트로 fontScale만큼 확대/축소하여 thickness의 두께로 baseLine위치에 출력합니다. baseLine은 가장 하단의 텍스트 위치를 기준으로 하는 기준선의 y좌표를 의미하고 필요 없으면 0을 작성하면 됩니다.
```

```
void drawText2()
{
    Mat img(200, 640, CV_8UC3, Scalar(255, 255, 255));
    
    const String text = "Hello, OpenCV";
    int fontFace = FONT_HERSHEY_TRIPLEX; // 폰트 설정
    double fontScale = 2.0; // 크기 설정
    int thickness = 1; // 두께 설정
    
    Size sizeText = getTextSize(text, fontFace, fontScale, thickness, 0);
    Size sizeImg = img.size();
    
    Point org((sizeImg.width - sizeText.width) / 2, (sizeImg.height + sizeText.height) / 2); // 중앙에 출력하기 위해서 좌표 계산
    putText(img, text, org, fontFace, fontScale, Scalar(255, 0, 0), thickness); // 문자열 출력
    rectangle(img, org, org + Point(sizeText.width, -sizeText.height), Scalar(255, 0, 0), 1); // 문자열을 감싸는 사각형 생성
    
    imshow("img", img);
    waitKey(0);
    
    destroyAllWindows();
}
```





### 키보드 이벤트 처리

> OpenCv에서 키보드 이벤트를 처리하기 위해서는 waitKey() 함수 등을 사용합니다. 그러나 waitKey()함수는 f1, f2같은 함수키나 화살표 키 등의 특수키 입력은 처리하지 못하기 때문에 대신 waitKeyEx() 함수를 사용해야 합니다. waitKeyEx()의 함수 반환값은 책 160쪽에 있습니다.





### 마우스 이벤트 처리

> 키보드 이벤트를 처리하는 waitKey()함수가 있는 것처럼 마우스의 입력을 처리하기 위한 함수도 OpenCV내에서 정의되어 있습니다. 이 함수를 통해서 클릭이나 드래그하여 영상에 그림을 그리는 등의 다양한 동작을 수행할 수 있습니다. 마우스 이벤트를 처리하기 위해서는 마우스 콜백 함수를 등록한 뒤에 마우스 콜백 함수에 마우스 이벤트를 처리하는 코드를 추가해야 합니다

```
void setMouseCallback(const String& winname, MouseCallback onMouse, void* userdata = 0);
// winname으로 마우스 이벤트를 처리할 창의 이름을 지정하고, onMouse로 마우스 이벤트 처리를 위한 콜백함수의 이름을 정의합니다. userdata를 통해서 콜백 함수에 전달할 사용자의 데이터 포인터를 전달할수도 있습니다.
```

```
typedef void (*MouseCallback)(int event, int x, int y, int flags, void* userdata); // event에는 MouseEventType으로 정의된 열거형 상수 중 하나가 전달되고, 마우스 이벤트가 발생한 위치는 (x, y)의 형태로 전달됩니다. flags에는 MonseEventFlags열거형 상수의 논리합 조합이 전달되고, userdata는 setMouseCallback()함수에서 전달한 userdata가 전달됩니다.
```

+ MouseEventType열거형 상수
> EVENT_MOUSEMOVE (0) // 마우스가 창 위에서 움직이는 경우
> EVENT_LBUTTONDOWN (1) // 마우스 왼쪽 버튼을 누르는 경우
> EVENT_RBUTTONDOWN (2) // 마우스 오른쪽 버튼을 누르는 경우
> EVENT_MBUTTONDOWN (3) // 마우스 가운데 버튼을 누르는 경우
> EVENT_LBUTTONUP (4) // 마우스 왼쪽 버튼을 떼는 경우
> EVENT_RBUTTONUP (5) // 마우스 오른쪽 버튼을 떼는 경우
> EVENT_MBUTTONUP (6) // 마우스 가운데 버튼을 떼는 경우
> EVENT_LBUTTONDBCLK (7) // 마우스 왼쪽 버튼을 두 번 누르는 경우
> EVENT_RBUTTONDBCLK (8) // 마우스 오른쪽 버튼을 두 번 누르는 경우
> EVENT_MBUTTONDBCLK (9) // 마우스 가운데 버튼을 두 번 누르는 경우
> EVENT_MOUSEWHELL (10) // 마우스 휠을 앞뒤로 돌리는 경우
> EVENT_MOUSEHWHEEL (11) // 마우스 휠을 좌우로 돌리는 경우

+ MouseEventFlags열거형 상수
> EVENT_FLAG_LBUTTON (1) // 마우스 왼쪽 버튼이 눌려 있음
> EVENT_FLAG_RBUTTON (2) // 마우스 오른쪽 버튼이 눌려 있음
> EVENT_FLAG_MBUTTON (4) // 마우스 가운데 버튼이 눌려 있음
> EVENT_FLAG_CTRLKEY (8) // ctrl키가 눌려 있음
> EVENT_FLAG_SHIFTKEY (16) // shifr키가 눌려 있음
> EVENT_FLAG_ALTKEY (32) // alt키가 눌려 있음





### 마우스 이벤트 처리 예제 코드

> 이벤트가 그려질 영상은 setMouseCallback의 인자로 전달하여 왼쪽 마우스를 누르면 누르거나 떼면 좌표과 선을 출력합니다. 

```
Mat global_img; // Mat 전역 객체 선언
Point ptOld; // Point 전역 객체 선언
void on_mouse(int event, int x, int y, int flags, void*)
{
    switch(event){ // 해당하는 정수에 해당하는 위치로 이동하고 그 다음 위치 실행
        case EVENT_LBUTTONDOWN: // == case 1:
            ptOld = Point(x, y); // 마우스 좌표 지정
            cout<<"EVENT_LBUTTONDOWN: "<<x<<", "<<y<<endl;
            break;
        case EVENT_LBUTTONUP: // == case 4:
            cout<<"EVENT_LBUTTONUP: "<<x<<", "<<y<<endl;
            break;
        case EVENT_MOUSEMOVE: // == case 0:
            if(flags & EVENT_FLAG_LBUTTON){
                line(global_img, ptOld, Point(x,y), Scalar(0,255,255), 2); // 선 그리기
                imshow("img", global_img);
                ptOld = Point(x,y);
            }
            break;
        default:
            break;
    }
}

int main(void)
{
   global_img = imread("Sample.jpg");
   
   if(global_img.empty()){
       cerr<<"Image load failed!"<<endl;
       return -1;
   }
   
   namedWindow("img");
   setMouseCallback("img", on_mouse);
   
   imshow("img", global_img);
   waitKey();
   
   return 0;
}
```





### 트랙바 사용하기

> OpenCV를 이용하면 함수 몇 가지만 호춣해서 새로운 창을 만들고 영상을 출력할 수 있습니다. 이 때 창 안에 영상만 출력하는 것이 아니라 사용자의 입력을 받을 수 있는 Graphic User Interface를 추가하고 싶을 때도 있습니다. OpenCV는 다양한 운영체제에서 동작하기 때문에 많은 GUI를 제공하지는 않지만, 트랙바 인터페이스는 제공합니다. 트랙바는 다른 말로 슬라이더 컨트롤 이라고도 부릅니다

```
int createTrackbar(const String& trackbarname, const String& winname, int* value, int count, TrackbarCallback onChange = 0, void* userdata = 0);
// trackbarname으로 트랙바의 이름을 받아서 winname 창에 트랩ㄱ바의 위치가 변경될 때마다 onChange함수를 실행합니다. 트랙바의 위치는 value로 받고, 트랙바의 최대 위치는 count로 받습니다.
```

```
int getTrackbarPos(const String& trackbarname, const String& winname); // trackbarname의 트랙바가 winnname창 안에 있는 좌표를 반환합니다.
```

```
void setTrackbarPos(const String& trackbarname, const String& winname, int pos); // trackbarname의 트랙바를 winname창 안의 pos위치로 이동시킵니다
```





### 트랙바를 이용한 그레이스케일 레벨 표현

> 트랙바를 움직이면 해당하는 밝기로 영상이 출력되는 프로그램을 만들어보겠습니다.

```
void on_level_change(int pos, void* userdata)
{
    Mat img = *(Mat*)userdata; // userdata를 Mat형으로 참조합니다

    img.setTo(pos* 16); // pos에 16을 곱한 결과로 픽셀 값을 설정하고, pos * 16이 255보다 크면 포화 연산이 적용됩니다.
    imshow("image", img);
}

int main()
{
    Mat img = Mat::zeros(400, 400, CV_8UC1); // 400X400 0으로 초기화된 영상 출력

    namedWindow("image");
    createTrackbar("level", "image", 0, 16, on_level_change, (void*)&img); // 트랙바 콜백 함수 등록

    imshow("image", img);
    waitKey();
}
```





### OpenCV 데이터 파일 입출력

> OpenCv에서는 Mat클래스에 저장된 영상 데이터를 imwrite()함수를 이용하여 BMP, JPG, PNG등의 영상 파일로 저장할 수 있습니다. 그러나, uchar형이 아니라면 영상 파일 형식으로 저장할 수 없습니다. 따라서 OpenCV에서는 일반적인 행렬을 범용적인 데이터 저장 방식으로 저장하고 불러오는 기능을 제공합니다. 따라서 OpenCV에서는 Mat객체 뿐만 아니라 XML, YAML, JSON등으로 파일 형식을 FileStorage에 저장할 수 있습니다.


```
class FileStorage
{
public:
    FileStroage();
    FileStorage(const String& filename, int flags, const String& encoding = String()); // filename파일을 flags형식으로 열어서 encoding방식으로 인코딩해서 객체를 생성합니다.

    virtual bool open(const String& filename, int flags, const String& encoding = String()); // filename파일을 flags형식으로 열어서 encoding방식으로 인코딩하고 성공하면 true, 실패하면 false를 반환합니다.
    virtual bool isOpened() const; // 파일이 정상적으로 저장되었는지 확인합니다.
    virtual void realease(); // 저장된 메모리를 해제합니다.

    FileNode opeartor[](const char* nodename) const; // 파일에서 데이터를 읽어서 FileNode 객체를 반환합니다.
};

// 파일에 데이터 저장할 때 사용되는 연산자입니다.
// fs객체에 value, str 중에 하나를 골라서 저장합니다.
template<typename _Tp> static
FileStorage& operator << (FileStorage& fs, const _Tp& value);
static FileStorage& operator <<(FileStorage& fs, const String& str);
static FileStorage& operator <<(FileStorage& fs, const char* str);

// 파일에서 데이터를 읽어올 때 사용되는 연산자입니다.
// fs객체에 value, str 중에 하나를 골라서 읽어옵니다.
tempalte<typename _Tp> static
void opeartor >>(cont FileNode& n, _Tp& value)
template<typename _Tp> static
void opeartor >>(cont FileNode& n, std::vector<_Tp>& vec)
```

+ FileStorage::mode 열거형 상수
> FileStorage::READ // 읽기 모드
> FileStorage::WRITE // 새로 생성
> FileStorage::APPEND // 추가 작성
> FileStorage::MEMORY // ||연산자에 FileStorage::READ, FileStorage::WRITE실제 파일 입출력 대신에 메모리 버퍼를 이용하여 입출력을 수행



```
String filename = "mydata.json"; // 파일 네임의 이름을 mydata.json으로 설정 (JSON형식)

void writeData()
{
	String name = "Jane";
	int age = 10;
	Point pt1(100, 200);
	vector<int> scores = { 80, 90, 50 };
	Mat mat1 = (Mat_<float>(2, 2) << 1.0f, 1.5f, 2.0f, 3.2f);

	FileStorage fs; // 빈 파일 스토리지 객체 생성
	fs.open(filename, FileStorage::WRITE); // WRITE형식으로 filename에 fs.open()함수 실행

	if (!fs.isOpened()) {
		cerr << "File open failed!" << endl;
		return;
	}

	fs << "name" << name; // 데이터 입력
	fs << "age" << age;
	fs << "point" << pt1;
	fs << "scores" << scores;
	fs << "data" << mat1;

	fs.release(); // 메모리 해제
}

void readData()
{
	String name;
	int age;
	Point pt1;
	vector<int> scores;
	Mat mat1;

	FileStorage fs(filename, FileStorage::READ); // READ형식으로 filename에 fs.open()함수 실행

	if (!fs.isOpened()) {
		cerr << "File open failed!" << endl;
		return;
	}
	
	fs["name"] >> name; // 데이터 출력
	fs["age"] >> age;
	fs["point"] >> pt1;
	fs["scores"] >> scores;
	fs["data"] >> mat1;

	fs.release(); // 메모리 해지

	cout << "name: " << name << endl;
	cout << "age: " << age << endl;
	cout << "point: " << pt1 << endl;
	cout << "scores: " << Mat(scores).t() << endl;
	cout << "data:\n" << mat1 << endl;
}


int main(void)
{
	writeData();
	readData();

	return 0;
}
```





### 유용한 OpenCV함수

> OpenCV 라이브러리에서는 사용자의 편의를 위하여 여러 가지 함수를 제공합니다. 예를 들어서 일부 영역에 대해서만 특정 연산을 수행하는 함수나, 최적화를 위해 프로그램의 어느 영역이 연산 시간이 긴지 측정할 수 있는 함수 등이 있습니다.



+ 마스크 연산

> 사각형이 아닌 임의의 ROI(Region Of Interest)에 대하여, 그 부분에서만 연산을 할 수 있도록 도와주는 함수입니다. mask객체는 깊이가 CV_8U입니다.

```
Mat& Mat::setTo(InputArray value, InputArray mask = noArray()) // mask로 넘겨받은 영역에 대하여 valu값으로 넘겨준 값으로 변경합니다. mask의 크기는 원본 객체와 같아야 하고, noArray()로 설정하면 모든 값에 대하여 마스크 연산을 수행합니다.
void Mat::copyTo(OutputArray m, InputArray mask) const; // 기존 객체에서 mask에 해당하는 부분의 행렬만 m의 행렬로 교체합니다.
```



+ 연산 시간 측정

> 프로그램의 최적화를 위해서 어느 파트에서 가장 시간이 많이 걸리는지 알기 위해서 사용하는 함수입니다. 여기서는 틱을 사용하여 카운트하는데 틱 횟수는 컴터 시스템에서 발생하는 클럭처럼 매우 빠르게 증가하는 성능 측정 계수를 의미하며, 컴퓨터 성능에 따라서 좀 더 빠르거나 느릴 수 있습니다.

```
int64 getTickCount(void) // 시스템의 현재 틱 횟수를 반환합니다.
double getTickFrequenty(void) // 시스템의 초당 틱 횟수를 반환합니다.

class TickMeter
{
public:
	TickMeter(); // 기본 생성자입니다.
	
	void start(); // 측정을 시작합니다.
	void stop(); // 측정을 중단합니다.
	void reset(); // 모든 멤버 변수 값을 0으로 초기화합니다.
	
	double getTimeMicro() const; // 연산 시간을 마이크로 단위로 반환합니다.
	double getTimeMilli() const; // 연산 시간을 밀리초 단위로 반환합니다.
	double getTimeSec() const; // 연산 시간을 초 단위로 반환합니다.
	int64 getCounter() const; // 연산 시간 측정을 수행한 횟수를 반환합니다.
};
```



+ OpenCV 기타 유용한 함수

> 다음부터는 범용적으로 사용할 수 있는 OpenCV의 함수에 대해서 알아보겠습니다.

```
Scalar sum(InputArray src); // 1~4채널인 src를 인자로 받아들여서 src내부의 모든 원소의 값을 채널 별로 반환합니다.
Scalar mean(InputArray src, InpurArray mask = noArray()); // 1~4채널의 src를 인자로 받아들여서 mask영역에 대한 평균을 구합니다. 이 때. mask영역이 noArray()이면 src안의 모든 값에 대한 평균을 구합니다.
void minMaxLoc(InputArray src, double* minVal, double* maxVal = 0, Point* minLoc = 0, Point* maxLoc = 0, InputArray mask = noArray() // src로 받은 행렬에 대해서 최솟값을 minVal에 저장하고 그 위치를 minLoc에 저장하며, 최댓값을 maxVal에 저장하고, 그 위치를 maxLoc에 저장합니다. 이 때 마스크를 통해서 범위를 한정지을 수 있습니다.
int cvRound(double value); // 실수값의 크기가 반올림했을 때 정수값 범위 이내에 있을 때, value의 반올림 값을 구합니다. 이 때, 소수점값이 정확하게 0.5이면 가장 가까운 짝수를 반환합니다. 만약에 정수값 범위 밖에 있는 실수의 경우, 알 수 없는 값이 반환됩니다.
int cvRound(float value); // 실수값의 크기가 반올림했을 때 정수값 범위 이내에 있을 때, value의 반올림 값을 구합니다. 이 때, 소수점값이 정확하게 0.5이면 가장 가까운 짝수를 반환합니다. 만약에 정수값 범위 밖에 있는 실수의 경우, 알 수 없는 값이 반환됩니다.
```





```
void mask_setTo()
{
	Mat src = imread("lenna.bmp", IMREAD_COLOR); // 사진 하나를 저장하는 Mat객체 생성
	Mat mask = imread("mask_smile.bmp", IMREAD_GRAYSCALE); // src객체의 mask 부분 변경을 위한 새로운 Mat객체 생성

	if (src.empty() || mask.empty()) {
		cerr << "Image load failed!" << endl;
		return;
	}

	src.setTo(Scalar(0, 255, 255), mask); // src.setTO() 함수로 mask 부분만 노란색이 나오도록 함수에 전달

	imshow("src", src);
	imshow("mask", mask);

	waitKey(0);
	destroyAllWindows();
}

void mask_copyTo()
{
	Mat src = imread("airplane.bmp", IMREAD_COLOR); // 넣고 싶은 Mat객체 생성
	Mat mask = imread("mask_plane.bmp", IMREAD_GRAYSCALE); // mask의 영역을 설정하기 위한 Mat객체 생성
	Mat dst = imread("field.bmp", IMREAD_COLOR); // 결과 파일로 담고 싶은 Mat객체 생성

	if (src.empty() || mask.empty() || dst.empty()) {
		cerr << "Image load failed!" << endl;
		return;
	}

	src.copyTo(dst, mask); // src객체에서 mask부분만 추출해서 dst객체에 출력

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

	TickMeter tm; // 틱 객체 생성
	tm.start(); // 틱 측정 시작

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

	cout << "Sum: " << (int)sum(img)[0] << endl; // img내부의 모든 값의 합
	cout << "Mean: " << (int)mean(img)[0] << endl; // img내부의 모든 값의 평균

	double minVal, maxVal;
	Point minPos, maxPos;
	minMaxLoc(img, &minVal, &maxVal, &minPos, &maxPos); // img내부의 최솟값과 그 위치, 최댓값과 그 위치

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
    mask_setTo();
    mask_copyTo();
    time_inverse();
    useful_func();
}
```

