#ifndef GZ_RENDERING_BASE_RENDERENGINEEXTENSION_HH_
#define GZ_RENDERING_BASE_RENDERENGINEEXTENSION_HH_

#include "gz_fft_waves/rendering/RenderEngineExtension.hh"

#include <map>
#include <string>

#include <gz/rendering/config.hh>
#include <gz/rendering/GraphicsAPI.hh>
#include <gz/rendering/RenderTypes.hh>
#include <gz/rendering/Export.hh>

namespace gz {
namespace rendering {
inline namespace GZ_RENDERING_VERSION_NAMESPACE {

class GZ_RENDERING_VISIBLE BaseRenderEngineExtension :
    public virtual RenderEngineExtension {
  
  protected: BaseRenderEngineExtension();

  public: virtual ~BaseRenderEngineExtension();

  public: virtual bool Load(
      const std::map<std::string, std::string> &_params = {}) override;

  public: virtual bool Init() override;

  public: virtual void Destroy() override;

  public: virtual bool IsInitialized() const override;

  protected: virtual bool LoadImpl(
      const std::map<std::string, std::string> &_params) = 0;

  protected: virtual bool InitImpl() = 0;

  protected: bool loaded = false;

  protected: bool initialized = false;
};

}
}  // namespace rendering
}  // namespace gz

#endif  // GZ_RENDERING_BASE_RENDERENGINEEXTENSION_HH_
