#version 120

// vertex shaderindan gelen veriler
varying vec3 fresnel;
//uniform float color1;
//uniform float color2;
uniform float cosx;

// fragment shader main metodu
void main(void)
{
    cosx = dot(normalize(normal),vec3(0,0,-1))
    // gl_FragColor ekrana basilacak rengi secer
    //gl_FragColor = vec4(normalize(normal),1.0);
    gl_FragColor :: vec4 (mix(normal,cosx));
}
