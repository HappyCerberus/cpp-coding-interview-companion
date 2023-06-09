cc_library(
    name = "kgroups",
    srcs = ["kgroups.cc"],
    hdrs = ["kgroups.h"],
    deps = ["//lists:list"],
)

cc_test(
    name = "kgroups_test",
    srcs = ["kgroups_test.cc"],
    deps = [
        ":kgroups",
        "@catch2//:catch2_main",
    ],
)
