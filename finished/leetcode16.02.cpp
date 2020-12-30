#include<bits/stdc++.h>
using namespace std;
class WordsFrequency {
public:
    unordered_map<string,int> aMap;
    WordsFrequency(vector<string>& book) {
        int size = book.size();
        for(int i = 0; i < size; i++) {
            if(aMap.find(book[i]) == aMap.end()) {
                aMap.insert(pair<string, int > (book[i], 1));
            }
            else {
                aMap[book[i]]++;
            }
        }
    }
    
    int get(string word) {
        if(aMap.find(word) == aMap.end()) {
            return 0;
        }
        return aMap[word];
    }

};

/**
 * Your WordsFrequency object will be instantiated and called as such:
 * WordsFrequency* obj = new WordsFrequency(book);
 * int param_1 = obj->get(word);
 */