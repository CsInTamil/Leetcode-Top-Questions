class Solution {
public:
    string convert(string s, int numRows) {
        string all[numRows][s.size()];
        int row = 0;
        int col = 0;
        int cur = 0;
        while (cur < s.size()) {
        	while (row < numRows && cur < s.size()) {
        		all[row++][col] = s[cur++];
        	}
        	row = max(0, row - 2);
        	while (row > 0 && cur < s.size()) {
        		all[row--][++col] = s[cur++];
        	}
        	col++;
        }
        string ans = "";
        for (int i = 0 ; i < numRows ; i++)
            for (int j = 0 ; j < s.size() ; j++)
                ans += all[i][j];
        return ans;
    }
};
