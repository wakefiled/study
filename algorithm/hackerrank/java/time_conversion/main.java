import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
import java.util.regex.*;

public class Solution {

    /*
     * Complete the timeConversion function below.
     */
    static String timeConversion(String s) {
        /*
         * Write your code here.
         */
        String result = new String();
        String[] s_token = s.split(":");
        int hh = Integer.parseInt(s_token[0]);
        int mm = Integer.parseInt(s_token[1]);
        int ss = Integer.parseInt(s_token[2].substring(0, 2));
        String type = s_token[2].substring(2, 4);

        if (hh == 12)
        {
            hh = 0;
        }

        if( type.compareTo("PM") == 0 )
        {
            hh = hh + 12;
        }

        result = String.format("%02d",hh) +":" + String.format("%02d",mm) +":"+ String.format("%02d",ss);

        return result;

    }

    private static final Scanner scan = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bw = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String s = scan.nextLine();

        String result = timeConversion(s);

        bw.write(result);
        bw.newLine();

        bw.close();
    }
}

