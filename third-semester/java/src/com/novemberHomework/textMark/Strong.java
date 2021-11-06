package com.homeWork.textMark;

import java.util.List;

public class Strong implements textMark {  // сильное выделение __
    public Strong(List<? extends textMark> markElements) {
        markElements_ = markElements;
    }

    @Override
    public void toMarkdown(StringBuilder stringBuilder) {
        stringBuilder.append("__");
        for (textMark element : markElements_) {
            element.toMarkdown(stringBuilder);
        }
        stringBuilder.append("__");
    }

    final private List<? extends textMark> markElements_;
}
