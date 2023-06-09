cc_library(
    name = "merge",
    srcs = ["merge.cc"],
    hdrs = ["merge.h"],
)

cc_test(
    name = "merge_test",
    srcs = ["merge_test.cc"],
    deps = [
        ":merge",
        "@catch2//:catch2_main",
    ],
)
