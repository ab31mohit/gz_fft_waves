/// \file CGALTypes.hh
/// \brief Type definitions for CGAL structures used in the library.

#ifndef GZ_WAVES_CGALTYPES_HH_
#define GZ_WAVES_CGALTYPES_HH_

#include <CGAL/AABB_face_graph_triangle_primitive.h>
#ifndef CGAL_VERSION_MAJOR
#error
#endif
#if CGAL_VERSION_MAJOR >= 6
#include <CGAL/AABB_traits_3.h>
#else
#include <CGAL/AABB_traits.h>
#endif
#include <CGAL/AABB_tree.h>
#include <CGAL/Simple_cartesian.h>
#include <CGAL/Surface_mesh.h>

#include <memory>

namespace gz {
namespace cgal {
//////////////////////////////////////////////////
// CGAL Typedefs

// 2D/3D Linear Geometry
typedef CGAL::Simple_cartesian<double>  Kernel;
typedef Kernel::Direction_2             Direction2;
typedef Kernel::Direction_3             Direction3;
typedef Kernel::Point_3                 Point3;
typedef Kernel::Line_3                  Line;
typedef Kernel::Ray_3                   Ray;
typedef Kernel::Triangle_3              Triangle;
typedef Kernel::Vector_2                Vector2;
typedef Kernel::Vector_3                Vector3;

// SurfaceMesh
typedef CGAL::Surface_mesh<Point3>      Mesh;
typedef Mesh::Face_index                FaceIndex;
typedef Mesh::Halfedge_index            HalfedgeIndex;
typedef Mesh::Vertex_index              VertexIndex;

// AABB Tree
typedef CGAL::AABB_face_graph_triangle_primitive<Mesh> Primitive;
#if CGAL_VERSION_MAJOR >= 6
typedef CGAL::AABB_traits_3<Kernel, Primitive> Traits;
#else
typedef CGAL::AABB_traits<Kernel, Primitive> Traits;
#endif
typedef CGAL::AABB_tree<Traits> AABBTree;

// Pointers
typedef std::shared_ptr<Mesh>           MeshPtr;

}  // namespace cgal
}  // namespace gz

#endif  // GZ_WAVES_CGALTYPES_HH_
