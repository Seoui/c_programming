#pragma once

#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <conio.h>

#define MAX_PLAIN 1024
#define MAX_CIPHER 1024

void Encrypt_Caesar(char *plaintext_cae, int key_cae);
void Decrypt_Caesar(char *ciphertext_cae, int key_cae);
void Caesar();

void Encrypt_Vigenere(char *plaintext_vig, char *key_vig);
void Decrypt_Vigenere(char *ciphertext_vig, char *key_vig);
void Vigenere();

void Encrypt_Rail(char *plaintext_rail, int depth);
void Decrypt_Rail(char *ciphertext_rail, int depth);
void Railfence();

void Encrypt_Poly(char *plaintext_poly);
void Decrypt_Poly(char *ciphertext_poly);
void Polybius();

void Encrypt_Squre(char *plaintext_squre, int key_squre, char* key_array);
void Decrypt_Squre(char* ciphertext_squre, int key_squre, char* key_array);
void SquareMatrix();

void Encrypt_Play(char *plaintext_play, char *key_play);
void Decrypt_Play(char *ciphertext_play, char *key_play);
void Playfair();