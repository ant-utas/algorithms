#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// Function to clear the screen
void clearScreen() {
    printf("\033[H\033[J");
}

// Function to move the cursor to the top-left of the screen
void moveToTopLeft() {
    printf("\033[H");
}

int main() {
    const int width = 80;  // Width of the terminal
    const int frames = width - 10;  // Number of frames for the animation
    const int delay = 100000;  // Delay between frames in microseconds (100000 microseconds = 0.1 seconds)

    // ASCII art for Ryu and Hadouken
    char *ryu[] = {
        "    .-'''''-.    ",
        "  .'         `.  ",
        " :             : ",
        " :             : ",
        "  `.         .'  ",
        "    `-.....-'    "
    };

    char *hadouken[] = {
        "    ____    ",
        "  /'    `\\  ",
        " |        | ",
        "  \\______/  "
    };

    int ryuHeight = sizeof(ryu) / sizeof(ryu[0]);
    int hadoukenHeight = sizeof(hadouken) / sizeof(hadouken[0]);

    // Animation loop
    for (int frame = 0; frame < frames; frame++) {
        clearScreen();
        moveToTopLeft();

        // Print Ryu
        for (int i = 0; i < ryuHeight; i++) {
            printf("%s\n", ryu[i]);
        }

        // Print spaces for the Hadouken position
        for (int i = 0; i < ryuHeight; i++) {
            printf("\n");
        }

        // Print spaces to move the Hadouken to the right
        for (int i = 0; i < frame; i++) {
            printf(" ");
        }

        // Print the Hadouken
        for (int i = 0; i < hadoukenHeight; i++) {
            if (i > 0) {
                for (int j = 0; j < frame; j++) {
                    printf(" ");
                }
            }
            printf("%s\n", hadouken[i]);
        }

        // Flush the output to ensure smooth animation
        fflush(stdout);

        // Delay between frames
        usleep(delay);
    }

    return 0;
}

