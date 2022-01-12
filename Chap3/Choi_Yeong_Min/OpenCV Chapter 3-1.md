# 3장 OpenCV 주요 클래스



#### Point_클래스

- 2차원 평면 위에 있는 점의 좌표를 표현하는 템플릿 클래스

- 2차원 좌표를 나타내는 x, y 멤버변수를 가지고 있음

```c++
template<typename_Tp> class Point_
{
    public:
    point_();									// 기본생성자, x = 0, y = 0 초기화
    point_(_Tp_x, _Tp_y);						// (_x, _y)생성자, x = _x, y = _y 초기화
    Point_(const point_& pt);					// 복사생성자, x = pt.x, y = pt.y 초기화
    
    point_& operator = (const Point_& pt);		// 대입 연산자 재정의
    
    _Tp dot(const Point_& pt) const;
    //Point::dot() 멤버 함수는 두 점 사이의 내적(dot product)을 구함
    double ddot(const Point_& pt) const;
    //Point::ddot() 멤버 함수는 두 점사이의 내적을 실수형으로 계산하여 double 자료형으로 반환
    double cross(const Point_& pt) const;
    // Point::cross() 멤버 함수는 두 점 사이의 외적(cross product)을 반환
    boolinside(const Rect_<_Tp>& r) const;
    // Point::inside() 멤버 함수는 점 좌표가 사각형 r영역 안에 있으면 true를 반환함
    _Tp x, y;
    // 멤버 변수, x는 x축 좌표, y는 y축 좌표를 나타냄
};

// 다양한 자료형에 대한 Point_ 클래스 이름 재정의
typedef Point_<int>		Point2i;
typedef Point_<int64>	Point2l;
typedef Point_<float>	Point2f;
typedef Point_<double>	Point2d;
typedef Point2i			Point;
```

- Point_ 클래스는 템플릿 클래스이기 때문에 사용할 때에는 어떤 자료형 좌표를 표현할 것인지 명시해야 함

- OpenCV는 자주 사용하는 자료형에 대해서  Point_ 클래스 이름을 재정의하여 제공

- Point 클래스는 2차원 정수 좌표계에서 좌표를 표현하는 자료형



point_ 클래스 사용법 예시

```c++
Point pt1;					// pt1 = (0, 0)
pt1.x = 5; pt1.y=10;		// pt1 = (5, 10)
Point pt2(10, 30);			// pt2 = (10, 30) 

Point pt3 = pt1 + pt2;		// pt3 = (15, 40)
Point pt4 = pt1 * pt2;		// pt4 = (10, 20)
int d1 = pt.dot(pt);		// d1 = 350
bool b1 = pt1 == pt2;		// b1 = false
```





#### Size_ 클래스

- 영상 또는 사각형 영역의 크기를 표현할 때에는 Size_클래스 사용
- Size_클래스는 사각형 영역의 가로와 세로 크기를 나타내는 width와 height 멤버 변수를 가짐

```c++
template<typename_Tp> class Size_
{
    public:
    Size_();							// 기본생성자, width, height 0으로 초기화
    Size_(_Tp _width, _Tp _height);		// width = _width, height = _height
    Size_(const Size_& sz);				// 복사생성자, width = sz.width, height = sz.height
    
    Size_& operator = (const Size_& sz);	// 대입 연산자 재정의
    
    _Tp area() const;	 // Size::area() 멤버 함수는 사각형 크기에 대한 면적을 반환
    bool empty() const;	 // Size::empty() 멤버 함수는 유효하지 않은 크기면 true를 반환
    
    _Tp width, height;	 // 멤버 변수, width = 가로, height = 세로
};

// 다양한 자료형에 대한 Size_ 클래스 재정의
typedef Size_<int>		Size2i;
typedef Size_<int64>	Size2l;
typedef Size_<float>	Size2f;
typedef Size_<double>	Size2d;
typedef Size2i			Size;
```

- Size_ 클래스도 템플릿으로 정의되어 있으며, 다양한 자료형에 대해 이름이 재정의되어 있음
- Size  클래스는 정수형 멤버 함수 width, height를 가지고 있는 사각형 크기 표현 클래스



Size_ 클래스 사용법 예시

```c++
Size sz1, sz2(10, 20);			// sz1 = [0 x 0], sz2 = [10 x 20]
sz.width = 5; sz1.height = 10;	// sz1 = [5 x10]
Size sz3 = sz1 + sz2;			// sz3 = [15 x 30]
Size sz4 = sz1 + 2;				// sz4 = [10 x 20]
int area1 = sz4.area();			// area1 = 200
```





#### Rect_ 클래스

- OpenCV에서 사각형의 위치나 크기 정보를 표현할 때에는 Rect_ 클래스를 사용

- Rect_ 클래스는 사각형의 좌측 상단 점의 좌표를 나타내는 x, y 멤버 변수, 가로와 세로 크기를 나타내는

  width, height 멤버변수를 가지고 있음

```c++
template<typename _Tp> class Rect_
{
    public:
    Rect_();	// 모든 멤버변수 0
    Rect_(_Tp _x, _Tp _y, _Tp _width, _Tp _height);
    // x = _x, y = _y, width = _width, height = _height
    Rect_(const Rect_& r);
    // x = r.x, y = r.y, width = r.width, height = r.height
    Rect_(const Point_<_Tp>& org, const Size_<_Tp>& sz);
    // 좌측 상단 점의 좌표와 사가형 크기 정보를 인자로 받는 생성자
    Rect_(const Point_<_Tp>& pt1, const Point_<_Tp>& pt2);
    // 사각형에서 서로 대각 위치에 있는 두 점의 좌표를 인자로 받는 생성자
    
    Rect_& operator = ( const Rect_& r );	// 대입 연산자 재정의
    
    Point_<_Tp> tl() const;		// Rect::tl() 멤버 함수는 사각형의 좌측 상단 점의 좌표를 반환
    Point_<_Tp> br() const;		// Rect::br() 멤버 함수는 사각형의 우측 하단 점의 좌표를 반환
    Size_<_Tp> size() const;	// Rect::size() 멤버 함수는 사각형의 크기 정보를 반환
    _Tp area() const;			// Rect::area() 멤버 함수는 사각형의 면적을 반환
    bool empty() const;			// Rect::empty() 멤버 함수는 유효하지 않은 사각형이면 true 반환
    bool contains(const Point_<_Tp>& pt) const;
    // Rect::contains() 멤버 함수는 인자로 전달된 pt 점이 사각형 내부에 있으면 true를 반환
    
    _Tp x, y, width, height; 	// 멤버 변수 x, y, width, height
};

// 다양한 자료형에 대하여 Rect_ 클래스 이름 재정의
typedef Rect_<int>		Rect2l;
typedef Rect_<float>	Rect2f;
typedef Rect_<double>	Rect2d;
typedef Rect2i			Rect;
```

- Rect_ 클래스도 템플릿으로 정의되어 있으며, 다양한 자료형에 대해 이름이 재정의되어 있음

- Rect 클래스는 정수형 멤버 변수 x, y, width, height를 가지고 있는 사각형 표현 클래스



Rect_ 클래스 사용법 예시

```c++
Rect rc1;						 // rc1 = [0 x 0 from (0, 0)]
Rect rc2(10, 10, 60 ,40);		 // rc2 = [60 x 40 from (10, 10)]
Rect rc3 = rc1 + Size(50, 40);	 // rc3 = [50 x 40 from (0, 0)]
Rect rc4 = rc2 + Point(10, 10);	 // rc4 = [60 x 40 from (20, 20)]
Rect rc5 = rc3 & rc4;			 // rc5 = [30 x 20 from(20, 20)]
Rect rc6 = rc3 | rc4;			 // rc6 = [80 x 60 from (0, 0)]
```





#### RotatedRect 클래스

- RotatedRect 클래스는 회전된 사각형을 표현하는 클래스

- 회전된 사각형의 중심 좌표를 나타내는 center, 사각형의 가로 세로 크기를 나타내는 size, 회전 각도 정보를

  나타내는 angle을 멤버 변수로 가진다

```c++
Class RotatedRect
{
    public:
    RotatedRect();	//기본 생성자, 멤버 변수 0으로 초기화 
    RotatedRect(const Point2f& _center, const Size2f& _size, float _angle);
    // center = _center, size = _size, angle = _angle
    RotatedRect(const Point2f& point1, const Point2f& point2, const Point2f& point3);
    // (point1, point2, point3)을 인자로 받는 생성자, 회전된 사각형의 세 꼭지점 좌표를 나타냄 
                
    void points(Point2f pts[]) const;
    // RotatedRect::points() 멤버 함수는 회전된 사각형은 네 꼭지점 좌표를 pts인자에 저장
    Rect boundingRect() const;
    /* RotatedRect::boundingRect()는 회전된 사각형을 포함하는 최소 크기의 사각형 정보를 나타냄
    (정수단위) */
    Rect_<float> boundingRect2f() const;
    /* RotatedRect::boundingRect2f()는 회전된 사각형을 포함하는 최소 크기의 사각형 정보를 나타냄
    (실수단위) */
    
    /* 멤버 변수, 사각형의 중심 좌표를 나타내는 center, 사각형의 가로 세로 크기를 나타내는 size, 회전
    각도 정보를 나타내는 angle */
    Point2f center;
    Size2f size;
    float angle;
};
```

- RotatedRect 클래스는 앞서 살펴본 Point_  ,  Size_ , Rect_  클래스와 달리 템플릿 클래스가 아니며, 모든 정보를 float 자료형을 사용하여 표현함. 즉, 중심점 좌표는 Point2f 클래스, 크기 정보는 Size2f 클래스, 회전 각도는 float 자료형 사용



RotatedRect_ 클래스 사용법 예시

```c++
RotatedRect rr1(Point2f(40, 30), Size2f(40, 20), 30.f);
// 중심 좌표 (40, 30), 크기 (40 x 20), 시계방향으로 30도 회전

Point2f pts[4];		// 회전된 사각형의 네 꼭지점 좌표가 pts 배열에 저장됨
rr1.points(pts);	// pts[0] = (17.6795, 28.6603), pts[1] ~ 형태로 좌표 설정됨 

Rect br = rr1.boundingRect();	// 실수 단위로 얻고 싶다면 RotatedRect::boundingRect2f() 사용
```

-  경우에 따라서 회전된 사각형을 감싸는 최소 크기의 사각형 정보가 필요함 = 객체를 감싸는 최소크기의 사각형: 바운딩 박스(bounding box)사용



#### Range 클래스

- Range 클래스는 범위 또는 구간을 표현하는 클래스

- Range 클래스는 범위의 시작과 끝을 나타내는 start와 end 멤버 변수를 가지고 있음

```c++
class Range
{
    public:
    Range();							// 멤버 변수 초기화
    Range(int_start, int _end);			// start = _start, end = _end
    
    int size() const;					// Range::size() 범위 크기(start-end) 반환
    bool empty() const;					// Range::empty() start와 end가 같으면 true를 변환
    static Range all();
    // Range::all() start=INT_MIN, end=INT_MAX로 설정한 Range 객체 반환
    
    int start, endl;					// 멤버변수
}
```

```c++
Range r1(0, 10);		//r1은 0부터 9까지 범위를 표현, 10은 포함되지 않음
```



#### String 클래스

- 영상 출력 창에 고유의 문자열을 지정하여 구분하고, 영상에 문자열을 출력하는 기능을 제공

- std::string과 같이 OpenCV에서는 cv::String으로 문자열 저장 및 처리 가능

```c++
typedef std::string String;

String str1 = "Hello";
String str2 = "world";
String str3 = str1 + " " + str2;		// str3 = "Hello world"

bool ret = (str2 == "WORLD");			// false
```



특정한 형식의 문자열을 만들고 싶다면 format() 함수 사용

```c++
String format(const char* fmt, ...);
```

- fmt 	  : 형식문자열
- ...          : 가변인자
- 반환값  : 지정 형식으로 생성된 문자열 