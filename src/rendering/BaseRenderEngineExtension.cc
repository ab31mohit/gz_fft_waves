#include "gz_fft_waves/rendering/BaseRenderEngineExtension.hh"

#include <map>
#include <string>

#include <gz/common/Console.hh>

namespace gz {
namespace rendering {
inline namespace GZ_RENDERING_VERSION_NAMESPACE {

//////////////////////////////////////////////////
BaseRenderEngineExtension::BaseRenderEngineExtension() {
}

//////////////////////////////////////////////////
BaseRenderEngineExtension::~BaseRenderEngineExtension() {
}

//////////////////////////////////////////////////
bool BaseRenderEngineExtension::Load(
    const std::map<std::string, std::string> &_params) {
  if (this->loaded) {
    gzwarn << "Render-engine extension has already been loaded" << std::endl;
    return true;
  }

  this->loaded = this->LoadImpl(_params);
  return this->loaded;
}

//////////////////////////////////////////////////
bool BaseRenderEngineExtension::Init() {
  if (!this->loaded) {
    gzerr << "Render-engine extension must be loaded first"
        << std::endl;
    return false;
  }

  if (this->initialized) {
    gzwarn << "Render-engine extension has already been initialized"
        << std::endl;
    return true;
  }

  this->initialized = this->InitImpl();
  return this->initialized;
}

//////////////////////////////////////////////////
bool BaseRenderEngineExtension::IsInitialized() const {
  return this->initialized;
}

//////////////////////////////////////////////////
void BaseRenderEngineExtension::Destroy() {
}

}
}  // namespace rendering
}  // namespace gz