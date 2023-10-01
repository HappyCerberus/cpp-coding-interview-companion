cc_library(
    name = "tree",
    srcs = ["tree.cc"],
    hdrs = ["tree.h"],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "construct_bst",
    srcs = ["construct_bst.cc"],
    hdrs = ["construct_bst.h"],
    visibility = ["//visibility:public"],
    deps = [":tree"],
)

cc_test(
    name = "construct_bst_test",
    srcs = ["construct_bst_test.cc"],
    deps = [
        ":construct_bst",
        "@catch2//:catch2_main",
    ],
)
