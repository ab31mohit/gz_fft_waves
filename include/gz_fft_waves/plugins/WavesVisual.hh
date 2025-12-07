#ifndef GZ_SIM_SYSTEMS_WAVESVISUAL_HH_
#define GZ_SIM_SYSTEMS_WAVESVISUAL_HH_

#include <memory>

#include <gz/sim/System.hh>

namespace gz {
namespace sim {
// Inline bracket to help doxygen filtering.
inline namespace GZ_SIM_VERSION_NAMESPACE {
namespace systems {
// Forward declaration
class WavesVisualPrivate;

/// \brief A plugin for surface waves
class WavesVisual
    : public System,
      public ISystemConfigure,
      public ISystemPreUpdate
{
  /// \brief Constructor
  public: WavesVisual();

  /// \brief Destructor
  public: ~WavesVisual() override;

  // Documentation inherited
  public: void Configure(const Entity &_entity,
                          const std::shared_ptr<const sdf::Element> &_sdf,
                          EntityComponentManager &_ecm,
                          EventManager &_eventMgr) final;

  /// Documentation inherited
  public: void PreUpdate(
              const UpdateInfo &_info,
              EntityComponentManager &_ecm) override;

  /// \brief Private data pointer
  private: std::unique_ptr<WavesVisualPrivate> dataPtr;
};

}  // namespace systems
}
}  // namespace sim
}  // namespace gz

#endif  // GZ_SIM_SYSTEMS_WAVESVISUAL_HH_
