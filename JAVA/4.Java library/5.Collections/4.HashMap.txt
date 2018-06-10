package com.rajeshpatkar;

import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import java.util.Set;

public class LearningHashMaps
{

    public static void main(String args[])
    {

        // Create a hash map
        HashMap<String, Object> hm = new HashMap<>();
        // Put elements to the map
        hm.put("Dalpat", new Double(3434.34));
        hm.put("Arnold", new Double(123.22));
        hm.put("Bruce", new Double(1378.00));
        hm.put("Amol", new Double(99.22));
        hm.put("James", new Double(-19.08));

        // Get a set of the entries
        Set<String> set = hm.keySet();

        String s;
        // Get an iterator
        Iterator i = set.iterator();
      // Display elements using iterator

        while (i.hasNext())
        {
            s = (String) i.next();
            System.out.println(s);
        }

        for (String s1 : set)
        {
            System.out.println("Key : " + s1);
            System.out.println("Value : " + hm.get(s1) + "\n\n");
        }

        System.out.println();
        // Deposit 1000 into Dalpat's account
        double balance = ((Double) hm.get("Dalpat")).doubleValue();
        hm.put("Dalpat", new Double(balance + 1000));
        System.out.println("Dalpat's new balance: " + hm.get("Dalpat"));
        
        System.out.println("do we have bruce's account with us? : " + hm.containsKey("Bruce"));
        System.out.println("do we have Harry's account with us? : " + hm.containsKey("Harry"));
        System.out.println("is there anyone with 1378 rs in account? : "+hm.containsValue(1378.00));

    }
}