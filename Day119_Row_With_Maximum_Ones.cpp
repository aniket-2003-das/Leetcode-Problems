class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        vector<int>answer;
        answer.push_back(0); 
        answer.push_back(0);
        int cnt=0;

        for (int i=0; i< mat.size(); i++) {
            for (int j=0; j<mat.at(i).size(); j++) {
                if (mat.at(i).at(j) == 1) cnt++;
            }
            if (answer.at(1)<cnt) {
                answer.at(1)=cnt;
                answer.at(0)=i;
            }
            cnt=0;
        }
        return answer;
    }
};