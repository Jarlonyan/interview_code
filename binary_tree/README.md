


+ 二叉树的基本操作：
    + `#`号法创建二叉树：让树的每一个节点都变成度数为2的树，用先序创建二叉树。`#`表示该指针为空，比如`ABC##DE#G##F###`,得到的二叉树为：
```text
                A
              /   \
             B     # 
          /    \
         C       D   
        / \    /  \
       #   #  E    F
             / \  / \
            #  G  #  #
              / \
             #  #
```
        + 取栈顶节点作为当前节点(最近的有用节点，递归的话，自动有栈的功能) 
        + 当`seq[pos]`是`#`，续在当前节点后
        + 当`seq[pos]`不是`#`，若当前节点左节点为空，`seq[pos]`作为左节点；否则作为右节点
    + 先序、中序、后序创建二叉树


+ zigzag蛇形遍历二叉树: ZigZag方式遍历二叉树，即：`根->左子->右子->右子的左子->右子的右子->XXX`
    + 比如:
```text
           3
          / \
         9   1
            / \
           5   6
返回：[
        [3],
        [1,9],
        [5,6]
      ]
```
    + 队列dq每次只保存一层的元素，使用一个栈st保存下一层的元素。使用bool变量leftToright记录当前层是否是“从左往右”的顺序遍历
    + 在遍历一层元素时：
        + 如果是“从左往右”，因为下一层是“从右往左”，所以先将左子节点压栈，再将右子节点压栈
        + 如果是“从右往左”，因为下一层是“从左往右”，所以先将右子节点压栈，再将左子节点压栈
    + 在遍历元素时，将元素保存在数组tp中
    + 如果队列dq为空，表示遍历完一层，那么将下一层元素从栈st中弹出，压入队列；改变元素的遍历方向；并将这一层的元素数组tp保存到结果数组res中


+ 二叉树遍历：非递归遍历、层次遍历
+ 二叉树的统计：
    + 求二叉树第K层的节点个数
    + 求二叉树第K层的叶子节点个数
    + https://juejin.im/post/5b8d64346fb9a01a1d4f99fa#heading-13


