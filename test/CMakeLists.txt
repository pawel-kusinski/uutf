function(add_self_test SOURCE_FILE)
    get_filename_component(TARGET_NAME ${SOURCE_FILE} NAME_WE)

    set(TARGET_SOURCES
        ${SOURCE_FILE}
    )

    set(TARGET_INCLUDES
        ${CMAKE_SOURCE_DIR}/include
    )

    add_executable(${TARGET_NAME} ${TARGET_SOURCES})
    target_include_directories(${TARGET_NAME} PRIVATE ${TARGET_INCLUDES})

    add_test(NAME ${TARGET_NAME} COMMAND ${TARGET_NAME})
endfunction()

file(GLOB TEST_FILES ${CMAKE_CURRENT_LIST_DIR}/test_*.c)

foreach(TEST_FILE IN LISTS TEST_FILES)
    add_self_test(${TEST_FILE})
endforeach()

enable_testing()
