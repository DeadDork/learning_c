// Plays around with a linked list array.

// Conclusion: holy shit this works...!

// Universal {{{
enum list_elements {
	PREVIOUS,
	CONTENT,
	NEXT
};
// }}}

// Main {{{
#include <stdio.h>

void word_lister(void *[]);

int main(void) {
	char word[] = "";
	void *start_node[3] = {[PREVIOUS] = NULL, [CONTENT] = word};

	word_lister(start_node);

	return 0;
}
// }}}

// Create word list {{{
#include <ctype.h>
#include <string.h>

#define MAX_WORD 1000 // arbitary

int last_character = 'a'; // arbitrary initial non-EOF value
char temporary_word[MAX_WORD];

int get_temporary_word(void);
void print_list(void *[]);
void print_list_reverse(void *[]);

void word_lister(void *old_node[]) {
	void *new_node[3] = {[PREVIOUS] = old_node};
	old_node[NEXT] = new_node;

	if (last_character != EOF) {
		char word[get_temporary_word()];
		strcpy(word, temporary_word);
		new_node[CONTENT] = word;
		word_lister(new_node);
	} else {
		old_node[NEXT] = NULL;

		print_list(new_node);
		putchar('\n');

		print_list_reverse(new_node);
		putchar('\n');
	}
}

int get_temporary_word(void) {
	int character;

	while (isspace(character = getchar()));

	int element;
	for (element = 0; element < MAX_WORD - 1 && !isspace(character) && character != EOF && character != '\0'; ++element, character = getchar())
		temporary_word[element] = character;
	temporary_word[element] = '\0';

	last_character = character;

	return element;
}
// }}}

// Print lists {{{
void print_list(void *node[]) {
	if (node[PREVIOUS] != NULL)
		print_list(node[PREVIOUS]);

	if (node[NEXT] != NULL)
		printf("%s ", node[CONTENT]);
}

void print_list_reverse(void *node[]) {
	if (node[NEXT] != NULL)
		printf("%s ", node[CONTENT]);

	if (node[PREVIOUS] != NULL)
		print_list_reverse(node[PREVIOUS]);
}
// }}}
