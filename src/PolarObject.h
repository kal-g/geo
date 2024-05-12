#include <cmath>
#include <vector>

struct Euclidean
{
    float x;
    float y;
    float z;
};

struct LatLong
{
    LatLong(float latitude, float longitude, float radius = 1) : latitude_(latitude), longitude_(longitude), radius_(radius)
    {
    }

    Euclidean toEuclidean()
    {
        auto xy = radius_ * cosf(latitude_);
        return {
            .x = xy * cosf(longitude_),
            .y = xy * sinf(longitude_),
            .z = radius_ * sinf(latitude_)};
    }

    float latitude_;
    float longitude_;
    float radius_;
};

class PolarObject
{
public:
    void AddVertex(float x, float y, float z)
    {
        vertices_.push_back(x);
        vertices_.push_back(y);
        vertices_.push_back(z);
    }

    void AddNormal(float x, float y, float z)
    {
        normals_.push_back(x);
        normals_.push_back(y);
        normals_.push_back(z);
    }

    void AddTextureVertex(float s, float t)
    {
        tex_.push_back(s);
        tex_.push_back(t);
    }

    void Interleave()
    {
        data_.clear();
        // TODO Reserve

        std::size_t i, j;
        std::size_t count = vertices_.size();
        for (i = 0, j = 0; i < count; i += 3, j += 2)
        {
            data_.push_back(vertices_[i]);
            data_.push_back(vertices_[i + 1]);
            data_.push_back(vertices_[i + 2]);

            data_.push_back(normals_[i]);
            data_.push_back(normals_[i + 1]);
            data_.push_back(normals_[i + 2]);

            data_.push_back(tex_[j]);
            data_.push_back(tex_[j + 1]);
        }
    }

protected:
    std::vector<float> vertices_;
    std::vector<float> normals_;
    std::vector<float> tex_;
    std::vector<float> data_;
};