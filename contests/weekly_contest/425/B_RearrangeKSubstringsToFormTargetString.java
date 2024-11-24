import java.util.HashMap;

// 25:00
// Time: O(n)
// Space: O(n)

public class Solution {
  public static void main(String[] args) {

  }

  public boolean solve(String s, String t, int k) {
    final int n = s.length();
    final int substrLength = n / k;
    HashMap<String, Integer> substrCount = new HashMap<String, Integer>();
    for (int i = 0; i < k; i++) {
      final String sSubstr = s.substring(substrLength * i, substrLength * (i + 1));
      substrCount.put(sSubstr, substrCount.getOrDefault(sSubstr, 0) + 1);
    }

    for (int i = 0; i < k; i++) {
      final String tSubstr = t.substring(substrLength * i, substrLength*(i+1));
      if (!substrCount.containsKey(tSubstr) || substrCount.get(tSubstr) == 0) {
        return false;
      }
      substrCount.put(tSubstr, substrCount.get(tSubstr) - 1);
    }

    return true;
  }

  public boolean isPossibleToRearrange(String s, String t, int k) {
      return solve(s, t, k);
  }
}
