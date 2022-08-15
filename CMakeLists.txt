# CMakeのバージョンを設定
cmake_minimum_required(VERSION 3.11.0)

# プロジェクト名と使用する言語を設定
project(common_library CXX)

# サブプロジェクト設定
add_subdirectory(fileSystem)
add_subdirectory(dataObject)
add_subdirectory(logSystem)

install(
    EXPORT commonLibraryTargets
    DESTINATION cmake
    NAMESPACE common_library::
    FILE commonLibraryTargets.cmake)

include(CMakePackageConfigHelpers)
configure_package_config_file( 
    "Config.cmake.cfg" 
    "common_libraryConfig.cmake"
    INSTALL_DESTINATION cmake)

install(
    FILES "${CMAKE_CURRENT_BINARY_DIR}/common_libraryConfig.cmake"
    DESTINATION "cmake")
