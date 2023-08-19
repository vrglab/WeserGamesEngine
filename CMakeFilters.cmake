set(PROJECT_NAME "WeserGamesEngine")
set(PROJECT_SRC_DIR "${CMAKE_SOURCE_DIR}/${PROJECT_NAME}")

#catagories
set(CAT_DISPLAY "Display Management")
set(CAT_EVENTSYS "Event System")
set(CAT_ENGTYPES "Types")
set(CAT_MEMMANG "Memory Management")
set(CAT_RENDFRAME "Redering Framework")

#Header or source
set(HEADER "Headers")
set(SOURCE "Sources")


#Source file filtering
file(GLOB REND_SOURCES "${PROJECT_SRC_DIR}/*Render*.cpp")
source_group("${SOURCE}/${CAT_RENDFRAME}" FILES ${REND_SOURCES})

file(GLOB REND_SOURCES "${PROJECT_SRC_DIR}/*Display*.cpp")
source_group("${SOURCE}/${CAT_RENDFRAME}" FILES ${REND_SOURCES})


#Header File filtering
file(GLOB REND_SOURCES "${PROJECT_SRC_DIR}/*Render*.h")
source_group("${HEADER}/${CAT_RENDFRAME}" FILES ${REND_SOURCES})

file(GLOB REND_SOURCES "${PROJECT_SRC_DIR}/*Display*.h")
source_group("${HEADER}/${CAT_RENDFRAME}" FILES ${REND_SOURCES})