class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> row_masks;
        
       
        for (const auto& seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];
            if (col >= 2 && col <= 9) {
                row_masks[row] |= (1 << col);
            }
        }
        
        int max_groups = (n - row_masks.size()) * 2;

        for (const auto& [row, mask] : row_masks) {
            bool left_free = (mask & 60) == 0;      
            bool right_free = (mask & 960) == 0;   
            bool mid_free = (mask & 240) == 0;     
            
   
            if (left_free && right_free) {
                max_groups += 2;
            } else if (left_free || right_free || mid_free) {
                max_groups += 1;
            }
        }
        
        return max_groups;
    }
};