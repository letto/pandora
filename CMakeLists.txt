project(pandora)

Find_Package ( SDL REQUIRED )

Set (CMAKE_CXX_FLAGS "-ggdb -O1 -std=gnu++0x -fno-exceptions -Wall")

Link_Libraries (
   ${SDL_LIBRARY}
   GL
   SDL_ttf
   SDLmain
)

add_subdirectory(src)

