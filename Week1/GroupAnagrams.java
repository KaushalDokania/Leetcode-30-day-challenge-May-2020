/*  @Author: Kaushal Dokania
    Date: 6th May 2020

URL: https://leetcode.com/explore/featured/card/30-day-leetcoding-challenge/528/week-1/3288/
Title:  Group Anagrams

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
*/

import java.util.*;

class GroupAnagrams {

    // Method to sort a string alphabetically 
    public static String sortString(String inputString) 
    { 
        char tempArray[] = inputString.toCharArray(); 
        Arrays.sort(tempArray); 
        return new String(tempArray); 
    } 

    public static String getCharCountedString(String inputString) {
        HashMap<Character, Integer> charsCountMap = new HashMap<>();
        String outputString = "";
        for (Character ch: inputString.toCharArray()) {
            if (charsCountMap.containsKey(ch))
                charsCountMap.put(ch, charsCountMap.get(ch)+1);
            charsCountMap.put(ch, 1);
        }
        for (char ch='a'; ch<='z'; ++ch) {
            outputString += charsCountMap.get(ch) + ",";
        }
        return outputString;
    }
    /*
    Complexity Analysis
        Time Complexity: O(NK)O(NK), where NN is the length of strs, and KK is the maximum length of a string in strs. Counting each string is linear in the size of the string, and we count every string.
        Space Complexity: O(NK)O(NK), the total information content stored in ans.*/
    public static List<List<String>> groupAnagramsUsingCount(String[] strs) {
        HashMap<String, List<String>> strMap = new HashMap<>();
        List<List<String>> strList = new ArrayList<>();

        for (String s: strs) {
            String strWithCharCounts = getCharCountedString(s);

            if (strMap.containsKey(strWithCharCounts))
                strMap.get(strWithCharCounts).add(s);
            else
                strMap.put(strWithCharCounts, new ArrayList<>(Arrays.asList(s)));                
        }
        for (Map.Entry<String,List<String>> entry : strMap.entrySet())  {
            strList.add(entry.getValue());
        }
        return strList;
    }

    /* Complexity Analysis
        Time Complexity: O(NK \log K)O(NKlogK), where NN is the length of strs, and KK is the maximum length of a string in strs. The outer loop has complexity O(N)O(N) as we iterate through each string. Then, we sort each string in O(K \log K)O(KlogK) time.
        Space Complexity: O(NK)O(NK), the total information content stored in ans. */
    public static List<List<String>> groupAnagrams(String[] strs) {
        HashMap<String, List<String>> strMap = new HashMap<>();
        List<List<String>> strList = new ArrayList<>();

        for (String s: strs) {
            System.out.println("s: " + s);
            String str_sorted = sortString(s);

            if (strMap.containsKey(str_sorted))
                strMap.get(str_sorted).add(s);
            else
                strMap.put(str_sorted, new ArrayList<>(Arrays.asList(s)));                
        }
        for (Map.Entry<String,List<String>> entry : strMap.entrySet())  {
            strList.add(entry.getValue());
        }
        return strList;
    }

    public static void main(String args[]) {
        
        for (List<String> entry : groupAnagramsUsingCount(new String[]{"hos","boo","bob"}))  {
            System.out.println(Arrays.deepToString(entry.toArray()));

        }

    }
}