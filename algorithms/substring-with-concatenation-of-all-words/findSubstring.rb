#!/usr/bin/ruby

# Source : https://leetcode.com/problems/substring-with-concatenation-of-all-words/
# Author : lixianmin?live.cn
# Date   : 2017-04-15
#
# /**********************************************************************************
#  * You are given a string, s, and a list of words, words, that are all of the same
#  * length. Find all starting indices of substring(s) in s that is a concatenation
#  * of each word in words exactly once and without any intervening characters.
#  *
#  * For example, given:
#  * s: "barfoothefoobarman"
#  * words: ["foo", "bar"]
#  *
#  * You should return the indices: [0,9].
#  * (order does not matter).
# **********************************************************************************/

def find_substring (s, words)
    wordsCount = words.length
    return [] if wordsCount == 0

    sLength = s.length
    wordLength = words[0].length
    endIndex = sLength - wordsCount * wordLength;
    return [] if endIndex < 0

    result = []
    cache  = Hash.new 0
    words.each {|word| cache[word] += 1 }

    for i in 0..endIndex do
        t = s[i, wordLength]
        next unless cache.include? t

        cache[t] -= 1

        for j in 1...wordsCount do
            t = s[i + j * wordLength, wordLength]
            break unless cache.include? t

            cache[t] -= 1
            break if cache[t] < 0
        end

        result << i unless cache.any? {|k, v| v != 0}
        cache.clear
        words.each {|word| cache[word] += 1 }
    end

    result
end

def test (s, words)
    result = find_substring(s, words)
    puts "[#{result.join(", ")}]";
    printf ("----------------------------\n");
end

def main
    s = "0barfoothefoobarman";
    words = ["foo", "the", "bar"]
    test(s, words);

    s = "wordgoodgoodgoodbestword";
    words = ["word", "good", "best", "good"]
    test(s, words);

    printf("\n");
end

if __FILE__ == $0 then
    main
end
