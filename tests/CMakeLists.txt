find_package(GMock)

set (GTEST_GMOCK_LIB
    ${GTEST_BOTH_LIBRARIES}
    ${GMOCK_LIBRARIES}
  )

set (GTEST_BACKEND_SOURCE
   test_color.cpp
   test_entity_creator.cpp
   test_main_loop.cpp
   test_point.cpp
   test_rect.cpp
   test_world.cpp

   test_main.cpp
  )

include_directories (${SDL_BACKEND_INCLUDE_DIRS} ${SDL_BACKEND_SOURCE_DIR}/src ${GTEST_INCLUDE_DIR})

add_executable (../gtest-test-backend ${GTEST_BACKEND_SOURCE})
target_link_libraries (../gtest-test-backend sdl-backend ${SDL_BACKEND_LIBRARIES} ${GTEST_GMOCK_LIB})
add_test (MazeGTest ../gtest-test-backend)

add_custom_target (check COMMAND ../gtest-test-backend)
