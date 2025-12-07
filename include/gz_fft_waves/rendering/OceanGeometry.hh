#ifndef GZ_RENDERING_OCEANGEOMETRY_HH_
#define GZ_RENDERING_OCEANGEOMETRY_HH_

#include <memory>
#include <string>

#include <gz/common/graphics/Types.hh>

#include <gz/rendering/config.hh>
#include <gz/rendering/Geometry.hh>
#include <gz/rendering/Object.hh>
#include <gz/rendering/RenderTypes.hh>

namespace gz {
namespace rendering {
inline namespace GZ_RENDERING_VERSION_NAMESPACE {

/// \brief Ocean geometry class based on a dynamic mesh
class GZ_RENDERING_VISIBLE OceanGeometry :
    public virtual Geometry {
  /// \brief Destructor
  public: virtual ~OceanGeometry();

  /// \brief Load from a mesh
  public: virtual void LoadMesh(gz::common::MeshPtr _mesh) = 0;

  /// \brief Update from a mesh
  public: virtual void UpdateMesh(gz::common::MeshPtr _mesh) = 0;

  /// \brief Work-around the protected accessors and methods in Scene
  public: virtual void InitObject(ScenePtr _scene,
      unsigned int _id, const std::string &_name) = 0;

};

typedef std::shared_ptr<OceanGeometry> OceanGeometryPtr;

}
}  // namespace rendering
}  // namespace gz

#endif  // GZ_RENDERING_OCEANGEOMETRY_HH_