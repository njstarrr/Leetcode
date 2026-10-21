class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        
        if (is_sorted(s.begin(), s.end())) return 0;
        
        if (n == 2) return -1;
        
        char min_c = *min_element(s.begin(), s.end());
        char max_c = *max_element(s.begin(), s.end());
        
        if (s[0] == min_c || s[n - 1] == max_c) return 1;
        
        int min_count = count(s.begin(), s.end(), min_c);
        int max_count = count(s.begin(), s.end(), max_c);
        
        if (s[0] == max_c && max_count == 1 && s[n - 1] == min_c && min_count == 1) {
            return 3;
        }
        
        return 2;
    }
};