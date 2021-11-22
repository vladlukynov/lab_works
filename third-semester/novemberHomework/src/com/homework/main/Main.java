package com.homework.main;

import com.homework.textMark.Paragraph;
import com.homework.textMark.Strikeout;
import com.homework.textMark.Strong;
import com.homework.textMark.Emphasis;
import com.homework.textMark.Text;

import java.util.List;

public class Main {
    public static void main(String[] args) {
        StringBuilder stringBuilder = new StringBuilder();
        Paragraph paragraph = new Paragraph(List.of(
                new Strong(List.of(
                        new Text("1"),
                        new Strikeout(List.of(
                                new Text("2"),
                                new Emphasis(List.of(
                                        new Text("3"),
                                        new Text("4")
                                )),
                                new Text("5")
                        )),
                        new Text("6")
                ))
        ));
        paragraph.toMarkdown(stringBuilder);
        System.out.println(stringBuilder);
    }
}
