#include<stdio.h>
#include<string.h>

#define N 2
#define M 16

char S[N][M];

char F(char);
void encrypt(char, char, char *);
void decrypt(char, char, char *);
void init_boxes(char *);
void perform_encryption(char *, char *, char *);
void perform_decryption(char *, char *);

int main(int argc, char **argv)
{
	char buff[64];

	init_boxes("abcd");	

	encrypt('a', 'z', buff);
	printf("%c - %c\n", buff[0], buff[1]);
	decrypt(buff[0], buff[1], buff);
	
	printf("%c - %c\n", buff[0], buff[1]);
	printf("%s - %s\n", S[0], S[1]);
//	perform_encryption(argv[0], argv[1], buff);
//	perform_decryption(buff, buff);
	
	printf("%s\n", buff);
	return 0;
}

char F(char x)
{
	return S[0][x >> 6] + S[1][x >> 4];
}

void encrypt(char L, char R, char *out)
{
	for (short i = 0; i < 16; ++i)
	{
		R ^= F(L);
		L ^= F(R);
	}
	out[0] = R;
	out[1] = L;
}

void decrypt(char L, char R, char *out)
{
	encrypt(L, R, out);
}

void init_boxes(char *key)
{
	for (short i = 0; i < N * M; ++i)
		S[i / M][i % M] = key[i % strlen(key)];
}

void perform_encryption(char *text, char *key, char *encrypted)
{
	init_boxes(key);
	for (short i = 0; i < strlen(text) - 1; ++i)
		encrypt(text[i], text[i + 1], encrypted + i);
	encrypted[strlen(text)] = '\0';
}

void perform_decryption(char *encrypted, char *decrypted)
{
	for (short i = 0; i < strlen(encrypted) - 1; ++i)
		decrypt(encrypted[i], encrypted[i + 1], decrypted + i);
	decrypted[strlen(encrypted)] = '\0';
}


