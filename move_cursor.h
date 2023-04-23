#ifndef MOVE_CURSOR_INCLUDED
	#define MOVE_CURSOR_INCLUDED
	
	//move distance cells up
	void move_up(int distance);
	
	//move distance cells down 
	void move_down(int distance);
	
	//move distance cells right
	void move_right(int distance);
	
	//move distance cells left
	void move_left(int distance);
	
	/*	go to given position
	 *  indexing starts from 1
	 * 		i.e. top left corner is (1,1)
	 */
	void move_to(int row,int column);
	
	//	move to beginning of num lines below
	void move_lines_down(int num_of_lines);
	
	//	move to beginning of num lines above
	void move_lines_up(int num_of_lines);
	
	//go to given column while maintaining row(line)
	void to_column(int column);
	
	//save current cursor position; restore using load_cursor
	void save_cursor(void);
	
	//restore position saved using save_cursor
	void load_cursor(void);
	
	//clear from cursor to end of screen; does not move cursor
	void clear_till_end(void);
	
	//clear from beginning of screen to cursor; does not move cursor
	void clear_till_beginning(void);
	
	
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
	void clear_screen_with_scrollback(void);
	
	//clear screen, retains cursor position relative to screen
	void clear_screen(void);
	
	/*	clear screen, *may* clear scrollback or not
	 * 	set cursor position to top-left of screen
	 */
	void clear_screen_goto_origin();
	
	//clear output from cursor position to end of line; does not move cursor
	void clear_line_after_cursor(void);
	
	//clear output from beginning of line to cursor position; does not move cursor
	void clear_line_before_cursor(void);
	
	//clears current line; does not move cursor
	void clear_line(void);
	
#endif
