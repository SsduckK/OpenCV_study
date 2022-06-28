# 3장 OpenCV 주요 클래스



### 3.3 Vec과 Scalar 클래스



##### Vec 클래스

> 하나의 행으로만 이루어진 행렬은 행 벡터라고 부르고, 하나의 열로만 구성된 행렬은 열 벡터라고 부름. 그리고 행 벡터와 열 벡터를 합쳐서 벡터 또는 벡터 행렬이라고 부름. 즉, 벡터는 같은 자료형을 가진 원소 몇 개로 구성된 데이터 형식.



- 간략화한 Matx와 Vec 클래스 정의

  ```c++
  template<typename _Tp, int m, int n> class Matx
  {
  public:
      …
      _Tp val[mn]; //< matrix elements
  };
   
  template<typename _Tp, int cn> class Vec : public Matx<_Tp, cn, 1>
  {
  public:
      …
   /! element access */
      _Tp& operator[](int i);
  };
  
  
  template<typename _Tp, int n> static inline
  std::ostream& operator << (std::ostream& out, const Vec<_Tp, n>& vec);
  ```

  