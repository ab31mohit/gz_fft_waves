#ifndef GZ_RENDERING_BASE_BASEOCEANGEOMETRY_HH_
#define GZ_RENDERING_BASE_BASEOCEANGEOMETRY_HH_

#include "gz_fft_waves/rendering/OceanGeometry.hh"
#include <string>

namespace gz {
namespace rendering {
inline namespace GZ_RENDERING_VERSION_NAMESPACE {

/// \brief Base implementation of an Ocean geometry
template <class T>
class BaseOceanGeometry :
    public virtual OceanGeometry,
    public virtual T {

  /// \brief Constructor
  public: BaseOceanGeometry();

  /// \brief Destructor
  public: virtual ~BaseOceanGeometry();

  /// \brief Load from a mesh
  public: virtual void LoadMesh(gz::common::MeshPtr _mesh) override;

  /// \brief Update from a mesh
  public: virtual void UpdateMesh(gz::common::MeshPtr _mesh) override;

  /// \brief Work-around the protected accessors and methods in Scene
  public: virtual void InitObject(ScenePtr _scene,
      unsigned int _id, const std::string &_name) override;
};

/////////////////////////////////////////////////
// BaseOceanGeometry
/////////////////////////////////////////////////
template <class T>
BaseOceanGeometry<T>::BaseOceanGeometry() {
}

/////////////////////////////////////////////////
template <class T>
BaseOceanGeometry<T>::~BaseOceanGeometry() {
}

/////////////////////////////////////////////////
template <class T>
void BaseOceanGeometry<T>::LoadMesh(gz::common::MeshPtr /*_mesh*/) {
  // no default implementation
}

/////////////////////////////////////////////////
template <class T>
void BaseOceanGeometry<T>::UpdateMesh(gz::common::MeshPtr /*_mesh*/) {
  // no default implementation
}

/////////////////////////////////////////////////
template <class T>
void BaseOceanGeometry<T>::InitObject(ScenePtr /*_scene*/,
    unsigned int /*_id*/, const std::string &/*_name*/) {
  // no default implementation
}

}
}  // namespace rendering
}  // namespace gz

#endif  // GZ_RENDERING_BASE_BASEOCEANGEOMETRY_HH_