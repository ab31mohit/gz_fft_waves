#ifndef GZ_RENDERING_OGRE2_RENDERENGINEEXTENSION_HH_
#define GZ_RENDERING_OGRE2_RENDERENGINEEXTENSION_HH_

#include "gz_fft_waves/rendering/BaseRenderEngineExtension.hh"
#include "gz_fft_waves/rendering/RenderEngineExtensionPlugin.hh"
#include "gz_fft_waves/rendering/RenderEngineExtension.hh"

#include <map>
#include <memory>
#include <string>

#include <gz/common/SingletonT.hh>

#include <gz/rendering/config.hh>
#include <gz/rendering/Export.hh>

#include "gz/rendering/ogre2/Ogre2RenderTypes.hh"
#include <gz/rendering/ogre2/Export.hh>

namespace gz {
namespace rendering {
inline namespace GZ_RENDERING_VERSION_NAMESPACE {

// Forward declaration
class  Ogre2RenderEngineExtensionPrivate;

class GZ_RENDERING_OGRE2_VISIBLE Ogre2RenderEngineExtensionPlugin :
  public RenderEngineExtensionPlugin {
  
  public: Ogre2RenderEngineExtensionPlugin();

  public: ~Ogre2RenderEngineExtensionPlugin();

  public: std::string Name() const;

  public: RenderEngineExtension *Extension() const;
};

class GZ_RENDERING_OGRE2_VISIBLE Ogre2RenderEngineExtension :
    public virtual BaseRenderEngineExtension,
    public common::SingletonT<Ogre2RenderEngineExtension> {
  
  private: Ogre2RenderEngineExtension();

  public: virtual ~Ogre2RenderEngineExtension();

  public: virtual void Destroy() override;

  public: virtual std::string Name() const override;

  public: virtual SceneNodeFactoryPtr SceneNodeFactory() const override;

  protected: virtual bool LoadImpl(
      const std::map<std::string, std::string> &_params) override;

  protected: virtual bool InitImpl() override;

  private: void LoadAttempt();

  private: void InitAttempt();

  /// \brief Pointer to private data
  private: std::unique_ptr<Ogre2RenderEngineExtensionPrivate> dataPtr;

  /// \brief Singleton setup
  private: friend class common::SingletonT<Ogre2RenderEngineExtension>;
};

}
}  // namespace rendering
}  // namespace gz

#endif  // GZ_RENDERING_OGRE2_RENDERENGINEEXTENSION_HH_