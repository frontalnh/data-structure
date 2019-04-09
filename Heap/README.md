## Heap

## What is heap

히프는 우선순위 큐를 구현하는 데 자주 사용된다. 우선순위 큐에서는 우선순위가 가장 높은(또는 낮은) 원소를 먼저 삭제한다.
히프에 대한 설명을 하기 전에 최대 트리와 최소 트리에 대한 설명을 먼저 진행한다.

최대 트리 란 각 노드의 키 값이 그 자식의 키 값보다 작지 않은 트리이며,
최소 트리 란 각 노드의 키 값이 그 자식의 키 값보다 크지 않은 트리를 말한다.

여기서 최대 히프 란 최대 트리이면서 완전 이진트리이며, 최소 히프 란 최소 트리이면서 완전 이진트리를 의미한다.

이러한 최대 히프 및 최소 히프에서는 부모를 쉽게 찾아 삽입이 가능하다.