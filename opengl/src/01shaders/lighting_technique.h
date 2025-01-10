/*

        Copyright 2011 Etay Meiri

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "technique.h"
#include <glm/glm.hpp>
//#include "ogldev_math_3d.h"
//#include "ogldev_material.h"
class color3f {
public:
    float r, g, b;
    color3f(float r, float g, float b) : r(r), g(g), b(b) {}
};

class BaseLight {
public:
    color3f color;
    float AmbientIntensity;

    BaseLight() {
        color = color3f(1.0f, 1.0f, 1.0f);
        AmbientIntensity = 0.0f;
    }
};



class LightingTechnique : public Technique {
public:
    LightingTechnique();
    virtual bool Init();
    void SetWVP(const Matrix4f& WVP);
    void SetTextureUnit(unsigned int TextureUnit);
    void SetLight(const BaseLight& Light);
    void SetMaterial(const Material& material);
private:
    GLuint WVPLoc;
    GLuint samplerLoc;
    GLuint lightColorLoc;
    GLuint lightAmbientIntensityLoc;
    GLuint materialAmbientColorLoc;
};
