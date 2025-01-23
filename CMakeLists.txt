cmake_minimum_required(VERSION 3.15)		  # never set less 3.15 min version
project(TestHello)

set(CMAKE_CXX_STANDARD 23)  # We're using C++23 standard :)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)  # Désactiver les extensions spécifiques au compilateur

# Build type is debug by default
# call cmake .. -DCMAKE_BUILD_TYPE=Release to change to relase
# call cmake .. -DCMAKE_BUILD_TYPE=Debug to revert to debug
if(NOT CMAKE_BUILD_TYPE)
set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type (Debug, Release, etc.)" FORCE)
endif()

add_compile_options(-Wshadow -Wnon-virtual-dtor -Wold-style-cast)

# Définir des options de compilation pour tous les compilateurs
add_compile_options(-Wall -Wextra -Wpedantic)

# Ajout de flags spécifiques pour GCC/Clang
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
  set(SANITIZE_FLAGS "-fsanitize=address,undefined") # Choisissez vos sanitizers ici
  if(CMAKE_BUILD_TYPE STREQUAL "Debug")
        add_compile_options(${SANITIZE_FLAGS} -fno-omit-frame-pointer -g)
        add_link_options(${SANITIZE_FLAGS})
    endif()
endif()


set(CMAKE_CXX_FLAGS_DEBUG "-Og -g")             # Debug : Optimisation légère pour le débogage
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")     # Release : Optimisation maximale sans symboles de debug


message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")


# Ajouter les fichiers source
add_executable(testHello src/test_Hello.cpp src/Hello.cpp)

# Inclure les répertoires d'en-têtes
target_include_directories(testHello PRIVATE include)





