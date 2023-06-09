cc_library(
    name = "remove_kth",
    srcs = ["remove_kth.cc"],
    hdrs = ["remove_kth.h"],
    deps = ["//lists:list"],
)

cc_test(
    name = "remove_kth_test",
    srcs = ["remove_kth_test.cc"],
    deps = [
        ":remove_kth",
        "@catch2//:catch2_main",
    ],
)
