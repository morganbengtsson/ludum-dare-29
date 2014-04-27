#ifdef GL_ES
precision mediump float;
precision mediump int;
#endif
uniform mat4 model_view_projection; 
uniform mat4 model_view; 
attribute vec3 position;
attribute vec3 normal;
attribute vec2 uv;
varying vec3 v_position;
varying vec3 v_normal;
varying vec3 v_position2;
varying vec2 v_uv;

void main()
{
    v_uv = uv;
    v_position2 = normalize((model_view_projection * vec4(position, 1.0)).xyz);
    v_position = (model_view * vec4(position, 0.0)).xyz;
    v_normal = normalize((model_view * vec4(normal, 0.0)).xyz);
    gl_Position = model_view_projection * vec4(position, 1.0);
}
