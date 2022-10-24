package de.adelhabib.fundamentals;

public class FixedCapacityStack<Item> {
    private final Item[] a;
    private int n;

    public FixedCapacityStack(int capacity){
        a = (Item[]) new Object[capacity];
    }

    public void push(Item item){
        // add item first then increment
        a[n++] = item;
    }
    public Item pop(){
        // decrement first then add item
        return a[--n];
    }

    public boolean isEmpty(){
        return n==0;
    }
    public int size(){
        return n;
    }
}
