#ifdef GL_ES
precision mediump float;
precision mediump int;
#endif
uniform vec4 color;
uniform sampler2D texture;
varying vec3 v_position;
varying vec3 v_normal; 
varying vec3 v_position2;
varying vec2 v_uv;
void main() {
vec3 ambient = vec3(0.3, 0.3, 0.3);
float d = (v_position.z + 100.0)/5000.0;

vec3 light = normalize(vec3(0.0, 0.0, 0.0) - v_position2);
float intensity = max(dot(v_normal,light), 0.0) * 0.5;        

vec3 indirect = texture2D(texture, v_uv).rgb;

gl_FragColor = vec4(indirect, 1.0);

//gl_FragColor = vec4(v_position, 1.0);

//gl_FragColor = vec4(color.xyz, 1.0);

//gl_FragColor = vec4(v_uv.xy, 1.0, 1.0);
//gl_FragColor = vec4(texture2D(texture, v_uv).rgb, 1.0);
//gl_FragColor = vec4(v_normal, 1.0); 
}
