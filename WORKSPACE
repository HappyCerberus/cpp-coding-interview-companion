workspace(name = "coding")

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
    name = "hedron_compile_commands",
    sha256 = "6c2f27f742392bec503a8fac1829810324bb7f6be8350f16004b8356f8bc15bf",
    strip_prefix = "bazel-compile-commands-extractor-abdd06e05c7949721dba4bf1ae465bde16b9d3e1",
    url = "https://github.com/hedronvision/bazel-compile-commands-extractor/archive/abdd06e05c7949721dba4bf1ae465bde16b9d3e1.tar.gz",
)

load("@hedron_compile_commands//:workspace_setup.bzl", "hedron_compile_commands_setup")

hedron_compile_commands_setup()