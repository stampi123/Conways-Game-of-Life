#include "cse30life.h"
#include "board.h"

/**
 * create a new board
 *
 * - malloc a Board structure
 * - set the generation to 0
 * - open the file (if it doesn't exist, return a NULL pointer
 * - read the first line which is the number of rows
 * - read the second line which is the number of cols
 * - set the # of rows and # of cols in the boards structure
 * - malloc bufferA and bufferB 
 * - Set currentBuffer and nextBuffer
 * - clear both board buffers
 * - read the file until done.  each row contains a row and a columns separted by
 *   white space
 *     for each line, set the cell in the current buffer
 * - close the file
 * - return the boards pointer if successfull or NULL ptr otherwise
 */
Board* create_board(const char* filename) {
	// TODO
	  FILE* file = fopen(filename, "r");
    if (file == NULL) {
        return NULL; // File error
    }

    // Read number of rows and columns from the file
    size_t num_rows, num_cols;
    fscanf(file, "%zu %zu", &num_rows, &num_cols);

    // Allocate memory for the Board struct on the heap
    Board* board = malloc(sizeof(Board));
    if (board == NULL) {
        fclose(file);
        return NULL; // Memory allocation failed
    }

    // Initialize the struct members
    *board = (Board){
        .buffer_a = malloc(num_rows * num_cols * sizeof(Cell)),
        .buffer_b = malloc(num_rows * num_cols * sizeof(Cell)),
        .num_rows = num_rows,
        .num_cols = num_cols,
        .current_buffer = NULL,
        .next_buffer = NULL,
        .gen = 0
    };

 	board->buffer_a = malloc(num_rows * num_cols * sizeof(Cell));
    board->buffer_b = malloc(num_rows * num_cols * sizeof(Cell));
    if (board->buffer_a == NULL || board->buffer_b == NULL) {
        fclose(file);
        free(board->buffer_a);
        free(board->buffer_b);
        free(board);
        return NULL; // Memory allocation failed
    }

    // Set current buffer and next buffer
    board->current_buffer = board->buffer_a;
    board->next_buffer = board->buffer_b;

    // Clear both buffers
    clear_board(board);

    // Read cell coordinates and set cells in the current buffer
    size_t row, col;
    while (fscanf(file, "%zu %zu", &row, &col) == 2) {
        if (row < num_rows && col < num_cols) {
            size_t index = get_index(num_cols, row, col);
            board->current_buffer[index] = 1; // Set the cell to alive
        }
		else{
		fclose(file);
        return NULL; 
		}
}
 	fclose(file);
    return board;
}

/**
 * delete a board
 */
void delete_board(Board** bpp) {
	// TODO
	if (bpp == NULL || *bpp == NULL) {
        return; 
    }

    // Free memory for buffer_a and buffer_b
    free((*bpp)->buffer_a);
    free((*bpp)->buffer_b);

    // Free memory for the Board struct
    free(*bpp);

    // Set the pointer to NULL to indicate deletion
    *bpp = NULL;
}

/**
 * set all the Cells in both buffers to 0
 */
void clear_board(Board* board) {
	// TODO
 	if (board == NULL || board->buffer_a == NULL || board->buffer_b == NULL) {
        return; 
    }

    // Clear buffer_a
    for (size_t row = 0; row < board->num_rows; ++row) {
        for (size_t col = 0; col < board->num_cols; ++col) {
            size_t index = get_index(board->num_cols, row, col);
            board->buffer_a[index] = 0;
        }
    }

    // Clear buffer_b
    for (size_t row = 0; row < board->num_rows; ++row) {
        for (size_t col = 0; col < board->num_cols; ++col) {
            size_t index = get_index(board->num_cols, row, col);
            board->buffer_b[index] = 0;
        }
    }
}

/**
 * swap the current and next buffers
 */ 
void swap_buffers(Board* board) {
	// TODO
	 if (board == NULL) {
        return; 
    }

    // Swap current_buffer and next_buffer pointers directly
    Cell* temp = board->current_buffer;
    board->current_buffer = board->next_buffer;
    board->next_buffer = temp;
}

/**
 * get a cell index
 */
size_t get_index(size_t num_cols, size_t row, size_t col) {
	// TODO
	 return row * num_cols + col;
}
