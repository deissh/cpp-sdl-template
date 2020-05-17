workspace(name = "roguelike")

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
    name = "sdl2",
    build_file = "sdl2.BUILD",
    sha256 = "e6a7c71154c3001e318ba7ed4b98582de72ff970aca05abc9f45f7cbdc9088cb",
    strip_prefix = "SDL2-2.0.8",
    urls = ["https://www.libsdl.org/release/SDL2-2.0.8.zip"],
)
http_archive(
    name = "sdl2_ttf",
    build_file = "sdl2_ttf.BUILD",
    sha256 = "ad7a7d2562c19ad2b71fa4ab2e76f9f52b3ee98096c0a7d7efbafc2617073c27",
    strip_prefix = "SDL2_ttf-2.0.14",
    urls = ["https://www.libsdl.org/projects/SDL_ttf/release/SDL2_ttf-2.0.14.zip"],
)
http_archive(
    name = "imgui",
    build_file = "imgui.BUILD",
    sha256 = "283a41ad534d2d3d7d480a6b6e2f16cc039c26444bfaaab2fea62a0bdeb07bd0",
    strip_prefix = "imgui-1.76",
    urls = ["https://github.com/ocornut/imgui/archive/v1.76.zip"],
)