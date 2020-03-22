cc_library(
    name='singleton',
    srcs=[
        './singleton.h'
    ],
)

cc_library (
    name='dynamic_dict',
    srcs = [
        './dynamic_dict.h'
    ],
)

cc_binary(
    name='template_test',
    srcs=[
        './unittest/template_test.cpp'
    ],
    deps=[
        ':singleton',
        ':dynamic_dict'
    ]
)
