# プロジェクト名を設定
project(fileSystem)
set(PARENT_PROJECT_NAME common_library)

# インクルードフォルダ追加
include_directories(include)

# # C++ファイル取得
file(GLOB_RECURSE source_list "src/*.cpp")

# ライブラリ設定
add_library(${PROJECT_NAME} ${source_list})
add_library(${PARENT_PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

# ヘッダー
set_target_properties(
    ${PROJECT_NAME}
    PROPERTIES
        PUBLIC_HEADER include/fileSystem.hpp)

# インストール
install(
    TARGETS ${PROJECT_NAME}
    EXPORT commonLibraryTargets
    INCLUDES DESTINATION include
    PUBLIC_HEADER DESTINATION include/${PARENT_PROJECT_NAME}/${PROJECT_NAME}
    ARCHIVE DESTINATION lib/${CMAKE_BUILD_TYPE})