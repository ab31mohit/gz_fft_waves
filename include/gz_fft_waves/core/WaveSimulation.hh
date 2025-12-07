#ifndef GZ_WAVES_WAVESIMULATION_HH_
#define GZ_WAVES_WAVESIMULATION_HH_

#include "gz_fft_waves/core/Types.hh"

#include <Eigen/Dense>

#include <memory>

namespace gz {
namespace waves {
// evaluate wave elevation and fluid pressure
class IWaveField {
 public:
  virtual ~IWaveField();

  virtual void Elevation(
      double x, double y,
      double& eta) const = 0;

  virtual void Elevation(
      const Eigen::Ref<const Eigen::ArrayXd>& x,
      const Eigen::Ref<const Eigen::ArrayXd>& y,
      Eigen::Ref<Eigen::ArrayXd> eta) const = 0;

  virtual void Pressure(
      double x, double y, double z,
      double& pressure) const = 0;

  virtual void Pressure(
      const Eigen::Ref<const Eigen::ArrayXd>& x,
      const Eigen::Ref<const Eigen::ArrayXd>& y,
      const Eigen::Ref<const Eigen::ArrayXd>& z,
      Eigen::Ref<Eigen::ArrayXd> pressure) const = 0;
};

// compute a wave field on a discrete grid
class IWaveSimulation {
 public:
  virtual ~IWaveSimulation();

  virtual Index SizeX() const = 0;

  virtual Index SizeY() const = 0;

  virtual Index SizeZ() const = 0;

  /// \todo(srmainwaring) deprecate or move?
  virtual void SetWindVelocity(double ux, double uy) = 0;

  /// \todo(srmainwaring) deprecate or move?
  virtual void SetSteepness(double value) = 0;

  /// \todo(srmainwaring) deprecate or move?
  virtual void SetTime(double value) = 0;

  // lookup interface - scalar
  virtual void ElevationAt(
      Index ix, Index iy,
      double& eta) const = 0;

  virtual void DisplacementAt(
      Index ix, Index iy,
      double& sx, double& sy) const = 0;

  virtual void PressureAt(
      Index ix, Index iy, Index iz,
      double& pressure) const = 0;

  // lookup interface - array
  virtual void ElevationAt(
      Eigen::Ref<Eigen::ArrayXXd> h) const = 0;

  virtual void ElevationDerivAt(
      Eigen::Ref<Eigen::ArrayXXd> dhdx,
      Eigen::Ref<Eigen::ArrayXXd> dhdy) const = 0;

  virtual void DisplacementAt(
      Eigen::Ref<Eigen::ArrayXXd> sx,
      Eigen::Ref<Eigen::ArrayXXd> sy) const = 0;

  virtual void DisplacementDerivAt(
      Eigen::Ref<Eigen::ArrayXXd> dsxdx,
      Eigen::Ref<Eigen::ArrayXXd> dsydy,
      Eigen::Ref<Eigen::ArrayXXd> dsxdy) const = 0;

  virtual void DisplacementAndDerivAt(
      Eigen::Ref<Eigen::ArrayXXd> h,
      Eigen::Ref<Eigen::ArrayXXd> sx,
      Eigen::Ref<Eigen::ArrayXXd> sy,
      Eigen::Ref<Eigen::ArrayXXd> dhdx,
      Eigen::Ref<Eigen::ArrayXXd> dhdy,
      Eigen::Ref<Eigen::ArrayXXd> dsxdx,
      Eigen::Ref<Eigen::ArrayXXd> dsydy,
      Eigen::Ref<Eigen::ArrayXXd> dsxdy) const = 0;

  virtual void PressureAt(
      Index iz,
      Eigen::Ref<Eigen::ArrayXXd> pressure) const = 0;
};

}  // namespace waves
}  // namespace gz

#endif  // GZ_WAVES_WAVESIMULATION_HH_
