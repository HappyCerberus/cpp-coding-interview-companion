cc_library(
    name = "queens",
    srcs = ["queens.cc"],
    hdrs = ["queens.h"],
)

cc_test(
    name = "queens_test",
    srcs = ["queens_test.cc"],
    deps = [
        ":queens",
        "@catch2//:catch2_main",
    ],
)
