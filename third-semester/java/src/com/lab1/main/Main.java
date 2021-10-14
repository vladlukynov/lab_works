package com.lab1.main;

import com.lab1.hero.Hero;
import com.lab1.hero.Point;
import com.lab1.strategies.HorseStrategy;
import com.lab1.strategies.MovingStrategy;
import com.lab1.strategies.RunStrategy;
import com.lab1.strategies.SwimStrategy;

public class Main {
    public static void main(String[] args) {
        MovingStrategy movingStrategy;
        Hero hero = new Hero();

        System.out.println("Test situation when movingStrategy is empty");
        System.out.println("Start position: (" + hero.getPosition().x + ";" + hero.getPosition().y + ")");
        hero.moveHero(new Point(1.0, 1.0));
        System.out.println("Finish position: (" + hero.getPosition().x + ";" + hero.getPosition().y + ")");

        System.out.println("\nRunStrategy test");
        movingStrategy = new RunStrategy();
        hero.setMovingStrategy(movingStrategy);
        hero.moveHero(new Point(5.0, 3.0));

        System.out.println("\nHorseStrategy test");
        movingStrategy = new HorseStrategy();
        hero.setMovingStrategy(movingStrategy);
        hero.moveHero(new Point(15.0, 12.0));

        System.out.println("\nSwimStrategy test");
        movingStrategy = new SwimStrategy();
        hero.setMovingStrategy(movingStrategy);
        hero.moveHero(new Point(7.0, 3.0));
    }
}
