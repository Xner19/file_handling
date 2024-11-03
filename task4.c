#include <stdio.h>
#include <string.h>

int main() {
    char text[100];
    int shift = 3; 
    char mode;
    
    printf("Enter text to encrypt or decrypt: ");
    fgets(text, sizeof(text), stdin);

    printf("Enter E for Encrypt or D for Decrypt: ");
    scanf(" %c", &mode);

    if (mode == 'E') {
        for (int i = 0; text[i] != '\0'; i++) {
            if (text[i] >= 'A' && text[i] <= 'Z') {
                text[i] = ((text[i] - 'A' + shift) % 26) + 'A';
            } else if (text[i] >= 'a' && text[i] <= 'z') {
                text[i] = ((text[i] - 'a' + shift) % 26) + 'a';
            }
        }
        printf("Encrypted text: %s\n", text);
    } else if (mode == 'D') {
        for (int i = 0; text[i] != '\0'; i++) {
            if (text[i] >= 'A' && text[i] <= 'Z') {
                text[i] = ((text[i] - 'A' - shift + 26) % 26) + 'A';
            } else if (text[i] >= 'a' && text[i] <= 'z') {
                text[i] = ((text[i] - 'a' - shift + 26) % 26) + 'a';
            }
        }
        printf("Decrypted text: %s\n", text);
    } else {
        printf("Invalid option.\n");
    }

    return 0;
}

