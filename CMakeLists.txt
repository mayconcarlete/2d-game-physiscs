cmake_minimum_required(VERSION 3.22)

# include("C:/Users/Maycon/dev/vcpkg/scripts/buildsystems/vcpkg.cmake")
# include("/home/maycon/dev/vcpkg/scripts/buildsystems/vcpkg.cmake")
project(
    Physics
    LANGUAGES
    CXX
)

find_package(SDL2 CONFIG REQUIRED)
find_package(sdl2-gfx REQUIRED)
find_package(SDL2_image CONFIG REQUIRED)

add_executable(
    main
    ./src/Main.cpp
    ./src/Graphics.cpp
    # Vec2.cpp
)

target_link_libraries(main
PRIVATE
$<TARGET_NAME_IF_EXISTS:SDL2::SDL2main>
$<IF:$<TARGET_EXISTS:SDL2::SDL2>,SDL2::SDL2,SDL2::SDL2-static>
$<IF:$<TARGET_EXISTS:SDL2_image::SDL2_image>,SDL2_image::SDL2_image,SDL2_image::SDL2_image-static>
SDL2::SDL2_gfx
)
# ${SDL2_GFX_LIBRARIES}

# cmake -S. -Bbuild -DCMAKE_TOOLCHAIN_FILE="C:\Users\Maycon\dev\vcpkg\scripts\buildsystems\vcpkg.cmake"
# cmake -S. -Bbuild -VCPKG_PATH_TOOLCHAIN_FILE=C:\Users\Maycon\dev\vcpkg\scripts\buildsystems\vcpkg.cmake