# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(FATAL_ERROR "Could not find messages which '/home/jonah/cavs_ws/src/cavs_radar_example/msg/RadarDetection.msg' depends on. Did you forget to specify generate_messages(DEPENDENCIES ...)?
Cannot locate message [Point]: unknown package [geometry_msgs] on search path [{'cavs_radar_example': ['/home/jonah/cavs_ws/src/cavs_radar_example/msg'], 'std_msgs': ['/opt/ros/melodic/share/std_msgs/cmake/../msg']}]")
message(STATUS "cavs_radar_example: 1 messages, 0 services")

set(MSG_I_FLAGS "-Icavs_radar_example:/home/jonah/cavs_ws/src/cavs_radar_example/msg;-Istd_msgs:/opt/ros/melodic/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(cavs_radar_example_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages

### Generating Services

### Generating Module File
_generate_module_cpp(cavs_radar_example
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/cavs_radar_example
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(cavs_radar_example_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(cavs_radar_example_generate_messages cavs_radar_example_generate_messages_cpp)

# add dependencies to all check dependencies targets

# target for backward compatibility
add_custom_target(cavs_radar_example_gencpp)
add_dependencies(cavs_radar_example_gencpp cavs_radar_example_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS cavs_radar_example_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages

### Generating Services

### Generating Module File
_generate_module_eus(cavs_radar_example
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/cavs_radar_example
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(cavs_radar_example_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(cavs_radar_example_generate_messages cavs_radar_example_generate_messages_eus)

# add dependencies to all check dependencies targets

# target for backward compatibility
add_custom_target(cavs_radar_example_geneus)
add_dependencies(cavs_radar_example_geneus cavs_radar_example_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS cavs_radar_example_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages

### Generating Services

### Generating Module File
_generate_module_lisp(cavs_radar_example
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/cavs_radar_example
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(cavs_radar_example_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(cavs_radar_example_generate_messages cavs_radar_example_generate_messages_lisp)

# add dependencies to all check dependencies targets

# target for backward compatibility
add_custom_target(cavs_radar_example_genlisp)
add_dependencies(cavs_radar_example_genlisp cavs_radar_example_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS cavs_radar_example_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages

### Generating Services

### Generating Module File
_generate_module_nodejs(cavs_radar_example
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/cavs_radar_example
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(cavs_radar_example_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(cavs_radar_example_generate_messages cavs_radar_example_generate_messages_nodejs)

# add dependencies to all check dependencies targets

# target for backward compatibility
add_custom_target(cavs_radar_example_gennodejs)
add_dependencies(cavs_radar_example_gennodejs cavs_radar_example_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS cavs_radar_example_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages

### Generating Services

### Generating Module File
_generate_module_py(cavs_radar_example
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/cavs_radar_example
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(cavs_radar_example_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(cavs_radar_example_generate_messages cavs_radar_example_generate_messages_py)

# add dependencies to all check dependencies targets

# target for backward compatibility
add_custom_target(cavs_radar_example_genpy)
add_dependencies(cavs_radar_example_genpy cavs_radar_example_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS cavs_radar_example_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/cavs_radar_example)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/cavs_radar_example
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(cavs_radar_example_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/cavs_radar_example)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/cavs_radar_example
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(cavs_radar_example_generate_messages_eus std_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/cavs_radar_example)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/cavs_radar_example
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(cavs_radar_example_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/cavs_radar_example)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/cavs_radar_example
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(cavs_radar_example_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/cavs_radar_example)
  install(CODE "execute_process(COMMAND \"/usr/bin/python2\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/cavs_radar_example\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/cavs_radar_example
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(cavs_radar_example_generate_messages_py std_msgs_generate_messages_py)
endif()
