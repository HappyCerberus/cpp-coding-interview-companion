cc_library(
    name = "sum_distances",
    srcs = [
        "sum_distances.cc",
    ],
    hdrs = ["sum_distances.h"],
)

cc_test(
    name = "sum_distances_test",
    srcs = ["sum_distances_test.cc"],
    deps = [
        ":sum_distances",
        "@catch2//:catch2_main",
    ],
)
