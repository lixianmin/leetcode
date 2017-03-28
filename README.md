---
### leetcode
既然默认给出的名字README.md是大写的， 我也就不自己改成小写了

#### [two sum](https://github.com/lixianmin/leetcode/tree/master/algorithms/two-sum)

这个解决方案是比较出乎我意料之外的，一开始我想到的就是最简直的brute force解法，结果。。。超时了。看了答案才知道，可以用hash表记录下m[target - nums[i]] = i，这样只要找到nums[j] = target - nums[i]，这样就可以在m中直接定位到上一个位置i了，很NB的解法啊

另外，c++感觉没啥问题，但这个方案在java中会生成一张heap上的hashtable， 这样空间效率可能比较差
