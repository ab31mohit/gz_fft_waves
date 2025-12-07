/// \file PhysicalConstants.hh
/// \brief This file contains definitions of some physical constants used
/// in the physics calculations.

#ifndef GZ_WAVES_PHYSICALCONSTANTS_HH_
#define GZ_WAVES_PHYSICALCONSTANTS_HH_

namespace gz {
namespace waves {

/// \brief A collection of static methods to retrieve physical constants.
class PhysicalConstants {
 public:
  /// \brief Uniform acceleration due to gravity at earth's surface
  ///        (orientation is z-up).
  ///
  /// \return     -9.8 [m s-2].
  static double Gravity();

  /// \brief Universal gravitational constant.
  ///
  /// \return     6.67408E-11 [m3 kg-1 s-2].
  static double G();

  /// \brief Density of water.
  ///
  /// \return     998.6 [kg m-3].
  static double WaterDensity();

  /// \brief Kinematic viscosity of water at 18 dgree C.
  ///
  /// Source:
  /// <https://www.engineeringtoolbox.com/water-dynamic-kinematic-viscosity-d_596.html>
  ///
  /// \return     1.0533E-6 [m2 s-1].
  static double WaterKinematicViscosity();
};

}  // namespace waves
}  // namespace gz

#endif  // GZ_WAVES_PHYSICALCONSTANTS_HH_
