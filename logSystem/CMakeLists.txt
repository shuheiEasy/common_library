# プロジェクト名を設定
project(logSystem)
set(PARENT_PROJECT_NAME common_library)

# インクルードフォルダ追加
include_directories(.)

# # C++ファイル取得
file(GLOB_RECURSE source_list "src/*.cpp")

# ライブラリ設定
add_library(${PROJECT_NAME} ${source_list})
add_library(${PARENT_PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

# ヘッダー
file(GLOB_RECURSE header_list "*.hpp")
set_target_properties(
    ${PROJECT_NAME} PROPERTIES
    FRAMEWORK TRUE
    PUBLIC_HEADER "${header_list}")

# インストール
install(
    TARGETS ${PROJECT_NAME}
    EXPORT commonLibraryTargets
    INCLUDES DESTINATION include
    PUBLIC_HEADER DESTINATION include/${PARENT_PROJECT_NAME}/${PROJECT_NAME}
    ARCHIVE DESTINATION lib/${CMAKE_BUILD_TYPE})