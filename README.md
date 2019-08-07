# LeetCode 每日一题

7.4

## 数组
## 数组查找

[1.寻找两数之和为给定值](https://github.com/JINGbw/LeetcodeLeetcode/blob/master/%E6%95%B0%E7%BB%84/1.%20%E4%B8%A4%E6%95%B0%E4%B9%8B%E5%92%8C.cpp)

- 题目：给定一个整数数组nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个整数，并返回他们的数组下标
- 思路：使用哈希表存放每个找到的数和它的下标(找到一对就可以了）//时间复杂度：O(1)//空间复杂度：O(n)

[15.寻找三数之和为给定值](https://github.com/JINGbw/LeetcodeLeetcode/blob/master/%E6%95%B0%E7%BB%84/15.%20%E4%B8%89%E6%95%B0%E4%B9%8B%E5%92%8C.cpp)
- 题目：是找到所有满足三数之和且不重复的三元组
- 思路：1. 排序 2. 循环每个数字，对于每个数字都在它后面剩下的位置两边夹（i+1，Num.size()）区间内找，使用两个指针一个从前向后，一个从后向前。时间复杂度：O(N^2)




[169.出现次数超过n/2的数](https://github.com/JINGbw/LeetcodeLeetcode/blob/master/%E6%95%B0%E7%BB%84/169.%E6%B1%82%E4%BC%97%E6%95%B0.cpp)
- 思路：法一：排序，找中间的，法二：利用partition函数，法三：用哈希表
- 法四：
    - 剑指Offer中的，使用两个数字，用一个数记录数组中的一个数字，一个是次数，
    - 如果下一个数字与保存的数字是一样的，则次数加1，如果不同，就次数减一，如果次数为0，
    - 就保存下一个数字，把次数设为1，因为我们要找的数字出现的次数比其它全部数字的出现次数之和还

- 该题的变种：寻找出现次数等于n/2的数字
    - 上一种解法在数字个数为偶数的时候就失效了。修改方法为：在数组中随便找一个数字，再对剩下的数字做刚刚的操作
    - 对比这个数字，和最后得到的数字，再遍历两遍原数组（一共遍历了三次数组复杂度为3n）

[287.找到数组中重复的数字](https://github.com/JINGbw/LeetcodeLeetcode/blob/master/%E6%95%B0%E7%BB%84/287.%20%E5%AF%BB%E6%89%BE%E9%87%8D%E5%A4%8D%E6%95%B0.cpp)

- 题目：找出数组中重复的数字 要求时间复杂度小与O(N^2)
- 思路： 空间复杂度O(1)//对于这种数组在[0,n-1]范围内的问题，可以将值为i的元素调整到第i个位置上
        //解法一：先排序再遍历(排序后相同数字都挨着)   时间O(NlogN) 空间：O(1) 不满足要求
        //解法二：用集合 set 时间O(N) 空间：O(N) 不满足要求
        //解法三：快慢指针，弗洛伊德的乌龟和兔子（循环检测）  （会认为你是有备而来的）时间复杂度0(1),空间复杂度O(N)
        //如果数组的每一个数的取值都是不重复的，那么可以选取特定的数值来使，不断通过索引值得到数值，再将新的数值作为索引值，循环下去可以得到一个链路。如果有重复数字，数组nums一定会存在一个环路，问题变为如何查找环路起点问题。


**旋转数组**       
[153.寻找旋转排序数组中的最小值](https://github.com/JINGbw/LeetcodeLeetcode/blob/master/%E6%95%B0%E7%BB%84/153.%20%E5%AF%BB%E6%89%BE%E6%97%8B%E8%BD%AC%E6%8E%92%E5%BA%8F%E6%95%B0%E7%BB%84%E4%B8%AD%E7%9A%84%E6%9C%80%E5%B0%8F%E5%80%BC.cpp)
- 题目：找到旋转排序数组的最小值（原来数组按照升序排列），且数组没有重复元素
- 思路：利用二分法 1. 如果长度为1 // 2. 如果旋转偶数次//3. 二分法循环，边界条件[mid]和两边的[mid-1]和[mid+1]比较//4. 左边有序（到右边找） 右边有序（到左边找）
    - //时间复杂度：和二分搜索一样 O(logN)
    - //空间复杂度： O(1)
- 注意！！：考虑mid在旋转点的左边和右边的情况


[33.在旋转排序数组中寻找目标值](https://github.com/JINGbw/LeetcodeLeetcode/blob/master/%E6%95%B0%E7%BB%84/33.%E6%90%9C%E7%B4%A2%E6%97%8B%E8%BD%AC%E6%8E%92%E5%BA%8F%E6%95%B0%E7%BB%84.cpp)


- 题目：在旋转前是升序的旋转数组中寻找目标值，返回目标值的索引
- 思路： 用二分法//0. 找到了  //1. mid在有序的一侧还是无序的一侧 //2. 目标在mid左边还是右边


[参考：你真的会写二分查找吗？](https://www.cnblogs.com/luoxn28/p/5767571.html)
- [数组二分查找](https://github.com/JINGbw/LeetcodeLeetcode/blob/master/%E6%95%B0%E7%BB%84/%E4%BA%8C%E5%88%86%E6%B3%95%E6%80%BB%E7%BB%93.cpp)
    - 找到key在数组中的下标
    - 查找第一个与key相等的元素
    - 查找最后一个与key相等的元素
    - 查找最后一个等于或者小于key的元素
    - 查找最后一个小于key的元素
    - 查找第一个等于或者大于key的元素
    - 查找第一个大于key的元素
  

### 数组子序列，子数组

[53.找到数组中 具有最大和的连续子数组](https://github.com/JINGbw/LeetcodeLeetcode/blob/master/%E6%95%B0%E7%BB%84/53.%E6%9C%80%E5%A4%A7%E5%AD%90%E5%BA%8F%E5%92%8C.cpp)
- 题目：找到给定数组中连续子数组的最大和
- 思路：动态规划的状态转移方程：

-一样的题： 剑指Offer [连续子数组的最大和](https://github.com/JINGbw/NewCoder/blob/master/%E6%95%B0%E7%BB%84/%E8%BF%9E%E7%BB%AD%E5%AD%90%E6%95%B0%E7%BB%84%E7%9A%84%E6%9C%80%E5%A4%A7%E5%92%8C.cpp)  


### 数组排序

[179.将数组中的数排成最大的数](https://github.com/JINGbw/LeetcodeLeetcode/blob/master/%E6%95%B0%E7%BB%84/179.%E6%9C%80%E5%A4%A7%E6%95%B0.cpp)
- 思路：1. 排序，排序重写Lambda函数，bool cmp() 利用to_string(x) 2. 如果第一个字符为'0'说明就是0了 

## 二维数组
### 二维数组查找

[74.有序二维矩阵中是否有目标值](https://github.com/JINGbw/LeetcodeLeetcode/blob/master/%E6%95%B0%E7%BB%84/74.%20%E6%90%9C%E7%B4%A2%E4%BA%8C%E7%BB%B4%E7%9F%A9%E9%98%B5.cpp)
- 题目：二维数组从左到右依次变大，从上到下依次变大，找到目标数字
- 思路：法一：利用二分法找到该数所在的行，再用二分法找到这个数。法二：从左下角或者右上角开始找，可以根据Target与当前元素的大小关系来缩小查找区间

[79.二维数组中是否存在一个单词](https://github.com/JINGbw/LeetcodeLeetcode/blob/master/%E6%95%B0%E7%BB%84/79.%E5%8D%95%E8%AF%8D%E6%90%9C%E7%B4%A2(%E7%9F%A9%E9%98%B5%E4%B8%AD%E7%9A%84%E8%B7%AF%E5%BE%84).cpp)
- 题目：搜索二维数组中是否存在一个单词，每个位置只能访问一次
- 思路：回溯法 ，利用一个bool数组来记录这个位置是否访问过。使用变量记录当前走到了单词的哪个位置，如果相同则在当前位置上去搜索上下左右相邻的单元格的元素是否和当前字母的下一个字母相同，不在搜索范围内或者字母不同就返回false，当搜索的字母数等于word的长度时，也就表明在board找到了这个word。注意每次判断一个字母要标记当前位置以搜索过，以防止字母重复利用，直接更改board元素，以便在后续的判断中不会重复判断此位置，在搜索结束后改回来就可以了。


[62.从二维数组的左上角走到右下角有多少种不同的路径（只能向右向下走）](https://github.com/JINGbw/LeetcodeLeetcode/blob/master/%E6%95%B0%E7%BB%84/62.%E4%B8%8D%E5%90%8C%E8%B7%AF%E5%BE%84.cpp)

## 字符串
### 字符串判断
[125.是否为回文字符串](https://github.com/JINGbw/LeetcodeLeetcode/blob/master/%E5%AD%97%E7%AC%A6%E4%B8%B2/125.%E5%9B%9E%E6%96%87%E5%AD%97%E7%AC%A6%E4%B8%B2.cpp)
- 题目：给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
- 思路：使用两个指针从字符串的两端向中间走，把字符转换为大写比较 如果相同就跳过，否则返回false;
    - 注意边界条件：循环停止条件<= ，如果不是英文字母要时刻注意，比较两个指针的大小 p1<p2


[20.判断只有括号的字符串是否有效 ](https://github.com/JINGbw/LeetcodeLeetcode/blob/master/%E5%AD%97%E7%AC%A6%E4%B8%B2/20.%E6%9C%89%E6%95%88%E7%9A%84%E6%8B%AC%E5%8F%B7.cpp)

[859.只交换字符串A中的两个字母是否可以得到字符串B](https://github.com/JINGbw/LeetcodeLeetcode/blob/master/%E5%AD%97%E7%AC%A6%E4%B8%B2/859.%20%E4%BA%B2%E5%AF%86%E5%AD%97%E7%AC%A6%E4%B8%B2.cpp)

### 字符串查找



[215.数组中第k个最大的元素](https://github.com/JINGbw/LeetcodeLeetcode/blob/master/%E5%AD%97%E7%AC%A6%E4%B8%B2/215.%E6%95%B0%E7%BB%84%E4%B8%AD%E7%AC%AC%20k%20%E4%B8%AA%E6%9C%80%E5%A4%A7%E7%9A%84%E5%85%83%E7%B4%A0.cpp)

### 字符串排序

[151.翻转字符串里的单词](https://github.com/JINGbw/LeetcodeLeetcode/blob/master/%E5%AD%97%E7%AC%A6%E4%B8%B2/151.%20%E7%BF%BB%E8%BD%AC%E5%AD%97%E7%AC%A6%E4%B8%B2%E9%87%8C%E7%9A%84%E5%8D%95%E8%AF%8D.cpp)

### 字符串常见算法问题

子序列是不要求连续的，子数组要求连续

**LCP（最长公共前缀）**

[14.查找两个字符串的最长公共前缀](https://github.com/JINGbw/LeetcodeLeetcode/blob/master/%E5%AD%97%E7%AC%A6%E4%B8%B2/14.%20%E6%9C%80%E9%95%BF%E5%85%AC%E5%85%B1%E5%89%8D%E7%BC%80.cpp)


**LIS (最长递增子序列）**
    
[300.最长递增子序列,求一个数组的最长上升子序列的长度](https://github.com/JINGbw/LeetcodeLeetcode/blob/master/%E5%AD%97%E7%AC%A6%E4%B8%B2/300.%E6%9C%80%E9%95%BF%E4%B8%8A%E5%8D%87%E5%AD%90%E5%BA%8F%E5%88%97.cpp) 


**LCS, LCS有两道经典问题 最长公共子串和最长公共子序列**

- 最长公共子串（在数组中是连续的）

[最长公共子串的长度 LCS ](https://github.com/JINGbw/LeetcodeLeetcode/blob/master/%E5%AD%97%E7%AC%A6%E4%B8%B2/%E6%9C%80%E9%95%BF%E5%85%AC%E5%85%B1%E5%AD%90%E4%B8%B2.cpp)

-  最长公共子序列 （在数组中不连续）
   
[最长公共子序列](https://github.com/JINGbw/LeetcodeLeetcode/blob/master/%E5%AD%97%E7%AC%A6%E4%B8%B2/%E6%9C%80%E9%95%BF%E5%85%AC%E5%85%B1%E5%AD%90%E5%BA%8F%E5%88%97.cpp)

- LCS问题Leetcode583,712

**题目OJ链接(牛客网)**

[LIS最长递增子序列](https://www.nowcoder.com/questionTerminal/585d46a1447b4064b749f08c2ab9ce66)

[LCS最长公共子序列](https://www.nowcoder.com/questionTerminal/c996bbb77dd447d681ec6907ccfb488a)

[LCS最长公共子串](https://www.nowcoder.com/questionTerminal/02e7cc263f8a49e8b1e1dc9c116f7602)

[LCP最长公共前缀](https://leetcode-cn.com/problems/longest-common-prefix)

[ED最小编辑代价](https://www.nowcoder.com/question/next?pid=116376&qid=25106&tid=25351883)

[字符串交错组成](https://www.nowcoder.com/question/next?pid=116376&qid=25107&tid=25351883)

[最长回文子串的长度](https://www.nowcoder.com/questionTerminal/b4525d1d84934cf280439aeecc36f4af)
- 有点像最长上升子序列的长度 
- 状态转移矩阵  

$$ dp[i][j]=\left\{
\begin{aligned}
true ,  字符串从i+1到j-1是回文串，且s[i]==s[j]  \\
false , 其他
\end{aligned}
\right.
$$

$$dp[i][j]=\left\{ 
\right.
\right.
\right.
\begin{cases}
true& \text{字符串从i+1到j-1是回文串，且是s[i]==s[j]}\\
false& \text{其他}
\end{cases}$$

$dp[i][j]=
\begin{cases}
true& \text{dp[i+1][j-1]=true&&s[i][j]}\\
false& \text{其他}
\end{cases}$$
\end{CJK*}
\end{document}$
 

## 链表
### 链表查找
[160.找到两个单链表相交的起始节点](https://github.com/JINGbw/LeetCode-/blob/master/160.%E7%9B%B8%E4%BA%A4%E9%93%BE%E8%A1%A8.cpp)

[ 142.找到链表中环的入口节点 ]()


### 链表判断

[141.链表中是否有环](https://github.com/JINGbw/LeetcodeLeetcode/blob/master/%E9%93%BE%E8%A1%A8/141.%E7%8E%AF%E5%BD%A2%E9%93%BE%E8%A1%A8.cpp)

### 链表排序

[148. 排序链表(对链表排序)](https://github.com/JINGbw/LeetcodeLeetcode/blob/master/%E9%93%BE%E8%A1%A8/148.%20%E6%8E%92%E5%BA%8F%E9%93%BE%E8%A1%A8(%E5%AF%B9%E9%93%BE%E8%A1%A8%E6%8E%92%E5%BA%8F).cpp)

[92.反转链表II.cpp](https://github.com/JINGbw/LeetcodeLeetcode/blob/master/%E9%93%BE%E8%A1%A8/92.%20%E5%8F%8D%E8%BD%AC%E9%93%BE%E8%A1%A8II.cpp)

[21.合并两个有序的链表](https://github.com/JINGbw/LeetcodeLeetcode/blob/master/%E9%93%BE%E8%A1%A8/21.%E5%90%88%E5%B9%B6%E4%B8%A4%E4%B8%AA%E6%9C%89%E5%BA%8F%E7%9A%84%E9%93%BE%E8%A1%A8.cpp)

[23.合并k个排序链表](https://github.com/JINGbw/LeetcodeLeetcode/blob/master/%E9%93%BE%E8%A1%A8/23.%E5%90%88%E5%B9%B6K%E4%B8%AA%E6%8E%92%E5%BA%8F%E9%93%BE%E8%A1%A8.cpp)

[92.反转链表中的部分节点](https://github.com/JINGbw/LeetcodeLeetcode/blob/master/%E9%93%BE%E8%A1%A8/92.%20%E5%8F%8D%E8%BD%AC%E9%93%BE%E8%A1%A8II.cpp)

### 链表删除

[19. 删除链表的倒数第N个节点](https://github.com/JINGbw/LeetcodeLeetcode/blob/master/%E9%93%BE%E8%A1%A8/19.%20%E5%88%A0%E9%99%A4%E9%93%BE%E8%A1%A8%E7%9A%84%E5%80%92%E6%95%B0%E7%AC%ACN%E4%B8%AA%E8%8A%82%E7%82%B9.cpp)

[203.移除链表元素(删除链表中值为指定值的节点)](https://github.com/JINGbw/LeetcodeLeetcode/blob/master/%E9%93%BE%E8%A1%A8/203.%E7%A7%BB%E9%99%A4%E9%93%BE%E8%A1%A8%E5%85%83%E7%B4%A0.cpp)
 
 

## 二叉树

### 二叉树查找
[230.二叉搜索树中第k小的元素](https://github.com/JINGbw/LeetcodeLeetcode/blob/master/%E4%BA%8C%E5%8F%89%E6%A0%91/230.%E4%BA%8C%E5%8F%89%E6%90%9C%E7%B4%A2%E6%A0%91%E4%B8%AD%E7%AC%ACk%E5%B0%8F%E7%9A%84%E5%85%83%E7%B4%A0.cpp)

[113.二叉树中和为目标值的所有路径](https://github.com/JINGbw/LeetcodeLeetcode/blob/master/%E4%BA%8C%E5%8F%89%E6%A0%91/113.%E8%B7%AF%E5%BE%84%E6%80%BB%E5%92%8C.cpp)

[257. 二叉树的所有路径](https://github.com/JINGbw/LeetcodeLeetcode/blob/master/%E4%BA%8C%E5%8F%89%E6%A0%91/257.%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E6%89%80%E6%9C%89%E8%B7%AF%E5%BE%84.cpp)

[543. 二叉树的直径]()

- 题目：给定一棵二叉树，你需要计算它的直径长度。一棵二叉树的直径长度是任意两个结点路径长度中的最大值。这条路径可能穿过根结点。
- 思路：
    - 方法一: 二叉树的直径为每一个节点左右深度之和的最大值。只用使用一个全局变量max，在求出深度的同时，记录每一个节点左右深度之和的最大值。
    - 方法二：二叉树的直径：二叉树中从一个结点到另一个节点最长的路径，叫做二叉树的直径。注意：两结点之间的路径长度是以它们之间边的数目表示。
    -  采用分治和递归的思想：根节点为root的二叉树的直径 = max(root->left的直径，root->right的直径，root->left的最大深度+root->right的最大深度+1)


### 二叉树判断

[101.是否为对称二叉树](https://github.com/JINGbw/LeetcodeLeetcode/blob/master/%E4%BA%8C%E5%8F%89%E6%A0%91/101.%E5%AF%B9%E7%A7%B0%E4%BA%8C%E5%8F%89%E6%A0%91.cpp)

[98.是否是二叉搜索树](https://github.com/JINGbw/LeetcodeLeetcode/blob/master/%E4%BA%8C%E5%8F%89%E6%A0%91/98.%20%E9%AA%8C%E8%AF%81%E4%BA%8C%E5%8F%89%E6%90%9C%E7%B4%A2%E6%A0%91.cpp)


### 二叉树遍历
- 二叉树的遍历有两种方式：深度优先遍历和广度优先遍历
    - 深度遍历(DFS)有前序、中序以及后序三种遍历方法
        - 前序遍历：根结点 ---> 左子树 ---> 右子树
        - 中序遍历：左子树---> 根结点 ---> 右子树
        - 后序遍历：左子树 ---> 右子树 ---> 根结点
    - 广度遍历(BFS)即我们寻常所说的层次遍历
        - 层次遍历：仅仅需按层次遍历就可以 
 - 要了解每一种遍历方式的递归和非递归实现，深度遍历的非递归使用栈，层次遍历的非递归使用队列 
 
[102.二叉树层次遍历（BFS）（广度优先遍历）](https://github.com/JINGbw/LeetcodeLeetcode/blob/master/%E4%BA%8C%E5%8F%89%E6%A0%91/102.%E5%B1%82%E6%AC%A1%E9%81%8D%E5%8E%86.cpp)

[144.二叉树的前序遍历](https://github.com/JINGbw/LeetcodeLeetcode/blob/master/%E4%BA%8C%E5%8F%89%E6%A0%91/144.%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E5%89%8D%E5%BA%8F%E9%81%8D%E5%8E%86.cpp)

[145.二叉树的后序遍历](https://github.com/JINGbw/LeetcodeLeetcode/blob/master/%E4%BA%8C%E5%8F%89%E6%A0%91/145.%20%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E5%90%8E%E5%BA%8F%E9%81%8D%E5%8E%86.cpp)

[94.二叉树的中序遍历](https://github.com/JINGbw/LeetcodeLeetcode/blob/master/%E4%BA%8C%E5%8F%89%E6%A0%91/94.%E4%BA%8C%E5%8F%89%E6%A0%91%E4%B8%AD%E5%BA%8F%E9%81%8D%E5%8E%86.cpp)

### 二叉树修改
[114. 将二叉树展开为链表](https://github.com/JINGbw/LeetcodeLeetcode/blob/master/%E4%BA%8C%E5%8F%89%E6%A0%91/114.%E4%BA%8C%E5%8F%89%E6%A0%91%E5%B1%95%E5%BC%80%E4%B8%BA%E9%93%BE%E8%A1%A8.cpp) 



### 最近公共祖先问题 

LCA问题可以看做是询问式的，即给出一系列询问，程序对一系列询问尽快做出反应，一半有两种解决方法，一种是在线式算法，相当于循序渐进处理，另一种是离线算法，如Tarjan算法啊，相当于一次性批量处理，一开始就知道了全部查询，只待询问。

[236. 二叉树的最近公共祖先]()
- **LCA(lowwst common ancestor)**
- 题目：给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。” 
- 思路：
    - 左、右子树中分别查找是否包含p或q，如果（两种情况：左子树包含p，右子树包含q/左子树包含q，右子树包含p），**那么此时的根节点就是最近公共祖先**
    -如果左子树包含p和q，那么到root->left中查找，最近公共祖先在左子树里面
    -如果右子树包含p和q，那么到root->right中查找，最近公共祖先在右子树里面
 
**解法一：蛮力解法**
-  如果是二叉查找树 
     1. 如果当前节点t,大于节点u,v,说明u和v都在t的左侧，到t的左侧查找公共祖先。
     2. 如果当前节点t,小于节点u,v,说明u和v都在t的右侧，到t的右侧查找公共祖先。
     3. 如果 u<t<v 说明 u和v分居在t两侧，当前节点t为最近公共祖先。
     - 另外，如果u是v的祖先，返回u的父节点，同理v是u的祖先，返回v的父节点。
- 如果不是二叉查找树 
     1. 如果每个结点有一个指针指向父节点（转化为寻找两个单向链表的第一个公共结点）
     2. 如果没有父指针，给定根节点后，可以通过根节点到结点u和结点v的递归查找（关于树的问题一般都可以转化为递归）
            1. root == q 、root == p和root==null，这三种情况均直接返回root 
            2. 从左右子树分别进行递归，即查找左右子树上是否有p结点或者q结点。
            第一种情况：左子树和右子树均找没有p结点或者q结点；（这里特别需要注意，虽然题目上说了p结点和q结点必定都存在，但是递归的时候必须把所有情况都考虑进去，因为题目给的条件是针对于整棵树，而递归会到局部，不一定都满足整体条件）
            第二种情况：左子树上能找到，但是右子树上找不到，此时就应当直接返回左子树的查找结果；
            第三种情况：右子树上能找到，但是左子树上找不到，此时就应当直接返回右子树的查找结果；
            第四种情况：左右子树上均能找到，说明此时的p结点和q结点分居root结点两侧，此时就应当直接返回root结点了。
  
- 蛮力解法的缺点：如果需要M次查询，复杂度会扩大m倍，因此蛮力解法只适合一次查询，不适合多次查询。

     
## 队列和栈
[225.用队列实现栈](https://github.com/JINGbw/LeetcodeLeetcode/blob/master/%E9%98%9F%E5%88%97%E5%92%8C%E6%A0%88/225.%20%E7%94%A8%E9%98%9F%E5%88%97%E5%AE%9E%E7%8E%B0%E6%A0%88.cpp)

[232.用栈实现队列](https://github.com/JINGbw/LeetcodeLeetcode/blob/master/%E9%98%9F%E5%88%97%E5%92%8C%E6%A0%88/232.%E7%94%A8%E6%A0%88%E5%AE%9E%E7%8E%B0%E9%98%9F%E5%88%97.cpp)

## 动态规划
- [上台阶 ]()
- [64.最小路径和]()
- [62.不同路径I]()
- [63.不同路径II]()
- [300.最长上升子序列 LIS(最长递增子序列) ]()
- [最长上升子序列的和]()
- [673.最长递增子序列的个数]()
- [53.最大连续子数组的和]最大子序列和()
- [121.买卖股票的最佳时机 I ]()
- [122.买卖股票的最佳时机 II ]()
- [123.买卖股票的最佳时机 III ]()
 
## c++
1. 判断是否为字母
```
isalnum(s)==true;//说明是字母 == false 不是字母

```
2. 把字母转为大写
```
toupper(s);
```
