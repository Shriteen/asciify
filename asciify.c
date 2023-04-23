#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "letters.h"
#include "move_cursor.h"

void print_buf(PTR_BUF ptr)
{
	save_cursor();
	for(int i=0;i<MATRIX_HEIGHT;i++)
	{
		load_cursor();
		move_down(i);
		for(int j=0;j<MATRIX_WIDTH;j++)
		{
			printf("%c",ptr[i][j]);
		}
	}
	load_cursor();
	move_right(MATRIX_WIDTH);
}

void display(int max_chars_per_line,char *str)
{
	PTR_BUF ptr;
	clear_screen_goto_origin();
	for(int i=0,count=0;i<strlen(str);i++)
	{
		if(count==max_chars_per_line)
		{
			move_lines_down(MATRIX_HEIGHT+1);
			count=0;
		}
		ptr=ascii_matrix_of(str[i]);
		print_buf(ptr);
		count++;
	}
	move_lines_down(MATRIX_HEIGHT+1);
}

void help(void)
{
	printf("\t\tASCIIFY\n");
	printf("\tConverts alphanumeric characters to ascii art\n\n");
	printf("Syntax:\tasciify --help|-h\n");
	printf("\tasciify -[number] [string]\n");
	printf("\tasciify [string]\n\n");
	printf("string is the text to convert to ascii\n\n");
	printf("Options:--help,-h\tDisplay this help text and exit\n");
	printf("\t-[number]\tSet maximum number of characters per line\n");
}

int main(int argc,char *argv[])
{
	if(argc<2)
	{
		printf("Pass the string to asciify as argument\n");
		exit(1);
	}
	
	int max_chars_per_line=5;
	if(sscanf(argv[1],"-%d",&max_chars_per_line)==1)
	{
		if(argc<3)
		{
			printf("Pass the string to asciify as argument\n");
			exit(1);
		}
		if(max_chars_per_line<1)
		{
			printf("Maximum characters per line must be greater than 0\n");
			exit(2);
		}
		display(max_chars_per_line,argv[2]);
		if(argc>3)
			printf("Ignored extra arguments; For text containing spaces enclose text in quotes\n");
	}
	else if(!strcmp(argv[1],"--help") || !strcmp(argv[1],"-h"))
	{
		help();
	}
	else
	{
		if(max_chars_per_line<1)
		{
			printf("Maximum characters per line must be greater than 0\n");
			exit(2);
		}
		display(max_chars_per_line,argv[1]);
		if(argc>2)
			printf("Ignored extra arguments; For text containing spaces enclose text in quotes\n");
	}
}
