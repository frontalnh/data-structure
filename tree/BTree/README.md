## B Tree 란

The main idea of using B-Trees is to reduce the number of disk accesses.
According to Knuth's definition, a B-tree of order m is a tree which satisfies the following properties:

1. 모든 노드는 최대 m 개의 자식을 가진다.
2. 리프 노드가 아닌 모든 노드는 최소 ⌈m/2⌉개의 자식 노드를 가진다.
3. The root has at least two children if it is not a leaf node.
4. A non-leaf node with k children contains k − 1 keys.
5. All leaves appear in the same level.

## B Tree 에서의 insert

B Tree 에서는 루트에서부터 element 를 삽입하는 식으로 삽입을 진행하며, 만약 해당 노드가 다 차있다면 원소를 체운 이후에 ⌈m/2⌉ 번째 원소를 상위로 올려보내고 이를 기준으로 양분하여 자식인자가 된다.
만약 이 과정에서 부모가 full 이 난다면 다시 split 을 진행한다.

1. 삽입하고자 하는 원소가 들어갈 수 있는 리프노드를 탐색
2. 해당 리프노드가 full 인 경우 삽입 이후 ⌈m/2⌉ 번째 원소가 ⌈m/2⌉이후의 원소쌍을 가진 새로운 노드를 가르키도록 하고 부모 노드로 보낸다.
3. 해당 리프노드의 ⌈m/2⌉ 번째와 그 이후의 원소들을 제거한다.
4. ⌈m/2⌉번째 원소를 부모 노드의 원소리스트에 다시 insert 함수를 실행한다.
