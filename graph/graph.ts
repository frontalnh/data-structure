type NodeId = number;

export interface INode {
  id: number;
  value: string;
}

export class Edge {
  constructor(public from: number, public to: number, public weight: number) {}
}

export class Graph<T extends INode> {
  constructor(
    private nodeMap: Array<T>,
    private destinations: { [nodeId: number]: Array<{ nodeId: number; weight: number }> }
  ) {}

  public addNode(node: T) {
    this.nodeMap[node.id] = node;
    this.destinations[node.id] = [];
  }

  public addDirectedEdge(from, to, weight) {
    this.destinations[from].push({ nodeId: to, weight });
  }
  public addUnDirectedEdge(node1, node2, weight) {
    this.destinations[node1].push({ nodeId: node2, weight });
    this.destinations[node2].push({ nodeId: node1, weight });
  }

  public bfs(nodeId: NodeId, item) {
    let searchQue: Array<{ nodeId: number; weight: number }> = [].concat(this.destinations[nodeId]);
    let searched = [];

    while (searchQue.length) {
      let searchingNode = searchQue.shift();
      console.log('searching node id: ', searchingNode.nodeId);
      if (searched.find(v => v === searchingNode.nodeId)) continue;

      searched.push(searchingNode.nodeId);
      if (this.nodeMap[searchingNode.nodeId].value === item) {
        return console.log('found the item!');
      }
      console.log('childs: ', this.destinations[searchingNode.nodeId]);
      searchQue = searchQue.concat(this.destinations[searchingNode.nodeId]);
      console.log(searchQue);
    }
  }
}
