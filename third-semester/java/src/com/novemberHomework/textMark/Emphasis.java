package com.homeWork.textMark;

import java.util.List;

public class Emphasis implements textMark {
    public Emphasis(List<? extends textMark> markElements) {
        markElements_ = markElements;
    }

    @Override
    public void toMarkdown(StringBuilder stringBuilder) {
        stringBuilder.append("*");
        for (textMark element : markElements_) {
            element.toMarkdown(stringBuilder);
        }
        stringBuilder.append("*");
    }

    final private List<? extends textMark> markElements_;
}
