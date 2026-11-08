#include <stdio.h>
#define MAXLINE 1000

int get_line(int n);
void detab(int n, int i, int col);
void entab(int n, int i, int col);
void copy(void);

char line[MAXLINE];
char text[MAXLINE];
int t = 0;

int main() {
        extern char text[];
        int len;

	int n = getchar() - '0';
        while ( (len = get_line(n)) > 0)
                copy();

        printf("\n%s\n", text);
}

int get_line(int n) {
        extern char line[];
        int c, i, col;
        col = 0;

        for (i=0; i<MAXLINE && (c=getchar()) != EOF && c != '\n'; i++) {
        	if (c == '\t')
	   		detab(n, i, col);
		
		else if (c == ' ')
			entab(n, i, col);
	
		else 
			line[i] = c;
			col++;
	
        }

        if (c == '\n') {
                line[i] = '\n';
                i++;
        }
        line[i] = '\0';
        return i;
}

void detab(int n, int i, int col) {
     	extern char line[];

	while ((col % n) != 0) {
        	line[i] = ' ';
                i++, col++;
        }
        line[i] = ' ';
}

void entab(int n, int i, int col) {
	extern char line[];
	
	if ( (col % n) == 0 && n >= 8) {
		line[i] = '\t';
		if (n > 8) {
			i++, col++;
			line[i] = ' ';
		}
	} else 
		line[i] = ' ';
		i++, col++;
	
}

void copy(void) {
        extern char line[], text[];
        int i = 0;
        while( (text[t] = line[i]) != '\0') {
                i++;
                t++;
        }
}
