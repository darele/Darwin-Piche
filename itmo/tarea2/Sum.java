public class Sum{
    public static void main(String[] args) {
        String s = "";
        int temp = 0;
        int ant = -1;
        int suma = 0;
        for (int i = 0; i < args.length; i++) {
            s = args[i];
            for (int j = 0; j < s.length(); j++) {
                if (Character.isWhitespace(s.charAt(j)) == true) {
                    if (ant != -1) {
                        temp = Integer.parseInt(s.substring(ant, j));
                        System.out.println(temp);
                        ant = -1;
                    } else {
                        ant = j;
                    }
                    continue;
                }
            }
            if (ant != -1) {
                temp = Integer.parseInt(s.substring(ant, s.length()));
                System.out.println(temp);
            }
        }
    }
}