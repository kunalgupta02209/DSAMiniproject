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


Line* convert_str_to_chs(char *str)
{
	Line *l = (Line*)malloc(sizeof(Line*));
	l->no_of_chars = strlen(str);
	Ch *temp, *prev;
	for(int i = 0; i < l->no_of_chars; i++)
	{
		temp = (Ch*)malloc(sizeof(Ch*));
		temp->ch = str[i];
		if(i == 0)
		{
			l->first_char = temp;
			prev = temp;
		}
		else
		{
			temp->prev = prev;
			prev->next = temp;
			prev = temp;
		}
	}
	l->last_char = prev;
	return l;
}

Ch* findPos(Line *line, int pos)
{
	Ch *temp = line->first_char;
	int i = 1;
	while(i<pos)
	{
		temp=temp->next;
		i++;
	}
	return temp;
}

Line* insert_at_pos(Line *l, int position, char *str)
{
	if(position > l->no_of_chars+1)
		return l;
	Ch *pos = findPos(l, position);	
	Ch *pos2;
	Line *temp;
	if(pos != NULL)
		pos2 = pos->next;
	int chars = 0;
	temp = convert_str_to_chs(str);
	
	l->no_of_chars += chars;
	if(l->first_char == NULL)
	{
		l = temp;
		return l;
	}
	if(pos != NULL)
		pos->next = temp->first_char;
	(temp->first_char)->prev = pos;

	if(pos2 != NULL)
		pos2->prev = temp->last_char;
	else
		l->last_char = temp->last_char;
	(temp->last_char)->next = pos2;

	return l;
}

void display(Line *l)
{
	Ch *cur = l->first_char;
	while(cur != NULL)
	{
		printf("%c", cur->ch);
		cur = cur->next;
	}
	printf("\n");
}

int main()
{

	//Lines *lines = (Lines*) malloc(sizeof(Lines*));
	//lines->no_of_lines = 0;
	//lines->first_line = NULL;
	//char s[1000];
//	fgets(s, 1000, stdin);

	char str[] = "strtok needs to be called several times to split a string";
	Line *l = (Line*)malloc(sizeof(Line));
	l->no_of_chars = 0;
	l = insert_at_pos(l,1,str);
	int choice = 1, pos = 0;
	while(choice != 4)
	{
		char s[1000];
		//display(l);
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				printf("Enter the text\n");
				scanf("%s",s);
				printf("Enter the position for insertion\n");
				scanf("%d", &pos);
				l = insert_at_pos(l,pos,s);
				display(l);
				break;
			case 2:
				break;
			case 3: 
				display(l);
			case 4:
				break;
			default:
				printf("Wrong Input selected\n");
		}
	}
	
	return 0;
}
