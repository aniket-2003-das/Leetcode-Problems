class Solution {
unordered_map<string, int> depthMap;
vector<vector<string>> ans;
string b;
private:
    void dfs(string word, vector<string> &seq) {
        if(word==b) {
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
            reverse(seq.begin(), seq.end());
            return;
        }
        
        int steps = depthMap[word];
        int sz=word.size();
        for(int i=0; i<sz; i++) {
            char original=word[i];
            for(char ch='a'; ch<='z'; ch++) {
                word[i]=ch;
                if(depthMap.find(word)!=depthMap.end() && depthMap[word]+1==steps) {
                    seq.push_back(word);
                    dfs(word, seq);
                    seq.pop_back();
                }
            }
            word[i] = original;
        }
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        // BFS to find the shortest path
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        queue<string> q;
        b=beginWord;
        q.push({beginWord});
        depthMap[beginWord]=1;
        int sizee = beginWord.size();
        wordSet.erase(beginWord);
        
        while(!q.empty()) {
            string word = q.front();
            q.pop();
            int steps = depthMap[word];
            if(word==endWord) break;
            for(int i=0; i<sizee; i++) {
                char original=word[i];
                for(char ch='a'; ch<='z'; ch++) {
                    word[i]=ch;
                    if(wordSet.count(word)) {
                        q.push(word);
                        wordSet.erase(word);
                        depthMap[word]=steps+1;
                    }
                }
                word[i]=original;
            }
        }
        // DFS to find all paths
        if(depthMap.find(endWord)!=depthMap.end()) {
            vector<string> seq = {endWord};
            dfs(endWord, seq);
        }
        return ans;
    }

    // vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    //     unordered_set<string> st(wordList.begin(), wordList.end());
    //     queue<vector<string>> q;
    //     q.push({beginWord});
    //     vector<string> usedOnLevel;
    //     usedOnLevel.push_back(beginWord);
    //     int level = 0;
    //     vector<vector<string>> ans;
        
    //     while(!q.empty()){
    //         vector<string> vec = q.front();
    //         q.pop();
    //         if(vec.size()>level){
    //             level++; 
    //             for(auto it: usedOnLevel) st.erase(it);
    //         }
            
    //         usedOnLevel.clear();
    //         string word = vec.back();
    //         if(word==endWord){
    //             if(ans.size()==0) ans.push_back(vec);
    //             else if(ans[0].size()==vec.size()) ans.push_back(vec);
    //         }
            
    //         for(int i=0; i<word.size(); i++){
    //             char orignal = word[i];
    //             for(char c='a'; c<='z'; c++){
    //                 word[i]=c;
    //                 if(st.count(word)>0){
    //                     vec.push_back(word);
    //                     q.push(vec);
    //                     // mark as visited on level
    //                     usedOnLevel.push_back(word);
    //                     vec.pop_back();
    //                 }
    //             }
    //             word[i]=orignal;
    //         }
    //     }
    //     return ans;
    // }
};