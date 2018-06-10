package learningjavaio;

import java.io.*;

public class LearningJavaIO {

    public static void main(String[] args) throws Exception {

        System.out.println("Welcome to JavaIO");

        final int SIZE = 5;
        BufferedReader kin = new BufferedReader(
                new InputStreamReader(System.in)
        );

        int[] a = new int[SIZE];

        for (int i = 0; i < SIZE; i++) {

            System.out.println("a["+i+"]=");
            a[i] = Integer.parseInt(kin.readLine());
        }

        System.out.println("Printing Numbers:");

        for (int j = 0; j < SIZE; j++) {

            System.out.println("a["+j+"]="+a[j]);

        }
        
        int max = a[0];
        for( int k = 1 ; k < SIZE ; k++){
            if ( max < a[k] ) max = k;
        }

        System.out.println("The highest number is "+max);    
    }
}