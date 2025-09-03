include("E:/Projects/QtProjects/testApp/build/Desktop_Qt_6_9_2_MinGW_64_bit-Release/.qt/QtDeploySupport.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/testApp-plugins.cmake" OPTIONAL)
set(__QT_DEPLOY_I18N_CATALOGS "qtbase")

qt6_deploy_runtime_dependencies(
    EXECUTABLE "E:/Projects/QtProjects/testApp/build/Desktop_Qt_6_9_2_MinGW_64_bit-Release/testApp.exe"
    GENERATE_QT_CONF
)
