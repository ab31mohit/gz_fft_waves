#include "gz_fft_waves/core/PhysicalConstants.hh"

namespace gz {
namespace waves {

//////////////////////////////////////////////////
// PhysicalConstants

double PhysicalConstants::Gravity() {
  // return -9.8;
  return -9.81;
}

double PhysicalConstants::G() {
  return 6.67408E-11;
}

double PhysicalConstants::WaterDensity() {
  // return 998.6;
  return 1025.0;
}

double PhysicalConstants::WaterKinematicViscosity() {
  return 1.0533E-6;
}

}  // namespace waves
}  // namespace gz