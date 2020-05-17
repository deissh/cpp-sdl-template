cc_library(
    name = "imgui",
    srcs = glob(
        include = [
            "*.cpp",
            "*.h",
            "examples/imgui_impl_sdl.*",
            "examples/imgui_impl_opengl2.*",
        ],
    ),
    visibility = ["//visibility:public"],
    alwayslink = 1,
    linkopts = ["-lGL -lGLU"],
    deps = [
        "@sdl2"
    ],
)
