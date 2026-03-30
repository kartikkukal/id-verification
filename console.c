// console.c

// A simple wrapper over platform specific 
// libraries for enchanced console output.

#define DELIMITER '-'

#if defined(__linux__)

#include <ncurses.h>

void console_initialize() {
    initscr();
    cbreak();
}

void console_clear() {
    clear();
}

void console_finish() {
    endwin();
} 

void console_print(const char* string) {
    addstr(string);
}

const char console_input_option() {
    char ch = getch();
    printw("\n");

    return ch;
}

void console_input_id(char* id, int length, int group) {
    for (int i = 0; i < length; i++) {
        char ch = getch();
        id[i] = ch;

        if ((i + 1) % group == 0 && (i + 1) != length) {
            printw("%c", DELIMITER);
        }
    }
}

void console_print_id(char* id, int length, int group) {
    for (int i = 0; i < length; i++) {
        printw("%c", id[i]);

        if ((i + 1) % group == 0 && (i + 1) != length) {
            printw("%c", DELIMITER);
        }
    }
}

void console_wait() {
    getch();
}

#else

#include <stdio.h>

void console_initialize() {
    return;
}

void console_clear() {
    printf("\n");
}

void console_finish() {
    return;
} 

void console_print(const char* string) {
    printf("%s", string);
}

const char console_input_option() {
    char ch;
    scanf("%c", &ch);
    while( getchar() != '\n');

    return ch;
}

void console_input_id(char* id, int length, int group) {
    scanf("%s", id);
    while( getchar() != '\n');
}

void console_print_id(char* id, int length, int group) {
    for (int i = 0; i < length; i++) {
        printf("%c", id[i]);

        if ((i + 1) % group == 0 && (i + 1) != length) {
            printf("%c", DELIMITER);
        }
    }
}

void console_wait() {
    return;
}
#endif