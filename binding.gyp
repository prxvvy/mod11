{
    "targets": [
        {
            "target_name": "rut_lib",
            "sources": [
                "./src/include/bool.h",
                "./src/include/list.h",
                "./src/include/node.h",
                "./src/include/rut.h",
                "./src/include/util.h",
                "./src/list.c",
                "./src/node.c",
                "./src/rut.c",
                "./src/util.c",
                "./src/main.cpp"
            ],
            "cflags!": [ "-fno-exceptions" ],
            "cflags_cc!": [ "-fno-exceptions" ],
            "include_dirs": [
                "<!@(node -p \"require('node-addon-api').include\")"
            ],
            'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ],
        }
    ]
}
