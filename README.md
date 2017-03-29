


---
### leetcode
既然默认给出的名字README.md是大写的， 我也就不自己改成小写了

---
#### [two sum](https://github.com/lixianmin/leetcode/tree/master/algorithms/two-sum)

这个解决方案是比较出乎我意料之外的，一开始我想到的就是最简直的brute force解法，结果。。。超时了。看了答案才知道，可以用hash表记录下m[target - nums[i]] = i，这样只要找到nums[j] = target - nums[i]，这样就可以在m中直接定位到上一个位置i了，很NB的解法啊。

另外，c++感觉没啥问题，但这个方案在java中会生成一张heap上的hashtable， 这样空间效率可能比较差。

如果返回的是数值而不是下标索引的话，还可以考虑先排序然后使用双索引的方式，这样可以得到一个O(nlogn)的算法。leetcode上的另一道题，使用的就是这种解法。参考 [two sum ii input array is sorted](https://github.com/lixianmin/leetcode/tree/master/algorithms/two-sum-ii-input-array-is-sorted)

---
####[four sum](https://github.com/lixianmin/leetcode/tree/master/algorithms/4sum)

four sum的解决方案是基于[three sum](https://github.com/lixianmin/leetcode/tree/master/algorithms/3sum)的，因此，在three sum这个问题需要有一个相对优雅的解决方案，我的第一个方案虽然可以解，但在去重的时候复杂化了。在three sum中，有三个地方分别针对结果中的v[1], v[2], v[0]是否跟nums数组中的数据相等进行了索引位置调整，这个整个解决方案最关键的地方。当three sum的问题解决后，four sum中完全基于three sum的代码就很容易实现了。

如果在void _threeSum()中知道结果将用于fourSum的话，内容占用方面还可以略做优化，考虑到代码独立性，还是略过了。

