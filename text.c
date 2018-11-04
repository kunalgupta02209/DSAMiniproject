#include "text.h"
/*
void convert_str_to_words(char *str, Word *wFront, Word *wEnd, int *chars, int *words)
{
	int wds = 0;
	int chs = strlen(str);
	*chars = chs;
	Word *temp, *prev;
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
		if(wds == 0)
			wFront = temp;
		else
		{
			temp->prev = prev;
			prev->next = temp;
			prev = temp;
		}
		wds += 1;
	}
	wEnd = prev;
}
*/

void convert_str_to_chs(char *str, Ch *cFront, Ch *cEnd, int *chars)
{
	*chars = strlen(str);
	Ch *temp, *prev;
	for(int i = 0; i < *chars; i++)
	{
		temp = (Ch*)malloc(sizeof(Ch*));
		temp->ch = str[i];
		if(i == 0)
		{
			cFront = temp;
			prev = temp;
		}
		else
		{
			temp->prev = prev;
			prev->next = temp;
			prev = temp;
		}
	}
	cEnd = prev;
}

Ch* findPos(Line *line, int pos)
{
	Ch *temp = line->first_char;
	int i = 0;
	while(i!=pos)
		temp=temp->next;
	return temp;
}

int insert_at_pos(Line *l, int position, char *str)
{
	if(position > l->no_of_chars+1)
		return 0;
	Ch *cFront, *cEnd;
	Ch *pos = findPos(l, position);
	Ch *pos2 = pos->next;
	int chars = 0;
	convert_str_to_chs(str, cFront, cEnd, &chars);
	l->no_of_chars += chars;

	if(pos != NULL)
		pos->next = cFront;
	else if(l->first_char == NULL)
		l->first_char = cFront;
	cFront->prev = pos;

	if(pos2 != NULL)
		pos2->prev = cEnd;
	else
		l->last_char = cEnd;
	cEnd->next = pos2;

	return 1;
}
/*

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
 */


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
