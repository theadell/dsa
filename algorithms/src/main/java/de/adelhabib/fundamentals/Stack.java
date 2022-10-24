package de.adelhabib.fundamentals;

import java.util.Iterator;

public class Stack<Item> implements Iterable<Item> {

    Node start = null;
    private class Node {
        Item item;
        Node next;
    }




    @Override
    public Iterator<Item> iterator() {
        return null;
    }
}
