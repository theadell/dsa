package de.adelhabib;

import de.adelhabib.fundamentals.FixedCapacityStack;
import edu.princeton.cs.introcs.StdIn;
import edu.princeton.cs.introcs.StdOut;

public class Main {

    public static void main(String[] args) {
        FixedCapacityStack s;
        s = new FixedCapacityStack(100);
        while (!StdIn.isEmpty())
        {
            String item = StdIn.readString();
            if (!item.equals("-"))
                s.push(item);
            else if (!s.isEmpty()) StdOut.print(s.pop() + " ");
        }
        StdOut.println("(" + s.size() + " left on stack)");
    }
}