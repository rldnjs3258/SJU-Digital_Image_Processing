# 1. Digital Image Processing(DIP)
## (1) Image Restoration
  - 이미지의 왜곡, 저하를 제거 또는 최소화 한다.
  - 이미지의 잡음 및 신호를 통계적으로 분석하는데, 영상에 노이즈가 생기면 Observed image의 그래프가 된다.

<br>
<br>


## (2) Image(Video) Data Compression
  - 이미지를 표현하는 데 필요한 데이터의 양을 줄인다.
  - 이미지 저장 및 이미지 전송의 측면.
  - 이미지의 퀄리티를 유지하며 데이터를 압축시켜야 하는데, 너무 크게 줄이면 다시 확장시켰을 때 깨질 수 있으므로 100:1 정도의
비율이 괜찮다.

<br>
<br>

## (3) Cont.
  - 이미지 압축 표준들이 계속 새로 생겨서, 표준간에 변환을 해주는 Transform이 필요하다.

<br>
<br>

## (4) Video Coding Standard
  - 비디오의 표준 분류에는 첫째로 ITU-T가 있고 ISO/IEC가 같이 개발하고 있다. 두번째로 MPEG은 H.xxx의 시리즈로 비디오를 코딩
한다.
  - 인간의 두뇌를 메모리로 환산하면 125,000,000(Mbytes)이다. 이에 비해 Blu-ray disk는 50,000(Mbytes)으로 사람의 두뇌에 못 미
친다.

<br>
<br>

## (5) High Compression
  - 3DTV, UHDTV, IPTV 등 다양한 곳에서 쓰인다.

<br>
<br>

## (6) Components of an Image Processing System
#####  - 이미지 프로세싱의 과정
   1) Object
   2) Observe
   3) Digitize
   4) Store(저장) : 프레임 버퍼(단기), 디스크(온라인), 테이프(보관) 등
   5) Process : Digital computer의 소프트웨어 및 하드웨어에서 진행.
   6) Refresh/store : Online 버퍼에 넣어서 보내거나 저장할 수 있다.
   7) Output : LCD 등으로 Display

<br>
<hr>
<br>

# 2. Digital Image Fundamentals
## (1) Structure of the Human Eye
  - 눈의 직경은 20mm정도 이다.
  - 세포막은 각막(cornea), 공막(sclera), 맥락막(chroid)이 둘러 싸고 있다.
  - Retina는 망막으로, 상이 맺히는 곳이다. Photoreceptors(광 수용체)인 rods와 cones를 포함하고 있다.
    cones는 컬러에 반응하고 rods는 밝고 어두움에 반응한다.
  - Iris(홍채)는 카메라의 조리개 역할을 한다. 빛의 양을 조절한다.
  - Pupil(동공)
  - Fovea(중심와)

<br>
<br>

## (2) Photoreceptors and Lens
#####   Lens
   - Ciliary body(모양체)에 의해 조절되고, 빛의 양이 많으면 렌즈를 차단해 준다. (망막 타는 것 방지)
   - 60~70%의 물로 채워져 있는데 약간 노랗다.
   - 가시광선(visible spectrum)의 8%를 흡수한다. 또한 단파장에서 상대적으로 높은 흡수율을 보인다.
#####   Cons
   - Cons는 600만 ~ 700만개 정도 분포한다.
   - 주로 fovea라고 하는 망막 중심부에 위치 한다.
   - 컬러에 민감하다.
   - 각각의 콘은 자신의 신경 끝에 연결되어 있다.
#####   Rods
   - Rods는 7500만 ~ 1억 5000만개 정도 분포 한다.
   - 주로 망막의 표면 위에 있다.
   - 밝기에 민감하다.
   - 여러 개의 로드들은 하나의 신경 끝에 연결되어 있다.

<br>
<br>

## (3) Rod and Cone
  - Rod의 response curve를 보면 Rod는 빛에 매우 잘 반응 하지만, 빛의 단일 스펙트럼만 볼 수 있으므로 색상을 구별할 수 없다.
    그래프에서 500nm에서 피크치를 찍으며, 1개의 특성 펑션(단일 스펙트럼)에 반응한다는 것을 확인할 수 있다.
  - Cone의 response curves를 보면 3개의 색상(S, M, L)을 구분할 수 있다.
    세상에는 굉장히 여러 파장이 있는데, 우리의 눈은 3개의 특성 펑션에만 반응한다.

<br>
<br>

## (4) Distribution of Three Cones
  - S-Cone : 푸른색
  - M-Cone : 초록색
  - L-Cone : 빨간색
  - L:M:S = 40:20:1(빨간색이 가장 눈에 띈다.)

<br>
<br>

## (5) Distribution of Rod and Cone
  - Perimetric Angle 그래프를 보면 Rods와 Cones는 0도 근처(fovea)에 없고 주변에 존재한다.
  - Rods는 밤에 동작한다.
  - Rods가 Cones보다 훨씬 많다.
  - 눈의 뒤쪽에 구멍 뚫려 있는 부분이 Blind Spot이다. (receptors(Rod and Cone)의 부재)

<br>
<br>

## (6) Evidence of blind spot
  - 착시현상

<br>
<br>

## (7) Image Formation in the eye
  - 눈을 광학적으로 표현하면, 망막에서 렌즈 중심까지의 거리는 14 ~ 17mm이다.
  - 눈의 원리를 이용해서 카메라를 제작한다.

<br>
<br>

## (8) Brightness adaptation and discrimination
  - 사람의 시각 시스템에 의해 감지되는 주관적 밝기의 강도는, 눈에 입사 하는 강도의 log 함수이다.
    사람의 눈은 log 함수의 그래프와 비슷해서, 빛이 많이 들어올 수록 천천히 증가한다.
  - 두 번째 그래프를 보면 Photopic Vision은 Bb보다 커야 인지를 할 수 있다.

<br>
<br>

## (9) Image Sensors
  - 렌즈는 Red센서, Green센서, Blue센서를 통해 색을 받아들인다.

<br>
<br>

## (10) Human Visual System(눈의 특성)
  - HVS에 대한 지식은 디자이너와 Image processing 유저에게 중요한 부분이다.
    눈(Human Vision)은 빛을 감지하는데, 가시광선의 영역만 받아드리고 나머지는 튕겨낸다.
  - Human Vision : 빛의 인식
   1) Physical quantities(물리량)
   - Illuminance : 표면에 입사하는 빛의 양(제일 큰 양)
   - Luminance(Luma) : 눈으로 들어와서 볼 수 있는 가시 광선의 양.
   - Reflectance : Surface에서 다 튀어 나온 반사된 양.
   2) Subjective variables(주관적 변수. 둘을 혼용하는 사람이 많은데 주로 Brightness를 쓰면 된다.)
   - Lightness : 감지된 reflectance
   - Brightness : 감지한 luminance

<br>
<br>

## (11) Brightness vs. Intensity
  - 사람이 빛을 볼 때, HVS의 반응에 의해 인지되는 빛의 강도(밝기)가 결정된다.
  - 540에서 HVS의 상대적인 Luminous 기능이 피크이다.

<br>
<br>

## (12) Human Visual Perception Characteristics
  - Luminance(밝기) vs. Chrominance(색 정보, RGB)
  - Contrast Sensitivity : 인간의 눈은 상대 적인 밝기를 절대 밝기보다 더 정확하게 판단한다.
    절대 값의 빛의 밝기로 보는 것이 아닌 주변 것들에 따라 상대적으로 본다.
  - Spatial frequency Sensitivity : 인간의 눈은 중간 주파수인 Spatial frequency가 3 ~ 10 cycles/degree에서 가장 민감하다. 
high freq에서는 민감하지 않다.
  - Edge Effect : 가장 자리가 있는 경우 사람의 눈은 저주파 성분에 덜 민감하다.
    데이터가 확 변하는 곳. 사람의 얼굴에서는 눈썹이나 입술 같은 곳이다.
    High Pass Filtering을 걸었을 때 더 잘 보이게 할 수 있다.

<br>
<br>

## (13) Contrast Sensitivity
  - 눈은 빛의 강도의 절대 값 보다는 비율에 민감하다.
  - 웨버의 법칙 : 조도는, 조명의 강도가 변경된 것을 알아차리기 위해서 '2배'가 변해야 알아차릴 수 있다.
    즉 Illumination Intensity(I + △I)가 두 배가 돼야 감지할 수 있었다.

<br>
<br>

## (14) Example of Weber's Law
  - 실험에서 Linear Gray Levels을 정확히 32씩 증가시켰다.
    또한 Edge(색이 변하는 부분)에서 High Pass Filtering이 걸려서 더 잘 보인다.
