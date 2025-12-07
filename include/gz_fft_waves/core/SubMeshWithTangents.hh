#ifndef GZ_COMMON_SUBMESHWITHTANGENTS_HH_
#define GZ_COMMON_SUBMESHWITHTANGENTS_HH_

#include <memory>
#include <string>
#include <vector>

#include <gz/common/SubMesh.hh>
#include <gz/math/Vector3.hh>
#include <gz/utils/ImplPtr.hh>

namespace gz {
namespace common {
/// \brief A child mesh
class GZ_COMMON_GRAPHICS_VISIBLE SubMeshWithTangents : public SubMesh {
  /// \brief Constructor
  public: SubMeshWithTangents();

  /// \brief Constructor
  /// \param _name Name of the submesh.
  public: explicit SubMeshWithTangents(const std::string &_name);

  /// \brief Copy constructor
  /// \param[in] _submesh SubMeshWithTangents to copy.
  public: SubMeshWithTangents(const SubMeshWithTangents &_submesh);

  /// \brief Move constructor
  /// \param[in] _collision SubMeshWithTangents to move.
  public: SubMeshWithTangents(SubMeshWithTangents &&_submesh) noexcept;

  /// \brief Copy assignment operator.
  /// \param[in] _submesh SubMeshWithTangents to copy.
  /// \return Reference to this.
  public: SubMeshWithTangents &operator=(const SubMeshWithTangents &_submesh);

  /// \brief Move assignment operator.
  /// \param[in] _collision Collision component to move.
  /// \return Reference to this.
  public: SubMeshWithTangents &operator=(
      SubMeshWithTangents &&_submesh) noexcept;

  /// \brief Destructor
  public: virtual ~SubMeshWithTangents();

  /// \brief Add a tangent to the mesh
  /// \param[in] _n The tangent
  public: void AddTangent(const gz::math::Vector3d &_tangent);

  /// \brief Add a tangent to the mesh
  /// \param[in] _x Position along x
  /// \param[in] _y Position along y
  /// \param[in] _z Position along z
  public: void AddTangent(const double _x, const double _y, const double _z);

  /// \brief Get a tangent
  /// \param[in] _index The tangent index
  /// \return The tangent direction or gz::math::Vector3d::Zero
  ///  if index is out of bounds.
  /// \sa bool HasTangent(const unsigned int _index);
  public: gz::math::Vector3d Tangent(const unsigned int _index) const;

  /// \brief Set a tangent
  /// \param[in] _index Index of the tangent that will be set.
  /// \param[in] _n The new tangent direction
  public: void SetTangent(const unsigned int _index,
      const gz::math::Vector3d &_tangent);

  /// \brief Return the number of tangents
  /// \return The number of tangents.
  public: unsigned int TangentCount() const;

  /// \brief Return true if this submesh has the tangent with the given
  /// index
  /// \param[in] _index Tangent index
  /// \return Return true if this submesh has the tangent with the given
  /// _index.
  public: bool HasTangent(const unsigned int _index) const;

  /// \brief Recalculate all the tangents.
  public: void RecalculateTangents();

  /// \brief Private data pointer.
  GZ_UTILS_IMPL_PTR(dataPtr)
};

}  // namespace common
}  // namespace gz

#endif  // GZ_COMMON_SUBMESHWITHTANGENTS_HH_
