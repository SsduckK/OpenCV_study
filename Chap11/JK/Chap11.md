# 영상의 이진화

- 그레이스케일 영상의 픽셀을  0, 255로 변환하는 이진화
- 영상의 이진화는 영상에서 관심 있는 객체 영역과 배경 영역을 구분하는 용도로 활용



### 이진화

- 이진 영상은 일반적으로 흰색, 검은색 픽셀로만 구성된다

![](./image/Bin2.png)

![](./image/Bin1.png)

- 원본 - 126 - 190 - 53
- TrackBar의 위치에 따라서 Threshold가 변함
- 변화한 Threshold에 따라 0과 255의 분포가 차이가 있음



### 적응형 이진화

```c++
void adaptiveThreshold(InputArray src, OutputArray dst,
                      double maxValue, int adaptiveMethod,
                      int thresholdType, int blockSize, double C);
```

- iamge - 입력 영상
- dst - 출력 영상. src와 같은 크기, 타입
- maxValue - 이진화 결과 영상의 최댓값
- adaptiveMethod - 적응형 이짛놔에서 블록 평균 계산 방법 지정.
  - ADAPTIVE_THRESH_MEAN_C  또는 ADAPTIVE_THRESH_GAUSSIAN_C 중 하나 사용
- thresholdType - THRESH_BINARY 또는 THRESH_BINARY_INV 둘 중 하나를 지정
- blockSize - 임계값 계산 시 사용하는 블록 크기, 3보다 같거나 큰 홀수를 지정
- C - 임계값 조정을 위한 상수, 블록 평균에서 C를 뺀 값을 임계값으로 사용

![](./image/Bin3.png)

- 1 - (1, 2, 3) 은 기본 Threshold를 이용하였을 떄
- 2 - (2, 3)은 AdaptiveThreshold를 이용하였을 때
- 위 코드에서 void on_threshold에서 threshold(37번째 줄)을 다음과 같이 바꾸어 실행
  - adaptiveThreshold(src, dst, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, bsize, 5);

- Adaptive Threshold 의 원리는 다음과 같다.

  - 영상의 모든 픽셀에서 정해진 크기의 사각형 블록 영역을 설정

  - 영역 내부의 픽셀값 분포로부터 고유의 임계값을 결정하여 이진화

  - 이때 (x, y)좌표에서의 임계값 T(x, y)는 다음과 같은 수식을 통해 결정된다.

  - $$
    T(x, y) = \mu(x, y) - C
    \\\mu(x, y) = Average of (x, y)
    $$



### 모폴로지 연산

- 이진연산의 침식과 팽창
- ![](./image/Bin4.png)

- (a) 이미지에 (b) 커널을 통해서 모폴로지 연산을 수행한 결과
- (c) - 침식
- (d) - 팽창



```c++
Mat getStructuringElement(int shape, Size ksize, Point anchor = Point(-1, -1));
```

- shape - 구조 요소의 모양
- ksize - 구조 요소의 크기
  - 일반적으로 모두 홀수로 지정
- anchor - MORPH_CROSS 모양의 구조 요소 Point(-1, -1)을 지정하면 구조 요소 중앙을 중심 좌표로 활용
- 반환값 - 구조 요소 행렬



침식(erode) 연산

```c++
void erode(InputArray src, OutputArray dst, InputArray kernel,
           Point anchor = Point(-1, -1), int iterations = 1,
           int borderType = BORDER_CONSTANT,
           const Scalar& borderValue = morphologyDefaultBorderValue());
)
```

팽창(dilate) 연산

```c++
void dilate(InputArray src, OutputArray dst, InputArray kernel,
           Point anchor = Point(-1, -1), int iterations = 1,
           int borderType = BORDER_CONSTANT,
           const Scalar& borderValue = morphologyDefaultBorderValue());
)
```

- src - 원본 영상
- dst - 출력 영상, src와 같은 타입, 크기
- kernel - 구조 요소
- iterations - 반복 횟수

![](./image/Bin5.png)

bin - 이진화 한 영상

erode - 침식이 진행된 영상

dilate - 팽창이 진행된 영상

- 붉은색 네모 안쪽을 비교해가면서 확인 가능

![](./image/Bin6.png)

- 저자가 공부할때 사용한 이미지 샘플들
- 침식 및 팽창 연산을 통해 문자를 단어 단위로 끊은 후 findContour를 통해 단어를 녹색 사각형으로 둘러싼 모습