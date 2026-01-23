
### sort, sorted 차이
arr 이 존재한다고 가정

- arr.sort()  : arr 에 있는 부분을 정렬하고 저장을 함 
- sorted(arr) : arr 에 있는 부분을 정렬하는데 기존 arr을 저장하지는 않음
                따로 할당을 해주어야 함.
  


### lambda를 활용하여 arr의 특정 부분을 정렬하는 방법
- 앞 부분의 정렬 
  - sorted(lambda x: x[0])
  - arr.sort(key=lambda x: x[0])
    
### 두 개 이상의 값에 대헤 정렬
- lambda x: (x[0], -x[1])
- 이런식으로 Tuple 을 형성해서 정렬이 가능
