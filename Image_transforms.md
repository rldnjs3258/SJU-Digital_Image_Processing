# 1. Affine transform
 (1) 변환(Transforamtion)이란?
  - 점 x를 점 x'에 매핑하는 함수를 transformation이라고 한다.
  - 위치 이동, 각도 변환, 크기 변환 등을 포함한다.
  - 변환에는 다양한 종류가 있다.

 (2) Affine Transformations이란?
  - 선형변환에서 이동변환까지 포함하여 Affine변환이라고 한다.
  
    즉, 회전, 평행이동, 스케일, Linear(선형 변환), Similtudes(유사 변환), Rigid/Euclidean(강제 변환) 등을 포함한다.
  - Affine 변환의 속성 중 하나는, 변환 전 물체가 평형한 선을 가지고 있다면 Affine 변환 후에도 역시 평형하다는 것이다.

 (3) Affine Transformations
  1) Identity(항등변환)
   - 변환이 있을 때, 그 변환 결과가 자기 자신이 나오는 변환을 항등변환이라고 한다.
   - Affine Matrix
   
| 1 | 0  |0 |
|---|:---:|---:|
| 0 | 1 | 0 |
| 0 | 0 | 1 |
     
   - 좌표 방정식
   
     x = v
     
     y = w

  2) Scaling(크기변환)
   - Affine Matrix
   
   
| Cx | 0  |0 |
|---|:---:|---:|
| 0 | Cy | 0 |
| 0 | 0 | 1 |

   - 좌표 방정식
   
     x = Cx*v
     
     y = Cy*w

  3) Rotation(각도변환)
   - Affine Matrix


| cosθ | sinθ  |0 |
|---|:---:|---:|
| -sinθ | cosθ | 0 |
| 0 | 0 | 1 |

   - 좌표 방정식
   
     x = v*cosθ - w*sinθ
     
     y = v*cosθ + w*sinθ

  4) Translation(위치변환)
   - Affine Matrix

   
| 1 | 0  |0 |
|---|:---:|---:|
| 0 | 1 | 0 |
| tx | ty | 1 |

   - 좌표 방정식
   
     x = v + tx
     
     y = w + ty

  5) Shear(vertical)
   - 직사각형 모양을 밀어서 평행사변형의 모양을 만드는 것처럼, 점을 기준으로 '수직' 방향으로 미는 것이다.
   - Affine Matrix

   
| 1 | 0  |0 |
|---|:---:|---:|
| sv | 1 | 0 |
| 0 | 0 | 1 |
 
   - 좌표 방정식
   
     x = v + sv*w
     
     y = w

  6) Shear(horizontal)
   - 직사각형 모양을 밀어서 평행사변형의 모양을 만드는 것처럼, 점을 기준으로 '수평' 방향으로 미는 것이다.
   - Affine Matrix

   
| 1 | sh  |0 |
|---|:---:|---:|
| 0 | 1 | 0 |
| 0 | 0 | 1 |

   - 좌표 방정식
   
     x = v
     
     y = sh*v + w

<br>
<hr>
<br>

# 2. Forward mapping and inverse mapping
 (1) Forward mapping (전방향 매핑)
  - Input Image의 화소 값, 해당 화소의 좌표를 '변환식'에 의해 Output으로 mapping
  - 단점 : 홀(hole)과 겹침(overlap) 발생
  - (x,y) = T{(v,w)}

 (2) Reverse mapping (역방향 매핑)
  - '역변환'에 의해서 Input Image의 어떤 부분이 Output으로 대응되는지 미리 계산한다.
  - 장점 : 홀(hole)과 겹침(overlap) 발생을 없앰
  - (v,w) = T^-1(x,y)


<br>
<hr>
<br>


# 3. Image registration(영상 정합)
 - 하나의 장면이나 대상을 다른 시간이나 관점에서 촬영할 경우, 영상은 서로 다른 좌표계에서 얻어지게 된다.
 
   영상 정합은 이와 같이 서로 다른 영상 중 기준 이미지(Reference image)에 맞게 Input image를 변형하여 하나의 좌표계에 나타내는 기법이다.
   
 - 식
 
   (x,y)가 reference image이고, (v,w)가 input image일 때
   
   x = c1*v + c2*w + c3*vw + c4
   
   y = c5*v + c6*w + c7*vw + c8
   
   compute c1, c2 ... c8


<br>
<hr>
<br>


# 4. Vector and matrix operations
 - RGB의 이미지 각 픽셀은 각각 R, G, B의 세가지 열 벡터로 구성되어 있다.
 
z = 
      
| z1 |
|---|
| z2 |
| z3 |

- Vector norm(denoted by ||z-a||)
 
   N개의 열로 구성된 이미지의 식은 다음과 같다.
   
   D(z,a) = [(z-a)^T*(z-a)]^1/2
   
          = [(z1-a1)^2 + (z2-a2)^2 + ... + (zn - an)^2]^1/2
          
 - 이미지가 픽셀 벡터로 이루어진 데 대한 중요한 이점은 선형 변환이 가능하다는 것이다.
 
   w = A(z-a)
   
   이때 A는 m * n의 매트릭스 사이즈이고, z와 a는 크기가 n * 1인 열 벡터이다.


<br>
<hr>
<br>


# 5. Image transforms
 - 경우에 따라 Image processing의 작업 중 input image를 변환하여 변환 상태에서 지정된 일을 하고, inverse transform을 통해 다시 원래의 input image의 상태로 돌아오는게 효율이 좋을 때가 있다.
 - Spatial domain(Input image) -> Transform -> Operation R -> Inverse transform -> Spatial domain(원래 상태)
 - 예제 : sinusoidal에 의해 손상된 이미지 a에 손상된 부분을 제거하는 마스크를 씌우고, inverse 하여 (향상된) 원래의 이미지로 돌아온다.


<br>
<hr>
<br>


# 6. 이미지에서의 푸리에 변환
 - 이미지는 연속이 아닌 이산(discrete) 신호이다. 또한 유한 구간에서 정의되는 신호이다. 따라서 이산 데이터에서 정의 되는 푸리에
변환이 필요하다.


<br>
<hr>
<br>


# 7. Probabilistic methods(확률론적 방법)
 - 확률은 여러 가지 방법에서 이미지 프로세싱에 이용된다.
 - 확률론적 방법 중 하나로, intensity value를 random 값으로 생각한다.
 
   zi(i = 0, 1, 2 ... L-1)은 M*N 이미지의 모든 가능한 Intensity의 값이다.
