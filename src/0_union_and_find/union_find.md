# 什么是union和find？
> Given a set of N objects.
>- Union command: connect two objects.
>- Find/connected query: is there a path connecting the two objects?

# Quick find
N长度的array，连在一起的node拥有相同的值
- find: O(1)
- union: O(N)
# Quick union
N长度array，存储自己的parent node
- find: O(N)
- union: O(N), union会调用find
