/// \file Wavefield.hh
/// \brief A class to interact with a wave field.

#ifndef GZ_WAVES_WAVEFIELD_HH_
#define GZ_WAVES_WAVEFIELD_HH_

#include <Eigen/Dense>

#include <memory>
#include <string>

namespace gz {
namespace waves {
class WaveParameters;
class WavefieldPrivate;

/// \brief A class to manage a wave field.
class Wavefield {
 public:
  /// \brief Destructor.
  virtual ~Wavefield();

  /// \brief Constructor.
  explicit Wavefield(const std::string& world_name);

  /// \brief Compute the height at a point (vertical distance to surface).
  bool Height(const Eigen::Vector3d& point, double& height) const;

  /// \brief Get the wave parameters.
  std::shared_ptr<const WaveParameters> GetParameters() const;

  /// \brief Set the wave parameters.
  ///
  /// \param[in] params    The new wave parameters.
  void SetParameters(std::shared_ptr<WaveParameters> params);

  /// \brief Update (recalculate) the wave field for the given time.
  ///
  /// \param[in] time    The time parameter for the wave evolution.
  void Update(double time);

 private:
  /// \internal Private implementation.
  std::shared_ptr<WavefieldPrivate> impl_;
};

typedef std::shared_ptr<Wavefield> WavefieldPtr;
typedef std::shared_ptr<const Wavefield> WavefieldConstPtr;
typedef std::weak_ptr<Wavefield> WavefieldWeakPtr;
typedef std::weak_ptr<const Wavefield> WavefieldConstWeakPtr;

}  // namespace waves
}  // namespace gz

#endif  // GZ_WAVES_WAVEFIELD_HH_
