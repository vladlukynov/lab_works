package com.homeWork.textMark;

public class Text implements textMark {
    public Text(String str) {
        str_ = str;
    }

    @Override
    public void toMarkdown(StringBuilder stringBuilder) {
        stringBuilder.append(str_);
    }

    private final String str_;
}
