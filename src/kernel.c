#include "kernel.h"

#include <stddef.h>
#include <stdint.h>

uint16_t *video_memory = 0;
uint16_t terminal_row = 0;
uint16_t terminal_col = 0;

uint16_t terminal_make_char(char c, char color) {
  return (uint16_t)c | (uint16_t)color << 8;
}

void terminal_putchar(int x, int y, char c, char color) {
  video_memory[y * VGA_WIDTH + x] = terminal_make_char(c, color);
}

void terminal_writechar(char c, char color) {
  if (c == '\n') {
    terminal_col = 0;
    terminal_row++;
    return;
  }

  terminal_putchar(terminal_col, terminal_row, c, color);
  terminal_col++;
  if (terminal_col >= VGA_WIDTH) {
    terminal_col = 0;
    terminal_row++;
  }
}

void terminal_initialize() {
  video_memory = (uint16_t *)0xb8000;
  for (int y = 0; y < VGA_HEIGHT; y++) {
    for (int x = 0; x < VGA_WIDTH; x++) {
      terminal_putchar(x, y, ' ', 0);
    }
  }
}

size_t strlen(const char *str) {
  size_t len = 0;
  while (str[len]) {
    len++;
  }
  return len;
}

void print(const char *str) {
  for (size_t i = 0; i < strlen(str); i++) {
    terminal_writechar(str[i], 15);
  }
}

void kernel_main() {
  terminal_initialize();
  print("Hello, world!\nThis is a new line!");
}
