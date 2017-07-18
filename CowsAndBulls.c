#include<stdio.h>
#include<stdlib.h>
int len(char *str){
	int count = 0, i = 0;
	while (str[i] != '\0'){
		i++;
		count++;
	}
	return count;
}
void charMatch(char *sourceWord, char *guess){
	int i = 0, j = 0, cocks = 0, bulls = 0;
	int arr[26];
	for (i = 0; i < 26; i++){
		arr[i] = -1;
	}
	i = 0;
	while (sourceWord[i] != '\0'){
		arr[sourceWord[i] - 97] = i;
		i++;
	}
	while (guess[j] != '\0'){
		if (arr[guess[j] - 97] == j){
			cocks++;

		}
		else if (arr[guess[j] - 97] != j&&arr[guess[j] - 97] != -1){
			bulls++;
		}
		j++;
	}
	printf("cocks:%d\tbulls:%d\n", cocks, bulls);

}
int main()
{
	
	char *word1 = "faith";
	char word2[100];
	FILE *fp = stdin;
	int i = 0;
	char ch;
	while (1){
		i = 0;
		printf("enter your guess word\n");
		while (EOF != (ch = fgetc(fp)) && ch != '\n'){
			word2[i++] = ch;
		}
		word2[i] = '\0';

		charMatch(word1, word2);
	}
	return 0;
}