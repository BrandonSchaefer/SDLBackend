set (GTEST_ROOT_DIR
     "/usr/src/gtest"
     CACHE
     PATH
     "Path to Google Tests source"
     FORCE)

set (GTEST_INCLUDE_DIR
     "/usr/include/gtest"
     CACHE
     PATH
     "Path to Google Tests include"
     FORCE)

find_path (GTEST_INCLUDE_DIR gtests/gtest.h)

if (GTEST_INCLUDE_DIR)
  add_subdirectory (
    ${GTEST_ROOT_DIR}
    gtest
   )
endif (GTEST_INCLUDE_DIR)

enable_testing ()

#find_library (GMOCK_LIB gmock)
#find_library (GMOCK_MAIN_LIB gmock_main)
find_path (GTEST_SRC_DIR gtest.cc PATHS /usr/src/gtest/src)

if (GTEST_SRC_DIR)# AND
   # GMOCK_LIB AND
    #GMOCK_MAIN_LIB)

  set (GTEST_GMOCK_LIB
       gtest
       #${GMOCK_LIB}
       #${GMOCK_MAIN_LIB}
      )

  set (GTEST_BACKEND_SOURCE
       test_entity_creator.cpp
       test_main.cpp
       test_main_loop.cpp
       test_point.cpp
       test_rect.cpp
      )

  include_directories (${SDL_BACKEND_INCLUDE_DIRS} ${SDL_BACKEND_SOURCE_DIR}/src ${GTEST_INCLUDE_DIR})

  add_executable (../gtest-test-backend ${GTEST_BACKEND_SOURCE})
  target_link_libraries (../gtest-test-backend sdl-backend ${SDL_BACKEND_LIBRARIES} ${GTEST_GMOCK_LIB})
  add_test (MazeGTest ../gtest-test-backend)

  add_custom_target (check COMMAND ../gtest-test-backend)

endif (GTEST_SRC_DIR)# AND
       #GMOCK_LIB AND
       #GMOCK_MAIN_LIB)
