public class String_FindDuplicates {
    public static void main(String[] args) {
        String str = "geeksforgeeks";

        int count[] = new int[26];
        for (char c : str.toCharArray()) {
            count[c - 97]++;
        }

        for (int i = 97; i - 97 < 26; i++) {
            if (count[i - 97] > 1) {
                char c = (char) i;
                System.out.println(c + " : " + count[i - 97]);
            }
        }
    }
}
