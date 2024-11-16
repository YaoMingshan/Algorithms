# Undirected graph

由顶点和边组成的形式。

## graph中的基本问题

![1731740230099](image/undirected_graph/1731740230099.png)

## Graph的表示

* 用list存储所有的边
* 用邻接矩阵存储，维护一个VxV的二维数组
* 用邻接list存储，list中第i个节点存储与i链接的其他vertex组成的链表

![1731741647030](image/undirected_graph/1731741647030.png)

## DFS

深度优先遍历，模拟迷宫探索，可用于查找conneced component和两点之间是否有path链接，实现方式：

* 将当前访问节点设为visited（有一个数组存储节点是否被查找）
* 递归的查询当前节点的临近节点，当所有邻近节点都被访问后，返回到上一节点
* 所有节点都被访问后，遍历结束

![1731748350972](image/undirected_graph/1731748350972.png)
