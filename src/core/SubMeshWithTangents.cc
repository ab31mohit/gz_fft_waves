#include "gz_fft_waves/core/SubMeshWithTangents.hh"

#include <string>
#include <vector>

#include <gz/common/Console.hh>

namespace gz {
namespace common {

/// \brief Private data for SubMeshWithTangents
class gz::common::SubMeshWithTangents::Implementation {
 public:
  /// \brief the tangents array
  std::vector<gz::math::Vector3d> tangents;
};

//////////////////////////////////////////////////
SubMeshWithTangents::SubMeshWithTangents()
    : SubMesh(),
    dataPtr(gz::utils::MakeImpl<Implementation>()) {
}

//////////////////////////////////////////////////
SubMeshWithTangents::SubMeshWithTangents(const std::string& _name)
    : SubMesh(_name),
    dataPtr(gz::utils::MakeImpl<Implementation>()) {
}

//////////////////////////////////////////////////
SubMeshWithTangents::SubMeshWithTangents(const SubMeshWithTangents& _submesh)
  : SubMesh(_submesh),
  dataPtr(gz::utils::MakeImpl<Implementation>()) {
  // copy this
  *this->dataPtr = (*_submesh.dataPtr);
}

//////////////////////////////////////////////////
SubMeshWithTangents::SubMeshWithTangents(SubMeshWithTangents&& _submesh)
    noexcept = default;

//////////////////////////////////////////////////
SubMeshWithTangents& SubMeshWithTangents::operator=(
    const SubMeshWithTangents& _submesh) {
  if (this != &_submesh) {
    // copy base
    (common::SubMesh&)(*this) = _submesh;

    // copy this
    *this->dataPtr = (*_submesh.dataPtr);
  }

  return *this;
}

//////////////////////////////////////////////////
SubMeshWithTangents& SubMeshWithTangents::operator=(
    SubMeshWithTangents&& _submesh)
    noexcept = default;

//////////////////////////////////////////////////
SubMeshWithTangents::~SubMeshWithTangents() {
}

//////////////////////////////////////////////////
void SubMeshWithTangents::AddTangent(const gz::math::Vector3d& _tanget) {
  this->dataPtr->tangents.push_back(_tanget);
}

//////////////////////////////////////////////////
void SubMeshWithTangents::AddTangent(
    const double _x, const double _y, const double _z) {
  this->AddTangent(gz::math::Vector3d(_x, _y, _z));
}

//////////////////////////////////////////////////
gz::math::Vector3d SubMeshWithTangents::Tangent(
    const unsigned int _index) const {
  if (_index >= this->dataPtr->tangents.size()) {
    gzerr << "Index too large" << std::endl;
    return math::Vector3d::Zero;
  }

  return this->dataPtr->tangents[_index];
}

//////////////////////////////////////////////////
bool SubMeshWithTangents::HasTangent(const unsigned int _index) const {
  return _index < this->dataPtr->tangents.size();
}

//////////////////////////////////////////////////
void SubMeshWithTangents::SetTangent(const unsigned int _index,
    const gz::math::Vector3d& _n) {
  if (_index >= this->dataPtr->tangents.size()) {
    gzerr << "Index too large" << std::endl;
    return;
  }

  this->dataPtr->tangents[_index] = _n;
}

//////////////////////////////////////////////////
unsigned int SubMeshWithTangents::TangentCount() const {
  return this->dataPtr->tangents.size();
}

}  // namespace common
}  // namespace gz