package com.rpise;

import java.util.*;

public class LearningCollections {

    public static void main(String[] args) {
        Linklist l = new Linklist();

        //Populating Linklist
        for (int i = 1; i < 6; i++) {
            l.insert((i * 10));

        }

        //Iterator i1 having its independent state...
        System.out.println(
               "Iterating list Consecutively..."
        );
        Iterator<Node> i1 = l.iterator();
        while (i1.hasNext()) {
            Node n1 =  i1.next();
            System.out.println(n1.getV());
        }

        //Iterator i2 having its independent state...
        System.out.println(
                "\nIterating list Alternatively..."
        );
        Iterator<Node> i2 = l.iterator();
        while (i2.hasNext()) {

            Node n1 = i2.next();
            System.out.println(n1.getV());
            i2.hasNext();
        }

    }

}

class Node {

    private final Node nxt;
    private final int v;

    public Node(int v, Node nxt) {
        this.nxt = nxt;
        this.v = v;
    }

    public Node getNxt() {
        return nxt;
    }

    public int getV() {
        return v;
    }

}


class Linklist implements Iterable<Object> {

    private Node head;

    void insert(int v) {
        head = new Node(v, head);
    }

    int pop() {
        if (head == null) {
            System.out.println("List Empty");
            return -1;
        }
        Node temp = head;
        head = head.getNxt();
        return temp.getV();
    }

    void print() {
        if (head == null) {
            System.out.println("List Empty");
            return;
        }
        Node temp = head;
        while (temp != null) {
            System.out.println(temp.getV());
            temp = temp.getNxt();
        }
    }

    @Override
    public Iterator iterator() {
        return new IteratorImplementation();
    }


class IteratorImplementation implements Iterator {

        Node temp = head;
        Node current;

        @Override
        public boolean hasNext() {
            if (temp == null) {
                return false;
            } else {
                current = temp;
                temp = temp.getNxt();
                return true;
            }
        }

        @Override
        public Object next() {
            return current;
        }
    }
}