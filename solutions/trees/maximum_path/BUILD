cc_library(
    name = "maximum_path",
    srcs = ["maximum_path.cc"],
    hdrs = ["maximum_path.h"],
    deps = [
        "//trees:tree",
    ],
)

cc_test(
    name = "maximum_path_test",
    srcs = ["maximum_path_test.cc"],
    deps = [
        ":maximum_path",
        "@catch2//:catch2_main",
    ],
)
