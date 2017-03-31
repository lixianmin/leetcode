four sum的解决方案是基于[three sum](https://github.com/lixianmin/leetcode/tree/master/algorithms/3sum)的，因此，在three sum这个问题需要有一个相对优雅的解决方案，我的第一个方案虽然可以解，但在去重的时候复杂化了。在three sum中，有三个地方分别针对结果中的v[1], v[2], v[0]是否跟nums数组中的数据相等进行了索引位置调整，这个整个解决方案最关键的地方。当three sum的问题解决后，four sum中完全基于three sum的代码就很容易实现了。

如果在void _threeSum()中知道结果将用于fourSum的话，内容占用方面还可以略做优化，考虑到代码独立性，还是略过了。
