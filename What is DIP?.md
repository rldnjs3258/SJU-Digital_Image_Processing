# 1. Digital Image Processing(DIP)
## (1) DIP란?
  - Pixel은 곧 Picture element(pel)이다.
  - 디지털 이미지 프로세싱은 디지털 컴퓨터를 이용하여 디지털 이미지를 처리하는 것을 의미한다.

<br>
<hr>
<br>

## (2) Digital Image Processing 종류
  - 2차원과 3차원 이미지를 프로세싱 한다.
  - 이미지 디스플레이, 저장, 전송 등과 관련 있다.
  - 비디오 표준 : HDTV의 표준은 MPEG2, Iphone/DMB/IPTV의 표준 등 영상의 표준이 있다.
  - 의학 영상에서 활용된다.
  - 달 탐사와 같은 Remote sensing과 관련 있다.
  - 레이더, Sonar 등은 박쥐, 돌고래의 방법을 모델링하여 활용한다.
  - Robotics, Computer vision
  - Deep learning

<br>
<hr>
<br>


## (3) Image Processing to computer vision
  - Low - level Processing : 가장 낮은 레벨의 프로세싱으로 이미지를 이미지로 처리한다.
  - Mid - level Processing : 이미지를 심볼로 처리한다. (홍채 인식 등)
  - High - level Processing : 심볼을 심볼로 처리한다. (AI 등)

<br>
<hr>
<br>


## (4) Historical Backgrounds
  - 1920년대 : 5개의 뚜렷한 회색 레벨을 이용한 전신 프린터 사용
  - 1940년대 : 디지털 컴퓨터의 기초
  - 1960년대 : 의미있는 이미지 처리 가능. 달 사진 등
  - 1970년대 : 의학 영상
  - 2000년대 : HDTV, 모바일 등

<br>
<hr>
<br>


## (5) 응용분야
  - Video Compression
  - Photography
  - 방송 / 멀티미디어
  - Biological Research : 뼈, 조직, 세포, DNA와 같은 의학 영상
  - 비디오 / 영화
  - 방위 / intelligence : 군대에서 아군, 적군의 미사일 분별
  - 노이즈 제거 : Convolutional Neural Network
  - 공장 자동화
  - 원격 탐사 / 지구 자원 분석
  - 우주 탐험 / 천문학
  - 법 의학 : 지문인식, DNA 매칭
  - Material Research : 전자 현미경 사용
  - 의료 진단 : X-ray, CT, MRI, PET 등

<br>
<hr>
<br>


## (6) Sample Images
  - Lena Soderberg : Lena라는 여성이 그려진 그림이 텍스쳐, 음영, 질감 등 이미지로서 분석하기에 좋아서 사람들이 이 그림을 분석
하기 시작했고, 모든 곳에서 표준 영상이 되었다.
  - 컬러, 흑백 이미지는 처리가 같기 때문에 그 중 흑백을 많이 사용한다.

<br>
<hr>
<br>


## (7) DIP 활용 분야
  * DIP 활용 분야
  - Gamma rays : 핵의학 등
  - X-rays : 폐와 같은 의료 진단
  - Ultraviolet(자외선) : 현미경, 레이저, 생물학적, 열감지 등
  - Visible&infrared(가시광선 및 적외선) : 광학 현미경, 원격 탐사, 천문학 등
  - Microwaves : Radar
  - Radio waves : MRI 등
  - 이미지 종류 : 가시광선, 일상 영상, X-rays, 우주, 서킷보드, 불량품 판별, MRI 영상, 태아 사진 등

<br>
<hr>
<br>


## (8) Digital Image Processing의 기본 단계
  - Image Enhancement(이미지 향상) : 이미지를 더 뚜렷하게 한다.
  - Image Restoration(이미지 복원) : 영상이 흔들리거나 뿌열 때 모델링하여 영상 왜곡을 잡아준다.
  - Image Understanding(이미지 이해) : 이미지를 분할, 인식하여 탱크를 찾아내거나 아군/적군 탱크 분별, 암 구별 같은 일을 한다.
  - Image Reconstruction from Projection : 투영된 이미지를 재구성(MRI 등)
  - Image data compression(Image Coding) : 이미지가 클 때 압축을 한다.
  - Color Image Processing(컬러 이미지 처리) : TV 등의 디지털 이미지 사용 증가로 자연상태의 컬러와 비슷하게 프로세싱 하는것이 
중요해졌다.
  - Morphological Processing(형태 처리) : 논리에 기반해서 Object의 경계선을 다룸.
  - Segmentation : 이미지에서 유의미한 부분만 찾아낸다.
  - Representation and description : 이미지에서 찾고 싶은 부분을 경계, regional, 설명까지 함.
  - Recognition : 인식
