project(pandora)

Find_Package ( SDL REQUIRED )

Set (CMAKE_CXX_FLAGS " -std=gnu++0x")

Link_Libraries (
   ${SDL_LIBRARY}
   GL
   SDL_ttf
   SDLmain
)

add_subdirectory(src)


