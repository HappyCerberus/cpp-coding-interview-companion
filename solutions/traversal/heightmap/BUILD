cc_library(
    name = "heightmap",
    srcs = ["heightmap.cc"],
    hdrs = ["heightmap.h"],
)

cc_test(
    name = "heightmap_test",
    srcs = ["heightmap_test.cc"],
    deps = [
        ":heightmap",
        "@catch2//:catch2_main",
    ],
)
