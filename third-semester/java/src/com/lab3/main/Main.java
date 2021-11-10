package com.lab3.main;

import com.lab3.queue.Queue;
import com.lab3.animals.*;

import static com.lab3.functions.Functions.*;

public class Main {
    public static void main(String[] args) {
        try {
            Queue<Chordates> upperBoundQueue;

            Class<? extends Chordates> upperBoundClass = selectUpperBoundClass();
            upperBoundQueue = produce(upperBoundClass);

            Class<? super Cat> lowerBoundClass = selectLowerBoundClass();
            Queue<Chordates> lowerBoundQueue;
            lowerBoundQueue = consume(lowerBoundClass, upperBoundQueue);

            if (lowerBoundClass.isAssignableFrom(upperBoundClass)) {
                System.err.println("Wrong lower bound class!");
                System.exit(1);
            }

            while (!lowerBoundQueue.isEmpty()) {
                lowerBoundQueue.get().print();
            }
        } catch (Exception error) {
            System.err.println(error.getMessage());
            System.exit(1);
        }
    }
}
