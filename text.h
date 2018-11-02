#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>


struct w{
	char *chs;
	int size; //size of each word
	struct w *next, *prev;
};

typedef struct w Word;

struct l{
	Word *first_word;
	int no_of_chars; 
	int words; //no. of words
	struct l *next, *prev;
};

typedef struct l Line;

struct ls{
	Line *line_head;
	int no_of_lines; //no. pf lines
}

typedef struct ls Lines;

int insert_front(Line line, char* str);
void convert_str_to_words(char *str, Word *wFront, Word *wEnd, int *chars, int *words);
