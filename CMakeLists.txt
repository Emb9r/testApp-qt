cmake_minimum_required(VERSION 3.19)
project(testApp LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets LinguistTools)
find_package(Qt6 REQUIRED COMPONENTS Core)

qt_standard_project_setup()

qt_add_executable(testApp
    WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp mainwindow.h mainwindow.ui
    workwindow.h workwindow.cpp workwindow.ui
    fileworker.h fileworker.cpp
)

qt_add_translations(
    TARGETS testApp
    TS_FILES testApp_ru_RU.ts
)

target_link_libraries(testApp
    PRIVATE
        Qt::Core
        Qt::Widgets
)
target_link_libraries(testApp PRIVATE Qt6::Core)

include(GNUInstallDirs)

install(TARGETS testApp
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET testApp
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})

if(WIN32)
    set(EXE_DIR $<TARGET_FILE_DIR:testApp>)

    add_custom_command(TARGET testApp POST_BUILD
        COMMAND "${CMAKE_COMMAND}" -E echo "Deploying Qt DLLs..."
        COMMAND "${Qt6_DIR}/../../../bin/windeployqt.exe" --dir "${EXE_DIR}" "$<TARGET_FILE:testApp>"
        COMMENT "Copying Qt DLLs to output directory"
    )
endif()
