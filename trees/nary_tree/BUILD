cc_library(
    name = "nary_tree",
    srcs = [
        "nary_tree.cc",
        "nary_tree_lib.cc",
    ],
    hdrs = ["nary_tree.h"],
)

cc_test(
    name = "nary_tree_test",
    srcs = ["nary_tree_test.cc"],
    deps = [
        ":nary_tree",
        "@catch2//:catch2_main",
    ],
)
