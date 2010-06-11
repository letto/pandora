project(pandora)

Find_Package ( SDL REQUIRED )

Set (CMAKE_CXX_FLAGS "-g -O1 -std=c++0x -fno-exceptions -Wall -Winvalid-pch")

Link_Libraries (
   ${SDL_LIBRARY}
   GL
   SDL_ttf
   SDLmain
)

add_subdirectory(src)

