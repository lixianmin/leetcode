#!/usr/bin/ruby
#encoding:utf-8

# Source : # https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
# Author : lixianmin?live.cn
# Date   : 2017-04-17
#
# /**********************************************************************************
# Say you have an array for which the ith element is the price of a given stock on day i.
#
# If you were only permitted to complete at most one transaction (ie, buy one and sell
# one share of the stock), design an algorithm to find the maximum profit.
#
# Example 1:
# Input: [7, 1, 5, 3, 6, 4]
# Output: 5
#
# max. difference = 6-1 = 5 (not 7-1 = 6, as selling price needs to be larger than buying price)
#
# Example 2:
# Input: [7, 6, 4, 3, 1]
# Output: 0
#
# In this case, no transaction is done, i.e. max profit = 0.
# **********************************************************************************/

def max_sum (data)
    return if !data or data.length <= 0

    maxSoFar, maxEndingHere = 0, 0
    data.each do |item|
        maxEndingHere += item
        if maxEndingHere > maxSoFar
            maxSoFar = maxEndingHere
        elsif maxEndingHere < 0
            maxEndingHere = 0
        end
    end

    maxSoFar;
end

def max_profit (prices)
    return 0 if !prices or prices.length <= 1
    i= 0
    deltas = Array.new(prices.length-1) do
        i += 1
        prices[i] - prices[i-1]
    end

    result = max_sum(deltas)
    result = 0 if result < 0
    result
end

def test (prices)
    profit = max_profit(prices)
    puts "#{profit} -> #{prices.join(',')}"
end

def main
    test []
    test [1]
    test [2, 1]
    test [7, 1, 5, 3, 6, 4]
    test [7, 6, 4, 3, 1]
    test [2, 1, 2, 1, 0, 1, 2]
    test [1, 0, 1, 2]
end

if __FILE__ == $0 then
    main
end
