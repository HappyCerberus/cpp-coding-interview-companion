# Modern-Only C++ Course - Homework

This repository contains the homework for Lesson 6.

## Format

Implement a `format_range` function (in file `format/format.h`) that formats the provided range into the provided output stream.

The content of the range should be surrounded by `{}`, each pair of elements should be delimited by `,`.

```
bazel test //format/...
bazel test --config=addrsan //format/...
bazel test --config=ubsan //format/...
```

## Advanced format

Implement a `format_range` function (in file `format_advanced/format.h`) that formats the provided range into the provided output stream.

The content of the range should be surrounded by `{}`.
Each pair of elements should be delimited based on the range type:

- `,` for random access ranges
- `<=>` for bidirectional ranges
- `->` for forward ranges

```
bazel test //format_advanced/...
bazel test --config=addrsan //format_advanced/...
bazel test --config=ubsan //format_advanced/...
```

## Trim whitespace

Implement a compound view `trim_whitespace` (in the file `trim_whitespace/trim.h`) that trims the leading and trailing whitespace from a character based range.

The goal is to have the following commands pass without errors:

```
bazel test //trim_whitespace/...
bazel test --config=addrsan //trim_whitespace/...
bazel test --config=ubsan //trim_whitespace/...
```

## Luhn validation

Implement function `validate` (in file `luhn_validation/validate.h`) that implements [Luhn validation](https://en.wikipedia.org/wiki/Luhn_algorithm) on top of a range of integers representing the digits of a card number.

The goal is to have the following commands pass without errors:

```
bazel test //luhn_validation/...
bazel test --config=addrsan //luhn_validation/...
bazel test --config=ubsan //luhn_validation/...
```

## Solutions

If you wish to have a look at the solutions, you can find the commented code in the `solutions` directory.