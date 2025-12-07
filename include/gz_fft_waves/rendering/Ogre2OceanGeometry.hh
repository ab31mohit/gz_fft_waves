#ifndef GZ_RENDERING_OGRE2_OGRE2OCEANGEOMETRY_HH_
#define GZ_RENDERING_OGRE2_OGRE2OCEANGEOMETRY_HH_

#include "gz_fft_waves/rendering/BaseOceanGeometry.hh"

#include <memory>
#include <string>

#include <gz/rendering/ogre2/Export.hh>
#include <gz/rendering/ogre2/Ogre2Geometry.hh>
#include <gz/rendering/RenderTypes.hh>

namespace Ogre {
class MovableObject;
}  // namespace Ogre

namespace gz {
namespace rendering {
inline namespace GZ_RENDERING_VERSION_NAMESPACE {

// Forward declarations
class Ogre2OceanGeometryPrivate;

/// \brief Ocean geometry class based on a dynamic mesh
class GZ_RENDERING_OGRE2_VISIBLE Ogre2OceanGeometry :
    public BaseOceanGeometry<Ogre2Geometry> {
  
  /// \brief Constructor
  public: explicit Ogre2OceanGeometry();

  /// \brief Destructor
  public: virtual ~Ogre2OceanGeometry();

  // Documentation inherited.
  public: virtual void Init() override;

  // Documentation inherited.
  public: virtual void Destroy() override;

  // Documentation inherited.
  public: virtual Ogre::MovableObject *OgreObject() const override;

  // Documentation inherited.
  public: virtual void PreRender() override;

  // Documentation inherited.
  public: virtual MaterialPtr Material() const override;

  // Documentation inherited.
  public: virtual void
    SetMaterial(MaterialPtr _material, bool _unique) override;

  /// \brief Load from a mesh
  public: virtual void LoadMesh(gz::common::MeshPtr _mesh) override;

  /// \brief Update from a mesh
  public: virtual void UpdateMesh(gz::common::MeshPtr _mesh) override;

  /// \brief Work-around the protected accessors and protected methods in Scene
  public: virtual void InitObject(ScenePtr _scene,
      unsigned int _id, const std::string &_name) override;

  /// \brief OceanGeometry should be created by scene.
  private: friend class Ogre2Scene;

  /// \brief Pointer to private data
  private: std::unique_ptr<Ogre2OceanGeometryPrivate> dataPtr;
};

typedef std::shared_ptr<Ogre2OceanGeometry> Ogre2OceanGeometryPtr;

}
}  // namespace rendering
}  // namespace gz

#endif  // GZ_RENDERING_OGRE2_OGRE2OCEANGEOMETRY_HH_