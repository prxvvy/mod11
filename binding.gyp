{
    "targets": [
        {
            "target_name": "rut_lib",
            "sources": [
                "./src/include/rut_functions.h",
                "./src/include/util.h",
                "./src/mod11.cpp",
                "./src/rut_functions.c",
                "./src/util.c",
            ],
            "cflags!": ["-fno-exceptions"],
            "cflags_cc!": ["-fno-exceptions"],
            "include_dirs": ["<!@(node -p \"require('node-addon-api').include\")"],
            "defines": ["NAPI_DISABLE_CPP_EXCEPTIONS"],
        }
    ]
}
