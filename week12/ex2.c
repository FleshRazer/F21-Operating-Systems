#include <stdio.h>
#include <linux/input.h>

#define true 1

int main() {
    FILE *kbd_events = fopen("/dev/input/by-path/platform-i8042-serio-0-event-kbd", "r");
    struct input_event kbd_event;
    
    while (true) {
        if (fread(&kbd_event, sizeof(struct input_event), 1, kbd_events)) {
            if (kbd_event.code == 0) {
                continue;
            }
        
            switch(kbd_event.value) {
                case 0:
                    printf("RELEASED %#06x (%d)\n", kbd_event.code, kbd_event.code);
                    break;
                case 1:
                    printf("PRESSED %#06x (%d)\n", kbd_event.code, kbd_event.code);
                    break;
            }
        }
    }
    
    return 0;
}
