package Parser;
import java.util.Scanner;
public class Actions {
    public static void print(String[] array){
        for(String s : array){
            System.out.print(" " + s);
        }
    }
    public static int[] read(int n){
        int[] res = new int[n];
        Scanner scanner = new Scanner(System.in);
        for(int i = 0; i < n; i++){
            res[i] = scanner.nextInt();
        }
        return res;
    }
    public static String read(char c){
        StringBuilder builder = new StringBuilder();
        Scanner scanner = new Scanner(System.in);
        String character = String.valueOf(c);
        while (true){
            String line = scanner.nextLine();
            if(line.contains(character)){
                int index = line.indexOf(character);
                String substring = line.substring(0, index);
                builder.append(substring);
                break;
            }
            builder.append(line + System.lineSeparator());
        }
        return builder.toString();

    }
    public static void print(int[] array){
        for(int i = 0; i < array.length; i++){
            if (i>0) System.out.print(", ");
            System.out.print(array[i]);
        }
    }


}
