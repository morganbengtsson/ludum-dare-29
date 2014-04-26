uniform vec4 color;
uniform sampler2D texture;
uniform vec3 camera_position;
varying vec3 v_position;
varying vec3 v_normal; 
varying vec3 v_position2;
varying vec2 v_uv;
void main() {
vec3 ambient = vec3(0.3, 0.3, 0.3);
float d = (v_position.z + 100.0)/5000.0;

vec3 light = normalize(camera_position - v_position2);
float intensity = max(dot(v_normal,light), 0.0) * 0.2;        

vec3 indirect = texture2D(texture, v_uv).rgb;

vec2 normalized_frag = vec2((gl_FragCoord.x / 1280.0)*2.0 - 1.0, (gl_FragCoord.y / 800.0)*2.0 - 1.0);
float test = length(normalized_frag);
gl_FragColor = vec4(indirect + intensity, 1.0);
//gl_FragColor = vec4(test.xxx, 1.0);
}
