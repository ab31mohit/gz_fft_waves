#-----------------------------------------------------------------------------------
# custom function to simplify linking & building plugins
function(gz_add_system system_name)
  set(options)
  set(oneValueArgs)
  set(multiValueArgs SOURCES PUBLIC_LINK_LIBS PRIVATE_LINK_LIBS PRIVATE_COMPILE_DEFS)

  cmake_parse_arguments(gz_add_system "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

  if(gz_add_system_SOURCES)
    set(sources ${gz_add_system_SOURCES})
  else()
    message(FATAL_ERROR "You must specify SOURCES for gz_add_system(~)!")
  endif()

  set(system_name ${system_name}-system)

  if(MSVC)
    # Warning #4251 is the "dll-interface" warning that tells you when types
    # used by a class are not being exported. These generated source files have
    # private members that don't get exported, so they trigger this warning.
    # However, the warning is not important since those members do not need to
    # be interfaced with.
    set_source_files_properties(${sources} COMPILE_FLAGS "/wd4251")
  endif()

  gz_add_component(${system_name}
    SOURCES ${sources}
    GET_TARGET_NAME system_target
    INDEPENDENT_FROM_PROJECT_LIB TRUE
    CXX_STANDARD 17)

  target_link_libraries(${system_target}
    PUBLIC
      ${gz_add_system_PUBLIC_LINK_LIBS}
      ${PROJECT_LIBRARY_TARGET_NAME}
    PRIVATE
      ${gz_add_system_PRIVATE_LINK_LIBS}
      gz-plugin${GZ_PLUGIN_VER}::register
  )

  if(gz_add_system_PRIVATE_COMPILE_DEFS)
    target_compile_definitions(${system_target}
      PRIVATE
        ${gz_add_system_PRIVATE_COMPILE_DEFS}
    )
  endif()

endfunction()
# ----------------------------------------------------------------------------------------------


#
set(sources
  core/Algorithm.cc
  core/Convert.cc
  core/Geometry.cc
  core/Grid.cc
  core/OceanTile.cc
  core/PhysicalConstants.cc
  core/Physics.cc
  core/SubMeshWithTangents.cc
  core/TriangulatedGrid.cc
  core/Utilities.cc
  core/Wavefield.cc
  core/WavefieldSampler.cc
  core/WaveParameters.cc
  core/WaveSimulation.cc
  core/LinearRandomFFTWaveSimulation.cc
  core/LinearRandomWaveSimulation.cc
  core/LinearRegularWaveSimulation.cc
  core/TrochoidIrregularWaveSimulation.cc
  core/WaveSpectrum.cc
  core/WaveSpreadingFunction.cc
)

# Create the library target
gz_create_core_library(SOURCES ${sources} CXX_STANDARD ${CMAKE_CXX_STANDARD})

target_link_libraries(${PROJECT_LIBRARY_TARGET_NAME}
  PUBLIC
  gz-math${GZ_MATH_VER}
  gz-msgs${GZ_MSGS_VER}::gz-msgs${GZ_MSGS_VER}
  gz-common${GZ_COMMON_VER}::gz-common${GZ_COMMON_VER}
  gz-common${GZ_COMMON_VER}::graphics
  gz-common${GZ_COMMON_VER}::profiler
  gz-transport${GZ_TRANSPORT_VER}::gz-transport${GZ_TRANSPORT_VER}
  sdformat${SDF_VER}::sdformat${SDF_VER}
  ${FFT_LIBRARIES}
)
if (${CGAL_VERSION_MAJOR} GREATER_EQUAL 6)
  target_link_libraries(${PROJECT_LIBRARY_TARGET_NAME}
    PUBLIC
    CGAL::CGAL
  )
endif()
if (UNIX AND NOT APPLE)
  target_link_libraries(${PROJECT_LIBRARY_TARGET_NAME}
    PRIVATE stdc++fs)
endif()

target_include_directories(${PROJECT_LIBRARY_TARGET_NAME}
  PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
  ${EIGEN3_INCLUDE_DIR}
)

# -------------------------------------------------------------------
# Rendering components
set(GZ-RENDERING_LIBRARY_DIRS
  ${GZ-RENDERING_INCLUDE_DIRS}/../../../lib/gz-rendering-${GZ_RENDERING_VER}/engine-plugins)

link_directories(${GZ-RENDERING_LIBRARY_DIRS})

# core rendering components
gz_add_component(rendering
  SOURCES
    rendering/BaseRenderEngineExtension.cc
    rendering/DisplacementMap.cc
    rendering/OceanGeometry.cc
    rendering/OceanVisual.cc
    rendering/RenderEngineExtension.cc
    rendering/RenderEngineExtensionManager.cc
    rendering/RenderEngineExtensionPlugin.cc
    rendering/SceneNodeFactory.cc
  GET_TARGET_NAME
    rendering_target
)

set_property(
  SOURCE rendering/RenderEngineExtensionManager.cc
  PROPERTY COMPILE_DEFINITIONS
  GZ_RENDERING_PLUGIN_PATH="${GZ_RENDERING_PLUGIN_PATH}"
)

target_link_libraries(${rendering_target}
  PUBLIC
    gz-common${GZ_COMMON_VER}::gz-common${GZ_COMMON_VER}
    gz-rendering${GZ_RENDERING_VER}::gz-rendering${GZ_RENDERING_VER}
  PRIVATE
    gz-plugin${GZ_PLUGIN_VER}::loader  
)

# ogre2 specific components
gz_add_component(rendering-ogre2
  SOURCES
    rendering/Ogre2DisplacementMap.cc
    rendering/Ogre2DynamicMesh.cc
    rendering/Ogre2OceanGeometry.cc
    rendering/Ogre2OceanVisual.cc
    rendering/Ogre2RenderEngineExtension.cc
    rendering/Ogre2SceneNodeFactory.cc
  GET_TARGET_NAME
    rendering_ogre2_target
  DEPENDS_ON_COMPONENTS
    ${rendering_target}
)

target_link_directories(${rendering_ogre2_target}
  PUBLIC
    ${GZ-RENDERING_LIBRARY_DIRS}
)

target_link_libraries(${rendering_ogre2_target}
  PUBLIC
    ${rendering_target}
    gz-common${GZ_COMMON_VER}::gz-common${GZ_COMMON_VER}
    gz-rendering${GZ_RENDERING_VER}::gz-rendering${GZ_RENDERING_VER}
    gz-rendering${GZ_RENDERING_VER}-ogre2
    GzOGRE2::GzOGRE2
  PRIVATE
    gz-plugin${GZ_PLUGIN_VER}::register
)
# Suppress an Ogre warning about adding _DEBUG to precompiler definitions.
# TODO: set conditional on the cmake build type. 
target_compile_definitions(${rendering_ogre2_target}
  PUBLIC
    OGRE_IGNORE_UNKNOWN_DEBUG
)
# ------------------------------------------------------------------------------------

# --------------------------------------
# adding plugins/ to cmake build system
add_subdirectory(plugins)