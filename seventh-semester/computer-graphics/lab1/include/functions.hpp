#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

enum window_state_t {
    PAGE_1, PAGE_2
};

void display();
void handleKeyboard(unsigned char key, int width, int height);
void handleSpecialKeys(int key, int width, int height);

#endif
