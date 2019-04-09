class Graph {
  constructor(
    private nodes: Array<number>,
    private edges: { [node: number]: Array<{ node: number; weight: number }> }
  ) {}

  public addNode(node: number) {
    this.nodes.push(node);
    this.edges[node] = [];
  }

  public addDirectedEdge(from, to, weight) {
    this.edges[from].push({ node: to, weight });
  }
  public addUnDirectedEdge(node1, node2, weight) {
    this.edges[node1].push({ node: node2, weight });
    this.edges[node2].push({ node: node1, weight });
  }
}
