#include <stdio.h>
#include <string.h>
#include <linux/input.h>

#define true 1

struct kbd_shortcut {
    char keys[256];
    char message[256];
};

void exec_shortcut(struct kbd_shortcut *shortcut, char *pressed_keys) {
    for (int i = 1; i < 256; i++) {
        if (shortcut->keys[i] != (0 < pressed_keys[i])) {
            return;
        }
    }
    
    printf("%s\n", shortcut->message);
    memset(pressed_keys, 0, 256);
}

int main() {
    FILE *kbd_events = fopen("/dev/input/by-path/platform-i8042-serio-0-event-kbd", "r");
    struct input_event kbd_event;
    
    struct kbd_shortcut shortcut_1 = {.message="I passed the Exam"};
    memset(shortcut_1.keys, 0, 256);
    shortcut_1.keys[KEY_P] = 1;
    shortcut_1.keys[KEY_E] = 1;
    
    struct kbd_shortcut shortcut_2 = {.message="Get some cappuccino!"};
    memset(shortcut_2.keys, 0, 256);
    shortcut_2.keys[KEY_C] = 1;
    shortcut_2.keys[KEY_A] = 1;
    shortcut_2.keys[KEY_P] = 1;
    
    struct kbd_shortcut shortcut_3 = {.message="Your RAM usage is reduced!"};
    memset(shortcut_3.keys, 0, 256);
    shortcut_3.keys[KEY_LEFTALT] = 1;
    shortcut_3.keys[KEY_F4] = 1;
    
    char pressed_keys[256];
    memset(pressed_keys, 0, 256);
    while (true) {
        if (fread(&kbd_event, sizeof(struct input_event), 1, kbd_events)) {
            if (kbd_event.type != EV_KEY) {
                continue;
            }
        
            pressed_keys[kbd_event.code] = kbd_event.value;
            exec_shortcut(&shortcut_1, pressed_keys);
            exec_shortcut(&shortcut_2, pressed_keys);
            exec_shortcut(&shortcut_3, pressed_keys);
        }
    }
    
    return 0;
}
