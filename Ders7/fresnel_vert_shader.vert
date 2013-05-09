#version 120

// sabit degiskenler
uniform mat4 MVP;

uniform mat4 ModelView;

glm::mat4 MVPmatrix = camera->getInverseModelMatrix() * getModelMatrix();

// diziden alinacak degiskenler
attribute vec4 Position;
attribute vec3 Normal;
attribute vec3 Fresnel;

// fragment shader'a aktarilacak veriler
varying vec3 normal;

normal = mat3(ModelView)*camera;
normal = normalize(normal );

// vertex shader main metodu
void main()
{	
    // gl_Position ekranda noktanin nerede olacagini belirtir.
    gl_Position = MVP * Position;
    //normal = mat3(MVP)*Normal;
    //normal = dot(Normal,camera);
    Fresnel :: mix(color1,color2,cosx);
}