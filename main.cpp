/*
 * OPTIMIZATIONS TO TEST:
 *  Storing cache[i][j] using Reference&
 *  Memoization
 *  Bottom-up implementation
 *  std::string_view vs const std::string&
 *  Vector vs. standard array
 */

#include <vector>
#include <string>
#include <string_view>

int longestCommonSubsequence(std::string text1, std::string text2);
int dfs(
        std::string_view text1, std::string_view text2,
        int i, int j, int n, int m,
        std::vector<std::vector<int>>& cache);

// ENTRY POINT
int main(void) {
    return 0;
}

/*
int longestCommonSubsequence(std::string text1, std::string text2) {
    int n = static_cast<int>(text1.size());
    int m = static_cast<int>(text2.size());
    std::vector<std::vector<int>> cache(n+1, std::vector<int>(m+1, -1));
    return dfs(text1, text2, 0, 0, n, m, cache);
}
*/

/* naive recursion
 * std::string
 * no references used
 */
int worst(
        const std::string& text1,
        const std::string& text2,
        int i, int j, int n, int m,
        std::vector<std::vector<int>>& cache) {
    if (i == n || j == m)
        return 0; // unable to evaluate i == j
    int res;
    if (text1[i] == text2[j])
        res = 1 + dfs(text1, text2, i+1, j+1, n, m, cache);
    else
        res = std::max(dfs(text1, text2, i+1, j, n, m, cache),
                dfs(text1, text2, i, j+1, n, m, cache));
    return res;
}
/* memoized recursion
 * string view
 * no references used
 */
int memo_sv_noref(
        std::string_view text1,
        std::string_view text2,
        int i, int j, int n, int m,
        std::vector<std::vector<int>>& cache) {
    if (i == n || j == m)
        return 0; // unable to evaluate i == j
    if (cache[i][j] > -1)
        return cache[i][j];
    int res;
    if (text1[i] == text2[j])
        res = 1 + dfs(text1, text2, i+1, j+1, n, m, cache);
    else
        res = std::max(dfs(text1, text2, i+1, j, n, m, cache),
                dfs(text1, text2, i, j+1, n, m, cache));
    cache[i][j] = res;
    return res;
}

/*
int dfs(
        std::string_view text1, std::string_view text2,
        int i, int j, int n, int m,
        std::vector<std::vector<int>>& cache) {
    if (i == n || j == m) {
        return 0; // unable to evaluate i == j
    }
    int& cache_val = cache[i][j];
    if (cache_val > -1) {
        return cache_val;
    }
    int res;
    if (text1[i] == text2[j]) {
        res = 1 + dfs(text1, text2, i+1, j+1, n, m, cache);
    } else {
        res = std::max(dfs(text1, text2, i+1, j, n, m, cache),
                dfs(text1, text2, i, j+1, n, m, cache));
    }
    cache_val = res;
    return res;
}
