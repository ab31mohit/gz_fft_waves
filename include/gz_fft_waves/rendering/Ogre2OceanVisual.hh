#ifndef GZ_RENDERING_OGRE2_OGRE2OCEANVISUAL_HH_
#define GZ_RENDERING_OGRE2_OGRE2OCEANVISUAL_HH_

#include "gz_fft_waves/rendering/BaseOceanVisual.hh"
#include "gz_fft_waves/core/OceanTile.hh"

#include <memory>
#include <string>

#include <gz/rendering/ogre2/Ogre2Visual.hh>

namespace gz {
namespace rendering {
inline namespace GZ_RENDERING_VERSION_NAMESPACE {

// Forward declaration
class Ogre2OceanVisualPrivate;

/// \brief Ogre2.x implementation of an ocean visual class
class GZ_RENDERING_OGRE2_VISIBLE Ogre2OceanVisual :
  public BaseOceanVisual<Ogre2Visual> {
  
  /// \brief Constructor
  public: Ogre2OceanVisual();

  /// \brief Destructor
  public: virtual ~Ogre2OceanVisual();

  // Documentation inherited.
  public: virtual void Init() override;

  // Documentation inherited.
  public: virtual void PreRender() override;

  // Documentation inherited.
  protected: virtual void Destroy() override;

  // Documentation inherited.
  public: virtual MaterialPtr Material() const override;

  // Documentation inherited.
  public: virtual void SetMaterial(
    MaterialPtr _material, bool _unique) override;

  /// \brief Load a dynamic cube (example)
  public: virtual void LoadCube() override;

  /// \brief Load from an ocean tile
  public: virtual void LoadOceanTile(
      waves::visual::OceanTilePtr _oceanTile) override;

  /// \brief Update from an ocean tile
  public: virtual void UpdateOceanTile(
      waves::visual::OceanTilePtr _oceanTile) override;

  /// \brief Load from a mesh
  public: virtual void LoadMesh(gz::common::MeshPtr _mesh) override;

  /// \brief Update from a mesh
  public: virtual void UpdateMesh(gz::common::MeshPtr _mesh) override;

  /// \brief Set material to geometry.
  /// \param[in] _material Ogre material.
  protected: virtual void SetMaterialImpl(Ogre2MaterialPtr _material);

  /// \brief Work-around the protected accessors and protected methods in Scene
  public: virtual void InitObject(ScenePtr _scene,
      unsigned int _id, const std::string &_name) override;

  private: friend class Ogre2Scene;

  /// \brief Private data class
  private: std::unique_ptr<Ogre2OceanVisualPrivate> dataPtr;
};

typedef std::shared_ptr<Ogre2OceanVisual> Ogre2OceanVisualPtr;

}
}  // namespace rendering
}  // namespace gz

#endif  // GZ_RENDERING_OGRE2_OGRE2OCEANVISUAL_HH_