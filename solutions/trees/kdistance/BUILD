cc_library(
    name = "kdistance",
    srcs = ["kdistance.cc"],
    hdrs = ["kdistance.h"],
    deps = [
        "//trees:tree",
    ],
)

cc_test(
    name = "kdistance_test",
    srcs = ["kdistance_test.cc"],
    deps = [
        ":kdistance",
        "@catch2//:catch2_main",
    ],
)
