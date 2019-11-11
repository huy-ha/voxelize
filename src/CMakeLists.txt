add_library(VoxelizeLib INTERFACE)
target_include_directories(VoxelizeLib INTERFACE 
    ${PROJECT_SOURCE_DIR}/include
)
target_sources(VoxelizeLib INTERFACE 
    ${PROJECT_SOURCE_DIR}/src/voxelize/Voxelize.cpp
)
add_executable(VoxelizeDemo ${PROJECT_SOURCE_DIR}/src/main.cpp)
target_link_libraries(VoxelizeDemo VoxelizeLib)