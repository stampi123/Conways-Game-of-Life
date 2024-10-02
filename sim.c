#include "sim.h"

#define C_IMPL
extern void asm_do_row(Cell*, Cell*, size_t, size_t, size_t);

/**
 * gets x mod N (works for negative numbers as well! Use this instead of %)
 */
size_t mod(int x, size_t N) {
	return (x + x / N * N) % N;
}

/**
 * process one row of the board
 */
static void do_row(Cell* dest, Cell* src, size_t row, size_t rows, size_t cols) {
	// TODO
	 size_t index = row * cols;
    for (size_t col = 0; col < cols; col++) {
        int live_neighbors = 0;
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i == 0 && j == 0) {
                    continue; // Skip the current cell
                }
                size_t neighbor_row = mod(row + i, rows);
                size_t neighbor_col = mod(col + j, cols);
                live_neighbors += src[neighbor_row * cols + neighbor_col];
            }
        }
        size_t cell_index = index + col;
        int current_cell = src[cell_index];
        if (current_cell == 1) {
            // Cell is currently alive
            dest[cell_index] = (live_neighbors == 2 || live_neighbors == 3) ? 1 : 0;
        } else {
            // Cell is currently dead
            dest[cell_index] = (live_neighbors == 3) ? 1 : 0;
        }
    }
}



/**
 * perform a simulation for "steps" generations
 *
 * for steps
 *   calculate the next board
 *   swap current and next
 */
void sim_loop(Board* board, unsigned int steps) {
	// TODO
	 for (unsigned int step = 0; step < steps; ++step) {
        do_row(board->next_buffer, board->current_buffer, 0, board->num_rows, board->num_cols);
        for (size_t row = 1; row < board->num_rows - 1; row++) {
            do_row(board->next_buffer, board->current_buffer, row, board->num_rows, board->num_cols);
        }
         swap_buffers(board);
        ++board->gen;
    }
}
