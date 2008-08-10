SET( EXTENSION_NAME "Extensions_RAWResource")

ADD_LIBRARY( ${EXTENSION_NAME}
  Resources/RAWResource.cpp
)

TARGET_LINK_LIBRARIES( ${EXTENSION_NAME}
  OpenEngine_Core
)
