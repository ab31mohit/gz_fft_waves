#include "gz_fft_waves/core/Convert.hh"
#include "gz_fft_waves/core/CGALTypes.hh"

#include <gz/math/Vector2.hh>
#include <gz/math/Vector3.hh>

namespace gz {
namespace waves {

//////////////////////////////////////////////////
// Conversions

gz::math::Vector3d ToGz(const cgal::Point3& _point)
{
  return gz::math::Vector3d(_point.x(), _point.y(), _point.z());
}

gz::math::Vector2d ToGz(const cgal::Vector2& _vector)
{
  return gz::math::Vector2d(_vector.x(), _vector.y());
}

gz::math::Vector3d ToGz(const cgal::Vector3& _vector)
{
  return gz::math::Vector3d(_vector.x(), _vector.y(), _vector.z());
}

cgal::Point3 ToPoint3(const gz::math::Vector3d& _vector)
{
  return cgal::Point3(_vector.X(), _vector.Y(), _vector.Z());
}

cgal::Vector2 ToVector2(const gz::math::Vector2d& _vector)
{
  return cgal::Vector2(_vector.X(), _vector.Y());
}

cgal::Vector3 ToVector3(const gz::math::Vector3d& _vector)
{
  return cgal::Vector3(_vector.X(), _vector.Y(), _vector.Z());
}

///////////////////////////////////////////////////////////////////////////////

}  // namespace waves
}  // namespace gz