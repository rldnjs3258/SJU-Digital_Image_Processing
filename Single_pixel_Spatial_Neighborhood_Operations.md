# 1. Some basic relationships between pixels
 (1) 픽셀의 Neighbors
  - 좌표 (x,y)에 있는 픽셀 p는 다음 4개의 수평, 수직 이웃을 가진다.
  - (x+1, y), (x-1, y), (X, y+1), (x, y-1) 이 4개의 Neighbors를 p에 대해서 N4(p)라고 한다.

 (2) 픽셀의 대각선(Diagonal) Neighbors
  - 좌표 (x,y)에 있는 픽셀 q는 다음 4개의 대각선 이웃을 가진다.
  - (x+1, y+1), (x+1, y-1), (x-1, y+1), (x-1, y-1) 이 4개의 Diagonal Neighbors를 p에 대해서 ND(p)라고 한다.

 (3) N8(p)
  - 위의 N4(p)와 ND(p)를 더한 총 8명의 이웃을 N8(p)라고 한다. (N8(p) = N4(p) + ND(p))

<br>
<hr>
<br>

# 2. Some basic relationships between pixels
 - N4(p)를 좌표상에서 쉽게 나타내면 점 P(x,y)의 주변으로
 
   N = (x-1, y), E = (x, y+1), W = (x, y-1), S = (x+1, y)의 동서남북 십자가 모양으로 4 점이 위치하는 것이다.
 - ND(p)를 좌표상에서 쉽게 나타내면 점 P(x,y)의 주변으로
 
   NE = (x-1, y+1), SE = (x+1, y+1), NW = (x-1, y-1), SW = (x+1, y-1)의 상하 대각선의 좌, 우측으로 4 점이 위치하는 것이다.
 - N8(P) = {N, E, W, S, NE, SE, NW, SW} = N4(P)와 ND(P)의 합집합


<br>
<hr>
<br>

# 3. Adjacency
 - V를 픽셀을 모으는 픽셀 컬렉션이라고 할 때, V에 p와 q의 픽셀이 있다고 하자.
  1) q가 N4(p)에 속할 때 : p와 q는 4-adjacency이다.
  2) q가 N8(p)에 속할 때 : p와 q는 8-adjacency이다.
  3) q가 N4(p)에 속하거나, q가 ND(p)에 있고 N4(p)와 N4(q)의 교집합이 V에 없을 경우 : p와 q는 m-adjacency이다.


<br>
<hr>
<br>

# 4. Path, Connected pixels, regions, edge
 (1) Path
  - 인접한 픽셀 p에서 q까지의 경로 혹은 curve이다. 즉 픽셀이 연결되어 있는 걸 path라고 한다.
  - path의 길이는 해당 path의 픽셀 수로 나타낸다.
  - Closed path : 픽셀들이 여러개 있을 때, 시작 픽셀과 끝 픽셀이 같으면 Closed path(닫힌 경로)이다.

 (2) Connected pixels
  - 두 픽셀 사이에 path가 있으면 '픽셀은 연결' 된다. (Connected pixels)
  - 한 픽셀로 연결된 픽셀들의 집합을 connected component(연결된 구성 요소)라고 한다.
  - Connected component가 하나만 있는 경우, Connected set(연결 집합)이라고 한다.

 (3) Region
  - R이 Connected set(연결 집합)일 때, R을 이미지의 region이다.
  - R의 boundary는 region 내부에 하나 이상의 neighbors(Not R)를 가지고 있는 픽셀 세트이다.

 (4) Edge
  - Gray level discontinuity(불연속 그레이 레벨)
  - 급격하게 변화하는 부분


<br>
<hr>
<br>

# 5. Distance measures
 (1) D는 픽셀 p, q, z에 대해서 거리를 구하는 함수(metric)이다.
  - D(p,q) >= 0 : 거리는 항상 0보다 크거나 같다.
  - D(p,q) = 0 : p와 q의 거리가 0인 것은, p와 q가 같다는 뜻이다. (p = q)
  - D(p,z) <= P(p,q) + D(q,z) : 한 점을 올 곧게 가는 점 보다, 다른 점을 거쳐 가는 점이 거리가 오래 걸린다.

 (2) 유클리드 거리
  - De(p,q) = [(x-s)^2 + (y-t)^2]^1/2
  - 피타고라스의 정리를 이용하여 두 픽셀 사이의 최단 거리를 구함.

 (3) D4 distance(City-block distance)
  - D4(p,q) = |x-s|+|y-t|
  - 실제의 거리에서 우리는 어떤 점을 가야 할 때, 최단의 거리로 갈 수 있는 게 아닌 블록 블록 거리를 통해 가야 한다.

 (4) D8 distance(chessboard distance)
  - D8(p,q) = max(|x-s|, |y-t|)
  - 체스 게임을 생각하면 된다. x방향과 y방향 크기의 max를 구한다.


<br>
<hr>
<br>

# 6. Linear operation (선형 연산자)
 (1) 아래의 경우 H는 선형 연산자이다.
  - H[aifi(x,y) + ajfj(x,y) = aiH[fi(x,y)] + ajH[fj(x,y)] : 상수인 a를 앞으로 끄집어 낼 수 있다.
  - H[f(x,y)] = g(x,y)
  
    f(x,y)와 g(x,y)는 같은 사이즈의 이미지이다.

 (2) 두 이미지의 합에 선형 연산자를 적용한 결과는 개별적 이미지에 선형 연산자를 적용한 것과 동일하다. 결과에 적절한 상수를 곱한 다음 그 결과를 더한다.
  - H[aifi(x,y) + ajfj(x,y) = aiH[fi(x,y)] + ajH[fj(x,y)] = aigi(x,y) + ajgj(x,y)

 (3) H가 합계 연산자 ∑라고 가정한다. (∑의 위치가 바뀌어도 상관없다.)
  - ∑[aifi(x,y) + ajfj(x,y)] = ∑aifi(x,y) + ∑ajfj(x,y)
   = ai∑fi(x,y) + aj∑fj(x,y)
   = aigi(x,y) + ajgj(x,y)


<br>
<hr>
<br>

# 7. Arithmetic operation
 - 픽셀 쌍 사이에서 산술 연산이 일어날 수 있다.
 
   s(x,y) = f(x,y) + g(x,y)
   
   d(x,y) = f(x,y) - g(x,y)
   
   p(x,y) = f(x,y) * g(x,y)
   
   v(x,y) = f(x,y) / g(x,y)
   
 - g(x,y) = f(x,y) + n(x,y) : 실제 찍은 영상 = 잡음이 없는 영상 + 노이즈
 - 실제 찍은 영상인 g(x,y)를 k번 평균내면 노이즈가 줄어든다.
 
   노이즈는 uncorrelated이며, 노이즈의 평균 값은 0이다.
 - E[ni(x,y)]가 0이고, 사진을 k번 찍었을 때
 
   E[(ni(x,y) - ni(x,y)의 평균)(nj(x,y) - nj(x,y)의 평균)] = 0이 되면 uncorrelated이다.


<br>
<hr>
<br>

# 8. 노이즈와 관련 된 식 확인하기


<br>
<hr>
<br>

# 9. Image averaging
 - 이미지는 Galaxy Pair NGC 3314의 이미지이다. 이 이미지는 가우스 노이즈에 의해 잡음이 생겼다.
 - 5, 10, 20, 50개의 노이즈가 낀 이미지를 평균 낸 결과 노이즈가 점차 줄어드는 것을 볼 수 있었다.
 
   노이즈가 섞인 영상을 많이 찍어서 평균 내면 이미지의 노이즈를 줄일 수 있다.


<br>
<hr>
<br>

# 10. Image subtraction
 - g(x,y) = f(x,y) - h(x,y) : 이미지 끼리의 뺄셈
 - 이미지 끼리의 뺄셈을 적용해서 '같은 이미지끼리의 차이'를 찾아낼 수 있다.
 
   물체는 가만히 있는데 배경만 바뀌었다던가 하는 차이를 쉽게 찾을 수 있다.
 - 그림의 예제는 사람의 혈관 이미지와 그 이미지를 마스크 한 이미지를 뺄셈해서
 
   두 이미지 사이의 차이 이미지를 얻어내고, 그 이미지를 뚜렷하게 만드는 과정이다. 
   
   사람 혈관 내에 막힌 게 있는지 찾을 때 이 방법이 도움 된다.


<br>
<hr>
<br>

# 11. Image multiplication
 - 이미지의 곱셈, 나눗셈은 음영을 보정하는데 많이 사용된다.
 - 이미지 곱셈은 마스킹, 즉 RoI(Region of interest)에도 많이 사용된다.
 
   예제 : 치과에서 x-ray 이미지와 진촬할 영역을 곱해서 RoI를 만든 후 본다.


<br>
<hr>
<br>

# 12. Image representation
 - 대부분의 이미지는 8 비트(0 ~ 255)를 사용하여 표시한다.
 
   24 비트의 컬러 이미지도 3개의 8비트 채널로 구성되어 있다.
   
   이미지의 픽셀이 10 비트(0 ~ 1023)인 경우에도 사람들은 종종 0 ~ 255의 값을 가질 것으로 생각한다!
   
 1) Minimum value가 0인 이미지를 생성한다.
  - fm = f - min(f)
 2) [0,K]의 범위를 갖는 scale된 이미지 fs를 생성한다.
  - fs = K*[fm/max(fm)]
  - K를 255로 설정하면 0~255의 범위로 스케일링 가능하다.


<br>
<hr>
<br>

# 13. Spatial operations
 (1) Spatial operations
  - Spatial operations는 이미지의 픽셀들에 직접 수행 된다.
  - Single-pixel operations : 개별 픽셀만 보고 operations
  
    Neighborhood operations : 주변의 픽셀들을 고려하여 operations
    
    Geometric spatial transform : 이미지를 돌리고 / scailing 함.

 (2) Single-pixel operations
  - Single-pixel operations : 개별 픽셀들의 intensity에 따라 변경한다.
  - s = T(z) 그래프에서 화살표는 input인 intensity 값을, 해당 출력값으로 변환해주는 걸 보여준다.
  
    영상이 너무 어두울 때 흑백을 바꾸는 등에 이용한다.


<br>
<hr>
<br>

# 14. Neighborhood operations
 - Neighborhood operations는 인풋 이미지의 픽셀에 특정 연산을 하여 출력 이미지의 동일 좌표에 corresponding 픽셀을 생성하는 것이다.
 - 그림의 예제는 Neighborhood processing을 이용하여 Local averaging을 한 것이다.
 
   인풋 이미지의 픽셀(x,y) 주변 일정 영역(a*b 크기의 S(x,y) 영역)을 평균내어 아웃풋의 동일 좌표(x,y)의 값으로 만들었다.
   
   g(x,y) = 1/mn∑f(r,c) (r,c∈Sxy)
 - Convolutional의 한 과정도 이와 비슷한데, 인풋 이미지를 3*3의 영역 한 픽셀 씩 옮겨가면서 평균을 취한다. 영상이 뭉개진다.


<br>
<hr>
<br>

# 15. Geometric spatial transformations
 - Geometric transformations는 이미지 픽셀들 사이의 spatial relationship을 수정한다.
 1) 좌표 변환
  - (x,y) = T{(v,w)}
 2) Affine 변환 : 이 것은 일련의 작업들을 연결하기 위한 프레임 워크를 제공한다.
