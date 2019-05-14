## 1. Viewing Geometry
 - 다음의 경우 이미지와 Observer는 공간적 변화 없이 공간 해상도(Spatial Resolution)가 1/2로 감소될 수 있다.
 
   예제의 그림에서 보는 것과 같이 눈은 2의 거리에 있는 것과 4의 거리에 있는 것을 똑같이 느낀다는 뜻이다.
   
  1) 이미지와 Observer 사이의 거리가 두 배가 되는 경우
  
  2) 이미지 크기가 1/2로 줄어드는 경우
    
<br>
<hr>
<br>

## 2. UHDTV
 (1) Interlaced와 Progressive
  - 1080i, 480i와 같이 'i'의 의미는 Interlaced이고, 720p, 480p와 같이 'p'의 의미는 Progressive이다.

 (2) HD
  - HDTV는 보통 1080i나 720p를 선호한다. 1080은 가로선이 1080개, 720은 가로선이 720개 이다. 둘 다 16:9의 비율로, 우리 눈의 비율과 같다.

 (3) SD(Standard Definition) : DVD에서 사용

 (4) UHD
  - 고효율 비디오 코딩(HEVC/H.265)
  - ISO/IEC SC29 WG11/MPEG video & ITU-T SG16 Q.6 VCEG


<br>
<hr>
<br>


## 3. Interlaced vs. Progressive
 (1) Progressive
  - 하나의 완성된 프레임을 연속적으로 전송하는 방식이다
  - Progressive 방식은 Interlaced보다 훨씬 부드럽고 안정적인 영상을 제공하지만, 두 배의 용량이 필요하다.

 (2) Interlaced
  - 화소를 다 찍지 않고, 화소의 가로줄 중 홀수선과 짝수선을 번갈아가며 찍는 방식이다.
  
    따라서 1080i60Hz는 실제로 30Hz를 번갈아 찍으며 성능을 내는 것이다.
  - 가끔 카메라로 모니터를 찍으면 모니터가 흘러내리는 것 처럼 보이는 오류가 Interlaced 때문이다.
  - 1080i는 top field인 540(30Hz)와 bottom field인 540(30Hz)가 더해진 것이다.


<br>
<hr>
<br>


## 4. Scanning(Display)
 - Object를 캡쳐할 때 Color video camera로 영상을 찍고 -> RGB로 들어온 색을 YCbCr로 프로세싱하고 -> DIP, video compression 등 프로세싱 과정(영상 향상)을 거
쳐 -> YCbCr을 다시 RGB로 바꾼 후 -> 아날로그로 모니터에 송출한다.


<br>
<hr>
<br>


## 5. Spatial Aliasing
 (1) 만약 Nyquist rate를 찾아내지 못하면 어떻게 할까?
  1) Undersampling : Undersampling은 지양해야 한다. Undersampling을 통해 Spatial Aliasing이 발생한다.
  2) Oversampling : Oversampling은 해도 좋다.

 (2) Spatial Aliasing
  - Spatial Aliasing은 Moire Pattern의 원인이 된다.
  - Undersampling을 하는 도중 High-frequency 정보들을 받게 되면, 샘플링 속도에 비해 High-frequency가 너무 빨라서 정보를 잃어버리게 된다.
  
    High-frequency 정보들은 평균되어 lower-frequency로 받아들이게 된다.


<br>
<hr>
<br>


## 6. Aliasing and Moire Pattern
 - 이미지에 반복적인 high-frequency가 있으면 Spatial aliasing이 발생할 수 있다.
 - 이미지의 예제는 Spatial aliasing이 발생한 경우인데, 이미지의 위로 갈 수록 frequency가 빨라져서 발생한 것을 알 수 있다.
 
   그 부분은 물결처럼 보이며 Aliasing(Moire Pattern)이 발생한 것을 알 수 있다.
 - 해결책 : 정말 빠른 High-frequency의 정보까지 살릴 필요는 없다.


<br>
<hr>
<br>


## 7. Aspect Ratio(화면 비율)
 - 화면 비율 = 이미지의 가로(폭) / 세로(높이)
 - 4:3 = 1.33
 
   16:9 = 1.78
 - 화면 종횡비
 
   픽셀 종횡비
 - 픽셀은 항상 정사각형이다.


<br>
<hr>
<br>


## 8. Brightness Resolution
 - Quantization : Quanatization은 아날로그 데이터를 디지털 데이터의 값으로 바꾸는 것이다.
 
		  영상은 픽셀로 이루어져 있는데, 8비트, 10비트, 12비트 등 quantization에 따라 픽셀의 range가 조절 된다.
  1) Contouring Effect : gray level이 불충분 하기 때문
  2) Dynamic Range : 회색 범위
 - 대부분의 '소비자용 이미지 시스템'은 8비트(0~255) quantization이다. 의료 영상은 10비트 혹은 12비트(0~4095)를 선호한다.
 - 이미지와 observer의 거리가 멀어질 수록 brightness contouring effect는 줄어든다.


<br>
<hr>
<br>


## 9. Color Fundamentals
 - 1666년 Isaac Neuton은 햇빛 광선은 흰색이지만, 유리 프리즘을 통과할 때 빨간색 부터 보라색 까지 연속적인 스펙트럼을 구성한다는 것을 
알게 되었다.
 - 뉴턴은 칼라 정보를 보기 위해 종이에 구멍을 뚫어 놓고 빛을 비춰 봤다. Optical Prism(스펙트럼을 넓게 해주는 도구)을 조절하면서 칼라
를 보여주고 파장에 칼라가 존재한 다는 것을 실험으로 증명했다.


<br>
<hr>
<br>


## 10. Color Fundamentals
 - 전자기 스펙트럼 중 가시광선은 상대적으로 좁은 주파수 대역을 갖고 있다. (사람이 볼 수 있는 가시광선의 영역은 적다.)
 
   전자기 스펙트럼은 왼쪽으로 갈 수록 에너지가 커지고 프리퀀시가 빨라진다.
 - 모든 가시 파장에서 균형잡히게 빛을 반사하는 물체는 흰 색으로 보인다.
 - 빛의 속도를 c라고 할 때, 프리퀀시를 알면 λ=c/v을 계산할 수 있다.
 - 플랭크 상수 : E = hv


<br>
<hr>
<br>


## 11. Color Fundamentals
 - Cone은 컬러를 보는 눈의 센서이다.
 
   Cone의 약 65%가 red에 민감하고, 33%는 green에 민감하며, 오직 2%만이 blue에 민감하다. 하지만 blue cone이 많이 민감해서 잘 볼수 있다.
 - CIE(국제 조명 위원회)는 세 가지 파장에 대한 특정 파장 값을 지정했다. 아래 그래프의 Curve를 통해 RGB의 파장대를 얻는다.
 
   blue = 435.8nm
   
   green = 546.1nm
   
   red = 700nm


<br>
<hr>
<br>


## 12. Color Resolution
 - Color를 찍는 시스템에는 두 가지가 있다.
 (1) Additive Color System(Emissive color)
  - 컬러를 표현할 때 RGB를 섞어서 컬러를 표현한다. RGB를 다 섞으면 white가 나오는데, white의 표현이 가장 어렵다.
  
    ex) Cyan을 표현하고 싶을 때 RGB 중 Green과 Blue를 섞는다.
  - 기본 색상 : Red(R), Green(G), Blue(B)
  
    (기본 색상이 반드시 RGB일 필요는 없다.)
  - 디스플레이 : TV, LCD, etc

 (2) Subtractive Color System(Reflective color)
  - 컬러를 표현할 때 전체 컬러에서 일부 컬러를 빼서 컬러를 표현한다. 개념적으로는 Additive와 같지만 상반된 칼라 표현이다. Black의 표현
이 가장 어렵다.

    ex) Cyan을 표현하고 싶을 때 전체에서 Red의 잉크만 뺀다.
  - Secondary colors : Cyan(C), Magenta(M), Yellow(Y)
  - 디스플레이 : 프린팅(컬러 프린트) 등


<br>
<hr>
<br>


## 13. RGB Color Space
 - 예제의 그래프는 기본적인 RGB의 3차원 컬러 공간이다.
 - 3차원 공간의 X, Y, Z에 R, G, B를 찍어서 큐브와 같은 그래프를 만든다. 나머지 꼭지점들에는 Cyan, Magenta, Yellow와 White, Black이 있다.
 
   RGB를 연결하는 삼각형을 Maxwell triangle이라고 한다.
   
   Black에서 white까지 라인을 그으면 Gray Scale이 된다. (R, G, B의 값이 모두 같으면 Gray가 됨)


<br>
<hr>
<br>


## 14. Color Gamut
 - Gamut : 3가지 기본 색상으로 표현 가능한 색상
 - Color Gamut을 통해 우리가 표현할 수 있는 컬러의 전부를 볼 수 있다.
 - Color Gamut의 삼각형 영역은 RGB 모니터에서 표현할 수 있는 색상 범위를 뜻한다.
 
   다각형 영역은 고품질 컬러 인쇄기의 색상 범위를 뜻한다.
   
   이 외에 필름, 잡지의 색상 범위도 확인할 수 있다.


<br>
<hr>
<br>


## 15. Detail on Additive Color Space
 - Trichromacy theory : Cone은 주로 RGB의 3가지 색에 반응한다.
 
   우리 눈을 모델링 해 봤더니 Cone으로 빛이 들어올 때 filter 3개를 통해서 들어온다. 콘에 들어오는 빛과 S1이 Convolution(적분) 되어 X가
되고, 빛 S2가 Y, 빛 S3가 Z가 되었다. 이게 R,G,B이다.
 - CRT 모니터는 우리의 눈을 흉내내서 컬러를 표현한다. CRT는 Additive Color System을 이용하고 3가지 기본 색상(R,G,B)로 색상을 표현한다.
 - Additive Primaries : R, G, B
 - White Balancing : color casts가 없는 '순수 흰색'을 표시하기 위해 3가지 색상을 보정한다.
 
   Additive Color System에서는 가장 White를 찍어내기 어렵다. 이걸 표현하기 위해 Calibration(보정)을 한다.


<br>
<hr>
<br>


## 16. Detail on Substractive Color Space
 - Substractive Color System은 컬러 인쇄에서 사용 된다.
 - Substractive primaries(Secondary colors) : Cyan(C), Magenta(M), Yellow(Y)
 
   M(R+B), C(G+B), Y(R+G)
 - Black Balancing : 3가지 Substractive Primaries를 조정하여 검정색을 표현한다. 검정색을 표현하기 가장 어렵다.


<br>
<hr>
<br>


## 17. Color Fundamentals
 - CIE chromaticity : 색조와 채도함께 있는 표준으로, 국제 조명위원회에서 지정한 컬러의 표준이다.
 
   우리가 표현할 수 있는 모든 컬러를 CIE chromaticity로 표현할 수 있다. 현재의 standard이다.
 - 사진의 컬러 가장자리들에는 파장이 써있다.
 - 특정 컬러 표현을 위해 필요한 R, G, B,의 양을 tristimulus values라고 하고, X, Y, Z라고 한다.
 
   X(Red)와 Y(Green)의 함수로 Blue를 구하면 B = 1 - G - R이다. (62% Green, 25% Red -> 13% Blue)


<br>
<hr>
<br>


## 18. The CMY and CMYK Color Model
 - Cyan색의 물체에 백색 광을 빛출 때, 붉은 빛은 표면에서 반사 되지 않는다. 즉 Cyan 색은 반사 된 백색광에서 적색광을 뺀다.   
 - 컬러 프린터 및 복사기 등은 CMY를 이용한다. 내부적으로 RGB를 CMY로 변환하여 수행한다.
 - CMYK : CMY는 Black 컬러를 표현하기 어렵기 때문에 이를 보안하려고 CMYK를 만들었다. fourth color로 black을 쓴다.


<br>
<hr>
<br>


## 19. The HIS Color Model(Space)
 - HSI 컬러 space : 색은 RGB가 아니라 아래 효과의 합으로 나타난다는 주장이 있다.
 (1) 색조(H) : 주 파장 구성 요소
  - equator도 주변의 각도로 표현되고, 0~1로 정규화 한다.
  - R(0.0), G(0.333), B(0.666)
  - 오른쪽 삼각 뿔 중 그 안의 원에 해당한다. 원의 각 각도에 RGB를 놓았는데, 이 것을 Hue라고 한다. R에서 120도를 가면 G, G에서 120도를
가면 B니까 각각 0.333씩 증가하는 것이다. R에 가까워 질 수록 Red에 가까워 지는 것이고, RGB 사이의 컬러도 다 채워져 있다.

 (2) 채도(S) : Color purity(색의 진함. 흰 색으로 얼마나 washed out 되었는가)
  - S = 0 : 회색 음영
  
    S = 1 : 완전 채도(진한 색)

 (3) 강도(I) : 광도 혹은 빛의 양(R, G, B의 총 량)
  - I = 0 : Black
  
    I = 1 : White
  - I의 값이 커지면 전반적으로 밝아진다.
  - 오른쪽 삼각 뿔 중 아래 꼭지점(Black)과 위 꼭지점(White)에 해당한다.

 (4) 그 외
  - HSB(Hue, Saturation, Brightness)
  
    HSL(Hue, Saturation, Lightness)
    
    HSV(Hue, Saturation, Value)


<br>
<hr>
<br>


## 20. HSI Color 예제
 - HSI를 주장하는 사람들이 각 다각형들의 방법으로 보자며 주장한다.
 - 예제의 각 점은 색상을 뜻한다. 각도는 색조를 나타내고, 벡터의 길이는 채도이다.
 
   모든 색의 Intensity는 평면부터 수직 Intensity axis의 위치에 의해 부여된다.


<br>
<hr>
<br>


## 21. HSI Color 예제2
 - 세모나 원의 예제를 보면 I의 값이 커질 때 마다 전반적으로 밝아지는 것을 알 수 있다.


<br>
<hr>
<br>


## 22. Converting colors from RGB to HSI
 - 기본적인 색의 구성이 RGB이기 때문에 HSI를 이용하고 싶으면 RGB에서 HSI로 처리를 해야 한다.
 
   R,G,B를 [0,1]의 범위로 처리하는 것이다.


<br>
<hr>
<br>


## 23. Converting colors from HSI to RGB
 - HSI에서 RGB로 처리하는 식 확인하기


<br>
<hr>
<br>


## 24. Color Space Conversion : RGB -> YCbCr
 - RGB에서 YCbCr로 처리하는 과정이다.
 (1) CIE 표준 색상 좌표 : Y, R-Y, B-Y
 
  Y = 0.299R + 0.587G + 0.114B
  
  B-Y = -0.299R + 0.587G + 0.886B
  
  R-Y = 0.701R - 0.587G - 0.114B

 (2) Color Different Signal Scaling : 이 식을 이용하여 CbCr을 구한다.
 
  Cb = 0.564(B-Y) + 128
  
  Cr = 0.713(R-Y) + 128

 (3) 단점
  - RGB에서 YCbCr로 처리할 때 단점은 Y의 Signal Level 0~255가 아닌 16~235로 표현되며 비는 칼라가 생긴다.
  
    Cb, Cr도 16~240까지로 표현되며 비는 칼라가 생긴다.
  - Y - 220 Level(16~235)
  
   Color - 225 Level(16~240)
