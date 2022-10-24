package de.adelhabib.fundamentals;

import java.util.Iterator;
import java.util.Spliterator;
import java.util.function.Consumer;

public class Bag<Item> implements Iterable<Item> {

    private class Node{
        Item item;
        Node next;
    }

    private class ListIterator implements Iterator<Item> {
        private Node current = first;
        public boolean hasNext(){
            return current != null;
        }
        public void remove(){}

        @Override
        public Item next() {
            Item item = current.item;
            current = current.next;
            return item;
        }
    }

    private Node first;

    public void add(Item item){
        Node prevFirst = first;
        first = new Node();
        first.item = item;
        first.next = prevFirst;
    }

    public boolean isEmpty(){
        return first == null;
    }



    @Override
    public Iterator<Item> iterator() {
        return new ListIterator();
    }

}
