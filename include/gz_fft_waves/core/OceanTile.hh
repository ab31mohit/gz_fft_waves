#ifndef GZ_WAVES_OCEANTILE_HH_
#define GZ_WAVES_OCEANTILE_HH_

#include "gz_fft_waves/core/CGALTypes.hh"
#include "gz_fft_waves/core/Types.hh"
#include "gz_fft_waves/core/WaveParameters.hh"

#include <array>
#include <memory>
#include <vector>

#include <gz/common/Mesh.hh>


namespace gz {
namespace waves {

template <typename Vector3>
class OceanTilePrivate;

template <typename Vector3>
class OceanTileT {
 public:
  virtual ~OceanTileT();

  explicit OceanTileT(Index nx, Index ny, double lx, double ly,
      bool has_visuals = true);

  explicit OceanTileT(WaveParametersPtr params, bool has_visuals = true);

  /// \brief The size of the wave tile (m).
  std::array<double, 2> TileSize() const;

  /// \brief The number of cells in the wave tile in each direction.
  /// The tile contains (nx + 1) * (ny + 1) vertices.
  std::array<Index, 2> CellCount() const;

  void SetWindVelocity(double ux, double uy);

  void SetSteepness(double value);

  void Create();

  // Returns a new gz::common::Mesh. The caller must take ownership.
  gz::common::Mesh* CreateMesh();

  void Update(double time);

  void UpdateMesh(double time, gz::common::Mesh* mesh);

  // Access to vertices, texture coordinates and faces
  Index VertexCount() const;

  Vector3 Vertex(Index index) const;

  gz::math::Vector2d UV0(Index index) const;

  Index FaceCount() const;

  gz::math::Vector3i Face(Index index) const;

  const std::vector<Vector3>& Vertices() const;

 private:
  std::unique_ptr<OceanTilePrivate<Vector3>> impl_;
};

namespace visual {
typedef OceanTileT<gz::math::Vector3d> OceanTile;
typedef std::shared_ptr<OceanTile> OceanTilePtr;
}  // namespace visual

namespace physics {
typedef OceanTileT<cgal::Point3>   OceanTile;
typedef std::shared_ptr<OceanTile> OceanTilePtr;
}  // namespace physics

}  // namespace waves
}  // namespace gz

#endif  // GZ_WAVES_OCEANTILE_HH_
