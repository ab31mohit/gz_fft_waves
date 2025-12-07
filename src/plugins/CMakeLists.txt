# -------------------------------------------------------
# Adding wave plugins

# Waves Model plugin
gz_add_system(waves-model
  SOURCES
    WavesModel.cc
  PUBLIC_LINK_LIBS
    gz-common${GZ_COMMON_VER}::gz-common${GZ_COMMON_VER}
    gz-sim${GZ_SIM_VER}::gz-sim${GZ_SIM_VER}
)

# Waves Visual plugin
gz_add_system(waves-visual
  SOURCES
    WavesVisual.cc
  PUBLIC_LINK_LIBS
    ${rendering_target}
    gz-common${GZ_COMMON_VER}::gz-common${GZ_COMMON_VER}
    gz-sim${GZ_SIM_VER}::gz-sim${GZ_SIM_VER}
)

# --------------------------------------------------------