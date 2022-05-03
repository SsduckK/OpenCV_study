# Labeling

- 레이블링은 영상 내에 존재하는 객체 픽셀에 고유 번호를 매기는 작업
- 일반적으로 이진화된 영상에서 수행
  - 검은색 픽셀 - 배경 - 0
  - 흰색 픽셀 - 객체 - 0이 아닌 수



#### 연결관계

![](./image/Lab1.png)

- 특정 픽셀과 이웃한 픽셀의 연결 관계는 두 가지 방식으로 정의 가능
  1. 특정 픽셀의 상하좌우로 붙어있는 픽셀끼리 연결되어있다 정의하는 4방향 연결성-(a)
  2. 상하좌우 뿐 아니라 대각선 방향으로 인접한 픽셀도 연결되어있다 정의하는 8방향 연결성-(b)

![](./image/Lab2.png)

- 이진 영상에 레이블링을 수행하면 각각의 객체 영역에 고유의 번호가 매겨진 2차원 정수 행렬이 만들어지고 이를 레이블 맵이라 한다.



### connectComponents

```c++
int connectedComponents(InputArray image, OutputArray labels,
						int connectivity = 8, int ltype = CV_32S);
```

- image - 입력 영상
- labels - 출력 레이블 맵 행렬
- connectivity - 연결성. 8, 4를 지정
- ltype - 출력 행렬 타입
- 반환값 - 레이블 개수

![](./image/Lab3.png)

- 입력영상을 data로 생성, 255를 곱해 입력영상으로 저장
- connectedComponents 함수를 통해 실행 후 labesl에 레이블맵을 저장
- background까지 해서 number of labels가 4임에 유의



### 레이블링 응용

- connectetdComponentsWithStats

  ```c++
  int connectedComponentsWithStats(InputArray image, OutputArray labels,
  							OutputArray stats, OutputArray centroids,
  							int connectivity = 8, int ltype = CV_32S);
  ```

- image - 입력 영상
- labels - 출력 레이블 맵 행렬
- stats - 각각의 레이블 ㅇ여역에 대한 통계 정보를 담은 행렬
- centroids - 각각의 레이블 영역의 무게 중심 좌표 정보를 담은 행렬
- connectivity - 연결성
- ltype - 출력 행렬 타입
- 반환값 - 레이블 개수

![](./image/Lab4.png)

- (a) - 레이블 맵을 담고있음
- (b) - CV_32SC1의 stats 행렬
  - 행 개수는 레이블 개수
  - 열 개수는 5이다.
    - x, y, w, h, 면적(픽셀 개수)
- (c) - CV)64FC1의 centroids 행렬
  - 행 개수는 레이블 개수
  - 열 개수는 2
    - 각각 x, y좌표

![](./image/Lab5.png)



### 외곽선 검출

- 객체의 외곽선은 객체 영역 픽셀 중에서 배경 영역과 인접한 일련의 픽셀을 의미

- 검은색 배경 안에 있는 흰색 객체 영역에서 가장 최외곽에 있는 픽셀을 찾아 외곽선으로 저으이

- 객체 하나의 외곽선 정보는 vector<Point> 타입으로 정의 가능

- 하나의 영상에 여러 객체가 존재할 수 있으므로 영상 하나에서 추출된 전체 객체의 외곽선 정보는 vector<vector<Point>>로 표현 가능

- ![](./image/Lab6.png)

- findContours()

- ```c++
  void findcontours(InputArray image, OutputArrayOfArrays contours,
  					OutputArray hierarchy, int mode,
  					int method, Point offset = Point());
  void findContours(InputArray image, OutputArrayOfArrays contours,
  					int mode, int method, Point offset = Point());
  ```

- image - 입력 영상

- contours - 검출된 외곽선 정보

- hierachy - 외곽선 계층 정보

- mode - 외곽선 검출 모드

- method - 외곽선 근사화 방법

- offset - 외곽선 점 좌표의 오프셋

![](./image/Lab7.png)

![](./image/Lab8.png)

![](./image/Lab9.png)

```c++
void drawContours(InputOutputArray image, InputArrayOfArrays contours,
                int contourIdx, const Scalar& color,
                int thickness = 1, int lineType = LINE_8,
                InputArray hierarchy = noArray(),
                int maxLevel = INT_MAX, Point offset = Point());
```

- image - 외곽선을 그릴 영상
- contours - findContours()를 통해 구한 외곽선 정보
- contourIdx - 외곽선 번호
- color - 외곽선 색상
- thickness - 외곽선 두께
- lineType - 외곽선 타입
- hierarchy - 외곽선 계층 정보
- maxLevel - 그릴 외곽선의 최대 레벨
- offset - 추가적으로 지정할 외곽선 점 좌표의 오프셋