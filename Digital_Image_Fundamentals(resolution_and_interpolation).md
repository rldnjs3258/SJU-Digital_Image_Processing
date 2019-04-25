# 1. Digital Image Fundamentals
# (1) Image Processing in the Eye : Simultaneous Contrast
  - 사진의 회색은 다 같은 회색인데, 주변 색에 따라 다르게 보이는 착시현상을 확인할 수 있다.
  - 우리 눈은 색을 절대적으로만 보는 것이 아닌, 주변 색의 강도에 따라 색을 본다.

<br>
<hr>
<br>

# (2) Optical Illusion
  - 사진을 통해 주변 도형들에만 의존해서 '없는 도형'이 있는 것처럼 의식하는 착시현상을 확인할 수 있다.
  - 눈은 존재하지 않는 정보를 채우거나, 잘못 인식하기도 한다.

<br>
<hr>
<br>

# (3) Light and the electromagnetic spectrum
  - 그래프의 왼쪽으로 갈 수록 빛의 밝기가 크다.
  - 중간의 Gamma rays, X-rays, Ultraviolet, Visible spectrum, Infrared, Microwaves, Radion waves의 그래프를 보면 왼쪽 영역이
파장이 작고, 오른쪽 영역이 파장이 크다.
    이 중 우리가 볼 수 있는 Visible Spectrum의 영역은 아주 작다. 우리는 굉장히 일부분만 보고 인지하는 것이다.

<br>
<hr>
<br>

# (4) Light and the electromagnetic spectrum
  - Frequency(주파수)는 Hz단위로 측정되며, 한 Hz는 초당 sin의 주기와 같다.
  - Frequency는 주기의 역수이다. (F = 1/T)
  - 빛은 인간의 눈으로 감지할 수 있는 electromagnetic radiation(전자기 방사선)이다.
  - 녹색 물체는 파장 500 ~ 570nm 범위의 빛을 반사하고, 다른 파장에서는 대부분 에너지를 흡수한다.
  - 사람이 녹색의 물체를 보는 것은, 빛이 object에 반사되어 내 눈에 들어오는 것이다.

<br>
<hr>
<br>

# (5) Image Processing in the Eye: Mach Band Effect(HPF)
  - 그레이 색상의 명도는 명도 자체의 벨류들은 계단형으로 증가하는데, 우리 눈은 정확히 계단형으로 증가되게 보이는게 아니라
그것보다 조금 떨어졌다 올랐다 하게 보인다.
  - 우리 눈은 spatial freq에 따른 오버 슛(overshoot)을 갖기 때문이다.

<br>
<hr>
<br>

# (6) MTF of Human Visual System
  - MTF는 시각 시스템에 대한 Fourier transform이다.
  - 눈은 아주 높거나 낮은 frequency보다 중간 value의 frequency를 잘 본다.
  - Contrast(대비)가 높을 수록 눈은 더 세밀한 디테일을 볼 수 있다.
    Transition(전환)이 너무 미세하면 눈은 전환 값들을 다 보는게 아닌 그 평균만 볼 수 있다.

<br>
<hr>
<br>

# (7) MTF
  - Spatial frequency(변함)가 우측으로 갈 수록 빨라지고, Contrast(대비)가 아래로 갈 수록 높아지는 그래프이다.
  - Contrast(대비)가 낮을 때 보다 높을 때 더 세밀한 디테일을 인지할 수 있었다.
    frequency가 너무 빨라져서 전환이 너무 미세해 졌을 때 그 전환 값들을 다 인지하기 힘들었다.

<br>
<hr>
<br>

# (8) Temporal Properties of Vision 1
  - 모션 이미지를 처리하고 이미지 디스플레이를 잘 설계하는 것이 중요하다.
  - Bloch Law : 블로우가 실험을 했는데, 같은 빛의 양으로 지속 시간을 다르게 했지만 사람들은 그 둘을 구분하지 못했다.
    T가 30ms였을 때 눈이 adapted 되었고, 사람들이 구분을 못했다.

<br>
<hr>
<br>

# (9) Temporal Properties of Vision 2
  - Critical Fusion Frequency(CFF) : 빛이 천천히 깜빡이면, 개별 깜빡이는 빛들을 구별할 수 있다.
    하지만 깜빡임 속도 > CFF인 경우 깜빡이고 있는지 구별해낼 수 없다.
  - HD : 50 ~ 60Hz
  - TV Raster scan : 50/60 Hz
  - 컴퓨터 모니터 : 60Hz
  - 눈은 낮은 spatial frequency보다 높은 spatial frequency에 더 민감하다. (edge는 높은 sparial frequency이다.)
    * Spatial frequency : 그림의 데이터가 얼마나 빠르게 바뀌는가.

<br>
<hr>
<br>

# (10) Temporal Frequency Response
  - Spatial frequency : 공간 주파수
  - Temporal frequency : 시간 주파수

<br>
<hr>
<br>

# (11) Image sensing and acquisition
  - 광원의 특성에 따라서 빛 에너지는 물체에서 반사되거나, 물체를 통해 전달된다.
    물체에서 반사된 빛이 눈으로 들어온다.
    X-rays는 환자의 몸을 통과한다.
  - 의학 영상들은 대부분 흑백의 Luminance만으로 detect한다.

<br>
<hr>
<br>

# (12) Image sensing and acquisition
  - 필름
   1) 종류 1 : 필름을 롤에 감아 놓고, 롤이 로테이션 하면 필름이 롤링되며 센서가 스캔하여 픽셀씩 읽는다.
   2) 종류 2 : 한 라인씩 통채로 읽는 필름도 있다.
  - MRI : 빛을 발산하는 소스가 있는데, 통이 돌아가며 돌 때마다 찍는다.

<br>
<hr>
<br>

# (13) Image sensing and acquisition
  - CCD array : 디지털 카메라의 일반적인 센서이다.
    센서가 입력 된 빛 신호를 수 시간에 걸쳐 통합함으로서 노이즈를 줄인다.

<br>
<hr>
<br>

# (14) A simple image formation model
  - 특정 위치에서의 화소 값은 f(x,y)이다. '빛' 자체는 무한대이기 때문에 '0 < f(x,y) < 무한대'이다.
  - 빛을 감지하기 위해서는 illumination과 reflectance가 있어야 한다. (reflectance가 클 수록 많이 받는다.)
  - illumination : 0<i(x,y)<무한대
  - reflectance : 0<r(x,y)<1
  - L(min) = 0(black) : i(min), r(min)의 상태이다.
  - L(max) = L-1(white) : i(max), r(max)의 상태이다.
  - 이때 특정 위치에서 l의 값은 L(min) <= l <= L(max)이다.

<br>
<hr>
<br>

# (15) Image sampling and quantization
  - 연속적 데이터를 디지털 형식으로 변환 : Sampling, Quantization
  - 이미지는 x 좌표와 y좌표, 진폭과 관련하여 연속적이다.
  - Sampling : 좌표 값을 디지털화 하는 것.
  - Quantization : 진폭 값을 디지털화 하는 것.

<br>
<hr>
<br>

# (16) Image sampling and quantization
  - 연속적 이미지(Continuous image) : 이미지 원본 상태
  - Sampling and Quantization : 좌표 값, 진폭 값들을 '정수 값'들로 반올림 하여 디지털화 하여 찍어 낸다.
  - 디지털화 된 이미지는 자연스럽지 않고 이미지의 픽셀들이 네모 블럭으로 보이는 그런 이미지이다.

<br>
<hr>
<br>

# (17) Spatial and intensity resolution
  - Spatial resolution(공간 해상도) : 단위 거리 당 Line 혹은 단위 거리 당 점(미국에서는 dpi라고 한다.)
  - Intensity resolution : quantization intensity에 사용된 bit들을 intensity resolution이라고 한다.

<br>
<hr>
<br>

# (18) Spatial and intensity resolution
  - 예제 : 네 개의 동일한 시계 이미지를, spatial resolution만 점차 줄이며 나타내 봤다.
    1250 dpi, 300 dpi, 150 dpi, 72 dpi로 점점 spatial resolution(dpi)를 줄일 때 마다 그림이 망가지고 노이즈가 생겼다.

<br>
<hr>
<br>

# (19) Spatial and intensity resolution
  - 예제 : 의학 영상 이미지를 452x374로 고정시키고, 같은 이미지를 gray levels만 점차 줄여 갔을 때 점점 이미지가 흐릿해졌다.

<br>
<hr>
<br>

# (20) Spatial and intensity resolution
  - NK Plane : 영상에서 N은 Resolution을 뜻하고, K는 quantization의 bit이다.
  - 레나, 카메라 맨, 축구장 사람들(crowd)의 세 가지 이미지가 있을 때, 3번째 이미지의 Spatial frequency가 가장 빨랐다.(이미지
가 가장 복잡했다.)
  - N-K 그래프를 보면 Spatial frequency가 많은 3번의 이미지는 quantization의 bit를 어떻게 바꾸든 그걸 본 사람들은 똑같이 받아
드렸다. 이에 반해 레나 영상은 Spatial frequency가 적은 단순한 이미지였고 resolution과 quantization의 영향을 받았다.

<br>
<hr>
<br>

# (21) Image interpolation
  - Interpolation : 알고 있는 데이터의 위치를 통해 모르는 위치의 값을 추정한다.
  - Nearest neighbor interpolation : 이미지에서 가장 가까운 픽셀을 찾고 해당 픽셀의 intensity를 새 픽셀에 할당한다.
  - Bilinear interpolation : 좌표계에서 f를 (0,0), (0,1), (1,0), (1,1)과 같은 알려진 네 점을 선택하면 공식이 단순화된다.
  - Bicubic interpolation : 가장 가까운 16개의 점을 포함한다. 16개의 픽셀을 기준으로 F(p', q')를 만든다.
    (x,y) 점에 할당 된 intensity value는 방정식을 사용하여 얻을 수 있다.
