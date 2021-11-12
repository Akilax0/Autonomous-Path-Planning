
# RRT ALGORITHMS FOR EXPERIMENTING ON AUTONOMOUS ROBOTS



Four main concerns in path planning algorithms

	1) Optimal path in static realisitc env.
	2) Expandable to dynamic env.
	3) Remain compatible with and enhance self referencing approach
	4) Minimize storage, time complexity, computation time.

## Dijkstra Algorithm 
Checks for shortest path in a greedy approach. Keeps the minimum lengthpath at the top of a prority queue. Computationally inefficient as it checks for paths without a direction. 


## A* Algorithm 

Similar to Dijkstra but less computational. Uses heurestic rules to define nodes.
	minimum checked for using 
		f(n) = g(n) + h(n)

		where g(n) is distance to n from start 
			h(n) distance left to end node,	
				Euclidean 
				Manhattan
				Diagonal
heirarchical A* algorithm divide area into parts and find the local result. In the end compare for global result.


Can be further improved using time as a variable in the equation,
	fw(n) = (1-w)g(n) + w.h(n)

	**Euclidean = sqrt((x1-x2)^2 + (y1-y2)^2)
	**Manhattan = |x1-x2| + |y1-y2|
	**Octile    = max|x1-x2| + |y1-y2| #Please check here

### Classification of A* algorithms variants

|     Algorithm               |  Static    |  Dynamic  |
|-----------------------------|------------|-----------|
|     A*                      |  T         |           |
|     Heirarchical A*         |  T         |           |
|     Improved Heirarchical A*|            |  T        |
|     Guided Hybrid A*        |            |  T        |
|     equal sampling          |  T         |           |
|     Diagonal     			  |  T         |           |
|     smart heuristics        |	           |  T        |
|     Lifelong planning       |  T         |  T        |



##Life Long A* Algorithm 

An incremental heuristic search algorithm based on A*.
     - Sven Koenig
	 - Maxim Likhaachev
	 (2001)

The algorithm can adapt to changes in the graph without recalculating the entire graph.
Done by updating the g-values (distance from start) from previous during current search when required.
Uses heuristic as lower boundary for the cost to goal.


Predecessors  - node which leads towards current node
Successors - node which leads from current node











## D* Algorithm 

To solve the problem of partially known and dynamic environments in efficient way(Dynamic A*). Informed incremental search algorithm repairs cost map partially and the previously calculated cost map.



|     Algorithm       |  Static    |  Dynamic  |
|---------------------|------------|-----------|
|     D*              |            |  T        |
|     D* Lite         |            |  T        |
|    Enhanced D* Lite |            |  T        |
|     Field D*        |            |  T        |



