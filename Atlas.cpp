// Atlas.cpp : This file contains the 'main' function. Program execution begins
// and ends there.
//
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

struct Texture {
  uint32_t w;
  uint32_t h;
};

struct Atlas2DTile {
  uint32_t x;
  uint32_t y;
  size_t id_tex;
};

class MaxRectsBinPack
{
public:
    MaxRectsBinPack();
    MaxRectsBinPack(uint32_t width, uint32_t height);

    enum AllocM
    {
        RectBest
    };
};

struct Atlas2D {
  void addTex(const Texture &tex);
  void finalize();

private:
  vector<Texture> texs;
  vector<Atlas2DTile> tiles;
};

vector<Texture> textures = {
    {64, 64},   {64, 64},     {128, 128},   {128, 128},   {128, 128},
    {128, 128}, {128, 128},   {128, 128},   {128, 128},   {256, 256},
    {256, 256}, {256, 256},   {256, 128},   {64, 64},     {512, 512},
    {256, 256}, {256, 256},   {1024, 1024}, {64, 64},     {512, 512},
    {256, 256}, {2048, 2048}, {2048, 2048}, {4096, 4096}, {512, 512},
};

int main() {
  Atlas2D at;
  for (auto tex : textures) {
    at.addTex(tex);
  }
  at.finalize();
  return 0;
}

void Atlas2D::addTex(const Texture &tex) {
  size_t id_tex = texs.size();
  texs.push_back(tex);
  tiles.push_back({ 0, 0, id_tex });
}

void Atlas2D::finalize() {

}
