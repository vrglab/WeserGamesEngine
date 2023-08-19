set(PROJECT_NAME "WeserGamesEngine")
set(PROJECT_SRC_DIR "${CMAKE_SOURCE_DIR}/${PROJECT_NAME}")

#catagories
set(CAT_DISPLAY "Display Management")
set(CAT_EVENTSYS "Event System")
set(CAT_ENGTYPES "Types")
set(CAT_MEMMANG "Memory Management")
set(CAT_RENDFRAME "Redering Framework")
set(CAT_DEBUGING "Debuging")
set(CAT_APP "Application")


#Header or source
set(HEADER "Header Files")
set(SOURCE "Source Files")


#Source file filtering

#Automated groups
file(GLOB REND_SOURCES "${PROJECT_SRC_DIR}/*Render*.cpp")
source_group("${SOURCE}/${CAT_RENDFRAME}" FILES ${REND_SOURCES})

file(GLOB DISPL_SOURCES "${PROJECT_SRC_DIR}/*Display*.cpp")
source_group("${SOURCE}/${CAT_DISPLAY}" FILES ${DISPL_SOURCES})

file(GLOB EVENT_SOURCES "${PROJECT_SRC_DIR}/*Event*.cpp")
source_group("${SOURCE}/${CAT_EVENTSYS}" FILES ${EVENT_SOURCES})

file(GLOB APP_SOURCES "${PROJECT_SRC_DIR}/*App*.cpp")
source_group("${SOURCE}/${CAT_APP}" FILES ${APP_SOURCES})

file(GLOB MEM_SOURCES "${PROJECT_SRC_DIR}/*Memory*.cpp")
source_group("${SOURCE}/${CAT_MEMMANG}" FILES ${MEM_SOURCES})

#Hand Writen
source_group("${SOURCE}/${CAT_DEBUGING}" FILES "${PROJECT_SRC_DIR}/Console.cpp")

#Header File filtering

#Automated groups
file(GLOB REND_HEADERS "${PROJECT_SRC_DIR}/*Render*.h")
source_group("${HEADER}/${CAT_RENDFRAME}" FILES ${REND_HEADERS})

file(GLOB DISPL_HEADERS "${PROJECT_SRC_DIR}/*Display*.h")
source_group("${HEADER}/${CAT_DISPLAY}" FILES ${DISPL_HEADERS})

file(GLOB EVENT_HEADERS "${PROJECT_SRC_DIR}/*Event*.h")
source_group("${HEADER}/${CAT_EVENTSYS}" FILES ${EVENT_HEADERS})

file(GLOB APP_HEADERS "${PROJECT_SRC_DIR}/*App*.h")
source_group("${HEADER}/${CAT_APP}" FILES ${APP_HEADERS})

file(GLOB MEM_HEADER "${PROJECT_SRC_DIR}/*Memory*.h")
source_group("${HEADER}/${CAT_MEMMANG}" FILES ${MEM_HEADER})

#Hand written
source_group("${HEADER}/${CAT_DEBUGING}" FILES "${PROJECT_SRC_DIR}/Console.h")


