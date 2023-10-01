cc_library(
    name = "validate_bst",
    srcs = ["validate_bst.cc"],
    hdrs = ["validate_bst.h"],
    deps = [
        "//trees:tree",
    ],
)

cc_test(
    name = "validate_bst_test",
    srcs = ["validate_bst_test.cc"],
    deps = [
        ":validate_bst",
        "//trees:construct_bst",
        "@catch2//:catch2_main",
    ],
)
