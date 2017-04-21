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

def do_max_product (data, _begin, _end)
    return data[_begin], data[_begin] if _end - _begin == 1

    mid = (_begin + _end)/2
    lmin, lmax = do_max_product(data, _begin, mid)
    rmin, rmax = do_max_product(data, mid, _end)

    mymin = lmin < rmin ? lmin : rmin
    mymax = lmax > rmax ? lmax : rmax

    temp = data[mid-1]
    lmin, lmax = temp, temp
    (mid-2).downto(_begin) do |i|
        temp *= data[i]
        if temp < lmin
            lmin = temp
        elsif temp > lmax
            lmax = temp
        end
    end

    temp = data[mid]
    rmin, rmax = temp, temp
    (mid+1).upto(_end-1) do |i|
        temp *= data[i]
        if temp < rmin
            rmin = temp
        elsif temp > rmax
            rmax = temp
        end
    end

    return [mymin, mymax, lmin*rmin, lmin*rmax, lmax*rmin, lmax*rmax].minmax
end

def max_product(nums)
    return 0 if !nums or nums.length <= 0
    _, max = do_max_product(nums, 0, nums.length)
    max
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
