#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
using namespace std;

void Cipher(FILE* fileCaesarCipher, FILE* EncryptedFile, int shift) {

    const unsigned short MAX_SIZE = 128;
    char line[MAX_SIZE];

    while (fgets(line, sizeof(line), fileCaesarCipher) != NULL) {
        cout << line << endl;


        for (int i = 0; line[i] != '\0'; ++i) {

            if (isalpha(line[i])) {

                char temp = islower(line[i]) ? 'a' : 'A';
                line[i] = ((line[i] - temp + shift) % 26) + temp;
            }
        }
        fputs(line, EncryptedFile);
        cout << line << endl;
    }
}

int main() {
    const char* pathOut = "CaesarCipher.txt";
    const char* pathIn = "EncryptedFile.txt";
    int shift = 3;

    FILE* fileOut, * fileIn;

    if (fopen_s(&fileOut, pathOut, "r") != 0)
        cout << "The file " << pathOut << " cannot be opened";
    else if (fopen_s(&fileIn, pathIn, "w") != 0)
        cout << "The file " << pathIn << " cannot be opened";
    else {
        Cipher(fileOut, fileIn, shift);

        fclose(fileOut);
        fclose(fileIn);
    }

    return 0;
}

