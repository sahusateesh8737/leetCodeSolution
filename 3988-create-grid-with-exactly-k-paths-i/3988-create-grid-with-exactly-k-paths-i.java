import java.util.Arrays;

class Solution {
    public String[] createGrid(int m, int n, int k) {
        if (k == 1) {
            return buildBoxAndCorridor(m, n, 1, 1);
        }
        if (m >= 2 && n >= k) {
            return buildBoxAndCorridor(m, n, 2, k);
        }
        if (m >= k && n >= 2) {
            return buildBoxAndCorridor(m, n, k, 2);
        }
        if (m == 3 && n == 3 && k == 4) {
            return new String[]{"..#", "...", "#.."};
        }
        return new String[0]; 
    }

    private String[] buildBoxAndCorridor(int m, int n, int boxRows, int boxCols) {
        char[][] grid = new char[m][n];
        for (char[] row : grid) {
            Arrays.fill(row, '#');
        }

        
        for (int i = 0; i < boxRows; i++) {
            for (int j = 0; j < boxCols; j++) {
                grid[i][j] = '.';
            }
        }

        int r = boxRows - 1;
        int c = boxCols - 1;

        
        for (int j = c; j < n; j++) {
            grid[r][j] = '.';
        }
        for (int i = r; i < m; i++) {
            grid[i][n - 1] = '.';
        }

        String[] result = new String[m];
        for (int i = 0; i < m; i++) {
            result[i] = new String(grid[i]);
        }
        return result;
    }
}
