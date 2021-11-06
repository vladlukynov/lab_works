package com.homeWork.textMark;

import java.util.List;

public class Paragraph implements textMark {
    public Paragraph(List<? extends textMark> markElements) {
        markElements_ = markElements;
    }

    @Override
    public void toMarkdown(StringBuilder stringBuilder) {
        for (textMark element : markElements_) {
            element.toMarkdown(stringBuilder);
        }
    }

    final private List<? extends textMark> markElements_;
}
