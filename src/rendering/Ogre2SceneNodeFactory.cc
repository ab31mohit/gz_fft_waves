#include "gz_fft_waves/rendering/Ogre2SceneNodeFactory.hh"
#include "gz_fft_waves/rendering/Ogre2DisplacementMap.hh"
#include "gz_fft_waves/rendering/Ogre2OceanGeometry.hh"
#include "gz_fft_waves/rendering/Ogre2OceanVisual.hh"
#include "gz_fft_waves/rendering/DisplacementMap.hh"
#include "gz_fft_waves/rendering/OceanGeometry.hh"
#include "gz_fft_waves/rendering/OceanVisual.hh"

#include <memory>
#include <string>

namespace gz {
namespace rendering {
inline namespace GZ_RENDERING_VERSION_NAMESPACE {

//////////////////////////////////////////////////
Ogre2SceneNodeFactory::Ogre2SceneNodeFactory()
{
}

//////////////////////////////////////////////////
Ogre2SceneNodeFactory::~Ogre2SceneNodeFactory()
{
}

//////////////////////////////////////////////////
OceanVisualPtr Ogre2SceneNodeFactory::CreateOceanVisual(ScenePtr _scene)
{
  // create name and increment the object id
  std::stringstream ss;
  ss << "OceanVisual(" << objId++ << ")";
  std::string objName = ss.str();

  // create visual
  rendering::OceanVisualPtr visual =
      std::make_shared<rendering::Ogre2OceanVisual>();
  visual->InitObject(_scene, objId, objName);

  return visual;
}

//////////////////////////////////////////////////
OceanGeometryPtr Ogre2SceneNodeFactory::CreateOceanGeometry(ScenePtr _scene)
{
  // create name and increment the object id
  std::stringstream ss;
  ss << "OceanGeometry(" << objId++ << ")";
  std::string objName = ss.str();

  // create geometry
  rendering::OceanGeometryPtr geometry =
      std::make_shared<rendering::Ogre2OceanGeometry>();
  geometry->InitObject(_scene, objId, objName);

  return geometry;
}

//////////////////////////////////////////////////
DisplacementMapPtr Ogre2SceneNodeFactory::CreateDisplacementMap(
    ScenePtr _scene,
    MaterialPtr _material,
    uint64_t _entity,
    uint32_t _width,
    uint32_t _height)
{
  rendering::DisplacementMapPtr displacementMap =
      std::make_shared<rendering::Ogre2DisplacementMap>(
          _scene, _material, _entity, _width, _height);

  return displacementMap;
}

}
}  // namespace rendering
}  // namespace gz