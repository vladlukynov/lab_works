package com.lab3.queue;

public class Queue<T> {
    public Queue() {
        size_ = 0;
    }

    public void add(T data) {
        if (head_ == null) {
            head_ = new Node(data);
            tail_ = head_;
        } else {
            tail_.next_ = new Node(data);
            tail_ = tail_.next_;
        }
        size_++;
    }

    public T get() throws IndexOutOfBoundsException {
        if (size_ == 0) {
            throw new IndexOutOfBoundsException("Size of queue is 0!");
        }
        Node temp = head_;
        head_ = head_.next_;
        size_--;
        return temp.data_;
    }

    public int getSize() {
        return size_;
    }

    public boolean isEmpty() {
        return (size_ == 0);
    }

    private class Node {
        Node(T data) {
            data_ = data;
        }

        T data_;
        Node next_;
    }

    private int size_;
    Node head_;
    Node tail_;
}
