public class String_CheckPalindrome {
    private static int isPalindrome(String s) {
        int len = s.length();
        for (int i = 0, j = len - 1; i < j; i++, j--) {
            if (s.charAt(i) != s.charAt(j))
                return 0;
        }
        return 1;
    }

    private static int checkPalindrome(String s, int l, int r) {
        if (l < r)
            if (s.charAt(l) == s.charAt(r))
                return checkPalindrome(s, l + 1, r - 1);
            else
                return 0;
        return 1;
    }

    public static void main(String[] args) {
        String s = "abba";
        System.out.println(isPalindrome(s));
        System.out.println(checkPalindrome(s, 0, s.length() - 1));
    }
}
