#!/usr/bin/ruby
#encoding:utf-8

# Source : https://leetcode.com/problems/maximum-product-subarray/
# Author : lixianmin?live.cn
# Date   : 2017-04-21
#
# /**********************************************************************************
# Find the contiguous subarray within an array (containing at least one number) which
# has the largest product.
#
# For example, given the array [2,3,-2,4],
# the contiguous subarray [2,3] has the largest product = 6.
# **********************************************************************************/

def max_product(nums)
    return 0 if !nums or nums.length <= 0
    maxherepre, minherepre, maxsofar = nums[0], nums[0], nums[0]

    1.upto(nums.length-1) do |i|
        item = nums[i]
        minhere, maxhere = [maxherepre*item, minherepre*item, item].minmax
        maxsofar = maxhere if maxhere > maxsofar
        minherepre, maxherepre = minhere, maxhere
    end

    maxsofar
end

def test (nums)
    result = max_product(nums)
    puts "#{result} -> [#{nums.join(',')}]"
end

def main
    test []
    test [1]
    test [-2,1,-3,4,-1,2,1,-5,4]
    test [-4, -3, -2]
    test [2, 3, -2, 4]
    test [2, 1, -2, -1, -1, -2, -1, -1, -1, 4]
end

if __FILE__ == $0 then
    main
end
