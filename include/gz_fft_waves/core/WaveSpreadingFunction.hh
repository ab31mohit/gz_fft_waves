#ifndef GZ_WAVES_WAVESPREADINGFUNCTION_HH_
#define GZ_WAVES_WAVESPREADINGFUNCTION_HH_

#include <Eigen/Dense>

namespace gz {
namespace waves {

class DirectionalSpreadingFunction {
 public:
  virtual ~DirectionalSpreadingFunction();

  virtual double Evaluate(
      double theta, double theta_mean, double k = 1.0) const = 0;

  virtual void Evaluate(
      Eigen::Ref<Eigen::ArrayXXd> phi,
      const Eigen::Ref<const Eigen::ArrayXXd>& theta,
      double theta_mean,
      const Eigen::Ref<const Eigen::ArrayXXd>& k = Eigen::ArrayXXd())
      const = 0;
};

class Cos2sSpreadingFunction : public DirectionalSpreadingFunction {
 public:
  virtual ~Cos2sSpreadingFunction();

  explicit Cos2sSpreadingFunction(double spread = 10.0);

  double Evaluate(
      double theta, double theta_mean, double k = 1.0) const override;

  void Evaluate(
      Eigen::Ref<Eigen::ArrayXXd> phi,
      const Eigen::Ref<const Eigen::ArrayXXd>& theta,
      double theta_mean,
      const Eigen::Ref<const Eigen::ArrayXXd>& k = Eigen::ArrayXXd())
      const override;

  double Spread() const;

  void SetSpread(double value);

 private:
  void RecalcCoeffs();

  double spread_{10.0};
  double cap_c_s_{0.0};
};

class ECKVSpreadingFunction : public DirectionalSpreadingFunction {
 public:
  virtual ~ECKVSpreadingFunction();

  explicit ECKVSpreadingFunction(
      double u10 = 5.0,
      double cap_omega_c = 0.84,
      double gravity = 9.81);

  double Evaluate(
      double theta, double theta_mean, double k = 1.0) const override;

  void Evaluate(
      Eigen::Ref<Eigen::ArrayXXd> phi,
      const Eigen::Ref<const Eigen::ArrayXXd>& theta,
      double theta_mean,
      const Eigen::Ref<const Eigen::ArrayXXd>& k = Eigen::ArrayXXd())
      const override;

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

#endif  // GZ_WAVES_WAVESPREADINGFUNCTION_HH_
