/*
 * @lc app=leetcode id=1455 lang=cpp
 *
 * [1455] Check If a Word Occurs As a Prefix of Any Word in a Sentence
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        // vector<string> words;
        // string word = "";
        // for(int i = 0; i < sentence.size(); i++){
        //     if(sentence[i] == ' '){
        //         words.push_back(word);
        //         word = "";
        //     }else{
        //         word += sentence[i];
        //     }
        // }
        // words.push_back(word);
        // for(int i = 0; i < words.size(); i++){
        //     if(words[i].find(searchWord) == 0){
        //         return i+1;
        //     }
        // }
        // return -1;
        // Optimized
        int n = sentence.size();
        int m = searchWord.size();
        int i = 0;
        int j = 0;
        int k = 0;
        while(i < n){
            if(sentence[i] == searchWord[j]){
                j++;
                i++;
                if(j == m){
                    return k+1;
                }
            }else{
                j = 0;
                k++;
                while(i < n && sentence[i] != ' '){
                    i++;
                }
                i++;
            }
        }
        return -1;
    }
};
// @lc code=end

