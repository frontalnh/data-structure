import { INode } from '../graph';
import { Graph } from '../graph';

class Person implements INode {
  constructor(public id, public value) {}
}

const graph = new Graph<Person>(
  [
    new Person(1, 'false'),
    new Person(2, 'false'),
    new Person(3, 'false'),
    new Person(4, 'false'),
    new Person(5, 'false'),
    new Person(6, 'true')
  ],
  {
    1: [{ nodeId: 2, weight: 1 }, { nodeId: 3, weight: 1 }],
    2: [{ nodeId: 4, weight: 1 }, { nodeId: 5, weight: 1 }],
    3: [{ nodeId: 6, weight: 1 }],
    4: [],
    5: [],
    6: []
  }
);

graph.bfs(1, 'true');
