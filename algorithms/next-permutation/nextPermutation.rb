#!/usr/bin/ruby
#encoding:utf-8

# Source : https://leetcode.com/problems/next-permutation/
# Author : lixianmin?live.cn
# Date   : 2017-04-17
#
# /**********************************************************************************
#  * Implement next permutation, which rearranges numbers into the lexicographically
#  * next greater permutation of numbers.
#  * If such arrangement is not possible, it must rearrange it as the lowest possible
#  * order (ie, sorted in ascending order).
#  *
#  * The replacement must be in-place, do not allocate extra memory.
#  * Here are some examples. Inputs are in the left-hand column and its corresponding
#  * outputs are in the right-hand column.
#  *
#  * 1,2,3 → 1,3,2
#  * 3,2,1 → 1,2,3
#  * 1,1,5 → 1,5,1
# **********************************************************************************/

def array_reverse (nums, _begin, _end)
    i, j = _begin, _end-1
    while i<j do
        nums[i], nums[j] = nums[j], nums[i]
        i+=1
        j-=1
    end
end

def next_permutation (nums)
    return if !nums or nums.length == 0

    numsSize = nums.length
    k = ((numsSize-2).downto(0).detect {|i| nums[i] < nums[i+1] } or -1)

    if k == -1 then
        array_reverse(nums, 0, numsSize)
        return;
    end

    l = ((numsSize-1).downto(k+1).detect {|i| nums[k] < nums[i] } or -1)
    nums[k], nums[l] = nums[l], nums[k]
    array_reverse(nums, k+1, numsSize)
end

def main
    nums = [1, 2, 3, 4]
    24.times do |i|
        next_permutation(nums);
        puts "#{i}: #{nums.join(", ")}"
    end

    printf("\n");
end

if __FILE__ == $0 then
    main
end
