#include "test_compound_literal.h"
#include "test_util.h"

#define COLS 5
#define ROWS 2

static void test_iterate1d_arr(const int *arr, const size_t size);
// static void test_iterate1d_arr(const int arr[], const size_t size);

static void test_iterate2d_arr(const int (*arr)[COLS], const size_t rows);
// static void test_iterate2d_arr(const int arr[][COLS], const size_t rows);

void test_compound_literal_arr1d(void) {
    log_debug("array 1d\n");
    int *arr = NULL;
    arr = (int []) {1, 2, 3, 4, 5};
    // arr = (int [COLS]) {1, 2, 3, 4, 5};
    test_iterate1d_arr(arr, COLS);
}

void test_compound_literal_arr2d(void) {
    log_debug("array 2d\n");
    int (*arr)[COLS];
    arr = (int [][COLS]){ {1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}};
    // arr = (int [ROWS][COLS]){ {1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}};
    test_iterate2d_arr(arr, ROWS);
}

static void test_iterate2d_arr(const int (*arr)[COLS], const size_t rows) 
// static void test_iterate2d_arr(const int arr[][COLS], const size_t rows)
{
    for (size_t r = 0; r < rows; ++r) {
        test_iterate1d_arr(arr[r], COLS);
    }
}

static void test_iterate1d_arr(const int *arr, const size_t size)
// static void test_iterate1d_arr(const int arr[], const size_t size)
{
    for (size_t i = 0; i < COLS; ++i) {
        log_debug("%d, ", arr[i]);
    }
    log_debug("\n");
}