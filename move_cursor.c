#include<stdio.h>
#include "move_cursor.h"

//move distance cells up
void move_up(int distance)
{
	printf("\x1b[%dA",distance);
}

//move distance cells down 
void move_down(int distance)
{
	printf("\x1b[%dB",distance);
}

//move distance cells right
void move_right(int distance)
{
	printf("\x1b[%dC",distance);
}

//move distance cells left
void move_left(int distance)
{
	printf("\x1b[%dD",distance);
}

/*	go to given position
 *  indexing starts from 1
 * 		i.e. top left corner is (1,1)
 */
void move_to(int row,int column)
{
	printf("\x1b[%d;%dH",row,column);
}

//	move to beginning of num lines below
void move_lines_down(int num_of_lines)
{
	printf("\x1b[%dE",num_of_lines);
}

//	move to beginning of num lines above
void move_lines_up(int num_of_lines)
{
	printf("\x1b[%dF",num_of_lines);
}

//go to given column while maintaining row(line)
void to_column(int column)
{
	printf("\x1b[%dG",column);
}

//save current cursor position; restore using load_cursor
void save_cursor(void)
{
	printf("\x1b[s");
}

//restore position saved using save_cursor
void load_cursor(void)
{
	printf("\x1b[u");
}

//clear from cursor to end of screen; does not move cursor
void clear_till_end(void)
{
	printf("\x1b[0J");
}

//clear from beginning of screen to cursor; does not move cursor
void clear_till_beginning(void)
{
	printf("\x1b[1J");
}


/*	clear screen by adding lines such that previous output is out of frame
 * 	previous output can be scrolled to reveal
 * 	retains cursor position relative to screen
 * 		i.e. if the cursor is at x,y then it will remain at x,y but 
 * 			 the text before it is few lines above it
 * 		eg.
 * 		-----------------------------		+++++++++++++++++++++++++++++
 * 		|							|		|							|	
 * 		|							|		|							|	<- not visible
 * 		|		A					|		|		A					|
 * 		|							|		-----------------------------
 * 		|							|		|							|
 * 		-----------------------------		|							|
 * 					Before					|		 B					|	<- visible
 * 											|							|
 * 											|							|
 * 											-----------------------------
 * 														After
 */
void clear_screen_with_scrollback(void)
{
	printf("\x1b[2J");
}

//clear screen, retains cursor position relative to screen
void clear_screen(void)
{
	clear_till_beginning();
	clear_till_end();
}

/*	clear screen, *may* clear scrollback or not
 * 	set cursor position to top-left of screen
 */
void clear_screen_goto_origin()
{
	clear_screen();
	move_to(1,1);
}

//clear output from cursor position to end of line; does not move cursor
void clear_line_after_cursor(void)
{
	printf("\x1b[0K");
}

//clear output from beginning of line to cursor position; does not move cursor
void clear_line_before_cursor(void)
{
	printf("\x1b[1K");
}

//clears current line; does not move cursor
void clear_line(void)
{
	printf("\x1b[2K");
}
