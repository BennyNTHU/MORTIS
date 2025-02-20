cmake_minimum_required(VERSION 3.10)
project(MORTIS VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 安裝 umbrella header
install(FILES src/MORTIS.hpp DESTINATION include)

# 安裝所有 .hpp 檔案到 include/MORTIS
install(DIRECTORY src/
        DESTINATION include/MORTIS
        FILES_MATCHING PATTERN "*.hpp")

# 限定只搜尋 src/ 下的 cpp 檔案
file(GLOB_RECURSE MORTIS_SOURCES 
    RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
    "src/*.cpp"
)

# 排除測試程式
foreach(file ${MORTIS_SOURCES})
    if(file MATCHES ".*[-_]test.*")
        list(REMOVE_ITEM MORTIS_SOURCES ${file})
    endif()
endforeach()

add_library(MORTIS STATIC ${MORTIS_SOURCES})

# 指定 src/ 為 include 根目錄
target_include_directories(MORTIS PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)
