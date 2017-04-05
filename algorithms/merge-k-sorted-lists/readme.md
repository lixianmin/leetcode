

---
#### [merge k sorted lists](https://leetcode.com/problems/merge-k-sorted-lists/) 

一开始想到的仍然是最简单的recursive调用方式，即每两个list都合并，合并出来的结果再与下一个list合并，这个时间复杂度是比较高的。

K路合并问题，使用**最小堆**是一个更好的策略，这在c++中有两种办法，一是std::priority_queue，二是std::make_heap

另外 partition策略，本来只是顺手一试，本以为跟brute force方式差不多，却意外发现提交后速度非常快，再仔细一想，这是divide & conquer策略啊，跟[merge sort](https://en.wikipedia.org/wiki/Merge_sort)完全是一样的时间复杂度。

---
#### std::priority_queue< ListNode*, std::vector< ListNode*>, ListNodeComparer>

因为在std::priority_queue中要存储自定义的ListNode*，因此需要使用带Comparer的Template形式，其中的第二个参数std::vector< ListNode*>是指的item在std::priority_queue中存储使用的容器类型

std::priority_queue默认使用的比较器是std::less<int>，然而此时是最大值先被pop()出 （⇒ std::priority_queue被设计成这样，我也很无奈啊），因为我们希望的是最小值先被pop()出，因此需要使用类似于std::greater<int>规则，所以ListNodeComparer的定义是如下形式的：

```
struct ListNodeComparer
{
    bool operator() (const ListNode* lhs, const ListNode* rhs) const
    {
	    // 注意这里是 > 号
        return lhs->val > rhs->val;
    }
};

```

Caution:

1. 不能直接使用std::priority_quque<> q(v.begin(), v.end());的形式去创建q，因为v中的指针有可能是NULL啊
2. 在链表相关的问题中，使用一个**栈上的dummy head对象**，很多时候可以极大简化链表指针的调整逻辑， 参考代码如下：

```
	ListNode dummy(0), *p = &dummy;
	while (!q.empty())
	{
	    p->next = q.top();
	    p = p->next;
	    q.pop();
	
	    if (NULL != p && NULL != p->next)
	    {
	        q.push(p->next);
	    }
	}
	
	return dummy.next;

```
3. 然而，使用dummy head对象的方案，完全可以用**two star pointers**来代替，而且代码看起来更加简单一些：

```
    ListNode *head= NULL, **p = &head;
    while (!q.empty())
    {
        *p = q.top();
        p = &(*p)->next;
        q.pop();

        if (NULL != *p)
        {
            q.push(*p);
        }
    }
```


---
#### [std::make_heap](http://www.cplusplus.com/reference/algorithm/make_heap/)

这个主要是学习一下std::make_heap, std::push_heap, std::pop_heap的使用，也需要使用跟std::priority_queue同样的 ListNodeComparer，实测速度跟std::priority_queue差不多。

因为std::priority_queue通常是std::vector的adapter，因此如果不是特别需要随机访问std::vector中的元素的话，可能没有必要使用std::make_heap，直接使用std::priority_queue即可。

---
#### partition方案 ⇒ divide and conquer

这是意外之喜，仔细分析了一下时间复杂度是  T(n) = 2T(n/2) + n ，这跟[merge sort](https://en.wikipedia.org/wiki/Merge_sort)完全一模一样的，以后要留意了。
