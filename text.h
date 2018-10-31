struct w{
	char *chs;
	int size; //size of each word
	struct w *next, *prev;
};

typedef struct w Word;

struct l{
	Word *word_head;
	int words; //no. of words
	struct l *next, *prev;
};

typedef struct l Line;

struct ls{
	Line *line_head;
	int no_of_lines; //no. pf lines
}

typedef struct ls Lines;