# 1. Digital Image
 (1) 연속 이미지와 디지털 이미지
  - Sampling : 연속된 원본의 이미지(Continuous Tone Image)를 디지털화 하여 Sampled Image로 만드는 것이다.
  - Quantization : Sampled Image의 각 픽셀을 '픽셀의 값'으로 표시하는 것이다.

 (2) Pixel이란?
  - Picture element
  - 이미지 안에 위치한다.
  - 회색 또는 컬러 레벨이다.
  - display 할 때의 size이다. (dpi)

 (3) Image digitization
  - spatial resolution
  - brightness(color) resolution
  - temporal resolution

<br>
<hr>
<br>

# 2. Nyquist Sampling Theorem
 (1) 나이퀴스트(Nyquist) 샘플링 법칙
  - 디지털 전송에서 입력 신호의 최고 주파수 Fmax의 2배 이상의 주파수, 즉 2Fmax 이상의 주파수에서 샘플링하면 원 신호를 충실하게 재현할 수 있다는 법칙이다.
  
    fs>2Fmax (fs는 샘플링 할 때의 주파수이다. 2Fmax는 Nyquist rate라고 불린다.)
    
    Nyquist sampling rate : cost, cos2πt
  - 나이퀴스트 샘플링 법칙을 지켜야 원 신호를 재현할 수 있다. 만약 샘플링 주파수가 입력 신호 주파수의 2배보다 낮으면 중첩(Folding)이 발생하여 앨리어싱(Aliasing) 현상이 발생한다.

 (2) 샘플링 단계
  - LPFing를 통해 continuous signal을 Fmax 이내로 제한한다.
  - 2Fmax 이상의 주파수에서 샘플링을 한다.

 (3) Reconstruction step
  - 이산 데이터를 사용하여 신호를 만들기 위해 hold circuit을 이용한다.

 (4) 기타
  - 종종 피쳐 특성을 정확하게 얻기 위해 over-sampling이 실행 된다.
  - Spatial frequency와 Temporal frequency 알기.


<br>
<hr>
<br>

# 3. 에일리어싱(aliasing)
 (1) 에일리어싱이란?
  - 에일리어싱이란 샘플링(sampling) 과정에서 고주파수 성분이 저주파수로 바뀌거나 변형되는 현상이다.
  
    즉 주파수 측면에서 정보손실이 일어나는 것으로, "아날로그가 디지털로 변환"되면서 겪는 정보손실의 대표적인 예이다.
    
  ex) 
  
      전구가 1초에 한 번씩 깜빡거릴 때 0.1초에 한 장씩 사진을 찍으면 전구가 깜빡거리고 있다는 걸 알 수 있지만,
  
      사진을 1초에 한 장씩 찍으면 전구가 깜빡거린다는 사실을 알 수 없다.
      
      달리는 자동차 바퀴를 보면 어느순간 바퀴가 멈추거나 거꾸로 돌아가는 것처럼 보이는 것도 같은 현상이다.
      
  ex2)
  
       벽돌 형태의 그림을 익스플로어 상에서 축소하면 이상한 무늬들이 이미지에 뜨게 되는데, 일반적으로 이미지 축소는 픽셀을
  
       적당히 건너 띄면서 읽어 오는 것이기 때문이다. 하지만 픽셀들이 흰색->검은색->흰색->검은색의 패턴을 갖을 때 이 방식으로
       
       축소를 하면 완전 흰색이나 완전 검은색이 된다.

 (2) 안티 에일리어싱
  - 흰색-> 검은색-> 흰색-> 검은색의 패턴을 미리 회색으로 바꾸는 것. 즉 고주파 성분을 제거하는 것을 안티 에일리어싱이라고 한다.

 (3) 에일리어싱 발생 이유
  - 샘플링 주파수가 입력 신호 주파수의 2배보다 낮으면 중첩(Folding)이 발생하여 앨리어싱(Aliasing) 현상이 발생한다.


<br>
<hr>
<br>

# 4. 1차원 주파수 영역 representation
 - 수학을 사용하여 주파수 영역에서의 앨리어싱 현상을 증명한다.
 
 
<br>
<hr>
<br>


# 5. What is aliasing phenomenon?
 - 320*240의 이미지를 다양하게 샘플링 한 이미지이다.
 - Nyquist Sampling Theorem을 준수하지 않으면 aliasing이 생긴다. (pixel-blocking effect를 볼 수 있다.)


<br>
<hr>
<br>

# 6. Cont.
 - 완전 복원 : 수식으로는 완벽하나, -무한대 ~ 무한대까지의 범위를 구해야 하므로 실현은 어렵다.


<br>
<hr>
<br>

# 7. And then guess 2D case
 - 2D의 경우에는 1D의 식에 2개의 시그마가 돌면서 오메가1, 오메가2가 있으면 된다.


<br>
<hr>
<br>

# 8. Interpolation Filters
 (1) 보간(Interpolation)
  - 보간은 샘플된 화소들 '사이'에 위치한 값들을 결정하는 과정이다. 

 (2) Interpolation filters
  - Zero-order hold interpolation : 샘플된 화소들을 직선으로 연결한다. (화소들 사이에 위치한 값들이 직선으로 결정된다.)
  - Linear interpolation : 샘플된 화소들을 1차함수로 연결한다.
  - Parabolic interpolation : 샘플된 화소들을 2차함수로 연결한다.
  - Ideal interpolation : 모든 샘플된 화소들에 대해 사인 함수를 구해서 밑의 식(중요)으로 계산하여 연결한다.
  
    이 방법이 interpolation의 케이스 들 중 가장 best이다.


<br>
<hr>
<br>


# 9. Spatial Frequency
 - 수평 및 수직 frequency의 그림 예제들을 보자.
 
   frequency가 빠른 건 이미지의 값들이 빠르게 바뀌는 것이다.
 - 1번 사진의 한 라인을 떼 놓으면 2번의 그래프처럼 픽셀이 찍힌다. 초반에 픽셀 값의 변화가 잘 없다가(frequency가 거의 없음) 1번 그림에서 나무쪽에서의 값들이 2번 그래프에서 확 변하는걸 볼 수 있다.
 - 밑의 사진에서 두 번째 네모는 수평(horizontal)에서 frequency가 없고 수직(vertical)에서 frequency가 있다.
 
   아래의 네모는 수평(horizontal)에서 frequency가 있고 수직(vertical)에서 frequency가 없다.
