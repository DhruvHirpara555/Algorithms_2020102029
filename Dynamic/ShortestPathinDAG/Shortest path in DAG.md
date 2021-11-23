# Shortest Path in DAG

A dag is distinguished by the fact that its nodes may be linearized, that is, It can be arranged on a line such that  all edges only going from left to right. This arranging is known as topological sorting

An example to see why Topo sort helps

Photo



For each node, a similar relation may be written. We can always be guaranteed that by the time we arrive to node v, we have all the information we need to compute the distance of node v from source. if we compute these dist values in the left-to-right order of topologically sorted order 

## Algorithm

1. Initialize a dist array will all it's elements initialized to INF
2. Initialize dist(source) = 0
3. For each vertex v in linearized order
   1.  For each vertex u in graph
      1. dist(v) = min(dist(v), G(v,u) + dist(u))

This algorithm involves tackling a set of subproblems, dist(u): u,v in E.
We'll start with the smallest, dist(s), because we already know the solution is = 0. Then continuously solve the larger and larger problem in topological order very fast since we already have all the information required

## Time complexity

We can see we are examining every inedge of each vertex. Each examine takes O(1)

So final time complexity = O(V+E)

