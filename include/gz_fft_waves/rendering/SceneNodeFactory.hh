#ifndef GZ_RENDERING_SCENENODEFACTORY_HH_
#define GZ_RENDERING_SCENENODEFACTORY_HH_

#include "gz_fft_waves/rendering/DisplacementMap.hh"
#include "gz_fft_waves/rendering/OceanGeometry.hh"
#include "gz_fft_waves/rendering/OceanVisual.hh"

#include <memory>

#include <gz/rendering/config.hh>
#include <gz/rendering/Scene.hh>
#include "gz/rendering/Export.hh"

namespace gz {
namespace rendering {
inline namespace GZ_RENDERING_VERSION_NAMESPACE {

class GZ_RENDERING_VISIBLE SceneNodeFactory {
  /// \brief Destructor
  public: virtual ~SceneNodeFactory();

  /// \brief Create an ocean visual
  public: virtual OceanVisualPtr CreateOceanVisual(ScenePtr _scene) = 0;

  /// \brief Create an ocean geometry
  public: virtual OceanGeometryPtr CreateOceanGeometry(ScenePtr _scene) = 0;

  /// \brief Create a displacement map
  public: virtual DisplacementMapPtr CreateDisplacementMap(
      ScenePtr _scene,
      MaterialPtr _material,
      uint64_t _entity,
      uint32_t _width,
      uint32_t _height) = 0;
};

typedef std::shared_ptr<SceneNodeFactory> SceneNodeFactoryPtr;

}
}  // namespace rendering
}  // namespace gz

#endif  // GZ_RENDERING_SCENENODEFACTORY_HH_