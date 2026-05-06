cmake_minimum_required(VERSION 3.19)
project(Zvezda LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets Sql)

qt_standard_project_setup()

qt_add_executable(Zvezda
    WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp
    mainwindow.h
    database_manager.h database_manager.cpp
    productspage.h productspage.cpp
    purchasespage.h purchasespage.cpp
)

target_link_libraries(Zvezda
    PRIVATE
        Qt::Core
        Qt::Widgets
        Qt6::Sql
)

install(TARGETS Zvezda
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET Zvezda
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
