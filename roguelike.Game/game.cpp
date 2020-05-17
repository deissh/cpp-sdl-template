#include "game.h"
#include "iostream"

Game::Game() {}
Game::~Game() {}

void Game::init(const char* title, GameArgs args) {
    int initFlags = SDL_INIT_VIDEO
        | SDL_INIT_TIMER
        | SDL_INIT_AUDIO
        | SDL_INIT_GAMECONTROLLER;

    if (SDL_Init(initFlags) != 0) {
        std::cout << "ERR: sdl not initialised!" << std::endl;
        return;
    }

    int flags = SDL_WINDOW_OPENGL
        | SDL_WINDOW_RESIZABLE
        | SDL_WINDOW_ALLOW_HIGHDPI;

    if (args.fullscreen) {
        flags |= SDL_WINDOW_FULLSCREEN_DESKTOP;
    }

    window = SDL_CreateWindow(
        title,
        args.xpos,
        args.ypos,
        args.width,
        args.height,
        flags
    );
    if (!window) {
        std::cout << "ERR: window not initialised!" << std::endl;
        return;
    }
    gl_context = SDL_GL_CreateContext(window);
    SDL_GL_MakeCurrent(window, gl_context);
    SDL_GL_SetSwapInterval(1); // Enable vsync

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();

    ImGuiIO& io = ImGui::GetIO(); (void)io;

    ImGui_ImplSDL2_InitForMetal(window);
    ImGui::StyleColorsDark();

    // Setup Platform/Renderer bindings
    ImGui_ImplSDL2_InitForOpenGL(window, gl_context);
    ImGui_ImplOpenGL2_Init();

    bool done = false;
    while(!done) {
        SDL_Event event;
        if (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT) done = true;
        }

        // Start the Dear ImGui frame
        ImGui_ImplOpenGL2_NewFrame();
        ImGui_ImplSDL2_NewFrame(window);
        ImGui::NewFrame();

        if (ImGui::BeginMainMenuBar())
        {
            if (ImGui::BeginMenu("Menu"))
            {
                if (ImGui::MenuItem("New")) {}
                if (ImGui::MenuItem("Open", "Ctrl+O")) {}
                if (ImGui::MenuItem("Save", "Ctrl+S")) {}
                if (ImGui::MenuItem("Save As..")) {}

                ImGui::Separator();

                if (ImGui::MenuItem("Quit", "Alt+F4")) done = true;

                ImGui::EndMenu();
            }
        
            ImGui::EndMainMenuBar();
        }

        ImGui::Render();
        ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());
        SDL_GL_SwapWindow(window);

        glClear(GL_COLOR_BUFFER_BIT);
    }

    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();

    SDL_DestroyWindow(window);
    SDL_Quit();

}