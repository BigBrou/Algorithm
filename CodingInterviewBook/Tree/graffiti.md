# Tree

트리는 순환구조를 갖지 않는 그래프 

## 트리 관련 용어
    Root

    Child, Parent, Sibling 

    Edge   : 간선
    
    Size   : 자신을 포함한 모든 자식 노드의 개수
    Degree : 자식 노드의 개수
    
    Depth  : Root 에서 Leaf 까지의 거리
    Height : 현재 위치에서부터 Leaf 까지의 거리

## 트리의 특징
    1. 순환 구조가 아님
    2. 부모 노드에서 자식 노드를 가리키는 Uni-Directional 그래프 
    3. 트리는 하나의 부모 노드만을 갖는다
    4. 루트는 하나여야만 한다.

## 트리의 종류
    노드가 m개 이하의 자식을 가지고 있으면 m-ary 트리라고 말한다.

### 이진 트리 (Binary Tree)
    m = 2, 모든 노드의 차수(Degree)가 2이면 Binary Tree라고 한다.
    왼쪽, 오른쪽 최대 2개의 자식을 가지는 매우 단순한 형태

    Full Binary Tree
        모든 노드가 0개 또는 2개의 자식 노드를 가짐
    Complete Binary Tree
        마지막 레벨을 제외하고 모든 레벨이 완전하게 채워져 있음
        마지막 레벨의 모든 노드는 가장 왼쪽부터 채워져 있음
    Perfect Binary Tree
        모든 노드가 2개의 자식 노드를 갖고 있으며, 모든 리프 노드가 동일한 깊이 또는 레벨을 가짐
            




