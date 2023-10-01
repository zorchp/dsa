from math import inf as X


def min_Key(N, key, visited):
    """查找权值最小且尚未被选择的顶点, key 列表记录了各顶点间的权值"""
    # min_weight 记录最小的权值, min_index 记录最小权值关联的顶点
    min_weight = X
    min_index = 0
    # 遍历 key 列表
    for i in range(N):
        # 如果当前顶点未被选择, 且对应的权值小于 min_weight
        if not visited[i] and key[i] < min_weight:
            # 更新 min_weight 的值并记录该顶点的位置
            min_weight = key[i]
            min_index = i
    # 返回最小权值的顶点的位置
    return min_index


def prim_MinTree(N, cost):
    # key 列表用于记录顶点权值
    # parent 列表用于记录最小生成树中各个顶点父节点的位置
    # visited记录各顶点是否已经被选择(属于 A 类还是 B 类)
    # A类代表已经存入生成树的结点, B类表示还未遍历的结点
    parent = [-1] * N
    key = [X] * N
    visited = [False] * N
    # 选择 key 列表中第一个顶点, 开始寻找最小生成树
    key[0] = 0
    # |E(T)| = N - 1
    for _ in range(N - 1):
        # 从 key 列表中找到权值最小的顶点所在的位置
        u = min_Key(N, key, visited)
        visited[u] = True
        # 由于新顶点加入 A 类, 因此需要更新 key 列表中的数据
        for v in range(N):
            # 如果类B(未被遍历)中存在到下标为u的顶点权值(不为0)比 key中记录的权值还小
            # 表明新顶点的加入, 使得类 B 到类 A 顶点的权值有了更好的选择
            if cost[u][v] and not visited[v] and cost[u][v] < key[v]:
                # 更新 parent记录的各个顶点父节点的信息
                parent[v] = u
                # 更新 key 列表
                key[v] = cost[u][v]
    # 根据 parent 记录的各个顶点父节点的信息
    return parent


def getNP(graph):
    # 结点数
    N = len(graph)
    # 边数
    P = 0
    for i in range(N):
        for j in range(i):
            P += graph[i][j] != X
    return N, P


# cost = [
#     [0, 7, 8, X, X, X],
#     [7, 0, 3, 6, X, X],
#     [8, 3, 0, 4, 3, X],
#     [X, 6, 4, 0, 2, 5],
#     [X, X, 3, 2, 0, 2],
#     [X, X, X, 5, 2, 0],
# ]
cost = [
    [0, 7, X, 5, X, X, X],
    [7, 0, 8, 9, 7, X, X],
    [X, 8, 0, X, 5, X, X],
    [5, 9, X, 0, 15, 6, X],
    [X, 7, 5, 15, 0, 8, 9],
    [X, X, X, 6, 8, 0, 11],
    [X, X, X, X, 9, 11, 0],
]
N, P = getNP(cost)
print("结点数为: ", N, "边数为: ", P)

parent = prim_MinTree(N, cost)
# print(parent)
# [-1, 0, 1, 4, 2, 4]

minCost = 0
print("最小生成树为：")
# 遍历 parent 列表
for i in range(1, N):
    # parent 列表下标值表示各个顶点, 各个下标对应的值为该顶点的父节点
    print("%d - %d wight:%d" % (parent[i], i, cost[i][parent[i]]))
    # 统计最小生成树的总权值
    minCost = minCost + cost[i][parent[i]]
print("总权值为：%d" % (minCost))
"""
结点数为:  6 边数为:  9
最小生成树为：
0 - 1 wight:7
1 - 2 wight:3
4 - 3 wight:2
2 - 4 wight:3
4 - 5 wight:2
总权值为：17
"""
