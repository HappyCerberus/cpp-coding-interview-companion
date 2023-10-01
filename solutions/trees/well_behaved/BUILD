cc_library(
    name = "well_behaved",
    srcs = [
        "well_behaved.cc",
    ],
    hdrs = ["well_behaved.h"],
)

cc_test(
    name = "well_behaved_test",
    srcs = ["well_behaved_test.cc"],
    deps = [
        ":well_behaved",
        "@catch2//:catch2_main",
    ],
)
