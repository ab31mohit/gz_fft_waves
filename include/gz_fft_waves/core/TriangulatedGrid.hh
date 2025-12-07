/// \file TriangulatedGrid.hh

#ifndef GZ_WAVES_TRIANGULATEDGRID_HH_
#define GZ_WAVES_TRIANGULATEDGRID_HH_

#include "gz_fft_waves/core/CGALTypes.hh"
#include "gz_fft_waves/core/Types.hh"

#include <array>
#include <memory>
#include <vector>

#include <gz/math.hh>

namespace gz {
namespace waves {

typedef std::array<int64_t, 3>    Index3;
typedef std::vector<cgal::Point3> Point3Range;
typedef std::vector<Index3>       Index3Range;

class TriangulatedGrid {
 public:
  virtual ~TriangulatedGrid();
  TriangulatedGrid(Index nx, Index ny, double lx, double ly);
  void CreateMesh();
  void CreateTriangulation();
  static std::unique_ptr<TriangulatedGrid> Create(
      Index nx, Index ny, double lx, double ly);

  bool Locate(const cgal::Point3& query, int64_t& faceIndex) const;
  bool Height(const cgal::Point3& query, double& height) const;
  bool Height(const std::vector<cgal::Point3>& queries,
      std::vector<double>& heights) const;

  bool Interpolate(TriangulatedGrid& patch) const;

  const Point3Range& Points() const;
  const Index3Range& Indices() const;
  const cgal::Point3& Origin() const;
  void ApplyPose(const math::Pose3d& pose);

  bool IsValid(bool verbose = false) const;
  void DebugPrintMesh() const;
  void DebugPrintTriangulation() const;
  void UpdatePoints(const std::vector<cgal::Point3>& from);
  void UpdatePoints(const std::vector<math::Vector3d>& from);
  void UpdatePoints(const cgal::Mesh& from);

  std::array<double, 2> TileSize() const;
  std::array<Index, 2> CellCount() const;

 private:
  class Private;
  std::unique_ptr<Private> impl_;
};

}  // namespace waves
}  // namespace gz

#endif  // GZ_WAVES_TRIANGULATEDGRID_HH_
