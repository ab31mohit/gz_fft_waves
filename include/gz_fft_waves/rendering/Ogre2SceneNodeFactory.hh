#ifndef GZ_RENDERING_OGRE2_SCENENODEFACTORY_HH_
#define GZ_RENDERING_OGRE2_SCENENODEFACTORY_HH_

#include "gz_fft_waves/rendering/SceneNodeFactory.hh"

#include <gz/rendering/config.hh>
#include <gz/rendering/Scene.hh>
#include "gz/rendering/Export.hh"

#include <gz/rendering/ogre2/Export.hh>

namespace gz {
namespace rendering {
inline namespace GZ_RENDERING_VERSION_NAMESPACE {

class GZ_RENDERING_OGRE2_VISIBLE Ogre2SceneNodeFactory :
    public SceneNodeFactory {
  
  /// \brief Constructor
  public: Ogre2SceneNodeFactory();

  /// \brief Destructor
  public: virtual ~Ogre2SceneNodeFactory();

  /// \brief Create an ocean visual
  public: virtual OceanVisualPtr CreateOceanVisual(
      ScenePtr _scene) override;

  /// \brief Create an ocean geometry
  public: virtual OceanGeometryPtr CreateOceanGeometry(
      ScenePtr _scene) override;

  /// \brief Create a displacement map
  public: virtual DisplacementMapPtr CreateDisplacementMap(
      ScenePtr _scene,
      MaterialPtr _material,
      uint64_t _entity,
      uint32_t _width,
      uint32_t _height) override;

  private: unsigned int objId{50000};
};

}
}  // namespace rendering
}  // namespace gz

#endif  // GZ_RENDERING_OGRE2_SCENENODEFACTORY_HH_