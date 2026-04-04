class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        if (rows == 0) return "";

        int n = encodedText.size();
        int cols = n / rows;

        string result;

        // Traverse starting from each column of first row
        for (int c = 0; c < cols; c++) {
            int i = 0, j = c;

            while (i < rows && j < cols) {
                result += encodedText[i * cols + j];
                i++;
                j++;
            }
        }

        // Remove trailing spaces
        while (!result.empty() && result.back() == ' ') {
            result.pop_back();
        }

        return result;
    }
};