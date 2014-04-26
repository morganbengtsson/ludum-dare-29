uniform vec4 color;
uniform sampler2D texture;
uniform vec3 camera_position;
varying vec3 v_position;
varying vec3 v_normal; 
varying vec3 v_position2;
varying vec2 v_uv;
void main() {
vec3 ambient = vec3(0.3, 0.3, 0.3);

vec3 light = normalize(vec3(0.0,0.0,0.0) - v_position2);

vec3 material = texture2D(texture, v_uv).rgb;
vec3 diffuse = max(dot(v_normal,light), 0.0);

gl_FragColor = vec4(diffuse, 1.0);
}
