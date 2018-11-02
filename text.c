#include "text.h"

void convert_str_to_words(char* str, Word *wFront, Word *wEnd, int *chars, int *words)
{
	*words = 0;
	*chars = strlen(str);
	

}


int insert(Lines *lines, char *str)
{
	Line *line = (Line*)malloc(sizeof(Line*));
	line->no_of_chars = strlen(str);
	line->words = 0;
	Word *temp, *prev;
	int init_size = strlen(str);

	char *ptr = strtok(str, " ");

	while(ptr != NULL)
	{
		printf("'%s'\n", ptr);
		temp = (Word*)malloc(sizeof(Word*));
		temp->size = strlen(ptr);
		temp->chs = (char*) malloc(temp->size*sizeof(char*));
		strcpy(temp->chs, ptr);
		printf("'%s'\n", temp->chs);
		temp->next = NULL;
		temp->prev = NULL;
		if(line->first_word == NULL){
			line->first_word = temp;
			prev = temp;
		}else{
			prev->next = temp;
			temp->prev = prev;
			prev = temp;		
		}
		line->words += 1;
		ptr = strtok(NULL, delim);
	}
	if(lines->first_line == NULL)
		
}

void addLine(Lines *l, Line *ll)
{
	if(l->first_line == NULL)
		l->first_line = ll;
	else{
		(l->last_line)->next = ll;
		ll->prev = (l->last_line)
	}
}

int insert_at_pos(Lines *lines, Line *line, Word *word, char *st)
{

}



void main()
{
	Lines *lines = (Lines*) malloc(sizeof(Lines*));
	lines->no_of_lines = 0;
	lines->first_line = NULL;
	char s[1000];
//	fgets(s, 1000, stdin);
	char str[] = "strtok needs to be called several times to split a string";
	insert(lines, str);
	//Lines lines = (Lines*)malloc(sizeof(Lines*));
	//lines.no_of_lines = 0;
	//lines.line_head = null;
	//word *new = (word*)malloc(sizeof(word*));
	//new->chs = (char*)malloc(10*sizeof(char));
	//new->chs = "thisStr";
	//printf("%s",new->chs);
}
