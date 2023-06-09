cc_library(
    name = "loop",
    srcs = ["loop.cc"],
    hdrs = ["loop.h"],
    deps = [
        "//lists:list",
    ],
)

cc_test(
    name = "loop_test",
    srcs = ["loop_test.cc"],
    deps = [
        ":loop",
        "@catch2//:catch2_main",
    ],
)
