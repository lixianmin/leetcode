

---
一开始想到的仍然是最简单的recursive调用方式，即每两个list都合并，合并出来的结果再与下一个list合并，这个时间复杂度是比较高的。

K路合并问题，使用**最小堆**是一个更好的策略，这在c++中有两种办法，一是std::priority_queue，二是std::make_heap

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
2. 在链表相关的问题中，使用一个**栈上的preHead对象**，很多时候可以极大简化链表指针的调整逻辑， 参考代码如下：

```
	ListNode head(0), *p = &head;
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
	
	return head.next;

```

---
#### [std::make_heap](http://www.cplusplus.com/reference/algorithm/make_heap/)

这个主要是学习一下std::make_heap, std::push_heap, std::pop_heap的使用，也需要使用跟std::priority_queue同样的 ListNodeComparer，实测速度跟std::priority_queue差不多。

因为std::priority_queue通常是std::vector的adapter，因此如果不是特别需要随机访问std::vector中的元素的话，可能没有必要使用std::make_heap，直接使用std::priority_queue即可。

