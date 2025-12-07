#ifndef GZ_RENDERING_DISPLACEMENTMAP_HH_
#define GZ_RENDERING_DISPLACEMENTMAP_HH_

#include <Eigen/Dense>

#include <memory>

#include <gz/rendering/config.hh>
#include <gz/rendering/Export.hh>

namespace gz {
namespace rendering {
inline namespace GZ_RENDERING_VERSION_NAMESPACE {

class GZ_RENDERING_VISIBLE DisplacementMap {
  public: virtual ~DisplacementMap();

  public: virtual void InitTextures() = 0;

  public: virtual void UpdateTextures(
    const Eigen::Ref<const Eigen::ArrayXXd> &mHeights,
    const Eigen::Ref<const Eigen::ArrayXXd> &mDhdx,
    const Eigen::Ref<const Eigen::ArrayXXd> &mDhdy,
    const Eigen::Ref<const Eigen::ArrayXXd> &mDisplacementsX,
    const Eigen::Ref<const Eigen::ArrayXXd> &mDisplacementsY,
    const Eigen::Ref<const Eigen::ArrayXXd> &mDxdx,
    const Eigen::Ref<const Eigen::ArrayXXd> &mDydy,
    const Eigen::Ref<const Eigen::ArrayXXd> &mDxdy) = 0;
};

typedef std::shared_ptr<DisplacementMap> DisplacementMapPtr;

}
}  // namespace rendering
}  // namespace gz

#endif  // GZ_RENDERING_DISPLACEMENTMAP_HH_
