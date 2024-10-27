# Hash Table

Hash就是通过key计算出一个index，称为哈希函数。如果两个key对应到同一个hash函数，那么就发生了冲突，可以尝试每个hash值是一个链表，当发生冲突时，即插入到链表中，这就是separate chaining；可以尝试从index向后线性寻找空位进行存储，称之为linear probing。

![1730014603853](image/hash_table/1730014603853.png)
