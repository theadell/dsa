package de.adelhabib.searching;

import java.util.ArrayList;
import java.util.List;

class Node{
    Integer item;

    Node left;

    Node right;

    Node(Integer item){
        this.item = item;
    }

}

public class LeftViewTree {
    public static void main(String[] args) {
        Node root = new Node(10);
        root.left = new Node(20);
        root.right = new Node(30);
        root.left.left = new Node(40);
        root.left.right = new Node(50);
        var result = leftView(root);
        result.forEach(item -> System.out.println(item));

    }

    public static List<Integer> leftView(Node node) {
        List<Integer> res = new ArrayList<>();
        res.add(node.item);
        while (node.left != null) {
            node = node.left;
            res.add(node.item);
        }
        return res;
    }
}
