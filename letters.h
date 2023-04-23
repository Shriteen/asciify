#ifndef LETTERS_INCLUDED
	#define LETTERS_INCLUDED
	
	#define MATRIX_WIDTH 15
	#define MATRIX_HEIGHT 8
	typedef char (*PTR_BUF)[MATRIX_WIDTH];
	PTR_BUF ascii_matrix_of(char character);
#endif
