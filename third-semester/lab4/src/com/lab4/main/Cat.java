package com.lab4.main;

import com.lab4.annotations.Repeat;

public class Cat {
    @Repeat()
    public void jump() {
        System.out.println("Cat jumps");
    }

    @Repeat(2)
    public void run() {
        System.out.println("Cat runs");
    }

    @Repeat(3)
    public void eat() {
        System.out.println("Cat eats");
    }

    @Repeat(4)
    public void showPeace() {
        System.out.println("Cat shows peace! :)");
    }
}
