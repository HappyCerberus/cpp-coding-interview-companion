cc_library(
    name = "sudoku",
    srcs = ["sudoku.cc"],
    hdrs = ["sudoku.h"],
)

cc_test(
    name = "sudoku_test",
    srcs = ["sudoku_test.cc"],
    deps = [
        ":sudoku",
        "@catch2//:catch2_main",
    ],
)
