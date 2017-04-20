#!/usr/bin/ruby
#encoding:utf-8

# Source : https://leetcode.com/problems/maximum-subarray/
# Author : lixianmin?live.cn
# Date   : 2017-04-20
#
# /**********************************************************************************
# Find the contiguous subarray within an array (containing at least one number) which
# has the largest sum.
#
# For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
# the contiguous subarray [4,-1,2,1] has the largest sum = 6.
# **********************************************************************************/

def do_max_sum (data, _begin, _end)
    return data[_begin] if _end - _begin == 1

    mid = (_begin + _end)/2
    lmax = do_max_sum(data, _begin, mid)
    rmax = do_max_sum(data, mid, _end)
    result = lmax > rmax ? lmax : rmax

    lmax, temp = data[mid-1], data[mid-1]
    (mid-2).downto(_begin) do |i|
        temp += data[i]
        lmax = temp if lmax < temp
    end

    rmax, temp = data[mid], data[mid]
    (mid+1).upto(_end-1) do |i|
        temp += data[i]
        rmax = temp if rmax < temp
    end

    cross_value = lmax + rmax
    result = cross_value if result < cross_value
    result
end

def max_sub_array(nums)
    return 0 if !nums or nums.length <= 0
    do_max_sum(nums, 0, nums.length)
end

def test (nums)
    result = max_sub_array(nums)
    puts "#{result} -> [#{nums.join(',')}]"
end

def main
    test []
    test [1]
    test [-2,1,-3,4,-1,2,1,-5,4]
    test [-2, -1]
end

if __FILE__ == $0 then
    main
end
