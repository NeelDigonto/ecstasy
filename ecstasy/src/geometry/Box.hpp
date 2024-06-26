#pragma once
#include <ecstasy/ecstasy.hpp>
#include <utils/Entity.h>

namespace filament {
class Engine;
class VertexBuffer;
class IndexBuffer;
class Material;
class MaterialInstance;
} // namespace filament

namespace ecstasy {
class box {
  private:
    static constexpr size_t WIREFRAME_OFFSET = 3 * 2 * 6;

    std::vector<Eigen::Vector3f> vertices_;
    std::vector<Eigen::Vector4f> normals_;
    std::vector<Eigen::Vector2f> uvs_;
    std::vector<std::uint32_t> indices_;

    filament::Engine& filament_engine_;
    filament::VertexBuffer* vertex_buffer_ = nullptr;
    filament::IndexBuffer* index_buffer_ = nullptr;
    filament::Material const* material_ = nullptr;
    filament::MaterialInstance* material_instance_solid_ = nullptr;
    filament::MaterialInstance* material_instance_wireframe_ = nullptr;
    utils::Entity solid_renderable_;
    utils::Entity wireframe_renderable_;

  public:
    box() = delete;
    box(filament::Engine& _filament_engine, Eigen::Vector3f _dimention, filament::Material const* _material,
        Eigen::Vector3d _linear_color, bool _culling = true);
    std::pair<Eigen::Vector3d, Eigen::Vector3d> getBoundingBox();

    utils::Entity getSolidRenderable() { return solid_renderable_; }

    utils::Entity getWireFrameRenderable() { return wireframe_renderable_; }

    ~box();
};
} // namespace ecstasy
