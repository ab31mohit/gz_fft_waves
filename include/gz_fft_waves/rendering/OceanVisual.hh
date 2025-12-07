#ifndef GZ_RENDERING_OCEANVISUAL_HH_
#define GZ_RENDERING_OCEANVISUAL_HH_

#include "gz_fft_waves/core/OceanTile.hh"

#include <memory>
#include <string>

#include <gz/common/graphics/Types.hh>

#include <gz/rendering/config.hh>
#include <gz/rendering/Object.hh>
#include <gz/rendering/RenderTypes.hh>
#include <gz/rendering/Visual.hh>

namespace gz {
namespace rendering {
inline namespace GZ_RENDERING_VERSION_NAMESPACE {

/// \brief Ocean visual using a dynamic mesh
class GZ_RENDERING_VISIBLE OceanVisual :
  public virtual Visual {
  /// \brief Destructor
  public: virtual ~OceanVisual();

  /// \brief Load a dynamic cube (example)
  public: virtual void LoadCube() = 0;

  /// \brief Load from an ocean tile
  public: virtual void LoadOceanTile(
      waves::visual::OceanTilePtr _oceanTile) = 0;

  /// \brief Update from an ocean tile
  public: virtual void UpdateOceanTile(
      waves::visual::OceanTilePtr _oceanTile) = 0;

  /// \brief Load from a mesh
  public: virtual void LoadMesh(gz::common::MeshPtr _mesh) = 0;

  /// \brief Update from a mesh
  public: virtual void UpdateMesh(gz::common::MeshPtr _mesh) = 0;

  /// \brief Work-around the protected accessors and methods in Scene
  public: virtual void InitObject(ScenePtr _scene,
      unsigned int _id, const std::string &_name) = 0;

};

typedef std::shared_ptr<OceanVisual> OceanVisualPtr;

}
}  // namespace rendering
}  // namespace gz

#endif  // GZ_RENDERING_OCEANVISUAL_HH_