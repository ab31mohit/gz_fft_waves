#ifndef GZ_WAVES_WAVESPECTRUM_HH_
#define GZ_WAVES_WAVESPECTRUM_HH_

#include <Eigen/Dense>

namespace gz {
namespace waves {

class OmniDirectionalWaveSpectrum {
 public:
  virtual ~OmniDirectionalWaveSpectrum();

  virtual double Evaluate(double k) const = 0;

  virtual void Evaluate(
      Eigen::Ref<Eigen::ArrayXXd> spectrum,
      const Eigen::Ref<const Eigen::ArrayXXd>& k) const = 0;
};

class PiersonMoskowitzWaveSpectrum : public OmniDirectionalWaveSpectrum {
 public:
  virtual ~PiersonMoskowitzWaveSpectrum();

  explicit PiersonMoskowitzWaveSpectrum(
      double u19 = 5.0,
      double gravity = 9.81);

  double Evaluate(double k) const override;

  void Evaluate(
      Eigen::Ref<Eigen::ArrayXXd> spectrum,
      const Eigen::Ref<const Eigen::ArrayXXd>& k) const override;

  double Gravity() const;

  void SetGravity(double value);

  double U19() const;

  void SetU19(double value);

 private:
  double gravity_{9.81};
  double u19_{5.0};
};

class ECKVWaveSpectrum : public OmniDirectionalWaveSpectrum {
 public:
  virtual ~ECKVWaveSpectrum();

  explicit ECKVWaveSpectrum(
      double u10 = 5.0,
      double cap_omega_c = 0.84,
      double gravity = 9.81);

  double Evaluate(double k) const override;

  void Evaluate(
      Eigen::Ref<Eigen::ArrayXXd> spectrum,
      const Eigen::Ref<const Eigen::ArrayXXd>& k) const override;

  double Gravity() const;

  void SetGravity(double value);

  double U10() const;

  void SetU10(double value);

  double CapOmegaC() const;

  void SetCapOmegaC(double value);

 private:
  double gravity_{9.81};
  double u10_{5.0};
  double cap_omega_c_{0.84};
};

}  // namespace waves
}  // namespace gz

#endif  // GZ_WAVES_WAVESPECTRUM_HH_