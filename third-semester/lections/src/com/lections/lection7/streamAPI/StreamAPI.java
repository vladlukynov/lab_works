package com.lections.lection7.streamAPI;

import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.util.stream.Stream;

public class StreamAPI {
    public static void main(String[] args) {
        System.out.println("--- forEach (10) ---");
        int[] array = {-1, -2, 0, 1, 2};
        for (int i : array) {
            if (i > 0) {
                System.out.print(i);
            }
        }
        System.out.println();

        System.out.println("--- Using Stream API (19) ---");
        Arrays.stream(array)
                .filter(n -> n > 0)
                .forEach(System.out::print);
        System.out.println();

        System.out.println("--- Stream creation example (25) ---");
        Stream.empty().forEach(System.out::print);     // пустой stream
        Stream.of(1, 2, 3).forEach(System.out::print); // stream из данных
        System.out.println();

        Stream.ofNullable(new Object()).forEach(System.out::print); // stream of nullable
        Stream.ofNullable(null).forEach(System.out::print);
        System.out.println();

        System.out.println("--- Stream generator (34) ---");
        Stream.generate(Math::random)
                .limit(5) // стрим создается бесконечно, но так можно установить предел
                .forEach(System.out::println);
        System.out.println();

        System.out.println("--- Stream iterator (40) ---");
        Stream.iterate(1, n -> n + 1)
                .limit(5)
                .forEach(System.out::print);
        System.out.println();

        System.out.println("--- With predicate (46) ---");
        Stream.iterate(1, n -> n < 6, n -> n + 1)
                .forEach(System.out::print);
        System.out.println();

        System.out.println("--- Stream concatenation (51) ---"); // соединить два готовых Stream в один новый
        Stream.concat(
                Stream.of(5),
                Stream.of("a")
        ).forEach(System.out::print);
        System.out.println();

        System.out.println("--- Stream builder (58) ---"); // добавление элементов без
        Stream.builder()                                   // использования дополнительных контейнеров
                .add(1)
                .add(2)
                .build()
                .forEach(System.out::print);
        System.out.println();

        System.out.println("--- Bounds (66) ---");
        Stream.of(1, 2, 3, 4, 5)
                .limit(3)                      // Позволяет ограничить выборку определенным
                .forEach(System.out::print);   // количеством первых элементов
        System.out.println();

        Stream.of(1, 2, 3, 4, 5)
                .skip(3)
                .forEach(System.out::print);
        System.out.println();

        System.out.println("--- Distinct (77) ---");  // возвращает стрим без дубликатов
        Stream.of(1, 2, 2, 2)                         // (для метода equals)
                .distinct()
                .forEach(System.out::print);
        System.out.println();

        System.out.println("--- Filter (83) ---");  // отфильтровывает записи, возвращает только записи,
        Stream.of(1, 2, 3, 4, 5)                    // соответствующие условию
                .filter(n -> n > 3)
                .forEach(System.out::print);
        System.out.println();

        System.out.println("--- Map (89) ---");  // позволяет применять функции к элементам
        Stream.of("1", "2", "3")                 // изменяет Stream
                .map(Integer::parseInt)
                .map(n -> n * n)
                .forEach(System.out::print);
        System.out.println();

        System.out.println("--- Flat map (96) ---");  // позволяет преобразовать один элемент
        Stream.of(1, 2, 3)                            // в несколько элементов
                .flatMapToInt(n -> IntStream.range(0, n))
                .forEach(System.out::print);
        System.out.println();

        System.out.println("--- Sorted (102) ---");  // Позволяет сортировать значения либо в натуральном порядке,
        Stream.of(4, 2, 5, 3, 1)                     // либо задавая Comparator
                .sorted()
                .forEach(System.out::print);
        System.out.println();

        System.out.println("--- Sorted with object (108) ---");
        Stream.of(new Cat(4), new Cat(2), new Cat(5))
                .sorted(Comparator.comparingInt(cat -> cat.age))
                .forEach(System.out::println);

        System.out.println("--- While (113) ---");
        Stream.of(1, 2, 3, 4, 3, 2, 1)
                .takeWhile(n -> n < 3)
                .forEach(System.out::print);
        System.out.println();

        Stream.of(1, 2, 3, 4, 3, 2, 1)
                .filter(n -> n < 3)
                .forEach(System.out::print);
        System.out.println();

        Stream.of(1, 2, 3, 4, 3, 2, 1)
                .dropWhile(n -> n < 3)
                .forEach(System.out::print);
        System.out.println();

        System.out.println("--- IntStream (129) ---");
        System.out.println(IntStream.range(0, 5)
                .filter(n -> n > 2)
                .count()
        );

        System.out.println("--- Find (135) ---");
        int i = IntStream.range(0, 5000)
                .parallel()
                .findAny().getAsInt();
        System.out.println(i);

        int k = IntStream.range(0, 500)
                .parallel()
                .findFirst().getAsInt();
        System.out.println(k);

        System.out.println("--- Match (146) ---");
        boolean isAllMatch = Stream.of(Math.random() + 3.5)
                .limit(5).allMatch(n -> n < 4);
        System.out.println(isAllMatch);

        boolean isNoneMatch = Stream.of(Math.random() + 3.5)
                .limit(5).allMatch(n -> n > 1);
        System.out.println(isNoneMatch);

        System.out.println("--- List example (155) ---");
        List<Integer> integers = Stream.of(1, 2, 3, 4, 5)
                .collect(Collectors.toList());
        integers.forEach(System.out::print);
        System.out.println();

        ArrayList<String> alphabet = Stream.of("a", "b", "c")
                .collect(Collectors.toCollection(ArrayList::new));
        alphabet.forEach(System.out::print);
        System.out.println();

        System.out.println("--- Map example (166) ---");
        Stream<Cat2> cats = Stream.of(
                new Cat2("Cat1", 5, 3),
                new Cat2("Cat2", 3, 7),
                new Cat2("Cat3", 6, 2),
                new Cat2("Cat4", 3, 4)
        );

        Map<String, Integer> catMap = cats
                .filter(cat2 -> cat2.getAge() > 3)
                .collect(Collectors.toMap(Cat2::getName, Cat2::getAge));
        catMap.forEach((k_, v) -> System.out.println(k_ + ": " + v));

        System.out.println("--- Reduce (179) ---");
        int result = Stream.of(2, 3, 4, 5)
                .reduce((x, y) -> x * y)
                .get();
        System.out.println(result);

        int resultWithStart = Stream.of(2, 3, 4, 5)
                .reduce(10, (x, y) -> x * y);
        System.out.println(resultWithStart);

        try {
            System.out.println("--- Exception. Closed stream (190) ---");
            Stream<String> alphabet_ = Arrays.stream(new String[]{"a", "b", "c"});
            alphabet_.forEach(System.out::print);
            System.out.println();
            long c = alphabet_.count();
        } catch (IllegalStateException error) {
            System.err.println(error.getMessage());
        }
    }

    private static class Cat {
        public Cat(int age) {
            this.age = age;
        }

        @Override
        public String toString() {
            return "Cat{age=" + age + "}";
        }

        int age;
    }

    private static class Cat2 {
        public Cat2(String name, int age, int weight) {
            this.name = name;
            this.age = age;
            this.weight = weight;
        }

        @Override
        public String toString() {
            return "Cat{name=" + name + ",age=" + age + ",weight=" + weight + "}";
        }

        public String getName() {
            return name;
        }

        int getAge() {
            return age;
        }

        String name;
        int age;
        int weight;
    }
}

/* Краткое описание конвейерных методов работы со стримами
filter - отфильтровывает записи, возвращает только записи, соответствующие условию
skip - позволяет пропустить N первых элементов
distinct - возвращает стрим без дубликатов (для метода equals)
map	- преобразует каждый элемент стрима
peek - возвращает тот же стрим, но применяет функцию к каждому элементу стрима
limit - позволяет ограничить выборку определенным количеством первых элементов
sorted - позволяет сортировать значения либо в натуральном порядке, либо задавая Comparator
mapToInt, mapToDouble, mapToLong - аналог map, но возвращает числовой стрим (то есть стрим из числовых примитивов)
flatMap, flatMapToInt, flatMapToDouble, flatMapToLong - похоже на map, но может создавать из одного элемента несколько */

/* Краткое описание терминальных методов работы со стримами
findFirst - возвращает первый элемент из стрима (возвращает Optional)
findAny - возвращает любой подходящий элемент из стрима (возвращает Optional)
collect - представление результатов в виде коллекций и других структур данных
count - возвращает количество элементов в стриме
anyMatch - возвращает true, если условие выполняется хотя бы для одного элемента
noneMatch - возвращает true, если условие не выполняется ни для одного элемента
allMatch - возвращает true, если условие выполняется для всех элементов
min - возвращает минимальный элемент, в качестве условия использует компаратор
max - возвращает максимальный элемент, в качестве условия использует компаратор
forEach - применяет функцию к каждому объекту стрима, порядок при параллельном выполнении не гарантируется
forEachOrdered - применяет функцию к каждому объекту стрима, сохранение порядка элементов гарантирует
toArray - возвращает массив значений стрима
reduce - позволяет выполнять агрегатные функции на всей коллекцией и возвращать один результат */

/* Краткое описание дополнительных методов у числовых стримов
sum - возвращает сумму всех чисел
average - возвращает среднее арифметическое всех чисел
mapToObj - преобразует числовой стрим обратно в объектный */

/* Несколько других полезных методов стримов
isParallel - узнать является ли стрим параллельным
parallel - вернуть параллельный стрим, если стрим уже параллельный, то может вернуть самого себя
sequential - вернуть последовательный стрим, если стрим уже последовательный, то может вернуть самого себя */
